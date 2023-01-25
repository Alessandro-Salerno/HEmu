#include <stdio.h>
#include <hexvsl.h>
#include <stdint.h>
#include <stdlib.h>
#include <inst.h>
#include <instinfo.h>


int hexvsl(FILE *__file) {
    uint32_t _line = 1;
    hemu_inst_t _opcode = 0;
    
    while (fread(&_opcode, 1, 1, __file) == 1) {
        hemu_inst_info_t _inst;
        if (hemu_inst_info(_opcode, &_inst) != 0) {
            printf("hexvsl: invalid opcode %x found", _opcode);
            return -1;
        }

        void *_inst_buf = malloc(_inst.size - 1);
        size_t _read = 0;
        size_t _byte_idx = 0;
        
        if ((_read = fread(_inst_buf, 1, _inst.size - 1, __file)) != _inst.size - 1) {
            printf("hexvsl: invalid number of bytes (%lu) read for instruction of size %d", _read + 1, _inst.size);
            return -2;
        }

        printf("%d | (%d bytes, %d operands) -- 0x%x ", _line, _inst.size, _inst.operands, _opcode);
        for (size_t _i = 0; _i < _inst.operands; _i++) {
            uint16_t _value = (_inst.opsizes[_i] == 2) ? *(uint16_t *) (_inst_buf + _byte_idx)
                                                       : *(uint8_t *) (_inst_buf + _byte_idx);
            
            printf("0x%x ", _value);
            _byte_idx += _inst.opsizes[_i];
        }
        
        printf("\n");
        free(_inst_buf);
        _line++;
    }

    return 0;
}
