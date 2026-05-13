// buffer_io.c
// NSMBW .text: 0x802DE824 - 0x802DE904

#include "ansi_files.h"
#include <stdio.h>
#include <stdlib.h>

EXTERN_C_START

int setvbuf(
    FILE* file, char* buffer, int mode, size_t size
) {
    unsigned char* file_bytes = (unsigned char*) file;
    unsigned short mode_bits  = *(unsigned short*) (file_bytes + 4);
    int            io_mode    = (mode_bits >> 6) & 7;

    if (mode == _IONBF) {
        fflush(file);
    }

    if (file->file_state.io_state != __neutral || io_mode == 0) {
        return -1;
    }

    if (mode != _IONBF && mode != _IOLBF && mode != _IOFBF) {
        return -1;
    }

    if (file->buffer != NULL && file->file_state.free_buffer != 0) {
        free(file->buffer);
    }

    file->file_mode.buffer_mode  = mode;
    file->file_state.free_buffer = 0;
    file->buffer                 = (unsigned char*) &file->char_buffer;
    file->buffer_ptr             = (unsigned char*) &file->char_buffer;
    file->buffer_size            = 1;
    file->buffer_length          = 0;
    file->buffer_alignment       = 0;

    if (mode == _IONBF || size < 1) {
        *file->buffer_ptr = 0;
        return 0;
    }

    if (buffer == NULL) {
        buffer = (char*) malloc(size);
        if (buffer == nullptr) {
            return -1;
        }
        file->file_state.free_buffer = 1;
    }

    file->buffer           = (unsigned char*) buffer;
    file->buffer_ptr       = file->buffer;
    file->buffer_size      = size;
    file->buffer_alignment = 0;

    return 0;
}

EXTERN_C_END
