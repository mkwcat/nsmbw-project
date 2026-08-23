#pragma once

#include "Resources.h"
#include "TexMap.h"
#include "Types.h"
#include <nw4r/ut/Color.h>
#include <nw4r/ut/LinkList.h>

namespace nw4r::lyt {

namespace res {
struct Material {
    SIZE_ASSERT(0x40);

    /* 0x00 */ char               materialName[0x14];
    /* 0x14 */ nw4r::ut::ColorS10 foreColor; // RGBA
    /* 0x1C */ nw4r::ut::ColorS10 backColor; // RGBA
    /* 0x24 */ nw4r::ut::ColorS10 colorReg3; // RGBA
    /* 0x2C */ nw4r::ut::Color    tevColor1; // RGBA
    /* 0x30 */ nw4r::ut::Color    tevColor2; // RGBA
    /* 0x34 */ nw4r::ut::Color    tevColor3; // RGBA
    /* 0x38 */ nw4r::ut::Color    tevColor4; // RGBA
    /* 0x3C */ u32                flags;
};
} // namespace res

class TexMap;
class TexSRT;
class TexCoordGen;
class ChanCtrl;
class TevSwapMode;
class AlphaCompare;
class BlendMode;
class IndirectStage;
class TevStage;

class Material {
    SIZE_ASSERT(0x5A);

public:
    // Instance Methods
    // ^^^^^^

    const TexMap* GetTexMapAry() const;

    [[nsmbw(0x802B3440)]]
    TexMap* GetTexMapAry();

    const TexSRT* GetTexSRTAry() const;
    TexSRT* GetTexSRTAry();
    const TexCoordGen* GetTexCoordGenAry() const;
    TexCoordGen* GetTexCoordGenAry();
    const ChanCtrl* GetChanCtrlAry() const;
    ChanCtrl* GetChanCtrlAry();
    const ut::Color* GetMatColAry() const;
    ut::Color* GetMatColAry();
    const TevSwapMode* GetTevSwapAry() const;
    TevSwapMode* GetTevSwapAry();
    const AlphaCompare* GetAlphaComparePtr() const;
    AlphaCompare* GetAlphaComparePtr();
    const BlendMode* GetBlendModePtr() const;
    BlendMode* GetBlendModePtr();
    const IndirectStage* GetIndirectStageAry() const;
    IndirectStage* GetIndirectStageAry();
    const TexSRT* GetIndTexSRTAry() const;
    TexSRT* GetIndTexSRTAry();
    const TevStage* GetTevStageAry() const;
    TevStage* GetTevStageAry();

public:
    // Inline Functions
    // ^^^^^^

    bool IsBlendModeCap() const { return mGXMemCap.blendMode; }

    bool IsAlphaCompareCap() const { return mGXMemCap.alpComp; }

    bool IsTevSwapCap() const { return mGXMemCap.tevSwap; }

    bool IsMatColorCap() const { return mGXMemCap.matCol; }

    bool IsChanCtrlCap() const { return mGXMemCap.chanCtrl; }

#if 0
    void SetTexSRTElement(u32 texSRTIdx, u32 eleIdx, f32 value) {
        f32 *srtAry = (f32 *)&(GetTexSRTAry()[texSRTIdx]);
        srtAry[eleIdx] = value;
    }
#endif

    TexMap* GetTexturePtr(
        u8 idx
    ) {
        return &GetTexMapAry()[idx];
    }

    u8 GetTexSRTCap() const { return mGXMemCap.texSRT; }

    u8 GetIndTexSRTCap() const { return mGXMemCap.indSRT; }

#if 0
    void SetIndTexSRTElement(u32 texSRTIdx, u32 eleIdx, f32 value) {
        f32 *srtAry = (f32 *)&(GetIndTexSRTAry()[texSRTIdx]);
        srtAry[eleIdx] = value;
    }
#endif

    ut::LinkList<AnimationLink, 0>* GetAnimationList() { return &mAnimList; }

    bool IsUserAllocated() const { return mbUserAllocated; }

    const char* GetName() const { return mName; }

    u8 GetTexCoordGenCap() const { return mGXMemCap.texCoordGen; }

    u8 GetTexCoordGenNum() const { return mGXMemNum.texCoordGen; }

    u8 GetTextureCap() const { return mGXMemCap.texMap; }

    u8 GetTextureNum() const { return mGXMemNum.texMap; }

    GXColorS10 GetTevColor(
        u32 idx
    ) const {
        return mTevCols[idx];
    }

    ut::Color GetTevKColor(
        u32 idx
    ) const {
        return mTevKCols[idx];
    }

    void SetTexture(
        u32 texMapIdx, const TexMap& texMap
    ) {
        GetTexMapAry()[texMapIdx] = texMap;
    }

#if 0
    void SetTexCoordGen(u32 idx, TexCoordGen value) {
        GetTexCoordGenAry()[idx] = value;
    }
#endif

    void SetTevColor(
        u32 idx, const GXColorS10& color
    ) {
        mTevCols[idx] = color;
    }

#if 0
    void SetAlphaCompare(const AlphaCompare &alphaComp) {
        *GetAlphaComparePtr() = alphaComp;
    }

    void SetChanControl(u32 idx, const ChanCtrl &chanCtrl) {
        GetChanCtrlAry()[idx] = chanCtrl;
    }
#endif

    void SetTevKColor(
        u32 idx, const ut::Color& color
    ) {
        mTevKCols[idx] = color;
    }

#if 0
    void SetTevSwapMode(u32 idx, const TevSwapMode &tevSwapMode) {
        GetTevSwapAry()[idx] = tevSwapMode;
    }

    void SetTexSRT(u32 idx, const TexSRT &texSRT) {
        GetTexSRTAry()[idx] = texSRT;
    }

    void SetIndirectStage(u32 idx, const IndirectStage &indStage) {
        GetIndirectStageAry()[idx] = indStage;
    }


    void SetBlendMode(const BlendMode &blendMode) {
        *GetBlendModePtr() = blendMode;
    }

    void SetTevStage(u32 idx, const TevStage &tevStage) {
        GetTevStageAry()[idx] = tevStage;
    }
#endif

protected:
    // Instance Variables
    // ^^^^^^

    FILL(0x00, 0x04);

    /* 0x04 */ ut::LinkList<AnimationLink, 0> mAnimList;
    /* 0x10 */ GXColorS10                     mTevCols[3];
    /* 0x28 */ ut::Color                      mTevKCols[4];
    /* 0x38 */ detail::BitGXNums              mGXMemCap;
    /* 0x3C */ detail::BitGXNums              mGXMemNum;
    /* 0x40 */ void*                          mpGXMem;
    /* 0x44 */ char                           mName[res::MATERIAL_NAME_SIZE + 1];
    /* 0x59 */ bool                           mbUserAllocated;
};

} // namespace nw4r::lyt
