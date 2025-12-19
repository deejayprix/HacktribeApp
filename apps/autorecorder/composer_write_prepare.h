#ifndef COMPOSER_WRITE_PREPARE_H
#define COMPOSER_WRITE_PREPARE_H

#include <stdint.h>
#include "composer.h"

/* ============================================================
   CONSTANTS
   ============================================================ */

#define COMPOSER_PATTERN_BARS      4
#define COMPOSER_MAX_PATTERN_SLOTS 250

/* ============================================================
   WRITE PREPARED ENTRY
   ============================================================ */

typedef struct {
    uint16_t slot;        /* 1..250 */
    uint16_t bar_start;   /* timeline bar index */
    composer_section_t section;
    uint8_t  segment;    /* 0..3 (A/B/C/D) */
} composer_write_entry_t;

/* ============================================================
   API
   ============================================================ */

/* reset internal buffer */
void composer_write_prepare_reset(void);

/* build mapping from timeline */
int composer_write_prepare_build(uint16_t first_slot);

/* query results */
uint16_t composer_write_prepare_count(void);
const composer_write_entry_t *
composer_write_prepare_get(uint16_t index);

#endif /* COMPOSER_WRITE_PREPARE_H */
