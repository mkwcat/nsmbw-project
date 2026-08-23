#pragma once

namespace nw4r::ut {

struct BinaryBlockHeader {
    SIZE_ASSERT(0x8);
    /* 0x0 */ u32 magic;
    /* 0x4 */ u32 length;
};

struct BinaryFileHeader {
    SIZE_ASSERT(0x10);
    /* 0x00 */ u32 magic;
    /* 0x04 */ u16 byteOrder;
    /* 0x06 */ u16 version;
    /* 0x08 */ u32 fileSize;
    /* 0x0C */ u16 headerSize;
    /* 0x0E */ u16 numBlocks;
};

bool IsValidBinaryFile(const BinaryFileHeader* header, u32 magic, u16 version, u16 numBlocks);

} // namespace nw4r::ut
