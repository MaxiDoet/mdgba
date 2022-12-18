#ifndef _gba_rom_h
#define _gba_rom_h

#include <stdint.h>

typedef struct rom_header_t {
    uint32_t entry_point;
    uint8_t nintendo_logo[156];
    char game_title[12];
    char game_code[4];
    char maker_code[4];
} __attribute__((packed)) rom_header_t;

#endif