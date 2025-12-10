#ifndef SYNC_LIVE_H
#define SYNC_LIVE_H

#include <stdint.h>

typedef struct {
    uint8_t is_playing;      // 1 = Sequencer läuft
    uint16_t step;           // Step Position (0..63 oder erweitert)
    uint8_t bar;             // berechneter Takt 0–3
    uint32_t tick;           // interner globaler Tick
    uint8_t pattern;         // aktuelles Pattern
    uint32_t bpm_x100;       // BPM * 100
} live_sync_state_t;

extern live_sync_state_t g_live;

void live_sync_init(void);
void live_sync_tick(void);
void live_sync_on_start(void);
void live_sync_on_stop(void);

#endif
