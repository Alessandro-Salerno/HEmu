#include <inst.h>
#include <instinfo.h>
#include <stdint.h>
#include <string.h>

static const hemu_inst_info_t INSTRUCTIONS[HEMU_INST_NUM] = {
    { .operands = 0 },
    { .operands = 2, .opsizes = { 1, 2, 0 }, .optypes = { HEMU_REGISTER, HEMU_IMMEDIATE }, .repr = "mov" },
    { .operands = 2, .opsizes = { 1, 1, 0 }, .optypes = { HEMU_REGISTER, HEMU_REGISTER }, .repr = "mov" },
    { .operands = 2, .opsizes = { 1, 2, 0 }, .optypes = { HEMU_REGISTER, HEMU_MEMORY }, .repr = "mov" },
    { .operands = 2, .opsizes = { 2, 1, 0 }, .optypes = { HEMU_MEMORY, HEMU_REGISTER }, .repr = "mov" },
    { .operands = 2, .opsizes = { 1, 1, 0 }, .optypes = { HEMU_REGISTER, HEMU_REGISTER }, .repr = "add" },
    { .operands = 2, .opsizes = { 1, 1, 0 }, .optypes = { HEMU_REGISTER, HEMU_REGISTER }, .repr = "sub" },
    { .operands = 2, .opsizes = { 1, 1, 0 }, .optypes = { HEMU_REGISTER, HEMU_REGISTER }, .repr = "mlt" },
    { .operands = 2, .opsizes = { 1, 1, 0 }, .optypes = { HEMU_REGISTER, HEMU_REGISTER }, .repr = "div" },
    { .operands = 2, .opsizes = { 1, 1, 0 }, .optypes = { HEMU_REGISTER, HEMU_REGISTER }, .repr = "and" },
    { .operands = 2, .opsizes = { 1, 2, 0 }, .optypes = { HEMU_REGISTER, HEMU_IMMEDIATE }, .repr = "and" },
    { .operands = 2, .opsizes = { 1, 1, 0 }, .optypes = { HEMU_REGISTER, HEMU_REGISTER }, .repr = "or" },
    { .operands = 2, .opsizes = { 1, 2, 0 }, .optypes = { HEMU_REGISTER, HEMU_IMMEDIATE }, .repr = "or" },
    { .operands = 2, .opsizes = { 1, 1, 0 }, .optypes = { HEMU_REGISTER, HEMU_REGISTER }, .repr = "xor" },
    { .operands = 2, .opsizes = { 1, 2, 0 }, .optypes = { HEMU_REGISTER, HEMU_IMMEDIATE }, .repr = "xor" },
    { .operands = 1, .opsizes = { 1, 0, 0 }, .optypes = { HEMU_REGISTER }, .repr = "not" },
    { .operands = 2, .opsizes = { 1, 1, 0 }, .optypes = { HEMU_REGISTER, HEMU_REGISTER }, .repr = "shl" },
    { .operands = 2, .opsizes = { 1, 2, 0 }, .optypes = { HEMU_REGISTER, HEMU_IMMEDIATE }, .repr = "shl" },
    { .operands = 2, .opsizes = { 1, 1, 0 }, .optypes = { HEMU_REGISTER, HEMU_REGISTER }, .repr = "shr" },
    { .operands = 2, .opsizes = { 1, 2, 0 }, .optypes = { HEMU_REGISTER, HEMU_IMMEDIATE }, .repr = "shr" },
    { .operands = 1, .opsizes = { 2, 0, 0 }, .optypes = { HEMU_MEMORY }, .repr = "jmp" },
    { .operands = 1, .opsizes = { 2, 0, 0 }, .optypes = { HEMU_MEMORY }, .repr = "jc" },
    { .operands = 1, .opsizes = { 2, 0, 0 }, .optypes = { HEMU_MEMORY }, .repr = "jz" },
    { .operands = 1, .opsizes = { 2, 0, 0 }, .optypes = { HEMU_MEMORY }, .repr = "jnc" },
    { .operands = 1, .opsizes = { 2, 0, 0 }, .optypes = { HEMU_MEMORY }, .repr = "jnz" },
    { .operands = 2, .opsizes = { 1, 1, 0 }, .optypes = { HEMU_REGISTER, HEMU_REGISTER }, .repr = "cmp" },
    { .operands = 2, .opsizes = { 1, 2, 0 }, .optypes = { HEMU_REGISTER, HEMU_REGISTER }, .repr = "cmp" }
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
    strcpy(__info->repr, _original.repr);
    memcpy(__info->opsizes, _original.opsizes, sizeof _original.opsizes);
    memcpy(__info->optypes, _original.optypes, sizeof _original.optypes);

    return 0;
}
