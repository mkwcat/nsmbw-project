// OS.c
// NSMBW .text: 0x801A9E80 - 0x801AB3C0

#include "revolution/os.h"

EXTERN_C_START

[[nsmbw(0x801AB300)]]
void OSRegisterVersion(const char* string);

EXTERN_C_END
