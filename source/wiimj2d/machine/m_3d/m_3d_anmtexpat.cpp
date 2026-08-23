// m_anmtexpat.cpp
// NSMBW .text: 0x80166560 - 0x80167140

#include "m_3d_anmtexpat.h"

namespace m3d
{

[[nsmbw(0x80166970)]]
bool anmTexPat_c::create(nw4r::g3d::ResMdl, nw4r::g3d::ResAnmTexPat, mAllocator_c*, u32*, s32);

[[nsmbw(0x80166D10)]]
void anmTexPat_c::setAnm(bmdl_c&, nw4r::g3d::ResAnmTexPat, s32, playMode_e);

[[nsmbw(0x80166FC0)]]
void anmTexPat_c::play(s32);

[[nsmbw(0x80167020)]]
f32 anmTexPat_c::getFrame(s32) const;

[[nsmbw(0x80167030)]]
void anmTexPat_c::setFrame(f32, s32);

[[nsmbw(0x80167050)]]
void anmTexPat_c::setRate(f32, s32);

[[nsmbw(0x80167060)]]
bool anmTexPat_c::isStop(s32) const;

} // namespace m3d