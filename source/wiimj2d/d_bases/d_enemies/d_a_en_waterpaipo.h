#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnWaterPaipo_c : public dEn_c {
    SIZE_ASSERT(0x558);
    VTABLE(0x060, fBase_c, 0x80B0F348);
    // 0x80B0F320 g_profile_EN_WATERPAIPO
    // 0x80AC4E70 daEnWaterPaipo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnWaterPaipo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x558);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80AC52F0
     * executeState:    0x80AC5320
     * finalizeState:   0x80AC5310
     */
    sState_Extern(0x80B1C4D8, daEnWaterPaipo_c, Waki);

    /*
     * initializeState: 0x80AC5390
     * executeState:    0x80AC53F0
     * finalizeState:   0x80AC53E0
     */
    sState_Extern(0x80B1C518, daEnWaterPaipo_c, Move);
};
