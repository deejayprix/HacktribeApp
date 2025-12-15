/* scale_engine.c
   Minimal implementation for scale engine functions referenced by randomizer.
*/

#include "scale_engine.h"
#include <stdint.h>
#include <string.h>

#define MAX_CHANNELS 16

static scale_type_t g_channel_scale[MAX_CHANNELS];
static int g_channel_tonic[MAX_CHANNELS];
static uint16_t g_channel_mask[MAX_CHANNELS];

int scale_engine_set_channel_scale(int ch, scale_type_t s, int tonic) {
    if (ch < 0 || ch >= MAX_CHANNELS) return -1;
    g_channel_scale[ch] = s;
    g_channel_tonic[ch] = tonic;
    return 0;
}
int scale_engine_get_channel_scale(int ch, scale_type_t *s, int *tonic) {
    if (ch < 0 || ch >= MAX_CHANNELS) return -1;
    if (s) *s = g_channel_scale[ch];
    if (tonic) *tonic = g_channel_tonic[ch];
    return 0;
}

int scale_engine_set_channel_custom_mask(int ch, uint16_t mask) {
    if (ch < 0 || ch >= MAX_CHANNELS) return -1;
    g_channel_mask[ch] = mask;
    return 0;
}
uint16_t scale_engine_get_channel_custom_mask(int ch) {
    if (ch < 0 || ch >= MAX_CHANNELS) return 0x0FFF;
    return g_channel_mask[ch];
}

/* naive mapping: returns same pitch, but clamp to 0..127 */
int scale_engine_map_pitch_to_scale(int ch, int pitch) {
    if (pitch < 0) pitch = 0;
    if (pitch > 127) pitch = 127;
    (void)ch;
    return pitch;
}

void scale_engine_commit_channel(int ch)
{
    (void)ch;
    /* future: store into persistent scale table */
}

void scale_engine_reset_channel(int ch)
{
    (void)ch;
    /* future: reset scale to default */
}
