#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daLineKinokoBlock_c : public dActorState_c {
    SIZE_ASSERT(0x5D8);
    VTABLE(0x060, fBase_c, 0x8096B738);
    // 0x8096B6F8 g_profile_LINE_KINOKO_BLOCK
    // 0x80857490 daLineKinokoBlock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLineKinokoBlock_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x5D8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80857A70
     * executeState:    0x80857A90
     * finalizeState:   0x80857A80
     */
    sState_Extern(0x8099C448, daLineKinokoBlock_c, Fall);

    /*
     * initializeState: 0x80857B40
     * executeState:    0x80857B60
     * finalizeState:   0x80857B50
     */
    sState_Extern(0x8099C488, daLineKinokoBlock_c, Wait);

    /*
     * initializeState: 0x80857BD0
     * executeState:    0x80857C40
     * finalizeState:   0x80857C30
     */
    sState_Extern(0x8099C4C8, daLineKinokoBlock_c, Move);
};
