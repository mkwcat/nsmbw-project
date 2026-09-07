#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daWaterMove_c : public dActorState_c {
    SIZE_ASSERT(0x4C0);
    VTABLE(0x060, fBase_c, 0x80980440);
    // 0x809803A8 g_profile_AC_WATER_MOVE
    // 0x808BF780 daWaterMove_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWaterMove_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x4C0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808C02B0
     * executeState:    0x808C02E0
     * finalizeState:   0x808C02D0
     */
    sState_Extern(0x8099FDD0, daWaterMove_c, Wait);

    /*
     * initializeState: 0x808C02F0
     * executeState:    0x808C0320
     * finalizeState:   0x808C0310
     */
    sState_Extern(0x8099FE10, daWaterMove_c, Udmove);

    /*
     * initializeState: 0x808C0360
     * executeState:    0x808C0390
     * finalizeState:   0x808C0380
     */
    sState_Extern(0x8099FE50, daWaterMove_c, Lrmove);
};

class daWaterMoveRegular_c : public daWaterMove_c {
    SIZE_ASSERT(0x4C0);
    // 0x809803B4 g_profile_AC_WATER_MOVE_REGULAR
    // 0x808BF820 daWaterMoveRegular_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWaterMoveRegular_c() {}
};
