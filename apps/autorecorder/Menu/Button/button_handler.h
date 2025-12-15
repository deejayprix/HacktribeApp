#ifndef BUTTON_HANDLER_H
#define BUTTON_HANDLER_H

#include <stdint.h>
#include <stdbool.h>

// Enum für interne Tasten
typedef enum {
    BTN_WRITE,
    BTN_EXIT,
    BTN_STOP,
    BTN_PLAY,
    BTN_SHIFT,
    BTN_NONE
} button_id_t;

// Wird vom Hardware-ISR oder Polling aufgerufen
void button_process(button_id_t btn, bool pressed);

// Interne Funktionen
void button_handle_single(button_id_t btn);
void button_handle_double(button_id_t btn);
void button_handle_long(button_id_t btn);

#endif
