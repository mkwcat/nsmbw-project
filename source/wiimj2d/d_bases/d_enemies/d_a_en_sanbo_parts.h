#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnSanboParts_c : public dEn_c {
    SIZE_ASSERT(0x550);
    VTABLE(0x060, fBase_c, 0x80B08338);
    // 0x80B082F0 g_profile_EN_SANBO_PARTS
    // 0x80AA1C70 daEnSanboParts_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnSanboParts_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x550);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80AA1FC0
     * executeState:    0x80AA1FE0
     * finalizeState:   0x80AA1FD0
     */
    sState_Extern(0x80B1B0B8, daEnSanboParts_c, Wait);
};
