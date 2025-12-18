#include "groove_engine.h"

/* ============================================================
   INTERNAL STATE
   ============================================================ */

typedef struct
{
    uint8_t enabled;

    uint8_t macro;

    uint8_t timing_curve;
    uint8_t velocity_curve;

    uint8_t timing_amount;     /* 0..127 */
    uint8_t velocity_amount;   /* 0..127 */

} groove_state_t;

static groove_state_t g_groove;

/* ============================================================
   CURVE SHAPES (signed, centered)
   ============================================================ */

static int16_t curve_linear(uint8_t p)
{
    return (int16_t)p - 64;
}

static int16_t curve_swing(uint8_t p)
{
    int16_t x = (int16_t)p - 64;
    return (x * x) / 64 * (x < 0 ? -1 : 1);
}

static int16_t curve_push(uint8_t p)
{
    int16_t x = (int16_t)p - 64;
    return x > 0 ? (x * 2) : x;
}

/* ============================================================
   PUBLIC API
   ============================================================ */

void groove_init(void)
{
    g_groove.enabled = 1;

    g_groove.macro = 0;

    g_groove.timing_curve   = 0;
    g_groove.velocity_curve = 0;

    g_groove.timing_amount   = 64;
    g_groove.velocity_amount = 64;
}

/* ------------------------------------------------------------ */

void groove_set_enabled(uint8_t on)
{
    g_groove.enabled = on ? 1 : 0;
}

uint8_t groove_is_enabled(void)
{
    return g_groove.enabled;
}

/* ------------------------------------------------------------
   Macro
   ------------------------------------------------------------ */

void groove_set_macro(uint8_t value)
{
    g_groove.macro = value & 0x7F;

    /* deterministic mapping */
    g_groove.timing_curve =
        (value < 42) ? 0 : (value < 85) ? 1 : 2;

    g_groove.velocity_curve =
        (value < 64) ? 0 : 1;

    g_groove.timing_amount   = value;
    g_groove.velocity_amount = value;
}

uint8_t groove_get_macro(void)
{
    return g_groove.macro;
}

/* ------------------------------------------------------------
   Curve select
   ------------------------------------------------------------ */

void groove_set_timing_curve(uint8_t curve)
{
    g_groove.timing_curve = curve;
}

void groove_set_velocity_curve(uint8_t curve)
{
    g_groove.velocity_curve = curve;
}

/* ------------------------------------------------------------
   Amount
   ------------------------------------------------------------ */

void groove_set_timing_amount(uint8_t amt)
{
    g_groove.timing_amount = amt & 0x7F;
}

void groove_set_velocity_amount(uint8_t amt)
{
    g_groove.velocity_amount = amt & 0x7F;
}

/* ------------------------------------------------------------
   Evaluation
   ------------------------------------------------------------ */

int16_t groove_curve_timing_shape(uint8_t phase)
{
    if (!g_groove.enabled)
        return 0;

    int16_t shape;

    switch (g_groove.timing_curve)
    {
        default:
        case 0: shape = curve_linear(phase); break;
        case 1: shape = curve_swing(phase);  break;
        case 2: shape = curve_push(phase);   break;
    }

    return (shape * g_groove.timing_amount) / 127;
}

int16_t groove_curve_velocity_shape(uint8_t phase)
{
    if (!g_groove.enabled)
        return 0;

    int16_t shape;

    switch (g_groove.velocity_curve)
    {
        default:
        case 0: shape = curve_linear(phase); break;
        case 1: shape = curve_swing(phase);  break;
    }

    return (shape * g_groove.velocity_amount) / 127;
}
