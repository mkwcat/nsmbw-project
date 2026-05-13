#pragma once

EXTERN_C_START

enum NANDResult {
    NAND_RESULT_FATAL_ERROR = -128,
    NAND_RESULT_UNKNOWN     = -64,

    NAND_RESULT_MAXDEPTH    = -16,
    NAND_RESULT_AUTHENTICATION,
    NAND_RESULT_OPENFD,
    NAND_RESULT_NOTEMPTY,
    NAND_RESULT_NOEXISTS,
    NAND_RESULT_MAXFILES,
    NAND_RESULT_MAXFD,
    NAND_RESULT_MAXBLOCKS,
    NAND_RESULT_INVALID,

    NAND_RESULT_EXISTS = -6,
    NAND_RESULT_ECC_CRIT,
    NAND_RESULT_CORRUPT,
    NAND_RESULT_BUSY,
    NAND_RESULT_ALLOC_FAILED,
    NAND_RESULT_ACCESS,

    NAND_RESULT_OK,
};

enum NANDFileType {
    NAND_FILE_TYPE_NONE,
    NAND_FILE_TYPE_FILE,
    NAND_FILE_TYPE_DIR,
};

struct NANDFileInfo {
    SIZE_ASSERT(0x8C);

    /* 0x00 */ s32  fileDescriptor;
    /* 0x04 */ s32  origFd;
    /* 0x08 */ char origPath[64];
    /* 0x48 */ char tmpPath[64];
    /* 0x88 */ u8   accType;
    /* 0x89 */ u8   stage;
    /* 0x8A */ u8   mark;
};

struct NANDCommandBlock {
    SIZE_ASSERT(0xBC);

    /* 0x00 */ void*  userData;
    /* 0x04 */ void*  callback;
    /* 0x08 */ void*  fileInfo;
    /* 0x0C */ void*  bytes;
    /* 0x10 */ void*  inodes;
    /* 0x14 */ void*  status;
    /* 0x18 */ u32    ownerId;
    /* 0x1C */ u16    groupId;
    /* 0x1E */ u8     nextStage;
    /* 0x20 */ u32    attr;
    /* 0x24 */ u32    ownerAcc;
    /* 0x28 */ u32    groupAcc;
    /* 0x2C */ u32    othersAcc;
    /* 0x30 */ u32    num;
    /* 0x34 */ char   absPath[64];
    /* 0x74 */ u32*   length;
    /* 0x78 */ u32*   pos;
    /* 0x7C */ int    state;
    /* 0x80 */ void*  copyBuf;
    /* 0x84 */ u32    bufLength;
    /* 0x88 */ u8*    type;
    /* 0x8C */ u32    uniqNo;
    /* 0x90 */ u32    reqBlocks;
    /* 0x94 */ u32    reqInodes;
    /* 0x98 */ u32*   answer;
    /* 0x9C */ u32    homeBlocks;
    /* 0xA0 */ u32    homeInodes;
    /* 0xA4 */ u32    userBlocks;
    /* 0xA8 */ u32    userInodes;
    /* 0xAC */ u32    workBlocks;
    /* 0xB0 */ u32    workInodes;
    /* 0xB4 */ char** dir;
    /* 0xB8 */ int    simpleFlag;
};

struct NANDBanner {
    SIZE_ASSERT(0xF0A0);

    /* 0x0000 */ u32 signature;
    /* 0x0004 */ u32 flag;
    /* 0x0008 */ u16 iconSpeed;
    /* 0x000A */ u8  reserved[22];
    /* 0x0020 */ u16 comment[2][32];
    /* 0x00A0 */ u8  bannerTexture[0x6000];
    /* 0x60A0 */ u8  iconTexture[8][0x1200];
};

/* 0x801D8620 */
NANDResult NANDCreate(const char* path, u8 perm, u8 attr);

NANDResult NANDOpen(const char* path, NANDFileInfo* file, u8 mode);
NANDResult NANDClose(NANDFileInfo* file);

/* 0x801D8B30 */
NANDResult NANDRead(NANDFileInfo* file, void* data, u32 len);

/* 0x801D8C20 */
NANDResult NANDWrite(NANDFileInfo* file, const void* data, u32 len);

/* 0x801D8D10 */
NANDResult NANDSeek(NANDFileInfo* file, s32 offset, s32 origin);

/* 0x801D9180 */
NANDResult NANDGetLength(NANDFileInfo* info, u32* length);

/* 0x801D9A90 */
NANDResult NANDSimpleSafeOpen(const char* path, NANDFileInfo* outInfo, int, void* buf, u32 bufLen);

/* 0x801DA0A0 */
NANDResult NANDSimpleSafeCancel(NANDFileInfo* info);

/* 0x801D9E50 */
NANDResult NANDSimpleSafeClose(NANDFileInfo* info);

/* 0x801D8920 */
NANDResult NANDDelete(const char* path);

/* 0x801D9110 */
NANDResult NANDMove(const char* from, const char* to);

/* 0x801DAC30 */
NANDResult NANDGetHomeDir(char* out);

/* 0x801DAFB0 */
NANDResult NANDGetType(const char* path, u8* type);

EXTERN_C_END
