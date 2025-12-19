#ifndef COMPOSER_TIMELINE_H
#define COMPOSER_TIMELINE_H

#include <stdint.h>
#include "composer.h"

/* ============================================================
   Timeline Layout
   ============================================================ */

/* Max number of timeline sections stored */
#ifndef COMPOSER_MAX_SECTIONS
#define COMPOSER_MAX_SECTIONS 8
#endif

/* Max bars supported by timeline (storage + safety) */
#ifndef COMPOSER_MAX_BARS
#define COMPOSER_MAX_BARS 512
#endif

/* Steps per bar (Electribe style: 16 steps per bar) */
#ifndef COMPOSER_STEPS_PER_BAR
#define COMPOSER_STEPS_PER_BAR 16
#endif

/* Policy segments are A/B/C/D -> 0..3
   We map segments as 4 bars each by default. */
#ifndef COMPOSER_BARS_PER_SEGMENT
#define COMPOSER_BARS_PER_SEGMENT 4
#endif

typedef struct {
    composer_section_t section;   /* INTRO/MAIN/BREAK/PEAK/OUTRO */
    uint16_t bar_start;           /* inclusive */
    uint16_t bar_length;          /* number of bars */
} composer_timeline_section_t;

typedef struct {
    uint16_t total_bars;

    composer_timeline_section_t sections[COMPOSER_MAX_SECTIONS];
    uint8_t  section_count;

    /* playhead (optional realtime usage) */
    uint8_t  playing;
    uint16_t playhead_bar;
    uint16_t playhead_step;
} composer_timeline_t;

/* ============================================================
   API
   ============================================================ */

void     composer_timeline_init(uint16_t total_bars);

/* Adds a section block starting at bar_start for bar_length bars */
int      composer_timeline_add_section(composer_section_t section,
                                       uint16_t bar_start,
                                       uint16_t bar_length);

/* Optional transport */
void     composer_timeline_play(void);
void     composer_timeline_stop(void);
void     composer_timeline_tick(void);

/* Query (playhead-based) */
composer_section_t composer_timeline_get_active_section(void);
uint16_t composer_timeline_get_playhead_bar(void);
uint16_t composer_timeline_get_playhead_step(void);

/* Query (bar-based) — REQUIRED by composer_preview.c */
composer_section_t composer_timeline_get_section_at_bar(uint16_t bar);
uint8_t            composer_timeline_get_segment_at_bar(uint16_t bar);
uint16_t           composer_timeline_get_total_bars(void);

#endif /* COMPOSER_TIMELINE_H */
