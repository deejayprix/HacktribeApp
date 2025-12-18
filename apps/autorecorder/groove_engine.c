#include "groove_engine.h"
#include "randomizer.h"
#include "ft_api.h"
#include <string.h>

/* ============================================================
   INTERNAL STATE
   ============================================================ */

typedef struct {
    uint8_t microtiming;     /* 0..127 */
    uint8_t vel_swing;       /* 0..127 */
    uint8_t pattern_aware;   /* 0/1 */
} groove_part_t;

static groove_part_t g_groove[GROOVE_MAX_PARTS];

static int g_stage_part = 0;
static int g_selected_preset = 0;
static int g_debug_enabled = 0;

static inline int clampi(int v, int lo, int hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

/* ============================================================
   PRESET TABLE
   ============================================================ */

typedef struct {
    uint8_t micro;
    uint8_t vel;
    uint8_t pat;
} groove_preset_def_t;

static groove_preset_def_t preset_def(int preset_id)
{
    switch (preset_id)
    {
        default:
        case GROOVE_PRESET_OFF:         return (groove_preset_def_t){ 0,   0,   0 };
        case GROOVE_PRESET_MPC_LIGHT:   return (groove_preset_def_t){ 24,  18,  1 };
        case GROOVE_PRESET_MPC_HARD:    return (groove_preset_def_t){ 44,  34,  1 };
        case GROOVE_PRESET_SHUFFLE_57:  return (groove_preset_def_t){ 36,  10,  1 };
        case GROOVE_PRESET_SHUFFLE_62:  return (groove_preset_def_t){ 56,  14,  1 };
        case GROOVE_PRESET_HUMAN_LIGHT: return (groove_preset_def_t){ 18,  26,  1 };
        case GROOVE_PRESET_HUMAN_HARD:  return (groove_preset_def_t){ 40,  52,  1 };
    }
}

/* ============================================================
   API
   ============================================================ */

void groove_init(void)
{
    memset(g_groove, 0, sizeof(g_groove));
    g_stage_part = 0;
    g_selected_preset = 0;
    g_debug_enabled = 0;
}

void groove_stage_part(int part)
{
    g_stage_part = clampi(part, 0, GROOVE_MAX_PARTS - 1);
}

int groove_get_staged_part(void)
{
    return g_stage_part;
}

void groove_set_microtiming(int part, int amount)
{
    part   = clampi(part, 0, GROOVE_MAX_PARTS - 1);
    amount = clampi(amount, 0, 127);
    g_groove[part].microtiming = (uint8_t)amount;
}

void groove_set_velocity_swing(int part, int amount)
{
    part   = clampi(part, 0, GROOVE_MAX_PARTS - 1);
    amount = clampi(amount, 0, 127);
    g_groove[part].vel_swing = (uint8_t)amount;
}

void groove_set_pattern_aware(int part, int en)
{
    part = clampi(part, 0, GROOVE_MAX_PARTS - 1);
    g_groove[part].pattern_aware = en ? 1 : 0;
}

void groove_preset_select(int preset_id)
{
    g_selected_preset = clampi(preset_id, 0, 127);
}

int groove_get_selected_preset(void)
{
    return g_selected_preset;
}

void groove_preset_apply_to_part(int part)
{
    part = clampi(part, 0, GROOVE_MAX_PARTS - 1);

    groove_preset_def_t d = preset_def(g_selected_preset);
    g_groove[part].microtiming   = d.micro;
    g_groove[part].vel_swing     = d.vel;
    g_groove[part].pattern_aware = d.pat;
}

/* ============================================================
   RUNTIME HELPERS
   ============================================================ */

int groove_apply_velocity(int part, int base_vel, int step, int sub_idx, int sub_total)
{
    (void)sub_total;

    part = clampi(part, 0, GROOVE_MAX_PARTS - 1);
    base_vel = clampi(base_vel, 0, 127);

    int amt = (int)g_groove[part].vel_swing; /* 0..127 */
    if (amt == 0) return base_vel;

    int accent = ((sub_idx & 1) == 0) ? +1 : -1;

    if (g_groove[part].pattern_aware)
    {
        int s16 = step & 0x0F;
        if (s16 == 4 || s16 == 12) accent *= 2;
    }

    int delta = (amt * 24) / 127;
    int out = base_vel + (accent * delta);

    if (out < 1) out = 1;
    if (out > 127) out = 127;
    return out;
}

int groove_get_timing_offset_ticks(int part, int step, int step_len_ticks, int sub_idx, int sub_total)
{
    (void)sub_total;

    part = clampi(part, 0, GROOVE_MAX_PARTS - 1);
    if (step_len_ticks < 1) step_len_ticks = 1;

    int amt = (int)g_groove[part].microtiming; /* 0..127 */
    if (amt == 0) return 0;

    int max_off = step_len_ticks / 8;
    if (max_off < 1) max_off = 1;

    int off = (amt * max_off) / 127;

    int sign = ((sub_idx & 1) == 0) ? -1 : +1;

    if (g_groove[part].pattern_aware)
    {
        int s16 = step & 0x0F;
        if (s16 == 4 || s16 == 12) sign = +1;
    }

    return sign * off;
}

/* ============================================================
   DEBUG
   ============================================================ */

void groove_debug_enable(int on)
{
    g_debug_enabled = (on != 0);
}

int groove_debug_is_enabled(void)
{
    return g_debug_enabled;
}

void groove_debug_dump_part(int part)
{
    if (!g_debug_enabled)
        return;

    part = clampi(part, 0, GROOVE_MAX_PARTS - 1);

    ft_print("[GROOVE DBG] part=%d micro=%d vel=%d pat=%d preset=%d\n",
             part,
             (int)g_groove[part].microtiming,
             (int)g_groove[part].vel_swing,
             (int)g_groove[part].pattern_aware,
             (int)g_selected_preset);
}

void groove_debug_dump_staged(void)
{
    groove_debug_dump_part(g_stage_part);
}
