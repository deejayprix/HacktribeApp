#ifndef COMPOSER_PREVIEW_H
#define COMPOSER_PREVIEW_H

#include <stdint.h>

/* ------------------------------------------------------------
   Composer Preview (virtuelles Probe-Playback)
   ------------------------------------------------------------ */

/* Enable / Disable preview mode */
void composer_preview_enable(uint8_t enable);

/* Reset preview playhead */
void composer_preview_reset(void);

/* Manuell auf einen Bar springen */
void composer_preview_set_bar(uint16_t bar);

/* Tick – wird von Sync / Live Clock aufgerufen */
void composer_preview_tick(void);

/* Query */
uint8_t  composer_preview_is_active(void);
uint16_t composer_preview_get_bar(void);

#endif /* COMPOSER_PREVIEW_H */
