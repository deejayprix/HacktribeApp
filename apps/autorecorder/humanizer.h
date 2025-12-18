/* ============================================================
   apps/autorecorder/humanizer.h
   ============================================================ */
#ifndef HUMANIZER_H
#define HUMANIZER_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------
   Humanizer – Public API

   Wir halten es bewusst minimal:
   - enabled
   - timing amount (ticks)
   - velocity amount
   ------------------------------------------------------------ */

void humanizer_set_enabled(int en);
int  humanizer_get_enabled(void);

/* timing jitter (0..N ticks) */
void humanizer_set_timing_amount_ticks(int ticks);
int  humanizer_get_timing_amount_ticks(void);

/* velocity jitter (0..N) */
void humanizer_set_velocity_amount(int amount);
int  humanizer_get_velocity_amount(void);

#ifdef __cplusplus
}
#endif

#endif /* HUMANIZER_H */
