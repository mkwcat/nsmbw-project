//
//  mkwcat/NoInitialize.hpp
//  nsmbw-project
//

#pragma once

namespace mkwcat {

template <class T>
constexpr T NoInitialize() {
    return __builtin_bit_cast(T, (char[sizeof(T)]) {});
}

} // namespace mkwcat
