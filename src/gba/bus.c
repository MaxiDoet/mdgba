#include <stdint.h>
#include <stdio.h>

#include "gba.h"

uint32_t bus_io_read_word(uint32_t addr){
    uint32_t result = 0;

    if (!(addr >= 0x04000000 && addr <= 0x040003FE)) {
        result = 0;
    }
}

uint32_t bus_read_word(uint32_t addr)
{
    uint32_t value = 0;

    if (addr >= 0x00000000 && addr <= 0x00004000) {
        /* BIOS */
        value = *((uint32_t *) &gba.bus.bios[addr]);
    } else if (addr >= 0x04000000 && addr <= 0x040003FE) {
        /* IO */
        value = bus_io_read_word(addr);
    } else if (addr >= 0x08000000 && addr <= 0x09FFFFFF) {
        /* Rom */
        value = *((uint32_t *) &gba.bus.rom[addr - 0x08000000]);
    }
    
    return value;
}