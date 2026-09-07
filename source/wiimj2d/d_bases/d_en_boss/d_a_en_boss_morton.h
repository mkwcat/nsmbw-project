#pragma once

#include "d_enemy_toride_kokoopa.h"
#include "s_State.h"

class daEnBossMorton_c : public dEnTorideKokoopa_c {
    SIZE_ASSERT(0xEA0);
    VTABLE(0x060, fBase_c, 0x80B852B8);
    // 0x80B84E10 g_profile_EN_BOSS_MORTON
    // 0x80B5F5A0 daEnBossMorton_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBossMorton_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x600, 0xEA0);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x5E4 0x80B60C30
     * executeState:    VT+0x5E8 0x80B60C60
     * finalizeState:   VT+0x5EC 0x80B60C50
     */
    sState_ExternVirtual(0x80B8D6A4, daEnBossMorton_c, AirSpin);

    /*
     * initializeState: VT+0x5F0 0x80B60CA0
     * executeState:    VT+0x5F4 0x80B60CC0
     * finalizeState:   VT+0x5F8 0x80B60CB0
     */
    sState_ExternVirtual(0x80B8D6E4, daEnBossMorton_c, AirWait);

    /*
     * initializeState: VT+0x5FC 0x80B60CF0
     * executeState:    VT+0x600 0x80B60DE0
     * finalizeState:   VT+0x604 0x80B60D90
     */
    sState_ExternVirtual(0x80B8D724, daEnBossMorton_c, QuakeFall);

    /*
     * initializeState: VT+0x608 0x80B60E90
     * executeState:    VT+0x60C 0x80B60F80
     * finalizeState:   VT+0x610 0x80B60F70
     */
    sState_ExternVirtual(0x80B8D764, daEnBossMorton_c, Quake);

    /*
     * initializeState: VT+0x614 0x80B611F0
     * executeState:    VT+0x618 0x80B61260
     * finalizeState:   VT+0x61C 0x80B61250
     */
    sState_ExternVirtual(0x80B8D7A4, daEnBossMorton_c, ShellAtk_Ed);

    /*
     * initializeState: VT+0x16C 0x80B613B0
     * executeState:    VT+0x170 0x80B614D0
     * finalizeState:   VT+0x174 0x80B614C0
     */
    sState_ExternVirtual(0x80B8D7E4, daEnBossMorton_c, DieFumi);

    /*
     * initializeState: VT+0x39C 0x80B60A30
     * executeState:    VT+0x3A0 0x80B60AC0
     * finalizeState:   VT+0x3A4 0x80B60AB0
     */
    sState_ExternVirtual(0x80B8D824, daEnBossMorton_c, Jump);

    /*
     * initializeState: VT+0x3B4 0x80B60AD0
     * executeState:    VT+0x3B8 0x80B60B60
     * finalizeState:   VT+0x3BC 0x80B60B50
     */
    sState_ExternVirtual(0x80B8D864, daEnBossMorton_c, BigJump);

    /*
     * initializeState: VT+0x45C 0x80B61010
     * executeState:    VT+0x460 0x80B61090
     * finalizeState:   VT+0x464 0x80B61080
     */
    sState_ExternVirtual(0x80B8D8A4, daEnBossMorton_c, ShellAtk);

    /*
     * initializeState: VT+0x620 0x80B61550
     * executeState:    VT+0x624 0x80B61670
     * finalizeState:   VT+0x628 0x80B61660
     */
    sState_ExternVirtual(0x80B8D8E4, daEnBossMorton_c, DemoFall);

    /*
     * initializeState: VT+0x62C 0x80B61710
     * executeState:    VT+0x630 0x80B61860
     * finalizeState:   VT+0x634 0x80B61850
     */
    sState_ExternVirtual(0x80B8D924, daEnBossMorton_c, DemoFallEd);

    /*
     * initializeState: VT+0x5D0 0x80B61A00
     * executeState:    VT+0x5D4 0x80B61B20
     * finalizeState:   VT+0x5D8 0x80B61B10
     */
    sState_ExternVirtual(0x80B8D964, daEnBossMorton_c, DemoEscape_St);

    /*
     * initializeState: VT+0x638 0x80B61C20
     * executeState:    VT+0x63C 0x80B61CD0
     * finalizeState:   VT+0x640 0x80B61CC0
     */
    sState_ExternVirtual(0x80B8D9A4, daEnBossMorton_c, DemoEscape_Ready);

    /*
     * initializeState: VT+0x644 0x80B61DA0
     * executeState:    VT+0x648 0x80B61FA0
     * finalizeState:   VT+0x64C 0x80B61F90
     */
    sState_ExternVirtual(0x80B8D9E4, daEnBossMorton_c, DemoEscape_Jump);
};
