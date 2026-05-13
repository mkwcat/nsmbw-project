// file_io.c
// NSMBW .text: 0x802DEC0C - 0x802DEDFC

#include "ansi_files.h"
#include "misc_io.h"
#include <stdio.h>
#include <stdlib.h>

EXTERN_C_START

[[nsmbw(0x802DEC0C)]]
int fclose(FILE* file);

[[nsmbw(0x802DECC8)]]
int fflush(FILE* file);

FILE* fopen(
    const char* restrict filename, const char* restrict mode
) {
    return freopen(filename, mode, __find_unopened_file());
}

int __open_file(const char* name, file_modes mode, __file_handle* handle);
int __get_file_modes(const char* mode, file_modes* modes);

FILE* freopen(
    const char* restrict filename, const char* restrict mode, FILE* restrict stream
) {
    file_modes modes;

    __stdio_atexit();

    if (!stream) {
        return nullptr;
    }

    fclose(stream);
    clearerr(stream);

    if (!__get_file_modes(mode, &modes)) {
        return NULL;
    }

    __init_file(stream, modes, 0, 0x400);

    if (__open_file(filename, modes, &stream->handle)) {
        stream->file_mode.file_kind = __closed_file;
        if (stream->file_state.free_buffer) {
            free(stream->buffer);
        }
        return NULL;
    }
    if (modes.io_mode & __append) {
        fseek(stream, 0, SEEK_END);
    }

    return stream;
}

int __get_file_modes(
    const char* mode, file_modes* modes
) {
    modes->file_kind        = __disk_file;
    modes->file_orientation = __unoriented;
    modes->binary_io        = 0;

    unsigned char open_mode;
    int           io_mode;
    switch (*mode++) {
    case 'r':
        open_mode = __must_exist;
        io_mode   = __read;
        break;

    case 'w':
        open_mode = __create_or_truncate;
        io_mode   = __write;
        break;

    case 'a':
        open_mode = __create_if_necessary;
        io_mode   = __write | __append;
        break;

    default:
        return 0;
    }

    modes->open_mode = open_mode;

    while (*mode != '\0') {
        switch (*mode++) {
        case 'b':
            if (modes->binary_io) {
                return 0;
            }
            modes->binary_io = 1;
            break;

        case '+':
            if ((io_mode & __read_write) == __read_write) {
                return 0;
            }
            io_mode |= __read_write;
            break;

        default:
            return 0;
        }
    }

    modes->io_mode = io_mode;
    return 1;
}

EXTERN_C_END
