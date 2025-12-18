#include "composer.h"
#include "composer_policy.h"

#include "pattern_writer.h"
#include "pattern_ram_map.h"
#include "live_fx.h"
#include "randomizer.h"
#include "composer_utils.h"
#include "composer_bridge.h"

#include <string.h>

/* ------------------------------------------------------------
   Global Composer State (Policy-Level Only)
   ------------------------------------------------------------ */

static uint8_t g_genre = GENRE_ACID_TECHNO;
static composer_fill_t g_fill = FILL_NONE;

/* ------------------------------------------------------------
   Init / State Access
   ------------------------------------------------------------ */

void composer_init(void)
{
    g_genre = GENRE_ACID_TECHNO;
    g_fill  = FILL_NONE;
}

void composer_set_genre(uint8_t genre_id)
{
    if (genre_id >= GENRE_COUNT)
        genre_id = GENRE_ACID_TECHNO;

    g_genre = genre_id;
}

uint8_t composer_get_genre(void)
{
    return g_genre;
}

composer_fill_t composer_get_current_fill(void)
{
    return g_fill;
}

void composer_set_current_fill(composer_fill_t f)
{
    g_fill = f;
}

/* ------------------------------------------------------------
   Option 4: Preset Recall (Policy only, non-destructive)
   ------------------------------------------------------------ */

void composer_preset_recall(uint8_t genre_id,
                            composer_section_t section,
                            uint8_t segment)
{
    composer_set_genre(genre_id);
    composer_apply_policy(genre_id, section, segment);
}

/* ------------------------------------------------------------
   Option 3: Song Mode Hook
   - reacts to section changes
   - triggers fill behaviour (performance-layer only)
   ------------------------------------------------------------ */

void composer_songmode_on_section(uint8_t section, uint8_t segment)
{
    /* Apply policy:
       - density
       - variation
       - euclid parameters
       - humanize
       - fill-state
    */
    composer_apply_policy(composer_get_genre(),
                          (composer_section_t)section,
                          (uint8_t)segment);

    /* Translate fill type into Live FX behaviour */
    switch (composer_get_current_fill())
    {
        case FILL_GROOVE:
            /* subtle energy lift */
            live_fx_set_variation_boost(20);
            break;

        case FILL_BUILD:
            /* strong rise + fill */
            live_fx_set_variation_boost(40);
            live_fx_trigger_fill_now();
            break;

        case FILL_PUNCTUATION:
            /* short accent fill */
            live_fx_set_variation_boost(30);
            live_fx_trigger_fill_now();
            break;

        default:
            live_fx_set_variation_boost(0);
            break;
    }
}

/* ------------------------------------------------------------
   Pattern Generation (Policy-driven, safe)
   ------------------------------------------------------------ */

#define BARS_PER_PATTERN 4
#define STEPS_PER_BAR    16
#define SEG_STEPS        (BARS_PER_PATTERN * STEPS_PER_BAR)

/* Write a guaranteed-empty 4-bar pattern page */
static void write_empty_pattern(uint8_t part, uint8_t page)
{
    ft_step_t steps[SEG_STEPS];
    memset(steps, 0, sizeof(steps));

    for (int i = 0; i < SEG_STEPS; i++)
    {
        steps[i].part = part;
        steps[i].step = i;
    }

    pattern_write_page(part, steps, SEG_STEPS, page);
}

/* ------------------------------------------------------------
   Generate ONE segment (A/B/C/D)
   ------------------------------------------------------------ */

void composer_generate_segment(uint8_t genre_id,
                               composer_section_t section,
                               uint8_t segment,
                               uint8_t target_page)
{
    /* Base: blank page for all parts */
    for (uint8_t part = 0; part < 16; part++)
        write_empty_pattern(part, target_page);

    /* Apply policy (no notes yet) */
    composer_preset_recall(genre_id, section, segment);

    /* STEP 11:
       Fill ONLY missing parts
       - never overwrites user/DAW content
       - safe, idempotent
    */
    composer_fill_missing_parts(target_page);
}

/* ------------------------------------------------------------
   Generate ONE section (Intro, Main, Break, Peak, Outro)
   ------------------------------------------------------------ */

void composer_generate_section(uint8_t genre_id,
                               composer_section_t section,
                               uint8_t start_page)
{
    uint8_t segments =
        (section == SECTION_BREAK || section == SECTION_PEAK) ? 2 : 4;

    for (uint8_t s = 0; s < segments; s++)
        composer_generate_segment(genre_id,
                                  section,
                                  s,
                                  start_page + s);
}

/* ------------------------------------------------------------
   Generate FULL song structure
   ------------------------------------------------------------ */

void composer_generate_song(uint8_t genre_id,
                            uint8_t start_page)
{
    uint8_t page = start_page;

    composer_generate_section(genre_id, SECTION_INTRO, page);
    page += 4;

    composer_generate_section(genre_id, SECTION_MAIN, page);
    page += 4;

    composer_generate_section(genre_id, SECTION_BREAK, page);
    page += 2;

    composer_generate_section(genre_id, SECTION_PEAK, page);
    page += 2;

    composer_generate_section(genre_id, SECTION_OUTRO, page);
}
