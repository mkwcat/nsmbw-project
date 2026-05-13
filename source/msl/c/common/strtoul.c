// strtoul.c
// NSMBW .text: 0x802E1FE4 - 0x802E24BC

#include <stdlib.h>

EXTERN_C_START

[[nsmbw(0x802E1FE4)]]
unsigned long __strtoul(int, int, int (*)(void*, int, int), void*, int*, int*, int*);

[[nsmbw(0x802E23F8)]]
int atoi(const char* s);

EXTERN_C_END
