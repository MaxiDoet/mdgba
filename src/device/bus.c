#include <stdint.h>
#include <stdio.h>

#include "device.h"

uint32_t bus_arm9_read_word(uint32_t addr)
{
    uint32_t value = 0;

    /* BIOS */
    if (addr >= 0xFFFF0000 && addr <= 0xFFFF8000) {
        value = *((uint32_t *) &dev.bus.arm9_bios[addr - 0xFFFF0000]);
    }

    return value;
}

uint32_t bus_arm7_read_word(uint32_t addr)
{
    uint32_t value = 0;

    /* BIOS */
    if (addr >= 0 && addr <= 0x7FFF) {
        value = dev.bus.arm7_bios[addr];
    }

    return value;
}