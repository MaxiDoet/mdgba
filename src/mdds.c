#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "device.h"

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("You need to specify a rom file!\n");
        exit(-1);
    }

    FILE *fp;
    
    uint32_t rom_size;
    uint8_t *rom_buf;
    fp = fopen(argv[1], "rb");
    fseek(fp, 0, SEEK_END);
    rom_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    rom_buf = (uint8_t *) malloc(rom_size);
    fread(rom_buf, rom_size, 1, fp);
    fclose(fp);

    /* Load ARM7 BIOS */
    uint8_t *bios7 = (uint8_t *) malloc(0x4000);
    fp = fopen("bios7.bin", "rb");
    fread(bios7, 0x4000, 1, fp);
    fclose(fp);

    /* Load ARM9 BIOS */
    uint8_t *bios9 = (uint8_t *) malloc(0x8000);
    fp = fopen("bios9.bin", "rb");
    fread(bios9, 0x9000, 1, fp);
    fclose(fp);

    device_load_bios(bios7, bios9);

    printf("Loaded %s (%d bytes)\n", argv[1], rom_size);

    device_init();
    device_load_rom(rom_buf);
    device_run();
}