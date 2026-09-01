#pragma once

#include "arithmetic.h"
#include "constant.h"

namespace nw4r::math {

// Macros
// ^^^^^^

// [0, 65535] -> [0.0, 256.0f]
#define NW4R_MATH_IDX_TO_FIDX(x) ((x) * (1.0f / 256.0f))

// Convert degrees <-> lookup-table index
#define NW4R_MATH_DEG_TO_FIDX(x) ((x) * (256.0f / 360.0f))
#define NW4R_MATH_FIDX_TO_DEG(x) ((x) * (360.0f / 256.0f))

// Convert radians <-> lookup-table index
#define NW4R_MATH_RAD_TO_FIDX(x) ((x) * (128.0f / NW4R_MATH_PI))
#define NW4R_MATH_FIDX_TO_RAD(x) ((x) * (NW4R_MATH_PI / 128.0f))

// Convert degrees <-> radians
#define NW4R_MATH_DEG_TO_RAD(x) ((x) * (NW4R_MATH_PI / 180.0f))
#define NW4R_MATH_RAD_TO_DEG(x) ((x) * (180.0f / NW4R_MATH_PI))

// Sin Functions
// ^^^^^^

f32 SinFIdx(f32 fidx);

inline f32 SinIdx(
    u16 idx
) {
    return SinFIdx(NW4R_MATH_IDX_TO_FIDX(U16ToF32(idx)));
}

inline f32 SinDeg(
    f32 deg
) {
    return SinFIdx(NW4R_MATH_DEG_TO_FIDX(deg));
}

inline f32 SinRad(
    f32 rad
) {
    return SinFIdx(NW4R_MATH_RAD_TO_FIDX(rad));
}

} // namespace nw4r::math
