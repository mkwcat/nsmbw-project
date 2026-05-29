//
//  mkwcat/Misc.hpp
//  nsmbw-project
//

#pragma once

#include "BaseTypes.hpp"
#include <bit>
#include <type_traits>

namespace mkwcat {

struct Misc {
private:
    Misc() = delete;

public:
    template <unsigned N>
    using UIntOfBits = std::conditional_t<
        N <= 8, u8,
        std::conditional_t<
            N <= 16, u16, std::conditional_t<N <= 32, u32, std::conditional<N <= 64, u64, void>>>>;

    template <unsigned long long N> using UIntOfLimit = UIntOfBits<std::bit_width(N)>;
};

template <class T>
std::type_identity<T>::type implicit_cast(
    auto& value
) {
    return value;
}

} // namespace mkwcat
