#ifndef COMMON_INSTINFO_H
#define COMMON_INSTINFO_H

#include <stdint.h>
#include <inst.h>


typedef struct HEmuInstructionInformation {
    uint16_t size;
    uint16_t operands;
    uint16_t opsizes[3];
} hemu_inst_info_t;

#endif // COMMON_INSTINFO_H
