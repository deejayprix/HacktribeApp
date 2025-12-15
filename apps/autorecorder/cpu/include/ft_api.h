#ifndef FT_API_H
#define FT_API_H

#include <stdint.h>
#include "ft_types.h"

/* -------------------------------------------------------------
   Core print/debug interface
   ------------------------------------------------------------- */
void ft_print(const char *fmt, ...);
void ft_puts(const char *s);
void set_pattern_number(int pat);

/* -------------------------------------------------------------
   Pattern read/write
   ------------------------------------------------------------- */
int ft_write_step(const ft_step_t *s);

/* -------------------------------------------------------------
   Sequencer info (dummy in Autorecorder)
   ------------------------------------------------------------- */
int ft_get_current_pattern(void);
int ft_get_play_position(void);
int ft_get_current_bar(void);
int ft_get_pattern_step_count(void);
int ft_get_bpm(void);


/* -------------------------------------------------------------
   Initialization
   ------------------------------------------------------------- */
void ft_api_init_from_fw(void);

#endif /* FT_API_H */
