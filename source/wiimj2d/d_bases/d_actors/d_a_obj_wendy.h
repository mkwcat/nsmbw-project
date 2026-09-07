#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daObjWendy_c : public dActorState_c {
    SIZE_ASSERT(0x1ACD0);
    VTABLE(0x00060, fBase_c, 0x80976D30);
    // 0x80976BB8 g_profile_OBJ_WENDY
    // 0x80889DF0 daObjWendy_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daObjWendy_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x003D0, 0x1ACD0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8088AAD0
     * executeState:    0x8088AB00
     * finalizeState:   0x8088AB40
     */
    sState_Extern(0x8099DF00, daObjWendy_c, Wait);

    /*
     * initializeState: 0x8088AB50
     * executeState:    0x8088AB80
     * finalizeState:   0x8088B260
     */
    sState_Extern(0x8099DF40, daObjWendy_c, Fall);

    /*
     * initializeState: 0x8088B270
     * executeState:    0x8088B340
     * finalizeState:   0x8088B630
     */
    sState_Extern(0x8099DF80, daObjWendy_c, Rise);

    /*
     * initializeState: 0x8088B640
     * executeState:    0x8088B680
     * finalizeState:   0x8088B6D0
     */
    sState_Extern(0x8099DFC0, daObjWendy_c, Fill);

    /*
     * initializeState: 0x8088B6E0
     * executeState:    0x8088B7B0
     * finalizeState:   0x8088BAD0
     */
    sState_Extern(0x8099E000, daObjWendy_c, Drop);
};
