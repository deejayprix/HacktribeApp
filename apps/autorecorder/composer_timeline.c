#include "composer_timeline.h"
#include <string.h>

/* ============================================================
   GLOBAL TIMELINE
   ============================================================ */

static composer_timeline_t g_tl;

/* ============================================================
   INTERNAL HELPERS
   ============================================================ */

static uint16_t clamp_u16(uint16_t v, uint16_t lo, uint16_t hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static int bar_in_section(uint16_t bar, const composer_timeline_section_t *s)
{
    if (!s) return 0;
    if (bar < s->bar_start) return 0;
    if (bar >= (uint16_t)(s->bar_start + s->bar_length)) return 0;
    return 1;
}

/* ============================================================
   INIT
   ============================================================ */

void composer_timeline_init(uint16_t total_bars)
{
    memset(&g_tl, 0, sizeof(g_tl));

    if (total_bars == 0)
        total_bars = 1;

    if (total_bars > COMPOSER_MAX_BARS)
        total_bars = COMPOSER_MAX_BARS;

    g_tl.total_bars = total_bars;
}

/* ============================================================
   SECTION SETUP
   ============================================================ */

int composer_timeline_add_section(composer_section_t section,
                                  uint16_t bar_start,
                                  uint16_t bar_length)
{
    if (g_tl.section_count >= COMPOSER_MAX_SECTIONS)
        return -1;

    if (bar_length == 0)
        return -2;

    /* clamp into timeline range */
    if (g_tl.total_bars == 0)
        g_tl.total_bars = 1;

    bar_start  = clamp_u16(bar_start, 0, (uint16_t)(g_tl.total_bars - 1));
    bar_length = clamp_u16(bar_length, 1, g_tl.total_bars);

    /* ensure section doesn't exceed total bars */
    if ((uint32_t)bar_start + (uint32_t)bar_length > (uint32_t)g_tl.total_bars)
    {
        bar_length = (uint16_t)(g_tl.total_bars - bar_start);
        if (bar_length == 0) return -3;
    }

    composer_timeline_section_t *s = &g_tl.sections[g_tl.section_count++];
    s->section    = section;
    s->bar_start  = bar_start;
    s->bar_length = bar_length;

    return 0;
}

/* ============================================================
   PLAYBACK (optional)
   ============================================================ */

void composer_timeline_play(void)
{
    g_tl.playing = 1;
    g_tl.playhead_bar  = 0;
    g_tl.playhead_step = 0;
}

void composer_timeline_stop(void)
{
    g_tl.playing = 0;
}

void composer_timeline_tick(void)
{
    if (!g_tl.playing)
        return;

    g_tl.playhead_step++;

    if (g_tl.playhead_step >= COMPOSER_STEPS_PER_BAR)
    {
        g_tl.playhead_step = 0;
        g_tl.playhead_bar++;

        if (g_tl.total_bars == 0)
            g_tl.total_bars = 1;

        if (g_tl.playhead_bar >= g_tl.total_bars)
            g_tl.playhead_bar = 0;
    }
}

/* ============================================================
   QUERY (playhead-based)
   ============================================================ */

composer_section_t composer_timeline_get_active_section(void)
{
    return composer_timeline_get_section_at_bar(g_tl.playhead_bar);
}

uint16_t composer_timeline_get_playhead_bar(void)
{
    return g_tl.playhead_bar;
}

uint16_t composer_timeline_get_playhead_step(void)
{
    return g_tl.playhead_step;
}

/* ============================================================
   QUERY (bar-based) — REQUIRED by composer_preview.c
   ============================================================ */

uint16_t composer_timeline_get_total_bars(void)
{
    return (g_tl.total_bars == 0) ? 1 : g_tl.total_bars;
}

composer_section_t composer_timeline_get_section_at_bar(uint16_t bar)
{
    /* if no sections defined, default MAIN */
    if (g_tl.section_count == 0)
        return SECTION_MAIN;

    for (uint8_t i = 0; i < g_tl.section_count; i++)
    {
        const composer_timeline_section_t *s = &g_tl.sections[i];
        if (bar_in_section(bar, s))
            return s->section;
    }

    /* not covered -> default MAIN */
    return SECTION_MAIN;
}

uint8_t composer_timeline_get_segment_at_bar(uint16_t bar)
{
    /* Default: map bar to 4-bar segments A/B/C/D (0..3) */
    const uint16_t seg_len = (COMPOSER_BARS_PER_SEGMENT == 0) ? 4 : COMPOSER_BARS_PER_SEGMENT;

    /* If we find the section that owns this bar, segment is relative to section start */
    if (g_tl.section_count != 0)
    {
        for (uint8_t i = 0; i < g_tl.section_count; i++)
        {
            const composer_timeline_section_t *s = &g_tl.sections[i];
            if (bar_in_section(bar, s))
            {
                uint16_t rel = (uint16_t)(bar - s->bar_start);
                uint8_t seg = (uint8_t)((rel / seg_len) & 0x03u);
                return seg; /* 0..3 */
            }
        }
    }

    /* fallback: global bar mapping */
    return (uint8_t)(((bar / seg_len) & 0x03u));
}
