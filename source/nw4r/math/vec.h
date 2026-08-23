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

} // namespace nw4r::math
