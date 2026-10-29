//
//  slu/init.hpp
//  supplemental-language-utilities
//

#pragma once

#include "attribute.hpp"

namespace slu::init {

using void_function = void (*)();

extern "C" {
extern void_function    _ctors[];
extern void_function    _ctors_end[];

extern attribute::entry slu_replace_array[];
extern attribute::entry slu_replace_array_end[];

extern attribute::entry slu_extern_array[];
extern attribute::entry slu_extern_array_end[];
}

// Defined by user
bool handle_null_extern_address(attribute::entry* entry);
bool handle_null_replace_address(attribute::entry* entry);

inline bool apply_patches() {
    // External replaced array
    for (slu::attribute::entry* __restrict repl = slu_extern_array; repl != slu_extern_array_end;
         ++repl) {
        if (repl->address == nullptr) {
            if (!handle_null_extern_address(repl)) {
                return false;
            }
            continue;
        }
        *repl->dest.instruction = *repl->address;
        repl->address           = nullptr;
    }

    // Function patches
    for (slu::attribute::entry* __restrict repl = slu_replace_array; repl != slu_replace_array_end;
         ++repl) {
        if (repl->address == nullptr) {
            if (!handle_null_replace_address(repl)) {
                return false;
            }
            continue;
        }
        *repl->address =
            0x48000000 | ((u32(repl->dest.instruction) - u32(repl->address)) & 0x3FFFFFC);
        repl->address = nullptr;
    }

    return true;
}

inline void run_ctors() {
    for (void_function* ctor = _ctors; ctor != _ctors_end && *ctor; ++ctor) {
        (*ctor)();
    }
}

} // namespace slu::init
