#pragma once

#include "g3d_anmobj.h"
#include "g3d_resdict.h"

namespace nw4r::g3d {

struct ResFile;

struct TexPatAnmResult;

struct ResAnmTexPatAnmFramesData {
    float mTime;      // at 0x0
    u16   mTexIndex;  // at 0x4
    u16   mPlttIndex; // at 0x6
};

struct ResAnmTexPatAnmData {
    u16                       mCount; // at 0x0
    float                     FLOAT_0x4;
    ResAnmTexPatAnmFramesData mFrames[]; // at 0x8
};

struct ResAnmTexPatMatData {
    char UNK_0x0[0x4];
    u32  mFlags; // at 0x4

    union AnmData {
        struct {
            u16 mTexIndex;  // at 0x0
            u16 mPlttIndex; // at 0x2
        };

        s32 mOffset;
    } mAnms[]; // at 0x8
};

struct ResAnmTexPatData {
    char      UNK_0x0[0x8];
    u32       mRevision; // at 0x8
    char      UNK_0xC[0x4];
    s32       mMatDictOffset;       // at 0x10
    s32       mTexNameArrayOffset;  // at 0x14
    s32       mPlttNameArrayOffset; // at 0x18
    s32       mTexArrayOffset;      // at 0x1c
    s32       mPlttArrayOffset;     // at 0x20
    char      UNK_0x24[0xC];
    u16       mTexCount;  // at 0x30
    u16       mPlttCount; // at 0x32
    char      UNK_0x34[0x4];
    AnmPolicy mAnmPolicy; // at 0x38
};

struct ResAnmTexPat {
    enum {
        REVISION = 3,
    };

    ResCommon<ResAnmTexPatData> mAnmTexPat;

    inline ResAnmTexPat(
        void* vptr
    )
        : mAnmTexPat(vptr) {}

    inline ResAnmTexPatData& ref() const { return mAnmTexPat.ref(); }

    inline bool CheckRevision() const { return ref().mRevision == REVISION; }

    inline const ResAnmTexPatMatData* GetMatAnm(
        u32 i
    ) const {
        return static_cast<const ResAnmTexPatMatData*>(
            mAnmTexPat.ofs_to_obj<ResDic>(ref().mMatDictOffset)[i]
        );
    }

    AnmPolicy GetAnmPolicy() const { return ref().mAnmPolicy; }

    int GetNumFrame() const { return ref().mTexCount; }

    void GetAnmResult(TexPatAnmResult*, u32, float) const;

    bool Bind(ResFile);
    void Release();
};
} // namespace nw4r::g3d
