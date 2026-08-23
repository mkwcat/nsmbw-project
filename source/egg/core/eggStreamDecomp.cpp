// eggStreamDecomp.cpp
// NSMBW .text: 0x802B8560 - 0x802B8BB0

#include "eggStreamDecomp.h"

namespace EGG {

[[nsmbw(0x802B8560)]]
bool StreamDecompLZ::init(void* dst, u32 maxCompressedSize);

[[nsmbw(0x802B8590)]]
bool StreamDecompLZ::decomp(const void* src, u32 size);

[[nsmbw(0x802B85C0)]]
bool StreamDecompRL::init(void* dst, u32 maxCompressedSize);

[[nsmbw(0x802B85F0)]]
bool StreamDecompRL::decomp(const void*, u32);

[[nsmbw(0x802B8620)]]
bool StreamDecompLH::init(void* dst, u32 maxCompressedSize);

[[nsmbw(0x802B8650)]]
bool StreamDecompLH::decomp(const void*, u32);

[[nsmbw(0x802B8680)]]
bool StreamDecompLRC::init(void* dst, u32 maxCompressedSize);

[[nsmbw(0x802B86B0)]]
bool StreamDecompLRC::decomp(const void*, u32);

[[nsmbw(0x802B86E0)]]
/* static */ u32 SZS_GetUncompressedSize(const void* src);

struct SZSContext;

[[nsmbw(0x802B8710)]]
/* static */ void SZSContext_init(SZSContext* ctx);

[[nsmbw(0x802B8740)]]
/* static */ u32 SZS_0x802B8740();

[[nsmbw(0x802B8840)]]
/* static */ s32 SZSContext_decompSZS(SZSContext* ctx, const void* src, u32 size);

[[nsmbw(0x802B8AB0)]]
bool StreamDecompSZS::init(void* dst, u32 maxCompressedSize);

[[nsmbw(0x802B8AE0)]]
bool StreamDecompSZS::decomp(const void*, u32);

[[nsmbw(0x802B8B10)]]
u32 StreamDecompSZS::getUncompressedSize(const void* src);

[[nsmbw(0x802B8B20)]]
u32 StreamDecompSZS::getHeaderSize();

[[nsmbw(0x802B8B30)]]
u32 StreamDecompLRC::getUncompressedSize(const void* src);

[[nsmbw(0x802B8B40)]]
u32 StreamDecompLRC::getHeaderSize();

[[nsmbw(0x802B8B50)]]
u32 StreamDecompLH::getUncompressedSize(const void* src);

[[nsmbw(0x802B8B60)]]
u32 StreamDecompLH::getHeaderSize();

[[nsmbw(0x802B8B70)]]
u32 StreamDecompRL::getUncompressedSize(const void* src);

[[nsmbw(0x802B8B80)]]
u32 StreamDecompRL::getHeaderSize();

[[nsmbw(0x802B8B90)]]
u32 StreamDecompLZ::getUncompressedSize(const void* src);

[[nsmbw(0x802B8BA0)]]
u32 StreamDecompLZ::getHeaderSize();

} // namespace EGG
