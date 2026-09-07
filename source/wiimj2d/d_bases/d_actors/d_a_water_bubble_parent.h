#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daWaterBubbleParent_c : public dActorState_c {
    SIZE_ASSERT(0x3E0);
    VTABLE(0x060, fBase_c, 0x809800A0);
    // 0x80980090 g_profile_AC_WATER_BUBBLE_PARENT
    // 0x808BEAE0 daWaterBubbleParent_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWaterBubbleParent_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x3E0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808BEBE0
     * executeState:    0x808BEC00
     * finalizeState:   0x808BEBF0
     */
    sState_Extern(0x8099FD10, daWaterBubbleParent_c, Move);
};
