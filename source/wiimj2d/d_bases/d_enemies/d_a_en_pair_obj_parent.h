#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnPairObjParent_c : public dEn_c {
    SIZE_ASSERT(0x5A8);
    VTABLE(0x060, fBase_c, 0x80B01548);
    // 0x80B01538 g_profile_EN_PAIR_OBJ_PARENT
    // 0x80A7E2F0 daEnPairObjParent_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnPairObjParent_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5A8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A7E590
     * executeState:    0x80A7E5B0
     * finalizeState:   0x80A7E5A0
     */
    sState_Extern(0x80B19A48, daEnPairObjParent_c, Still);

    /*
     * initializeState: 0x80A7E5C0
     * executeState:    0x80A7E5E0
     * finalizeState:   0x80A7E5D0
     */
    sState_Extern(0x80B19A88, daEnPairObjParent_c, Vanish);

    /*
     * initializeState: 0x80A7E6D0
     * executeState:    0x80A7E720
     * finalizeState:   0x80A7E710
     */
    sState_Extern(0x80B19AC8, daEnPairObjParent_c, MoveForever);

    /*
     * initializeState: 0x80A7E7B0
     * executeState:    0x80A7E7D0
     * finalizeState:   0x80A7E7C0
     */
    sState_Extern(0x80B19B08, daEnPairObjParent_c, MoveNormal);
};
