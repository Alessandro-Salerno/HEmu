#ifndef COMMON_INST_H
#define COMMON_INST_H

#include <stdint.h>
#include <inst/instinfo.h>


typedef enum {
    HEMU_HLT,                   // Halt. Base for HEmu instructions
    HEMU_MOV_REG_IMM,           // Move immediate value into register
    HEMU_MOV_REG_REG,           // Move right register value into left register value
    HEMU_MOV_REG_MEM,           // Move value at memory address into register
    HEMU_MOV_MEM_REG,           // Move value in register to memory location
    HEMU_ADD_REG_REG,           // Add right register value to left register value (Save in left)
    HEMU_SUB_REG_REG,           // Subtract right register value from left register value (Save in left)
    HEMU_MLT_REG_REG,           // Multiply right register value and left register value (Save in left)
    HEMU_DIV_REG_REG,           // Divide left register value by right register value (Save in left)
    HEMU_AND_REG_REG,           // Bitwise and between left register value and right register value (Save in left)
    HEMU_AND_REG_IMM,           // Bitwise and between a register's value and an immediate value (Save in register)
    HEMU_OR_REG_REG,            // Bitwise or between left register value and right register value (Save in left)
    HEMU_OR_REG_IMM,            // Bitwise or between a register's value and an immediate value (Save in register)
    HEMU_XOR_REG_REG,           // Bitwise xor between left register value and right register value (Save in left)
    HEMU_XOR_REG_IMM,           // Bitwise xor between a register's value and an immediate value (Save in register)
    HEMU_NOT_REG,               // Bitwise not of a register (Overides register value)
    HEUM_SHL_REG_REG,           // Shifts the left register's value to the left by the number of bits in the right register
    HEMU_SHL_REG_IMM,           // Shifts the register's value to the left by an arbitrary number of bits
    HEMU_SHR_REG_REG,           // Shifts the left register's value to the right by the number of bits in the right register
    HEMU_SHR_REG_IMM,           // Shifts the register's value to the right by an arbitrary number of bits
    HEMU_JMP_IMM,               // Jumps to a memory address
    HEMU_JC_IMM,                // Jumps to a memory address if the carry flag is true
    HEMU_JZ_IMM,                // Jumps to a memory address if the zero flag is true
    HEMU_JNC_IMM,               // Jumps to a memory address if the carry flag is false
    HEMU_JNZ_IMM,               // Jumps to a memory address if the zero flag is false
    HEMU_CMP_REG_REG,           // Updates zero and carry flags using two registers
    HEMU_CMP_REG_IMM,           // Updates zero and carry flags using a register and an immediate value
    HEMU_INST_END               // End of HEmu instructions
} hemu_inst_t;

#define HEMU_INST_NUM (uint16_t) HEMU_INST_END
#define HEMU_INST_MAX_OPS 3

int hemu_inst_info(hemu_inst_t __opcode, hemu_inst_info_t *__info);

#endif // COMMON_INST_H
