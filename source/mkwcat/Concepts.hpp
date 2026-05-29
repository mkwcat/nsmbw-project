//
//  mkwcat/Concepts.hpp
//  nsmbw-project
//

#pragma once

#include <concepts>

namespace mkwcat {

template <class T>
concept TypeTrait = requires { typename T::type; };

template <class T>
concept BoolTrait = requires {
    { T::value } -> std::same_as<bool>;
};

template <class T, template <class> class Trait>
concept Test = Trait<T>::value;

template <class T>
concept CompleteType = __is_complete_type(T);

template <class T>
concept Enum = std::is_enum_v<T>;

} // namespace mkwcat
