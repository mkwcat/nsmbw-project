#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnBirikyu_c : public dEn_c {
    SIZE_ASSERT(0x730);
    VTABLE(0x060, fBase_c, 0x80ADA5B8);
    // 0x80ADA578 g_profile_EN_BIRIKYU
    // 0x809BC4F0 daEnBirikyu_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBirikyu_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x730);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809BCEA0
     * executeState:    0x809BCF30
     * finalizeState:   0x809BCF20
     */
    sState_Extern(0x80B12478, daEnBirikyu_c, Wait);

    /*
     * initializeState: 0x809BCFA0
     * executeState:    0x809BD040
     * finalizeState:   0x809BD030
     */
    sState_Extern(0x80B124B8, daEnBirikyu_c, Attack);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x809BD0D0
     * executeState:    VT+0x17C 0x809BD260
     * finalizeState:   VT+0x180 0x809BD250
     */
    sState_ExternVirtual(0x80B124F4, daEnBirikyu_c, DieFall);
};
