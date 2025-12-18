#include "pattern_writer.h"
#include "pattern_ram_map.h"
#include "ft_config.h"
#include "ft_api.h"

#include <string.h>
#include <stdlib.h>

/* Active page index */
static int g_active_page = 0;
/* Default page size (may be overridden by firmware calls / config) */
static int g_page_size   = FT_DEFAULT_PAGE_SIZE;

/* -------------------------------------------------------------
   Internal helpers
   ------------------------------------------------------------- */
static inline int clampi(int v, int lo, int hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static inline int safe_page_size(void)
{
    int ps = g_page_size;
    if (ps <= 0) ps = 64;
    return ps;
}

/* -------------------------------------------------------------------
   Page helpers
   ------------------------------------------------------------------- */
int pattern_get_paging_page_size(void)
{
    return safe_page_size();
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

/* Compatibility: some modules call this name and expect int return */
int pattern_set_current_page(int page)
{
    pattern_set_active_page(page);
    return g_active_page;
}

/* -------------------------------------------------------------------
   STEP READ API
   ------------------------------------------------------------------- */

/* Low-level reader for entire page or segment */
int pattern_read_page(int part, ft_step_t *dst, int nsteps, int page)
{
    if (!dst || nsteps <= 0) return 0;

    int ps = safe_page_size();
    if (nsteps > ps) nsteps = ps;
    if (page < 0) page = 0;

    int offset = page * ps;

    /* If RAM map is available, read from RAM */
    if (pattern_ram_map_is_available())
    {
        for (int i = 0; i < nsteps; ++i)
        {
            ft_step_t tmp;
            int ok = 0;

            /* Prefer hardened helper if present */
            ok = pattern_ram_read_step(offset + i, &tmp);

            if (!ok)
            {
                memset(&dst[i], 0, sizeof(ft_step_t));
                dst[i].part = (uint8_t)part;
                dst[i].step = (uint8_t)i;
                continue;
            }

            /* Keep stored values, but enforce caller expectation:
               - correct part
               - step index relative to page (0..ps-1) */
            tmp.part = (uint8_t)part;
            tmp.step = (uint8_t)i;

            dst[i] = tmp;
        }

        return nsteps;
    }

    /* fallback: blank steps */
    memset(dst, 0, sizeof(ft_step_t) * (size_t)nsteps);
    for (int i = 0; i < nsteps; ++i) {
        dst[i].part = (uint8_t)part;
        dst[i].step = (uint8_t)i;
    }
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

    int ps = safe_page_size();
    if (nsteps > ps) nsteps = ps;
    if (page < 0) page = 0;

    int offset = page * ps;

    /* RAM write if available */
    if (pattern_ram_map_is_available())
    {
        for (int i = 0; i < nsteps; ++i)
        {
            ft_step_t tmp;
            memcpy(&tmp, &src[i], sizeof(ft_step_t));

            /* enforce canonical fields */
            tmp.part = (uint8_t)part;
            tmp.step = (uint8_t)i;

            pattern_ram_write_step(part, offset + i, &tmp);
        }
        return nsteps;
    }

    /* fallback: use firmware write */
    for (int i = 0; i < nsteps; ++i)
    {
        ft_step_t tmp = src[i];
        tmp.part = (uint8_t)part;
        tmp.step = (uint8_t)i;
        (void)ft_write_step(&tmp);
    }

    return nsteps;
}

/* High-level write wrapper (writes a block starting at step 0 of the active page) */
int pattern_write_steps(int part, const ft_step_t *src, int n)
{
    if (!src || n <= 0) return 0;
    return pattern_write_page(part, src, n, g_active_page);
}

/* -------------------------------------------------------------------
   Single-step writer (FIXED)
   IMPORTANT: Must write to the requested step index, not always step 0.
   ------------------------------------------------------------------- */
int pattern_write_step(int part, int step, int pitch, int velocity, int gate)
{
    int ps = safe_page_size();
    step = clampi(step, 0, ps - 1);

    ft_step_t s;
    memset(&s, 0, sizeof(s));
    s.part     = (uint8_t)part;
    s.step     = (uint8_t)step;
    s.pitch    = (uint8_t)pitch;
    s.velocity = (uint8_t)velocity;
    s.gate     = (uint8_t)gate;

    /* If RAM is available, write directly at correct physical index */
    if (pattern_ram_map_is_available())
    {
        int offset = g_active_page * ps;
        return pattern_ram_write_step(part, offset + step, &s);
    }

    /* firmware fallback */
    return (int)ft_write_step(&s);
}

/* -------------------------------------------------------------
   Compatibility shim: set pattern (page) number
   (Some firmware hooks call this)
   ------------------------------------------------------------- */
void set_pattern_number(int pat)
{
    pattern_set_active_page(pat);
}
