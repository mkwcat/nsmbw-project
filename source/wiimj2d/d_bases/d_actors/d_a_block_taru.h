#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daBlockTaru_c : public dActorState_c {
    SIZE_ASSERT(0x6B0);
    VTABLE(0x060, fBase_c, 0x809532C8);
    // 0x809531D0 g_profile_BLOCK_TARU
    // 0x807C1100 daBlockTaru_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBlockTaru_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x6B0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807C2810
     * executeState:    0x807C2850
     * finalizeState:   0x807C2840
     */
    sState_Extern(0x80996680, daBlockTaru_c, Wait);

    /*
     * initializeState: 0x807C28F0
     * executeState:    0x807C29E0
     * finalizeState:   0x807C2980
     */
    sState_Extern(0x809966C0, daBlockTaru_c, Carry);

    /*
     * initializeState: 0x807C2C20
     * executeState:    0x807C2D30
     * finalizeState:   0x807C2D20
     */
    sState_Extern(0x80996700, daBlockTaru_c, Throw);

    /*
     * initializeState: 0x807C2EE0
     * executeState:    0x807C2F00
     * finalizeState:   0x807C2EF0
     */
    sState_Extern(0x80996740, daBlockTaru_c, Quit);
};
