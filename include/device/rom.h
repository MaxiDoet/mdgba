#ifndef _mdds_rom_h
#define _mdds_rom_h

#include <stdint.h>

typedef struct rom_header_t {
    char game_title[12];
    uint32_t game_code;
    uint16_t maker_code;
    uint8_t unit_code;
    uint8_t encryption_seed_select;
    uint8_t capacity;
    uint8_t reserved[8];
    uint8_t nds_region;
    uint8_t rom_version;
    uint8_t autostart;
    uint32_t arm9_rom_offset;
    uint32_t arm9_entry_address;
    uint32_t arm9_ram_address;
    uint32_t arm9_size;
    uint32_t arm7_rom_offset;
    uint32_t arm7_entry_address;
    uint32_t arm7_ram_address;
    uint32_t arm7_size;
    uint32_t fnt_offset;
    uint32_t fnt_size;
    uint32_t fat_offset;
    uint32_t fat_size;
} __attribute__((packed)) rom_header_t;


#endif