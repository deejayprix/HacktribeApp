#ifndef PATTERN_RAM_MAP_H
#define PATTERN_RAM_MAP_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "ft_types.h"

/*
 * Pattern RAM Map API
 *
 * - Legacy compatible:
 *   pattern_ram_map_set_base(void*)
 *
 * - Hardened optional:
 *   pattern_ram_map_set_base_ex(void*, size_t bytes)
 *   pattern_ram_max_steps()
 *   pattern_ram_read_step()
 */

void   pattern_ram_map_init(void);
bool   pattern_ram_map_is_available(void);

void   pattern_ram_map_set_base(void *addr);

/* NEW (additive, recommended): provide RAM region size for bounds checks */
void   pattern_ram_map_set_base_ex(void *addr, size_t bytes);

void   pattern_ram_map_enable(bool enable);

size_t pattern_ram_step_size(void);

/* NEW (additive): known max steps if capacity provided, else 0 */
size_t pattern_ram_max_steps(void);

uint8_t *pattern_ram_step_address(int physical_index);

int    pattern_ram_write_step(int part, int physical_index, const ft_step_t *s);

/* NEW (additive): safe read helper */
int    pattern_ram_read_step(int physical_index, ft_step_t *out);

#endif /* PATTERN_RAM_MAP_H */
