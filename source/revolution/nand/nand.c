// nand.c
// NSMBW .text: 0x801D8620 - 0x801D95E0

#include "revolution/nand.h"

EXTERN_C_START

[[nsmbw(0x801D8620)]]
NANDResult NANDCreate(const char* path, u8 perm, u8 attr);

[[nsmbw(0x801D8920)]]
NANDResult NANDDelete(const char* path);

[[nsmbw(0x801D8B30)]]
NANDResult NANDRead(NANDFileInfo* file, void* data, u32 len);

[[nsmbw(0x801D8C20)]]
NANDResult NANDWrite(NANDFileInfo* file, const void* data, u32 len);

[[nsmbw(0x801D8D10)]]
NANDResult NANDSeek(NANDFileInfo* file, s32 offset, s32 origin);

[[nsmbw(0x801D9110)]]
NANDResult NANDMove(const char* from, const char* to);

[[nsmbw(0x801D9180)]]
NANDResult NANDGetLength(NANDFileInfo* info, u32* length);

EXTERN_C_END
