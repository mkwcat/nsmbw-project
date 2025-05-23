#ifndef NW4R_G3D_CALC_WORLD_H
#define NW4R_G3D_CALC_WORLD_H

#include "nw4r/g3d/g3d_anmchr.h"
#include "nw4r/g3d/g3d_resmdl.h"
#include "nw4r/math/mtx.h"
#include "nw4r/math/vec.h"
#include "revolution/mtx.h"

namespace nw4r {
namespace g3d {

struct FuncObjCalcWorld {
private:
    u8 UNK_0x00[0x06];
    /** 0x06 */ u16 mNodeId;

public:
    u32 GetNodeId() const {
        return mNodeId;
    }

    void SetNodeId(u32 n) {
        mNodeId = n;
    }
};

class WorldMtxManip {
public:
    void GetMtx(nw4r::math::MTX34 *out) {
        if (out != nullptr) {
            MTXCopy(mpM, out);
        }
    }

    void SetMtx(const nw4r::math::MTX34 *arg) {
        if (arg != nullptr) {
            PSMTXCopy(arg, mpM);
        } else {
            PSMTXIdentity(mpM);
        }
    }

private:
    nw4r::math::MTX34 *mpM;
    nw4r::math::VEC3 *mpS;
    u32 *mpWMAttr;
};

// Name from ketteiban
class ICalcWorldCallback {
public:
    virtual ~ICalcWorldCallback() {}

    virtual void ExecCallbackA(nw4r::g3d::ChrAnmResult *, nw4r::g3d::ResMdl, nw4r::g3d::FuncObjCalcWorld *) {}
    virtual void ExecCallbackB(nw4r::g3d::WorldMtxManip *, nw4r::g3d::ResMdl, nw4r::g3d::FuncObjCalcWorld *) {}
    virtual void ExecCallbackC(nw4r::math::MTX34 *, nw4r::g3d::ResMdl, nw4r::g3d::FuncObjCalcWorld *) {}
};


void CalcWorld(math::MTX34 *, u32 *, const u8 *, const math::MTX34 *, ResMdl, AnmObjChr *, FuncObjCalcWorld *, u32);

void CalcWorld(math::MTX34 *, u32 *, const u8 *, const math::MTX34 *, ResMdl, AnmObjChr *, FuncObjCalcWorld *);

void CalcSkinning(math::MTX34 *, u32 *, ResMdl, const u8 *);
} // namespace g3d
} // namespace nw4r

#endif
