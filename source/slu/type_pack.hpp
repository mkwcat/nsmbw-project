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

template <auto... V>
struct value_pack {
    using size_type = misc::uint_to_hold<sizeof...(V)>;

    template <size_type I>
    static constexpr decltype(auto) at   = V...[I];

    static constexpr size_type      size = sizeof...(V);

    template <auto U>
    static constexpr size_type find = [] {
        size_type i   = 0;
        size_type pos = 0;
        (void) ((U == V ? (pos = i, true) : (i++, false)) || ...);
        return pos;
    }();

    template <auto U>
    static constexpr bool contains = [] {
        return ((U == V) || ...);
    };
};

namespace detail {

template <class T>
struct type_pack_from {
    using type = type_pack<>;
};

template <template <class...> class O, class... T>
struct type_pack_from<O<T...>> {
    using type = type_pack<T...>;
};

template <class T>
struct value_pack_from {
    using type = value_pack<>;
};

template <template <auto...> class O, auto... V>
struct value_pack_from<O<V...>> {
    using type = value_pack<V...>;
};

} // namespace detail

template <class T>
using type_pack_from = detail::type_pack_from<T>::type;

template <class T>
using value_pack_from = detail::value_pack_from<T>::type;

} // namespace slu
