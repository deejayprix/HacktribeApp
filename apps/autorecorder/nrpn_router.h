#ifndef NRPN_ROUTER_H
#define NRPN_ROUTER_H

#include <stdint.h>

/*
 * NRPN Router – Transaction-safe
 *
 * Unterstützt 2 Aufrufarten (ohne API-Sprung):
 *
 *  A) CC-Stream (empfohlen, DAW: CC99/CC98/CC6 (+CC38)):
 *     nrpn_handle(channel, cc, value)
 *     → erkennt automatisch CC99/98/6/38 und verwaltet Transaction-State.
 *
 *  B) Direkt (bereits dekodiertes NRPN):
 *     nrpn_handle(msb, lsb, value)
 *     → wenn "cc" NICHT 99/98/6/38 ist, wird es als (msb,lsb,value) interpretiert.
 *
 * Fail-safe:
 *  - unvollständige Sequenzen werden verworfen (Timeout)
 *  - keine halben Commits
 */

#ifdef __cplusplus
extern "C" {
#endif

/* Polymorpher Entry: siehe Kommentar oben */
void nrpn_handle(int a, int b, int c);

/* Optional tick hook (z.B. 1x pro Frame), um Timeouts abzuräumen */
void nrpn_router_tick(void);

#ifdef __cplusplus
}
#endif

#endif /* NRPN_ROUTER_H */
