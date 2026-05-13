// d_reset.cpp
// NSMBW .text: 0x80107FD0 - 0x80109020

#include "d_reset.h"

namespace dReset {

[[nsmbw(0x80108020)]]
Manage_c* Manage_c::GetInstance();

[[nsmbw(0x80108340)]]
void Manage_c::SetSoftResetFinish();

} // namespace dReset
