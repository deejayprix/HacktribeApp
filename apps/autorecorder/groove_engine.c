#include "groove_engine.h"
#include <string.h>

/* ============================================================
   INTERNAL STATE
   ============================================================ */

typedef struct {
    uint8_t enabled;         /* 0/1 */
    uint8_t macro;           /* 0..127 */

    /* “locked defaults” – used by apply_* paths */
    uint8_t timing_amount;   /* 0..127 */
    uint8_t velocity_amount; /* 0..127 */
} groove_state_t;

static groove_state_t g_groove;

/* ============================================================
   INTERNAL HELPERS
   ============================================================ */

static inline uint8_t clamp_u7(int v)
{
    if (v < 0)   return 0;
    if (v > 127) return 127;
    return (uint8_t)v;
}

static inline int clampi(int v, int lo, int hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

/* Pattern weighting (Phase 3.2.3.4) */
static uint8_t groove_pattern_weight(int step)
{
    /* Stronger on downbeats */
    int s = step & 15;
    if (s == 0) return 127;
    if (s == 8) return 108;
    if ((s & 3) == 0) return 92;
    return 72;
}

/* Global “lock”: if disabled OR macro==0 => NO-OP */
static inline int groove_is_active(void)
{
    return (g_groove.enabled && g_groove.macro > 0) ? 1 : 0;
}

/* Macro-scaled amount (0..127), safe: macro==0 => 0 */
static inline int apply_macro_amount(uint8_t amount)
{
    /* (amount * macro) / 127 */
    return ((int)amount * (int)g_groove.macro) / 127;
}

/* ============================================================
   INIT / ENABLE
   ============================================================ */

void groove_init(void)
{
    memset(&g_groove, 0, sizeof(g_groove));

    /* Final defaults (Phase 3.2.3.13.4):
       - enabled: ON by default is okay, but macro 0 keeps it effectively off
       - macro: 0 => no change until user turns it up
       - timing/velocity amounts: moderate defaults, still gated by macro
    */
    g_groove.enabled = 1;
    g_groove.macro = 0;

    g_groove.timing_amount = 64;    /* “centered” strength */
    g_groove.velocity_amount = 64;
}

void groove_set_enabled(uint8_t en)
{
    g_groove.enabled = en ? 1 : 0;
}

uint8_t groove_get_enabled(void)
{
    return g_groove.enabled;
}

/* ============================================================
   AMOUNTS (micro-timing + velocity swing)
   ============================================================ */

void groove_set_timing_amount(uint8_t v)
{
    g_groove.timing_amount = clamp_u7((int)v);
}

void groove_set_velocity_amount(uint8_t v)
{
    g_groove.velocity_amount = clamp_u7((int)v);
}

uint8_t groove_get_timing_amount(void)
{
    return g_groove.timing_amount;
}

uint8_t groove_get_velocity_amount(void)
{
    return g_groove.velocity_amount;
}

/* ============================================================
   MACRO / CURVE ENTRY (alias)
   ============================================================ */

void groove_set_macro(uint8_t v)
{
    g_groove.macro = clamp_u7((int)v);
}

/* Router compatibility (older naming) */
void groove_set_curve(uint8_t v)
{
    groove_set_macro(v);
}

uint8_t groove_get_macro(void)
{
    return g_groove.macro;
}

/* ============================================================
   CURVES (base)
   ============================================================ */

int groove_get_timing_curve(int step)
{
    /* Simple “odd-step late” swing base */
    return (step & 1) ? 2 : 0;
}

int groove_get_velocity_curve(int step)
{
    /* Slightly softer on off-beats */
    return (step & 1) ? -8 : 0;
}

/* ============================================================
   SHAPE HELPERS (phase 0..127)
   ============================================================ */

int groove_curve_timing_shape(int phase)
{
    /* signed, small range */
    int p = clampi(phase, 0, 127);
    return (p - 64) / 16; /* approx -4..+3 */
}

int groove_curve_velocity_shape(int phase)
{
    int p = clampi(phase, 0, 127);
    return (p - 64) / 8;  /* approx -8..+7 */
}

/* ============================================================
   APPLY (pattern-aware + macro + amounts)
   ============================================================ */

int groove_apply_timing(int step, int curve_val)
{
    if (!groove_is_active())
        return 0;

    /* amount after macro scaling */
    int amt = apply_macro_amount(g_groove.timing_amount); /* 0..127 */
    if (amt <= 0)
        return 0;

    /* scale curve_val by amount (amt/127) */
    int v = (curve_val * amt) / 127;

    /* pattern weight */
    v = (v * (int)groove_pattern_weight(step)) / 127;

    return v;
}

int groove_apply_velocity(int step, int curve_val)
{
    if (!groove_is_active())
        return 0;

    int amt = apply_macro_amount(g_groove.velocity_amount);
    if (amt <= 0)
        return 0;

    int v = (curve_val * amt) / 127;
    v = (v * (int)groove_pattern_weight(step)) / 127;

    return v;
}
