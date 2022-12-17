#include <stdint.h>
#include <stdio.h>

#include "device.h"

void device_load_rom(uint8_t *rom_buf)
{
    rom_header_t *rom_header = (rom_header_t *) rom_buf;

    printf("%d\n", rom_header->unit_code);
}

void device_run()
{
    
}