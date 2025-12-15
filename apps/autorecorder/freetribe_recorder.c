/*
 * freetribe_recorder.c
 *
 * Core app logic for AutoRecorder / Extended Pattern Engine
 * Integrates:
 *  - Randomizer Engine
 *  - NRPN Router
 *  - Live FX Overlay
 *  - Live Sync Layer (Phase 4.1)
 *  - Song Mode Hooks
 */

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

/* App-specific headers */
#include "ft_api.h"
#include "randomizer.h"
#include "nrpn_router.h"
#include "live_fx.h"
#include "song_mode.h"
#include "sync_live.h"

#include "pattern_writer.h"
#include "pattern_ram_map.h"

#include "Menu/Speichern/save_nrpn.h"
#include "Menu/Speichern/save_manager.h"
#include "Menu/Speichern/icons.h"
#include "ui_messages.h"



/* --------------------------------------------------------------------
   Internal State
   -------------------------------------------------------------------- */

static uint8_t g_record_armed = 0;
static uint8_t g_is_playing   = 0;

/* --------------------------------------------------------------------
   INIT
   -------------------------------------------------------------------- */

void app_init(void)
{
    /* LiveSync System (Phase 4.1) */
    live_sync_init();

    /* Randomizer defaults */
    randomizer_init_default();

    /* Song mode (if enabled) */
    song_mode_init();

    /* Initialize Live-FX subsystem */
    live_fx_init();

    g_record_armed = 0;
    g_is_playing = 0;
}

/* --------------------------------------------------------------------
   PLAY / STOP Hooks
   -------------------------------------------------------------------- */

void app_on_play(void)
{
    g_is_playing = 1;
    live_sync_on_start();
}

void app_on_stop(void)
{
    g_is_playing = 0;
    live_sync_on_stop();
}

/* --------------------------------------------------------------------
   RECORD ARM / DISARM
   -------------------------------------------------------------------- */

void recorder_arm(void)      { g_record_armed = 1; }
void recorder_disarm(void)   { g_record_armed = 0; }
uint8_t recorder_is_armed(void) { return g_record_armed; }

/* --------------------------------------------------------------------
   Main Tick — called every app cycle (≈1ms)
   -------------------------------------------------------------------- */

void app_tick(void)
{
    live_sync_tick();
    song_mode_tick();
    nrpn_router_tick();
    randomizer_tick_once();
    live_fx_tick();
}

/* --------------------------------------------------------------------
   Auto Pattern Generation
   -------------------------------------------------------------------- */

void recorder_generate_pattern(uint8_t part, uint8_t page)
{
    int steps = ft_get_pattern_step_count();

    if (steps <= 0)
        steps = 64;

    randomize_and_write_pattern_paged(part, steps, g_live.bar, page);
}

/* --------------------------------------------------------------------
   Manual Step Recording
   -------------------------------------------------------------------- */

void recorder_write_step(uint8_t part, uint8_t step, uint8_t pitch, uint8_t vel)
{
    if (!g_record_armed)
        return;

    ft_step_t s;
    s.part     = part;
    s.step     = step;
    s.pitch    = pitch;
    s.velocity = vel;
    s.gate     = (vel > 0) ? 1 : 0;

    ft_write_step(&s);
}

/* --------------------------------------------------------------------
   NRPN + MIDI CC handling
   -------------------------------------------------------------------- */

void app_handle_nrpn(uint16_t msb, uint16_t lsb, uint16_t value)
{
    nrpn_handle(msb, lsb, value);
}


void app_handle_midi_cc(uint8_t cc, uint8_t value)
{
    static int nrpn_msb = -1;
    static int nrpn_lsb = -1;

    switch (cc)
    {
        case 99: nrpn_msb = value; break; /* NRPN MSB */
        case 98: nrpn_lsb = value; break; /* NRPN LSB */

        case 6:  /* DATA ENTRY */
            if (nrpn_msb >= 0 && nrpn_lsb >= 0)
                nrpn_handle(nrpn_msb, nrpn_lsb, value);
            break;

        default:
            break;
    }
}

/* --------------------------------------------------------------------
   Debug
   -------------------------------------------------------------------- */

void app_debug_print_state(void)
{
    ft_print("LIVE SYNC:\n");
    ft_print("  step=%d bar=%d pattern=%d bpm=%.2f\n",
             g_live.step,
             g_live.bar,
             g_live.pattern,
             g_live.bpm_x100 / 100.0);
}

/* --------------------------------------------------------------------
   Main Entry
   -------------------------------------------------------------------- */

void app_main(void)
{
    ft_api_init_from_fw();

    for (;;) {
        /* idle mainloop */
    }
}
/* Beispiel-Handler, der vom Hardware-Button-ISR oder Poller aufgerufen wird.
   Bitte hooke diese Funktion an deinen Button-Event (ft_api / HW layer).
*/
void recorder_on_write_button(int shift_pressed)
{
    if (shift_pressed) {
        /* Write + Shift => Save-as (speichere unter neuem Namen)
           Wir starten Save-Request mit Mode=1 (Sysex + e2Pat) — du kannst ändern.
        */
        save_manager_request_save(SAVE_MODE_SYSEX_E2PAT, NULL);
        /* direkt in "Name eingeben" UI wechseln (UI-Flow nicht implementiert hier) */
        ui_show_message("Name eingeben");
        /* host may stream name via NRPN afterwards */
    } else {
        /* normal Write = quick-save using current defaults */
        save_manager_request_save(SAVE_MODE_SYSEX_E2PAT, NULL);
        /* automatically confirm for quick-save */
        save_manager_confirm(1);
    }
}