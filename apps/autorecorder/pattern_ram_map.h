#ifndef PATTERN_RAM_MAP_H
#define PATTERN_RAM_MAP_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "ft_types.h"

void pattern_ram_map_init(void);
bool pattern_ram_map_is_available(void);
void pattern_ram_map_set_base(void *addr);
void pattern_ram_map_enable(bool enable);

size_t pattern_ram_step_size(void);
uint8_t *pattern_ram_step_address(int physical_index);

int pattern_ram_write_step(int part, int physical_index, const ft_step_t *s);

#endif /* PATTERN_RAM_MAP_H */
