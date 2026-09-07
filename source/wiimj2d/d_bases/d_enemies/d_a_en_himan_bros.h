#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnHimanBros_c : public dEn_c {
    SIZE_ASSERT(0x748);
    VTABLE(0x060, fBase_c, 0x80AEE518);
    // 0x80AEE408 g_profile_EN_HIMANBROS
    // 0x80A16040 daEnHimanBros_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnHimanBros_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x748);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A176C0
     * executeState:    0x80A17760
     * finalizeState:   0x80A17750
     */
    sState_Extern(0x80B15A88, daEnHimanBros_c, Attack);

    /*
     * initializeState: 0x80A17930
     * executeState:    0x80A17950
     * finalizeState:   0x80A17940
     */
    sState_Extern(0x80B15AC8, daEnHimanBros_c, AttackEd);

    /*
     * initializeState: 0x80A17A40
     * executeState:    0x80A17AC0
     * finalizeState:   0x80A17AB0
     */
    sState_Extern(0x80B15B08, daEnHimanBros_c, Jump_St);

    /*
     * initializeState: 0x80A17BC0
     * executeState:    0x80A17C60
     * finalizeState:   0x80A17C50
     */
    sState_Extern(0x80B15B48, daEnHimanBros_c, JumpAttack);

    /*
     * initializeState: 0x80A17E30
     * executeState:    0x80A17EB0
     * finalizeState:   0x80A17EA0
     */
    sState_Extern(0x80B15B88, daEnHimanBros_c, JumpAttack_Ed);

    /*
     * initializeState: 0x80A17F80
     * executeState:    0x80A18000
     * finalizeState:   0x80A17FF0
     */
    sState_Extern(0x80B15BC8, daEnHimanBros_c, Quake);

    /*
     * initializeState: 0x80A18150
     * executeState:    0x80A181C0
     * finalizeState:   0x80A181B0
     */
    sState_Extern(0x80B15C08, daEnHimanBros_c, Quake_Ed);

    /*
     * initializeState: 0x80A172A0
     * executeState:    0x80A17380
     * finalizeState:   0x80A17350
     */
    sState_Extern(0x80B15C48, daEnHimanBros_c, Walk);

    /*
     * initializeState: 0x80A17520
     * executeState:    0x80A17560
     * finalizeState:   0x80A17550
     */
    sState_Extern(0x80B15C88, daEnHimanBros_c, Turn);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x16C 0x80A18230
     * executeState:    VT+0x170 0x80A18290
     * finalizeState:   VT+0x174 0x80A18280
     */
    sState_ExternVirtual(0x80B15CC4, daEnHimanBros_c, DieFumi);

    /*
     * initializeState: VT+0x178 0x80A182E0
     * executeState:    VT+0x17C 0x80A18340
     * finalizeState:   VT+0x180 0x80A18330
     */
    sState_ExternVirtual(0x80B15D04, daEnHimanBros_c, DieFall);
};
