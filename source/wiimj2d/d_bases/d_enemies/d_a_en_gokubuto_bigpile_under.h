#pragma once

#include "d_a_en_super_bigpile.h"
#include "s_State.h"

class daEnGokubutoBigPileUnder_c : public daEnSuperBigPile_c {
    SIZE_ASSERT(0x6A8);
    VTABLE(0x060, fBase_c, 0x80AEC524);
    // 0x80AEC4E8 g_profile_EN_GOKUBUTO_BIGPILE_UNDER
    // 0x80A0BE30 daEnGokubutoBigPileUnder_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnGokubutoBigPileUnder_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x6A0, 0x6A8);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x28C 0x80A0C910
     * executeState:    VT+0x290 0x80A0C970
     * finalizeState:   VT+0x294 0x80A0C960
     */
    sState_ExternVirtual(0x80B1558C, daEnGokubutoBigPileUnder_c, GoMove);

    /*
     * initializeState: VT+0x2A4 0x80A0CAB0
     * executeState:    VT+0x2A8 0x80A0CAD0
     * finalizeState:   VT+0x2AC 0x80A0CAC0
     */
    sState_ExternVirtual(0x80B155CC, daEnGokubutoBigPileUnder_c, RetMove);
};
