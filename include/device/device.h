#ifndef _mdds_device_h
#define _mdds_device_h

#include "rom.h"
#include "arm.h"
#include "bus.h"

typedef struct device_t {
    arm_t arm9;
    arm_t arm7;
    bus_t bus;
} device_t;

extern device_t dev;

void device_load_rom(uint8_t *rom_buf);
void device_load_bios(uint8_t *bios7, uint8_t *bios9);
void device_init();
void device_run();

#endif