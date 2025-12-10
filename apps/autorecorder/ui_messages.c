#include "ui_messages.h"
#include "ft_api.h"     /* wegen ft_print – existiert bereits */

void ui_show_message(const char *msg)
{
    /* Placeholder: Ausgabe in UART/Debug-Konsole */
    ft_print("[UI] %s\n", msg);

    /* TODO: Später Display ansteuern */
}

void ui_show_icon(const uint8_t *bitmap, int w, int h)
{
    /* Placeholder: Keine echte Grafik-Ausgabe */
    ft_print("[UI] Icon (%dx%d) angezeigt.\n", w, h);

    /* TODO: Pixel-Draw implementieren */
}
