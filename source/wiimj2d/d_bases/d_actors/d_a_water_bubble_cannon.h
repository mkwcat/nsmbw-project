#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daWaterBubbleCannon_c : public dActorState_c {
    SIZE_ASSERT(0x528);
    VTABLE(0x060, fBase_c, 0x8097FE90);
    // 0x8097FE80 g_profile_AC_WATER_BUBBLE_CANNON
    // 0x808BE270 daWaterBubbleCannon_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWaterBubbleCannon_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x528);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808BE500
     * executeState:    0x808BE520
     * finalizeState:   0x808BE510
     */
    sState_Extern(0x8099FC50, daWaterBubbleCannon_c, SearchID);

    /*
     * initializeState: 0x808BE580
     * executeState:    0x808BE5A0
     * finalizeState:   0x808BE590
     */
    sState_Extern(0x8099FC90, daWaterBubbleCannon_c, ParentMove);

    /*
     * initializeState: 0x808BE600
     * executeState:    0x808BE620
     * finalizeState:   0x808BE610
     */
    sState_Extern(0x8099FCD0, daWaterBubbleCannon_c, Move);
};
