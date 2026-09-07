#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daShipCannon_c : public dActorState_c {
    SIZE_ASSERT(0x660);
    VTABLE(0x060, fBase_c, 0x8097ACA8);
    // 0x8097AC38 g_profile_AC_SHIP_CANNON
    // 0x808A0A40 daShipCannon_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daShipCannon_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x660);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808A17A0
     * executeState:    0x808A17C0
     * finalizeState:   0x808A17B0
     */
    sState_Extern(0x8099ED20, daShipCannon_c, Wait);

    /*
     * initializeState: 0x808A17D0
     * executeState:    0x808A17F0
     * finalizeState:   0x808A17E0
     */
    sState_Extern(0x8099ED60, daShipCannon_c, RotationWait);

    /*
     * initializeState: 0x808A1890
     * executeState:    0x808A18C0
     * finalizeState:   0x808A18B0
     */
    sState_Extern(0x8099EDA0, daShipCannon_c, RotationMove);

    /*
     * initializeState: 0x808A19A0
     * executeState:    0x808A19C0
     * finalizeState:   0x808A19B0
     */
    sState_Extern(0x8099EDE0, daShipCannon_c, ReturnRotationMove);
};
