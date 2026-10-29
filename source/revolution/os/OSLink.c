// OSLink.c
// NSMBW .text: 0x801B1A50 - 0x801B24D0

#include "OSLink.h"

EXTERN_C_START

[[nsmbw_symbol(0x801B1A50, "OSNotifyLink")]];

[[nsmbw_symbol(0x801B1A60, "OSNotifyUnlink")]];

[[nsmbw_symbol(0x801B1A70, "OSNotifyPreLink")]];

[[nsmbw_symbol(0x801B1A80, "OSNotifyPostLink")]];

[[nsmbw_symbol(0x801B1A90, "OSSetStringTable")]];

[[nsmbw_symbol(0x801B1AA0, "Relocate")]];

[[nsmbw_symbol(0x801B1D70, "Link")]];

[[nsmbw(0x801B2060)]] [[mkw(0x801A72DC)]]
bool OSLink(OSModuleInfo* info, void* bss);

[[nsmbw(0x801B2070)]]
bool OSLinkFixed(OSModuleInfo* info, void* bss);

// 0x801B2090: Undo

// 0x801B22D0: OSUnlink

// 0x801B24B0: __OSModuleInit

// UNUSED: OSSearchModule

EXTERN_C_END
