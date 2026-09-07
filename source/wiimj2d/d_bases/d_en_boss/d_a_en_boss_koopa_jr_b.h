#pragma once

#include "d_enemy_boss_koopa_jr_base.h"
#include "s_State.h"

class daEnBossKoopaJrB_c : public dEnBossKoopaJrBase_c {
    SIZE_ASSERT(0xD78);
    VTABLE(0x060, fBase_c, 0x80B80ACC);
    // 0x80B80A38 g_profile_EN_BOSS_KOOPA_JR_B
    // 0x80B4C9D0 daEnBossKoopaJrB_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80B4CA70 */
    daEnBossKoopaJrB_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0xC3C, 0xD78);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80B4D550
     * executeState:    0x80B4D630
     * finalizeState:   0x80B4D620
     */
    sState_Extern(0x80B8C610, daEnBossKoopaJrB_c, DemoSt);

    /*
     * initializeState: 0x80B4DD20
     * executeState:    0x80B4DD40
     * finalizeState:   0x80B4DD30
     */
    sState_Extern(0x80B8C690, daEnBossKoopaJrB_c, DemoEd);

    /*
     * initializeState: 0x80B4DE40
     * executeState:    0x80B4DF50
     * finalizeState:   0x80B4DF40
     */
    sState_Extern(0x80B8C710, daEnBossKoopaJrB_c, NeedleHitRot);

    /*
     * initializeState: 0x80B4DFA0
     * executeState:    0x80B4DFF0
     * finalizeState:   0x80B4DFB0
     */
    sState_Extern(0x80B8C750, daEnBossKoopaJrB_c, NeedleHitRotDamp);

    /*
     * initializeState: 0x80B4E110
     * executeState:    0x80B4E130
     * finalizeState:   0x80B4E120
     */
    sState_Extern(0x80B8C790, daEnBossKoopaJrB_c, NeedleHitRotEnd);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x390 0x80B4DBB0
     * executeState:    VT+0x394 0x80B4DCC0
     * finalizeState:   VT+0x398 0x80B4DCB0
     */
    sState_ExternVirtual(0x80B8C64C, daEnBossKoopaJrB_c, DemoAwake);

    /*
     * initializeState: VT+0x3E4 0x80B4DD50
     * executeState:    VT+0x3E8 0x80B4DDE0
     * finalizeState:   VT+0x3EC 0x80B4DDD0
     */
    sState_ExternVirtual(0x80B8C6D0, daEnBossKoopaJrB_c, Stoop);

    /*
     * initializeState: VT+0x178 0x80B4E140
     * executeState:    VT+0x17C 0x80B4E1C0
     * finalizeState:   VT+0x180 0x80B4E1B0
     */
    sState_ExternVirtual(0x80B8C7CC, daEnBossKoopaJrB_c, DieFall);
};
