#include <cstdint>
#include <revolution/arc.h>
#include <revolution/dvd.h>
#include <revolution/os.h>
#include <slu/init.hpp>
#include <slu/relocate.hpp>
#include <slu/revision.hpp>

#if is_nsmbw
#  include "Four.h"
#endif

// External init
extern "C" {
int main(int argc, char** argv);
int preinit(s32, void*);
}

// Rel init
extern "C" void _prolog(int argc, char** argv, const char*& at, s32 arcEntryNum, void* arcStart);
extern "C" void _epilog();
extern "C" void _unresolved();

// Runtime init
extern "C" void __stack_chk_init(std::uintptr_t value);

#define HID0      1008
#define HID0_ICFI (1 << 31 >> 20)
#define HID0_DCFA (1 << 31 >> 25)
static void __flush_entire_cache(bool interrupts = OSDisableInterrupts()) ASM_METHOD(
    // Enable data cache flush assist
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
);

bool slu::init::handle_null_extern_address(
    attribute::entry* entry
) {
    return true;
}

bool slu::init::handle_null_replace_address(
    attribute::entry* entry
) {
    return true;
}

bool slu::relocate::handle_null_relocate_address(
    entry<1>* entry
) {
    return true;
}

bool slu::relocate::handle_invalid_relocation_type(
    entry<1>* entry
) {
    OS_PANIC("Invalid relocation type");
}

[[gnu::no_stack_protector]] [[gnu::section("rel_prolog")]]
void _prolog(
    int argc, char** argv, const char*& at, s32 arcEntryNum, void* arcStart
) {
    __stack_chk_init(OSGetTick());
    slu::determine_revision();

    BOOL interrupts = OSDisableInterrupts();

    NSMBW_ONLY(slu::relocate::apply());

    // Apply patches to DOL
    slu::init::apply_patches();

    NSMBW_ONLY(Four::Apply());

    __flush_entire_cache(interrupts);

    if (preinit(arcEntryNum, arcStart) != 0) {
        at = "preinit";
        return;
    }

    // Run global constructors
    slu::init::run_ctors();

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmain"
    (void) main(argc, argv);
#pragma clang diagnostic pop

    at = nullptr;
}

[[gnu::no_stack_protector]] [[gnu::section("rel_prolog")]]
void _epilog() {}

[[gnu::no_stack_protector]] [[gnu::section("rel_prolog")]]
void _unresolved() {
    // Infinite loop
    while (true) {
    }
}

#if is_mkw
extern "C" [[mkw(0x801A6D30)]]
void OSNotifyLink(
    OSModuleInfo* newModule
) {
    BOOL interrupts = OSDisableInterrupts();

    // Apply patches to StaticR.rel
    slu::init::apply_patches();

    __flush_entire_cache(interrupts);
}
#endif
