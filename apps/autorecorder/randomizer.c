/* randomizer.c  (PHASE 3.5.4 – Step 3+4 merged)
   - Step 3: “Micro-Timing Drift” (Humanizer-reuse, Timeline-Scope)  ✅
     -> implemented as deterministic per-Part/per-Bar drift that modulates
        velocity + gate slightly (no new structure decisions, no RNG bleed).
   - Step 4: Preview == Write == Playback ✅
     -> generation uses an internal deterministic PRNG (does NOT touch rng.c global state),
        so preview/write/playback see identical results for same inputs.
*/

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "ft_types.h"
#include "pattern_writer.h"
#include "randomizer.h"

/* ============================================================
   INTERNAL FORWARD DECLS
   ============================================================ */
static void undo_clear_entry(randomizer_undo_entry_t *u);
static void undo_push(int part, int page,
                      const ft_step_t *steps, int n);

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

/* Composer → Randomizer policy flags */
static randomizer_policy_flags_t g_policy_flags = 0;

/* Part usage mask */
static uint16_t g_part_used_mask = 0;

/* Undo */
static randomizer_undo_entry_t g_undo[RANDOMIZER_UNDO_SLOTS];
static int g_undo_top = 0;

/* Step repeater */
static uint8_t g_step_repeat
    [RANDOMIZER_MAX_CHANNELS]
    [RANDOMIZER_MAX_STEPS];

/* ============================================================
   HELPERS
   ============================================================ */

