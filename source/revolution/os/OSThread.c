// OSThread.c
// NSMBW .text: 0x801B4950 - 0x801B60C0

#include "OSThread.h"

EXTERN_C_START

[[nsmbw_symbol(0x801B4950, "DefaultSwitchThreadCallback")]];

[[nsmbw_symbol(0x801B4960, "OSSetSwitchThreadCallback")]];

[[nsmbw_symbol(0x801B49D0, "__OSThreadInit")]];

[[nsmbw_symbol(0x801B4C60, "OSInitThreadQueue")]];

[[nsmbw(0x801B4C70)]] [[mkw(0x801A98B0)]]
OSThread* OSGetCurrentThread(void);

[[nsmbw_symbol(0x801B4C80, "OSIsThreadTerminated")]];

[[nsmbw_symbol(0x801B4CB0, "OSDisableScheduler")]];

[[nsmbw_symbol(0x801B4CF0, "OSEnableScheduler")]];

[[nsmbw_symbol(0x801B4D30, "UnsetRun")]];

[[nsmbw_symbol(0x801B4DA0, "__OSGetEffectivePriority")]];

[[nsmbw_symbol(0x801B4DE0, "SetEffectivePriority")]];

[[nsmbw_symbol(0x801B4F90, "__OSPromoteThread")]];

[[nsmbw_symbol(0x801B4FE0, "SelectThread")]];

[[nsmbw_symbol(0x801B5210, "__OSReschedule")]];

[[nsmbw_symbol(0x801B5230, "OSYieldThread")]];

[[nsmbw_symbol(0x801B5270, "OSCreateThread")]];

[[nsmbw_symbol(0x801B54E0, "OSExitThread")]];

[[nsmbw_symbol(0x801B55D0, "OSCancelThread")]];

[[nsmbw_symbol(0x801B57B0, "OSJoinThread")]];

[[nsmbw_symbol(0x801B5900, "OSDetachThread")]];

[[nsmbw_symbol(0x801B59A0, "OSResumeThread")]];

[[nsmbw_symbol(0x801B5C40, "OSSuspendThread")]];

[[nsmbw_symbol(0x801B5DD0, "OSSleepThread")]];

[[nsmbw_symbol(0x801B5EC0, "OSWakeupThread")]];

[[nsmbw_symbol(0x801B5FC0, "OSSetThreadPriority")]];

[[nsmbw_symbol(0x801B60B0, "OSGetThreadPriority")]];

EXTERN_C_END
