#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daKokoopaSearchFire_c : public dActorState_c {
    SIZE_ASSERT(0x6D8);
    VTABLE(0x060, fBase_c, 0x80963870);
    // 0x809637A0 g_profile_KOKOOPA_SEARCH_FIRE
    // 0x808264F0 daKokoopaSearchFire_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daKokoopaSearchFire_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x6D8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80826F10
     * executeState:    0x80826F40
     * finalizeState:   0x80826F30
     */
    sState_Extern(0x8099A540, daKokoopaSearchFire_c, Wait);

    /*
     * initializeState: 0x80826FB0
     * executeState:    0x808270B0
     * finalizeState:   0x808270A0
     */
    sState_Extern(0x8099A580, daKokoopaSearchFire_c, Move);

    /*
     * initializeState: 0x80827330
     * executeState:    0x80827390
     * finalizeState:   0x80827380
     */
    sState_Extern(0x8099A5C0, daKokoopaSearchFire_c, Hit);

    /*
     * initializeState: 0x808273A0
     * executeState:    0x808273C0
     * finalizeState:   0x808273B0
     */
    sState_Extern(0x8099A600, daKokoopaSearchFire_c, Vanish);
};
