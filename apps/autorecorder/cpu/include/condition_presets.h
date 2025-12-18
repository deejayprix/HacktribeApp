#ifndef CONDITION_PRESETS_H
#define CONDITION_PRESETS_H

#include <stdint.h>

/* ============================================================
   Condition Preset Browser (NRPN)
   Phase 3.1.5
   - Policy-only
   - builds node graphs + assigns to staged step
   ============================================================ */

/* Select preset id (0..N-1) */
void condition_preset_select(int preset_id);

/* Set preset parameter (meaning depends on preset) */
void condition_preset_set_param(int param);

/* Apply selected preset to currently staged step (condition_engine staging) */
void condition_preset_apply_to_staged_step(void);

/* Debug: print current preset and its resolved node */
void condition_preset_dump(void);

/* Helper: count and name for UI/debug */
int  condition_preset_count(void);
const char* condition_preset_name(int preset_id);

#endif /* CONDITION_PRESETS_H */
