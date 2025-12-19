#include "composer_write_export.h"
#include "composer_write_prepare.h"
#include "pattern_writer.h"
#include "e2pat_writer.h"
#include "sysex_helper.h"
#include "midi_out.h"

bool composer_write_export_e2pat(void)
{
    uint8_t buf[4096];

    int len = e2pat_build_file(buf, sizeof(buf));
    if (len < 0)
        return false;

    return e2pat_save_to_media(buf, len);
}

bool composer_write_export_sysex(void)
{
    uint8_t buf[4096];

    int len = sysex_build_full_dump(buf, sizeof(buf));
    if (len <= 0)
        return false;

    return sysex_send_dump(buf, len);
}
