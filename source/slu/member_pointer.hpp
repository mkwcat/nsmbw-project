//
//  slu/member_pointer.hpp
//  supplemental-language-utilities
//

#pragma once

#include "concepts.hpp"

namespace slu {

template <concepts::member_object_pointer>
struct member_pointer_parts;

template <class T, class U>
struct member_pointer_parts<T(U::*)> {
    using value_type = T;
    using class_type = U;
};

template <concepts::member_object_pointer auto V>
struct member_pointer_parts_obj : member_pointer_parts<decltype(V)> {};

template <decltype(sizeof 0) N>
class ptmf_size_pad;

template <decltype(sizeof 0) N = sizeof(void (ptmf_size_pad<12>::*)())>
class ptmf_size_pad {
    [[no_unique_address]] char pad[12 - N];
};

template <>
class ptmf_size_pad<12> {};

} // namespace slu
