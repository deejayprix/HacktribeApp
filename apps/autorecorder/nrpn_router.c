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
#include "composer.h"

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
   DISPATCH
   ============================================================ */

static void nrpn_dispatch(uint16_t nrpn, int value)
{
    /* ========================================================
       7-bit groups
       ======================================================== */
    uint8_t msb = nrpn >> 7;
    uint8_t lsb = nrpn & 0x7F;

    /* --------------------------------------------------------
       MSB 40 — Randomizer
       -------------------------------------------------------- */
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

    /* --------------------------------------------------------
       MSB 41 — Global / Write / Undo / Song / Clear
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

            case 6:
                if (value == 1)
                    randomizer_undo_last_public();
                return;

            /* Song Mode NRPN passthrough */
            case 30:
                song_mode_handle_nrpn(70, value);
                return;

            case 50:
                if (value == 127)
                    pattern_clear_nrpn(-1);
                else
                    pattern_clear_nrpn(value);
                return;
        }

        ft_print("[NRPN 41] Unknown LSB=%d\n", lsb);
        return;
    }

    /* --------------------------------------------------------
       MSB 42 — Composer Presets (Step 9 Option 4 + Option 3 hook)
       -------------------------------------------------------- */
    if (msb == 42)
    {
        static int genre = GENRE_ACID_TECHNO;
        static int section = SECTION_INTRO;
        static int segment = 0;
        static int start_page = 0;

        switch (lsb)
        {
            case 0: genre = value; composer_set_genre((uint8_t)value); return;
            case 1: section = value; return;
            case 2: segment = value; return;
            case 3: start_page = value; return;

            /* Generate */
            case 10:
                if (value == 1)
                    composer_generate_segment((uint8_t)genre,
                                             (composer_section_t)section,
                                             (uint8_t)segment,
                                             (uint8_t)pattern_get_active_page());
                return;

            case 11:
                if (value == 1)
                    composer_generate_section((uint8_t)genre,
                                             (composer_section_t)section,
                                             (uint8_t)pattern_get_active_page());
                return;

            case 12:
                if (value == 1)
                    composer_generate_song((uint8_t)genre,
                                          (uint8_t)pattern_get_active_page());
                return;

            /* Preset Recall ONLY (Policy apply, no write) */
            case 20:
                if (value == 1)
                    composer_preset_recall((uint8_t)genre,
                                           (composer_section_t)section,
                                           (uint8_t)segment);
                return;

            /* SongMode “now active section/segment” hook */
            case 30:
                if (value == 1)
                    composer_songmode_on_section((uint8_t)section,
                                                 (uint8_t)segment);
                return;
        }

        ft_print("[NRPN 42] Unknown LSB=%d\n", lsb);
        return;
    }

    /* --------------------------------------------------------
       MSB 50 — Motion / Mod / Condition / Scale / Live FX
       -------------------------------------------------------- */
    if (msb == 50)
    {
        static int motion_lane = -1;
        static int motion_idx  = -1;

        switch (lsb)
        {
            case 80: motion_lane = value; return;
            case 81: randomizer_create_motion_lane(motion_lane, value); return;
            case 82: motion_lane = value; return;
            case 83: motion_idx = value; return;
            case 84: randomizer_set_motion_value(motion_lane, motion_idx, value); return;

            case 85: mod_matrix_stage_source(value); return;
            case 86: mod_matrix_stage_destination(value); return;
            case 87: mod_matrix_stage_argument(value); return;
            case 88: mod_matrix_stage_amount(value); return;
            case 89: mod_matrix_commit_route(); return;

            case 90: nrpn_condition_stage_part(value); return;
            case 91: nrpn_condition_stage_step(value); return;
            case 92: nrpn_condition_stage_node(value); return;
            case 94: nrpn_condition_commit(); return;

            case 100: nrpn_scale_stage_channel(value); return;
            case 101: nrpn_scale_stage_type(value); return;
            case 102: nrpn_scale_stage_tonic(value); return;
            case 103: nrpn_scale_commit(); return;
            case 104: nrpn_scale_reset(); return;

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

    uint32_t now = ft_get_ticks();
    nrpn_tx_check_timeout(now);

    if (cc == 99)
    {
        if (g_nrpn.active &&
            (now - g_nrpn.last_tick) < NRPN_MIN_GAP_TICKS)
            return;

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
        return;
    }
}

void nrpn_router_tick(void)
{
    /* reserved */
}
