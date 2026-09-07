#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daBrosIceball_c : public dActorState_c {
    SIZE_ASSERT(0x3E8);
    VTABLE(0x060, fBase_c, 0x80955A68);
    // 0x80955A58 g_profile_BROS_ICEBALL
    // 0x807D4F20 daBrosIceball_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBrosIceball_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x3E8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807D5580
     * executeState:    0x807D55E0
     * finalizeState:   0x807D55D0
     */
    sState_Extern(0x809970C8, daBrosIceball_c, Move);

    /*
     * initializeState: 0x807D5500
     * executeState:    0x807D5520
     * finalizeState:   0x807D5510
     */
    sState_Extern(0x80997108, daBrosIceball_c, EatIn);

    /*
     * initializeState: 0x807D5550
     * executeState:    0x807D5570
     * finalizeState:   0x807D5560
     */
    sState_Extern(0x80997148, daBrosIceball_c, EatNow);
};
