#pragma once

#include "m_3d_banm.h"
#include "m_3d_scnleaf.h"
#include "m_math.h"
#include <nw4r/g3d/g3d_resmat.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#include <nw4r/math/mtx.h>
#include <revolution/gx/GXEnum.h>
#include <revolution/gx/GXStruct.h>

namespace m3d {

class bmdl_c : public scnLeaf_c {
    SIZE_ASSERT(0xC);

public:
    bmdl_c()
        : mpCurrentAnm(nullptr) {}

    /* VT+0x08 */ virtual ~bmdl_c();

    /* VT+0x0C */ virtual int getType() const override;
    /* VT+0x10 */ virtual void remove() override;

    /* VT+0x18 */ virtual void setAnm(banm_c& anm);
    /* VT+0x1C */ virtual void play();

    int getMatID(const char* name) const;
    int getNodeID(const char* name) const;
    bool getNodeWorldMtx(u32 p1, nw4r::math::MTX34* out) const;
    bool getNodeWorldMtxMultVecZero(u32 p1, nw4r::math::VEC3& out) const;
    bool getNodeWorldMtxMultVec(u32, nw4r::math::VEC3&, nw4r::math::VEC3&) const;
    nw4r::g3d::ResMdl getResMdl() const;
    nw4r::g3d::ResMat getResMat(u32 index) const;

    void               removeAnm(nw4r::g3d::ScnMdlSimple::AnmObjType);
    nw4r::g3d::AnmObj* getAnmObj(nw4r::g3d::ScnMdlSimple::AnmObjType) const;
    void setTevColor(u32, GXTevRegID, GXColor, bool);
    void setTevColorAll(GXTevRegID, GXColor, bool);
    void setTevKColor(u32, GXTevKColorID, GXColor, bool);
    void setTevKColorAll(GXTevKColorID, GXColor, bool);
    void setBlendModeAll(GXBlendMode, GXBlendFactor, GXBlendFactor, GXLogicOp, bool bMarkDirty);
    void setCullMode(u32 matId, GXCullMode cullMode, bool bMarkDirty);
    void setCullModeAll(GXCullMode cullMode, bool bMarkDirty);
    void setMatVisible(u32 matId, bool bVisble);
    int setMatTexture(char* name, GXTexObj* texObj, bool copy, void* unk, int, int);
    bool getBounds(mVec3_c* min, mVec3_c* max);

private:
    banm_c* mpCurrentAnm;
};

} // namespace m3d
