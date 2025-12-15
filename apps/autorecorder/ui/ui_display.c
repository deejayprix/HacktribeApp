#include "ui_display.h"
#include "app_log.h"
#include "ft_api.h"     /* draw_text(), clear_display() usw. */
#include <string.h>
#include <stdio.h>

typedef struct {
    char text[64];
    uint32_t timer;
    uint8_t active;
} ui_msg_t;

static ui_msg_t msg_queue[4];
static uint8_t queue_head = 0;
static uint8_t queue_tail = 0;

/* interne Hilfsfunktion */
static void ui_queue_push(const char *txt)
{
    uint8_t next = (queue_tail + 1) & 3;
    if (next == queue_head) {
        /* Queue voll, wir verwerfen die älteste Meldung */
        queue_head = (queue_head + 1) & 3;
    }

    strncpy(msg_queue[queue_tail].text, txt, sizeof(msg_queue[queue_tail].text));
    msg_queue[queue_tail].text[sizeof(msg_queue[queue_tail].text) - 1] = '\0';
    msg_queue[queue_tail].timer = UI_MSG_TIMEOUT_MS;
    msg_queue[queue_tail].active = 1;

    queue_tail = next;
}

/* UTF-8 zu Electribe-kompatibel */
static void ui_normalize_text(char *dst, const char *src)
{
    while (*src && strlen(dst) < 63)
    {
        switch (*src)
        {
            case 'ä': strcat(dst, "ae"); break;
            case 'ö': strcat(dst, "oe"); break;
            case 'ü': strcat(dst, "ue"); break;
            case 'Ä': strcat(dst, "Ae"); break;
            case 'Ö': strcat(dst, "Oe"); break;
            case 'Ü': strcat(dst, "Ue"); break;
            case 'ß': strcat(dst, "ss"); break;
            default:
                {
                    size_t len = strlen(dst);
                    dst[len] = *src;
                    dst[len+1] = '\0';
                }
                break;
        }
        src++;
    }
}

/* 1-Zeilen Popup */
void ui_show_message(const char *msg)
{
    char normalized[64] = {0};
    ui_normalize_text(normalized, msg);

    ui_queue_push(normalized);
    app_log(normalized);
}

/* Mehrzeilige Meldungen (automatisch umbrechen) */
void ui_show_message_long(const char *msg)
{
    char tmp[64] = {0};
    ui_normalize_text(tmp, msg);

    /* Hard break nach 16 Zeichen (Electribe Display Breite) */
    char line1[20] = {0}, line2[20] = {0}, line3[20] = {0};
    strncpy(line1, tmp, 16);
    strncpy(line2, tmp + 16, 16);
    strncpy(line3, tmp + 32, 16);

    ui_queue_push(line1);
    if (line2[0]) ui_queue_push(line2);
    if (line3[0]) ui_queue_push(line3);
}

/* Meldung sofort anzeigen (SAVE-Popup) */
void ui_force_message(const char *msg)
{
    char normalized[64] = {0};
    ui_normalize_text(normalized, msg);

    ft_api_clear_display();
    ft_api_draw_text(0, 0, normalized);
    ft_api_refresh();

    app_log(normalized);
}

/* Wird in main loop aufgerufen */
void ui_display_tick(uint32_t ms_elapsed)
{
    if (queue_head == queue_tail)
        return; /* keine Meldung aktiv */

    ui_msg_t *m = &msg_queue[queue_head];

    if (!m->active)
        return;

    ft_api_clear_display();
    ft_api_draw_text(0, 0, m->text);
    ft_api_refresh();

    if (m->timer > ms_elapsed)
        m->timer -= ms_elapsed;
    else
    {
        /* Meldung abgelaufen */
        m->active = 0;
        queue_head = (queue_head + 1) & 3;
    }
}
