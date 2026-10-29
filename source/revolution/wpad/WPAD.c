// WPAD.c
// NSMBW .text: 0x801DDC90 - 0x801E55A0

#include <revolution/wpad.h>

EXTERN_C_START

[[mkw(0x801BF644)]]
void WPADRegisterAllocator(WPADAllocFunc pAllocFunc, WPADFreeFunc pFreeFunc);

[[mkw(0x801BF648)]]
u32 WPADGetWorkMemorySize(void);

[[nsmbw(0x801DFC40)]]
WPADClearDeviceCallback WPADSetClearDeviceCallback(WPADClearDeviceCallback pCallback);

[[nsmbw(0x801DFD10)]]
BOOL WPADSetAcceptConnection(BOOL accept);

[[nsmbw(0x801E0F80)]]
void WPADDisconnect(WPADChannel chan);

[[nsmbw(0x801E1080)]]
WPADResult WPADProbe(WPADChannel chan, u32* pDevType);

[[nsmbw(0x801E1620)]]
void WPADControlMotor(WPADChannel chan, WPADMotorCommand command);

EXTERN_C_END
