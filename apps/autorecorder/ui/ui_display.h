#ifndef UI_DISPLAY_H
#define UI_DISPLAY_H

#include <stdint.h>

/* Standarddauer für Popup-Meldungen */
#define UI_MSG_TIMEOUT_MS 1800

/* Eine kurze 1-Zeilen Meldung anzeigen */
void ui_show_message(const char *msg);

/* Mehrzeilige Nachricht (automatische Umbrüche + Timeout) */
void ui_show_message_long(const char *msg);

/* Eine Nachricht erzwingen (ohne Warteschlange) */
void ui_force_message(const char *msg);

/* Wird 1× pro Frame aus main_loop() aufgerufen */
void ui_display_tick(uint32_t ms_elapsed);

#endif
