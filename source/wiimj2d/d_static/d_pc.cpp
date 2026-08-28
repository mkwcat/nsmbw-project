// d_pc.cpp
// NSMBW .text: 0x800D15F0 - 0x800D2D10

#include "d_pc.h"

#include <cstring>
#include <type_traits>

[[nsmbw(0x800D2360)]]
short dPc_c::getAngle() const;

[[nsmbw(0x800D2480)]]
void dPole_ctr_c::init() {
    mPrev = mNext = nullptr;
    mPc           = nullptr;
    mIsLink       = false;
    m0x1E         = -1;
}

[[nsmbw(0x800D24A0)]]
void dPole_ctr_c::entry();

[[nsmbw(0x800D24F0)]]
void dPole_ctr_c::release();

[[nsmbw(0x800D2600)]]
void dPoleRope_c::calcLength();

[[nsmbw(0x800D2700)]]
void dPoleRope_c::init(
    dActor_c* parent, u8 count, mVec3_c* v0x28, const float* floats, short* angles, int mode,
    bool v0x22, u8 flags
) {
    mParent = parent;
    mMode   = mode + 1;
    m0x22   = v0x22;
    mFlags  = flags;
    m0x28   = v0x28;
    mAngFlt = floats;
    mAngle  = angles;
    if constexpr (std::is_pointer_v<std::remove_cvref_t<decltype(mPlrAngle)>>) {
        if (mPlrAngle) {
            std::memset(mPlrAngle, 0, sizeof(short) * PLAYER_COUNT);
        }
    } else {
        std::memset(mPlrAngle, 0, sizeof mPlrAngle);
    }
    mAngCount = count;
    calcLength();
    calc();
}

[[nsmbw(0x800D2780)]]
void dPoleRope_c::calc();
