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
concept enumerator = __is_enum(T);

template <class T>
concept pointer = __is_pointer(T);

template <class T>
concept integral = __is_integral(T);

template <class T>
concept unsigned_integral = integral<T> && __is_unsigned(T);

template <class T>
concept address = pointer<T> || unsigned_integral<T>;

namespace detail {
template <class T, template <class...> class Template>
struct same_templated_type {
    enum {
        value = false,
    };
};

template <template <class...> class Template, class... Args>
struct same_templated_type<Template<Args...>, Template> {
    enum {
        value = true,
    };
};

template <class T, template <auto...> class Template>
struct same_value_templated_type {
    enum {
        value = false,
    };
};

template <template <auto...> class Template, auto... Args>
struct same_value_templated_type<Template<Args...>, Template> {
    enum {
        value = true,
    };
};
} // namespace detail

template <class T, template <class...> class Template>
concept same_templated_type = !!detail::same_templated_type<__remove_cvref(T), Template>::value;

template <class T, template <auto...> class Template>
concept same_value_templated_type =
    !!detail::same_value_templated_type<__remove_cvref(T), Template>::value;

} // namespace slu::concepts
