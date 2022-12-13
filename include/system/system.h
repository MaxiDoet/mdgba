#ifndef _md64_system_h
#define _md64_system_h

#include "rom.h"
#include "r4300.h"

extern r4300_t cpu;

void system_load_rom(uint8_t *rom_buf);

#endif