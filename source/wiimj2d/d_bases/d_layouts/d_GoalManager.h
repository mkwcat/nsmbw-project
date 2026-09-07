#pragma once

#include "d_base.h"
#include "s_State.h"

class dGoalManager_c : public dBase_c {
    SIZE_ASSERT(0xB8);
    VTABLE(0x60, fBase_c, 0x80322608);
    // 0x803225FC g_profile_GOAL_MANAGER
    // 0x8010B050 dGoalManager_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8010B080 */
    dGoalManager_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x70, 0xB8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8010B360
     * executeState:    0x8010B370
     * finalizeState:   0x8010B3B0
     */
    sState_Extern(0x80374F90, dGoalManager_c, StartWait);

    /*
     * initializeState: 0x8010B470
     * executeState:    0x8010B480
     * finalizeState:   0x8010B510
     */
    sState_Extern(0x80374FD0, dGoalManager_c, KiMePose);

    /*
     * initializeState: 0x8010B3C0
     * executeState:    0x8010B3D0
     * finalizeState:   0x8010B460
     */
    sState_Extern(0x80375010, dGoalManager_c, KiMePoseStartWait);

    /*
     * initializeState: 0x8010B520
     * executeState:    0x8010B530
     * finalizeState:   0x8010B5D0
     */
    sState_Extern(0x80375050, dGoalManager_c, MessageOnStage);

    /*
     * initializeState: 0x8010B5E0
     * executeState:    0x8010B5F0
     * finalizeState:   0x8010B610
     */
    sState_Extern(0x80375090, dGoalManager_c, ScoreCalc);

    /*
     * initializeState: 0x8010B620
     * executeState:    0x8010B630
     * finalizeState:   0x8010B660
     */
    sState_Extern(0x803750D0, dGoalManager_c, MessageDisp);

    /*
     * initializeState: 0x8010B670
     * executeState:    0x8010B680
     * finalizeState:   0x8010B6F0
     */
    sState_Extern(0x80375110, dGoalManager_c, MessageExit);

    /*
     * initializeState: 0x8010B700
     * executeState:    0x8010B7B0
     * finalizeState:   0x8010B7C0
     */
    sState_Extern(0x80375150, dGoalManager_c, ClearWait);
};
