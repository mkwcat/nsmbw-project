#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daObjCenter2_c : public dActorState_c {
    SIZE_ASSERT(0x3E8);
    VTABLE(0x060, fBase_c, 0x80971F80);
    // 0x80971F70 g_profile_OBJ_CENTER2
    // 0x80874670 daObjCenter2_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daObjCenter2_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x3E8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80874AD0
     * executeState:    0x80874B30
     * finalizeState:   0x80874B20
     */
    sState_Extern(0x8099D2E0, daObjCenter2_c, ReturnHome);

    /*
     * initializeState: 0x80874C20
     * executeState:    0x80874CA0
     * finalizeState:   0x80874C90
     */
    sState_Extern(0x8099D320, daObjCenter2_c, GoAim);

    /*
     * initializeState: 0x80874E40
     * executeState:    0x80874E80
     * finalizeState:   0x80874E70
     */
    sState_Extern(0x8099D360, daObjCenter2_c, Move);
};
