#pragma once

#include "nw4r/ut/Color.h"
#include <revolution/gx/GXStruct.h>

namespace nw4r::lyt
{

namespace res
{

constexpr u32 PANE_NAME_SIZE = 16;
constexpr u32 PANE_USERDATA_SIZE = 8;
constexpr u32 ANIMTARGET_PANE_MAX = 10;
constexpr u32 MATERIAL_NAME_SIZE = 20;
constexpr u32 NW4R_RES_NAME_SIZE  = 16;
constexpr u32 NW4R_MAT_NAME_SIZE  = 20;

constexpr u32 TEXCOORD_VTX_COUNT = 4;

struct DataBlockHeader {
    SIZE_ASSERT(0x8);

    /* 0x0 */ char kind[4];
    /* 0x4 */ u32 size;
};

struct TextureList {
    SIZE_ASSERT(0xC);

    /* 0x0 */ res::DataBlockHeader blockHeader;
    /* 0x8 */ u16 texNum;
    /* 0xA */ u16 padding = 0;
};

struct Font {
    SIZE_ASSERT(0x8);

    /* 0x0 */ u32 nameStrOffset;
    /* 0x4 */ u8 type;
    /* 0x5 */ u8 padding[3] = {};
};

struct FontList {
    SIZE_ASSERT(0xC);

    /* 0x0 */ res::DataBlockHeader blockHeader;
    /* 0x8 */ u16 fontNum;
    /* 0xA */ u16 padding = 0;
};

struct MaterialList {
    SIZE_ASSERT(0xC);

    /* 0x0 */ res::DataBlockHeader blockHeader;
    /* 0x8 */ u16 materialNum;
    /* 0xA */ u16 padding = 0;
};

struct ExtUserDataList {
    SIZE_ASSERT(0xC);

    /* 0x0 */ DataBlockHeader blockHeader;
    /* 0x8 */ u16 num;
    /* 0xA */ u16 padding = 0;
};

} // namespace res

class ResourceAccessor;

struct ResBlockSet {
    SIZE_ASSERT(0x10);

    /* 0x00 */ const res::TextureList* pTextureList; // at 0x0
    /* 0x04 */ const res::FontList* pFontList; // at 0x4
    /* 0x08 */ const res::MaterialList* pMaterialList; // at 0x8
    /* 0x0C */ ResourceAccessor* pResAccessor; // at 0xC
};

} // namespace nw4r::lyt
