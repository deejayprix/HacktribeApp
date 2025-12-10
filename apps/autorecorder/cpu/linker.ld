ENTRY(_start)

MEMORY
{
    rom (rx)  : ORIGIN = 0x80000000, LENGTH = 256K
    ram (rwx) : ORIGIN = 0x20000000, LENGTH = 64K
}

SECTIONS
{
    /* ---------------------------------------------------------
       CODE & READ-ONLY DATA
       --------------------------------------------------------- */
    .text : ALIGN(4)
    {
        KEEP(*(.vectors))      /* Startup / Interrupt Table */
        *(.text*)
        *(.rodata*)
    } > rom

    /* ---------------------------------------------------------
       INITIALIZED DATA (RAM, load from ROM)
       --------------------------------------------------------- */
    .data : ALIGN(4)
    {
        _data_start = .;
        *(.data*)
        _data_end = .;
    } > ram AT > rom

    /* Load address of .data in ROM */
    _data_load = LOADADDR(.data);

    /* ---------------------------------------------------------
       BSS SECTION (zeroed RAM)
       --------------------------------------------------------- */
    .bss : ALIGN(4)
    {
        _bss_start = .;
        *(.bss*)
        *(COMMON)
        _bss_end = .;
    } > ram

    /* ---------------------------------------------------------
       HEAP STARTS HERE
       newlib benötigt _end für _sbrk()
       --------------------------------------------------------- */
    _end = _bss_end;

    /* ---------------------------------------------------------
       STACK SECTION (at the top of RAM)
       ARM requires a defined stack symbol
       --------------------------------------------------------- */
    .stack (NOLOAD) :
    {
        . = ALIGN(8);
        _stack_start = .;
        . = ORIGIN(ram) + LENGTH(ram);
        _stack_end = .;
    } > ram

    /* Startup-Code uses this as initial SP */
    _estack = ORIGIN(ram) + LENGTH(ram);
}
