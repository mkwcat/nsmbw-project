#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnEatJugem_c : public dEn_c {
    SIZE_ASSERT(0x5F0);
    VTABLE(0x060, fBase_c, 0x80AE87C0);
    // 0x80AE8790 g_profile_EN_EATJUGEM
    // 0x809F7C60 daEnEatJugem_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnEatJugem_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5F0);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x1E4 0x809F7E90
     * executeState:    VT+0x1E8 0x809F7EB0
     * finalizeState:   VT+0x1EC 0x809F7EA0
     */
    sState_ExternVirtual(0x80B1458C, daEnEatJugem_c, EatOut);
};
