#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daGearGyration_c : public dActorState_c {
    SIZE_ASSERT(0xC80);
    VTABLE(0x060, fBase_c, 0x8095CB38);
    // 0x8095CA80 g_profile_AC_GEAR_GYRATION
    // 0x807FB4A0 daGearGyration_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daGearGyration_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0xC80);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807FC1E0
     * executeState:    0x807FC200
     * finalizeState:   0x807FC1F0
     */
    sState_Extern(0x80998D30, daGearGyration_c, SearchID);

    /*
     * initializeState: 0x807FC2B0
     * executeState:    0x807FC2D0
     * finalizeState:   0x807FC2C0
     */
    sState_Extern(0x80998D70, daGearGyration_c, Move);
};
