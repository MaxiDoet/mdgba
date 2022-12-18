#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "gba.h"

gba_t gba;

void gba_init(gba_config_t config)
{
    gba.config = config;

    memcpy(gba.bus.bios, config.bios, 0x4000);
    printf("Loaded GBA BIOS\n");

    memcpy(gba.bus.rom, gba.config.rom, gba.config.rom_size);
    //dev.arm7.pc = 0x00000000; // Reset vector
    
    gba.cpu.pc = 0x08000000;
}

void gba_run()
{
    while(true) {
        arm_step();
    }
}