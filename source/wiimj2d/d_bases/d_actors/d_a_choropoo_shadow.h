#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daChoropooShadow_c : public dEn_c {
    SIZE_ASSERT(0x588);
    VTABLE(0x060, fBase_c, 0x809581B8);
    // 0x80958178 g_profile_CHOROPOO_SHADOW
    // 0x807E1A00 daChoropooShadow_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daChoropooShadow_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x588);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807E1D00
     * executeState:    0x807E1D20
     * finalizeState:   0x807E1D10
     */
    sState_Extern(0x80997D58, daChoropooShadow_c, Wait);
};
