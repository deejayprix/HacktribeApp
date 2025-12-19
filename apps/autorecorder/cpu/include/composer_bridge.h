#ifndef COMPOSER_BRIDGE_H
#define COMPOSER_BRIDGE_H

#include <stdint.h>
#include "composer.h"

/* If you already have a lock system somewhere else, keep the signature. */
int composer_part_is_locked(uint8_t part, composer_section_t section);

/* NEW: decisions-driven fill */
void composer_fill_missing_parts(uint8_t target_page,
                                 composer_section_t section,
                                 uint8_t segment);

#endif /* COMPOSER_BRIDGE_H */
