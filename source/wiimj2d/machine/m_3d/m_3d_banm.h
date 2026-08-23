#ifndef M3D_M_BANM_H
#define M3D_M_BANM_H

#include <egg/core/eggFrmHeap.h>
#include "machine/m_allocator.h"
#include <nw4r/g3d/g3d_anmobj.h>

namespace m3d {

class banm_c {
public:
    banm_c() = default;
    virtual ~banm_c();

    virtual int getType() const = 0;
    virtual void remove();
    virtual void play();

    bool createAllocator(mAllocator_c *alloc, u32 *pSize);
    bool IsBound() const;
    f32 getFrame() const;
    void setFrameOnly(f32);
    f32 getRate() const;
    void setRate(f32);

    inline nw4r::g3d::AnmObj *getAnimObj() const {
        return mpAnmObj;
    }

protected:
    nw4r::g3d::AnmObj *mpAnmObj = nullptr;
    EGG::FrmHeap *mpFrameHeap = nullptr;
    mAllocator_c mAllocator;
};

} // namespace m3d

#endif
