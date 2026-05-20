//
//  mkwcat/TypePack.hpp
//  nsmbw-project
//

#pragma once

#include "mkwcat/Misc.hpp"
#include <cstddef>

namespace mkwcat {

template <class... T> struct TypePack {
    using size_type                 = Misc::UIntOfLimit<sizeof...(T)>;

    template <size_type I> using at = T...[I];

    static constexpr size_type size = sizeof...(T);

    template <class U>
    static constexpr size_type find = [] {
        size_type i   = 0;
        size_type pos = 0;
        (void) ((std::is_same_v<U, T> ? (pos = i, true) : (i++, false)) || ...);
        return pos;
    }();
};

template <class... T> struct TypeSwitch : TypePack<T...> {
    TypePack<T...>::size_type index;
};

} // namespace mkwcat
