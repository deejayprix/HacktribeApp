#include "composer_preview.h"
#include "composer_timeline.h"
#include "composer.h"
#include "randomizer.h"

static uint8_t  g_preview_active = 0;
static uint16_t g_preview_bar    = 0;
static uint16_t g_last_bar       = 0xFFFF;

/* ------------------------------------------------------------ */

void composer_preview_enable(uint8_t enable)
{
    g_preview_active = enable ? 1 : 0;

    if (!g_preview_active)
        g_last_bar = 0xFFFF;
}

uint8_t composer_preview_is_active(void)
{
    return g_preview_active;
}

void composer_preview_reset(void)
{
    g_preview_bar = 0;
    g_last_bar    = 0xFFFF;
}

void composer_preview_set_bar(uint16_t bar)
{
    g_preview_bar = bar;
    g_last_bar    = 0xFFFF;
}

uint16_t composer_preview_get_bar(void)
{
    return g_preview_bar;
}

/* ------------------------------------------------------------
   MAIN PREVIEW TICK
   ------------------------------------------------------------ */

void composer_preview_tick(void)
{
    if (!g_preview_active)
        return;

    /* Nur bei Bar-Wechsel reagieren */
    if (g_preview_bar != g_last_bar)
    {
        composer_section_t section =
            composer_timeline_get_section_at_bar(g_preview_bar);

        uint8_t segment =
            composer_timeline_get_segment_at_bar(g_preview_bar);

        /* Policy anwenden (NON-DESTRUCTIVE) */
        composer_preset_recall(
            composer_get_genre(),
            section,
            segment
        );

        g_last_bar = g_preview_bar;
    }

    /* Weiterlaufen */
    g_preview_bar++;

    if (g_preview_bar >= composer_timeline_get_total_bars())
        g_preview_bar = 0;
}
