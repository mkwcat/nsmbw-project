#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnFixationIcicle_c : public dEn_c {
    SIZE_ASSERT(0x5B8);
    VTABLE(0x060, fBase_c, 0x80AE9DB8);
    // 0x80AE9D40 g_profile_EN_FIXATION_ICICLE
    // 0x809FDE80 daEnFixationIcicle_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnFixationIcicle_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5B8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809FE4F0
     * executeState:    0x809FE510
     * finalizeState:   0x809FE500
     */
    sState_Extern(0x80B149A8, daEnFixationIcicle_c, Wait);
};
