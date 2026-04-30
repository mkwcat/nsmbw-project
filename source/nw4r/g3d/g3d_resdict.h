#ifndef NW4R_G3D_RESDICT_H
#define NW4R_G3D_RESDICT_H

#include "g3d_rescommon.h"

namespace nw4r
{
namespace g3d
{
struct ResDicNodeData {
    SIZE_ASSERT(0x10);
    u16 ref; // at 0x0
    u16 flag; // at 0x2
    u16 idxLeft; // at 0x4
    u16 idxRight; // at 0x6
    u32 ofsString; // at 0x8
    u32 ofsData; // at 0xC
};

struct ResDicData {
    SIZE_ASSERT(0x18);
    u32 size; // at 0x0
    u32 numData; // at 0x4
    ResDicNodeData data[1]; // 0x8
};

struct ResDic {
    ResCommon<ResDicData> mDict;

    ResDicNodeData* Get(ResName) const;
    ResDicNodeData* Get(const char*, u32) const;
    void* operator[](const char*) const;
    void* operator[](ResName) const;
    s32 GetIndex(ResName) const;

    inline ResDic(void* vptr)
      : mDict(vptr)
    {
    }

    inline void* operator[](int i) const
    {
        if (mDict.IsValid()) {
            return const_cast<void*>(
              static_cast<const void*>(mDict.ofs_to_ptr<void>(mDict.ref().data[i + 1].ofsData))
            );
        }

        return nullptr;
    }

    inline u32 GetNumData() const
    {
        if (mDict.IsValid()) {
            return mDict.ref().numData;
        }

        return 0;
    }
};
} // namespace g3d
} // namespace nw4r

#endif
