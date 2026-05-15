#pragma once

#include <bit>

template <class T> class fParam_c : public T::Param_s {
public:
    // Structors
    // ^^^^^^

    constexpr fParam_c() = default;

    constexpr fParam_c(
        const T::Param_s& param
    )
        : T::Param_s(param) {}

    constexpr fParam_c(
        u32 raw
    )
        : T::Param_s(std::bit_cast<typename T::Param_s>(raw)) {}

public:
    // Operators
    // ^^^^^^

    constexpr operator u32() { return std::bit_cast<u32>(*this); }
};
