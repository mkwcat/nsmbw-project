#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daRotDokan_c : public dActorState_c {
    SIZE_ASSERT(0x500);
    VTABLE(0x060, fBase_c, 0x8097A4E0);
    // 0x8097A498 g_profile_ROT_DOKAN
    // 0x8089C8D0 daRotDokan_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daRotDokan_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x500);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8089DB30
     * executeState:    0x8089DB50
     * finalizeState:   0x8089DB40
     */
    sState_Extern(0x8099E998, daRotDokan_c, Ready);

    /*
     * initializeState: 0x8089DBD0
     * executeState:    0x8089DBF0
     * finalizeState:   0x8089DBE0
     */
    sState_Extern(0x8099E9D8, daRotDokan_c, Wait);

    /*
     * initializeState: 0x8089DC40
     * executeState:    0x8089DC90
     * finalizeState:   0x8089DC50
     */
    sState_Extern(0x8099EA18, daRotDokan_c, Turn);
};
