#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daRotBarnar_c : public dActorState_c {
    SIZE_ASSERT(0x15C8);
    VTABLE(0x0060, fBase_c, 0x80979AB0);
    // 0x80979A08 g_profile_ROT_BARNAR
    // 0x80898B70 daRotBarnar_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daRotBarnar_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x03D0, 0x15C8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80899990
     * executeState:    0x808999B0
     * finalizeState:   0x808999A0
     */
    sState_Extern(0x8099E818, daRotBarnar_c, Move);

    /*
     * initializeState: 0x80899A50
     * executeState:    0x80899A70
     * finalizeState:   0x80899A60
     */
    sState_Extern(0x8099E858, daRotBarnar_c, Wait);
};
