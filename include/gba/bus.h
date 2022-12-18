#ifndef _gba_bus_h
#define _gba_bus_h

typedef struct bus_t {
    uint8_t bios[0x4000];
    uint8_t rom[0x2000000];
} bus_t;

uint32_t bus_read_word(uint32_t addr);

#endif