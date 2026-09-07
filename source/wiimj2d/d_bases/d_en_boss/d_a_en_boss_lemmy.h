#pragma once

#include "d_enemy_toride_kokoopa.h"
#include "s_State.h"

class daEnBossLemmy_c : public dEnTorideKokoopa_c {
    SIZE_ASSERT(0xFF0);
    VTABLE(0x060, fBase_c, 0x80B82D00);
    // 0x80B82840 g_profile_EN_BOSS_LEMMY
    // 0x80B545D0 daEnBossLemmy_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBossLemmy_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x600, 0xFF0);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x5E4 0x80B56000
     * executeState:    VT+0x5E8 0x80B56130
     * finalizeState:   VT+0x5EC 0x80B56120
     */
    sState_ExternVirtual(0x80B8CB94, daEnBossLemmy_c, Chase_St);

    /*
     * initializeState: VT+0x5F0 0x80B562D0
     * executeState:    VT+0x5F4 0x80B563D0
     * finalizeState:   VT+0x5F8 0x80B563C0
     */
    sState_ExternVirtual(0x80B8CBD4, daEnBossLemmy_c, Chase);

    /*
     * initializeState: VT+0x5FC 0x80B56520
     * executeState:    VT+0x600 0x80B56600
     * finalizeState:   VT+0x604 0x80B565F0
     */
    sState_ExternVirtual(0x80B8CC14, daEnBossLemmy_c, Chase_Ed);

    /*
     * initializeState: VT+0x608 0x80B567D0
     * executeState:    VT+0x60C 0x80B568B0
     * finalizeState:   VT+0x610 0x80B568A0
     */
    sState_ExternVirtual(0x80B8CC54, daEnBossLemmy_c, Stop);

    /*
     * initializeState: VT+0x3D8 0x80B569F0
     * executeState:    VT+0x3DC 0x80B56A60
     * finalizeState:   VT+0x3E0 0x80B56A50
     */
    sState_ExternVirtual(0x80B8CC94, daEnBossLemmy_c, AttackBegin);

    /*
     * initializeState: VT+0x3E4 0x80B56A70
     * executeState:    VT+0x3E8 0x80B56AF0
     * finalizeState:   VT+0x3EC 0x80B56AE0
     */
    sState_ExternVirtual(0x80B8CCD4, daEnBossLemmy_c, AttackSearch);

    /*
     * initializeState: VT+0x3F0 0x80B56C90
     * executeState:    VT+0x3F4 0x80B56D00
     * finalizeState:   VT+0x3F8 0x80B56CF0
     */
    sState_ExternVirtual(0x80B8CD14, daEnBossLemmy_c, Attack);

    /*
     * initializeState: VT+0x3FC 0x80B56D40
     * executeState:    VT+0x400 0x80B56DB0
     * finalizeState:   VT+0x404 0x80B56DA0
     */
    sState_ExternVirtual(0x80B8CD54, daEnBossLemmy_c, AttackEnd);

    /*
     * initializeState: VT+0x45C 0x80B56DC0
     * executeState:    VT+0x460 0x80B56FE0
     * finalizeState:   VT+0x464 0x80B56FD0
     */
    sState_ExternVirtual(0x80B8CD94, daEnBossLemmy_c, ShellAtk);

    /*
     * initializeState: VT+0x614 0x80B57260
     * executeState:    VT+0x618 0x80B57290
     * finalizeState:   VT+0x61C 0x80B57280
     */
    sState_ExternVirtual(0x80B8CDD4, daEnBossLemmy_c, ShellAtk_Ed);

    /*
     * initializeState: VT+0x468 0x80B573C0
     * executeState:    VT+0x46C 0x80B57420
     * finalizeState:   VT+0x470 0x80B57410
     */
    sState_ExternVirtual(0x80B8CE14, daEnBossLemmy_c, ShellOut);

    /*
     * initializeState: VT+0x16C 0x80B55E70
     * executeState:    VT+0x170 0x80B55F80
     * finalizeState:   VT+0x174 0x80B55F70
     */
    sState_ExternVirtual(0x80B8CE54, daEnBossLemmy_c, DieFumi);

    /*
     * initializeState: VT+0x280 0x80B57720
     * executeState:    VT+0x284 0x80B57880
     * finalizeState:   VT+0x288 0x80B57870
     */
    sState_ExternVirtual(0x80B8CE94, daEnBossLemmy_c, DemoWait);

    /*
     * initializeState: VT+0x5A0 0x80B57890
     * executeState:    VT+0x5A4 0x80B57900
     * finalizeState:   VT+0x5A8 0x80B578F0
     */
    sState_ExternVirtual(0x80B8CED4, daEnBossLemmy_c, DemoAwake);

    /*
     * initializeState: VT+0x5AC 0x80B57910
     * executeState:    VT+0x5B0 0x80B57980
     * finalizeState:   VT+0x5B4 0x80B57970
     */
    sState_ExternVirtual(0x80B8CF14, daEnBossLemmy_c, DemoAwake_Wait);

    /*
     * initializeState: VT+0x5B8 0x80B57990
     * executeState:    VT+0x5BC 0x80B57A00
     * finalizeState:   VT+0x5C0 0x80B579F0
     */
    sState_ExternVirtual(0x80B8CF54, daEnBossLemmy_c, DemoIkaku);

    /*
     * initializeState: VT+0x5C4 0x80B57A80
     * executeState:    VT+0x5C8 0x80B57AF0
     * finalizeState:   VT+0x5CC 0x80B57AE0
     */
    sState_ExternVirtual(0x80B8CF94, daEnBossLemmy_c, DemoIkaku_Wait);

    /*
     * initializeState: VT+0x620 0x80B57B00
     * executeState:    VT+0x624 0x80B57C20
     * finalizeState:   VT+0x628 0x80B57C10
     */
    sState_ExternVirtual(0x80B8CFD4, daEnBossLemmy_c, DemoFall);

    /*
     * initializeState: VT+0x62C 0x80B57CD0
     * executeState:    VT+0x630 0x80B57E20
     * finalizeState:   VT+0x634 0x80B57E10
     */
    sState_ExternVirtual(0x80B8D014, daEnBossLemmy_c, DemoFallEd);

    /*
     * initializeState: VT+0x5D0 0x80B57FD0
     * executeState:    VT+0x5D4 0x80B58090
     * finalizeState:   VT+0x5D8 0x80B58080
     */
    sState_ExternVirtual(0x80B8D054, daEnBossLemmy_c, DemoEscape_St);

    /*
     * initializeState: VT+0x638 0x80B581C0
     * executeState:    VT+0x63C 0x80B58270
     * finalizeState:   VT+0x640 0x80B58260
     */
    sState_ExternVirtual(0x80B8D094, daEnBossLemmy_c, DemoEscape_Ready);

    /*
     * initializeState: VT+0x644 0x80B58350
     * executeState:    VT+0x648 0x80B58550
     * finalizeState:   VT+0x64C 0x80B58540
     */
    sState_ExternVirtual(0x80B8D0D4, daEnBossLemmy_c, DemoEscape_Jump);
};
