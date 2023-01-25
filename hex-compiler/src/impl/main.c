#include <stdio.h>
#include <hexc.h>


int main(int argc, char const *argv[]) {
    if (argc != 3) {
        printf("hexc: insufficient arguments");
        return -1;
    }

    FILE *_file_to_compile = fopen(argv[1], "r");
    
    if (_file_to_compile == NULL) {
        printf("hexc: no such file \"%s\"", argv[1]);
        return -2;
    }
    
    FILE *_output_file = fopen(argv[2], "w");

    if (hexc(_file_to_compile, _output_file) != 0) {
        printf("\nhexc: compilation aborted");
        return -3;
    }

    return 0;
}
