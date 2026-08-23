// m_mdl.cpp
// NSMBW .text: 0x801696A0 - 0x8016A150

#include "m_3d_mdl.h"

namespace m3d {

[[nsmbw(0x80169E10)]]
mdl_c::mdl_c();

[[nsmbw(0x80169ED0)]]
bool mdl_c::create(nw4r::g3d::ResMdl, mAllocator_c*, u32, int, u32*);

[[nsmbw(0x8016A070)]]
void mdl_c::setAnm(banm_c&);

[[nsmbw(0x8016A0C0)]]
void mdl_c::setAnm(banm_c&, f32);

} // namespace m3d
