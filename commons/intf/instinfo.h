#ifndef COMMON_INSTINFO_H
#define COMMON_INSTINFO_H

#include <stdint.h>
#include <inst.h>


typedef enum {
    HEMU_IMMEDIATE,
    HEMU_REGISTER,
    HEMU_MEMORY
} hemu_operand_type_t;

typedef struct HEmuInstructionInformation {
    uint16_t size;
    uint16_t operands;
    uint16_t opsizes[3];
    hemu_operand_type_t optypes[3];
    char repr[3];
} hemu_inst_info_t;

#endif // COMMON_INSTINFO_H
