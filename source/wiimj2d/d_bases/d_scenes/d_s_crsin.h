#pragma once

#include "d_preGame.h"
#include "d_scene.h"
#include "s_State.h"
#include "s_StateMgrDefault.h"

class dScCrsin_c : public dScene_c {
    SIZE_ASSERT(0x3C8);
    VTABLE(0x060, fBase_c, 0x8098C518);
    // 0x8098C278 g_profile_CRSIN
    // 0x8091EC10 dScCrsin_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8091EFD0 */
    virtual ~dScCrsin_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8091EC50 */
    int loadDefaultObjectResPhase();

    /* 0x8091F560 */
    bool isDoneLoading();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x074 */ sStateMgrDefault_c<dScCrsin_c> mStateMgr;
    /* 0x0B0 */ dPreGame_c                     mPreGameLyt;
    FILL(0x3BC, 0x3C8);

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A494 */ static dScCrsin_c* m_instance;

    /* 0x8042A490 */ static bool        m_isDispOff;

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8091F5A0
     * executeState:    0x8091F5C0
     * finalizeState:   0x8091F5B0
     */
    sState_Extern(0x809A1BA8, dScCrsin_c, initStageProc);

    /*
     * initializeState: 0x8091F640
     * executeState:    0x8091F660
     * finalizeState:   0x8091F650
     */
    sState_Extern(0x809A1BE8, dScCrsin_c, resWaitProc);

    /*
     * initializeState: 0x8091F940
     * executeState:    0x8091F960
     * finalizeState:   0x8091F950
     */
    sState_Extern(0x809A1C28, dScCrsin_c, loadCourseProc);

    /*
     * initializeState: 0x8091FA10
     * executeState:    0x8091FA30
     * finalizeState:   0x8091FA20
     */
    sState_Extern(0x809A1C68, dScCrsin_c, initSoundProc);

    /*
     * initializeState: 0x8091FBB0
     * executeState:    0x8091FBD0
     * finalizeState:   0x8091FBC0
     */
    sState_Extern(0x809A1CA8, dScCrsin_c, initStageProc2);

    /*
     * initializeState: 0x8091FE00
     * executeState:    0x8091FE20
     * finalizeState:   0x8091FE10
     */
    sState_Extern(0x809A1CE8, dScCrsin_c, resWaitProc2);

    /*
     * initializeState: 0x8091FFF0
     * executeState:    0x80920020
     * finalizeState:   0x80920010
     */
    sState_Extern(0x809A1D28, dScCrsin_c, createReplayHeapProc);

    /*
     * initializeState: 0x8091F6B0
     * executeState:    0x8091F6D0
     * finalizeState:   0x8091F6C0
     */
    sState_Extern(0x809A1D68, dScCrsin_c, replayResWaitProc);

    /*
     * initializeState: 0x80920190
     * executeState:    0x809203C0
     * finalizeState:   0x809203B0
     */
    sState_Extern(0x809A1DA8, dScCrsin_c, effectResWaitProc);

    /*
     * initializeState: 0x80920530
     * executeState:    0x80920550
     * finalizeState:   0x80920540
     */
    sState_Extern(0x809A1DE8, dScCrsin_c, DispEndCheck);
};
