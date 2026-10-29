// vi.c
// NSMBW .text: 0x801BBB70 - 0x801BE5C0

EXTERN_C_START

#include <revolution/vi.h>

[[nsmbw_data(0x8042AB30)]]
s32 __VIDimmingFlag_SI_IDLE;

[[nsmbw_symbol(0x801BBB70, "OnShutdown")]];

[[nsmbw_symbol(0x801BBD10, "__VIRetraceHandler")]];

[[nsmbw_symbol(0x801BC520, "VISetPreRetraceCallback")]];

[[nsmbw_symbol(0x801BC570, "VISetPostRetraceCallback")]];

// UNUSED: __VISetExtraTiming

[[nsmbw_symbol(0x801BC5C0, "getTiming")]];

[[nsmbw_symbol(0x801BC6E0, "__VIInit")]];

[[nsmbw(0x801BC8E0)]] [[mkw(0x801B94A4)]]
void VIInit(void);

[[nsmbw_symbol(0x801BCE30, "VIWaitForRetrace")]];

[[nsmbw_symbol(0x801BCE90, "setFbbRegs")]];

[[nsmbw_symbol(0x801BD140, "setHorizontalRegs")]];

[[nsmbw_symbol(0x801BD220, "setVerticalRegs")]];

[[nsmbw_symbol(0x801BD3C0, "VIConfigure")]];

[[nsmbw_symbol(0x801BDA90, "VIConfigurePan")]];

[[nsmbw_symbol(0x801BDDF0, "VIFlush")]];

[[nsmbw_symbol(0x801BDF10, "VISetNextFrameBuffer")]];

// UNUSED: VIGetNextFrameBuffer

[[nsmbw_symbol(0x801BDF80, "VIGetCurrentFrameBuffer")]];

// UNUSED: VISetNextRightFrameBuffer

[[nsmbw(0x801BDF90)]] [[mkw(0x801BAB2C)]]
void VISetBlack(BOOL);

// UNUSED: VISet3D

[[nsmbw_symbol(0x801BE010, "VIGetRetraceCount")]];

[[nsmbw_symbol(0x801BE020, "VIGetNextField")]];

[[nsmbw_symbol(0x801BE0C0, "VIGetCurrentLine")]];

[[nsmbw_symbol(0x801BE150, "VIGetTvFormat")]];

// UNUSED: VIGetScanMode

[[nsmbw_symbol(0x801BE1B0, "VIGetDTVStatus")]];

// UNUSED: __VISetAdjustingValues
// UNUSED: __VIGetAdjustingValues
// UNUSED: __VIEnableRawPositionInterrupt
// UNUSED: __VIDisableRawPositionInterrupt

[[nsmbw_symbol(0x801BE1F0, "__VIDisplayPositionToXY")]];

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

[[nsmbw_symbol(0x801BE430, "VIEnableDimming")]];

[[nsmbw_symbol(0x801BE490, "VISetTimeToDimming")]];

[[nsmbw_symbol(0x801BE590, "VIResetDimmingCount")]];

// UNUSED: VIEnableDVDStopMotor

[[nsmbw_symbol(0x801BE5B0, "__VIResetRFIdle")]];

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
