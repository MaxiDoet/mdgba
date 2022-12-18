#ifndef _gba_arm_h
#define _gba_arm_h

typedef struct arm_psr_t {
    uint32_t value;

    union {
        uint8_t mode            : 5;
        uint8_t state           : 1;
        uint8_t fiq_disable     : 1;
        uint8_t irq_disable     : 1;
        uint8_t abort_disable   : 1;
        uint8_t endian          : 1;
        uint32_t reserved      : 17;
        uint8_t sticky_overflow : 1;
        uint8_t overflow        : 1;
        uint8_t carry           : 1;
        uint8_t zero            : 1;
        uint8_t sign            : 1;
    };
} __attribute__((packed)) arm_psr_t;

typedef struct arm_t {
    uint32_t gpr[13];

    uint32_t sp;
    uint32_t lr;
    uint32_t pc;
    
    arm_psr_t cpsr;
    arm_psr_t spsr;

    bool enabled;
    uint32_t cycles;
} arm_t;

void arm_step();

#endif