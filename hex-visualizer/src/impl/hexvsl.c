#include <stdio.h>
#include <hexvsl.h>
#include <stdint.h>
#include <stdlib.h>
#include <inst.h>
#include <instinfo.h>


int hexvsl(FILE *__file) {
    hemu_inst_t _opcode = 0;
    while (fread(&_opcode, 1, 1, __file) == 1) {
        hemu_inst_info_t _inst;
        if (hemu_inst_info(_opcode, &_inst) != 0) {
            printf("hexvsl: invalid opcode %x found", _opcode);
            return -1;
        }

        uint8_t *_inst_buf = malloc(_inst.size - 1);
        size_t _read = 0;
        
        if ((_read = fread(_inst_buf, 1, _inst.size - 1, __file)) != _inst.size - 1) {
            printf("hexvsl: invalid number of bytes (%lu) read for instruction of size %d", _read + 1, _inst.size);
            return -2;
        }
        
        printf("0x%x ", _opcode);
        for (uint8_t _i; _i < _inst.size - 1; _i++)
            printf("0x%x ", _inst_buf[_i]);
        printf("\n");
    }

    return 0;
}
