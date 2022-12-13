#ifndef _md64_rom_h
#define _md64_rom_h

#include <stdint.h>

/*
typedef struct rom_info_t {
    char *image_name;
}
*/

typedef struct rom_header_t {
    uint8_t reserved[4];
    uint32_t cro;       /* Clock Rate Override */
    uint32_t pc;        /* Program Counter */
    uint32_t raddr;     /* Release Address */
    uint32_t crc1;
    uint32_t crc2;
    uint8_t reserved1[8];
    char image_name[20];
    uint8_t reserved2[4];
    uint8_t media_format[4];
    uint16_t cartridge_id;
    uint8_t country_code;
    uint8_t version;
} __attribute__((packed)) rom_header_t;

#endif