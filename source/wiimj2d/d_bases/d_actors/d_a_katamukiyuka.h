#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daKatamukiyuka_c : public dActorState_c {
    SIZE_ASSERT(0x498);
    VTABLE(0x060, fBase_c, 0x80962158);
    // 0x809620F0 g_profile_KATAMUKIYUKA
    // 0x8081CF40 daKatamukiyuka_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daKatamukiyuka_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x498);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8081D4C0
     * executeState:    0x8081D4E0
     * finalizeState:   0x8081D4D0
     */
    sState_Extern(0x80999D88, daKatamukiyuka_c, Search);

    /*
     * initializeState: 0x8081D4F0
     * executeState:    0x8081D510
     * finalizeState:   0x8081D500
     */
    sState_Extern(0x80999DC8, daKatamukiyuka_c, Move);
};
