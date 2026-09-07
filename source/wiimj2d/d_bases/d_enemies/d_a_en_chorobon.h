#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnChorobon_c : public dEn_c {
    SIZE_ASSERT(0x6C0);
    VTABLE(0x060, fBase_c, 0x80AE0638);
    // 0x80AE0608 g_profile_EN_CHOROBON
    // 0x809D76E0 daEnChorobon_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnChorobon_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x6C0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809D8010
     * executeState:    0x809D8110
     * finalizeState:   0x809D8100
     */
    sState_Extern(0x80B131F8, daEnChorobon_c, Move);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x809D8160
     * executeState:    VT+0x17C 0x809D81C0
     * finalizeState:   VT+0x180 0x809D81B0
     */
    sState_ExternVirtual(0x80B13234, daEnChorobon_c, DieFall);

    /*
     * initializeState: VT+0x1FC 0x809D8370
     * executeState:    VT+0x200 0x809D8390
     * finalizeState:   VT+0x204 0x809D8380
     */
    sState_ExternVirtual(0x80B13274, daEnChorobon_c, Ice);
};
