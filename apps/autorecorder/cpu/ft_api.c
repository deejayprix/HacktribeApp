/*
 * ft_api.c
 *
 * Wrapper zwischen App und Electribe Firmwarefunktionen.
 * Diese Version ist kompiliersicher und enthält nur FW-Hooks,
 * KEINE local Pattern-Writer Fallbacks.
 */

#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include <sys/stat.h>    // struct stat fix

#include "ft_api.h"
#include "sync_live.h"
#include "syscalls.h"

/* -------------------------------------------------------------
   Firmware Function Pointer (Platzhalter)
   ------------------------------------------------------------- */
static void (*fw_write_step)(const ft_step_t*)     = 0;
static int  (*fw_get_step_count)(void)             = 0;
static void (*fw_print)(const char *fmt, ...)      = 0;

/* g_live darf NICHT hier definiert werden → wird in sync_live.c definiert */
extern live_sync_state_t g_live;

/* -------------------------------------------------------------
   INIT – muss beim Start aufgerufen werden
   ------------------------------------------------------------- */
void ft_api_init_from_fw(void)
{
    /* Diese Adressen werden später durch echte Firmware-Offsets ersetzt */

    fw_write_step     = (void*)0x080F1234;
    fw_get_step_count = (void*)0x080F12A8;
    fw_print          = (void*)0x080F1ABC;
}

/* -------------------------------------------------------------
   Schritt schreiben
   ------------------------------------------------------------- */
int ft_write_step(const ft_step_t *s)
{
    if (!s)
        return 0;

    if (fw_write_step) {
        fw_write_step(s);
        return 1;
    }

    return 0;
}

/* -------------------------------------------------------------
   Patternlänge abfragen
   ------------------------------------------------------------- */
int ft_get_pattern_step_count(void)
{
    if (fw_get_step_count)
        return fw_get_step_count();

    return 64; /* Electribe Default */
}

/* -------------------------------------------------------------
   Firmware-Print Wrapper
   ------------------------------------------------------------- */
void ft_print(const char *fmt, ...)
{
    if (!fmt)
        return;

    char buf[256];

    va_list va;
    va_start(va, fmt);
    vsnprintf(buf, sizeof(buf), fmt, va);
    va_end(va);

    if (fw_print)
        fw_print("%s", buf);
}

/* -------------------------------------------------------------
   Ticks aus Syscalls
   ------------------------------------------------------------- */
uint32_t ft_get_ticks(void)
{
    return syscall_get_ticks();
}

/* -------------------------------------------------------------
   FEHLENDE API FUNKTIONEN FÜR sync_live.c
   ------------------------------------------------------------- */

int ft_get_current_pattern(void)
{
    return g_live.pattern;
}

int ft_get_play_position(void)
{
    return g_live.step;
}

/* NOTE:
   ft_get_bpm() wird im Projekt bereits in sync.c bereitgestellt.
   Damit es keine "multiple definition" Linker-Fehler gibt,
   wird ft_get_bpm() hier NICHT noch einmal definiert.
*/
