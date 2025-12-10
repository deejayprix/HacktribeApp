#include "midi_out.h"

/* Dummy-Ausgabe — später ersetzen durch echte UART/USART Ausgabe */
void midi_send_byte(uint8_t b)
{
    (void)b;
    /* TODO: Hardware UART Implementierung */
}
