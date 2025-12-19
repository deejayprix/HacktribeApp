#ifndef COMPOSER_WRITE_PREPARE_H
#define COMPOSER_WRITE_PREPARE_H

#include <stdint.h>
#include "ft_types.h"
#include "composer_timeline.h"

#define COMPOSER_PATTERN_BARS   4
#define COMPOSER_STEPS_PER_BAR 16
#define COMPOSER_PATTERN_STEPS 64   /* 4 × 16 */

typedef struct {
    uint16_t slot;              /* 1..250 */
    uint16_t bar_start;         /* absolute bar */
    ft_step_t steps[COMPOSER_PATTERN_STEPS];
} composer_write_block_t;

/* Prepare all pattern blocks for writing */
int composer_write_prepare(uint16_t slot_base);

/* Access prepared blocks */
int composer_write_get_block_count(void);
const composer_write_block_t *composer_write_get_block(int idx);

#endif
