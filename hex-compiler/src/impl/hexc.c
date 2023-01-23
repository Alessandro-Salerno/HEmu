#include <stdio.h>
#include <stdint.h>
#include <hexc.h>


int hexc(FILE *__input, FILE *__output) {
    while (!feof(__input)) {
        uint32_t _raw = 0;
        fscanf(__input, "%x", &_raw);
        uint8_t _sz = (_raw > UINT8_MAX) ? 2 : 1;

        if (_raw > UINT16_MAX || _raw < 0) {
            printf("hexc: invalid value 0x%x found", _raw);
            return -1;
        }

        fwrite(&_raw, _sz, 1, __output);
    }

    return 0;
}
