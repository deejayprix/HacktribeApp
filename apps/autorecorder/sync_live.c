#include "sync_live.h"
#include "ft_api.h"

/* EINZIGE Definition von g_live */
live_sync_state_t g_live;

void live_sync_init(void)
{
    g_live.is_playing = 0;
    g_live.step = 0;
    g_live.bar = 0;
    g_live.tick = 0;
    g_live.pattern = ft_get_current_pattern();
    g_live.bpm_x100 = ft_get_bpm() * 100;
}

void live_sync_on_start(void)
{
    g_live.is_playing = 1;
    g_live.step = 0;
    g_live.bar = 0;
}

void live_sync_on_stop(void)
{
    g_live.is_playing = 0;
}

void live_sync_tick(void)
{
    g_live.tick++;

    if (!g_live.is_playing)
        return;

    g_live.step = ft_get_play_position();
    g_live.bar  = (g_live.step / 16) & 0x03;

    g_live.pattern = ft_get_current_pattern();
    g_live.bpm_x100 = ft_get_bpm() * 100;
}
