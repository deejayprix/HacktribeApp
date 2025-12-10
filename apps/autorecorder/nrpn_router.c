/**
 * nrpn_router.c – FINAL SYNCHRONIZED VERSION (Variant A)
 *
 * Compatible with:
 *  - Randomizer v3.x (NO Euclid Probability)
 *  - Euclid Engine v2
 *  - Condition Engine v2
 *  - Scale Engine v2
 *  - Mod Matrix v2
 *  - Motion Engine v2
 *  - Live FX
 */

#include <stdint.h>
#include <stdio.h>

#include "nrpn_router.h"
#include "randomizer.h"
#include "mod_matrix.h"
#include "condition_engine.h"
#include "live_fx.h"
#include "pattern_writer.h"
#include "pattern_ram_map.h"
#include "song_mode.h"
#include "ft_api.h"
#include "scale_engine.h"

/* ============================================================
   INTERNAL NRPN STATE (CC99/98 + CC06/38)
   ============================================================ */
static int nrpn_msb = -1;
static int nrpn_lsb = -1;

static inline void nrpn_reset(void)
{
    nrpn_msb = -1;
    nrpn_lsb = -1;
}

static inline uint16_t nrpn_build_id(void)
{
    if (nrpn_msb < 0 || nrpn_lsb < 0) return 0xFFFF;
    return (uint16_t)((nrpn_msb << 7) | nrpn_lsb);
}

/* ============================================================
   EUCLID NRPN CONSTANTS (16-bit)
   ============================================================ */
#define NRPN_EU_CHANNEL       0x2100
#define NRPN_EU_SLOT          0x2101
#define NRPN_EU_PULSES        0x2102
#define NRPN_EU_STEPS         0x2103
#define NRPN_EU_ROTATION      0x2104
#define NRPN_EU_PROBABILITY   0x2105 /* NOT USED IN VARIANT A (NO-OP) */
#define NRPN_EU_MODE          0x2106
#define NRPN_EU_COMMIT        0x2107
#define NRPN_EU_ENABLE        0x2108
#define NRPN_EU_ROTATE_LIVE   0x2109

/* Forward EUCLID staging vars (declared in randomizer.c) */
extern int eu_stage_channel;
extern int eu_stage_slot;

/* ============================================================
   16-BIT NRPN DISPATCHER
   ============================================================ */
