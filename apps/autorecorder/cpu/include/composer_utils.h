#ifndef COMPOSER_UTILS_H
#define COMPOSER_UTILS_H

#include <stdint.h>
#include "composer.h"

/* 16-bit mask: bit0 = part0 ... bit15 = part15 */
typedef uint16_t composer_partmask_t;

/* Decision: which parts SHOULD exist in this section/segment */
composer_partmask_t composer_decide_partmask(composer_section_t section,
                                             uint8_t segment);

/* Convenience helpers */
static inline int composer_mask_has_part(composer_partmask_t m, uint8_t part)
{
    return (part < 16) ? ((m >> part) & 1u) : 0;
}

#endif /* COMPOSER_UTILS_H */
