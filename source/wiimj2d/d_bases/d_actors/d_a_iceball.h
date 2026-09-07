#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daIceBall_c : public dActorState_c {
    SIZE_ASSERT(0x430);
    VTABLE(0x060, fBase_c, 0x80324AB8);
    // 0x80324AA8 g_profile_ICEBALL
    // 0x801233F0 daIceBall_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daIceBall_c();

public:
    // Virtual Methods
    // ^^^^^^

    /* 0x80123470 */ PACK_RESULT_e create() override;

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x430);

public:
    // Static Variables
    // ^^^^^^

    /* 0x80375DA8 */ static int REMOVED(sm_IceBallCount)[4];
    /* 0x80375DB8 */ static int REMOVED(sm_IceBallAliveCount)[4];

    // Static Variables
    // ++++++

    static int sm_IceBallCount[PLAYER_COUNT];
    static int sm_IceBallAliveCount[PLAYER_COUNT];

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x801241F0
     * executeState:    0x80124240
     * finalizeState:   0x80124230
     */
    sState_Extern(0x80375DD8, daIceBall_c, FireMove);

    /*
     * initializeState: 0x80124390
     * executeState:    0x80124480
     * finalizeState:   0x80124470
     */
    sState_Extern(0x80375E18, daIceBall_c, Move);

    /*
     * initializeState: 0x801245F0
     * executeState:    0x80124610
     * finalizeState:   0x80124600
     */
    sState_Extern(0x80375E58, daIceBall_c, EatIn);

    /*
     * initializeState: 0x80124670
     * executeState:    0x80124690
     * finalizeState:   0x80124680
     */
    sState_Extern(0x80375E98, daIceBall_c, EatNow);

    /*
     * initializeState: 0x801246A0
     * executeState:    0x801246F0
     * finalizeState:   0x801246E0
     */
    sState_Extern(0x80375ED8, daIceBall_c, Kill);
};
