#pragma once

#include "d_a_en_kuribo_base.h"
#include "s_State.h"

class daEnPataKuribo_c : public daEnKuriboBase_c {
    SIZE_ASSERT(0x8E8);
    VTABLE(0x060, fBase_c, 0x80B02360);
    // 0x80B02318 g_profile_EN_PATA_KURIBO
    // 0x80A81790 daEnPataKuribo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnPataKuribo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x85C, 0x8E8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A82150
     * executeState:    0x80A822C0
     * finalizeState:   0x80A822B0
     */
    sState_Extern(0x80B19D08, daEnPataKuribo_c, Pata_Walk);

    /*
     * initializeState: 0x80A824A0
     * executeState:    0x80A824F0
     * finalizeState:   0x80A824E0
     */
    sState_Extern(0x80B19D48, daEnPataKuribo_c, Pata_Turn);
};
