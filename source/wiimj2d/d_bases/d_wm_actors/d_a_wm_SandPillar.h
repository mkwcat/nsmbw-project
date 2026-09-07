#pragma once

#include "d_wm_demo_actor.h"
#include "s_State.h"

class daWmSandPillar_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x508);
    VTABLE(0x060, fBase_c, 0x80984F08);
    // 0x80984E94 g_profile_WM_SANDPILLAR
    // 0x808E4E00 daWmSandPillar_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808E4E30 */
    daWmSandPillar_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x508);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808E5630
     * executeState:    0x808E5660
     * finalizeState:   0x808E5770
     */
    sState_Extern(0x809A0860, daWmSandPillar_c, Ready);

    /*
     * initializeState: 0x808E5780
     * executeState:    0x808E5830
     * finalizeState:   0x808E5870
     */
    sState_Extern(0x809A08A0, daWmSandPillar_c, BottomWait);

    /*
     * initializeState: 0x808E5940
     * executeState:    0x808E59A0
     * finalizeState:   0x808E5B20
     */
    sState_Extern(0x809A08E0, daWmSandPillar_c, MoveReady);

    /*
     * initializeState: 0x808E5B30
     * executeState:    0x808E5B80
     * finalizeState:   0x808E5CB0
     */
    sState_Extern(0x809A0920, daWmSandPillar_c, MoveUp);

    /*
     * initializeState: 0x808E5CC0
     * executeState:    0x808E5D20
     * finalizeState:   0x808E5D50
     */
    sState_Extern(0x809A0960, daWmSandPillar_c, TopWait);

    /*
     * initializeState: 0x808E5DF0
     * executeState:    0x808E5E60
     * finalizeState:   0x808E5EF0
     */
    sState_Extern(0x809A09A0, daWmSandPillar_c, MoveDown);

    /*
     * initializeState: 0x808E5880
     * executeState:    0x808E5920
     * finalizeState:   0x808E5930
     */
    sState_Extern(0x809A09E0, daWmSandPillar_c, BottomWaitForever);

    /*
     * initializeState: 0x808E5D60
     * executeState:    0x808E5DD0
     * finalizeState:   0x808E5DE0
     */
    sState_Extern(0x809A0A20, daWmSandPillar_c, TopWaitForever);

    /*
     * initializeState: 0x808E5F00
     * executeState:    0x808E5FA0
     * finalizeState:   0x808E5FC0
     */
    sState_Extern(0x809A0A60, daWmSandPillar_c, TopWaitFromTheStart);
};
