#pragma once

#include <revolution/mtx.h>

namespace nw4r::math {

struct VEC2 : ::Vec2 {
    constexpr VEC2() {}

    constexpr VEC2(
        float x, float y
    )
        : ::Vec2(x, y) {}
};

struct VEC3 : ::Vec {
    constexpr VEC3() {}

    constexpr VEC3(
        float x, float y, float z
    )
        : ::Vec(x, y, z) {}
};

using MTX33 = float[3][3];
using MTX34 = Mtx;
using MTX44 = Mtx44;

} // namespace nw4r::math
