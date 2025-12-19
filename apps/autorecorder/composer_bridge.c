#include "composer_bridge.h"
#include "composer_utils.h"
#include "randomizer.h"

/* ------------------------------------------------------------
   DEFAULT LOCK BEHAVIOR
   If you have a real lock system, replace this implementation.
   ------------------------------------------------------------ */
int composer_part_is_locked(uint8_t part, composer_section_t section)
{
    (void)part;
    (void)section;
    return 0; /* default: nothing locked */
}

/* ------------------------------------------------------------
   Composer triggers generation decisions.
   Randomizer generates (only if empty).
   ------------------------------------------------------------ */
void composer_fill_missing_parts(uint8_t target_page,
                                 composer_section_t section,
                                 uint8_t segment)
{
    (void)target_page; /* keep for later: page-aware in_use checks */

    composer_partmask_t want = composer_decide_partmask(section, segment);

    for (uint8_t part = 0; part < 16; ++part)
    {
        if (!composer_mask_has_part(want, part))
            continue;

        if (composer_part_is_locked(part, section))
            continue;

        /* IMPORTANT: Randomizer decides emptiness */
        if (randomizer_part_in_use(part))
            continue;

        /* Trigger generation for this part.
           Keep it minimal: generate one pattern page for this part.
           steps_count: usually 64 on electribe-style patterns.
        */
        (void)randomize_and_write_pattern_paged(part, 64, (int)section, (int)target_page);

        /* After writing, randomizer_part_in_use() should become true
           (either via your in-use scan OR via a usage-bit update). */
    }
}
