#pragma once

#include "d_enemy_boss_koopa_jr_base.h"
#include "s_State.h"

class daEnBossKoopaJrC_c : public dEnBossKoopaJrBase_c {
    SIZE_ASSERT(0xCB8);
    VTABLE(0x060, fBase_c, 0x80B81378);
    // 0x80B81278 g_profile_EN_BOSS_KOOPA_JR_C
    // 0x80B4EC70 daEnBossKoopaJrC_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80B4ECA0 */
    daEnBossKoopaJrC_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0xC3C, 0xCB8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80B50A50
     * executeState:    0x80B50B40
     * finalizeState:   0x80B50B30
     */
    sState_Extern(0x80B8C850, daEnBossKoopaJrC_c, DemoSt);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x80B506B0
     * executeState:    VT+0x284 0x80B50780
     * finalizeState:   VT+0x288 0x80B50770
     */
    sState_ExternVirtual(0x80B8C80C, daEnBossKoopaJrC_c, DemoWait);

    /*
     * initializeState: VT+0x390 0x80B50BA0
     * executeState:    VT+0x394 0x80B50C30
     * finalizeState:   VT+0x398 0x80B50C20
     */
    sState_ExternVirtual(0x80B8C88C, daEnBossKoopaJrC_c, DemoAwake);

    /*
     * initializeState: VT+0x3B4 0x80B50C80
     * executeState:    VT+0x3B8 0x80B50D20
     * finalizeState:   VT+0x3BC 0x80B50D10
     */
    sState_ExternVirtual(0x80B8C8CC, daEnBossKoopaJrC_c, FumiHitRot);

    /*
     * initializeState: VT+0x178 0x80B50D30
     * executeState:    VT+0x17C 0x80B50DA0
     * finalizeState:   VT+0x180 0x80B50D90
     */
    sState_ExternVirtual(0x80B8C90C, daEnBossKoopaJrC_c, DieFall);
};
