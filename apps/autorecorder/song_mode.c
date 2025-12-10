// song_mode.c
// Song Mode 2.0 — arranger / sequencer for autorecorder app

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "song_mode.h"
#include "ft_config.h"
#include "panel_hooks.h"
#include "pattern_writer.h"
#include "ft_api.h"


// optional: use firmware BPM if configured
static int song_mode_get_bpm(void)
{
    if ((uintptr_t)ADDR_GET_BPM_FUNC != 0 && FT_USE_FW_GET_BPM) {
        typedef int (*bpm_fn_t)(void);
        bpm_fn_t f = (bpm_fn_t)ADDR_GET_BPM_FUNC;
        if (f) return f();
    }
    return FT_DEFAULT_BPM;
}

// simple busy-wait ms delay (safe fallback)
static void song_mode_delay_ms(int ms)
{
    volatile int i;
    // calibrated previously in recorder; keep same multiplier
    for (i = 0; i < ms * 2000; ++i) {
        __asm__ volatile("nop");
    }
}

// convert bars -> milliseconds (4/4 assumed)
static int song_mode_bars_to_ms(int bars)
{
    int bpm = song_mode_get_bpm();
    if (bpm <= 0) bpm = FT_DEFAULT_BPM;
    int ms_per_beat = 60000 / bpm;
    int ms_per_bar = ms_per_beat * 4;
    return ms_per_bar * bars;
}

/* Internal state */
static song_t g_song;
static bool g_running = false;
static bool g_paused = false;
static int g_current_entry = 0;
static int g_current_repeat = 0;
static int g_current_phase = 0; // 0 idle, 1 playing
static int g_wait_remaining_ms = 0;

/* Helper to set pattern + play + optionally record/write (synchronous) */
static void song_mode_play_entry_once(const song_entry_t *e)
{
    if (!e) return;

    // set pattern number and small delay for GUI settle
    set_pattern_number(e->pattern);
    song_mode_delay_ms(60);

    // start playing
    panel_play();
    song_mode_delay_ms(20);

    // if pattern should be recorded, press record
    // decision: if write_after==true we assume pattern is being recorded live,
    // otherwise simply play the pattern.
    if (e->write_after) {
        panel_record();
    }

    // wait bars
    int wait_ms = song_mode_bars_to_ms(e->bars);
    // wait in smaller chunks to allow pause/stop responsiveness
    int chunk = 100; // 100ms
    int waited = 0;
    while (waited < wait_ms) {
        if (!g_running || g_paused) break;
        int rem = wait_ms - waited;
        int step = (rem < chunk) ? rem : chunk;
        song_mode_delay_ms(step);
        waited += step;
    }

    // stop
    panel_stop();
    song_mode_delay_ms(20);

    // write after if requested (press WRITE)
    if (e->write_after) {
        panel_write();
        song_mode_delay_ms(50);
    }
}

/* Initialize internal structures */
void song_mode_init(void)
{
    memset(&g_song, 0, sizeof(g_song));
    g_running = false;
    g_paused = false;
    g_current_entry = 0;
    g_current_repeat = 0;
    g_current_phase = 0;
    g_wait_remaining_ms = 0;
}

/* Load a song into RAM (copy). Returns 0 on success. */
int song_mode_load_song(const song_t *s)
{
    if (!s) return -1;
    memcpy(&g_song, s, sizeof(song_t));
    if (g_song.entry_count < 0) g_song.entry_count = 0;
    if (g_song.entry_count > SONG_MAX_ENTRIES) g_song.entry_count = SONG_MAX_ENTRIES;
    return 0;
}

void song_mode_clear(void)
{
    memset(&g_song, 0, sizeof(g_song));
    g_current_entry = 0;
    g_current_repeat = 0;
}

/* Start playback from current entry */
void song_mode_start(void)
{
    if (g_song.entry_count <= 0) return;
    g_running = true;
    g_paused = false;
}

