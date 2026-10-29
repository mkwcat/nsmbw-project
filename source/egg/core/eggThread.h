#pragma once

#include <nw4r/ut/List.h>
#include <revolution/os.h>

namespace EGG {

// Forward declarations
class Heap;

class Thread {
    SIZE_ASSERT(0x48);

public:
    [[mkw(0x802435A4)]] static void initialize();
    static Thread* findThread(OSThread* pOSThread);

    [[mkw(0x802432E0)]] Thread(u32 stackSize, int capacity, int priority, Heap* pHeap = nullptr);
    [[mkw(0x802433AC)]] Thread(OSThread* pOSThread, int capacity);

    /* VT+0x08 */ virtual ~Thread();

    /* VT+0x0C */ virtual void* run() { return nullptr; }

    /* VT+0x10 */ virtual void onEnter() {}

    /* VT+0x14 */ virtual void onExit() {}

    void resume() { OSResumeThread(mOSThread); }

    bool sendMessage(
        OSMessage msg
    ) {
        return OSSendMessage(&mMesgQueue, msg, 0);
    }

    bool jamMessage(
        OSMessage msg
    ) {
        return OSJamMessage(&mMesgQueue, msg, 0);
    }

    OSMessage waitMessage(
        BOOL* pSuccess
    ) {
        OSMessage msg;
        *pSuccess = OSReceiveMessage(&mMesgQueue, &msg, 0);
        return msg;
    }

    OSMessage waitMessageBlock() {
        OSMessage msg;
        OSReceiveMessage(&mMesgQueue, &msg, OS_MESSAGE_BLOCKING);
        return msg;
    }

    OSThread* getOSThread() const { return mOSThread; }

    void* getStack() const { return mStackMemory; }

    u32 getStackSize() const { return mStackSize; }

    static nw4r::ut::List& getList() { return sThreadList; }

private:
    void setCommonMesgQueue(int capacity, Heap* pHeap);

    static void switchThreadCallback(OSThread* pCurrOSThread, OSThread* pNewOSThread);
    static void* start(void* pArg);

private:
    /* 0x04 */ Heap*          mContainHeap;
    /* 0x08 */ OSThread*      mOSThread;
    /* 0x0C */ OSMessageQueue mMesgQueue;
    /* 0x2C */ OSMessage*     mMesgBuffer;
    /* 0x30 */ int            mMesgNum;
    /* 0x34 */ void*          mStackMemory;
    /* 0x38 */ u32            mStackSize;
    /* 0x3C */ u32            m0x3C;

public:
    /* 0x3C */ NW4R_UT_LIST_LINK_DECL();

private:
    static nw4r::ut::List sThreadList;
};

} // namespace EGG
