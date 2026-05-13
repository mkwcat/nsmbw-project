#pragma once

#include <stddef.h>

EXTERN_C_START

//
// runtime/__mem.c
//

/* 0x80004364 */
constexpr inline void* memcpy(
    void* __restrict dest, const void* __restrict src, size_t n
) {
    unsigned char*       d = static_cast<unsigned char*>(dest);
    const unsigned char* s = static_cast<const unsigned char*>(src);
    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }
    return dest;
}

/* 0x800046B4 */
constexpr inline void* memset(
    void* s, int c, size_t n
) {
    unsigned char* p = static_cast<unsigned char*>(s);
    for (size_t i = 0; i < n; i++) {
        p[i] = static_cast<unsigned char>(c);
    }
    return s;
}

/* 0x800046B4 */
constexpr inline size_t strlen(
    const char* s
) {
    size_t length = 0;
    while (s[length] != char()) {
        ++length;
    }
    return length;
}

//
// mem.c
//

/* 0x802DF264 */
void* memmove(void* dest, const void* src, size_t n);

/* 0x802DF330 */
void* memchr(const void* s, int c, size_t n);

/* 0x802DF35C */
void* memrchr(const void* s, int c, size_t n) asm("__memrchr");

/* 0x802DF388 */
int memcmp(const void* s1, const void* s2, size_t n);

//
// string.c
//

/* 0x802E1C28 */
char* strcpy(char* __restrict dst, const char* __restrict src);

/* 0x802E1CE8 */
char* strncpy(char* dst, const char* src, size_t n);

/* 0x802E1D2C */
char* strcat(char* __restrict dst, const char* __restrict src);

/* 0x802E1D58 */
char* strncat(char* __restrict dst, const char* __restrict src, size_t n);

/* 0x802E1DA4 */
int strcmp(const char* s1, const char* s2);

/* 0x802E1EC0 */
int strncmp(const char* s1, const char* s2, size_t n);

/* 0x802E1F00 */
char* strchr(const char* s, int c);

/* 0x802E1F30 */
char* strrchr(const char* s, int c);

/* 0x802E1F78 */
char* strstr(const char* haystack, const char* needle);

EXTERN_C_END
