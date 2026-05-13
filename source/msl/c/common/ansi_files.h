#pragma once

#include "stdio.h"

EXTERN_C_START

typedef size_t __file_handle;

#define __ungetc_buffer_size 2


enum __file_kinds {
    __closed_file      = 0,
    __disk_file        = 1,
    __console_file     = 2,
    __unavailable_file = 3,
};

enum __open_modes {
    __must_exist          = 0,
    __create_if_necessary = 1,
    __create_or_truncate  = 2,
};

enum __file_orientation {
    __unoriented    = 0,
    __char_oriented = 1,
    __wide_oriented = 2,
};

enum __io_modes {
    __read       = 1,
    __write      = 2,
    __read_write = 3,
    __append     = 4,
};

typedef struct _file_modes {
    unsigned open_mode        : 2;
    unsigned io_mode          : 3;
    unsigned buffer_mode      : 2;
    unsigned file_kind        : 3;
    unsigned file_orientation : 2;
    unsigned binary_io        : 1;
} file_modes;

enum __io_states {
    __neutral = 0,
    __writing = 1,
    __reading = 2,
    __rereading = 3,
};

enum __io_results {
    __no_io_error = 0,
    __io_error = 1,
    __io_EOF = 2,
};

typedef struct _file_states {
    unsigned int  io_state    : 3;
    unsigned int  free_buffer : 1;
    unsigned char eof;
    unsigned char error;
} file_states;

typedef void (*__idle_proc)(void);
typedef int (*__pos_proc)(__file_handle file, fpos_t* position, int mode, __idle_proc idle_proc);
typedef int (*__io_proc)(
    __file_handle file, unsigned char* buff, size_t* count, __idle_proc idle_proc
);
typedef int (*__close_proc)(__file_handle file);

struct _FILE {
    SIZE_ASSERT(0x50);

    /* 0x00 */ __file_handle  handle;
    /* 0x04 */ file_modes     file_mode;
    /* 0x08 */ file_states    file_state;
    /* 0x0C */ unsigned char  is_dynamically_allocated;
    /* 0x0D */ char           char_buffer;
    /* 0x0E */ char           char_buffer_overflow;
    /* 0x0F */ char           ungetc_buffer[__ungetc_buffer_size];
    /* 0x12 */ wchar_t        ungetc_wide_buffer[__ungetc_buffer_size];
    /* 0x18 */ unsigned long  position;
    /* 0x1C */ unsigned char* buffer;
    /* 0x20 */ unsigned long  buffer_size;
    /* 0x24 */ unsigned char* buffer_ptr;
    /* 0x28 */ unsigned long  buffer_length;
    /* 0x2C */ unsigned long  buffer_alignment;
    /* 0x30 */ unsigned long  save_buffer_length;
    /* 0x34 */ unsigned long  buffer_position;
    /* 0x38 */ __pos_proc     position_fn;
    /* 0x3C */ __io_proc      read_fn;
    /* 0x40 */ __io_proc      write_fn;
    /* 0x44 */ __close_proc   close_fn;
    /* 0x48 */ __idle_proc    idle_fn;
    /* 0x4C */ struct _FILE*  next_file;
};

struct _files {
    struct _FILE _stdin;
    struct _FILE _stdout;
    struct _FILE _stderr;
    struct _FILE empty;
};

extern struct _files __files;

_FILE* __find_unopened_file(void);

void __init_file(FILE* file, file_modes mode, unsigned char* buffer, size_t buffer_size);

EXTERN_C_END
