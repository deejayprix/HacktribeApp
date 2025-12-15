#include "display_manager.h"

/* TODO: Hardware-spezifische Display-Funktionen eintragen */
extern void hw_display_clear(void);
extern void hw_display_text(const char *txt);
extern uint32_t ft_millis(void);

static uint32_t display_timeout = 0;
static display_page_t current_page = DISP_MAIN;

void display_show(const char *msg, uint16_t ms)
{
    hw_display_clear();
    hw_display_text(msg);
    display_timeout = ft_millis() + ms;
}

void display_set_page(display_page_t page)
{
    current_page = page;

    /* TODO: deutschsprachige Texte */
    switch (page) {
        case DISP_SAVE_CONFIRM:
            display_show("Speichern?  (WRITE)", 1200);
            break;

        case DISP_SAVE_SUCCESS:
            display_show("Speichern erfolgreich!", 1200);
            break;

        case DISP_SAVE_ERROR:
            display_show("Fehler beim Speichern!", 1500);
            break;

        case DISP_WARNING:
            display_show("Achtung!", 1000);
            break;

        default:
            break;
    }
}

void display_update(void)
{
    if (display_timeout && ft_millis() > display_timeout) {
        display_timeout = 0;
        hw_display_clear();
        current_page = DISP_MAIN;

        /* TODO: MAIN-SCREEN zeichnen */
    }
}
