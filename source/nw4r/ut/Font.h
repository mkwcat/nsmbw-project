#pragma once

#include "nw4r/ut/CharStrmReader.h"

namespace nw4r::ut {

struct Font {
    SIZE_ASSERT(0x10);

    static u16 INVALID_CHARACTER_CODE;

public:
    /* VT+0x8 */ [[mkw(0x8007C670)]] virtual ~Font();

private:
    u16 (CharStrmReader::*mReaderFunc)(void*, void*);

#ifdef CLANGD
    u8 FILL(0x0C, 0x10);
#endif
};

} // namespace nw4r::ut
