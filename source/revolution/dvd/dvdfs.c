// dvdfs.c
// NSMBW .text: 0x801CA790 - 0x801CADA0

#include <cstdio>
#include <revolution/arc.h>
#include <revolution/dvd.h>
#include <revolution/os.h>

EXTERN_C_START

static constexpr int DVDEX_ARC_ENTRYNUM_BASE = 800000;

[[nsmbw_data(0x8042ABE4)]]
const char* FstStringStart;

[[nsmbw_data(0x8042ABE8)]]
FstEntry* FstStart;

static s32 s_dvdExArc = -1;
static ARCHandle* s_dvdExArcHandle = nullptr;

// 0x801CA790: __DVDFSInit

void __DVDEXInit(s32 arcEntryNum, ARCHandle* arcHandle)
{
    if (s_dvdExArcHandle != nullptr) {
        return;
    }

    if (arcEntryNum == -1) {
        return;
    }

    s_dvdExArc = arcEntryNum;
    s_dvdExArcHandle = arcHandle;

    bool arcChangeDirOk = ARCChangeDir(s_dvdExArcHandle, "/.");
    ASSERT(arcChangeDirOk);
}

EXTERN_REPL(
  0x801CA7C0, //
  s32 __DVDPathToEntrynum(const char* fileName)
);

[[nsmbw(0x801CA7C0)]]
s32 DVDConvertPathToEntrynum(const char* fileName)
{
    if (s_dvdExArcHandle != nullptr) {
        s32 entryNum =
          ARCConvertPathToEntrynum(s_dvdExArcHandle, *fileName == '/' ? fileName + 1 : fileName);

        if (entryNum != -1) {
            return entryNum + DVDEX_ARC_ENTRYNUM_BASE;
        }
    }

    return __DVDPathToEntrynum(fileName);
}

// UNUSED: DVDEntrynumIsDir

EXTERN_REPL(
  0x801CAAD0, //
  bool __DVDFastOpen(s32 entryNum, DVDFileInfo* fileInfo)
);

[[nsmbw(0x801CAAD0)]]
bool DVDFastOpen(s32 entryNum, DVDFileInfo* fileInfo)
{
    if (s_dvdExArcHandle == nullptr || entryNum < DVDEX_ARC_ENTRYNUM_BASE) {
        return __DVDFastOpen(entryNum, fileInfo);
    }

    // Regular file replacement
    s32 arcEntryNum = entryNum - DVDEX_ARC_ENTRYNUM_BASE;

    ARCFileInfo af;
    bool ret = ARCFastOpen(s_dvdExArcHandle, arcEntryNum, &af);

    if (!ret) {
        return false;
    }

    ret = __DVDFastOpen(s_dvdExArc, fileInfo);

    if (!ret) {
        return false;
    }

    fileInfo->startAddr += ARCGetStartOffset(&af) >> 2;
    fileInfo->length = ARCGetLength(&af);

    return true;
}

bool DVDOpen(const char* fileName, DVDFileInfo* fileInfo)
{
    s32 entryNum = DVDConvertPathToEntrynum(fileName);

    if (entryNum == -1) {
        return false;
    }

    return DVDFastOpen(entryNum, fileInfo);
}

[[nsmbw(0x801CAB40)]]
bool DVDClose(DVDFileInfo* fileInfo);

// UNUSED: entryToPath

// From Double Dash Deluxe:
// https://github.com/doubledashdeluxe/ddd/blob/d7eed424d55f926f2fc6f65b476815942562c7f5/payload/dolphin/DVD.c#L75
// SPDX-License-Identifier: MIT
static bool __DVDEntrynumToPath(s32 entrynum, char* path, u32 maxlen)
{
    u32 len = 0;
    for (u32 location = 1; location != u32(entrynum);) {
        if (!FstStart[location].isDir) {
            location++;
            continue;
        }
        if ((s32) FstStart[location].dir.next <= entrynum) {
            location = FstStart[location].dir.next;
            continue;
        }
        const char* name = FstStringStart + FstStart[location].stringOffset;
        len += (u32) std::snprintf(path + len, maxlen - len, "%s/", name);
        if (len >= maxlen) {
            return false;
        }
        location++;
    }
    const char* name = FstStringStart + FstStart[entrynum].stringOffset;
    const char* format = FstStart[entrynum].isDir ? "%s/" : "%s";
    len += (u32) std::snprintf(path + len, maxlen - len, format, name);
    if (len >= maxlen) {
        return false;
    }
    return true;
}

bool DVDConvertEntrynumToPath(s32 entrynum, char* path, u32 maxlen)
{
    if (s_dvdExArcHandle != nullptr && entrynum >= DVDEX_ARC_ENTRYNUM_BASE) {
        return ARCConvertEntrynumToPath(
          s_dvdExArcHandle, entrynum - DVDEX_ARC_ENTRYNUM_BASE, path, maxlen
        );
    }

    return __DVDEntrynumToPath(entrynum, path, maxlen);
}

// UNUSED: DVDGetCurrentDir

// UNUSED: DVDChangeDir

[[nsmbw(0x801CAB70)]]
void DVDReadAsyncPrio();

[[nsmbw(0x801CAC40)]]
/* static */ void cbForReadAsync();

[[nsmbw(0x801CAC60)]]
s32 DVDReadPrio(DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset, s32 prio);

[[nsmbw(0x801CAD90)]]
/* static */ void cbForReadSync();

// UNUSED: DVDSeekAsyncPrio

// UNUSED: cbForSeekAsync

// UNUSED: DVDSeekPrio

// UNUSED: cbForSeekSync

// UNUSED: DVDGetFileInfoStatus

// UNUSED: DVDFastOpenDir

// UNUSED: DVDOpenDir

// UNUSED: DVDReadDir

// UNUSED: DVDCloseDir

// UNUSED: DVDRewindDir

// UNUSED: DVDGetFSTLocation

// UNUSED: DVDGetTransferredSize

// UNUSED: DVDGetEntrynum

// UNUSED: DVDGetEntryName

bool DVDEntrynumIsDir(s32 entryNum)
{
    if (s_dvdExArcHandle != nullptr && entryNum >= DVDEX_ARC_ENTRYNUM_BASE) {
        return ARCEntrynumIsDir(s_dvdExArcHandle, entryNum - DVDEX_ARC_ENTRYNUM_BASE);
    }

    return FstStart[entryNum].isDir;
}

ARCHandle* DVDGetExArcHandle()
{
    return s_dvdExArcHandle;
}

s32 DVDGetExArchiveEntrynum()
{
    return s_dvdExArc;
}

s32 DVDGetExEntrynum(s32 entrynum)
{
    if (s_dvdExArcHandle == nullptr) {
        return -1;
    }

    if (entrynum < DVDEX_ARC_ENTRYNUM_BASE) {
        return -1;
    }

    return entrynum - DVDEX_ARC_ENTRYNUM_BASE;
}

EXTERN_C_END
