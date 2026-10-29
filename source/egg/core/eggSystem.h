#pragma once

struct _GXRenderModeObj;

namespace EGG {

// Forward declarations
class Display;
class Heap;

class IAudioMgr {};

class PerformanceView;
class SceneManager;
class Video;
class XfbManager;
class Thread;

class ConfigurationData {
public:
    constexpr ConfigurationData() {}

    explicit ConfigurationData(
        u32 systemHeapSize
    )
        : mSystemHeapSize(systemHeapSize) {}

    /* VT+0x08 */ virtual Video* getVideo()              = 0;
    /* VT+0x0C */ virtual Heap* getSystemHeap()          = 0;
    /* VT+0x10 */ virtual Display* getDisplay()          = 0;
    /* VT+0x14 */ virtual XfbManager* getXfbMgr()        = 0;
    /* VT+0x18 */ virtual PerformanceView* getPerfView() = 0;
    /* VT+0x1C */ virtual SceneManager* getSceneMgr()    = 0;
    /* VT+0x20 */ virtual IAudioMgr* getAudioMgr()       = 0;

    /* VT+0x24 */ virtual void onBeginFrame() {}

    /* VT+0x28 */ virtual void onEndFrame() {}

    /* VT+0x2C */ virtual void initRenderMode() {}

    /* VT+0x30 */ [[mkw(0x80242504)]] virtual void initMemory();
    /* VT+0x34 */ [[mkw(0x8024269C)]] virtual void run();

    Heap* getRootHeapMem1() { return mRootHeapMem1; }

    Heap* getRootHeapMem2() { return mRootHeapMem2; }

    Heap* getRootHeapDebug() { return mRootHeapDebug; }

private:
    /* 0x04 */ void* mMem1Start;
    /* 0x08 */ void* mMem1End;
    /* 0x0C */ void* mMem2Start;
    /* 0x10 */ void* mMem2End;
    /* 0x14 */ u32   mMemorySize;
    /* 0x18 */ Heap* mRootHeapMem1;
    /* 0x1C */ Heap* mRootHeapMem2;
    /* 0x20 */ Heap* mRootHeapDebug;

protected:
    /* 0x24 */ Heap*             mSystemHeap;
    /* 0x28 */ Thread*           mParentThread;
    /* 0x2C */ void*             mCodeStart;
    /* 0x30 */ void*             mCodeEnd;
    /* 0x34 */ u32               mSystemHeapSize;
    /* 0x38 */ u32               mGraphicsFifoSize;
    /* 0x3C */ _GXRenderModeObj* mRenderMode;
};

class BaseSystem {
public:
    static void configure(
        ConfigurationData* pConfigData
    ) {
        mConfigData = pConfigData;
    }

    static Video* getVideo() { return mConfigData->getVideo(); }

    static Heap* getRootHeapMem1() { return mConfigData->getRootHeapMem1(); }

    static Heap* getRootHeapMem2() { return mConfigData->getRootHeapMem2(); }

    static Heap* getRootHeapDebug() { return mConfigData->getRootHeapDebug(); }

    static Heap* getSystemHeap() { return mConfigData->getSystemHeap(); }

    static Display* getDisplay() { return mConfigData->getDisplay(); }

    static XfbManager* getXfbManager() { return mConfigData->getXfbMgr(); }

    static PerformanceView* getPerfView() { return mConfigData->getPerfView(); }

    static SceneManager* getSceneManager() { return mConfigData->getSceneMgr(); }

    static IAudioMgr* getAudioManager() { return mConfigData->getAudioMgr(); }

private:
    [[mkw_data(0x80386F60)]] static inline ConfigurationData* mConfigData;
};

// Forward declarations
class AsyncDisplay;

class SimpleAudioMgr : public IAudioMgr {};

class ProcessMeter;

template <
    class TVideo = Video, class TDisplay = AsyncDisplay, class TXfbManager = XfbManager,
    class TAudioMgr = SimpleAudioMgr, class TSceneManager = SceneManager,
    class TPerformanceView = ProcessMeter>
class TSystem : public BaseSystem {
public:
    class Configuration : public ConfigurationData {
    public:
        using TSystem = TSystem;

        constexpr Configuration() {
            mGraphicsFifoSize = 0x80000;
            mRenderMode       = nullptr;
        }

        virtual Video* getVideo() { return mVideo; }

        virtual Heap* getSystemHeap() { return mSystemHeap; }

        virtual Display* getDisplay() { return mDisplay; }

        virtual XfbManager* getXfbMgr() { return mXfbMgr; }

        virtual PerformanceView* getPerfView() { return mPerfView; }

        virtual SceneManager* getSceneMgr() { return mSceneMgr; }

        virtual IAudioMgr* getAudioMgr() { return mAudioMgr; }

        virtual void initialize();

        /* 0x40 */ TAudioMgr*        mAudioMgr;
        /* 0x44 */ TVideo*           mVideo;
        /* 0x48 */ TXfbManager*      mXfbMgr;
        /* 0x4C */ TDisplay*         mDisplay;
        /* 0x50 */ TPerformanceView* mPerfView;
        /* 0x54 */ TSceneManager*    mSceneMgr;
    };

    static Configuration* sConfiguration;
};

} // namespace EGG
