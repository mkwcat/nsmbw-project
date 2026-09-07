#pragma once

#include "d_enemy_toride_kokoopa.h"
#include "s_State.h"

class daEnBossLudwig_c : public dEnTorideKokoopa_c {
    SIZE_ASSERT(0x1118);
    VTABLE(0x0060, fBase_c, 0x80B83FE8);
    // 0x80B83AD8 g_profile_EN_BOSS_LUDWIG
    // 0x80B59EC0 daEnBossLudwig_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBossLudwig_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0600, 0x1118);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x5E4 0x80B5AF10
     * executeState:    VT+0x5E8 0x80B5AFC0
     * finalizeState:   VT+0x5EC 0x80B5AFB0
     */
    sState_ExternVirtual(0x80B8D11C, daEnBossLudwig_c, AirBegin);

    /*
     * initializeState: VT+0x5F0 0x80B5B0A0
     * executeState:    VT+0x5F4 0x80B5B1B0
     * finalizeState:   VT+0x5F8 0x80B5B1A0
     */
    sState_ExternVirtual(0x80B8D15C, daEnBossLudwig_c, AirJump);

    /*
     * initializeState: VT+0x5FC 0x80B5B290
     * executeState:    VT+0x600 0x80B5B3B0
     * finalizeState:   VT+0x604 0x80B5B3A0
     */
    sState_ExternVirtual(0x80B8D19C, daEnBossLudwig_c, AirRise_1st);

    /*
     * initializeState: VT+0x608 0x80B5B4B0
     * executeState:    VT+0x60C 0x80B5B5D0
     * finalizeState:   VT+0x610 0x80B5B5C0
     */
    sState_ExternVirtual(0x80B8D1DC, daEnBossLudwig_c, AirRise);

    /*
     * initializeState: VT+0x614 0x80B5B780
     * executeState:    VT+0x618 0x80B5B830
     * finalizeState:   VT+0x61C 0x80B5B820
     */
    sState_ExternVirtual(0x80B8D21C, daEnBossLudwig_c, AirFall);

    /*
     * initializeState: VT+0x620 0x80B5BA50
     * executeState:    VT+0x624 0x80B5BB70
     * finalizeState:   VT+0x628 0x80B5BB60
     */
    sState_ExternVirtual(0x80B8D25C, daEnBossLudwig_c, AirEd);

    /*
     * initializeState: VT+0x62C 0x80B5BD20
     * executeState:    VT+0x630 0x80B5BE60
     * finalizeState:   VT+0x634 0x80B5BE50
     */
    sState_ExternVirtual(0x80B8D29C, daEnBossLudwig_c, AirEd2);

    /*
     * initializeState: VT+0x638 0x80B5BF80
     * executeState:    VT+0x63C 0x80B5C030
     * finalizeState:   VT+0x640 0x80B5C020
     */
    sState_ExternVirtual(0x80B8D2DC, daEnBossLudwig_c, AirHigh);

    /*
     * initializeState: VT+0x644 0x80B5C160
     * executeState:    VT+0x648 0x80B5C200
     * finalizeState:   VT+0x64C 0x80B5C1F0
     */
    sState_ExternVirtual(0x80B8D31C, daEnBossLudwig_c, AirStomp);

    /*
     * initializeState: VT+0x3C0 0x80B5C2B0
     * executeState:    VT+0x3C4 0x80B5C380
     * finalizeState:   VT+0x3C8 0x80B5C370
     */
    sState_ExternVirtual(0x80B8D35C, daEnBossLudwig_c, LandOn);

    /*
     * initializeState: VT+0x16C 0x80B5CB40
     * executeState:    VT+0x170 0x80B5CC70
     * finalizeState:   VT+0x174 0x80B5CC60
     */
    sState_ExternVirtual(0x80B8D39C, daEnBossLudwig_c, DieFumi);

    /*
     * initializeState: VT+0x3E4 0x80B5C420
     * executeState:    VT+0x3E8 0x80B5C470
     * finalizeState:   VT+0x3EC 0x80B5C460
     */
    sState_ExternVirtual(0x80B8D3DC, daEnBossLudwig_c, AttackSearch);

    /*
     * initializeState: VT+0x3F0 0x80B5C6B0
     * executeState:    VT+0x3F4 0x80B5C700
     * finalizeState:   VT+0x3F8 0x80B5C6F0
     */
    sState_ExternVirtual(0x80B8D41C, daEnBossLudwig_c, Attack);

    /*
     * initializeState: VT+0x650 0x80B5C860
     * executeState:    VT+0x654 0x80B5C8F0
     * finalizeState:   VT+0x658 0x80B5C8E0
     */
    sState_ExternVirtual(0x80B8D45C, daEnBossLudwig_c, QuickAttackSt);

    /*
     * initializeState: VT+0x65C 0x80B5C990
     * executeState:    VT+0x660 0x80B5C9F0
     * finalizeState:   VT+0x664 0x80B5C9E0
     */
    sState_ExternVirtual(0x80B8D49C, daEnBossLudwig_c, QuickAttack);

    /*
     * initializeState: VT+0x668 0x80B5CCF0
     * executeState:    VT+0x66C 0x80B5CE10
     * finalizeState:   VT+0x670 0x80B5CE00
     */
    sState_ExternVirtual(0x80B8D4DC, daEnBossLudwig_c, DemoFall);

    /*
     * initializeState: VT+0x674 0x80B5CEB0
     * executeState:    VT+0x678 0x80B5D000
     * finalizeState:   VT+0x67C 0x80B5CFF0
     */
    sState_ExternVirtual(0x80B8D51C, daEnBossLudwig_c, DemoFallEd);

    /*
     * initializeState: VT+0x5D0 0x80B5D1A0
     * executeState:    VT+0x5D4 0x80B5D2C0
     * finalizeState:   VT+0x5D8 0x80B5D2B0
     */
    sState_ExternVirtual(0x80B8D55C, daEnBossLudwig_c, DemoEscape_St);

    /*
     * initializeState: VT+0x680 0x80B5D3F0
     * executeState:    VT+0x684 0x80B5D4A0
     * finalizeState:   VT+0x688 0x80B5D490
     */
    sState_ExternVirtual(0x80B8D59C, daEnBossLudwig_c, DemoEscape_Ready);

    /*
     * initializeState: VT+0x68C 0x80B5D570
     * executeState:    VT+0x690 0x80B5D760
     * finalizeState:   VT+0x694 0x80B5D750
     */
    sState_ExternVirtual(0x80B8D5DC, daEnBossLudwig_c, DemoEscape_Jump);

    /*
     * initializeState: VT+0x45C 0x80B5D820
     * executeState:    VT+0x460 0x80B5DA60
     * finalizeState:   VT+0x464 0x80B5DA50
     */
    sState_ExternVirtual(0x80B8D61C, daEnBossLudwig_c, ShellAtk);

    /*
     * initializeState: VT+0x698 0x80B5DC60
     * executeState:    VT+0x69C 0x80B5DC90
     * finalizeState:   VT+0x6A0 0x80B5DC80
     */
    sState_ExternVirtual(0x80B8D65C, daEnBossLudwig_c, ShellAtk_Ed);
};
