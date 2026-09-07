#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnPairObjChild_c : public dEn_c {
    SIZE_ASSERT(0x4BA0);
    VTABLE(0x0060, fBase_c, 0x80B00EE0);
    // 0x80B00EB0 g_profile_EN_PAIR_OBJ_CHILD
    // 0x80A7CFC0 daEnPairObjChild_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80A7D820 */
    daEnPairObjChild_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0524, 0x4BA0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A7D8A0
     * executeState:    0x80A7D8C0
     * finalizeState:   0x80A7D8B0
     */
    sState_Extern(0x80B19970, daEnPairObjChild_c, Searchparent);

    /*
     * initializeState: 0x80A7DA20
     * executeState:    0x80A7DB00
     * finalizeState:   0x80A7DAF0
     */
    sState_Extern(0x80B199B0, daEnPairObjChild_c, Move);

    /*
     * initializeState: 0x80A7DBF0
     * executeState:    0x80A7DC60
     * finalizeState:   0x80A7DC50
     */
    sState_Extern(0x80B199F0, daEnPairObjChild_c, Vanish);
};
