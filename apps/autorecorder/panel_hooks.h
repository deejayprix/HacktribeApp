#ifndef PANEL_HOOKS_H
#define PANEL_HOOKS_H

#include <stdint.h>
#include "ft_config.h"

// Firmware panel handler signature
typedef void (*panel_handler_t)(unsigned char *pkt, int len, unsigned int a, unsigned int b);

// Send any raw panel event to firmware
static inline void panel_send_raw(void* handler, uint8_t code, uint8_t arg1, uint8_t arg2)
{
    panel_handler_t h = (panel_handler_t)handler;
    if (!h) return;

    unsigned char pkt[12] = {0};
    pkt[0] = code;
    pkt[1] = arg1;
    pkt[2] = arg2;

    h(pkt, sizeof(pkt), 0, 0);
}

// ==========================
// OFFIZIELLE ELECTRIBE BUTTONS
// ==========================
static inline void panel_play(void)
{
    panel_send_raw(ADDR_PLAY_HANDLER, 0x50, 0, 0);
}

static inline void panel_record(void)
{
    panel_send_raw(ADDR_RECORD_HANDLER, 0x52, 0, 0);
}

static inline void panel_stop(void)
{
    panel_send_raw(ADDR_STOP_HANDLER, 0x53, 0, 0);
}

static inline void panel_write(void)
{
    panel_send_raw(ADDR_WRITE_HANDLER, 0x57, 0, 0);
}

// ==========================
// VERSTECKTE CUSTOM PANEL SLOTS (0x52–0x57)
// ==========================
// Diese existieren laut Disassembly & Paket4
static inline void panel_custom(uint8_t panel_id, uint8_t a, uint8_t b)
{
    if (panel_id < 0x52 || panel_id > 0x57)
        return;

    panel_send_raw(ADDR_RECORD_HANDLER, panel_id, a, b);
}

#endif
