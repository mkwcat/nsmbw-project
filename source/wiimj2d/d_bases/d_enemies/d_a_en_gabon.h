#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnGabon_c : public dEn_c {
    SIZE_ASSERT(0x668);
    VTABLE(0x060, fBase_c, 0x80AEA570);
    // 0x80AEA4D0 g_profile_EN_GABON
    // 0x809FFFD0 daEnGabon_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnGabon_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x668);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A01000
     * executeState:    0x80A01080
     * finalizeState:   0x80A01070
     */
    sState_Extern(0x80B14A40, daEnGabon_c, Appear);

    /*
     * initializeState: 0x80A01230
     * executeState:    0x80A01340
     * finalizeState:   0x80A01330
     */
    sState_Extern(0x80B14A80, daEnGabon_c, Move);

    /*
     * initializeState: 0x80A01540
     * executeState:    0x80A01560
     * finalizeState:   0x80A01550
     */
    sState_Extern(0x80B14AC0, daEnGabon_c, MoveEd);

    /*
     * initializeState: 0x80A01730
     * executeState:    0x80A017A0
     * finalizeState:   0x80A01790
     */
    sState_Extern(0x80B14B00, daEnGabon_c, Attack);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x16C 0x80A01960
     * executeState:    VT+0x170 0x80A019C0
     * finalizeState:   VT+0x174 0x80A019B0
     */
    sState_ExternVirtual(0x80B14B3C, daEnGabon_c, DieFumi);

    /*
     * initializeState: VT+0x178 0x80A01A60
     * executeState:    VT+0x17C 0x80A01AC0
     * finalizeState:   VT+0x180 0x80A01AB0
     */
    sState_ExternVirtual(0x80B14B7C, daEnGabon_c, DieFall);
};
