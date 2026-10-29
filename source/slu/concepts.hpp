//
//  slu/concepts.hpp
//  supplemental-language-utilities
//

#pragma once

namespace slu::concepts {

template <class T, class U>
concept same_as = __is_same_as(T, U);

template <class T>
concept is_void = __is_void(T);

template <class T>
concept member_object_pointer = __is_member_object_pointer(T);

template <class T>
concept not_void = !__is_void(T);

template <class T>
concept type_trait = requires { typename T::type; };

template <class T>
concept bool_trait = requires {
    { T::value } -> same_as<bool>;
};

template <class T, template <class> class Trait>
concept test = Trait<T>::value;

template <class T>
concept complete_type = __is_complete_type(T);

template <class T>
concept enum_type = __is_enum(T);

template <class T>
concept pointer = __is_pointer(T);

template <class T>
concept integral = __is_integral(T);

template <class T>
concept unsigned_integral = integral<T> && __is_unsigned(T);

template <class T>
concept address = pointer<T> || unsigned_integral<T>;

} // namespace slu::concepts
