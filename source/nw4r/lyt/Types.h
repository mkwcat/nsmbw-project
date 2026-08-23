#pragma once

#include <nw4r/math/vec.h>
#include <nw4r/ut/LinkList.h>

namespace nw4r::lyt {

enum VertexColor {
    VERTEXCOLOR_LT,
    VERTEXCOLOR_RT,
    VERTEXCOLOR_LB,
    VERTEXCOLOR_RB,

    VERTEXCOLOR_MAX,
};

namespace detail {

typedef math::VEC2 TexCoord[VERTEXCOLOR_MAX];

class TexCoordAry {
public:
    TexCoordAry();

    void Free();
    void Reserve(u8 num);
    void SetSize(u8 num);
    void Copy(const void* pSrc, u8 num);

    bool IsEmpty() const { return mCap == 0; }

    u8 GetSize() const { return mNum; }

    TexCoord* GetArray() const { return mpData; }

private:
    u8        mCap; // at 0x0
    u8        mNum; // at 0x1
    TexCoord* mpData;
};

struct BitGXNums {
    u32 texMap      : 4; // ( >> 28 ) &  0xF
    u32 texSRT      : 4; // ( >> 24 ) &  0xF
    u32 texCoordGen : 4; // ( >> 20 ) &  0xF
    u32 indSRT      : 2; // ( >> 18 ) &  0x3
    u32 indStage    : 3; // ( >> 15 ) &  0x7
    u32 tevSwap     : 1; // ( >> 14 ) &  0x1
    u32 tevStage    : 5; // ( >>  9 ) & 0x1F
    u32 chanCtrl    : 1; // ( >>  8 ) &  0x1
    u32 matCol      : 1; // ( >>  7 ) &  0x1
    u32 alpComp     : 1; // ( >>  6 ) &  0x1
    u32 blendMode   : 1; // ( >>  5 ) &  0x1
};

template <typename T>
inline bool TestBit(
    T bits, int index
) {
    T mask = 1 << index;
    return bits & mask;
}

template <typename T>
inline void SetBit(
    T* bits, int pos, bool val
) {
    T mask = T(1 << pos);
    *bits  = T((*bits & ~mask)) | (val << pos);
}

template <typename T>
inline T GetBits(
    T bits, int pos, int len
) {
    u32 mask = T(1 << pos);
    return bits & mask;
}

} // namespace detail

struct Size {
    SIZE_ASSERT(0x8);

    constexpr Size()
        : width()
        , height() {}

    constexpr Size(
        f32 w, f32 h
    )
        : width(w)
        , height(h) {}

    /* 0x0 */ f32 width;
    /* 0x4 */ f32 height;
};

class AnimTransform;

class AnimationLink {
    SIZE_ASSERT(0xF);

public:
    inline AnimationLink()
        : mLink() {
        Reset();
    }

    AnimTransform* GetAnimTransform() const { return mAnimTrans; }

    u16 GetIndex() const { return mIdx; }

    void SetIndex(
        u16 val
    ) {
        mIdx = val;
    }

    bool IsEnable() const { return !mbDisable; }

    void SetEnable(
        bool enable
    ) {
        mbDisable = !enable;
    }

    void Reset() { Set(nullptr, 0, false); }

    void Set(
        AnimTransform* pTransform, u16 us, bool b
    ) {
        mAnimTrans = pTransform;
        mIdx       = us;
        mbDisable  = b;
    }

private:
    /* 0x0 */ ut::LinkListNode mLink;
    /* 0x8 */ AnimTransform*   mAnimTrans;
    /* 0xC */ u16              mIdx;
    /* 0xE */ bool             mbDisable;
};

} // namespace nw4r::lyt
