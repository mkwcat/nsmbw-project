#pragma once

namespace nw4r::math
{
    [[address(0x80237D10)]]
    float SinFIdx(float idx);

    [[address(0x80237D80)]]
    float CosFIdx(float idx);
}

#include "mtx.h"
#include "vec.h"
