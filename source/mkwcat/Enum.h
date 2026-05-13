//
//  mkwcat/Enum.h
//  nsmbw-project
//

#pragma once

namespace mkwcat {

#define ENUM_ALLOW_BITWISE(X_TYPE)                                                                 \
    constexpr X_TYPE operator~(X_TYPE a) {                                                         \
        return static_cast<X_TYPE>(~static_cast<__underlying_type(X_TYPE)>(a));                    \
    }                                                                                              \
    constexpr X_TYPE operator&(X_TYPE a, X_TYPE b) {                                               \
        return static_cast<X_TYPE>(                                                                \
            static_cast<__underlying_type(X_TYPE)>(a) & static_cast<__underlying_type(X_TYPE)>(b)  \
        );                                                                                         \
    }                                                                                              \
    constexpr X_TYPE operator|(X_TYPE a, X_TYPE b) {                                               \
        return static_cast<X_TYPE>(                                                                \
            static_cast<__underlying_type(X_TYPE)>(a) | static_cast<__underlying_type(X_TYPE)>(b)  \
        );                                                                                         \
    }                                                                                              \
    constexpr X_TYPE operator^(X_TYPE a, X_TYPE b) {                                               \
        return static_cast<X_TYPE>(                                                                \
            static_cast<__underlying_type(X_TYPE)>(a) ^ static_cast<__underlying_type(X_TYPE)>(b)  \
        );                                                                                         \
    }                                                                                              \
    constexpr X_TYPE& operator&=(X_TYPE& a, X_TYPE b) {                                            \
        return a = a & b;                                                                          \
    }                                                                                              \
    constexpr X_TYPE& operator|=(X_TYPE& a, X_TYPE b) {                                            \
        return a = a | b;                                                                          \
    }                                                                                              \
    constexpr X_TYPE& operator^=(X_TYPE& a, X_TYPE b) {                                            \
        return a = a ^ b;                                                                          \
    }                                                                                              \
    constexpr bool operator!(const X_TYPE& a) {                                                    \
        return !static_cast<__underlying_type(X_TYPE)>(a);                                         \
    }

} // namespace mkwcat
