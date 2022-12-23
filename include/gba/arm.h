#ifndef _gba_arm_h
#define _gba_arm_h

#define ARM_REG_BANK_SYSTEM 1
#define ARM_REG_BANK_FIQ    2
#define ARM_REG_BANK_SVC    3
#define ARM_REG_BANK_ABT    4
#define ARM_REG_BANK_IRQ    5
#define ARM_REG_BANK_UND    6

typedef struct arm_psr_t {
    uint32_t value;

    union {
        uint8_t mode            : 5;
        uint8_t state           : 1;
        uint8_t fiq_disable     : 1;
        uint8_t irq_disable     : 1;
        uint8_t abort_disable   : 1;
        uint8_t endian          : 1;
        uint32_t reserved       : 17;
        uint8_t sticky_overflow : 1;
        uint8_t overflow        : 1;
        uint8_t carry           : 1;
        uint8_t zero            : 1;
        uint8_t sign            : 1;
    };
} __attribute__((packed)) arm_psr_t;

typedef struct arm_t {
    uint32_t regs[16];
    uint32_t regs_fiq[16];
    uint32_t regs_svc[16];
    uint32_t regs_abt[16];
    uint32_t regs_irq[16];
    uint32_t regs_und[16];

    arm_psr_t cpsr;

    arm_psr_t spsr;
    arm_psr_t spsr_fiq;
    arm_psr_t spsr_svc;
    arm_psr_t spsr_abt;
    arm_psr_t spsr_irq;
    arm_psr_t spsr_und;

    bool running;
    uint32_t cycles;
} arm_t;

void arm_step();

#endif