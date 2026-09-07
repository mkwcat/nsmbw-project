#pragma once

#include "d_enemy_toride_kokoopa.h"
#include "s_State.h"

class daEnBossRoy_c : public dEnTorideKokoopa_c {
    SIZE_ASSERT(0x10E8);
    VTABLE(0x0060, fBase_c, 0x80B86320);
    // 0x80B85E28 g_profile_EN_BOSS_ROY
    // 0x80B63160 daEnBossRoy_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBossRoy_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0600, 0x10E8);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x5E4 0x80B642F0
     * executeState:    VT+0x5E8 0x80B64320
     * finalizeState:   VT+0x5EC 0x80B64310
     */
    sState_ExternVirtual(0x80B8DA24, daEnBossRoy_c, AirSpin);

    /*
     * initializeState: VT+0x5F0 0x80B64360
     * executeState:    VT+0x5F4 0x80B64380
     * finalizeState:   VT+0x5F8 0x80B64370
     */
    sState_ExternVirtual(0x80B8DA64, daEnBossRoy_c, AirWait);

    /*
     * initializeState: VT+0x5FC 0x80B643B0
     * executeState:    VT+0x600 0x80B644A0
     * finalizeState:   VT+0x604 0x80B64450
     */
    sState_ExternVirtual(0x80B8DAA4, daEnBossRoy_c, QuakeFall);

    /*
     * initializeState: VT+0x608 0x80B64570
     * executeState:    VT+0x60C 0x80B646B0
     * finalizeState:   VT+0x610 0x80B646A0
     */
    sState_ExternVirtual(0x80B8DAE4, daEnBossRoy_c, Quake);

    /*
     * initializeState: VT+0x16C 0x80B64740
     * executeState:    VT+0x170 0x80B64860
     * finalizeState:   VT+0x174 0x80B64850
     */
    sState_ExternVirtual(0x80B8DB24, daEnBossRoy_c, DieFumi);

    /*
     * initializeState: VT+0x3B4 0x80B641C0
     * executeState:    VT+0x3B8 0x80B64220
     * finalizeState:   VT+0x3BC 0x80B64210
     */
    sState_ExternVirtual(0x80B8DB64, daEnBossRoy_c, BigJump);

    /*
     * initializeState: VT+0x5A0 0x80B648E0
     * executeState:    VT+0x5A4 0x80B64980
     * finalizeState:   VT+0x5A8 0x80B64970
     */
    sState_ExternVirtual(0x80B8DBA4, daEnBossRoy_c, DemoAwake);

    /*
     * initializeState: VT+0x5AC 0x80B64A40
     * executeState:    VT+0x5B0 0x80B64AD0
     * finalizeState:   VT+0x5B4 0x80B64AC0
     */
    sState_ExternVirtual(0x80B8DBE4, daEnBossRoy_c, DemoAwake_Wait);

    /*
     * initializeState: VT+0x5B8 0x80B64B40
     * executeState:    VT+0x5BC 0x80B64BE0
     * finalizeState:   VT+0x5C0 0x80B64BD0
     */
    sState_ExternVirtual(0x80B8DC24, daEnBossRoy_c, DemoIkaku);

    /*
     * initializeState: VT+0x5C4 0x80B64CB0
     * executeState:    VT+0x5C8 0x80B64D50
     * finalizeState:   VT+0x5CC 0x80B64D40
     */
    sState_ExternVirtual(0x80B8DC64, daEnBossRoy_c, DemoIkaku_Wait);

    /*
     * initializeState: VT+0x628 0x80B65370
     * executeState:    VT+0x62C 0x80B65430
     * finalizeState:   VT+0x630 0x80B65420
     */
    sState_ExternVirtual(0x80B8DCA4, daEnBossRoy_c, DemoFall);

    /*
     * initializeState: VT+0x634 0x80B654C0
     * executeState:    VT+0x638 0x80B655D0
     * finalizeState:   VT+0x63C 0x80B655C0
     */
    sState_ExternVirtual(0x80B8DCE4, daEnBossRoy_c, DemoFallEd);

    /*
     * initializeState: VT+0x5D0 0x80B65760
     * executeState:    VT+0x5D4 0x80B65830
     * finalizeState:   VT+0x5D8 0x80B65820
     */
    sState_ExternVirtual(0x80B8DD24, daEnBossRoy_c, DemoEscape_St);

    /*
     * initializeState: VT+0x640 0x80B65950
     * executeState:    VT+0x644 0x80B65A00
     * finalizeState:   VT+0x648 0x80B659F0
     */
    sState_ExternVirtual(0x80B8DD64, daEnBossRoy_c, DemoEscape_Ready);

    /*
     * initializeState: VT+0x64C 0x80B65AD0
     * executeState:    VT+0x650 0x80B65CD0
     * finalizeState:   VT+0x654 0x80B65CC0
     */
    sState_ExternVirtual(0x80B8DDA4, daEnBossRoy_c, DemoEscape_Jump);

    /*
     * initializeState: VT+0x45C 0x80B64DE0
     * executeState:    VT+0x460 0x80B65020
     * finalizeState:   VT+0x464 0x80B65010
     */
    sState_ExternVirtual(0x80B8DDE4, daEnBossRoy_c, ShellAtk);

    /*
     * initializeState: VT+0x614 0x80B65220
     * executeState:    VT+0x618 0x80B65250
     * finalizeState:   VT+0x61C 0x80B65240
     */
    sState_ExternVirtual(0x80B8DE24, daEnBossRoy_c, ShellAtk_Ed);
};
