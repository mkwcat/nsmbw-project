#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daStrongBox_c : public dActorState_c {
    SIZE_ASSERT(0x908);
    VTABLE(0x060, fBase_c, 0x8097C658);
    // 0x8097C478 g_profile_AC_STRONGBOX
    // 0x808AA2C0 daStrongBox_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daStrongBox_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x908);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808AB150
     * executeState:    0x808AB170
     * finalizeState:   0x808AB160
     */
    sState_Extern(0x8099F1C8, daStrongBox_c, Wait);

    /*
     * initializeState: 0x808AB1E0
     * executeState:    0x808AB200
     * finalizeState:   0x808AB1F0
     */
    sState_Extern(0x8099F208, daStrongBox_c, CoinWait);

    /*
     * initializeState: 0x808AB2A0
     * executeState:    0x808AB2D0
     * finalizeState:   0x808AB2C0
     */
    sState_Extern(0x8099F248, daStrongBox_c, AppearWait);

    /*
     * initializeState: 0x808AB4E0
     * executeState:    0x808AB550
     * finalizeState:   0x808AB540
     */
    sState_Extern(0x8099F288, daStrongBox_c, Open);

    /*
     * initializeState: 0x808AB660
     * executeState:    0x808AB700
     * finalizeState:   0x808AB6F0
     */
    sState_Extern(0x8099F2C8, daStrongBox_c, KinopioAppear);

    /*
     * initializeState: 0x808AB790
     * executeState:    0x808AB7B0
     * finalizeState:   0x808AB7A0
     */
    sState_Extern(0x8099F308, daStrongBox_c, ItemAppear);

    /*
     * initializeState: 0x808AB880
     * executeState:    0x808AB900
     * finalizeState:   0x808AB8F0
     */
    sState_Extern(0x8099F348, daStrongBox_c, ItemUp);

    /*
     * initializeState: 0x808AB9C0
     * executeState:    0x808AB9E0
     * finalizeState:   0x808AB9D0
     */
    sState_Extern(0x8099F388, daStrongBox_c, StopWait);
};
