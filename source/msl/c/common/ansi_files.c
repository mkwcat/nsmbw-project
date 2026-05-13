// ansi_files.c
// NSMBW .data: 0x80350D58 - 0x80350E98

#include "ansi_files.h"

#include <stdlib.h>
#include <string.h>

EXTERN_C_START

[[nsmbw(0x80350D58)]]
_files __files;

// Original symbol is "__files" at 0x80350D58, however we break this into multiple symbols for
// simpler access

[[nsmbw(0x80350D58)]]
_FILE __stdin;

[[nsmbw(0x80350DA8)]]
_FILE __stdout;

[[nsmbw(0x80350DF8)]]
_FILE __stderr;

FILE* __find_unopened_file(
    void
) {
    FILE* file = stderr;
    while (file->next_file != nullptr) {
        if (file = file->next_file; file->file_mode.file_kind == __closed_file) {
            return file;
        }
    }

    FILE* new_file = new FILE;
    if (new_file == nullptr) {
        return nullptr;
    }

    memset(new_file, 0, sizeof(FILE));
    new_file->is_dynamically_allocated = 1;
    file->next_file                    = new_file;
    return new_file;
}

int __position_file(__file_handle file, fpos_t* position, int mode, __idle_proc idle_proc);
int __read_file(__file_handle file, unsigned char* buffer, size_t* count, __idle_proc idle_fn);
int __write_file(__file_handle file, unsigned char* buffer, size_t* count, __idle_proc idle_fn);
int __close_file(__file_handle file);

void __init_file(
    FILE* file, file_modes mode, unsigned char* buffer, size_t buffer_size
) {
    file->handle                 = 0;
    file->file_mode              = mode;

    file->file_state.io_state    = __neutral;
    file->file_state.free_buffer = 0;
    file->file_state.eof         = 0;
    file->file_state.error       = 0;

    file->position               = 0;

    if (buffer_size != 0) {
        setvbuf(file, (char*) buffer, _IOFBF, buffer_size);
    } else {
        setvbuf(file, nullptr, _IONBF, 0);
    }

    file->buffer_ptr    = file->buffer;
    file->buffer_length = 0;

    if (file->file_mode.file_kind == __disk_file) {
        file->position_fn = __position_file;
        file->read_fn     = __read_file;
        file->write_fn    = __write_file;
        file->close_fn    = __close_file;
    }

    file->idle_fn = nullptr;
}

EXTERN_C_END
