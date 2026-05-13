// mslsupp.c
// NSMBW .text: 0x802EC304 - 0x802EC490

#include <msl/c/common/ansi_files.h>

EXTERN_C_START

int __position_file(
    __file_handle file, fpos_t* position, int mode, __idle_proc idle_proc
) {
    return 0;
}

int __close_file(
    __file_handle file
) {
    return 0;
}

[[nsmbw(0x802EC3D4)]]
int __read_file(__file_handle file, unsigned char* buffer, size_t* count, __idle_proc idle_fn);

[[nsmbw(0x802EC3DC)]]
int __write_file(__file_handle file, unsigned char* buffer, size_t* count, __idle_proc idle_fn);

EXTERN_C_END
