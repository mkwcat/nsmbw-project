#ifndef M3D_M_SMDL_H
#define M3D_M_SMDL_H

#include "m_3d_bmdl.h"
#include "m_3d_scnleaf.h"
#include <nw4r/g3d/g3d_resmdl.h>


namespace m3d {

class smdl_c : public bmdl_c {
    SIZE_ASSERT(0xC);

public:
    smdl_c();
    /* VT+0x08 */ virtual ~smdl_c();

    bool create(nw4r::g3d::ResMdl mdl, mAllocator_c *alloc, u32 bufferOption, int nView, u32 *pSize);
    bool create(nw4r::g3d::ResMdl mdl, mAllocator_c *alloc, u32 bufferOption) {
        return create(mdl, alloc, bufferOption, 1, nullptr);
    }
};

} // namespace m3d

#endif
