// sync.c — BPM / timing helpers for autorecorder, randomizer & song mode
// Safe with fallback if firmware BPM function not available.

#include "ft_config.h"
#include <stdint.h>

/* Firmware function type */
typedef int (*fw_get_bpm_t)(void);

/* -------------------------------------------------------
   ft_get_bpm()
   - Reads BPM from firmware if ADDR_GET_BPM_FUNC != 0
   - Otherwise returns FT_DEFAULT_BPM safely.
   ------------------------------------------------------- */
int ft_get_bpm(void)
{
    if ((uintptr_t)ADDR_GET_BPM_FUNC != 0 && FT_USE_FW_GET_BPM)
    {
        fw_get_bpm_t f = (fw_get_bpm_t)ADDR_GET_BPM_FUNC;
        if (f)
        {
            int bpm = f();
            if (bpm > 0 && bpm < 400)   // sanity range
                return bpm;
        }
    }

    return FT_DEFAULT_BPM;
}

/* -------------------------------------------------------
   ft_ms_per_beat()
   - convert BPM → ms per beat
   ------------------------------------------------------- */
int ft_ms_per_beat(void)
{
    int bpm = ft_get_bpm();
    if (bpm <= 0) bpm = FT_DEFAULT_BPM;
    return 60000 / bpm;
}

/* -------------------------------------------------------
   ft_ms_per_bar()
   - assumes 4/4 signature for Electribe (true for all E2)
   ------------------------------------------------------- */
int ft_ms_per_bar(void)
{
    return ft_ms_per_beat() * 4;
}

/* -------------------------------------------------------
   ft_wait_ms()
   Safe busy-wait implementation used across project
   (Auto-Recorder, Song Mode, Randomizer operations).
   ------------------------------------------------------- */
void ft_wait_ms(int ms)
{
    volatile int i;
    // calibrated roughly to ARM E2 speed, same as original recorder
    for (i = 0; i < ms * 2000; ++i)
    {
        __asm__ volatile("nop");
    }
}

/* -------------------------------------------------------
   ft_wait_bars()
   Wait N bars using BPM-derived timing.
   Used by Song Mode for pattern playback timing.
   ------------------------------------------------------- */
void ft_wait_bars(int bars)
{
    if (bars <= 0) return;

    int total = bars * ft_ms_per_bar();
    int chunk = 100; // 100 ms → responsive to break conditions
    int waited = 0;

    while (waited < total)
    {
        int rem = total - waited;
        int step = (rem < chunk) ? rem : chunk;
        ft_wait_ms(step);
        waited += step;
    }
}
