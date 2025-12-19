#ifndef COMPOSER_POLICY_H
#define COMPOSER_POLICY_H

#include <stdint.h>
#include "composer.h"

/* ============================================================
   Decision Flags (Composer → Randomizer Bias)
   ============================================================ */

typedef uint16_t composer_policy_flags_t;

/* Flags */
#define CP_FLAG_NONE            0x0000
#define CP_FLAG_SPARSE          0x0001
#define CP_FLAG_DENSE           0x0002
#define CP_FLAG_LOW_REGISTER    0x0004
#define CP_FLAG_HIGH_REGISTER   0x0008
#define CP_FLAG_STRAIGHT        0x0010
#define CP_FLAG_SYNCOPATED      0x0020
#define CP_FLAG_SUSTAINED       0x0040
#define CP_FLAG_PERCUSSIVE      0x0080
#define CP_FLAG_BUILDING        0x0100
#define CP_FLAG_RELEASE         0x0200

/* ============================================================
   Policy Segment
   ============================================================ */

typedef struct {
    uint8_t density;          /* 0–100 */
    uint8_t variation;        /* 0–127 */
    uint8_t euclid_pulses;
    int8_t  euclid_rotation;
    composer_fill_t fill;

    composer_policy_flags_t flags; /* <<< NEU */
} composer_policy_segment_t;

/* ============================================================
   API
   ============================================================ */

void composer_apply_policy(uint8_t genre_id,
                           composer_section_t section,
                           uint8_t segment);

#endif /* COMPOSER_POLICY_H */
