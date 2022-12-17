#include <stdint.h>
#include <stdio.h>

#include "device.h"

uint32_t bus_arm7_read_32(uint32_t addr)
{
    uint32_t value = 0;

    /* BIOS */
    if (addr >= 0 && addr <= 0x7FFF) {
        value = dev.bus.arm7_bios[addr];
    }

    return value;
}