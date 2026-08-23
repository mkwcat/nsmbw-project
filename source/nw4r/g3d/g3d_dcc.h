#ifndef NW4R_G3D_DCC_H
#define NW4R_G3D_DCC_H

#include "g3d_anmtexsrt.h"
#include "nw4r/math.h"

namespace nw4r {
namespace g3d {
void CalcTexMtx(math::MTX34*, bool, const TexSrt&, TexSrt::Flag, TexSrtTypedef::TexMatrixMode);
}
} // namespace nw4r

#endif
