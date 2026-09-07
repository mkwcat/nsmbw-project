#pragma once

#include "d_a_en_kuribo_base.h"
#include "s_State.h"

class daEnKuribo_c : public daEnKuriboBase_c {
    SIZE_ASSERT(0x878);
    VTABLE(0x060, fBase_c, 0x80AF7DE8);
    // 0x80AF7DD0 g_profile_EN_KURIBO
    // 0x80A55F20 daEnKuribo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnKuribo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x85C, 0x878);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A567E0
     * executeState:    0x80A56920
     * finalizeState:   0x80A56910
     */
    sState_Extern(0x80B18070, daEnKuribo_c, Born_Split1);

    /*
     * initializeState: 0x80A56930
     * executeState:    0x80A56AA0
     * finalizeState:   0x80A56A90
     */
    sState_Extern(0x80B180B0, daEnKuribo_c, Born_Split2);

    /*
     * initializeState: 0x80A56CA0
     * executeState:    0x80A56CC0
     * finalizeState:   0x80A56CB0
     */
    sState_Extern(0x80B180F0, daEnKuribo_c, BlockAppear);

    /*
     * initializeState: 0x80A56730
     * executeState:    0x80A56780
     * finalizeState:   0x80A56770
     */
    sState_Extern(0x80B18130, daEnKuribo_c, Down);

    /*
     * initializeState: 0x80A56EF0
     * executeState:    0x80A57020
     * finalizeState:   0x80A57010
     */
    sState_Extern(0x80B18170, daEnKuribo_c, Auto_Walk);

    /*
     * initializeState: 0x80A56D90
     * executeState:    0x80A56E40
     * finalizeState:   0x80A56E30
     */
    sState_Extern(0x80B181B0, daEnKuribo_c, Dokan_Down);

    /*
     * initializeState: 0x80A56CF0
     * executeState:    0x80A56D10
     * finalizeState:   0x80A56D00
     */
    sState_Extern(0x80B181F0, daEnKuribo_c, EatOut_Ready);
};
