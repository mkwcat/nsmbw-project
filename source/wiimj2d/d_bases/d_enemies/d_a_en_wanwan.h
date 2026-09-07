#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnWanWan_c : public dEn_c {
    SIZE_ASSERT(0x6D8);
    VTABLE(0x060, fBase_c, 0x80B0E280);
    // 0x80B0E230 g_profile_EN_WANWAN
    // 0x80ABF4B0 daEnWanWan_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnWanWan_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x6D8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80AC0B70
     * executeState:    0x80AC0C80
     * finalizeState:   0x80AC0C70
     */
    sState_Extern(0x80B1C1D8, daEnWanWan_c, Walk);

    /*
     * initializeState: 0x80AC0EA0
     * executeState:    0x80AC0FC0
     * finalizeState:   0x80AC0FB0
     */
    sState_Extern(0x80B1C218, daEnWanWan_c, AttackReady);

    /*
     * initializeState: 0x80AC1120
     * executeState:    0x80AC11E0
     * finalizeState:   0x80AC11D0
     */
    sState_Extern(0x80B1C258, daEnWanWan_c, Attack);

    /*
     * initializeState: 0x80AC1360
     * executeState:    0x80AC14C0
     * finalizeState:   0x80AC1450
     */
    sState_Extern(0x80B1C298, daEnWanWan_c, AttackEnd);

    /*
     * initializeState: 0x80AC15A0
     * executeState:    0x80AC16F0
     * finalizeState:   0x80AC16E0
     */
    sState_Extern(0x80B1C2D8, daEnWanWan_c, Release);

    /*
     * initializeState: 0x80AC1B50
     * executeState:    0x80AC1C20
     * finalizeState:   0x80AC1C10
     */
    sState_Extern(0x80B1C318, daEnWanWan_c, DieCrush);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x1E4 0x80AC18A0
     * executeState:    VT+0x1E8 0x80AC19E0
     * finalizeState:   VT+0x1EC 0x80AC19D0
     */
    sState_ExternVirtual(0x80B1C354, daEnWanWan_c, EatOut);

    /*
     * initializeState: VT+0x178 0x80AC0A50
     * executeState:    VT+0x17C 0x80AC0B20
     * finalizeState:   VT+0x180 0x80AC0B10
     */
    sState_ExternVirtual(0x80B1C394, daEnWanWan_c, DieFall);
};
