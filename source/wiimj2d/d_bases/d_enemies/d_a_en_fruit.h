#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnFruit_c : public dEn_c {
    SIZE_ASSERT(0x680);
    VTABLE(0x060, fBase_c, 0x80AEA140);
    // 0x80AEA0B8 g_profile_EN_FRUIT
    // 0x809FE830 daEnFruit_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnFruit_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x680);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809FF130
     * executeState:    0x809FF150
     * finalizeState:   0x809FF140
     */
    sState_Extern(0x80B149E8, daEnFruit_c, Wait);
};
