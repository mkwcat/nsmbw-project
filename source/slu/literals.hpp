//
//  slu/literals.hpp
//  supplemental-language-utilities
//

#include "base_types.hpp"

namespace slu::literals {

constexpr u64 operator""_bit(
    u64 bit
) {
    return 1ull << bit;
}

} // namespace slu::literals
