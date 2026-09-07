#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnGessoChild_c : public dEn_c {
    SIZE_ASSERT(0x5C8);
    VTABLE(0x060, fBase_c, 0x80AEB938);
    // 0x80AEB8E8 g_profile_EN_GESSO_CHILD
    // 0x80A083A0 daEnGessoChild_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnGessoChild_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5C8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A08B20
     * executeState:    0x80A08BB0
     * finalizeState:   0x80A08BA0
     */
    sState_Extern(0x80B15330, daEnGessoChild_c, Follow);

    /*
     * initializeState: 0x80A08D60
     * executeState:    0x80A08DA0
     * finalizeState:   0x80A08D80
     */
    sState_Extern(0x80B15370, daEnGessoChild_c, Hide);

    /*
     * initializeState: 0x80A08BC0
     * executeState:    0x80A08C30
     * finalizeState:   0x80A08C20
     */
    sState_Extern(0x80B153B0, daEnGessoChild_c, Attack);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x80A08A60
     * executeState:    VT+0x17C 0x80A08A80
     * finalizeState:   VT+0x180 0x80A08A70
     */
    sState_ExternVirtual(0x80B153EC, daEnGessoChild_c, DieFall);

    /*
     * initializeState: VT+0x190 0x80A08A90
     * executeState:    VT+0x194 0x80A08B10
     * finalizeState:   VT+0x198 0x80A08B00
     */
    sState_ExternVirtual(0x80B1542C, daEnGessoChild_c, DieSmoke);
};
