#pragma once

#include "OSContext.h"
#include "revolution/types.h"

EXTERN_C_START

#define OS_PRIORITY_MIN 0
#define OS_PRIORITY_MAX 31

enum OSThreadState {
    OS_THREAD_STATE_EXITED = 0,
    OS_THREAD_STATE_READY = 1,
    OS_THREAD_STATE_RUNNING = 2,
    OS_THREAD_STATE_SLEEPING = 4,
    OS_THREAD_STATE_MORIBUND = 8
};

enum OSThreadFlags {
    OS_THREAD_NO_FLAGS = 0,
    OS_THREAD_DETACHED = 0_bit,
};

struct OSThread;

struct OSThreadQueue {
    SIZE_ASSERT(0x8);

    /* 0x0 */ OSThread* head;
    /* 0x4 */ OSThread* tail;
};

struct OSMutex;

struct OSMutexQueue {
    SIZE_ASSERT(0x8);

    /* 0x0 */ OSMutex* head;
    /* 0x4 */ OSMutex* tail;
};

struct OSThread {
    SIZE_ASSERT(0x318);

    /* 0x000 */ OSContext context;
    /* 0x2C8 */ u16 state;
    /* 0x2CA */ u16 flags;
    /* 0x2CC */ s32 suspend;
    /* 0x2D0 */ s32 priority;
    /* 0x2D4 */ s32 base;
    /* 0x2D8 */ u32 val;
    /* 0x2DC */ OSThreadQueue* queue;
    /* 0x2E0 */ OSThread* next;
    /* 0x2E4 */ OSThread* prev;
    /* 0x2E8 */ OSThreadQueue joinQueue;
    /* 0x2F0 */ OSMutex* mutex;
    /* 0x2F4 */ OSMutexQueue mutexQueue;
    /* 0x2FC */ OSThread* nextActive;
    /* 0x300 */ OSThread* prevActive;
    /* 0x304 */ void* stackBegin;
    /* 0x308 */ void* stackEnd;
    /* 0x30C */ s32 error;
    /* 0x310 */ void* specific[2];
};

typedef void (*OSSwitchThreadCallback)(OSThread* currThread, OSThread* newThread);
typedef void* (*OSThreadFunc)(void* arg);

OSSwitchThreadCallback OSSetSwitchThreadCallback(OSSwitchThreadCallback callback);
void __OSThreadInit(void);
void OSSetCurrentThread(OSThread* thread);
void OSInitMutexQueue(OSMutexQueue* queue);
void OSInitThreadQueue(OSThreadQueue* queue);
OSThread* OSGetCurrentThread(void);
BOOL OSIsThreadTerminated(OSThread* thread);
s32 OSDisableScheduler(void);
s32 OSEnableScheduler(void);
s32 __OSGetEffectivePriority(OSThread* thread);
void __OSPromoteThread(OSThread* thread, s32 prio);
void __OSReschedule(void);
void OSYieldThread(void);
BOOL OSCreateThread(
  OSThread* thread, OSThreadFunc func, void* funcArg, void* stackBegin, u32 stackSize, s32 prio,
  u16 flags
);
void OSExitThread(OSThread* thread);
void OSCancelThread(OSThread* thread);
BOOL OSJoinThread(OSThread* thread, void* val);
void OSDetachThread(OSThread* thread);
s32 OSResumeThread(OSThread* thread);
s32 OSSuspendThread(OSThread* thread);
void OSSleepThread(OSThreadQueue* queue);
void OSWakeupThread(OSThreadQueue* queue);
BOOL OSSetThreadPriority(OSThread* thread, s32 prio);
void OSClearStack(u8 val);
void OSSleepTicks(s64 ticks);

EXTERN_C_END
