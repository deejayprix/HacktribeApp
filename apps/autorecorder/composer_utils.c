#include "composer_utils.h"
#include "randomizer.h"

/*
 Phase 2 Regel:
 - Parts 1–5 → User / DAW
 - Parts 6–16 → Composer darf füllen
*/
int composer_part_should_be_generated(uint8_t part)
{
    /* 0–4 (CH1–5): User */
    if (part < 5)
        return 0;

    /* 5–15 (CH6–16): Maschine */
    return 1;
}
