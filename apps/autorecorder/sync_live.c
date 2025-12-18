#include "sync_live.h"
#include "ft_api.h"
#include "randomizer.h"
#include "midi_out.h"
#include "groove_engine.h"
#include <string.h>
#include <stdint.h>

/* ============================================================
   LIVE SYNC STATE
   ============================================================ */

live_sync_state_t g_live;

/* ============================================================
   STEP REPEATER
   ============================================================ */

#define MAX_PARTS    16
#define MAX_REPEAT   8
#define NOTE_LENGTH_TICKS_DIV 4   /* gate = step_len / 4 */

typedef struct {
    uint8_t  active;
    uint8_t  repeat;
    uint8_t  fired;
    uint8_t  note_on;

    uint32_t step_start;
    uint32_t step_len;

    uint32_t next_fire;
    uint32_t note_off;
} step_repeat_state_t;

static step_repeat_state_t g_rep[MAX_PARTS];

/* ============================================================
   INTERNAL
   ============================================================ */

static inline int32_t clampi32(int32_t v, int32_t lo, int32_t hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static void rep_reset(int p)
{
    memset(&g_rep[p], 0, sizeof(step_repeat_state_t));
}

static uint32_t rep_tick(uint32_t start,
                         uint32_t len,
                         int rep,
                         int idx)
{
    /* idx: 0..rep */
    return start + ((uint64_t)len * (uint64_t)idx) / (uint64_t)rep;
}

/* Map repeat index -> phase 0..127 */
static uint8_t rep_phase_0_127(int fired, int repeat)
{
    if (repeat <= 1) return 0;
    if (fired < 0) fired = 0;
    if (fired > repeat) fired = repeat;

    /* 0..repeat -> 0..127 */
    return (uint8_t)((fired * 127) / repeat);
}

/* Convert groove curve timing-shape units into small tick offsets.
   We keep it subtle and bounded inside the step. */
static int32_t groove_offset_ticks(uint32_t step_len, uint8_t phase, uint8_t amount)
{
    if (amount == 0 || step_len == 0) return 0;

    /* shape roughly -32..+31 (depending on curve) */
    int32_t shape = (int32_t)groove_curve_timing_shape(phase);

    /* scale to ticks:
       - step_len/32 is a decent "max feel" cap
       - then scale by amount/127
       Example: if step_len is 96 ticks, step_len/32 = 3 ticks max-ish. */
    int32_t max_ticks = (int32_t)(step_len / 32);
    if (max_ticks < 1) max_ticks = 1;
    if (max_ticks > 12) max_ticks = 12; /* hard safety cap */

    int32_t off = (shape * max_ticks) / 32;     /* approx -max..+max */
    off = (off * (int32_t)amount) / 127;        /* amount scaling */

    /* keep within +- (step_len/8) absolute safety */
    int32_t hard = (int32_t)(step_len / 8);
    if (hard < 1) hard = 1;
    off = clampi32(off, -hard, hard);
    return off;
}

static int32_t groove_velocity_delta(uint8_t phase, uint8_t amount)
{
    if (amount == 0) return 0;

    int32_t shape = (int32_t)groove_curve_velocity_shape(phase); /* ~ -21..+21 etc. */
    int32_t dv = (shape * (int32_t)amount) / 127;

    /* keep it subtle */
    dv = clampi32(dv, -24, 24);
    return dv;
}

/* ============================================================
   MIDI EMIT
   ============================================================ */

static void emit_note_on(int part, int vel)
{
    midi_send_byte((uint8_t)(0x90 | (part & 0x0F)));
    midi_send_byte(60);           /* placeholder note */
    midi_send_byte((uint8_t)(vel & 0x7F));
}

static void emit_note_off(int part)
{
    midi_send_byte((uint8_t)(0x80 | (part & 0x0F)));
    midi_send_byte(60);
    midi_send_byte(0);
}

/* ============================================================
   PUBLIC API
   ============================================================ */

void live_sync_init(void)
{
    memset(&g_live, 0, sizeof(g_live));
    g_live.pattern  = ft_get_current_pattern();
    g_live.bpm_x100 = ft_get_bpm() * 100;

    for (int i = 0; i < MAX_PARTS; ++i)
        rep_reset(i);

    /* Groove engine state should exist globally; init is safe to call */
    groove_init();
}

void live_sync_on_start(void)
{
    g_live.is_playing = 1;
    g_live.step = 0;
    g_live.bar  = 0;

    for (int i = 0; i < MAX_PARTS; ++i)
        rep_reset(i);
}

void live_sync_on_stop(void)
{
    g_live.is_playing = 0;

    for (int i = 0; i < MAX_PARTS; ++i)
        rep_reset(i);
}

void live_sync_tick(void)
{
    static int      last_step = -1;
    static uint32_t last_step_tick = 0;

    uint32_t now = ++g_live.tick;
    if (!g_live.is_playing)
        return;

    int step = ft_get_play_position();
    g_live.step = step;
    g_live.bar  = (step / 16) & 0x03;

    g_live.pattern  = ft_get_current_pattern();
    g_live.bpm_x100 = ft_get_bpm() * 100;

    /* --------------------------------------------------------
       STEP CHANGE
       -------------------------------------------------------- */
    if (step != last_step)
    {
        uint32_t step_len =
            (last_step_tick > 0) ? (now - last_step_tick) : 1;
        if (step_len == 0) step_len = 1;
        last_step_tick = now;

        for (int part = 0; part < MAX_PARTS; ++part)
        {
            int r = randomizer_get_step_repeat(part, step);

            if (r <= 1)
            {
                rep_reset(part);
                continue;
            }

            if (r > MAX_REPEAT) r = MAX_REPEAT;

            step_repeat_state_t *s = &g_rep[part];
            s->active     = 1;
            s->repeat     = (uint8_t)r;
            s->fired      = 0;
            s->note_on    = 0;

            s->step_start = now;
            s->step_len   = step_len;

            /* First fire time = start, plus curve offset (phase=0) */
            {
                uint8_t phase = rep_phase_0_127(0, r);
                uint8_t amt   = groove_get_macro(); /* 0..127 */
                int32_t off   = groove_offset_ticks(step_len, phase, amt);

                int32_t t = (int32_t)rep_tick(now, step_len, r, 0) + off;
                /* keep within [start .. start+len-1] */
                int32_t lo = (int32_t)now;
                int32_t hi = (int32_t)(now + step_len - 1);
                t = clampi32(t, lo, hi);

                s->next_fire = (uint32_t)t;
            }
        }

        last_step = step;
    }

    /* --------------------------------------------------------
       REPEATER PLAYBACK + GROOVE CURVE APPLY (3.2.3.13.2)
       -------------------------------------------------------- */
    for (int part = 0; part < MAX_PARTS; ++part)
    {
        step_repeat_state_t *s = &g_rep[part];
        if (!s->active)
            continue;

        /* Note-Off */
        if (s->note_on && now >= s->note_off)
        {
            emit_note_off(part);
            s->note_on = 0;
        }

        /* Fire repeat */
        if (now >= s->next_fire && s->fired < s->repeat)
        {
            int rep = (int)s->repeat;
            int fired = (int)s->fired;

            /* Base velocity ramp (existing) */
            int vel = 127 - (fired * (64 / (rep > 0 ? rep : 1)));
            if (vel < 20) vel = 20;

            /* Apply groove curve to velocity (amount = macro) */
            {
                uint8_t phase = rep_phase_0_127(fired, rep);
                uint8_t amt   = groove_get_macro();
                int32_t dv    = groove_velocity_delta(phase, amt);

                vel = (int)clampi32((int32_t)vel + dv, 1, 127);
            }

            emit_note_on(part, vel);
            s->note_on  = 1;
            s->note_off = now + (s->step_len / NOTE_LENGTH_TICKS_DIV);
            if (s->note_off <= now) s->note_off = now + 1;

            /* advance */
            s->fired++;

            /* Next base tick */
            uint32_t base_next = rep_tick(s->step_start, s->step_len, rep, (int)s->fired);

            /* Apply groove curve to timing (amount = macro) */
            {
                uint8_t phase = rep_phase_0_127((int)s->fired, rep);
                uint8_t amt   = groove_get_macro();
                int32_t off   = groove_offset_ticks(s->step_len, phase, amt);

                int32_t t = (int32_t)base_next + off;

                /* keep inside step window */
                int32_t lo = (int32_t)s->step_start;
                int32_t hi = (int32_t)(s->step_start + s->step_len - 1);
                t = clampi32(t, lo, hi);

                /* ensure strictly non-decreasing vs now (avoid “stuck”)
                   if it collapses, push by 1 tick */
                if (t <= (int32_t)now) t = (int32_t)now + 1;
                if (t > hi) t = hi;

                s->next_fire = (uint32_t)t;
            }

            if (s->fired >= s->repeat)
                s->active = 0;
        }
    }
}
