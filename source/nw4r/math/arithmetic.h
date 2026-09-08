#pragma once

#include "constant.h"
#include <bit>
#include <cmath>
#include <mkwcat/Instructions.hpp>
#include <revolution/os.h>

namespace nw4r::math {

namespace detail {

f32 FExp(f32 x);
f32 FLog(f32 x);

} // namespace detail

f32 FrSqrt(f32 x);

inline f32 FAbs(
    f32 x
) {
    return std::fabs(x);
}

inline f32 FCeil(
    f32 x
) {
    return std::ceilf(x);
}

inline f32 FExp(
    f32 x
) {
    return detail::FExp(x);
}

inline f32 FFloor(
    f32 x
) {
    return std::floorf(x);
}

inline f32 FInv(
    f32 x
) {
    f32 res = __builtin_ppc_fres(x);

    // Refine estimate
    return mkwcat::ps_nmsub(
        x, mkwcat::ps_mul(res, res), mkwcat::ps_add(res, res)
    ); // -(x * 1/x^2 - 2/x)
}

inline f32 FMod(
    f32 x, f32 y
) {
    return std::fmodf(x, y);
}

inline f32 FModf(
    f32 x, f32* pY
) {
    return std::modff(x, pY);
}

inline f32 FSqrt(
    f32 x
) {
    return x <= 0.0f ? 0.0f : x * FrSqrt(x);
}

inline f32 FLog(
    f32 x
) {
    if (x > 0.0f) {
        return detail::FLog(x);
    }

    return NW4R_MATH_QNAN;
}

inline f32 FSelect(
    f32 value, f32 ge_zero, f32 lt_zero
) {
    return __builtin_ppc_fsel(value, ge_zero, lt_zero);
}

// Using internal OSFastCast functions because the public ones have a volatile pointer and emit
// unnecessary instructions

inline f32 U16ToF32(
    u16 x
) {
    return __OSu16tof32(&x);
}

inline u16 F32ToU16(
    f32 x
) {
    return __OSf32tou16(x);
}

inline f32 S16ToF32(
    s16 x
) {
    return __OSs16tof32(&x);
}

inline s16 F32ToS16(
    f32 x
) {
    return __OSf32tos16(x);
}

constexpr u32 F32AsU32(
    f32 x
) {
    return std::bit_cast<u32>(x);
}

constexpr f32 U32AsF32(
    u32 x
) {
    return std::bit_cast<f32>(x);
}

constexpr s32 FGetExpPart(
    f32 x
) {
    s32 s = F32AsU32(x);
    return ((s >> 23) & 0xFF) - 127;
}

constexpr f32 FGetMantPart(
    f32 x
) {
    u32 u = F32AsU32(x);
    return U32AsF32((u & 0x807FFFFF) | 0x3F800000);
}

} // namespace nw4r::math
