#ifndef _mdds_device_h
#define _mdds_device_h

#include "rom.h"
#include "arm.h"

void device_load_rom(uint8_t *rom_buf);
void device_run();

#endif