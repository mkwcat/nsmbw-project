#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnWaterBubbleBullet_c : public dEn_c {
    SIZE_ASSERT(0x600);
    VTABLE(0x060, fBase_c, 0x80B0F008);
    // 0x80B0EFD8 g_profile_EN_WATER_BUBBLE_BULLET
    // 0x80AC4300 daEnWaterBubbleBullet_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnWaterBubbleBullet_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x600);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80AC4A70
     * executeState:    0x80AC4A90
     * finalizeState:   0x80AC4A80
     */
    sState_Extern(0x80B1C498, daEnWaterBubbleBullet_c, Move);
};
