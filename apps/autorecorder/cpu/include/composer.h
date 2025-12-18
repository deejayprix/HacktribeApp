#ifndef COMPOSER_H
#define COMPOSER_H

#include <stdint.h>
#include "ft_types.h"

/* ============================================================
   SECTION IDs (stabil)
   ============================================================ */
typedef enum {
    SECTION_INTRO = 0,
    SECTION_MAIN,
    SECTION_BREAK,
    SECTION_PEAK,
    SECTION_OUTRO
} composer_section_t;

/* ============================================================
   GENRE IDs (stabil, maschinenlesbar)
   ============================================================ */
typedef enum {
    GENRE_ACID_TECHNO = 0,
    GENRE_RAVE,
    GENRE_GABBER,
    GENRE_FRENCHCORE,
    GENRE_HAPPY_HARDCORE,
    GENRE_TECH_TRANCE,
    GENRE_TEKKNO,
    GENRE_COUNT
} composer_genre_t;

/* ============================================================
   FILL TYPES (Policy only)
   ============================================================ */
typedef enum {
    FILL_NONE = 0,
    FILL_GROOVE,
    FILL_BUILD,
    FILL_PUNCTUATION
} composer_fill_t;

/* ============================================================
   Composer State API
   ============================================================ */
void composer_init(void);

/* selected genre (for SongMode hooks / preset recall) */
void composer_set_genre(uint8_t genre_id);
uint8_t composer_get_genre(void);

/* current policy state (published for Conditions/SongMode) */
composer_fill_t composer_get_current_fill(void);
void composer_set_current_fill(composer_fill_t f);

/* ------------------------------------------------------------
   Preset Recall (Option 4)
   Apply policy ONLY (no generation / no write)
   ------------------------------------------------------------ */
void composer_preset_recall(uint8_t genre_id,
                            composer_section_t section,
                            uint8_t segment);

/* ------------------------------------------------------------
   Generation (optional / existing usage)
   ------------------------------------------------------------ */
void composer_generate_segment(uint8_t genre_id,
                               composer_section_t section,
                               uint8_t segment,
                               uint8_t target_page);

void composer_generate_section(uint8_t genre_id,
                               composer_section_t section,
                               uint8_t start_page);

void composer_generate_song(uint8_t genre_id,
                            uint8_t start_page);

/* ------------------------------------------------------------
   Song Mode Auto-Fill hook (Option 3)
   Call when a section/segment becomes active.
   Non-destructive: triggers Live-FX fill / boosts only.
   ------------------------------------------------------------ */
void composer_songmode_on_section(uint8_t section,
                                  uint8_t segment);

#endif /* COMPOSER_H */
