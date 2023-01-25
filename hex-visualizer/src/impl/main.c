#include <stdio.h>
#include <hexvsl.h>
#include <hemubin.h>


int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("hexvsl: insufficient arguments");
        return -1;
    }

    FILE *_bin = fopen(argv[1], "r");

    if (hemu_seek_executable(_bin) != HEMU_BINARY) {
        printf("hexvsl: file \"%s\" is not a HEmu executable binary", argv[1]);
        return -2;
    }

    if (hexvsl(_bin) != 0) {
        printf("\nhexvsl: aborting...");
        return -3;
    }

    return 0;
}
