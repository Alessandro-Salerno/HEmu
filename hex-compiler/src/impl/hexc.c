#include <stdio.h>
#include <stdint.h>
#include <hexc.h>
#include <hemubin.h>


int hexc(FILE *__input, FILE *__output) {
    if (hemu_mark_file(__output) != MARK_SUCCESS) {
        printf("hexc: failed to mark binary file");
        return -3;
    }
    
    uint32_t _raw = 0;
    while (fscanf(__input, "%x", &_raw) == 1) {
        uint8_t _sz = (_raw > UINT8_MAX) ? 2 : 1;

        if (_raw > UINT16_MAX || _raw < 0) {
            printf("hexc: invalid value 0x%x found", _raw);
            return -1;
        }

        if (fwrite(&_raw, _sz, 1, __output) != 1) {
            printf("hexc: failed to write to output file");
            return -2;
        }
    }

    return 0;
}
