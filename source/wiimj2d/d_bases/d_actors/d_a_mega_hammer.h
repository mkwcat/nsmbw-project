#pragma once

#include "d_a_bullet.h"
#include "s_State.h"

class daMegaHammer_c : public daBullet_c {
    SIZE_ASSERT(0x420);
    VTABLE(0x060, fBase_c, 0x8096E940);
    // 0x8096E908 g_profile_MEGA_HAMMER
    // 0x80861BD0 daMegaHammer_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daMegaHammer_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x400, 0x420);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80862160
     * executeState:    0x80862190
     * finalizeState:   0x80862180
     */
    sState_Extern(0x8099C930, daMegaHammer_c, Wait);

    /*
     * initializeState: 0x80862260
     * executeState:    0x80862300
     * finalizeState:   0x808622F0
     */
    sState_Extern(0x8099C970, daMegaHammer_c, Move);
};
