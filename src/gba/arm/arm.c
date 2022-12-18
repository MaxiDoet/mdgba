#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "gba.h"

uint8_t arm_instruction_branch(uint32_t opcode)
{
    uint32_t branch_offset = (opcode & 0x7FFFFF) * 4 + 4;

    printf("Branch: %x\n", branch_offset);

    gba.cpu.pc += branch_offset;
}

uint8_t arm_instruction_alu(uint32_t opcode)
{
    uint8_t alu_opcode = (opcode & 0xF00000) >> 20;

    printf("ALU Opcode: %x\n", alu_opcode);
}

void arm_step()
{
    uint32_t opcode = bus_read_word(gba.cpu.pc);

    /* Decode condition */
    uint8_t condition_code = (opcode & 0xFF000000) >> 28;
    bool condition = false;

    switch(condition_code) {
        case 0x00: condition = (gba.cpu.cpsr.zero == true); break;
        case 0x01: condition = (gba.cpu.cpsr.zero != true); break;
        case 0x02: condition = (gba.cpu.cpsr.carry == true); break;
        case 0x03: condition = (gba.cpu.cpsr.carry != true); break;
        case 0x04: condition = (gba.cpu.cpsr.sign == true); break;
        case 0x05: condition = (gba.cpu.cpsr.sign != true); break;
        case 0x06: condition = (gba.cpu.cpsr.overflow == true); break;
        case 0x07: condition = (gba.cpu.cpsr.overflow != true); break;
        case 0x08: condition = (gba.cpu.cpsr.carry == true && gba.cpu.cpsr.zero != true); break;
        case 0x09: condition = (gba.cpu.cpsr.carry != true && gba.cpu.cpsr.zero == true); break;
        case 0x0A: condition = (gba.cpu.cpsr.sign == gba.cpu.cpsr.overflow); break;
        case 0x0B: condition = (gba.cpu.cpsr.sign < gba.cpu.cpsr.overflow || gba.cpu.cpsr.sign > gba.cpu.cpsr.overflow); break;
        case 0x0C: condition = (gba.cpu.cpsr.zero != true && gba.cpu.cpsr.sign == gba.cpu.cpsr.overflow); break;
        case 0x0D: condition = (gba.cpu.cpsr.zero == true && gba.cpu.cpsr.sign < gba.cpu.cpsr.overflow || gba.cpu.cpsr.sign > gba.cpu.cpsr.overflow); break;
        case 0x0E: condition = true; break;
        case 0x0F: condition = false; break;
    }

    printf("CPSR: %08x SPSR: %08x PC: %08x (PC): %08x | %c |\n", gba.cpu.cpsr.value, gba.cpu.spsr.value, gba.cpu.pc, opcode, condition ? '*' : ' ');

    gba.cpu.pc += 4;

    if (!condition) {
        return;
    }

    if (((opcode & 0xE000000) >> 25) == 0x05) {
        // Branch
        arm_instruction_branch(opcode);
    } else if (opcode & ~(1 << 26) && opcode & ~(1 << 27)) {
        // ALU instruction
        arm_instruction_alu(opcode);
    }
}