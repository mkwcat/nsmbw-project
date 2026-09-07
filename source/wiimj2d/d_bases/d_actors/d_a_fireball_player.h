#pragma once

#include "d_a_fireball_base.h"
#include "s_State.h"

class daFireBall_Player_c : public daFireBall_Base_c {
    SIZE_ASSERT(0x560);
    VTABLE(0x060, fBase_c, 0x80324080);
    // 0x80324060 g_profile_PL_FIREBALL
    // 0x8011A5B0 daFireBall_Player_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daFireBall_Player_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x554, 0x560);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0xE0 0x8011ACF0
     * executeState:    VT+0xE4 0x8011AD10
     * finalizeState:   VT+0xE8 0x8011AD00
     */
    sState_ExternVirtual(0x8037586C, daFireBall_Player_c, Move);
};
