//
//  mkwcat/ToString.hpp
//  nsmbw-project
//

#pragma once

#include "Concepts.hpp"
#include <magic_enum/magic_enum.hpp>
#include <string_view>

namespace mkwcat {

template <Test<std::is_enum> E>
constexpr std::string_view ToStringView(
    E e
) {
    return magic_enum::enum_name(e);
}

template <Test<std::is_enum> E>
constexpr const char* ToString(
    E e
) {
    return ToStringView<E>(e).data();
}

constexpr std::string_view ToStringView(
    bool i
) {
    return i ? "true" : "false";
}

constexpr const char* ToString(
    bool i
) {
    return i ? "true" : "false";
}

} // namespace mkwcat
