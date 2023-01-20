#include <stdio.h>
#include <stdint.h>
#include <hexc.h>


int hexc(FILE *__input, FILE *__output) {
    while (!feof(__input)) {
        uint32_t _raw = 0;
        fscanf(__input, "%x", &_raw);

        if (_raw > UINT8_MAX || _raw < 0) {
            printf("hexc: invalid value 0x%x found", _raw);
            return -1;
        }

        uint8_t _real = (uint8_t) _raw;
        fwrite(&_real, 1, 1, __output);
    }

    return 0;
}
