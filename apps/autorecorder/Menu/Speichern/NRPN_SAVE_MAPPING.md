# NRPN Mapping — Save / Speichern (AutoRecorder)

> Konvention: MSB = 0 für Menü-Panels (wie gewünscht). LSB codiert die Funktion innerhalb des Panels.
> NRPN uses: NRPN MSB = 0, NRPN LSB = [LSB value] — DataEntry(MSB) carries payload/value.

## Übersicht / Kurzfassung
- **Panel**: MSB = `0` (Menü / UI)
- **Sub-IDs (LSB)**: 0x40..0x4F reserved for "Speichern" menu
- **Werte**: Data Entry MSB (CC 6) überträgt 0..127 (oder längere Streams in mehrere NRPN-Frames).

## LSB Codes (empfohlen)
| LSB (dec/hex) | Name | Beschreibung | Werte / Payload |
|---:|---|---|---|
| 64 / 0x40 | SAVE_REQUEST | Startet Save-Request. DataEntry: Modus (1=Sysex+e2Pat, 2=e2Pat, 3=Sysex) | 1..3 |
| 65 / 0x41 | SAVE_CONFIRM | Bestätigung. DataEntry: 1 = accept, 0 = cancel | 0/1 |
| 66 / 0x42 | SAVE_STATUS | Outgoing — Status reporting (Log) | 0=Idle,1=Saving,2=Saved,3=Error |
| 67 / 0x43 | SAVE_NAME_STREAM | Streaming eines ASCII-Namens (8-bit per NRPN value = ASCII) — Use sequence numbers or termination char (0x00). | mehrere NRPNs: each DataEntry=ASCII byte |
| 68 / 0x44 | SAVE_MODE_SET | Setzt Default Save Mode persistent (same encoding as SAVE_REQUEST) | 1..3 |
| 69 / 0x45 | SAVE_ICON_REQ | Request to show a save icon on Display (DataEntry: icon id) | 0..127 |

## Status Meldungen (Log, an DAW / Host gesendet)
Beim Start eines Requests (aus Gerät oder DAW) sendet das Gerät per NRPN oder SysEx folgende Log-Strings (gerendert lokal; NRPN-Ausgabe optional):
- `NRPN: SAVE_REQUEST geladen`  — wenn ein SAVE_REQUEST empfangen wurde
- `NRPN: SAVE_CONFIRM gespeichert` — nach erfolgreichem Speichern

## Name-Streaming (praktische Regeln)
- Beginne mit NRPN (MSB=0, LSB=67) für ersten Byte.
- Verwende DataEntry MSB (CC6) zum Übertragen eines Bytes.
- Terminiere mit ASCII `0x00` oder mit `SAVE_CONFIRM` (LSB=65, value=1).

## Beispiele
**Host → Gerät:** Save request for Sysex+e2Pat:
- NRPN MSB=0 (CC99 = 0)
- NRPN LSB=64 (CC98 = 64)
- DATA ENTRY (CC6) = 1

**Host → Gerät:** Name "beat01" streamen:
- MSB=0 LSB=67 DataEntry= 'b' (0x62)
- MSB=0 LSB=67 DataEntry= 'e' (0x65)
- ...
- MSB=0 LSB=67 DataEntry= 0x00 (terminator)
- MSB=0 LSB=65 DataEntry=1 (SAVE_CONFIRM)

## Hinweise zur Implementation
- Implementiere eine Timeout (z. B. 5s) beim Name-Streaming, falls Terminator fehlt.
- Sicherstellen: NRPN-IDs nicht mit anderen Panels kollidieren.
- Lokal UI-Texte in Deutsch / Anzeige-Strings wie oben definieren.

