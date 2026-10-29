#pragma once

#include "revolution/os/OSThread.h"

EXTERN_C_START

typedef void* OSMessage;

typedef struct OSMessageQueue {
    SIZE_ASSERT(0x20);
    /* 0x00 */ OSThreadQueue queueSend;
    /* 0x08 */ OSThreadQueue queueReceive;
    /* 0x10 */ OSMessage*    msgArray;
    /* 0x14 */ int           msgCount;
    /* 0x18 */ int           firstIndex;
    /* 0x1C */ int           usedCount;
} OSMessageQueue;

enum {
    OS_MESSAGE_BLOCKING = 1 << 0,
};

[[mkw(0x801A72FC)]]
void OSInitMessageQueue(OSMessageQueue* queue, OSMessage* msgArray, int msgCount);
[[mkw(0x801A735C)]]
BOOL OSSendMessage(OSMessageQueue* queue, OSMessage msg, u32 flags);
[[mkw(0x801A7424)]]
BOOL OSReceiveMessage(OSMessageQueue* queue, OSMessage* msg, u32 flags);
[[mkw(0x801A7500)]]
BOOL OSJamMessage(OSMessageQueue* queue, OSMessage msg, u32 flags);

EXTERN_C_END
