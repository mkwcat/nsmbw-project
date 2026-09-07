#pragma once

#include "d_enemy.h"

class daEnPataMet_c : public dEn_c {
    SIZE_ASSERT(0x838);
    VTABLE(0x060, fBase_c, 0x80B027E8);
    // 0x80B02730 g_profile_EN_PATAMET
    // 0x80A82A70 daEnPatamet_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnPataMet_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x838);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A83CF0
     * executeState:    0x80A83D20
     * finalizeState:   0x80A83D10
     */
    sState_Extern(0x80B19D88, daEnPataMet_c, Move);
};

class daEnBigPataMet_c : public daEnPataMet_c {
    SIZE_ASSERT(0x838);
    // 0x80B0273C g_profile_EN_BIG_PATAMET
    // 0x80A82B50 daEnBigPataMet_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBigPataMet_c();
};
