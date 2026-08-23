// d_ka_draw.cpp
// NSMBW .text: 0x800BBD80 - 0x800BC330

#include "d_ka_draw.h"

[[nsmbw(0x800BBF60)]]
void dKADr_c::init(u16);

[[nsmbw(0x800BBE60)]]
void dKADr_c::calc_vtx_pos();

[[nsmbw(0x800BBFC0)]]
void dKADr_c::move(const mVec3_c&);

[[nsmbw(0x800BC190)]]
void dKADr_c::nodeCallback_c::timingB(u32, nw4r::g3d::WorldMtxManip*, nw4r::g3d::ResMdl);

[[nsmbw(0x800BC2F0)]]
dKADr_c::nodeCallback_c::~nodeCallback_c() {}
