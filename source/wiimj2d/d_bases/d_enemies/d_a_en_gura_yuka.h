#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daEnGuraYuka_c : public dActorState_c {
    SIZE_ASSERT(0x4A0);
    VTABLE(0x060, fBase_c, 0x80AED388);
    // 0x80AED330 g_profile_EN_GURA_YUKA
    // 0x80A10220 daEnGuraYuka_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnGuraYuka_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x4A0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A10D00
     * executeState:    0x80A10D20
     * finalizeState:   0x80A10D10
     */
    sState_Extern(0x80B157F0, daEnGuraYuka_c, Wait);
};
