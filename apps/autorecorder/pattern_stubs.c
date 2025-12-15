#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "ft_api.h"
#include "pattern_writer.h"

/* ===================================================================
   Correct Stub/Fallback Implementation Matching pattern_writer.h
   ===================================================================
   Headers declare:

      int pattern_write_rle_batch(int part,
                                  const ft_step_t *steps,
                                  int nsteps,
                                  int target_page);

      int pattern_write_compressed(int part,
                                   const ft_step_t *steps,
                                   int nsteps,
                                   int target_page);

   Therefore we MUST match these exact signatures.
   =================================================================== */


/* ------------------------------------------------------------
   Fallback RLE Writer
   ------------------------------------------------------------ */
__attribute__((weak))
int pattern_write_rle_batch(int part, const ft_step_t *steps, int nsteps, int target_page)
{
    if (!steps || nsteps <= 0) {
        ft_print("[WARN] pattern_write_rle_batch: invalid args\n");
        return -1;
    }

    /* fallback = direct page-write */
    int w = pattern_write_page(part, steps, nsteps, target_page);
    if (w != nsteps) {
        ft_print("[WARN] pattern_write_rle_batch fallback mismatch\n");
    }
    return w;
}


/* ------------------------------------------------------------
   Fallback Compressed Writer
   ------------------------------------------------------------ */
__attribute__((weak))
int pattern_write_compressed(int part, const ft_step_t *steps, int nsteps, int target_page)
{
    if (!steps || nsteps <= 0) {
        ft_print("[WARN] pattern_write_compressed: invalid args\n");
        return -1;
    }

    int w = pattern_write_page(part, steps, nsteps, target_page);
    if (w != nsteps) {
        ft_print("[WARN] pattern_write_compressed fallback mismatch\n");
    }
    return w;
}


/* ------------------------------------------------------------
   Fallback: ft_write_pattern()
   ------------------------------------------------------------ */
__attribute__((weak))
int ft_write_pattern(int part, const ft_step_t *steps, int nsteps)
{
    if (!steps || nsteps <= 0) {
        ft_print("[WARN] ft_write_pattern: invalid args\n");
        return -1;
    }

    int page = pattern_get_active_page();
    int w = pattern_write_page(part, steps, nsteps, page);
    if (w != nsteps) {
        ft_print("[WARN] ft_write_pattern fallback mismatch\n");
    }

    return w;
}
