    .section .vectors, "ax"
    .global _start

_start:
    b reset

    .section .text, "ax"
    .global reset
reset:
    bl app_main
hang:
    b hang
