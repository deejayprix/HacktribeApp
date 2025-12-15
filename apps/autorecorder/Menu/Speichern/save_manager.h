#ifndef SAVE_MANAGER_H
#define SAVE_MANAGER_H

#include <stdint.h>

void save_manager_init(void);
int save_manager_request_save(uint8_t mode, const char *name);
void save_manager_confirm(int accept);
void save_manager_stream_name_byte(uint8_t b);
void save_manager_send_status(uint8_t status_code);
void save_manager_trigger_ui_save(uint8_t mode);

#endif /* SAVE_MANAGER_H */