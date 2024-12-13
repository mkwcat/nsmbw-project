#pragma once

#include <revolution/gx/GXEnum.h>
#include <revolution/gx/GXStruct.h>
#include <revolution/tpl.h>

namespace nw4r::lyt
{

namespace detail
{

inline bool IsCITexelFormat(GXCITexFmt fmt)
{
    return (fmt == GX_TF_C4 || fmt == GX_TF_C8 || fmt == GX_TF_C14X2);
}

} // namespace detail

class TexMap
{
    SIZE_ASSERT(0x1C);

public:
    TexMap(TPLPalette* pTPLPalette, u32 id)
    {
        Set(pTPLPalette, id);
    }

    TexMap()
    {
        mpImage = nullptr;
        mWidth = 0;
        mHeight = 0;

        mBits.textureFormat = 0;
        mBits.mipmap = 0;

        mBits.wrapS = 0;
        mBits.wrapT = 0;
        mBits.minFilter = 1;
        mBits.magFilter = 1;

        mMinLOD = 0.0f;
        mMaxLOD = 0.0f;
        mLODBias = 0;
        mBits.biasClampEnable = 0;
        mBits.edgeLODEnable = 0;

        mpPalette = nullptr;
        mBits.anisotropy = 0;
        mBits.paletteFormat = 0;
        mPaletteEntryNum = 0;
    }

    void Get(GXTexObj*) const;
    void Get(GXTlutObj*) const;

    void Set(const TexMap& t)
    {
        *this = t;
    }

     void Set(const GXTexObj&);
    void Set(const GXTlutObj&);
    void Set(TPLPalette*, u32);
    void Set(const TPLDescriptor*);

    void ReplaceImage(const TexMap&);
    void ReplaceImage(const GXTexObj&);
    void ReplaceImage(TPLPalette*, u32);
    void ReplaceImage(const TPLDescriptor*);

    void SetNoWrap(const TexMap&);
    void SetNoWrap(const GXTexObj&);
    void SetNoWrap(TPLPalette*, u32);
    void SetNoWrap(const TPLDescriptor*);

    void SetTexParam(
      void* pImage, u16 width, u16 height, GXTexFmt format, GXTexWrapMode wrapS,
      GXTexWrapMode wrapT, bool
    );

    void* GetImage() const
    {
        return mpImage;
    }

    void SetImage(void* img)
    {
        mpImage = img;
    }

    void* GetPalette() const
    {
        return mpPalette;
    }

    void SetPalette(void* pal)
    {
        mpPalette = pal;
    }

    u16 GetWidth() const
    {
        return mWidth;
    }

    u16 GetHeight() const
    {
        return mHeight;
    }

    void SetSize(u16 w, u16 h)
    {
        mWidth = w;
        mHeight = h;
    }

    f32 GetMinLOD() const
    {
        return mMinLOD;
    }

    f32 GetMaxLOD() const
    {
        return mMaxLOD;
    }

    void SetLOD(f32 min, f32 max)
    {
        mMinLOD = min;
        mMaxLOD = max;
    }

    f32 GetLODBias() const
    {
        return mLODBias / 256.0f;
    }

    void SetLODBias(f32 val)
    {
        mLODBias = u16(val * 256.0f);
    }

    u16 GetPaletteEntryNum() const
    {
        return mPaletteEntryNum;
    }

    void SetPaletteEntryNum(u16 num)
    {
        mPaletteEntryNum = num;
    }

    GXTexFmt GetTexelFormat() const
    {
        return (GXTexFmt) mBits.textureFormat;
    }

    void SetTexelFormat(GXTexFmt fmt)
    {
        mBits.textureFormat = fmt;
    }

    bool IsMipMap() const
    {
        return mBits.mipmap;
    }

    void SetMipMap(bool b)
    {
        mBits.mipmap = b;
    }

    GXTexWrapMode GetWrapModeS() const
    {
        return (GXTexWrapMode) mBits.wrapS;
    }

    GXTexWrapMode GetWrapModeT() const
    {
        return (GXTexWrapMode) mBits.wrapT;
    }

    void SetWrapMode(GXTexWrapMode wrapS, GXTexWrapMode wrapT)
    {
        mBits.wrapS = wrapS;
        mBits.wrapT = wrapT;
    }

    GXTexFilter GetMinFilter() const
    {
        return (GXTexFilter) mBits.minFilter;
    }

    GXTexFilter GetMagFilter() const
    {
        return (GXTexFilter) mBits.magFilter;
    }

    void SetFilter(GXTexFilter minFlt, GXTexFilter magFlt)
    {
        mBits.minFilter = minFlt;
        mBits.magFilter = magFlt;
    }

    bool IsBiasClampEnable() const
    {
        return mBits.biasClampEnable;
    }

    void SetBiasClampEnable(bool b)
    {
        mBits.biasClampEnable = b;
    }

    bool IsEdgeLODEnable() const
    {
        return mBits.edgeLODEnable;
    }

    void SetEdgeLODEnable(bool b)
    {
        mBits.edgeLODEnable = b;
    }

    GXAnisotropy GetAnisotropy() const
    {
        return (GXAnisotropy) mBits.anisotropy;
    }

    void SetAnisotropy(GXAnisotropy a)
    {
        mBits.anisotropy = a;
    }

    GXTlutFmt GetPaletteFormat() const
    {
        return (GXTlutFmt) mBits.paletteFormat;
    }

    void SetPaletteFormat(GXTlutFmt fmt)
    {
        mBits.paletteFormat = fmt;
    }

private:
    /* 0x00 */ void* mpImage; 
    /* 0x04 */ void* mpPalette; 
    /* 0x08 */ u16 mWidth;
    /* 0x0A */ u16 mHeight;
    /* 0x0C */ f32 mMinLOD;
    /* 0x10 */ f32 mMaxLOD;
    /* 0x14 */ u16 mLODBias; 
    /* 0x16 */ u16 mPaletteEntryNum;

    /* 0x18 */ struct {
        u32 textureFormat : 4; // (>> 28) & 0xF : GXTexFmt
        u32 mipmap : 1; // (>> 27) & 0x1 : bool
        u32 wrapS : 2; // (>> 25) & 0x3 : GXTexWrapMode
        u32 wrapT : 2; // (>> 23) & 0x3 : GXTexWrapMode
        u32 minFilter : 3; // (>> 20) & 0x7 : GXTexFilter
        u32 magFilter : 1; // (>> 19) & 0x1 : GXTexFilter
        u32 biasClampEnable : 1; // (>> 18) & 0x1 : bool
        u32 edgeLODEnable : 1; // (>> 17) & 0x1 : bool
        u32 anisotropy : 2; // (>> 15) & 0x3 : GXAnisotropy
        u32 paletteFormat : 2; // (>> 13) & 0x3 : GXTlutFmt
    } mBits;
};

} // namespace nw4r::lyt