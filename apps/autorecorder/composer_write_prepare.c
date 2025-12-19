#include "composer_write_prepare.h"
#include "composer_timeline.h"
#include <string.h>

/* ============================================================
   INTERNAL STATE
   ============================================================ */

static composer_write_entry_t g_entries[COMPOSER_MAX_PATTERN_SLOTS];
static uint16_t g_entry_count = 0;

/* ============================================================
   RESET
   ============================================================ */

void composer_write_prepare_reset(void)
{
    memset(g_entries, 0, sizeof(g_entries));
    g_entry_count = 0;
}

/* ============================================================
   BUILD WRITE MAP
   ============================================================ */

int composer_write_prepare_build(uint16_t first_slot)
{
    composer_write_prepare_reset();

    if (first_slot == 0)
        first_slot = 1;

    uint16_t total_bars = composer_timeline_get_total_bars();
    uint16_t bar = 0;
    uint16_t slot = first_slot;

    while (bar < total_bars &&
           g_entry_count < COMPOSER_MAX_PATTERN_SLOTS &&
           slot <= COMPOSER_MAX_PATTERN_SLOTS)
    {
        composer_section_t section =
            composer_timeline_get_section_at_bar(bar);

        uint8_t segment =
            composer_timeline_get_segment_at_bar(bar);

        composer_write_entry_t *e = &g_entries[g_entry_count++];

        e->slot      = slot;
        e->bar_start = bar;
        e->section   = section;
        e->segment   = segment;

        /* advance exactly 4 bars */
        bar  += COMPOSER_PATTERN_BARS;
        slot += 1;
    }

    return g_entry_count;
}

/* ============================================================
   QUERY
   ============================================================ */

uint16_t composer_write_prepare_count(void)
{
    return g_entry_count;
}

const composer_write_entry_t *
composer_write_prepare_get(uint16_t index)
{
    if (index >= g_entry_count)
        return 0;

    return &g_entries[index];
}
