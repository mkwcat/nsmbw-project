// OSTime.c
// NSMBW .text: 0x801B60C0 - 0x801B64F0

#include "OSTime.h"

EXTERN_C_START

[[nsmbw(0x801B60C0)]] [[mkw(0x801AAD5C)]]
OSTime OSGetTime();

[[nsmbw(0x801B60E0)]] [[mkw(0x801AAD74)]]
OSTick OSGetTick();

// UNUSED: __SetTime
// UNUSED: __OSSetTime

[[nsmbw_symbol(0x801B60F0, "__OSGetSystemTime")]];

[[nsmbw_symbol(0x801B6160, "__OSTimeToSystemTime")]];

// UNUSED: __OSSetTick

[[nsmbw(0x801B61C0)]] [[mkw(0x801AAFA8)]]
void OSTicksToCalendarTime(OSTime time, OSCalendarTime* cal);

// UNUSED: OSCalendarTimeToTicks

EXTERN_C_END
