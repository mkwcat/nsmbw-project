#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnIgaPuku_c : public dEn_c {
    SIZE_ASSERT(0x848);
    VTABLE(0x060, fBase_c, 0x80AF09B0);
    // 0x80AF0950 g_profile_EN_IGAPUKU
    // 0x80A24A30 daEnIgaPuku_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnIgaPuku_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x848);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A25950
     * executeState:    0x80A259D0
     * finalizeState:   0x80A259C0
     */
    sState_Extern(0x80B16498, daEnIgaPuku_c, Swim);

    /*
     * initializeState: 0x80A25B80
     * executeState:    0x80A25BC0
     * finalizeState:   0x80A25BB0
     */
    sState_Extern(0x80B164D8, daEnIgaPuku_c, Turn);

    /*
     * initializeState: 0x80A25C90
     * executeState:    0x80A25D20
     * finalizeState:   0x80A25D10
     */
    sState_Extern(0x80B16518, daEnIgaPuku_c, JumpReady);

    /*
     * initializeState: 0x80A25E00
     * executeState:    0x80A25EA0
     * finalizeState:   0x80A25E80
     */
    sState_Extern(0x80B16558, daEnIgaPuku_c, Jump);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x80A25FF0
     * executeState:    VT+0x17C 0x80A26050
     * finalizeState:   VT+0x180 0x80A26040
     */
    sState_ExternVirtual(0x80B16594, daEnIgaPuku_c, DieFall);
};
