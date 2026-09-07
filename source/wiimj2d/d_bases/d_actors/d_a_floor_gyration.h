#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daFloorGyration_c : public dActorState_c {
    SIZE_ASSERT(0x4F8);
    VTABLE(0x060, fBase_c, 0x8095A648);
    // 0x8095A4B8 g_profile_AC_FLOOR_GYRATION
    // 0x807EEC80 daFloorGyration_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daFloorGyration_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x4F8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807EF450
     * executeState:    0x807EF470
     * finalizeState:   0x807EF460
     */
    sState_Extern(0x80998668, daFloorGyration_c, Move);
};
