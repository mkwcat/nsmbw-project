#pragma once

#include "stdarg.h"
#include "stddef.h"

EXTERN_C_START

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

typedef unsigned long __file_handle;
typedef unsigned long fpos_t;

#define set_error(file)                                                                            \
    do {                                                                                           \
        (file)->file_state.error = 1;                                                              \
        (file)->buffer_length = 0;                                                                 \
    } while (0)

enum __file_kinds {
    __closed_file,
    __disk_file,
    __console_file,
    __unavailable_file,
};

enum __file_orientation {
    /* 0x0 */ UNORIENTED,
    /* 0x1 */ CHAR_ORIENTED,
    /* 0x2 */ WIDE_ORIENTED,
};

typedef struct _file_modes {
    unsigned int open_mode : 2;
    unsigned int io_mode : 3;
    unsigned int buffer_mode : 2;
    unsigned int file_kind : 3;
    unsigned int file_orientation : 2;
    unsigned int binary_io : 1;
} file_modes;

enum __io_modes {
    __read = 1,
    __write = 2,
    __read_write = 3,
    __append = 4,
};

enum __io_states {
    __neutral,
    __writing,
    __reading,
    __rereading,
};

enum __io_results {
    __no_io_error,
    __io_error,
    __io_EOF,
};

typedef struct _file_states {
    unsigned int io_state : 3;
    unsigned int free_buffer : 1;
    unsigned char eof;
    unsigned char error;
} file_states;

typedef void (*__idle_proc)(void);
typedef int (*__pos_proc)(__file_handle file, fpos_t* position, int mode, __idle_proc idle_proc);
typedef int (*__io_proc)(
  __file_handle file, unsigned char* buff, size_t* count, __idle_proc idle_proc
);
typedef int (*__close_proc)(__file_handle file);

typedef struct _FILE {
    SIZE_ASSERT(0x50);

    /* 0x00 */ __file_handle handle;
    /* 0x04 */ file_modes file_mode;
    /* 0x08 */ file_states file_state;
    /* 0x0C */ unsigned char is_dynamically_allocated;
    /* 0x0D */ char char_buffer;
    /* 0x0E */ char char_buffer_overflow;
    /* 0x0F */ char ungetc_buffer[2];
    /* 0x12 */ wchar_t ungetc_wide_buffer[2];
    /* 0x18 */ unsigned long position;
    /* 0x1C */ unsigned char* buffer;
    /* 0x20 */ unsigned long buffer_size;
    /* 0x24 */ unsigned char* buffer_ptr;
    /* 0x28 */ unsigned long buffer_length;
    /* 0x2C */ unsigned long buffer_alignment;
    /* 0x30 */ unsigned long save_buffer_length;
    /* 0x34 */ unsigned long buffer_position;
    /* 0x38 */ __pos_proc position_fn;
    /* 0x3C */ __io_proc read_fn;
    /* 0x40 */ __io_proc write_fn;
    /* 0x44 */ __close_proc close_fn;
    /* 0x48 */ __idle_proc idle_fn;
    /* 0x4C */ struct _FILE* next_file;
} FILE;

typedef struct _files {
    FILE _stdin;
    FILE _stdout;
    FILE _stderr;
    FILE empty;
} files;

#define _IONBF 0
#define _IOLBF 1
#define _IOFBF 2

/* 0x802DECC8 */
int fflush(FILE* file);

[[gnu::format(printf, 2, 3)]]
int fprintf(FILE* __restrict file, const char* __restrict format, ...);

/* 0x802E1850 */
[[gnu::format(printf, 1, 2)]]
int vprintf(const char* __restrict format, va_list ap);

/* 0x802E18CC */
[[gnu::format(printf, 3, 4)]]
int vsnprintf(char* __restrict s, size_t n, const char* __restrict format, va_list ap);

/* 0x802E1954 */
[[gnu::format(printf, 2, 3)]]
int vsprintf(char* __restrict s, const char* __restrict format, va_list ap);

/* 0x802E19D8 */
[[gnu::format(printf, 3, 4)]]
int snprintf(char* __restrict s, size_t n, const char* __restrict format, ...);

/* 0x802E1ACC */
[[gnu::format(printf, 2, 3)]]
int sprintf(char* __restrict s, const char* __restrict format, ...);

//
EXTERN_C_END
