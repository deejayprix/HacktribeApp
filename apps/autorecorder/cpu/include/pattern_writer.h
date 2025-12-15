#ifndef PATTERN_WRITER_H
#define PATTERN_WRITER_H

#include <stdint.h>
#include "ft_types.h"

/* =====================================================================
   PATTERN WRITER API – Freetribe / Autorecorder
   ---------------------------------------------------------------------
   Dieses Modul abstrahiert das Schreiben / Lesen von Pattern Steps,
   unabhängig davon, ob RAM-Backend oder Firmware-Hooks aktiv sind.

   Die API besteht aus:
     • high-level: pattern_write_steps(), pattern_read_steps()
     • paging: active page, paging size, direct page read/write
     • compatibility layer für Randomizer (RLE/Compressed)
     • single-step writer
   ===================================================================== */


/* ---------------------------------------------------------------------
   HIGH-LEVEL STEP READ/WRITE
   --------------------------------------------------------------------- */

/* Read N steps from the current active page */
int pattern_read_steps(int part, ft_step_t *dst, int n);

/* Write N steps to the current active page */
int pattern_write_steps(int part, const ft_step_t *src, int n);

/* Write ONE step */
int pattern_write_step(int part, int step, int pitch, int velocity, int gate);


/* ---------------------------------------------------------------------
   FULL PATTERN WRITE
   (legacy API expected by some modules)
   --------------------------------------------------------------------- */
int pattern_write_pattern(int part, const ft_step_t *steps, int count);


/* ---------------------------------------------------------------------
   RLE + COMPRESSED WRITERS (Randomizer uses these)
   Implementations may fallback internally.
   --------------------------------------------------------------------- */
int pattern_write_rle_batch(int part,
                            const ft_step_t *steps,
                            int nsteps,
                            int target_page);

int pattern_write_compressed(int part,
                             const ft_step_t *steps,
                             int nsteps,
                             int target_page);


/* ---------------------------------------------------------------------
   PAGING SYSTEM
   --------------------------------------------------------------------- */

/* Set current page number */
int pattern_set_current_page(int page);

/* Set active page (used by Song Mode and NRPN Clear) */
void pattern_set_active_page(int page);

/* Get active page */
int pattern_get_active_page(void);

/* Typically 16, 64, 128 — configurable */
int pattern_get_paging_page_size(void);


/* ---------------------------------------------------------------------
   DIRECT PAGE ACCESS
   --------------------------------------------------------------------- */

/* Read N steps from a specific page */
int pattern_read_page(int part, ft_step_t *dst, int nsteps, int page);

/* Write N steps to a specific page */
int pattern_write_page(int part, const ft_step_t *src, int nsteps, int page);


/* ---------------------------------------------------------------------
   CLEAR / RESET UTILITIES
   --------------------------------------------------------------------- */

/* Clear only one part */
int pattern_clear_part(int part);

/* Clear all parts */
int pattern_clear_all_parts(void);

/* Clear entire page (pattern) including all parts */
int pattern_clear_page(int pat);

/* NRPN-compatible clear command */
int pattern_clear_nrpn(int part);


/* ---------------------------------------------------------------------
   DEPRECATED / INTERNAL (still used by ft_api)
   --------------------------------------------------------------------- */

/* Provided in ft_api.c — sets g_active_page */
void set_pattern_number(int pat);


#endif /* PATTERN_WRITER_H */