static void nrpn_dispatch(uint16_t nrpn, int value)
{
    switch (nrpn)
    {
        /* -----------------  EUCLID ENGINE  ----------------- */

        case NRPN_EU_CHANNEL:
            randomizer_euclid_stage_channel(value);
            return;

        case NRPN_EU_SLOT:
            randomizer_euclid_stage_slot(value);
            return;

        case NRPN_EU_PULSES:
            randomizer_euclid_stage_pulses(value);
            return;

        case NRPN_EU_STEPS:
            randomizer_euclid_stage_steps(value);
            return;

        case NRPN_EU_ROTATION:
            randomizer_euclid_stage_rotation(value);
            return;

        /* Variant A → Probability removed */
        case NRPN_EU_PROBABILITY:
            /* NO-OP */
            return;

        case NRPN_EU_MODE:
            randomizer_euclid_stage_mode((uint8_t)(value & 0x7F));
            return;

        case NRPN_EU_COMMIT:
            randomizer_euclid_commit();
            return;

        case NRPN_EU_ENABLE:
            randomizer_euclid_set_enabled(
                eu_stage_channel,
                eu_stage_slot,
                value ? 1 : 0
            );
            return;

        case NRPN_EU_ROTATE_LIVE:
        {
            int delta = (value > 63) ? value - 128 : value;
            randomizer_euclid_live_rotate(
                eu_stage_channel,
                eu_stage_slot,
                delta
            );
            return;
        }
    }

    /* ====================================================
       7-bit NRPN handling (MSB = 40 / 41 / 50 category)
       ==================================================== */

    uint8_t msb = nrpn >> 7;
    uint8_t lsb = nrpn & 0x7F;

    /* -----------------------------
       MSB 40 — Randomizer 
       ----------------------------- */
    if (msb == 40)
    {
        switch (lsb)
        {
            case 10: randomizer_set_density(value); return;
            case 11: randomizer_set_variation(value); return;
            case 15: randomizer_set_freeze(value); return;
            case 20: randomizer_set_section(value); return;
            case 80: randomizer_set_seed(value); return;

            default:
                ft_print("[NRPN 40] Unknown LSB=%d\n", lsb);
                return;
        }
    }

    /* ----------------------------------------------
       MSB 41 — Randomizer global / write / undo etc.
       ---------------------------------------------- */
    if (msb == 41)
    {
        switch (lsb)
        {
            case 0: /* Write all parts */
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

            case 3: /* Write single part */
                if (value >= 0 && value < RANDOMIZER_MAX_CHANNELS)
                {
                    int ps = pattern_get_paging_page_size();
                    randomize_and_write_pattern_paged(
                        value, ps,
                        randomizer_get_section(),
                        pattern_get_active_page()
                    );
                }
                return;

            case 6: /* Undo */
                if (value == 1)
                    randomizer_undo_last_public();
                return;

            case 30: /* Song Mode */
                song_mode_handle_nrpn(70, value);
                return;

            case 50: /* Pattern Clear */
                if (value == 127)
                    pattern_clear_nrpn(-1);
                else
                    pattern_clear_nrpn(value);
                return;
        }

        ft_print("[NRPN 41] Unknown LSB=%d\n", lsb);
        return;
    }

    /* ---------------------------------------------------
       MSB 50 — Motion / Mod Matrix / Scale / Conditions
       --------------------------------------------------- */
    if (msb == 50)
    {
        static int motion_lane = -1;
        static int motion_idx = -1;

        switch (lsb)
        {
            /* ===== MOTION ENGINE ===== */
            case 80: motion_lane = value; return;                    /* select lane */
            case 81: randomizer_create_motion_lane(motion_lane, value); return;
            case 82: motion_lane = value; return;                    /* select lane again */
            case 83: motion_idx = value; return;                     /* index */
            case 84: randomizer_set_motion_value(motion_lane, motion_idx, value); return;

            /* ===== MOD MATRIX ===== */
            case 85: mod_matrix_stage_source(value); return;
            case 86: mod_matrix_stage_destination(value); return;
            case 87: mod_matrix_stage_argument(value); return;
            case 88: mod_matrix_stage_amount(value); return;
            case 89: mod_matrix_commit_route(); return;

            /* ===== CONDITIONS ===== */
            case 90: nrpn_condition_stage_part(value); return;
            case 91: nrpn_condition_stage_step(value); return;
            case 92: nrpn_condition_stage_node(value); return;
            case 94: nrpn_condition_commit(); return;

            /* ===== SCALE ENGINE ===== */
            case 100: nrpn_scale_stage_channel(value); return;
            case 101: nrpn_scale_stage_type(value); return;
            case 102: nrpn_scale_stage_tonic(value); return;
            case 103: nrpn_scale_commit(); return;
            case 104: nrpn_scale_reset(); return;

            /* ===== LIVE FX ===== */
            case 60: live_fx_set_variation_boost(value); return;
            case 61: live_fx_trigger_fill_now(); return;
            case 62: live_fx_set_mutation(value); return;

            default:
                ft_print("[NRPN 50] Unknown LSB=%d\n", lsb);
                return;
        }
    }

    ft_print("[NRPN] Unknown MSB=%d LSB=%d\n", msb, lsb);
}

/* ============================================================
   PUBLIC MIDI CC → NRPN ENTRY
   ============================================================ */
void nrpn_handle(int channel, int cc, int value)
{
    (void)channel;

    if (cc == 99) { nrpn_msb = value; return; }
    if (cc == 98) { nrpn_lsb = value; return; }

    if (cc == 6 || cc == 38)
    {
        uint16_t id = nrpn_build_id();
        if (id != 0xFFFF)
            nrpn_dispatch(id, value);

        nrpn_reset();
        return;
    }
}

/* Optional tick hook */
void nrpn_router_tick(void)
{
}
