#include "pattern_writer.h"
#include "pattern_ram_map.h"
#include "ft_config.h"
#include "ft_api.h"

#include <string.h>
#include <stdlib.h>

/* Active page index */
int g_active_page = 0;
/* Default page size (may be overridden by firmware calls) */
int g_page_size   = FT_DEFAULT_PAGE_SIZE;

/* -------------------------------------------------------------------
   Page helpers
   ------------------------------------------------------------------- */
int pattern_get_paging_page_size(void)
{
    return g_page_size;
}

int pattern_get_active_page(void)
{
    return g_active_page;
}

void pattern_set_active_page(int page)
{
    if (page < 0) page = 0;
    g_active_page = page;
}

/* -------------------------------------------------------------------
   STEP READ API
   ------------------------------------------------------------------- */

/* Low-level reader for entire page or segment */
int pattern_read_page(int part, ft_step_t *dst, int nsteps, int page)
{
    if (!dst || nsteps <= 0) return 0;

    /* If RAM map is available, read from RAM */
    if (pattern_ram_map_is_available())
    {
        size_t step = pattern_ram_step_size();
        if (step == 0) step = sizeof(ft_step_t);

        int offset = page * pattern_get_paging_page_size();

        for (int i = 0; i < nsteps; ++i)
        {
            uint8_t *src = pattern_ram_step_address(offset + i);
            if (!src)
            {
                memset(&dst[i], 0, sizeof(ft_step_t));
                continue;
            }

            /* Restore full ft_step_t from RAM area.
               We expect the RAM to contain a serialized ft_step_t. */
            memcpy(&dst[i], src, sizeof(ft_step_t));

            /* Ensure part/step fields are consistent with caller expectations */
            dst[i].part = part;
            dst[i].step = i;
        }

        return nsteps;
    }

    /* fallback: blank steps */
    memset(dst, 0, sizeof(ft_step_t) * nsteps);
    return nsteps;
}

/* High-level read for current active page */
int pattern_read_steps(int part, ft_step_t *dst, int n)
{
    if (!dst || n <= 0) return 0;
    return pattern_read_page(part, dst, n, g_active_page);
}

/* -------------------------------------------------------------------
   STEP WRITE API
   ------------------------------------------------------------------- */

/* Low-level write to specific page index */
int pattern_write_page(int part, const ft_step_t *src, int nsteps, int page)
{
    if (!src || nsteps <= 0) return 0;

    /* raw RAM write if available */
    if (pattern_ram_map_is_available())
    {
        int offset = page * pattern_get_paging_page_size();

        for (int i = 0; i < nsteps; ++i)
        {
            /* ensure part/step fields are saved as provided src may not set them */
            ft_step_t tmp;
            memcpy(&tmp, &src[i], sizeof(ft_step_t));
            tmp.part = (uint8_t)part;
            tmp.step = (uint8_t)i;
            pattern_ram_write_step(part, offset + i, &tmp);
        }

        return nsteps;
    }

    /* fallback: use ft_api (expects a pointer to ft_step_t) */
    for (int i = 0; i < nsteps; ++i)
    {
        ft_step_t tmp = src[i];
        /* ensure part/step fields are set */
        tmp.part = part;
        /* tmp.step should already be set in src[i], but keep as-is */
        (void)ft_write_step(&tmp); /* ignore return value */
    }

    return nsteps;
}


/* High-level write wrapper */
int pattern_write_steps(int part, const ft_step_t *src, int n)
{
    if (!src || n <= 0) return 0;
    return pattern_write_page(part, src, n, g_active_page);
}

/* -------------------------------------------------------------------
   Single-step writer (simple wrapper)
   ------------------------------------------------------------------- */
int pattern_write_step(int part, int step, int pitch, int velocity, int gate)
{
    ft_step_t s = {
        .part     = (uint8_t)part,
        .step     = (uint8_t)step,
        .pitch    = (uint8_t)pitch,
        .velocity = (uint8_t)velocity,
        .gate     = (uint8_t)gate
    };

    return pattern_write_steps(part, &s, 1);
}

/* -------------------------------------------------------------
   Compatibility shim: set pattern (page) number
   ------------------------------------------------------------- */
void set_pattern_number(int pat)
{
    if (pat < 0) pat = 0;
    g_active_page = pat;
}
