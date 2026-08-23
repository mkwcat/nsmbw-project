#pragma once

#include "machine/m_allocator.h"
#include <nw4r/g3d/g3d_scnobj.h>

namespace m3d
{

// NON-OFFICIAL
enum ScnLeafType_e {
    SCN_LEAF_MODEL = 0,
    SCN_LEAF_PROC = 2,
};

class scnLeaf_c
{
    SIZE_ASSERT(0x8);

public:
    scnLeaf_c();
    /* VT+0x08 */ virtual ~scnLeaf_c();
    /* VT+0x0C */ virtual int getType() const = 0;
    /* VT+0x10 */ virtual void remove();
    /* VT+0x14 */ virtual int entry();

    void setOption(u32 flag, u32 set);
    void setScale(f32, f32, f32);
    void setScale(const nw4r::math::VEC3&);
    void getScale(nw4r::math::VEC3*) const;

    void setLocalMtx(const nw4r::math::MTX34*);
    void getLocalMtx(nw4r::math::MTX34*) const;
    const nw4r::math::MTX34* getLocalMtx() const;
    void getWorldMtx(nw4r::math::MTX34*) const;
    void getViewMtx(nw4r::math::MTX34*) const;

    void setCallback(nw4r::g3d::IScnObjCallback* cb);
    nw4r::g3d::IScnObjCallback* swapCallback(nw4r::g3d::IScnObjCallback* cb);

    void enableCallbackTiming(nw4r::g3d::ScnObj::Timing);
    void enableCallbackOp(nw4r::g3d::ScnObj::ExecOp);

    void calc(bool);
    void calcVtx(bool);
    void calcView(void*, bool);

    void setPriorityDraw(int, int);

    inline nw4r::g3d::ScnLeaf* getG3dObject()
    {
        return mpScnLeaf;
    }

protected:
    /* 0x4 */ nw4r::g3d::ScnLeaf* mpScnLeaf;
};

} // namespace m3d
