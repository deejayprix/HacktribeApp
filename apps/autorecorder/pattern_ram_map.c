#include "pattern_ram_map.h"
#include "ft_types.h"

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/*
 * Pattern RAM Mapper (Hardened Version)
 *
 * Goals:
 *  - Always write/read full ft_step_t
 *  - Prevent out-of-bounds access via capacity tracking
 *  - Keep API stable (only additive helper function)
 *  - Optional debug guard prints (compile-time)
 */

/* =========================
   CONFIG: Debug Guards
   ========================= */
#ifndef PATTERN_RAM_MAP_DEBUG
#define PATTERN_RAM_MAP_DEBUG 0
#endif

#if PATTERN_RAM_MAP_DEBUG
#include "ft_api.h"
#define PRM_DBG(...) ft_print(__VA_ARGS__)
#else
#define PRM_DBG(...) do{}while(0)
#endif

/* =========================
   INTERNAL STATE
   ========================= */
static bool     g_enabled      = true;
static uint8_t *g_base         = NULL;
static size_t   g_step_size    = 0;      /* should be sizeof(ft_step_t) */
static size_t   g_capacity_b   = 0;      /* size of RAM region in bytes */

/* fallback buffer (default) */
#define FALLBACK_STEPS 1024

/* =========================
   INTERNAL HELPERS
   ========================= */
static inline size_t step_size_safe(void)
{
    return (g_step_size != 0) ? g_step_size : sizeof(ft_step_t);
}

static inline size_t max_steps_safe(void)
{
    size_t ss = step_size_safe();
    if (!g_base || ss == 0 || g_capacity_b < ss) return 0;
    return g_capacity_b / ss;
}

static inline bool idx_in_range(int idx)
{
    if (idx < 0) return false;
    size_t maxs = max_steps_safe();
    return ((size_t)idx < maxs);
}

/* =========================
   PUBLIC API
   ========================= */
void pattern_ram_map_init(void)
{
    g_step_size = sizeof(ft_step_t);

    /* Provide fallback storage if not set */
    if (!g_base)
    {
        static uint8_t fallback_ram[sizeof(ft_step_t) * FALLBACK_STEPS];
        g_base = fallback_ram;
        g_capacity_b = sizeof(fallback_ram);
    }
    else
    {
        /* If base is already set but capacity not, we cannot safely bounds-check.
           Keep available, but warn in debug mode. */
        if (g_capacity_b == 0)
            PRM_DBG("[pattern_ram_map] WARN: base set without capacity; bounds checks limited.\n");
    }

    g_enabled = true;
}

bool pattern_ram_map_is_available(void)
{
    return g_enabled && (g_base != NULL);
}

void pattern_ram_map_set_base(void *addr)
{
    g_base = (uint8_t *)addr;
    /* legacy setter: capacity unknown -> no hard bounds possible unless user calls set_base_ex */
    g_capacity_b = 0;
#if PATTERN_RAM_MAP_DEBUG
    PRM_DBG("[pattern_ram_map] set_base(addr=%p) capacity=UNKNOWN\n", addr);
#endif
}

/* NEW (additive, safe): set base + size */
void pattern_ram_map_set_base_ex(void *addr, size_t bytes)
{
    g_base = (uint8_t *)addr;
    g_capacity_b = bytes;
#if PATTERN_RAM_MAP_DEBUG
    PRM_DBG("[pattern_ram_map] set_base_ex(addr=%p, bytes=%u)\n", addr, (unsigned)bytes);
#endif
}

void pattern_ram_map_enable(bool enable)
{
    g_enabled = enable;
}

size_t pattern_ram_step_size(void)
{
    return step_size_safe();
}

size_t pattern_ram_max_steps(void)
{
    return max_steps_safe();
}

uint8_t *pattern_ram_step_address(int idx)
{
    if (!g_enabled || !g_base)
        return NULL;

    /* If capacity unknown, we can only compute address (legacy behavior).
       If capacity known, enforce bounds. */
    if (g_capacity_b != 0)
    {
        if (!idx_in_range(idx))
        {
            PRM_DBG("[pattern_ram_map] OOB step_address idx=%d (max=%u)\n",
                    idx, (unsigned)max_steps_safe());
            return NULL;
        }
    }
    else
    {
        /* Capacity unknown: cannot bounds-check */
        if (idx < 0) return NULL;
    }

    size_t ss = step_size_safe();
    return g_base + ((size_t)idx * ss);
}

/* Write full ft_step_t to RAM */
int pattern_ram_write_step(int part, int idx, const ft_step_t *s)
{
    (void)part;

    if (!g_enabled || !g_base || !s)
        return 0;

    /* If we know capacity, enforce bounds strictly */
    if (g_capacity_b != 0 && !idx_in_range(idx))
    {
        PRM_DBG("[pattern_ram_map] OOB write idx=%d (max=%u)\n",
                idx, (unsigned)max_steps_safe());
        return 0;
    }

    /* Legacy mode (capacity unknown): best effort but still require non-negative index */
    if (g_capacity_b == 0 && idx < 0)
        return 0;

    uint8_t *p = pattern_ram_step_address(idx);
    if (!p)
        return 0;

    memcpy(p, s, sizeof(ft_step_t));
    return 1;
}

/* NEW (additive): Read full ft_step_t from RAM */
int pattern_ram_read_step(int idx, ft_step_t *out)
{
    if (!g_enabled || !g_base || !out)
        return 0;

    if (g_capacity_b != 0 && !idx_in_range(idx))
    {
        PRM_DBG("[pattern_ram_map] OOB read idx=%d (max=%u)\n",
                idx, (unsigned)max_steps_safe());
        return 0;
    }

    if (g_capacity_b == 0 && idx < 0)
        return 0;

    uint8_t *p = pattern_ram_step_address(idx);
    if (!p)
        return 0;

    memcpy(out, p, sizeof(ft_step_t));
    return 1;
}
