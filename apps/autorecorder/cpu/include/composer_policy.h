#ifndef COMPOSER_POLICY_H
#define COMPOSER_POLICY_H

#include <stdint.h>
#include "composer.h"

/* -------------------------------------------------------------
   Policy für ein 4-Bar Segment (A/B/C/D)
   ------------------------------------------------------------- */
typedef struct {
    uint8_t density;          /* Randomizer Density 0–100 */
    uint8_t variation;        /* Randomizer Variation 0–127 */
    uint8_t euclid_pulses;    /* Euclid Pulses */
    int8_t  euclid_rotation;  /* Euclid Rotation */
    composer_fill_t fill;     /* Fill-Charakter */
} composer_policy_segment_t;

/* -------------------------------------------------------------
   Apply Policy (Option 1 + 4)
   ------------------------------------------------------------- */
void composer_apply_policy(uint8_t genre_id,
                           composer_section_t section,
                           uint8_t segment);

#endif /* COMPOSER_POLICY_H */
