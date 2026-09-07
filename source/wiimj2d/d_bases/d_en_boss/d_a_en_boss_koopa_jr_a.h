#pragma once

#include "d_enemy_boss_koopa_jr_base.h"
#include "s_State.h"

class daEnBossKoopaJrA_c : public dEnBossKoopaJrBase_c {
    SIZE_ASSERT(0xD98);
    VTABLE(0x060, fBase_c, 0x80B803C4);
    // 0x80B80328 g_profile_EN_BOSS_KOOPA_JR_A
    // 0x80B4ADB0 daEnBossKoopaJrA_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80B4ADF0 */
    daEnBossKoopaJrA_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0xC3C, 0xD98);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80B4B900
     * executeState:    0x80B4B9E0
     * finalizeState:   0x80B4B9D0
     */
    sState_Extern(0x80B8C4D8, daEnBossKoopaJrA_c, DemoSt);

    /*
     * initializeState: 0x80B4C020
     * executeState:    0x80B4C040
     * finalizeState:   0x80B4C030
     */
    sState_Extern(0x80B8C558, daEnBossKoopaJrA_c, DemoEd);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x390 0x80B4BF30
     * executeState:    VT+0x394 0x80B4BFC0
     * finalizeState:   VT+0x398 0x80B4BFB0
     */
    sState_ExternVirtual(0x80B8C514, daEnBossKoopaJrA_c, DemoAwake);

    /*
     * initializeState: VT+0x178 0x80B4C050
     * executeState:    VT+0x17C 0x80B4C0D0
     * finalizeState:   VT+0x180 0x80B4C0C0
     */
    sState_ExternVirtual(0x80B8C594, daEnBossKoopaJrA_c, DieFall);
};
