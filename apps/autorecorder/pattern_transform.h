#ifndef PATTERN_TRANSFORM_H
#define PATTERN_TRANSFORM_H

#include <stdint.h>
#include "pattern_writer.h"

void transform_rotate(int part, int amount);
void transform_mirror(int part);
void transform_invert(int part);
void transform_scale_steps(int part, int scale);
void transform_humanize(int part, int vel_amt, int pitch_amt);

void transform_euclidean(int part, int fills, int total_steps);

void pattern_transform_apply(int part, ft_step_t *steps, int count);

#endif
