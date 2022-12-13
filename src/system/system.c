#include <stdint.h>
#include <stdio.h>

#include "system.h"

r4300_t cpu;

void system_load_rom(uint8_t *rom_buf)
{
    rom_header_t *rom_header = (rom_header_t *) rom_buf;

    printf("%x\n", rom_header->pc);
}