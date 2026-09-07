#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daFloorHoleDokan_c : public dActorState_c {
    SIZE_ASSERT(0xAD8);
    VTABLE(0x060, fBase_c, 0x8095A8A0);
    // 0x8095A7A8 g_profile_AC_FLOOR_HOLE_DOKAN
    // 0x807EF7A0 daFloorHoleDokan_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daFloorHoleDokan_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0xAD8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807F0860
     * executeState:    0x807F0880
     * finalizeState:   0x807F0870
     */
    sState_Extern(0x809986A8, daFloorHoleDokan_c, Move);
};
