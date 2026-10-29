#pragma once

#include <revolution/arc.h>

typedef void (*DVDCBCallback)(int, struct DVDCommandBlock*);

struct DVDDiskID {
    SIZE_ASSERT(0x20);

    /* 0x00 */ char gameName[4];
    /* 0x04 */ char company[2];
    /* 0x06 */ u8   diskNumber;
    /* 0x07 */ u8   gameVersion;
    /* 0x08 */ u8   streaming;
    /* 0x09 */ u8   streamingBufSize;
    /* 0x0A */ u8   padding[22];
};

struct DVDCommandBlock {
    SIZE_ASSERT(0x30);

    /* 0x00 */ DVDCommandBlock* next;
    /* 0x04 */ DVDCommandBlock* prev;
    /* 0x08 */ u32              command;
    /* 0x0C */ s32              state;
    /* 0x10 */ u32              offset;
    /* 0x14 */ u32              length;
    /* 0x18 */ void*            addr;
    /* 0x1C */ u32              currTransferSize;
    /* 0x20 */ u32              transferredSize;
    /* 0x24 */ DVDDiskID*       id;
    /* 0x28 */ DVDCBCallback    callback;
    /* 0x2C */ void*            userData;
};

struct DVDFileInfo {
    SIZE_ASSERT(0x3C);

    /* 0x00 */ DVDCommandBlock cb;
    /* 0x30 */ u32             startAddr;
    /* 0x34 */ u32             length;
    /* 0x3C */ void*           callback;
};

enum {
    DVD_STATE_FATAL         = -1,
    DVD_STATE_IDLE          = 0,
    DVD_STATE_BUSY          = 1,
    DVD_STATE_WAITING       = 2,
    DVD_STATE_COVER_CLOSED  = 3,
    DVD_STATE_NO_DISK       = 4,
    DVD_STATE_COVER_OPENED  = 5,
    DVD_STATE_WRONG_DISK_ID = 6,
    DVD_STATE_7             = 7,
    DVD_STATE_PAUSED        = 8,
    DVD_STATE_9             = 9,
    DVD_STATE_CANCELED      = 10,
    DVD_STATE_DISK_ERROR    = 11,
    DVD_STATE_MOTOR_STOPPED = 12,
};

EXTERN_C_START

void DVDPatchInit(s32 arcEntryNum, void* arcStart);

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
