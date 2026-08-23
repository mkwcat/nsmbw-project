#pragma once

#include <nw4r/ut/Color.h>
#include <revolution/gx/GXEnum.h>

namespace nw4r::g3d {

struct FogAnmResult {
    GXFogType mFogType; // at 0x18
    f32       mStartZ;  // at 0x14
    f32       mEndZ;    // at 0x10
    ut::Color mColor;   // at 0xC
};

} // namespace nw4r::g3d
