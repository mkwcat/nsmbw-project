#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnItemIvy_c : public dEn_c {
    SIZE_ASSERT(0x700);
    VTABLE(0x060, fBase_c, 0x80AF1BB8);
    // 0x80AF1B68 g_profile_EN_ITEM_IVY
    // 0x80A2D610 daEnItemIvy_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnItemIvy_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x700);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A2E010
     * executeState:    0x80A2E090
     * finalizeState:   0x80A2E080
     */
    sState_Extern(0x80B16B18, daEnItemIvy_c, Move);

    /*
     * initializeState: 0x80A2E150
     * executeState:    0x80A2E170
     * finalizeState:   0x80A2E160
     */
    sState_Extern(0x80B16B58, daEnItemIvy_c, Wait);

    /*
     * initializeState: 0x80A2E1E0
     * executeState:    0x80A2E200
     * finalizeState:   0x80A2E1F0
     */
    sState_Extern(0x80B16B98, daEnItemIvy_c, DemoWait);
};
