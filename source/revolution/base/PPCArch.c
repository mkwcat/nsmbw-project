// PPCArch.c
// NSMBW .text: 0x801A9C60 - 0x801A9E80

#include <revolution/base/PPCArch.h>

[[nsmbw_symbol(0x801A9C60, "PPCMfmsr")]];
[[nsmbw_symbol(0x801A9C70, "PPCMtmsr")]];
// UNUSED: PPCOrMsr
// UNUSED: PPCAndMsr
// UNUSED: PPCAndCMsr

[[nsmbw_symbol(0x801A9C80, "PPCMfhid0")]];
[[nsmbw_symbol(0x801A9C90, "PPCMthid0")]];
// UNUSED: PPCMthid1

[[nsmbw_symbol(0x801A9CA0, "PPCMfl2cr")]];
[[nsmbw_symbol(0x801A9CB0, "PPCMtl2cr")]];

[[nsmbw_symbol(0x801A9CC0, "PPCMtdec")]];
// UNUSED: PPCMfdec

[[nsmbw_symbol(0x801A9CD0, "PPCSync")]];
// UNUSED: PPCEieio

[[nsmbw(0x801A9CE0)]] [[noreturn]]
void PPCHalt();

// UNUSED: PPCMfmmcr0
[[nsmbw_symbol(0x801A9D00, "PPCMtmmcr0")]];
// UNUSED: PPCMfmmcr1
[[nsmbw_symbol(0x801A9D10, "PPCMtmmcr1")]];

// UNUSED: PPCMfpmc1
[[nsmbw_symbol(0x801A9D20, "PPCMtpmc1")]];
// UNUSED: PPCMfpmc2
[[nsmbw_symbol(0x801A9D30, "PPCMtpmc2")]];
// UNUSED: PPCMfpmc3
[[nsmbw_symbol(0x801A9D40, "PPCMtpmc3")]];
// UNUSED: PPCMfpmc4
[[nsmbw_symbol(0x801A9D50, "PPCMtpmc4")]];

// UNUSED: PPCMfsia
// UNUSED: PPCMtsia

[[nsmbw_symbol(0x801A9D60, "PPCMffpscr")]];
[[nsmbw_symbol(0x801A9D80, "PPCMtfpscr")]];

[[nsmbw_symbol(0x801A9DB0, "PPCMfhid2")]];
[[nsmbw_symbol(0x801A9DC0, "PPCMthid2")]];

[[nsmbw_symbol(0x801A9DD0, "PPCMfwpar")]];
[[nsmbw_symbol(0x801A9DE0, "PPCMtwpar")]];

// UNUSED: PPCMfdmaU
// UNUSED: PPCMfdmaL
// UNUSED: PPCMtdmaU
// UNUSED: PPCMtdmaL

// UNUSED: PPCMfpvr

// UNUSED: PPCEnableSpeculation
[[nsmbw_symbol(0x801A9DF0, "PPCDisableSpeculation")]];

// UNUSED: PPCSetFpIEEEMode
[[nsmbw_symbol(0x801A9E20, "PPCSetFpNonIEEEMode")]];

// UNUSED: PPCMfhid4
[[nsmbw_symbol(0x801A9E30, "PPCMthid4")]];
