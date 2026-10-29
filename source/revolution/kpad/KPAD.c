// KPAD.c
// NSMBW .text: 0x801EAA80 - 0x801EEAE0

#include <revolution/kpad.h>

EXTERN_C_START

[[mkw(0x80197AAC)]]
void KPADInit(void);

[[nsmbw(0x801ED4F0)]]
int KPADReadEx(WPADChannel chan, KPADStatus* status, u32 count, s32* result);

EXTERN_C_END
