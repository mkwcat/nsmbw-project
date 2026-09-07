#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daNiceCoin_c : public dActorState_c {
    SIZE_ASSERT(0x3F0);
    VTABLE(0x060, fBase_c, 0x80971A10);
    // 0x809719F8 g_profile_AC_NICE_COIN
    // 0x808724E0 daNiceCoin_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daNiceCoin_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x3F0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808726E0
     * executeState:    0x80872700
     * finalizeState:   0x808726F0
     */
    sState_Extern(0x8099D1E0, daNiceCoin_c, Search);

    /*
     * initializeState: 0x808727F0
     * executeState:    0x80872810
     * finalizeState:   0x80872800
     */
    sState_Extern(0x8099D220, daNiceCoin_c, EndWait);
};

class daNiceCoinRegular_c : public daNiceCoin_c {
    SIZE_ASSERT(0x3F0);
    VTABLE(0x060, fBase_c, 0x80971A10);
    // 0x80971A04 g_profile_AC_NICE_COIN_REGULAR
    // 0x80872530 daNiceCoinRegular_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daNiceCoinRegular_c() {}
};
