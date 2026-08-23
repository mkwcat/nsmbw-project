#pragma once

#include <revolution/arc.h>

struct DVDCommandBlock {
    SIZE_ASSERT(0x30);

    FILL(0x00, 0x0C);
    s32 state;
    FILL(0x10, 0x30);
};

struct DVDFileInfo {
    SIZE_ASSERT(0x3C);

    DVDCommandBlock cb;
    u32             startAddr;
    u32             length;
    void*           callback;
};

EXTERN_C_START

void __DVDEXInit(s32 arcEntryNum, ARCHandle* arcHandle);

bool DVDFastOpen(s32 entryNum, DVDFileInfo* fileInfo);

bool DVDOpen(const char* fileName, DVDFileInfo* fileInfo);

bool DVDClose(DVDFileInfo* fileInfo);

s32 __DVDPathToEntrynum(const char* fileName);

bool DVDConvertEntrynumToPath(s32 entrynum, char* path, u32 maxlen);

s32 DVDReadPrio(DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset, s32 prio);

#define DVDRead(fileInfo, addr, length, offset) \
    DVDReadPrio((fileInfo), (addr), (length), (offset), 2)

s32 DVDConvertPathToEntrynum(const char* fileName);

bool DVDEntrynumIsDir(s32 entryNum);

ARCHandle* DVDGetExArcHandle();

s32 DVDGetExArchiveEntrynum();

s32 DVDGetExEntrynum(s32 entrynum);

bool DVDOpenExArc(DVDFileInfo* fileInfo);

EXTERN_C_END
