#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "device.h"

device_t dev;

void device_load_rom(uint8_t *rom_buf)
{
    rom_header_t *rom_header = (rom_header_t *) rom_buf;

    printf("%d\n", rom_header->unit_code);
}

void device_load_bios(uint8_t *bios7, uint8_t *bios9)
{
    memcpy(dev.bus.arm7_bios, bios7, 0x4000);
    memcpy(dev.bus.arm9_bios, bios9, 0x8000);

    printf("Loaded ARM7/ARM9 BIOS\n");
}

void device_init()
{
    /* Init CPU(s) */
    dev.arm9.type = ARM_TYPE_9;
    dev.arm9.pc = 0xFFFF0000; // Reset vector

    dev.arm7.type = ARM_TYPE_7;
    dev.arm7.pc = 0x00000000; // Reset vector
}

void device_run()
{
    
}