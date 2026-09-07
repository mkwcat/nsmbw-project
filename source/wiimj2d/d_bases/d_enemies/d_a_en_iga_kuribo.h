#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnIgaKuribo_c : public dEn_c {
    SIZE_ASSERT(0x798);
    VTABLE(0x060, fBase_c, 0x80AF0448);
    // 0x80AF03D0 g_profile_EN_IGA_KURIBO
    // 0x80A22390 daEnIgaKuribo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnIgaKuribo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x798);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A23670
     * executeState:    0x80A23690
     * finalizeState:   0x80A23680
     */
    sState_Extern(0x80B162D8, daEnIgaKuribo_c, KyoroSt);

    /*
     * initializeState: 0x80A23700
     * executeState:    0x80A237B0
     * finalizeState:   0x80A237A0
     */
    sState_Extern(0x80B16318, daEnIgaKuribo_c, Kyoro);

    /*
     * initializeState: 0x80A23AF0
     * executeState:    0x80A23BE0
     * finalizeState:   0x80A23BD0
     */
    sState_Extern(0x80B16358, daEnIgaKuribo_c, Sleep);

    /*
     * initializeState: 0x80A23CF0
     * executeState:    0x80A23DF0
     * finalizeState:   0x80A23DE0
     */
    sState_Extern(0x80B16398, daEnIgaKuribo_c, Jump);

    /*
     * initializeState: 0x80A23890
     * executeState:    0x80A23900
     * finalizeState:   0x80A238F0
     */
    sState_Extern(0x80B163D8, daEnIgaKuribo_c, IgaWalk);

    /*
     * initializeState: 0x80A239D0
     * executeState:    0x80A23A00
     * finalizeState:   0x80A239F0
     */
    sState_Extern(0x80B16418, daEnIgaKuribo_c, IgaTurn);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x16C 0x80A23570
     * executeState:    VT+0x170 0x80A23600
     * finalizeState:   VT+0x174 0x80A235F0
     */
    sState_ExternVirtual(0x80B16454, daEnIgaKuribo_c, DieFumi);
};
