//
//  slu/misc.hpp
//  supplemental-language-utilities
//

#pragma once

#include "base_types.hpp"

namespace slu {

struct misc {
public:
    misc() = delete;

public:
    template <bool B, class T>
    struct cond {
        static constexpr bool met = true;
        using type                = T;
    };

    template <class T>
    struct cond<false, T> {
        static constexpr bool met = false;
        using type                = void;
    };

    template <class... C>
    struct long_conditional {
        static constexpr bool met = false;
        using type                = void;
    };

    template <class C, class... E>
        requires(C::met)
    struct long_conditional<C, E...> {
        static constexpr bool met = true;
        using type                = C::type;
    };

    template <class C, class... E>
        requires(!C::met)
    struct long_conditional<C, E...> {
        static constexpr bool met = long_conditional<E...>::met;
        using type                = long_conditional<E...>::type;
    };

    template <unsigned N>
    using uint_of_bits = long_conditional<
        cond<N <= 8, u8>, cond<N <= 16, u16>, cond<N <= 32, u32>, cond<N <= 64, u64>>::type;

    template <unsigned long long N>
    using uint_to_hold = uint_of_bits<sizeof(long long) * 8 - __builtin_clzll(N)>;
};

} // namespace slu
