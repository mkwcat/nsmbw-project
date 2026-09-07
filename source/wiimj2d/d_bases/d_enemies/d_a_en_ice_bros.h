#pragma once

#include "d_a_en_bros_base.h"
#include "s_State.h"

class daEnIceBros_c : public daEnBrosBase_c {
    SIZE_ASSERT(0x850);
    VTABLE(0x060, fBase_c, 0x80AEFA04);
    // 0x80AEF9F0 g_profile_EN_ICEBROS
    // 0x80A1FFD0 daEnIceBros_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnIceBros_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x84C, 0x850);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A20350
     * executeState:    0x80A20400
     * finalizeState:   0x80A203F0
     */
    sState_Extern(0x80B16098, daEnIceBros_c, JumpAttack);
};
