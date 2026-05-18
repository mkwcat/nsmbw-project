//
//  mkwcat/NoConsteval.hpp
//  nsmbw-project
//

#pragma once

namespace mkwcat {

[[gnu::always_inline]]
inline auto NoConsteval(
    auto v
) -> decltype(v) {
    return v;
}

} // namespace mkwcat
