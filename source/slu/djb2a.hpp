//
//  slu/djb2a.hpp
//  supplemental-language-utilities
//

#pragma once

#include "base_types.hpp"

namespace slu {

constexpr u32 djb2a(
    const char* str
) {
    u32 hash = 5381;
    while (char c = *str++) {
        hash = (hash * 33) ^ c;
    }
    return hash;
}

constexpr u32 djb2a(
    const char* str, std::size_t len
) {
    u32 hash = 5381;
    while (len--) {
        hash = (hash * 33) ^ *str++;
    }
    return hash;
}

} // namespace slu
