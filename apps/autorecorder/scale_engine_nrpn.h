#ifndef SCALE_ENGINE_NRPN_H
#define SCALE_ENGINE_NRPN_H

#include <stdint.h>

/* wrappers used by nrpn_router.c to stage scale changes.
 * These functions are thin wrappers that call into the project's
 * scale_engine if available; otherwise they are safe no-ops.
 */

void nrpn_scale_stage_channel(int ch);
void nrpn_scale_stage_type(int t);
void nrpn_scale_stage_tonic(int tonic);
void nrpn_scale_commit(void);
void nrpn_scale_reset(void);

#endif /* SCALE_ENGINE_NRPN_H */
