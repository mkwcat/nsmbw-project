// d_pc.cpp
// NSMBW .text: 0x800D15F0 - 0x800D2D10

#include "d_pc.h"

[[nsmbw(0x800D2360)]]
short dPc_c::getAngle() const;

[[nsmbw(0x800D2480)]]
void dPole_ctr_c::init();

[[nsmbw(0x800D24A0)]]
void dPole_ctr_c::entry();

[[nsmbw(0x800D24F0)]]
void dPole_ctr_c::release();

[[nsmbw(0x800D2600)]]
void dPoleRope_c::calcLength();

[[nsmbw(0x800D2700)]]
void dPoleRope_c::init(
    dActor_c* parent, u8 count, mVec3_c* v0x28, const float* floats, short* angles, int type,
    bool v0x22, u8 flags
);
