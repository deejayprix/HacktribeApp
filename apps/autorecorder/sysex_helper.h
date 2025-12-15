#ifndef SYSEX_HELPER_H
#define SYSEX_HELPER_H

#include <stdint.h>
#include <stdbool.h>

/* ============================================================
   Sysex Helper – Platzhalter
   Funktioniert als Dummy, bis echte Sysex-Logik implementiert wird
   ============================================================ */

/* Beispiel: Erstelle Sysex Dump in Buffer */
static inline int sysex_build_full_dump(uint8_t *out, int maxlen)
{
    /* TODO:
       - Gerätezustand abfragen
       - Original Electribe Strukturen füllen
       - Echte Sysex Formatierung implementieren
    */

    /* Platzhalter: erzeugt leeren Dump */
    if (!out || maxlen <= 0) return 0;
    return 0;
}

/* Beispiel: sende fertigen Sysex-Dump */
static inline bool sysex_send_dump(const uint8_t *data, int len)
{
    /* TODO:
       - UART / MIDI OUT senden
       - CHUNKING 256b
       - NRPN Log: "Sysex Dump gesendet"
    */

    (void)data;
    (void)len;
    return true;
}

#endif /* SYSEX_HELPER_H */
