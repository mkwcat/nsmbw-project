// OSTime.c
// NSMBW .text: 0x801B60C0 - 0x801B64F0

#include "OSTime.h"

EXTERN_C_START

[[nsmbw(0x801B60C0)]]
OSTime OSGetTime();

[[nsmbw(0x801B60E0)]]
OSTick OSGetTick();

// UNUSED: __SetTime
// UNUSED: __OSSetTime

EXTERN_SYMBOL(0x801B60F0, "__OSGetSystemTime");

EXTERN_SYMBOL(0x801B6160, "__OSTimeToSystemTime");

// UNUSED: __OSSetTick

[[nsmbw(0x801B61C0)]]
void OSTicksToCalendarTime(OSTime time, OSCalendarTime* cal);

// UNUSED: OSCalendarTimeToTicks

EXTERN_C_END
