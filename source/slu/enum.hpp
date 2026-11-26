//
//  slu/enum.hpp
//  supplemental-language-utilities
//

#pragma once

#include "slu/concepts.hpp"
#include <type_traits>
#include <utility>

namespace slu {

#define ENUM_ALLOW_BITWISE(X_TYPE) \
    constexpr X_TYPE operator~(X_TYPE a) { \
        return static_cast<X_TYPE>(~std::to_underlying(a)); \
    } \
    constexpr X_TYPE operator&(X_TYPE a, X_TYPE b) { \
        return static_cast<X_TYPE>(std::to_underlying(a) & std::to_underlying(b)); \
    } \
    constexpr X_TYPE operator|(X_TYPE a, X_TYPE b) { \
        return static_cast<X_TYPE>(std::to_underlying(a) | std::to_underlying(b)); \
    } \
    constexpr X_TYPE operator^(X_TYPE a, X_TYPE b) { \
        return static_cast<X_TYPE>(std::to_underlying(a) ^ std::to_underlying(b)); \
    } \
    constexpr X_TYPE& operator&=(X_TYPE& a, X_TYPE b) { \
        return a = a & b; \
    } \
    constexpr X_TYPE& operator|=(X_TYPE& a, X_TYPE b) { \
        return a = a | b; \
    } \
    constexpr X_TYPE& operator^=(X_TYPE& a, X_TYPE b) { \
        return a = a ^ b; \
    } \
    constexpr bool operator!(const X_TYPE& a) { \
        return !std::to_underlying(a); \
    }

#define ENUM_ALLOW_PROMOTION(X_TYPE) \
    constexpr std::underlying_type_t<X_TYPE> operator+(X_TYPE a) { \
        return std::to_underlying(a); \
    }

template <class SizeType, class ValueType>
class [[gnu::packed]] enum_value {
    static_assert(std::is_enum_v<ValueType>, "ValueType must be an enum type");
    static_assert(std::is_integral_v<SizeType>, "SizeType must be an integral type");

    SizeType m_underlying_value;

public:
    constexpr enum_value()
        : m_underlying_value(0) {}

    constexpr enum_value(
        ValueType value
    )
        : m_underlying_value(static_cast<SizeType>(value)) {}

    constexpr enum_value(
        const enum_value& other
    )
        : m_underlying_value(other.m_underlying_value) {}

    template <class OtherSizeType>
    constexpr enum_value(
        const enum_value<OtherSizeType, ValueType>& other
    )
        : m_underlying_value(static_cast<SizeType>(other)) {}

    constexpr operator ValueType() const { return static_cast<ValueType>(m_underlying_value); }

    constexpr enum_value& operator=(
        ValueType value
    ) {
        m_underlying_value = static_cast<SizeType>(value);
        return *this;
    }

    template <class OtherSizeType>
    constexpr enum_value& operator=(
        const enum_value<OtherSizeType, ValueType>& other
    ) {
        m_underlying_value = static_cast<SizeType>(other);
        return *this;
    }

    constexpr bool operator==(
        ValueType value
    ) const {
        return static_cast<ValueType>(m_underlying_value) == value;
    }

    template <class OtherSizeType>
    constexpr bool operator==(
        const enum_value<OtherSizeType, ValueType>& other
    ) const {
        return m_underlying_value == static_cast<SizeType>(other);
    }

    constexpr bool operator<(
        ValueType value
    ) const {
        return static_cast<ValueType>(m_underlying_value) < value;
    }

    template <class OtherSizeType>
    constexpr bool operator<(
        const enum_value<OtherSizeType, ValueType>& other
    ) const {
        return m_underlying_value < static_cast<SizeType>(other);
    }

    constexpr bool operator<=(
        ValueType value
    ) const {
        return static_cast<ValueType>(m_underlying_value) <= value;
    }

    template <class OtherSizeType>
    constexpr bool operator<=(
        const enum_value<OtherSizeType, ValueType>& other
    ) const {
        return m_underlying_value <= static_cast<SizeType>(other);
    }

    constexpr bool operator!() const { return m_underlying_value == 0; }

    template <class T>
        requires(slu::concepts::integral<T> || slu::concepts::enumerator<T>)
    explicit constexpr operator T() const {
        return static_cast<T>(m_underlying_value);
    }
};

} // namespace slu

namespace std {
template <class SizeType, class ValueType>
struct underlying_type<slu::enum_value<SizeType, ValueType>> {
    using type = SizeType;
};
} // namespace std
