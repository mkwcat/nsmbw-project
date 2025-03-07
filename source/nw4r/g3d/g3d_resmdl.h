#pragma once

#include "g3d_rescommon.h"
#include "g3d_resdict.h"
#include "g3d_resmat.h"
#include "g3d_resnode.h"
#include "g3d_resvtx.h"

namespace nw4r::g3d
{

struct ResFile;
struct ResShp;

enum ResMdlDrawMode {
    RESMDL_DRAWMODE_SORT_OPA_NONE = 0,
    RESMDL_DRAWMODE_SORT_OPA_Z = 1,
    RESMDL_DRAWMODE_SORT_XLU_NONE = 0,
    RESMDL_DRAWMODE_SORT_XLU_Z = 2,
    RESMDL_DRAWMODE_IGNORE_MATERIAL = 4,
    RESMDL_DRAWMODE_FORCE_LIGHTOFF = 8,
    RESMDL_DRAWMODE_NOPPCSYNC = 16,
    RESMDL_DRAWMODE_DEFAULT = 2,
    REDMDL_DRAWMODE_SORT_NONE = 0,
    RESMDL_DRAWMODE_SORT_Z = 3,
};

struct ResMdlData {
    char mMagic[4]; // "MDL0"
    u32 INT_0x4;
    u32 mRevision; // at 0x8
    s32 INT_0xC;
    u32 mByteCodeDictOfs; // at 0x10
    u32 mNodeDictOfs; // at 0x14
    u32 mVtxPosDictOfs; // at 0x18
    u32 mVtxNrmDictOfs; // at 0x1C
    u32 mVtxClrDictOfs; // at 0x20
    u32 mVtxTexCoordDictOfs; // at 0x24
    u32 mMatDictOfs; // at 0x28
    u32 mTevDictOfs; // at 0x2C
    u32 mShpDictOfs; // at 0x30
    u32 mPlttTexInfoOfs; // at 0x34
};

struct ResMdl {
    enum {
        REVISION = 9
    };

    ResCommon<ResMdlData> mMdl;

    inline ResMdl(void* vptr)
      : mMdl(vptr)
    {
    }

    bool IsValid() const
    {
        return mMdl.IsValid();
    }

    u8* GetResByteCode(const char*) const;

    ResNode GetResNode(const char*) const;
    ResNode GetResNode(ResName) const;
    ResNode GetResNode(int) const;
    ResNode GetResNode(u32) const;
    u32 GetResNodeNumEntries() const;

    ResVtxPos GetResVtxPos(ResName) const;
    ResVtxPos GetResVtxPos(int) const;
    ResVtxPos GetResVtxPos(u32) const;
    u32 GetResVtxPosNumEntries() const;

    ResVtxNrm GetResVtxNrm(ResName) const;
    ResVtxNrm GetResVtxNrm(int) const;
    ResVtxNrm GetResVtxNrm(u32) const;
    u32 GetResVtxNrmNumEntries() const;

    ResVtxClr GetResVtxClr(ResName) const;
    ResVtxClr GetResVtxClr(int) const;
    ResVtxClr GetResVtxClr(u32) const;
    u32 GetResVtxClrNumEntries() const;

    ResVtxTexCoord GetResVtxTexCoord(int) const;

    ResMat GetResMat(const char*) const;
    ResMat GetResMat(ResName) const;
    ResMat GetResMat(int) const;
    ResMat GetResMat(u32) const;
    u32 GetResMatNumEntries() const;

    ResShp GetResShp(const char*) const;
    ResShp GetResShp(int) const;
    ResShp GetResShp(u32) const;
    u32 GetResShpNumEntries() const;

    ResTexPlttInfo GetResTexPlttInfoOffsetFromTexName(int) const;
    u32 GetResTexPlttInfoOffsetFromTexNameNumEntries() const;

    bool Bind(ResFile);
    void Release();
    void Init();
    void Terminate();

    inline bool CheckRevision() const
    {
        return mMdl.ref().mRevision == REVISION;
    }

    inline u32 GetResVtxTexCoordNumEntries() const
    {
        ResMdlData& ref = mMdl.ref();
        return mMdl.ofs_to_obj<ResDic>(ref.mVtxTexCoordDictOfs).GetNumData();
    }
};
} // namespace nw4r::g3d
