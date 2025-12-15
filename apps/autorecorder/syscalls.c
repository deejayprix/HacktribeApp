/*
 * syscalls.c
 *
 * Minimal-Implementierung für newlib auf der Electribe-CPU.
 * Stellt Memory-Allocation, Write/Read-Stubs und Tick-System bereit.
 */

#include <sys/stat.h>
#include <errno.h>
#include <stdint.h>
#include <stddef.h>

/* --------------------------------------------------------------------
   Heap für malloc() – vom Linker vorgegeben
   -------------------------------------------------------------------- */

extern uint32_t _end;     // Start des freien RAM (nach BSS)
extern uint32_t _estack;  // Ende des RAM (oberes Limit vom Linker)

static uint8_t *heap_ptr = (uint8_t *)&_end;

void *_sbrk(ptrdiff_t incr)
{
    uint8_t *prev = heap_ptr;
    uint8_t *next = heap_ptr + incr;

    if (next >= (uint8_t *)&_estack) {
        errno = ENOMEM;
        return (void *)-1;
    }

    heap_ptr = next;
    return prev;
}

/* --------------------------------------------------------------------
   newlib Syscalls – Dummy-Implementierungen
   -------------------------------------------------------------------- */

int _open(const char *name, int flags, int mode)
{
    (void)name; (void)flags; (void)mode;
    return -1;       // keine Dateien vorhanden
}

int _close(int file)
{
    (void)file;
    return -1;
}

int _fstat(int file, struct stat *st)
{
    (void)file;
    st->st_mode = S_IFCHR;   // Character device
    return 0;
}

int _isatty(int file)
{
    (void)file;
    return 1;
}

off_t _lseek(int file, off_t ptr, int dir)
{
    (void)file; (void)ptr; (void)dir;
    return 0;
}

/* --------------------------------------------------------------------
   Write: Weiterleitung an ft_puts (falls benötigt)
   -------------------------------------------------------------------- */

extern void ft_puts(const char *s);   // optional

int _write(int file, char *ptr, int len)
{
    (void)file;

    // Optional: Text an Firmware-Print weiterleiten
    // ACHTUNG: ptr ist kein Nullterminierter String
    // Ft_puts akzeptiert nur nullterminierte Strings → also NICHT benutzen.

    return len;   // OK, "geschrieben"
}

/* --------------------------------------------------------------------
   Read: nicht unterstützt
   -------------------------------------------------------------------- */

int _read(int file, char *ptr, int len)
{
    (void)file; (void)ptr; (void)len;
    return 0;
}

/* --------------------------------------------------------------------
   Prozesskontrolle – nicht verwendet
   -------------------------------------------------------------------- */

int _kill(int pid, int sig)
{
    (void)pid; (void)sig;
    return -1;
}

int _getpid(void)
{
    return 1;
}

void _exit(int status)
{
    (void)status;
    while (1) {}   // Soft-Halt
}

/* --------------------------------------------------------------------
   Tick-System – globaler Zeitmesser
   Wird z.B. im SysTick-Interrupt inkrementiert.
   -------------------------------------------------------------------- */

volatile uint32_t system_ticks = 0;

uint32_t syscall_get_ticks(void)
{
    return system_ticks;
}
