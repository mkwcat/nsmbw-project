// direct_io.c
// NSMBW .text: 0x802DE904 - 0x802DEC0C

#include <stdio.h>

EXTERN_C_START

size_t __fwrite(const void* buffer, size_t size, size_t count, FILE* stream);

size_t fwrite(
    const void* buffer, size_t size, size_t count, FILE* stream
) {
    return __fwrite(buffer, size, count, stream);
}

[[nsmbw(0x802DE904)]]
size_t __fwrite(const void* buffer, size_t size, size_t count, FILE* stream);

EXTERN_C_END
