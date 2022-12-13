#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "system.h"

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("You need to specify a rom file!\n");
        exit(-1);
    }

    FILE *rom_fp;
    uint32_t rom_size;
    uint8_t *rom_buf;

    rom_fp = fopen(argv[1], "rb");

    fseek(rom_fp, 0, SEEK_END);
    rom_size = ftell(rom_fp);
    fseek(rom_fp, 0, SEEK_SET);

    rom_buf = (uint8_t *) malloc(rom_size);
    fread(rom_buf, rom_size, 1, rom_fp);

    fclose(rom_fp);

    printf("Loaded %s (%d bytes)\n", argv[1], rom_size);

    system_load_rom(rom_buf);
}