/* Stop and reset */
void song_mode_stop(void)
{
    g_running = false;
    g_paused = false;
    g_current_entry = 0;
    g_current_repeat = 0;
    g_current_phase = 0;
}

/* Pause */
void song_mode_pause(void)
{
    if (!g_running) return;
    g_paused = !g_paused;
}

/* Is running? */
bool song_mode_is_running(void)
{
    return g_running && !g_paused;
}

/* Add entry (appends) returns index or -1 */
int song_mode_add_entry(int pattern, int bars, int repeats, bool write_after)
{
    if (g_song.entry_count >= SONG_MAX_ENTRIES) return -1;
    int idx = g_song.entry_count++;
    g_song.entries[idx].pattern = pattern;
    g_song.entries[idx].bars = (bars <= 0) ? 1 : bars;
    g_song.entries[idx].repeats = (repeats <= 0) ? 1 : repeats;
    g_song.entries[idx].write_after = write_after;
    return idx;
}

/* set entry */
void song_mode_set_entry(int idx, int pattern, int bars, int repeats, bool write_after)
{
    if (idx < 0 || idx >= g_song.entry_count) return;
    g_song.entries[idx].pattern = pattern;
    g_song.entries[idx].bars = (bars <= 0) ? 1 : bars;
    g_song.entries[idx].repeats = (repeats <= 0) ? 1 : repeats;
    g_song.entries[idx].write_after = write_after;
}

/* navigation */
void song_mode_next(void)
{
    if (g_song.entry_count <= 0) return;
    g_current_repeat = 0;
    g_current_entry++;
    if (g_current_entry >= g_song.entry_count) g_current_entry = 0;
}
void song_mode_prev(void)
{
    if (g_song.entry_count <= 0) return;
    g_current_repeat = 0;
    g_current_entry--;
    if (g_current_entry < 0) g_current_entry = g_song.entry_count - 1;
}
void song_mode_goto(int entry_index)
{
    if (entry_index < 0 || entry_index >= g_song.entry_count) return;
    g_current_entry = entry_index;
    g_current_repeat = 0;
}

/* simple tick — to be called from app_tick() frequently */
void song_mode_tick(void)
{
    if (!g_running || g_paused) return;
    if (g_song.entry_count <= 0) return;

    // play current entry repeats times
    song_entry_t *e = &g_song.entries[g_current_entry];
    if (!e) return;

    // play one repeat
    song_mode_play_entry_once(e);

    // advance repeat counter
    g_current_repeat++;
    if (g_current_repeat >= e->repeats) {
        // next entry
        g_current_repeat = 0;
        g_current_entry++;
        if (g_current_entry >= g_song.entry_count) {
            // loop back to beginning
            g_current_entry = 0;
            // stop if you prefer non-looping behavior:
            // g_running = false;
        }
    }
}

/* Query functions */
int song_mode_get_current_index(void) { return g_current_entry; }
int song_mode_get_entry_count(void) { return g_song.entry_count; }

/* NRPN handler: map some LSBs to song mode controls
   - 70 = SONG_START (value 1 start, 0 stop)
   - 71 = SONG_NEXT (value 1 -> next)
   - 72 = SONG_PREV (value 1 -> prev)
   - 73 = SONG_GOTO (value = index)
   - 74 = SONG_ADD_ENTRY (value = pattern id; uses 1 bar, 1 repeat, no write)
   - 75 = SONG_CLEAR (value 1 -> clear)
*/
void song_mode_handle_nrpn(int lsb, int value)
{
    switch (lsb) {
        case 70:
            if (value) song_mode_start(); else song_mode_stop();
            break;
        case 71:
            if (value) song_mode_next();
            break;
        case 72:
            if (value) song_mode_prev();
            break;
        case 73:
            song_mode_goto(value);
            break;
        case 74:
            // append pattern=value
            song_mode_add_entry(value, 1, 1, false);
            break;
        case 75:
            if (value) song_mode_clear();
            break;
        default:
            break;
    }
}
