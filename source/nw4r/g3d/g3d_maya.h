#pragma once

#include "g3d_anmtexsrt.h"
#include "nw4r/math/mtx.h"

namespace nw4r::g3d::detail::dcc
{
bool CalcTexMtx_Maya(math::MTX34*, bool, const TexSrt&, TexSrt::Flag);
}
