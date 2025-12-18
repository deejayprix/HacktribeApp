#include "sync_live.h"
#include "ft_api.h"
#include "randomizer.h"
#include "midi_out.h"
#include "groove_engine.h"
#include <string.h>

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

static void rep_reset(int p)
{
    memset(&g_rep[p], 0, sizeof(step_repeat_state_t));
}

static uint32_t rep_tick(uint32_t start,
                         uint32_t len,
                         int rep,
                         int idx)
{
    return start + ((uint64_t)len * idx) / rep;
}

/* ============================================================
   MIDI EMIT
   ============================================================ */

static void emit_note_on(int part, int vel)
{
    midi_send_byte(0x90 | (part & 0x0F));
    midi_send_byte(60);           /* placeholder note */
    midi_send_byte(vel & 0x7F);
}

static void emit_note_off(int part)
{
    midi_send_byte(0x80 | (part & 0x0F));
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

    groove_init();

    for (int i = 0; i < MAX_PARTS; ++i)
        rep_reset(i);
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

    /* --------------------------------------------------------
       STEP CHANGE
       -------------------------------------------------------- */
    if (step != last_step)
    {
        uint32_t step_len =
            (last_step_tick > 0) ? (now - last_step_tick) : 1;
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

            /* initial fire time (+ groove offset) */
            int off = groove_get_timing_offset_ticks(part, step, (int)step_len, 0, r);
            int64_t nf = (int64_t)rep_tick(now, step_len, r, 0) + off;
            if (nf < (int64_t)now) nf = now;
            s->next_fire = (uint32_t)nf;
        }

        last_step = step;
    }

    /* --------------------------------------------------------
       REPEATER PLAYBACK
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
            int base_vel = 110;
            int vel = groove_apply_velocity(part, base_vel, g_live.step, s->fired, s->repeat);

            emit_note_on(part, vel);
            s->note_on  = 1;
            s->note_off = now + (s->step_len / NOTE_LENGTH_TICKS_DIV);

            s->fired++;

            /* schedule next (+ groove offset per sub-hit) */
            uint32_t raw_next = rep_tick(s->step_start, s->step_len, s->repeat, s->fired);
            int off = groove_get_timing_offset_ticks(part, g_live.step, (int)s->step_len, s->fired, s->repeat);

            int64_t nf = (int64_t)raw_next + off;
            if (nf < (int64_t)now) nf = now;
            s->next_fire = (uint32_t)nf;

            if (s->fired >= s->repeat)
                s->active = 0;
        }
    }
}
