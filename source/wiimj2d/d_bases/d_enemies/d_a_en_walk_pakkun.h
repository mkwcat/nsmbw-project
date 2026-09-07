#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnWalkPakkun_c : public dEn_c {
    SIZE_ASSERT(0x5F8);
    VTABLE(0x060, fBase_c, 0x80B0DAC8);
    // 0x80B0DA58 g_profile_EN_WALK_PAKKUN
    // 0x80ABCFE0 daEnWalkPakkun_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnWalkPakkun_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5F8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80ABDDB0
     * executeState:    0x80ABDED0
     * finalizeState:   0x80ABDEC0
     */
    sState_Extern(0x80B1C058, daEnWalkPakkun_c, Walk);

    /*
     * initializeState: 0x80ABE060
     * executeState:    0x80ABE090
     * finalizeState:   0x80ABE080
     */
    sState_Extern(0x80B1C098, daEnWalkPakkun_c, Turn);

    /*
     * initializeState: 0x80ABE190
     * executeState:    0x80ABE260
     * finalizeState:   0x80ABE250
     */
    sState_Extern(0x80B1C0D8, daEnWalkPakkun_c, AttackSt);

    /*
     * initializeState: 0x80ABE390
     * executeState:    0x80ABE430
     * finalizeState:   0x80ABE420
     */
    sState_Extern(0x80B1C118, daEnWalkPakkun_c, Attack);

    /*
     * initializeState: 0x80ABE4D0
     * executeState:    0x80ABE590
     * finalizeState:   0x80ABE580
     */
    sState_Extern(0x80B1C158, daEnWalkPakkun_c, AttackEd);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x80ABE6F0
     * executeState:    VT+0x17C 0x80ABE8C0
     * finalizeState:   VT+0x180 0x80ABE8B0
     */
    sState_ExternVirtual(0x80B1C194, daEnWalkPakkun_c, DieFall);
};
