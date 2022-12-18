#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "gba.h"

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("You need to specify a rom file!\n");
        exit(-1);
    }
    
    uint32_t rom_size;
    uint8_t *rom_buf;
    FILE *fp = fopen(argv[1], "rb");
    fseek(fp, 0, SEEK_END);
    rom_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    rom_buf = (uint8_t *) malloc(rom_size);
    fread(rom_buf, rom_size, 1, fp);
    fclose(fp);

    uint8_t *bios = (uint8_t *) malloc(0x4000);
    fp = fopen("bios.bin", "rb");
    fread(bios, 0x4000, 1, fp);
    fclose(fp);

    gba_config_t config;

    config.bios = bios;
    config.rom = rom_buf;
    config.rom_size = rom_size;

    gba_init(config);
    gba_run();
}