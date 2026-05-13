#pragma once

#include <stddef.h>

EXTERN_C_START

#define abs(x) __builtin_abs(x)
#define labs(x) __builtin_abs(x)

/* 0x802E1FE4 */
unsigned long __strtoul(int, int, int (*)(void*, int, int), void*, int*, int*, int*);

/* 0x802E23F8 */
int atoi(const char* s);

/* 0x802DF0EC */
size_t mbstowcs(wchar_t* dest, const char* src, size_t len);

[[gnu::malloc]]
inline void* malloc(
    size_t size
) {
    return operator new(size);
}

[[gnu::malloc]]
inline void* calloc(
    size_t num, size_t size
) {
    void* ptr = operator new(size);
    __builtin_memset(ptr, 0, num * size);
    return ptr;
}

/* 0x802DDB50 */
void free(void* ptr);

EXTERN_C_END
