/* ============================================================
   apps/autorecorder/nrpn_router.c   (vollständig)
   + 3.2.3.13.4 – Final Defaults & Phase-3-Lock
   NRPN: MSB 51 / LSB 3,4,20,21
   ============================================================ */
#include <stdint.h>
#include <stdio.h>

#include "nrpn_router.h"
#include "randomizer.h"
#include "mod_matrix.h"
#include "condition_engine.h"
#include "condition_presets.h"
#include "live_fx.h"
#include "pattern_writer.h"
#include "pattern_ram_map.h"
#include "song_mode.h"
#include "ft_api.h"
#include "scale_engine.h"
#include "composer.h"
#include "groove_engine.h"

/* ============================================================
   NRPN TRANSACTION GUARD
   ============================================================ */

#define NRPN_TX_TIMEOUT_TICKS   5
#define NRPN_MIN_GAP_TICKS     25

typedef struct {
    int msb;
    int lsb;
    uint32_t last_tick;
    uint8_t active;
} nrpn_tx_state_t;

static nrpn_tx_state_t g_nrpn = {
    .msb = -1,
    .lsb = -1,
    .last_tick = 0,
    .active = 0
};

/* Condition staging */
static int g_cond_part = 0;
static int g_cond_step = 0;

/* ============================================================
   INTERNAL HELPERS
   ============================================================ */

static inline void nrpn_tx_reset(void)
{
    g_nrpn.msb = -1;
    g_nrpn.lsb = -1;
    g_nrpn.active = 0;
}

static inline void nrpn_tx_check_timeout(uint32_t now)
{
    if (g_nrpn.active &&
        (now - g_nrpn.last_tick) > NRPN_TX_TIMEOUT_TICKS)
    {
        nrpn_tx_reset();
    }
}

static inline uint16_t nrpn_build_id(void)
{
    if (g_nrpn.msb < 0 || g_nrpn.lsb < 0)
        return 0xFFFF;

    return (uint16_t)((g_nrpn.msb << 7) | g_nrpn.lsb);
}

/* ============================================================
   NRPN DISPATCH
   ============================================================ */

static void nrpn_dispatch(uint16_t nrpn, int value)
{
    uint8_t msb = (uint8_t)(nrpn >> 7);
    uint8_t lsb = (uint8_t)(nrpn & 0x7F);

    /* --------------------------------------------------------
       MSB 40 — Randomizer Core
       -------------------------------------------------------- */
    if (msb == 40)
    {
        switch (lsb)
        {
            case 10: randomizer_set_density(value);   return;
            case 11: randomizer_set_variation(value); return;
            case 15: randomizer_set_freeze(value);    return;
            case 20: randomizer_set_section(value);   return;
            case 80: randomizer_set_seed(value);      return;
        }
        return;
    }

    /* --------------------------------------------------------
       MSB 41 — Global / Write / Song / Clear
       -------------------------------------------------------- */
    if (msb == 41)
    {
        switch (lsb)
        {
            case 0:
                if (value == 1)
                {
                    int ps = pattern_get_paging_page_size();
                    int pg = pattern_get_active_page();
                    for (int p = 0; p < RANDOMIZER_MAX_CHANNELS; ++p)
                        randomize_and_write_pattern_paged(
                            p, ps,
                            randomizer_get_section(),
                            pg
                        );
                }
                return;

            case 3:
                randomize_and_write_pattern_paged(
                    value,
                    pattern_get_paging_page_size(),
                    randomizer_get_section(),
                    pattern_get_active_page()
                );
                return;

            case 6:
                if (value == 1)
                    randomizer_undo_last_public();
                return;

            case 30:
                song_mode_handle_nrpn(70, value);
                return;

            case 50:
                pattern_clear_nrpn(value == 127 ? -1 : value);
                return;
        }
        return;
    }

    /* --------------------------------------------------------
       MSB 50 — Condition / Randomizer Extensions / Debug
       -------------------------------------------------------- */
    if (msb == 50)
    {
        switch (lsb)
        {
            /* Condition addressing */
            case 90: g_cond_part = value; nrpn_condition_stage_part(value); return;
            case 91: g_cond_step = value; nrpn_condition_stage_step(value); return;

            /* Node staging */
            case 92: nrpn_condition_stage_node(value); return;
            case 94: nrpn_condition_commit(); return;

            /* Node editing */
            case 93: nrpn_condition_node_create(value); return;
            case 95: nrpn_condition_node_set_param(value); return;
            case 96: nrpn_condition_node_to_and(value); return;
            case 97: nrpn_condition_node_to_or(value); return;
            case 98: nrpn_condition_node_to_not(); return;
            case 99: nrpn_condition_node_delete(value); return;

            /* Phase 3.2.1 — Per-Step Probability */
            case 110:
                condition_set_step_probability(
                    g_cond_part,
                    g_cond_step,
                    value
                );
                return;

            /* Phase 3.2.2 — Step Repeater */
            case 111:
                randomizer_set_step_repeat(
                    g_cond_part,
                    g_cond_step,
                    value
                );
                return;

            /* Phase 3.1.5 — Condition Preset Browser */
            case 112: condition_preset_select(value); return;
            case 113: condition_preset_set_param(value); return;
            case 114: if (value == 1) condition_preset_apply_to_staged_step(); return;
            case 115: if (value == 1) condition_preset_dump(); return;

            /* Debug Visualizer */
            case 120: condition_debug_enable(value); return;
            case 121: condition_debug_select(value, g_cond_step); return;
            case 122: condition_debug_select(g_cond_part, value); return;
            case 123: condition_debug_dump_step(); return;
            case 124: condition_debug_dump_node(value); return;

            /* Live FX */
            case 60: live_fx_set_variation_boost(value); return;
            case 61: live_fx_trigger_fill_now(); return;
            case 62: live_fx_set_mutation(value); return;
        }
        return;
    }

    /* --------------------------------------------------------
       MSB 51 — Groove Engine
       -------------------------------------------------------- */
    if (msb == 51)
    {
        switch (lsb)
        {
            /* 3.2.3.2 Micro-Timing Amount */
            case 3:
                groove_set_timing_amount((uint8_t)(value & 0x7F));
                return;

            /* 3.2.3.3 Velocity Swing Amount */
            case 4:
                groove_set_velocity_amount((uint8_t)(value & 0x7F));
                return;

            /* 3.2.3.12 One-Knob Macro */
            case 20:
                groove_set_macro((uint8_t)(value & 0x7F));
                return;

            /* 3.2.3.13.4 Phase-3 Lock (Enable) */
            case 21:
                groove_set_enabled((uint8_t)(value ? 1 : 0));
                return;
        }
        return;
    }
}

/* ============================================================
   PUBLIC MIDI CC → NRPN ENTRY
   ============================================================ */

void nrpn_handle(int channel, int cc, int value)
{
    (void)channel;

    uint32_t now = ft_get_ticks();
    nrpn_tx_check_timeout(now);

    if (cc == 99)
    {
        g_nrpn.msb = value & 0x7F;
        g_nrpn.active = 1;
        g_nrpn.last_tick = now;
        return;
    }

    if (cc == 98 && g_nrpn.active)
    {
        g_nrpn.lsb = value & 0x7F;
        g_nrpn.last_tick = now;
        return;
    }

    if ((cc == 6 || cc == 38) && g_nrpn.active)
    {
        uint16_t id = nrpn_build_id();
        if (id != 0xFFFF)
            nrpn_dispatch(id, value & 0x7F);

        nrpn_tx_reset();
    }
}

void nrpn_router_tick(void)
{
    /* reserved */
}
