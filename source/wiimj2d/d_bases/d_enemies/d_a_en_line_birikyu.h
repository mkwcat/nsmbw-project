#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnLineBirikyu_c : public dEn_c {
    SIZE_ASSERT(0x828);
    VTABLE(0x060, fBase_c, 0x80AFA418);
    // 0x80AFA400 g_profile_EN_LINE_BIRIKYU
    // 0x80A5F190 daEnLineBirikyu_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnLineBirikyu_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x828);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A5F6D0
     * executeState:    0x80A5F7B0
     * finalizeState:   0x80A5F750
     */
    sState_Extern(0x80B185B8, daEnLineBirikyu_c, Appear);
};
