// m_3d_anmchr.cpp
// NSMBW .text: 0x80165210 - 0x80165660

#include "m_3d_anmchr.h"

namespace m3d {

// Moved from d_player_model_base.o (weak)
[[nsmbw(0x800D5590)]]
anmChr_c::anmChr_c();

[[nsmbw(0x80165210)]]
bool anmChr_c::create(nw4r::g3d::ResMdl, nw4r::g3d::ResAnmChr, mAllocator_c*, u32*);

[[nsmbw(0x80165330)]]
void anmChr_c::setAnm(bmdl_c&, nw4r::g3d::ResAnmChr, playMode_e);

} // namespace m3d
