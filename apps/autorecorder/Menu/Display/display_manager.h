#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <stdint.h>

void display_show(const char *msg, uint16_t ms);

/*
    TODO:
    - Display-Seiten Enums ergänzen
    - Menüstrukturen definieren
*/

typedef enum {
    DISP_MAIN,
    DISP_SAVE_CONFIRM,
    DISP_SAVE_SUCCESS,
    DISP_SAVE_ERROR,
    DISP_WARNING,
    DISP_CUSTOM
} display_page_t;

void display_set_page(display_page_t page);
void display_update(void);

#endif
