#pragma once

#include <concepts>

namespace cLib {

template <class T, std::same_as<T>... V>
constexpr bool isOneOf(
    T value, V... values
) {
    return ((value == values) || ...);
}

} // namespace cLib
