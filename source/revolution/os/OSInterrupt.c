// OSInterrupt.c
// NSMBW .text: 0x801B1280 - 0x801B1A50

#include "OSInterrupt.h"

EXTERN_C_START

[[nsmbw(0x801B1280)]] [[mkw(0x801A65AC)]]
bool OSDisableInterrupts();

[[nsmbw(0x801B12A0)]] [[mkw(0x801A65C0)]]
bool OSEnableInterrupts();

[[nsmbw(0x801B12C0)]] [[mkw(0x801A65D4)]]
bool OSRestoreInterrupts(bool status);

EXTERN_C_END
