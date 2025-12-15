#ifndef SONG_MODE_H
#define SONG_MODE_H

#include <stdint.h>
#include <stdbool.h>
#include "pattern_writer.h"

/*
 Song Mode API for Freetribe / Hacktribe autorecorder app
 - Simple arranger: chains PatternID + bars + repeats
 - Uses existing Panel Hooks for play/stop/record/write
 - Uses FT_DEFAULT_BPM fallback for timing, but will use firmware BPM if available
*/

/* Max entries in a song */
#define SONG_MAX_ENTRIES 128

/* One song entry: play pattern 'pattern' for 'bars' bars, repeat 'repeats' times.
 * if write_after = true, do panel_write() after playing the bars (useful for auto-record)
 */
typedef struct {
    int pattern;        /* pattern number */
    int bars;           /* bars to play */
    int repeats;        /* repeat count (>=1) */
    bool write_after;   /* write after each repeat */
} song_entry_t;

/* A Song container */
typedef struct {
    char name[32];
    song_entry_t entries[SONG_MAX_ENTRIES];
    int entry_count;
} song_t;

/* Init / tick functions */
void song_mode_init(void);
void song_mode_tick(void); /* call regularly from app_tick */

/* Song control */
int song_mode_load_song(const song_t *s); /* load into RAM, returns 0 ok */
void song_mode_clear(void);
void song_mode_start(void);
void song_mode_stop(void);
void song_mode_pause(void);
bool song_mode_is_running(void);

/* Song editing helpers */
int song_mode_add_entry(int pattern, int bars, int repeats, bool write_after); /* returns index or -1 */
void song_mode_set_entry(int idx, int pattern, int bars, int repeats, bool write_after);

/* Jump / navigation */
void song_mode_next(void);
void song_mode_prev(void);
void song_mode_goto(int entry_index);

/* Query */
int song_mode_get_current_index(void);
int song_mode_get_entry_count(void);

/* NRPN handler hook (call from nrpn_router when MSB=127) */
void song_mode_handle_nrpn(int lsb, int value);

#endif // SONG_MODE_H
