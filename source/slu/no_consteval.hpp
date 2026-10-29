//
//  slu/no_consteval.hpp
//  supplemental-language-utilities
//

#pragma once

namespace slu {

[[gnu::always_inline]]
inline auto no_consteval(
    auto v
) -> decltype(v) {
    return v;
}

} // namespace slu
