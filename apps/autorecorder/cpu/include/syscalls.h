#ifndef SYSCALLS_H
#define SYSCALLS_H

#include <stdint.h>     // for uint32_t
#include <stddef.h>     // for ptrdiff_t
#include <sys/types.h>  // for off_t
#include <sys/stat.h>   // for struct stat

/* --------------------------------------------------------------------
   Global Tick Counter Interface (used by ft_api.c)
   -------------------------------------------------------------------- */

extern volatile uint32_t system_ticks;

/* Provided by syscalls.c */
uint32_t syscall_get_ticks(void);


/* --------------------------------------------------------------------
   Memory / Syscall Stubs required by newlib
   -------------------------------------------------------------------- */

void *_sbrk(ptrdiff_t incr);

int _open(const char *name, int flags, int mode);
int _close(int file);

int _fstat(int file, struct stat *st);
int _isatty(int file);

off_t _lseek(int file, off_t ptr, int dir);

int _write(int file, char *ptr, int len);
int _read(int file, char *ptr, int len);

int _kill(int pid, int sig);
int _getpid(void);
void _exit(int status);

#endif /* SYSCALLS_H */