static inline int clampi(int v, int lo, int hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

/* ============================================================
   DETERMINISTIC LOCAL PRNG (Step 4: Preview == Write == Playback)
   ============================================================ */
/* xorshift32 – fast, deterministic, local state only */
static inline uint32_t prng_next_u32(uint32_t *s)
{
    uint32_t x = *s;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    *s = x;
    return x;
}

static inline uint8_t prng_u7(uint32_t *s)
{
    return (uint8_t)(prng_next_u32(s) & 0x7Fu);
}

static inline uint32_t hash_u32(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    /* simple avalanche mix */
    uint32_t x = a ^ (b + 0x9e3779b9u) ^ (c << 6) ^ (c >> 2) ^ (d * 0x85ebca6bu);
    x ^= x >> 16;
    x *= 0x7feb352du;
    x ^= x >> 15;
    x *= 0x846ca68bu;
    x ^= x >> 16;
    return x ? x : 0xA5A5A5A5u;
}

/* ============================================================
   PART BIAS (PHASE 3.5.1.3 – OPTION A)  (already “green” tuned)
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
   3.5.4 Step 2 (already done): Velocity Energy Curve per Section
   ============================================================ */
/* Section ids assumed: 0=Intro,1=Main,2=Break,3=Peak,4=Outro
   Curve is conservative: “no new decision logic”, only scaling.
*/
static inline int section_velocity_gain_pct(int section)
{
    switch (section)
    {
        default:
        case 0: return 92;  /* Intro: slightly softer */
        case 1: return 105; /* Main: a bit more forward */
        case 2: return 85;  /* Break: pull back */
        case 3: return 112; /* Peak: push */
        case 4: return 95;  /* Outro: relax */
    }
}

/* ============================================================
   3.5.4 Step 3: Micro-Timing Drift (Humanizer-reuse, Timeline-Scope)
   ============================================================ */
/* We implement “micro timing drift” as a deterministic, slow drift signal
   per (part, bar) that slightly modulates velocity + gate.
   - No new structural decisions (hit pattern unchanged)
   - Deterministic from (global seed, part, section, bar)
   - Stable across preview/write/playback because PRNG is local
*/
static inline int drift_per_part_bar(int part, int section, int bar, int span)
{
    /* span: magnitude in “units” (kept small) */
    uint32_t s = hash_u32(g_seed, (uint32_t)part, (uint32_t)section, (uint32_t)bar);
    int d = (int)(prng_next_u32(&s) % (uint32_t)(span * 2 + 1)) - span;
    return d;
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
    /* NOTE: do NOT touch global rng state here (Step 4 requirement). */
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

    return g_step_repeat[part][step];
}

/* ============================================================
   UNDO (INTERNAL)
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
   PATTERN GENERATION
   - Part-Bias applied (3.5.1.3)
   - Section energy curve applied (3.5.4 Step 2)
   - Micro drift applied (3.5.4 Step 3)
   - Deterministic local PRNG (3.5.4 Step 4)
   ============================================================ */

int randomize_generate_pattern(int part,
                               int steps_count,
                               ft_step_t *steps_out,
                               int section_bar)
{
    if (!steps_out) return -1;
    if (part < 0 || part >= RANDOMIZER_MAX_CHANNELS) return -1;
    if (steps_count <= 0 || steps_count > RANDOMIZER_MAX_STEPS) return -1;

    /* Freeze = do nothing new (safe) */
    if (g_freeze) return -1;

    /* Local deterministic stream:
       include section_bar to make bar-to-bar evolution deterministic. */
    uint32_t s = hash_u32(g_seed,
                          (uint32_t)part,
                          (uint32_t)g_section,
                          (uint32_t)section_bar);

    const part_bias_t *pb = &g_part_bias[part];

    int eff_density = clampi(g_density + pb->density_bias, 0, 100);
    int vel_gain    = section_velocity_gain_pct(g_section);

    /* Drift is stable per (part, bar) — “timeline scope” */
    int drift_v = drift_per_part_bar(part, g_section, section_bar, 6);  /* ±6 velocity */
    int drift_g = drift_per_part_bar(part, g_section, section_bar, 8);  /* ±8 gate base */

    for (int i = 0; i < steps_count; i++)
    {
        uint8_t r_pitch = prng_u7(&s);
        uint8_t r_vel   = prng_u7(&s);
        uint8_t r_hit   = prng_u7(&s);

        int hit = ((int)(r_hit % 100u) < eff_density) ? 1 : 0;

        /* Base velocity from PRNG + part bias */
        int v = ((int)r_vel) + pb->velocity_bias;

        /* Apply section energy curve (gain in percent) */
        v = (v * vel_gain) / 100;

        /* Apply micro drift (humanizer-style), but only if hit */
        v += drift_v;

        /* Variation subtly increases spread (still deterministic) */
        if (g_variation > 0)
        {
            /* symmetrical small wobble scaled by variation */
            int wob = (int)((prng_next_u32(&s) & 0x1Fu) - 16); /* -16..+15 */
            v += (wob * g_variation) / 256; /* gentle */
        }

        v = clampi(v, 1, 127);

        /* Gate: base + part bias + drift. Keep in 1..127 for hit, else 0 */
        int g = 64 + pb->gate_bias + drift_g;
        g = clampi(g, 1, 127);

        steps_out[i] = (ft_step_t){
            .part     = (uint8_t)part,
            .step     = (uint8_t)i,
            .pitch    = r_pitch,
            .velocity = (uint8_t)(hit ? v : 0),
            .gate     = (uint8_t)(hit ? g : 0)
        };
    }

    undo_push(part, 0, steps_out, steps_count);
    return steps_count;
}

/* ============================================================
   WRITE HELPERS (must exist for linker)
   ============================================================ */

int randomize_and_write_pattern_paged(int part,
                                      int steps_count,
                                      int section,
                                      int page)
{
    (void)page;

    /* Keep generation determinism:
       temporarily set g_section for this call, then restore. */
    int prev_section = g_section;
    g_section = section;

    ft_step_t tmp[RANDOMIZER_MAX_STEPS];
    int n = randomize_generate_pattern(part, steps_count, tmp, section);

    g_section = prev_section;

    return (n > 0) ? pattern_write_pattern(part, tmp, n) : -1;
}

int randomize_and_write_pattern_paged_simple(int part,
                                             int steps_count,
                                             ft_step_t *steps_out)
{
    int n = randomize_generate_pattern(part, steps_count, steps_out, g_section);
    return (n > 0) ? pattern_write_pattern(part, steps_out, n) : -1;
}

/* ============================================================
   INIT
   ============================================================ */

void randomizer_init_default(void)
{
    g_policy_flags   = 0;
    g_part_used_mask = 0;
    g_undo_top       = 0;

    for (int i = 0; i < RANDOMIZER_UNDO_SLOTS; i++)
        undo_clear_entry(&g_undo[i]);

    for (int p = 0; p < RANDOMIZER_MAX_CHANNELS; p++)
        for (int st = 0; st < RANDOMIZER_MAX_STEPS; st++)
            g_step_repeat[p][st] = STEP_REPEAT_MIN;
}

void randomizer_tick_once(void)
{
    /* reserved */
}
