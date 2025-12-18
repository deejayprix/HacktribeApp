#ifndef COMPOSER_UTILS_H
#define COMPOSER_UTILS_H

#include <stdint.h>

/* Phase 2:
   entscheidet NUR logisch – keine RAM-Inspektion */
int composer_part_should_be_generated(uint8_t part);

#endif
