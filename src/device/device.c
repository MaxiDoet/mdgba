#include <stdint.h>
#include <stdio.h>

#include "device.h"

void device_load_rom(uint8_t *rom_buf)
{
    rom_header_t *rom_header = (rom_header_t *) rom_buf;

    printf("%s\n", rom_header->game_title);
}