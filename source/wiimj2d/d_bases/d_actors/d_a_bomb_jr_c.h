#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daBombJrC_c : public dEn_c {
    SIZE_ASSERT(0x7B0);
    VTABLE(0x060, fBase_c, 0x809537C4);
    // 0x80953700 g_profile_BOMB_JR_C
    // 0x807C4370 daBombJrC_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x807C45E0 */
    daBombJrC_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x7B0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807C5700
     * executeState:    0x807C57C0
     * finalizeState:   0x807C57B0
     */
    sState_Extern(0x809968A0, daBombJrC_c, Appear);

    /*
     * initializeState: 0x807C58E0
     * executeState:    0x807C5900
     * finalizeState:   0x807C58F0
     */
    sState_Extern(0x809968E0, daBombJrC_c, Fall);

    /*
     * initializeState: 0x807C5A60
     * executeState:    0x807C5B30
     * finalizeState:   0x807C5B20
     */
    sState_Extern(0x80996920, daBombJrC_c, RollOver);

    /*
     * initializeState: 0x807C5C90
     * executeState:    0x807C5D10
     * finalizeState:   0x807C5D00
     */
    sState_Extern(0x80996960, daBombJrC_c, Rise);

    /*
     * initializeState: 0x807C5E30
     * executeState:    0x807C6020
     * finalizeState:   0x807C6010
     */
    sState_Extern(0x809969A0, daBombJrC_c, Explode);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x807C5690
     * executeState:    VT+0x284 0x807C56B0
     * finalizeState:   VT+0x288 0x807C56A0
     */
    sState_ExternVirtual(0x8099685C, daBombJrC_c, DemoWait);

    /*
     * initializeState: VT+0x178 0x807C6040
     * executeState:    VT+0x17C 0x807C60F0
     * finalizeState:   VT+0x180 0x807C60E0
     */
    sState_ExternVirtual(0x809969DC, daBombJrC_c, DieFall);
};
