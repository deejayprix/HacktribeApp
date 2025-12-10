#include "button_handler.h"
#include "save_manager.h"
#include "display_manager.h"
#include "ft_log.h"

/* -----------------------------------------------------------
   Konfiguration / Platzhalter
   ----------------------------------------------------------- */

/*
    TODO:
    - Debounce-Time definieren
    - Doubleclick-Zeit definieren
    - Longpress-Zeit definieren
*/
static const int DOUBLECLICK_MS = 300;
static const int LONGPRESS_MS   = 600;

/*
    TODO:
    - Falls Hardware via GPIO ISR geliefert wird:
      -> button_process() in GPIO-Callback aufrufen
*/

/* -----------------------------------------------------------
   Button States
   ----------------------------------------------------------- */
typedef struct {
    bool pressed;
    uint32_t last_time;
    uint32_t press_start;
} button_state_t;

static button_state_t btn_state[BTN_NONE];

/* Platzhalter: Timer-Funktion */
extern uint32_t ft_millis(void);

/* -----------------------------------------------------------
    MAIN ENTRY: button_process()
----------------------------------------------------------- */

void button_process(button_id_t btn, bool pressed)
{
    if (btn >= BTN_NONE) return;

    button_state_t *st = &btn_state[btn];
    uint32_t now = ft_millis();

    if (pressed && !st->pressed) {
        // FIRST PRESS
        st->pressed = true;
        st->press_start = now;

        /* TODO:
            - Aktionen bei Button-Down
            - akustisches Feedback?
        */
    }
    else if (!pressed && st->pressed) {
        // RELEASE
        st->pressed = false;
        uint32_t held = now - st->press_start;

        if (held >= LONGPRESS_MS) {
            button_handle_long(btn);
        }
        else {
            // check for double
            if (now - st->last_time < DOUBLECLICK_MS) {
                button_handle_double(btn);
            } else {
                button_handle_single(btn);
            }
            st->last_time = now;
        }
    }
}

/* -----------------------------------------------------------
    BUTTON-ACTIONS / Platzhalter für Funktionen
----------------------------------------------------------- */

void button_handle_single(button_id_t btn)
{
    switch (btn)
    {
        case BTN_WRITE:
            /* WRITE = Save Confirm */
            save_confirm();
            display_show("Gespeichert (WRITE)", 900);
            break;

        case BTN_EXIT:
            /* EXIT cancelt Save */
            save_cancel();
            display_show("Abgebrochen (EXIT)", 900);
            break;

        case BTN_STOP:
            /* TODO STOP */
            display_show("STOP gedrückt", 600);
            break;

        default:
            break;
    }
}

void button_handle_double(button_id_t btn)
{
    /* TODO:
        - doubleclick functions eintragen
        - z.B. Save sofort ohne Nachfrage?
    */
    display_show("Doppelklick erkannt", 600);
}

void button_handle_long(button_id_t btn)
{
    /* TODO:
        - longpress functions eintragen
        - Hold WRITE → Quick-Save?
        - Hold EXIT → Hard-Abbruch?
    */
    display_show("Lange gedrückt", 600);
}
