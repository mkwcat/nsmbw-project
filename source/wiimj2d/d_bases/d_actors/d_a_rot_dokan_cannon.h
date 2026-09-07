#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daRotDokanCannon_c : public dActorState_c {
    SIZE_ASSERT(0xA08);
    VTABLE(0x060, fBase_c, 0x8097A778);
    // 0x8097A6B8 g_profile_AC_ROT_DOKAN_CANNON
    // 0x8089E170 daRotDokanCannon_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daRotDokanCannon_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0xA08);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8089F670
     * executeState:    0x8089F690
     * finalizeState:   0x8089F680
     */
    sState_Extern(0x8099EB60, daRotDokanCannon_c, RotationWait);

    /*
     * initializeState: 0x8089F740
     * executeState:    0x8089F770
     * finalizeState:   0x8089F760
     */
    sState_Extern(0x8099EBA0, daRotDokanCannon_c, RotationMove);

    /*
     * initializeState: 0x8089F890
     * executeState:    0x8089F8B0
     * finalizeState:   0x8089F8A0
     */
    sState_Extern(0x8099EBE0, daRotDokanCannon_c, ReturnRotationMove);
};
