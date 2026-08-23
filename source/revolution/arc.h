#pragma once

#define ARC_MAGIC 0x55AA382D

struct ARCHeader {
    SIZE_ASSERT(0x20);

    /* 0x00 */ u32 magic;
    /* 0x04 */ u32 fstOffset;
    /* 0x08 */ u32 fstSize;
    /* 0x0C */ u32 fileStart;
    /* 0x10 */ u8  reserved[0x10];
};

struct ARCHandle {
    SIZE_ASSERT(0x1C);

    /* 0x00 */ void* archiveStartAddr;
    /* 0x04 */ void* FSTStart;
    /* 0x08 */ void* fileStart;
    /* 0x0C */ u32   entryNum;
    /* 0x10 */ char* FSTStringStart;
    /* 0x14 */ u32   FSTLength;
    /* 0x18 */ u32   currDir;
};

struct ARCFileInfo {
    SIZE_ASSERT(0xC);

    /* 0x0 */ ARCHandle* handle;
    /* 0x4 */ u32        startOffset;
    /* 0x8 */ u32        length;
};

struct ARCDir {
    SIZE_ASSERT(0x10);

    /* 0x00 */ ARCHandle* handle;
    /* 0x04 */ u32        entryNum;
    /* 0x08 */ u32        location;
    /* 0x0C */ u32        next;
};

struct ARCDirEntry {
    SIZE_ASSERT(0x10);

    FILL(0x00, 0x04);
    /* 0x04 */ u32   entryNum;
    /* 0x08 */ bool  isDir;
    /* 0x0C */ char* name;
};

struct FstEntry {
    SIZE_ASSERT(0xC);

    u8  isDir        : 8;
    u32 stringOffset : 24;

    struct Dir {
        u32 parent;
        u32 next;
    };

    struct File {
        u32 startAddr;
        u32 length;
    };

    union {
        Dir  dir;
        File file;
    };
};

EXTERN_C_START

bool ARCInitHandle(void* arcStart, ARCHandle* handle);

bool ARCOpen(ARCHandle* handle, const char* fileName, ARCFileInfo* af);

bool ARCFastOpen(ARCHandle* handle, s32 entrynum, ARCFileInfo* af);

s32 ARCConvertPathToEntrynum(ARCHandle* handle, const char* pathPtr);

bool ARCConvertEntrynumToPath(ARCHandle* handle, s32 entrynum, char* path, u32 maxlen);

bool ARCEntrynumIsDir(ARCHandle* handle, s32 entrynum);

void* ARCGetStartAddrInMem(ARCFileInfo* af);

u32 ARCGetStartOffset(ARCFileInfo* af);

u32 ARCGetLength(ARCFileInfo* af);

bool ARCClose(ARCFileInfo* af);

bool ARCChangeDir(ARCHandle* handle, const char* dirName);

bool ARCFastOpenDir(ARCHandle* handle, s32 entrynum, ARCDir* dir);

bool ARCOpenDir(ARCHandle* handle, const char* dirName, ARCDir* dir);

bool ARCReadDir(ARCDir* dir, ARCDirEntry* dirent);

bool ARCCloseDir(ARCDir* dir);

EXTERN_C_END
