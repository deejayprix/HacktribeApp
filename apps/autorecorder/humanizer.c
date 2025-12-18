/* ============================================================
   apps/autorecorder/humanizer.c
   ============================================================ */
#include "humanizer.h"

/* ------------------------------------------------------------
   Internal state (deterministisch, keine RNG hier)
   ------------------------------------------------------------ */
static uint8_t g_enabled = 0;
static int g_timing_ticks = 0;   /* 0..N */
static int g_vel_amount   = 0;   /* 0..N */

void humanizer_set_enabled(int en)
{
    g_enabled = en ? 1 : 0;
}

int humanizer_get_enabled(void)
{
    return (int)g_enabled;
}

void humanizer_set_timing_amount_ticks(int ticks)
{
    if (ticks < 0) ticks = 0;
    if (ticks > 16) ticks = 16; /* hard cap */
    g_timing_ticks = ticks;
}

int humanizer_get_timing_amount_ticks(void)
{
    return g_timing_ticks;
}

void humanizer_set_velocity_amount(int amount)
{
    if (amount < 0) amount = 0;
    if (amount > 64) amount = 64; /* hard cap */
    g_vel_amount = amount;
}

int humanizer_get_velocity_amount(void)
{
    return g_vel_amount;
}
