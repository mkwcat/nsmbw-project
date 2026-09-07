#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnBigTogetekkyu_c : public dEn_c {
    SIZE_ASSERT(0x798);
    VTABLE(0x060, fBase_c, 0x80AD8CE0);
    // 0x80AD8C70 g_profile_EN_BIG_TOGETEKKYU
    // 0x809B73A0 daEnBigTogetekkyu_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBigTogetekkyu_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x798);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809B7AD0
     * executeState:    0x809B7B20
     * finalizeState:   0x809B7B10
     */
    sState_Extern(0x80B12178, daEnBigTogetekkyu_c, Move);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x809B7D60
     * executeState:    VT+0x17C 0x809B7D80
     * finalizeState:   VT+0x180 0x809B7D70
     */
    sState_ExternVirtual(0x80B121B4, daEnBigTogetekkyu_c, DieFall);
};
