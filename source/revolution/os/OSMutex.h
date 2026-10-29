#pragma once

#include "OSThread.h"
#include "revolution/types.h"

EXTERN_C_START

struct OSThreadQueue;

struct OSMutex {
    SIZE_ASSERT(0x18);

    /* 0x00 */ OSThreadQueue queue;
    /* 0x08 */ OSThread* thread;
    /* 0x0C */ s32 lock;
    /* 0x10 */ OSMutex* next;
    /* 0x14 */ OSMutex* prev;
};

/* 0x801B2F60 */
void OSInitMutex(OSMutex* mutex);
/* 0x801B2FA0 */
void OSLockMutex(OSMutex* mutex);
/* 0x801B3080 */
void OSUnlockMutex(OSMutex* mutex);
/* 0x801B3150 */
void __OSUnlockAllMutex(OSThread* thread);
/* 0x801B31C0 */
BOOL OSTryLockMutex(OSMutex* mutex);

/* 0x801B3370 */
void OSSignalCond(OSThreadQueue* queue);

EXTERN_C_END
