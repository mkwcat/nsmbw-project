#ifndef NW4R_G3D_RESNODE_H
#define NW4R_G3D_RESNODE_H

#include "g3d_rescommon.h"
#include "nw4r/math/vec.h"

namespace nw4r::g3d {

struct ChrAnmResult;

struct ResNodeData {
    u32        INT_0x0;
    s32        INT_0x4;
    u16        SHORT_0x8;
    u16        SHORT_0xA;
    u32        WORD_0xC;
    u32        WORD_0x10;
    u32        mFlags; // at 0x14
    u32        WORD_0x18;
    u32        WORD_0x1C;
    math::VEC3 VEC3_0x20;
    math::VEC3 VEC3_0x2C;
    f32        FLOAT_0x38;
    f32        FLOAT_0x3C;
    f32        FLOAT_0x40;
    f32        FLOAT_0x44;
    f32        FLOAT_0x48;
    f32        FLOAT_0x4C;
    f32        FLOAT_0x50;
};

struct ResNode {
    enum ResNodeFlags {
        NODE_IS_VISIBLE = 0x100,
    };

    ResCommon<ResNodeData> mNode;

    inline ResNode(
        void* vptr
    )
        : mNode(vptr) {}

    bool IsValid() const { return mNode.IsValid(); }

    u32 GetID() const {
        if (IsValid()) {
            return mNode.ptr()->WORD_0xC;
        }
        return 0;
    }

    void SetVisibility(
        bool visible
    ) {
        if (IsValid()) {
            if (visible) {
                mNode.ptr()->mFlags |= NODE_IS_VISIBLE;
            } else {
                mNode.ptr()->mFlags &= ~NODE_IS_VISIBLE;
            }
        }
    }

    void PatchChrAnmResult(ChrAnmResult*) const;
    void CalcChrAnmResult(ChrAnmResult*) const;
};

} // namespace nw4r::g3d

#endif
