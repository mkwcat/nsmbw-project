#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daLiftSeesaw_c : public dActorState_c {
    SIZE_ASSERT(0x4A8);
    VTABLE(0x060, fBase_c, 0x80969480);
    // 0x80969438 g_profile_AC_LIFT_SEESAW
    // 0x80849980 daLiftSeesaw_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftSeesaw_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x4A8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80849DD0
     * executeState:    0x80849E10
     * finalizeState:   0x80849E00
     */
    sState_Extern(0x8099BB68, daLiftSeesaw_c, NoDisp);

    /*
     * initializeState: 0x80849E60
     * executeState:    0x80849ED0
     * finalizeState:   0x80849EC0
     */
    sState_Extern(0x8099BBA8, daLiftSeesaw_c, Move);
};
