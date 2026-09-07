#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daObjClearBlock_c : public dActorState_c {
    SIZE_ASSERT(0x3F0);
    VTABLE(0x060, fBase_c, 0x80972178);
    // 0x80972168 g_profile_AC_OBJ_CLEAR_BLOCK
    // 0x808753C0 daObjClearBlock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daObjClearBlock_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x3F0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808756D0
     * executeState:    0x808756F0
     * finalizeState:   0x808756E0
     */
    sState_Extern(0x8099D3A0, daObjClearBlock_c, Wait);
};
