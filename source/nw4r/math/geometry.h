#pragma once

#include "mtx.h"
#include "vec.h"

namespace nw4r::math {

struct AABB {
    AABB() {}

    void Set(const VEC3* points, unsigned int num);
    void Set(const AABB* box, const MTX34* mtx);

    VEC3 min; // at 0x0
    VEC3 max; // at 0xC
};

} // namespace nw4r::math
