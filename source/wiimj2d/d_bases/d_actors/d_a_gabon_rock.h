#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daGabonRock_c : public dActorState_c {
    SIZE_ASSERT(0x720);
    VTABLE(0x060, fBase_c, 0x8095C738);
    // 0x8095C660 g_profile_GABON_ROCK
    // 0x807F8A60 daGabonRock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daGabonRock_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x720);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807F9EA0
     * executeState:    0x807F9FC0
     * finalizeState:   0x807F9F30
     */
    sState_Extern(0x80998B30, daGabonRock_c, Bind);

    /*
     * initializeState: 0x807FA610
     * executeState:    0x807FA6E0
     * finalizeState:   0x807FA6D0
     */
    sState_Extern(0x80998B70, daGabonRock_c, Roll);

    /*
     * initializeState: 0x807FA100
     * executeState:    0x807FA1C0
     * finalizeState:   0x807FA1B0
     */
    sState_Extern(0x80998BB0, daGabonRock_c, Fall);

    /*
     * initializeState: 0x807FA310
     * executeState:    0x807FA3F0
     * finalizeState:   0x807FA3E0
     */
    sState_Extern(0x80998BF0, daGabonRock_c, FallWater);

    /*
     * initializeState: 0x807FA4D0
     * executeState:    0x807FA5B0
     * finalizeState:   0x807FA5A0
     */
    sState_Extern(0x80998C30, daGabonRock_c, FallWater2);

    /*
     * initializeState: 0x807FA940
     * executeState:    0x807FA9B0
     * finalizeState:   0x807FA9A0
     */
    sState_Extern(0x80998C70, daGabonRock_c, Drop);

    /*
     * initializeState: 0x807FAA60
     * executeState:    0x807FAAD0
     * finalizeState:   0x807FAAC0
     */
    sState_Extern(0x80998CB0, daGabonRock_c, Crush);

    /*
     * initializeState: 0x807FAB60
     * executeState:    0x807FAB90
     * finalizeState:   0x807FAB80
     */
    sState_Extern(0x80998CF0, daGabonRock_c, DropOut);
};
