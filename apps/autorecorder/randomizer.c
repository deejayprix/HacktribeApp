#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "ft_types.h"
#include "rng.h"
#include "pattern_writer.h"
#include "mod_matrix.h"
#include "euclid_engine_v2.h"
#include "randomizer.h"

/* ============================================================
   INTERNAL FORWARD DECLS
   ============================================================ */
static void undo_clear_entry(randomizer_undo_entry_t *u);
static void undo_push(int part, int page,
                      const ft_step_t *steps, int n);

static inline int clampi(int v, int lo, int hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

/* ============================================================
   GLOBAL STATE
   ============================================================ */

/* Global Euclid storage used by randomizer_euclid.c */
eu_channel_t g_eu_channels[RANDOMIZER_MAX_CHANNELS];

/* Core */
static uint32_t g_seed = 0xC0FFEEu;
static int g_density   = 100;
static int g_variation = 0;
static int g_freeze    = 0;
static int g_section   = 0;

/* Composer → Randomizer */
static randomizer_policy_flags_t g_policy_flags = 0;

/* Part usage mask */
static uint16_t g_part_used_mask = 0;

/* Motion lanes */
static motion_lane_t g_motions[RANDOMIZER_MAX_MOTION_LANES];

/* Undo */
static randomizer_undo_entry_t g_undo[RANDOMIZER_UNDO_SLOTS];
static int g_undo_top = 0;

/* Step repeater */
static uint8_t g_step_repeat
    [RANDOMIZER_MAX_CHANNELS]
    [RANDOMIZER_MAX_STEPS];

/* ============================================================
   PART BIAS (PHASE 3.5.1.3 – OPTION A)
   ============================================================ */

typedef struct {
    int density_bias;   /* −40 … +40 */
    int velocity_bias;  /* −32 … +32 */
    int gate_bias;      /* −48 … +48 */
} part_bias_t;

/* Index = part number */
static const part_bias_t g_part_bias[RANDOMIZER_MAX_CHANNELS] = {
    /* 0  Bass */  { +10,  -6, +24 },
    /* 1  Lead */  {  -5, +12, +12 },
    /* 2  Pad  */  { -15,  -6, +36 },
    /* 3  Pad  */  { -15,  -6, +36 },
    /* 4  Synth*/  {  -5,   0, +12 },
    /* 5  FX   */  { -20,  +6, -12 },
    /* 6  FX   */  { -20,  +6, -12 },
    /* 7  FX   */  { -20,  +6, -12 },

    /* 8  Kick */  { +20, +16, -36 },
    /* 9  Snare*/  { +10, +12, -42 },
    /* 10 Hat */  { +25,  +6, -60 },
    /* 11 Hat */  { +25,  +6, -60 },
    /* 12 Perc*/  { +15,  +8, -48 },
    /* 13 Perc*/  { +15,  +8, -48 },
    /* 14 Perc*/  { +10,  +6, -48 },
    /* 15 Perc*/  { +10,  +6, -48 }
};

/* ============================================================
   3.5.4 – TIMELINE-SCOPE POST PROCESSING (STEP 2)
   - deterministic, no structural changes
   - multi-bar coherence via stable per-(part,bar,section) seeds
   ============================================================ */

static inline uint32_t mix_u32(uint32_t x)
{
    /* cheap hash/mix */
    x ^= x >> 16;
    x *= 0x7feb352du;
    x ^= x >> 15;
    x *= 0x846ca68bu;
    x ^= x >> 16;
    return x;
}

/* "Groove" here is energy/section-coherent accenting (no timing shifts) */
static inline int groove_accent_delta(int section, int step_idx)
{
    /* 16-step grid accents, varies gently by section */
    const int pos = (step_idx & 15);
    int d = 0;

    /* base: downbeats stronger */
    if (pos == 0) d += 10;
    if (pos == 4 || pos == 8 || pos == 12) d += 6;

    /* section flavor */
    switch (section)
    {
        default:
        case 0: /* INTRO  */ d -= 2; break;
        case 1: /* MAIN   */ d += 2; break;
        case 2: /* BREAK  */ d -= 6; break;
        case 3: /* PEAK   */ d += 6; break;
        case 4: /* OUTRO  */ d -= 4; break;
    }

    return d;
}

/* Humanizer = tiny deterministic variance, consistent per part+bar */
static inline int humanize_delta(uint32_t seed_mix, int step_idx, int max_abs)
{
    uint32_t h = mix_u32(seed_mix ^ (uint32_t)step_idx * 0x9e3779b9u);
    int v = (int)(h & 0x7F) - 64; /* -64..+63 */
    v = (v * max_abs) / 64;
    return v;
}

/* Apply Euclid as a gate-mask (timeline scope) */
static inline int euclid_gate_mask(int ch, int step_idx)
{
    /* slot 0 is "default gate mask" if enabled; other slots can be routed via mod-matrix */
    return randomizer_get_euclid_value_public(ch, 0, step_idx) ? 1 : 0;
}

/* ============================================================
   POLICY FLAGS API
   ============================================================ */

void randomizer_set_policy_flags(randomizer_policy_flags_t flags)
{
    g_policy_flags = flags;
}

randomizer_policy_flags_t randomizer_get_policy_flags(void)
{
    return g_policy_flags;
}

/* ============================================================
   CORE SETTINGS
   ============================================================ */

void randomizer_set_seed(int seed)
{
    g_seed = (uint32_t)seed;
    rng_seed(g_seed);
}

void randomizer_set_density(int pct)
{
    g_density = clampi(pct, 0, 100);
}

void randomizer_set_variation(int v)
{
    g_variation = clampi(v, 0, 127);
}

void randomizer_set_freeze(int en)
{
    g_freeze = en ? 1 : 0;
}

void randomizer_set_section(int s)
{
    g_section = s;
}

int randomizer_get_section(void)   { return g_section; }
int randomizer_get_variation(void) { return g_variation; }

/* ============================================================
   PART USAGE (PUBLIC)
   ============================================================ */

int randomizer_part_in_use(uint8_t part)
{
    if (part >= RANDOMIZER_MAX_CHANNELS) return 0;
    return (g_part_used_mask & (1u << part)) ? 1 : 0;
}

void randomizer_mark_part_used(uint8_t part)
{
    if (part < RANDOMIZER_MAX_CHANNELS)
        g_part_used_mask |= (1u << part);
}

void randomizer_reset_part_usage(uint8_t part)
{
    if (part < RANDOMIZER_MAX_CHANNELS)
        g_part_used_mask &= ~(1u << part);
}

/* ============================================================
   STEP REPEATER (PUBLIC)
   ============================================================ */

void randomizer_set_step_repeat(int part, int step, int repeat)
{
    if (part < 0 || part >= RANDOMIZER_MAX_CHANNELS) return;
    if (step < 0 || step >= RANDOMIZER_MAX_STEPS) return;

    g_step_repeat[part][step] =
        (uint8_t)clampi(repeat, STEP_REPEAT_MIN, STEP_REPEAT_MAX);
}

int randomizer_get_step_repeat(int part, int step)
{
    if (part < 0 || part >= RANDOMIZER_MAX_CHANNELS)
        return STEP_REPEAT_MIN;
    if (step < 0 || step >= RANDOMIZER_MAX_STEPS)
        return STEP_REPEAT_MIN;

    return (int)g_step_repeat[part][step];
}

/* ============================================================
   MOTION LANES (PUBLIC)
   ============================================================ */

int randomizer_create_motion_lane(int id, int length)
{
    if (id < 0 || id >= RANDOMIZER_MAX_MOTION_LANES) return -1;
    length = clampi(length, 1, RANDOMIZER_MAX_MOTION_LEN);

    g_motions[id].length  = length;
    g_motions[id].enabled = true;

    for (int i = 0; i < RANDOMIZER_MAX_MOTION_LEN; i++)
        g_motions[id].values[i] = 0;

    return 0;
}

int randomizer_set_motion_value(int id, int idx, int val)
{
    if (id < 0 || id >= RANDOMIZER_MAX_MOTION_LANES) return -1;
    if (idx < 0 || idx >= RANDOMIZER_MAX_MOTION_LEN) return -1;

    g_motions[id].values[idx] = clampi(val, 0, 127);
    return 0;
}

int randomizer_set_motion_length(int id, int length)
{
    if (id < 0 || id >= RANDOMIZER_MAX_MOTION_LANES) return -1;
    g_motions[id].length = clampi(length, 1, RANDOMIZER_MAX_MOTION_LEN);
    return 0;
}

int randomizer_set_motion_enabled(int id, int en)
{
    if (id < 0 || id >= RANDOMIZER_MAX_MOTION_LANES) return -1;
    g_motions[id].enabled = (en ? true : false);
    return 0;
}

int randomizer_get_motion_value(int id, int idx)
{
    if (id < 0 || id >= RANDOMIZER_MAX_MOTION_LANES) return 0;
    if (!g_motions[id].enabled) return 0;

    int len = g_motions[id].length;
    if (len <= 0) len = 1;

    int i = idx % len;
    if (i < 0) i = 0;

    return clampi(g_motions[id].values[i], 0, 127);
}

int randomizer_get_motion_length(int id)
{
    if (id < 0 || id >= RANDOMIZER_MAX_MOTION_LANES) return 0;
    return g_motions[id].length;
}

/* ============================================================
   MOD MATRIX WRAPPERS (PUBLIC)
   ============================================================ */

int randomizer_add_mod_route(void *route)
{
    if (!route) return -1;
    return mod_matrix_add((const mod_route_t*)route);
}

int randomizer_remove_mod_route(int idx)
{
    return mod_matrix_remove(idx);
}

int randomizer_clear_mod_routes(void)
{
    return mod_matrix_clear();
}

/* ============================================================
   UNDO (INTERNAL/PUBLIC)
   ============================================================ */

static void undo_clear_entry(randomizer_undo_entry_t *u)
{
    if (!u) return;
    u->part = -1;
    u->page = -1;
    u->n    = 0;
}

static void undo_push(int part, int page,
                      const ft_step_t *steps, int n)
{
    int idx = g_undo_top % RANDOMIZER_UNDO_SLOTS;
    randomizer_undo_entry_t *u = &g_undo[idx];

    u->part = part;
    u->page = page;
    u->n    = (n > RANDOMIZER_MAX_STEPS)
                ? RANDOMIZER_MAX_STEPS : n;

    if (steps && u->n > 0)
        memcpy(u->steps, steps, sizeof(ft_step_t) * (size_t)u->n);

    g_undo_top++;
}

int randomizer_undo_last_public(void)
{
    if (g_undo_top == 0) return -1;

    int idx = (g_undo_top - 1) % RANDOMIZER_UNDO_SLOTS;
    randomizer_undo_entry_t *u = &g_undo[idx];

    if (u->part < 0 || u->n == 0) return -1;

    pattern_write_pattern(u->part, u->steps, u->n);
    undo_clear_entry(u);
    return 0;
}

/* ============================================================
   PATTERN GENERATION (PART-BIAS + 3.5.4 STEP2 POST)
   section_bar = "timeline bar index / section bar" input from caller
   ============================================================ */

int randomize_generate_pattern(int part,
                               int steps_count,
                               ft_step_t *steps_out,
                               int section_bar)
{
    if (!steps_out) return -1;
    if (part < 0 || part >= RANDOMIZER_MAX_CHANNELS) return -1;
    if (steps_count <= 0 || steps_count > RANDOMIZER_MAX_STEPS) return -1;

    /* Freeze = do nothing (keep deterministic behavior by not touching output) */
    if (g_freeze) return -1;

    const part_bias_t *pb = &g_part_bias[part];

    /* Multi-bar deterministic seed: stable per (seed, part, section, bar) */
    const uint32_t seed_mix =
        mix_u32(g_seed ^ (uint32_t)part * 0x45d9f3bu ^ (uint32_t)g_section * 0x27d4eb2du ^ (uint32_t)section_bar);

    rng_seed(seed_mix);

    int eff_density = clampi(g_density + pb->density_bias, 0, 100);

    for (int i = 0; i < steps_count; i++)
    {
        /* base RNG */
        int r  = rng_get() & 0x7F;
        int r2 = rng_get() & 0x7F;

        /* hit decision (density) */
        int hit = ((r2 % 100) < eff_density) ? 1 : 0;

        /* base vel/gate */
        int vel = hit ? clampi(((r >> 1) & 0x7F) + pb->velocity_bias, 1, 127) : 0;
        int gate = hit ? clampi(64 + pb->gate_bias, 1, 127) : 0;

        /* 3.5.4 STEP2: Euclid gate mask across bars (slot 0 as main mask) */
        if (hit)
        {
            int eg = euclid_gate_mask(part, i);
            if (!eg) {
                /* masked out -> silence */
                hit = 0;
                vel = 0;
                gate = 0;
            }
        }

        /* 3.5.4 STEP2: Groove accent per section (no timing changes) */
        if (hit)
        {
            vel = clampi(vel + groove_accent_delta(g_section, i), 1, 127);
        }

        /* 3.5.4 STEP2: Humanizer (deterministic per part+bar) */
        if (hit)
        {
            vel  = clampi(vel  + humanize_delta(seed_mix ^ 0xA11CEu, i, 8),  1, 127);
            gate = clampi(gate + humanize_delta(seed_mix ^ 0xBADA55u, i, 6), 1, 127);
        }

        /* write step */
        steps_out[i] = (ft_step_t){
            .part     = (uint8_t)part,
            .step     = (uint8_t)i,
            .pitch    = (uint8_t)(r & 0x7F),
            .velocity = (uint8_t)vel,
            .gate     = (uint8_t)gate
        };

        /* 3.5.4 STEP2: Mod-matrix (timeline scope) */
        mod_matrix_apply(&steps_out[i], part, i);
    }

    /* undo snapshot */
    undo_push(part, 0, steps_out, steps_count);
    return steps_count;
}

/* ============================================================
   WRITE HELPERS  (IMPORTANT: MUST BE NON-STATIC FOR LINKER)
   ============================================================ */

int randomize_and_write_pattern_paged(int part,
                                      int steps_count,
                                      int section,
                                      int page)
{
    (void)page;

    ft_step_t tmp[RANDOMIZER_MAX_STEPS];

    /* section is treated as "timeline bar index/section_bar" seed input */
    int n = randomize_generate_pattern(part, steps_count, tmp, section);

    return (n > 0)
        ? pattern_write_pattern(part, tmp, n)
        : -1;
}

int randomize_and_write_pattern_paged_simple(int part,
                                             int steps_count,
                                             ft_step_t *steps_out)
{
    int n = randomize_generate_pattern(part, steps_count, steps_out, g_section);

    return (n > 0)
        ? pattern_write_pattern(part, steps_out, n)
        : -1;
}

/* ============================================================
   INIT / TICK
   ============================================================ */

void randomizer_init_default(void)
{
    rng_seed(g_seed);

    g_policy_flags   = 0;
    g_part_used_mask = 0;
    g_undo_top       = 0;

    /* motions default */
    for (int i = 0; i < RANDOMIZER_MAX_MOTION_LANES; i++) {
        g_motions[i].length = 16;
        g_motions[i].enabled = false;
        for (int j = 0; j < RANDOMIZER_MAX_MOTION_LEN; j++)
            g_motions[i].values[j] = 0;
    }

    for (int i = 0; i < RANDOMIZER_UNDO_SLOTS; i++)
        undo_clear_entry(&g_undo[i]);

    for (int p = 0; p < RANDOMIZER_MAX_CHANNELS; p++)
        for (int s = 0; s < RANDOMIZER_MAX_STEPS; s++)
            g_step_repeat[p][s] = STEP_REPEAT_MIN;

    mod_matrix_init();
}

void randomizer_tick_once(void)
{
    /* reserved */
}
