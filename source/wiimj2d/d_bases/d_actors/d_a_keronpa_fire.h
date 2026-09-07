#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daKeronpaFire_c : public dActorState_c {
    SIZE_ASSERT(0x510);
    VTABLE(0x060, fBase_c, 0x80962938);
    // 0x80962900 g_profile_KERONPA_FIRE
    // 0x8081FDB0 daKeronpaFire_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daKeronpaFire_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x510);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80820200
     * executeState:    0x80820230
     * finalizeState:   0x80820220
     */
    sState_Extern(0x8099A098, daKeronpaFire_c, Follow);

    /*
     * initializeState: 0x80820390
     * executeState:    0x80820470
     * finalizeState:   0x80820460
     */
    sState_Extern(0x8099A0D8, daKeronpaFire_c, Move);

    /*
     * initializeState: 0x80820570
     * executeState:    0x80820590
     * finalizeState:   0x80820580
     */
    sState_Extern(0x8099A118, daKeronpaFire_c, EatIn);
};
