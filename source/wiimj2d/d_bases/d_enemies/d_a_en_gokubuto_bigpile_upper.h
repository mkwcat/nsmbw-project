#pragma once

#include "d_a_en_super_bigpile.h"
#include "s_State.h"

class daEnGokubutoBigPileUpper_c : public daEnSuperBigPile_c {
    SIZE_ASSERT(0x6A8);
    VTABLE(0x060, fBase_c, 0x80AEC954);
    // 0x80AEC918 g_profile_EN_GOKUBUTO_BIGPILE_UPPER
    // 0x80A0D2F0 daEnGokubutoBigPileUpper_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnGokubutoBigPileUpper_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x6A0, 0x6A8);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x28C 0x80A0DDE0
     * executeState:    VT+0x290 0x80A0DE40
     * finalizeState:   VT+0x294 0x80A0DE30
     */
    sState_ExternVirtual(0x80B1560C, daEnGokubutoBigPileUpper_c, GoMove);

    /*
     * initializeState: VT+0x2A4 0x80A0DF80
     * executeState:    VT+0x2A8 0x80A0DFA0
     * finalizeState:   VT+0x2AC 0x80A0DF90
     */
    sState_ExternVirtual(0x80B1564C, daEnGokubutoBigPileUpper_c, RetMove);
};
