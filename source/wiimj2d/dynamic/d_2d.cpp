// d_2d.cpp
// NSMBW .text: 0x80006790 - 0x80007510

#include "d_2d.h"

namespace d2d
{

[[address(0x80006EA0)]]
void Multi_c::entry();

[[address(0x80007220)]]
nw4r::lyt::Pane* Multi_c::getRootPane();

} // namespace d2d