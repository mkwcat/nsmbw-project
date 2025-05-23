// PPCArch.c
// NSMBW .text: 0x801A9C60 - 0x801A9E80

#include <revolution/base/PPCArch.h>

EXTERN_SYMBOL(0x801A9C60, "PPCMfmsr");
EXTERN_SYMBOL(0x801A9C70, "PPCMtmsr");
// UNUSED: PPCOrMsr
// UNUSED: PPCAndMsr
// UNUSED: PPCAndCMsr

EXTERN_SYMBOL(0x801A9C80, "PPCMfhid0");
EXTERN_SYMBOL(0x801A9C90, "PPCMthid0");
// UNUSED: PPCMthid1

EXTERN_SYMBOL(0x801A9CA0, "PPCMfl2cr");
EXTERN_SYMBOL(0x801A9CB0, "PPCMtl2cr");

EXTERN_SYMBOL(0x801A9CC0, "PPCMtdec");
// UNUSED: PPCMfdec

EXTERN_SYMBOL(0x801A9CD0, "PPCSync");
// UNUSED: PPCEieio

[[address(0x801A9CE0)]] [[noreturn]]
void PPCHalt();

// UNUSED: PPCMfmmcr0
EXTERN_SYMBOL(0x801A9D00, "PPCMtmmcr0");
// UNUSED: PPCMfmmcr1
EXTERN_SYMBOL(0x801A9D10, "PPCMtmmcr1");

// UNUSED: PPCMfpmc1
EXTERN_SYMBOL(0x801A9D20, "PPCMtpmc1");
// UNUSED: PPCMfpmc2
EXTERN_SYMBOL(0x801A9D30, "PPCMtpmc2");
// UNUSED: PPCMfpmc3
EXTERN_SYMBOL(0x801A9D40, "PPCMtpmc3");
// UNUSED: PPCMfpmc4
EXTERN_SYMBOL(0x801A9D50, "PPCMtpmc4");

// UNUSED: PPCMfsia
// UNUSED: PPCMtsia

EXTERN_SYMBOL(0x801A9D60, "PPCMffpscr");
EXTERN_SYMBOL(0x801A9D80, "PPCMtfpscr");

EXTERN_SYMBOL(0x801A9DB0, "PPCMfhid2");
EXTERN_SYMBOL(0x801A9DC0, "PPCMthid2");

EXTERN_SYMBOL(0x801A9DD0, "PPCMfwpar");
EXTERN_SYMBOL(0x801A9DE0, "PPCMtwpar");

// UNUSED: PPCMfdmaU
// UNUSED: PPCMfdmaL
// UNUSED: PPCMtdmaU
// UNUSED: PPCMtdmaL

// UNUSED: PPCMfpvr

// UNUSED: PPCEnableSpeculation
EXTERN_SYMBOL(0x801A9DF0, "PPCDisableSpeculation");

// UNUSED: PPCSetFpIEEEMode
EXTERN_SYMBOL(0x801A9E20, "PPCSetFpNonIEEEMode");

// UNUSED: PPCMfhid4
EXTERN_SYMBOL(0x801A9E30, "PPCMthid4");