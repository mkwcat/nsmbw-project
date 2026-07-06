// OSReset.c
// NSMBW .text: 0x801B3410 - 0x801B3E20

#include "OSReset.h"

EXTERN_C_START

[[nsmbw(0x801B3410)]]
void OSRegisterShutdownFunction(OSShutdownFunctionInfo* info);

EXTERN_C_END
