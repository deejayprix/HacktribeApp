#ifndef NRPN_ROUTER_H
#define NRPN_ROUTER_H

#include <stdint.h>

/*
 * NRPN router entry point.
 * Call this for every received NRPN message:
 *
 *   msb = NRPN MSB (CC#99 value)
 *   lsb = NRPN LSB (CC#98 value)
 *   value = data entry MSB (CC#6 value)
 */
void nrpn_handle(int msb, int lsb, int value);

/*
 * Optional explicit handler for MSB=50 (Live FX, Motion, Mods, Conditions)
 * Called automatically inside nrpn_handle().
 */
void nrpn_handle_msb50(int lsb, int value);
void nrpn_router_tick(void);


#endif /* NRPN_ROUTER_H */
