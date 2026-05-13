// misc_io.c
// NSMBW .text: 0x802DF798 - 0x802DF7A8

#include "ansi_files.h"
#include <stdio.h>

EXTERN_C_START

void clearerr(
    FILE* stream
) {
    stream->file_state.error = stream->file_state.eof = 0;
}

int feof(
    FILE* stream
) {
    return stream->file_state.eof;
}

int ferror(
    FILE* stream
) {
    return stream->file_state.error;
}

[[nsmbw(0x802DF798)]]
void __stdio_atexit(void);

EXTERN_C_END
