#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daKokoopaRing_c : public dActorState_c {
    SIZE_ASSERT(0x1730);
    VTABLE(0x0060, fBase_c, 0x80963500);
    // 0x80963408 g_profile_KOKOOPA_RING
    // 0x80824460 daKokoopaRing_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daKokoopaRing_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x03D0, 0x1730);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808250C0
     * executeState:    0x808250E0
     * finalizeState:   0x80825140
     */
    sState_Extern(0x8099A480, daKokoopaRing_c, Wait);

    /*
     * initializeState: 0x80825350
     * executeState:    0x80825A00
     * finalizeState:   0x80825FE0
     */
    sState_Extern(0x8099A4C0, daKokoopaRing_c, Move);

    /*
     * initializeState: 0x80825150
     * executeState:    0x808251D0
     * finalizeState:   0x808251E0
     */
    sState_Extern(0x8099A500, daKokoopaRing_c, Vanish);
};
