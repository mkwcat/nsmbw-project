#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnLiftRotHalf_c : public dEn_c {
    SIZE_ASSERT(0x688);
    VTABLE(0x060, fBase_c, 0x80AF9728);
    // 0x80AF96F8 g_profile_EN_LIFT_ROTATION_HALF
    // 0x80A5CF00 daEnLiftRotHalf_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80A5CF30 */
    daEnLiftRotHalf_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x688);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A5D720
     * executeState:    0x80A5D770
     * finalizeState:   0x80A5D760
     */
    sState_Extern(0x80B184B0, daEnLiftRotHalf_c, CreateWait);

    /*
     * initializeState: 0x80A5D7D0
     * executeState:    0x80A5D7F0
     * finalizeState:   0x80A5D7E0
     */
    sState_Extern(0x80B184F0, daEnLiftRotHalf_c, Move);
};
