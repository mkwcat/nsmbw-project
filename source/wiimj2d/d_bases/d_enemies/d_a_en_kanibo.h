#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnKanibo_c : public dEn_c {
    SIZE_ASSERT(0x660);
    VTABLE(0x060, fBase_c, 0x80AF4D20);
    // 0x80AF4C48 g_profile_EN_KANIBO
    // 0x80A3E700 daEnKanibo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnKanibo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x660);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A3F4D0
     * executeState:    0x80A3F500
     * finalizeState:   0x80A3F4F0
     */
    sState_Extern(0x80B173E8, daEnKanibo_c, Wait);

    /*
     * initializeState: 0x80A3F610
     * executeState:    0x80A3F640
     * finalizeState:   0x80A3F630
     */
    sState_Extern(0x80B17428, daEnKanibo_c, RockUp);

    /*
     * initializeState: 0x80A3F710
     * executeState:    0x80A3F780
     * finalizeState:   0x80A3F770
     */
    sState_Extern(0x80B17468, daEnKanibo_c, Jump);

    /*
     * initializeState: 0x80A3F870
     * executeState:    0x80A3F980
     * finalizeState:   0x80A3F970
     */
    sState_Extern(0x80B174A8, daEnKanibo_c, BackMove);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x16C 0x80A3FAB0
     * executeState:    VT+0x170 0x80A3FB70
     * finalizeState:   VT+0x174 0x80A3FB60
     */
    sState_ExternVirtual(0x80B174E4, daEnKanibo_c, DieFumi);

    /*
     * initializeState: VT+0x178 0x80A3FBC0
     * executeState:    VT+0x17C 0x80A3FC80
     * finalizeState:   VT+0x180 0x80A3FC70
     */
    sState_ExternVirtual(0x80B17524, daEnKanibo_c, DieFall);
};
