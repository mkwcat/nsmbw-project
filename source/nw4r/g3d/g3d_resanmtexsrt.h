#pragma once

#include "g3d_resanm.h"
#include "g3d_resdict.h"
#include "g3d_anmobj.h"

namespace nw4r::g3d
{

struct TexSrtAnmResult;

struct ResAnmTexSrtTexData {
    u32 mFlags; // at 0x0
    ResAnmData mAnms[]; // at 0x4
};

struct ResAnmTexSrtMatData {
    char UNK_0x0[0x4];
    u32 FLAGS_0x4;
    u32 FLAGS_0x8;
    s32 mTexOffsets[]; // at 0xc
};

struct ResAnmTexSrtData {
    char UNK_0x0[0x8];
    u32 mRevision; // at 0x8
    char UNK_0xC[0x4];
    s32 mMatDictOffset; // at 0x10
    char UNK_0x14[0x0C];
    u16 mNumFrames; // at 0x20
    u32 UNK_0x24;
    AnmPolicy mAnmPolicy; // at 0x28
};

struct ResAnmTexSrt {
    enum {
        REVISION = 4
    };

    ResCommon<ResAnmTexSrtData> mAnmTexSrt;

    inline ResAnmTexSrt(void* vptr)
      : mAnmTexSrt(vptr)
    {
    }

    inline ResAnmTexSrtData& ref() const
    {
        return mAnmTexSrt.ref();
    }

    inline bool CheckRevision() const
    {
        return mAnmTexSrt.ref().mRevision == REVISION;
    }

    inline const ResAnmTexSrtMatData* GetMatAnm(u32 i) const
    {
        return static_cast<const ResAnmTexSrtMatData*>(
          mAnmTexSrt.ofs_to_obj<ResDic>(ref().mMatDictOffset)[i]
        );
    }

    AnmPolicy GetAnmPolicy() const
    {
        return ref().mAnmPolicy;
    }

    int GetNumFrame() const
    {
        return ref().mNumFrames;
    }

    void GetAnmResult(TexSrtAnmResult*, u32, float) const;
};

} // namespace nw4r::g3d
