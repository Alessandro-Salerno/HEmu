#ifndef COMMONS_HEMUBIN_H
#define COMMONS_HEMUBIN_H

#include <stdio.h>

#define MARK_SUCCESS 5
#define HEMU_BINARY 0


int hemu_mark_file(FILE *__outout);
int hemu_seek_executable(FILE *__file);

#endif // COMMONS_HEMUBIN_H
