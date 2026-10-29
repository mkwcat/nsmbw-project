//
//  slu/pointer.hpp
//  supplemental-language-utilities
//

#include "concepts.hpp"

namespace slu::pointer {

template <concepts::address T>
[[gnu::always_inline]]
constexpr T align(
    T address, int alignment
) {
    decltype(sizeof 0) adjusted;
    if constexpr (concepts::integral<T>) {
        adjusted = address;
    } else {
        adjusted = reinterpret_cast<decltype(sizeof 0)>(address);
    }
    if (alignment < 0) {
        adjusted &= alignment;
    } else if (alignment > 0) {
        adjusted = (adjusted + alignment - 1) & ~(alignment - 1);
    }
    if constexpr (concepts::integral<T>) {
        return adjusted;
    } else {
        return reinterpret_cast<T>(adjusted);
    }
}

template <class T>
[[gnu::always_inline]]
inline T* offset(
    concepts::address auto                                address,
    decltype(static_cast<int*>(0) - static_cast<int*>(0)) offset = 0, int alignment = 0
) {
    auto adjusted = reinterpret_cast<decltype(sizeof 0)>(address) + offset;
    if (alignment < 0) {
        adjusted &= alignment;
    } else if (alignment > 0) {
        adjusted = (adjusted + alignment - 1) & ~(alignment - 1);
    }
    return reinterpret_cast<T*>(adjusted);
}

template <concepts::address T, concepts::address U>
[[gnu::always_inline]]
constexpr decltype(static_cast<int*>(0) - static_cast<int*>(0)) raw_distance(
    T a, U b
) {
    if constexpr (concepts::integral<T> && concepts::integral<U>) {
        return reinterpret_cast<decltype(static_cast<int*>(0) - static_cast<int*>(0))>(b) - a;
    } else {
        return reinterpret_cast<char*>(b) - reinterpret_cast<char*>(a);
    }
}

} // namespace slu::pointer
