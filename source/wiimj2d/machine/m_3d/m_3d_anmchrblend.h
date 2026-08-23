#ifndef M3D_M_ANMCHRBLEND_H
#define M3D_M_ANMCHRBLEND_H

#include "machine/m_3d/m_3d_anmchr.h"
#include "machine/m_3d/m_3d_banm.h"
#include "machine/m_3d/m_3d_bmdl.h"
#include <nw4r/g3d/g3d_anmchr.h>

namespace m3d {

class anmChrBlend_c : public banm_c {
public:
    virtual ~anmChrBlend_c();

    virtual int getType() const override;

    bool create(nw4r::g3d::ResMdl, int, mAllocator_c *, u32 *);
    void attach(int, nw4r::g3d::AnmObjChrRes *, f32);
    void attach(int, anmChr_c *, f32);
    void detach(int);
    // Not in NSMBW
    void setWeight(int, f32);
    f32 getWeight(int) const;
};

} // namespace m3d

#endif
