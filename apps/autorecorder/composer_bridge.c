#include "composer_bridge.h"
#include "composer_utils.h"

/*
 Phase 2 – Step 11
 ------------------------------------------------------------
 - KEINE Noten-Generierung
 - KEIN Step-/RAM-Zugriff
 - KEIN direkter Randomizer-Call
 - Composer = Policy / Entscheidungsebene
 - Engines reagieren später (NRPN / SongMode / User Trigger)
 ------------------------------------------------------------
*/

/*
 Decide which parts SHOULD be generated.
 Actual generation is handled elsewhere.
*/
void composer_fill_missing_parts(uint8_t page)
{
    (void)page; /* Page-Info wird ab Phase 3 relevant */

    for (uint8_t part = 0; part < 16; part++)
    {
        if (!composer_part_should_be_generated(part))
            continue;

        /*
         Phase 2:
         --------------------------------------------
         KEINE Aktion hier.

         - Kein randomize_generate_pattern()
         - Kein scale_engine_generate_part()
         - Kein pattern_write()
         - Kein RAM-Zugriff

         Composer setzt NUR:
         - Genre
         - Section
         - Density
         - Variation
         - Fill-Type

         Die eigentliche Pattern-Erzeugung passiert über:
         - bestehende Randomizer-Trigger
         - NRPN
         - SongMode
         - User Action
        */
    }
}
