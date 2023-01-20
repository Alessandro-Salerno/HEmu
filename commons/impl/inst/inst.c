#include <inst/inst.h>
#include <inst/instinfo.h>
#include <stdint.h>

static const hemu_inst_info_t INSTRUCTIONS[HEMU_INST_NUM] = {
    { .operands = 0 },
    { .operands = 2,      .opsizes = { 1, 2, 0 } },
    { .operands = 2,      .opsizes = { 1, 1, 0 } },
    { .operands = 2,      .opsizes = { 1, 2, 0 } },
    { .operands = 2,      .opsizes = { 2, 1, 0 } },
    { .operands = 2,      .opsizes = { 1, 1, 0 } },
    { .operands = 2,      .opsizes = { 1, 1, 0 } },
    { .operands = 2,      .opsizes = { 1, 1, 0 } },
    { .operands = 2,      .opsizes = { 1, 1, 0 } },
    { .operands = 2,      .opsizes = { 1, 1, 0 } },
    { .operands = 2,      .opsizes = { 1, 2, 0 } },
    { .operands = 2,      .opsizes = { 1, 1, 0 } },
    { .operands = 2,      .opsizes = { 1, 2, 0 } },
    { .operands = 2,      .opsizes = { 1, 1, 0 } },
    { .operands = 2,      .opsizes = { 1, 2, 0 } },
    { .operands = 1,      .opsizes = { 1, 0, 0 } },
    { .operands = 2,      .opsizes = { 1, 1, 0 } },
    { .operands = 2,      .opsizes = { 1, 2, 0 } },
    { .operands = 2,      .opsizes = { 1, 1, 0 } },
    { .operands = 2,      .opsizes = { 1, 2, 0 } },
    { .operands = 1,      .opsizes = { 2, 0, 0 } },
    { .operands = 1,      .opsizes = { 2, 0, 0 } },
    { .operands = 1,      .opsizes = { 2, 0, 0 } },
    { .operands = 1,      .opsizes = { 2, 0, 0 } },
    { .operands = 1,      .opsizes = { 2, 0, 0 } },
    { .operands = 2,      .opsizes = { 1, 1, 0 } },
    { .operands = 2,      .opsizes = { 1, 2, 0 } }
};


int hemu_inst_info(hemu_inst_t __opcode, hemu_inst_info_t *__info) {
    if (__opcode >= HEMU_INST_NUM || __opcode < 0) return -1;

    hemu_inst_info_t _original = INSTRUCTIONS[__opcode];

    if (_original.size == 0) {
        _original.size++;
        for (uint8_t _i = 0; _i < _original.operands; _i++)
            _original.size += _original.opsizes[_i];
    }

    __info->size = _original.size;
    __info->operands = _original.operands;
    
    for (uint8_t _i = 0; _i < _original.operands; _i++)
        __info->opsizes[_i] = _original.opsizes[_i];

    return 0;
}
