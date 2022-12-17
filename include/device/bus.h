#ifndef _mdds_bus_h
#define _mdds_bus_h

typedef struct bus_t {
    /* Shared between both CPUs */
    uint8_t wram_shared[0x8000];
    uint8_t ram_shared[0x40000];

    /* ARM7 only */
    uint8_t arm7_bios[0x4000];
    uint8_t arm7_ram[0x40000];
    uint8_t arm7_wram[0x10000];

    /* ARM9 only */
    uint8_t arm9_instruction_tcm[0x8000];
    uint8_t arm9_data_tcm[0x4000];
    uint8_t arm9_bios[0x8000];
} bus_t;

uint32_t bus_arm9_read_word(uint32_t addr);
uint32_t bus_arm7_read_word(uint32_t addr);

#endif