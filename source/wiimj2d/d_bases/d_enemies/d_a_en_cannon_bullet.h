#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnCannonBullet_c : public dEn_c {
    SIZE_ASSERT(0x5B8);
    VTABLE(0x060, fBase_c, 0x80ADF7E8);
    // 0x80ADF7B8 g_profile_EN_CANNON_BULLET
    // 0x809D3B40 daEnCannonBullet_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnCannonBullet_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5B8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809D4110
     * executeState:    0x809D4190
     * finalizeState:   0x809D4180
     */
    sState_Extern(0x80B12FF0, daEnCannonBullet_c, Move);
};
