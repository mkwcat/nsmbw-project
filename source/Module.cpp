// Module.cpp

#include "Four.h"
#include <mkwcat/Relocate.hpp>
#include <revolution/arc.h>
#include <revolution/dvd.h>
#include <revolution/os.h>
#include <wiimj2d/d_system/d_system.h>

EXTERN_C_START

// External init
int main();
int preinit(s32, void*);

// Rel init
void _prolog(s32, void*);
void _epilog();
void _unresolved();

// Runtime init
void __stack_chk_init(std::uintptr_t value);

constexpr u32 THIS_MODULE_ID = 0x50414C41; // 'PALA'

using VoidFunction = void (*)();
extern VoidFunction _ctors[];
extern VoidFunction _ctors_end[];

extern mkwcat::Attribute::Entry _MRel_replace_array[];
extern mkwcat::Attribute::Entry _MRel_replace_array_end[];

extern mkwcat::Attribute::Entry _MRel_extern_array[];
extern mkwcat::Attribute::Entry _MRel_extern_array_end[];

extern mkwcat::Relocate::Entry<1> _MRel_patch_references_array[];
extern mkwcat::Relocate::Entry<1> _MRel_patch_references_array_end[];

#define HID0 1008
#define HID0_ICFI (1 << 31 >> 20)
#define HID0_DCFA (1 << 31 >> 25)
static void __flush_entire_cache(bool interrupts = OSDisableInterrupts()) ASM_METHOD(
  // clang-format off
    // Set data cache flush assist
    mfspr   r4, HID0;
    ori     r0, r4, HID0_DCFA;
    mtspr   HID0, r0;
    isync;

    // Flush the entire L1 data cache by filling up all 8 ways of 128 sets
    li      r0, 128 * 8;
    mtctr   r0;
    lis     r5, 0x8000;
    subi    r5, r5, 32;

    lwzu    r0, 32(r5);
    dcbst   0, r5;
    bdnz+   (-0x8);

    ori     r0, r4, HID0_ICFI; // Enable icache flash invalidate
    mtspr   HID0, r0;

    // Sync with the 60x bus
    sc;

    // Restore interrupts
    mfmsr   r4;
    rlwimi  r4, r3, 15, 0x8000;
    mtmsr   r4;
    blr;
  // clang-format on
);

[[gnu::no_stack_protector]]
void _prolog(s32 param1, void* param2)
{
    __stack_chk_init(OSGetTick());

    auto codeRegion = dSys_c::findCodeRegion();
    *const_cast<volatile dSys_c::CODE_REGION_e*>(&dSys_c::m_codeRegion) = codeRegion;

    int interrupt = OSDisableInterrupts();

    // Reference patches
    for (auto repl = _MRel_patch_references_array; repl != _MRel_patch_references_array_end;) {
        for (u32 i = 0; i < repl->count; i++) {
            u32 offset = reinterpret_cast<u32>(repl->dest.addr) + repl->references[i].addend;
            volatile u16* ptr = reinterpret_cast<volatile u16*>(
              (&repl->references[i].addrP1)[static_cast<int>(codeRegion)]
            );
            if (ptr == nullptr) {
                OS_REPORT(
                  "WARNING: Skipping relocation patch at P1 %08X\n", repl->references[i].addrP1
                );
                continue;
            }

            if (repl->references[i].type == R_PPC_ADDR16_LO) {
                offset &= 0xFFFF;
            } else if (repl->references[i].type == R_PPC_ADDR16_HI) {
                offset >>= 16;
            } else if (repl->references[i].type == R_PPC_ADDR16_HA) {
                offset = (offset + 0x8000) >> 16;
            } else {
                OSPanic(__FILE_NAME__, __LINE__, "Unsupported relocation type %d");
            }

            *ptr = static_cast<u16>(offset);
        }

        // Increment repl to the next entry
        repl = reinterpret_cast<mkwcat::Relocate::Entry<1>*>(&repl->references[repl->count]);
    }

    Four::Apply();

    // External replaced array
    for (mkwcat::Attribute::Entry* __restrict repl = _MRel_extern_array;
         repl != _MRel_extern_array_end; ++repl) {
        if (repl->addr == nullptr) {
            OS_REPORT("WARNING: Skipping extern patch with null address\n");
            continue;
        }
        *repl->dest.instruction = *repl->addr;
    }

    // Function patches
    for (mkwcat::Attribute::Entry* __restrict repl = _MRel_replace_array;
         repl != _MRel_replace_array_end; ++repl) {
        if (repl->addr == nullptr) {
            OS_REPORT(
              "WARNING: Skipping replace patch #%d with null address (prev: 0x%08X)\n",
              u32(repl - _MRel_replace_array), u32((repl - 1)->addr)
            );
            continue;
        }
        *repl->addr = 0x48000000 | ((u32(repl->dest.instruction) - u32(repl->addr)) & 0x3FFFFFC);
    }

    __flush_entire_cache(false);

    if (preinit(param1, param2) != 0) {
        OSPanic(__FILE_NAME__, __LINE__, "preinit() returned non-zero");
    }

    // Run global constructors
    for (VoidFunction* ctor = _ctors; ctor != _ctors_end && *ctor; ++ctor) {
        (*ctor)();
    }

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmain"
    if (main() != 0) {
        OSPanic(__FILE_NAME__, __LINE__, "main() returned non-zero");
    }
#pragma clang diagnostic pop

    OSRestoreInterrupts(interrupt);
}

[[gnu::no_stack_protector]]
void _epilog()
{
}

[[gnu::no_stack_protector]]
void _unresolved()
{
    // Infinite loop
    while (true) {
    }
}

EXTERN_C_END