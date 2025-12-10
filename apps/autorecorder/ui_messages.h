#ifndef UI_MESSAGES_H
#define UI_MESSAGES_H

#include <stdint.h>

/*
 * Simple UI abstraction layer for AutoRecorder
 * All messages / icons in DEUTSCH.
 *
 * Diese Funktionen können später auf das echte Display,
 * OLED, LCD oder SysEx-Statusmeldung umgebogen werden.
 */

void ui_show_message(const char *msg);
void ui_show_icon(const uint8_t *bitmap, int w, int h);

#endif /* UI_MESSAGES_H */
