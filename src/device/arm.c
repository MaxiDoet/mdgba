#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "device.h"

void arm_step(arm_t *cpu)
{
    uint32_t opcode = 0;

    if (cpu->type == ARM_TYPE_9) {
        opcode = bus_arm9_read_word(cpu->pc);
    } else {
        opcode = bus_arm7_read_word(cpu->pc);
    }

    /* Decode condition */
    uint8_t condition_code = (opcode & 0xFF000000) >> 28;
    bool condition = false;

    switch(condition_code) {
        case 0x00: condition = (cpu->cpsr.zero == true); break;
        case 0x01: condition = (cpu->cpsr.zero != true); break;
        case 0x02: condition = (cpu->cpsr.carry == true); break;
        case 0x03: condition = (cpu->cpsr.carry != true); break;
        case 0x04: condition = (cpu->cpsr.sign == true); break;
        case 0x05: condition = (cpu->cpsr.sign != true); break;
        case 0x06: condition = (cpu->cpsr.overflow == true); break;
        case 0x07: condition = (cpu->cpsr.overflow != true); break;
        case 0x08: condition = (cpu->cpsr.carry == true && cpu->cpsr.zero != true); break;
        case 0x09: condition = (cpu->cpsr.carry != true && cpu->cpsr.zero == true); break;
        case 0x0A: condition = (cpu->cpsr.sign == cpu->cpsr.overflow); break;
        case 0x0B: condition = (cpu->cpsr.sign < cpu->cpsr.overflow || cpu->cpsr.sign > cpu->cpsr.overflow); break;
        case 0x0C: condition = (cpu->cpsr.zero != true && cpu->cpsr.sign == cpu->cpsr.overflow); break;
        case 0x0D: condition = (cpu->cpsr.zero == true && cpu->cpsr.sign < cpu->cpsr.overflow || cpu->cpsr.sign > cpu->cpsr.overflow); break;
        case 0x0E: condition = true;
        case 0x0F: condition = false;
    }

    printf("PC: %x | %x Condition: %x\n", cpu->pc, opcode, condition);

    cpu->pc += 4;
}