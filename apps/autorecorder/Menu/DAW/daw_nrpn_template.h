#ifndef DAW_NRPN_TEMPLATE_H
#define DAW_NRPN_TEMPLATE_H

#include <stdint.h>

/*
    DAW NRPN Template
    =================

    Dieses Template beschreibt:

    - Welche NRPNs DAWs senden müssen
    - Wie Parameter gemappt werden
    - Welche Messages zurückkommen
*/

typedef struct {
    uint16_t nrpn_msb;
    uint16_t nrpn_lsb;
    const char *description;     /* Deutsch */
    const char *daw_hint;        /* DAW-spezifischer Hinweis */
} daw_nrpn_entry_t;

extern const daw_nrpn_entry_t g_daw_nrpn_map[];

#endif
