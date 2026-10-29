//
//  slu/relocate.hpp
//  supplemental-language-utilities
//

#pragma once

#include "base_types.hpp"
#include "macro.hpp"
#include "port.hpp"
#include <revolution/os/OSLink.h>

namespace slu {

namespace relocate {
struct reference {
    consteval reference()
        : type(0)
        , addend(0)
        , address(nullptr) {}

    consteval reference(
        u32 address, u8 type, s16 addend = 0
    )
        : type(type)
        , addend(addend)
        , address(&slu::port_region[address]) {}

    u8    type;
    s16   addend;
    void* address;
};

template <u32 N>
struct entry {
    constexpr entry(
        u32 offset, const reference (&references_)[N]
    ) {
        dest.offset = offset;
        for (unsigned i = 0; i < N; i++) {
            references[i] = references_[i];
        }
    }

    constexpr entry(
        const void* const& address_, const reference (&references_)[N]
    ) {
        dest.address = address_;
        for (unsigned i = 0; i < N; i++) {
            references[i] = references_[i];
        }
    }

    union {
        const void* address;
        u32         offset;
    } dest;

    u32       count = N;

    reference references[N];
};

extern "C" entry<1> slu_patch_references_array[];
extern "C" entry<1> slu_patch_references_array_end[];

bool handle_null_relocate_address(entry<1>* entry);
bool handle_invalid_relocation_type(entry<1>* entry);

inline void apply() {
    // Reference patches
    for (auto entry = slu_patch_references_array; entry != slu_patch_references_array_end;) {
        for (u32 i = 0; i < entry->count; i++) {
            u32 offset = reinterpret_cast<u32>(entry->dest.address) + entry->references[i].addend;
            volatile u16* ptr = static_cast<volatile u16*>(entry->references[i].address);
            if (ptr == nullptr) {
                if (!handle_null_relocate_address(entry)) {
                    return;
                }
                continue;
            }

            if (entry->references[i].type == R_PPC_ADDR16_LO) {
                offset &= 0xFFFF;
            } else if (entry->references[i].type == R_PPC_ADDR16_HI) {
                offset >>= 16;
            } else if (entry->references[i].type == R_PPC_ADDR16_HA) {
                offset = (offset + 0x8000) >> 16;
            } else {
                if (!handle_invalid_relocation_type(entry)) {
                    return;
                }
                continue;
            }

            *ptr = static_cast<u16>(offset);
        }

        // Increment repl to the next entry
        entry = reinterpret_cast<relocate::entry<1>*>(&entry->references[entry->count]);
    }
}

#define __PATCH_REFERENCES_EVAL(X_COUNTER, X_DEST, ...) \
    [[__gnu__::__section__("patch_references_array")]] [[__gnu__::__used__]] \
    static constinit ::slu::relocate::entry __RelocateEntry_##X_COUNTER = {X_DEST, __VA_ARGS__};
#define __PATCH_REFERENCES(X_COUNTER, X_DEST, ...) \
    __PATCH_REFERENCES_EVAL(X_COUNTER, X_DEST, __VA_ARGS__)

#define PATCH_REFERENCES(X_DEST, ...) __PATCH_REFERENCES(__COUNTER__, X_DEST, __VA_ARGS__)
}; // namespace relocate

} // namespace slu
