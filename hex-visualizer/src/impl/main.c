#include <stdio.h>
#include <hexvsl.h>


int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("hexvsl: insufficient arguments");
        return -1;
    }

    FILE *_bin = fopen(argv[1], "r");

    if (hexvsl(_bin) != 0) {
        printf("\nhexvsl: aborting...");
        return -1;
    }

    return 0;
}
