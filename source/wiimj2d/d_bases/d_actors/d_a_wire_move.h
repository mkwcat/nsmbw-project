#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daWireMove_c : public dActorState_c {
    SIZE_ASSERT(0x568);
    VTABLE(0x060, fBase_c, 0x80980E58);
    // 0x80980DD8 g_profile_AC_WIRE_MOVE
    // 0x808C2FD0 daWireMove_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWireMove_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x568);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808C36D0
     * executeState:    0x808C3700
     * finalizeState:   0x808C36F0
     */
    sState_Extern(0x809A0050, daWireMove_c, Wait);

    /*
     * initializeState: 0x808C3710
     * executeState:    0x808C3750
     * finalizeState:   0x808C3740
     */
    sState_Extern(0x809A0090, daWireMove_c, Udmove);

    /*
     * initializeState: 0x808C37B0
     * executeState:    0x808C37E0
     * finalizeState:   0x808C37D0
     */
    sState_Extern(0x809A00D0, daWireMove_c, Lrmove);
};
