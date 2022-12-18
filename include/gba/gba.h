#ifndef _gba_h
#define _gba_h

#include <stdbool.h>

#include "rom.h"
#include "arm.h"
#include "bus.h"

typedef struct gba_config_t {
    uint8_t *bios;

    uint8_t *rom;
    uint32_t rom_size;
} gba_config_t;

typedef struct gba_t {
    arm_t cpu;
    bus_t bus;

    gba_config_t config;
} gba_t;

extern gba_t gba;

void gba_init(gba_config_t config);
void gba_run();

#endif