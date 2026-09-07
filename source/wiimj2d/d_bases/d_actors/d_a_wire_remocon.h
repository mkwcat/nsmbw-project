#pragma once

#include "d_a_lift_remocon_main.h"
#include "s_State.h"

class daWireRemocon_c : public daLiftRemoconMain_c {
    SIZE_ASSERT(0x640);
    VTABLE(0x060, fBase_c, 0x80981098);
    // 0x80981038 g_profile_AC_WIRE_REMOCON
    // 0x808C3D80 daWireRemocon_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWireRemocon_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x454, 0x640);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808C4980
     * executeState:    0x808C49A0
     * finalizeState:   0x808C4990
     */
    sState_Extern(0x809A0180, daWireRemocon_c, Move);
};
