#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnParaBomhei_c : public dEn_c {
    SIZE_ASSERT(0x840);
    VTABLE(0x060, fBase_c, 0x80B01AA8);
    // 0x80B01A40 g_profile_EN_PARA_BOMHEI
    // 0x80A7ED90 daEnParaBomhei_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnParaBomhei_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x840);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A7F5C0
     * executeState:    0x80A7F6A0
     * finalizeState:   0x80A7F680
     */
    sState_Extern(0x80B19B48, daEnParaBomhei_c, Fall);

    /*
     * initializeState: 0x80A7F7A0
     * executeState:    0x80A7F860
     * finalizeState:   0x80A7F850
     */
    sState_Extern(0x80B19B88, daEnParaBomhei_c, ParaEnd);

    /*
     * initializeState: 0x80A7F920
     * executeState:    0x80A7F9E0
     * finalizeState:   0x80A7F9D0
     */
    sState_Extern(0x80B19BC8, daEnParaBomhei_c, LandOn);
};
