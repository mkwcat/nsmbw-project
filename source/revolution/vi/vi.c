// vi.c
// NSMBW .text: 0x801BBB70 - 0x801BE5C0

EXTERN_C_START

#include <revolution/vi.h>

[[nsmbw_data(0x8042AB30)]]
s32 __VIDimmingFlag_SI_IDLE;

EXTERN_SYMBOL(0x801BBB70, "OnShutdown");

EXTERN_SYMBOL(0x801BBD10, "__VIRetraceHandler");

EXTERN_SYMBOL(0x801BC520, "VISetPreRetraceCallback");

EXTERN_SYMBOL(0x801BC570, "VISetPostRetraceCallback");

// UNUSED: __VISetExtraTiming

EXTERN_SYMBOL(0x801BC5C0, "getTiming");

EXTERN_SYMBOL(0x801BC6E0, "__VIInit");

EXTERN_SYMBOL(0x801BC8E0, "VIInit");

EXTERN_SYMBOL(0x801BCE30, "VIWaitForRetrace");

EXTERN_SYMBOL(0x801BCE90, "setFbbRegs");

EXTERN_SYMBOL(0x801BD140, "setHorizontalRegs");

EXTERN_SYMBOL(0x801BD220, "setVerticalRegs");

EXTERN_SYMBOL(0x801BD3C0, "VIConfigure");

EXTERN_SYMBOL(0x801BDA90, "VIConfigurePan");

EXTERN_SYMBOL(0x801BDDF0, "VIFlush");

EXTERN_SYMBOL(0x801BDF10, "VISetNextFrameBuffer");

// UNUSED: VIGetNextFrameBuffer

EXTERN_SYMBOL(0x801BDF80, "VIGetCurrentFrameBuffer");

// UNUSED: VISetNextRightFrameBuffer

EXTERN_SYMBOL(0x801BDF90, "VISetBlack");

// UNUSED: VISet3D

EXTERN_SYMBOL(0x801BE010, "VIGetRetraceCount");

EXTERN_SYMBOL(0x801BE020, "VIGetNextField");

EXTERN_SYMBOL(0x801BE0C0, "VIGetCurrentLine");

EXTERN_SYMBOL(0x801BE150, "VIGetTvFormat");

// UNUSED: VIGetScanMode

EXTERN_SYMBOL(0x801BE1B0, "VIGetDTVStatus");

// UNUSED: __VISetAdjustingValues
// UNUSED: __VIGetAdjustingValues
// UNUSED: __VIEnableRawPositionInterrupt
// UNUSED: __VIDisableRawPositionInterrupt

EXTERN_SYMBOL(0x801BE1F0, "__VIDisplayPositionToXY");

// UNUSED: __VIGetCurrentPosition
// UNUSED: __VISetLatchMode
// UNUSED: __VIGetLatch0Position
// UNUSED: __VIGetLatch1Position
// UNUSED: __VIGetLatchPosition
// UNUSED: VIGetVSyncTimingTest
// UNUSED: VISetVSyncTimingTest
// UNUSED: __VIDisableDimming
// UNUSED: __VISetAutoDimming
// UNUSED: __VISetDimmingCountLimit
// UNUSED: __VISetDVDStopMotorCountLimit
// UNUSED: VIGetDimmingCount
// UNUSED: VIGetDVDStopMotorCount

EXTERN_SYMBOL(0x801BE430, "VIEnableDimming");

EXTERN_SYMBOL(0x801BE490, "VISetTimeToDimming");

EXTERN_SYMBOL(0x801BE590, "VIResetDimmingCount");

// UNUSED: VIEnableDVDStopMotor

EXTERN_SYMBOL(0x801BE5B0, "__VIResetRFIdle");

bool __VIResetSIIdle() {
    __VIDimmingFlag_SI_IDLE = 0;
    return true;
}

// UNUSED: __VIResetDev0Idle
// UNUSED: __VIResetDev1Idle
// UNUSED: __VIResetDev2Idle
// UNUSED: __VIResetDev3Idle
// UNUSED: __VIResetDev4Idle
// UNUSED: __VIResetDev5Idle
// UNUSED: __VIResetDev6Idle
// UNUSED: __VIResetDev7Idle
// UNUSED: __VIResetDev8Idle
// UNUSED: __VIResetDev9Idle

EXTERN_C_END
