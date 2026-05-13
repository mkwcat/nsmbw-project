// alloc.c
// NSMBW .text: 0x802DD76C - 0x802DDC80

#include "stdio.h"

EXTERN_C_START

[[nsmbw(0x802DDB50)]]
void free(
    void* ptr
) {
    operator delete(ptr);
}

EXTERN_C_END
