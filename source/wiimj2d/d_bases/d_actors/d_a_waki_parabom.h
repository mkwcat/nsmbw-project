#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daWakiParabom_c : public dActorState_c {
    SIZE_ASSERT(0x3F8);
    VTABLE(0x060, fBase_c, 0x8097ED40);
    // 0x8097ED30 g_profile_WAKI_PARABOM
    // 0x808B8C10 daWakiParabom_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWakiParabom_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x3F8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808B9110
     * executeState:    0x808B9130
     * finalizeState:   0x808B9120
     */
    sState_Extern(0x8099F790, daWakiParabom_c, Ready);

    /*
     * initializeState: 0x808B9140
     * executeState:    0x808B9180
     * finalizeState:   0x808B9170
     */
    sState_Extern(0x8099F7D0, daWakiParabom_c, Waki);

    /*
     * initializeState: 0x808B9280
     * executeState:    0x808B92A0
     * finalizeState:   0x808B9290
     */
    sState_Extern(0x8099F810, daWakiParabom_c, Wait);
};
