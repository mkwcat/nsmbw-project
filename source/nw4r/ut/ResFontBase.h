#pragma once

#include "Font.h"

namespace nw4r::ut {

class ResFontBase : public Font {
    SIZE_ASSERT(0x1C);

    static u16                         GLYPH_INDEX_NOT_FOUND;

    /* 0x10 */ void*                   mResource;
    /* 0x14 */ struct FontInformation* mFontInfo;
    /* 0x18 */ u16                     mLastCharCode;
    /* 0x1A */ u16                     mLastGlyphIndex;
};

} // namespace nw4r::ut
