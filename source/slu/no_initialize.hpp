//
//  slu/no_initialize.hpp
//  supplemental-language-utilities
//

#pragma once

namespace slu {

template <class T> constexpr T no_initialize() {
    return __builtin_bit_cast(T, (char[sizeof(T)]) {});
}

} // namespace slu
