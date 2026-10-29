//
//  slu/type_pack.hpp
//  supplemental-language-utilities
//

#pragma once

#include "misc.hpp"

namespace slu {

template <class... T>
struct type_pack {
    using size_type = misc::uint_to_hold<sizeof...(T)>;

    template <size_type I>
    using at                        = T...[I];

    static constexpr size_type size = sizeof...(T);

    template <class U>
    static constexpr size_type find = [] {
        size_type i   = 0;
        size_type pos = 0;
        (void) ((__is_same_as(U, T) ? (pos = i, true) : (i++, false)) || ...);
        return pos;
    }();

    template <class U>
    static constexpr bool contains = [] {
        return (__is_same_as(U, T) || ...);
    };
};

template <class... T>
struct type_switch : type_pack<T...> {
    type_pack<T...>::size_type index;
};

} // namespace slu
