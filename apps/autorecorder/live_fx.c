#include "live_fx.h"
#include <stdint.h>

/* Global FX state */
live_fx_state_t g_live_fx = {
    .fill_strength = 0,
    .gate_lfo_period = 0,
    .gate_lfo_depth = 0,
    .gate_lfo_enabled = 0
};

static uint32_t g_lfo_phase = 0;

/* ------------------------------------------------------------- */
void live_fx_init(void)
{
    g_live_fx.fill_strength = 0;
    g_live_fx.gate_lfo_period = 0;
    g_live_fx.gate_lfo_depth = 0;
    g_live_fx.gate_lfo_enabled = 0;
    g_lfo_phase = 0;
}

/* ------------------------------------------------------------- */
void live_fx_tick(void)
{
    g_lfo_phase++;
}

/* ------------------------------------------------------------- */
void live_fx_set_fill(int strength)
{
    if (strength < 0) strength = 0;
    if (strength > 127) strength = 127;
    g_live_fx.fill_strength = strength;
}

int live_fx_get_fill(void)
{
    return g_live_fx.fill_strength;
}

/* ------------------------------------------------------------- */
void live_fx_set_gate_lfo(int period, int depth, int enable)
{
    if (period < 0) period = 0;
    if (depth < 0) depth = 0;
    if (depth > 127) depth = 127;

    g_live_fx.gate_lfo_period  = period;
    g_live_fx.gate_lfo_depth   = depth;
    g_live_fx.gate_lfo_enabled = enable ? 1 : 0;
}

/* ------------------------------------------------------------- */
/* NEW: Mod-Matrix compatible getters */
int live_fx_get_fill_state(void)
{
    return g_live_fx.fill_strength & 0x7F;
}

int live_fx_get_gate_lfo_value(void)
{
    if (!g_live_fx.gate_lfo_enabled || g_live_fx.gate_lfo_period <= 0)
        return 0;

    uint32_t period = g_live_fx.gate_lfo_period;
    uint32_t phase = g_lfo_phase % period;

    int depth = g_live_fx.gate_lfo_depth;
    int v;

    if (phase < period / 2)
        v = (phase * 127) / (period / 2);
    else
        v = ((period - phase) * 127) / (period / 2);

    v = (v * depth) / 127;

    return v & 0x7F;
}

/* ------------------------------------------------------------- */
/* Weak default implementation */
__attribute__((weak))
void live_fx_process_cycle(int part, struct ft_step *buffer, int count)
{
    (void) part;
    (void) buffer;
    (void) count;
}
/* ============================================================
   Minimal API used by NRPN Router
   ============================================================ */
void live_fx_set_variation_boost(int v)
{
    /* TODO: hook into your FX engine */
    (void)v;
}

void live_fx_trigger_fill_now(void)
{
    /* TODO: trigger FX fill mode */
}

void live_fx_set_mutation(int m)
{
    /* TODO: apply mutation to FX engine */
    (void)m;
}
