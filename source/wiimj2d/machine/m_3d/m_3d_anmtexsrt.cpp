// m_3d_anmtexsrt.cpp
// NSMBW .text: 0x80167140 - 0x80167D80

#include "m_3d_anmtexsrt.h"

namespace m3d
{

[[nsmbw(0x80167560)]]
bool anmTexSrt_c::create(nw4r::g3d::ResMdl, nw4r::g3d::ResAnmTexSrt, mAllocator_c*, u32*, s32);

[[nsmbw(0x80167940)]]
void anmTexSrt_c::setAnm(bmdl_c&, nw4r::g3d::ResAnmTexSrt, s32, playMode_e);

} // namespace m3d