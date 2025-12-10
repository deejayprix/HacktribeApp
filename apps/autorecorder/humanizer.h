#ifndef HUMANIZER_H
#define HUMANIZER_H

#include <stdint.h>
#include "pattern_writer.h" /* ft_step_t */

#ifdef __cplusplus
extern "C" {
#endif

/* Timing humanize: jitter_range (in steps) */
int humanizer_apply_timing(ft_step_t *steps, int nsteps, int jitter_range);

/* Velocity humanize:
 * - vel_range: +/- range
 * - mode: 0=relative (add random delta), 1=absolute (pick in window around base)
 */
int humanizer_apply_velocity(ft_step_t *steps, int nsteps, int vel_range, int mode);

#ifdef __cplusplus
}
#endif

#endif /* HUMANIZER_H */
