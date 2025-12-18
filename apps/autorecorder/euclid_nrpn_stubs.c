/* euclid_nrpn_stubs.c
   Keep this file only as a fallback helper.
   IMPORTANT: Do NOT define eu_stage_channel/eu_stage_slot here as strong globals.
*/

#include <stdint.h>
#include "randomizer.h"

/* If nrpn_router.c expects extern staging vars, they must be defined EXACTLY ONCE.
   Preferred: define them in randomizer_euclid.c (real module).
   Here we only provide weak fallback definitions. */

__attribute__((weak)) int eu_stage_channel = 0;
__attribute__((weak)) int eu_stage_slot    = 0;

/* Optional: weak fallbacks for any missing functions (usually not needed if randomizer_euclid.c is linked) */
__attribute__((weak)) void randomizer_euclid_stage_channel(int ch) { eu_stage_channel = ch; }
__attribute__((weak)) void randomizer_euclid_stage_slot(int slot)  { eu_stage_slot = slot; }
