#include <hemubin.h>
#include <stdio.h>
#include <string.h>

#define MAGIC_STRING "HEMU"
#define HEX_MAGIC 0xaaff


int hemu_mark_file(FILE *__outout) {
    int _res = fprintf(__outout, MAGIC_STRING);
    int _magic = HEX_MAGIC;
    _res += fwrite(&_magic, sizeof _magic, 1, __outout);
    return _res;
}

int hemu_seek_executable(FILE *__file) {
    char _magic_str[5];
    fgets(_magic_str, 5, __file);
    int _hex_magic;
    fread(&_hex_magic, 4, 1, __file);

    return !(strcmp(_magic_str, MAGIC_STRING) == 0
              && _hex_magic == HEX_MAGIC);
}
