#include <stdint.h>
#include <stdio.h>

#include "system.h"

void system_load_rom(uint8_t *rom_buf)
{
    rom_header_t *rom_header = (rom_header_t *) rom_buf;

    printf("%x\n", rom_header->pc);
}