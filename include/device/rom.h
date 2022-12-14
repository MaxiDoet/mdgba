#ifndef _mdds_rom_h
#define _mdds_rom_h

#include <stdint.h>

typedef struct rom_header_t {
    char game_title[12];
    uint32_t game_code;
    uint16_t maker_code;
    uint8_t unit_code;
} __attribute__((packed)) rom_header_t;


#endif