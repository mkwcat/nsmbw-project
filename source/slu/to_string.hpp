//
//  slu/to_string.hpp
//  supplemental-language-utilities
//

#pragma once

#include "concepts.hpp"
#include <magic_enum/magic_enum.hpp>
#include <string_view>

namespace slu {

template <concepts::test<std::is_enum> E>
constexpr std::string_view to_string_view(
    E e
) {
    return magic_enum::enum_name(e);
}

template <concepts::test<std::is_enum> E>
constexpr const char* to_string(
    E e
) {
    return to_string_view<E>(e).data();
}

constexpr std::string_view to_string_view(
    bool i
) {
    return i ? "true" : "false";
}

constexpr const char* to_string(
    bool i
) {
    return i ? "true" : "false";
}

} // namespace slu
