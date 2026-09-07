#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daItemKey_c : public dActorState_c {
    SIZE_ASSERT(0x448);
    VTABLE(0x060, fBase_c, 0x8095E138);
    // 0x8095E108 g_profile_AC_ITEM_KEY
    // 0x80804030 daItemKey_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daItemKey_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x448);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80804500
     * executeState:    0x80804520
     * finalizeState:   0x80804510
     */
    sState_Extern(0x80999260, daItemKey_c, Wait);

    /*
     * initializeState: 0x808045D0
     * executeState:    0x808045F0
     * finalizeState:   0x808045E0
     */
    sState_Extern(0x809992A0, daItemKey_c, GetUpDemo);

    /*
     * initializeState: 0x80804680
     * executeState:    0x808046A0
     * finalizeState:   0x80804690
     */
    sState_Extern(0x809992E0, daItemKey_c, UpDemoWait);

    /*
     * initializeState: 0x808046F0
     * executeState:    0x80804710
     * finalizeState:   0x80804700
     */
    sState_Extern(0x80999320, daItemKey_c, UIJumpDemo);
};
