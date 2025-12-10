#include "pattern_ram_map.h"
#include "ft_types.h"
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/*
 * Pattern RAM Mapper (Software-Fallback Version)
 *
 * Diese Datei stellt ein RAM-basiertes Pattern-Mapping bereit,
 * falls kein Firmware-Pattern-RAM verfügbar ist.
 *
 * Mit den letzten Fixes speichert/wiederherstellt dieses Modul nun
 * *vollständige ft_step_t-Strukturen* und ist damit kompatibel mit:
 *
 *  - pattern_writer.c
 *  - randomizer.c
 *  - undo-system
 *  - NRPN-/Pattern-Transformationspipelines
 */

/* -------------------------------------------------------------
   Interner Zustand
   ------------------------------------------------------------- */
static bool     g_enabled   = true;        // RAM-map aktiv?
static uint8_t *g_base      = NULL;        // Zeiger auf RAM-Puffer
static size_t   g_step_size = 0;           // Größe eines Steps in Bytes


/* ----------------------------------------------------------------------------
   Initialisierung der RAM-Map

   Wichtig:
   - g_step_size wird jetzt auf sizeof(ft_step_t) gesetzt
   - fallback_ram ist groß genug für ca. 1024 Steps
   ---------------------------------------------------------------------------- */
void pattern_ram_map_init(void)
{
    /* Schrittgröße = vollständige ft_step_t-Struktur */
    g_step_size = sizeof(ft_step_t);

    /* Fallback-Speicher bereitstellen, falls nichts extern gesetzt wurde */
    if (!g_base)
    {
        /* 1024 Steps → reicht für Pattern aller Längen */
        static uint8_t fallback_ram[sizeof(ft_step_t) * 1024];
        g_base = fallback_ram;
    }

    g_enabled = true;
}


/* -------------------------------------------------------------
   Map-Status abfragen
   ------------------------------------------------------------- */
bool pattern_ram_map_is_available(void)
{
    return g_enabled && g_base != NULL;
}


/* -------------------------------------------------------------
   Basisadresse des Pattern-RAM setzen (z. B. Firmware-RAM)
   ------------------------------------------------------------- */
void pattern_ram_map_set_base(void *addr)
{
    g_base = (uint8_t *)addr;
}


/* -------------------------------------------------------------
   RAM-Map aktivieren/deaktivieren
   ------------------------------------------------------------- */
void pattern_ram_map_enable(bool enable)
{
    g_enabled = enable;
}


/* -------------------------------------------------------------
   Schrittgröße zurückgeben
   ------------------------------------------------------------- */
size_t pattern_ram_step_size(void)
{
    return g_step_size ? g_step_size : sizeof(ft_step_t);
}


/* ----------------------------------------------------------------------------
   Adresse eines Steps im RAM berechnen
   ---------------------------------------------------------------------------- */
uint8_t *pattern_ram_step_address(int idx)
{
    if (!g_enabled || g_base == NULL)
        return NULL;

    size_t step = pattern_ram_step_size();
    return g_base + (idx * step);
}


/* ----------------------------------------------------------------------------
   Step in RAM schreiben

   NEU (fix):
   - Es wird *die gesamte ft_step_t-Struktur* geschrieben
   - Dadurch sind part/step/pitch/velocity/gate konsistent
   ---------------------------------------------------------------------------- */
int pattern_ram_write_step(int part, int idx, const ft_step_t *s)
{
    (void)part;

    uint8_t *p = pattern_ram_step_address(idx);
    if (!p || !s)
        return 0;

    memcpy(p, s, sizeof(ft_step_t));
    return 1;
}
