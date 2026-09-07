#pragma once

#include "d_enemy_toride_kokoopa.h"
#include "s_State.h"

class daEnBossCastleLudwig_c : public dEnTorideKokoopa_c {
    SIZE_ASSERT(0x12E8);
    VTABLE(0x0060, fBase_c, 0x80B78290);
    // 0x80B78148 g_profile_EN_BOSS_CASTLE_LUDWIG
    // 0x80B269F0 daEnBossCastleLudwig_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBossCastleLudwig_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0600, 0x12E8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80B28130
     * executeState:    0x80B28220
     * finalizeState:   0x80B28210
     */
    sState_Extern(0x80B8A408, daEnBossCastleLudwig_c, AirStruggle);

    /*
     * initializeState: 0x80B28F70
     * executeState:    0x80B29010
     * finalizeState:   0x80B29000
     */
    sState_Extern(0x80B8A488, daEnBossCastleLudwig_c, GoUpToAirship);

    /*
     * initializeState: 0x80B292E0
     * executeState:    0x80B29300
     * finalizeState:   0x80B292F0
     */
    sState_Extern(0x80B8A4C8, daEnBossCastleLudwig_c, ReachAtAirship);

    /*
     * initializeState: 0x80B29850
     * executeState:    0x80B29880
     * finalizeState:   0x80B29860
     */
    sState_Extern(0x80B8A688, daEnBossCastleLudwig_c, DemoAwakeEnd);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x5F0 0x80B27F30
     * executeState:    VT+0x5F4 0x80B28050
     * finalizeState:   VT+0x5F8 0x80B28040
     */
    sState_ExternVirtual(0x80B8A3C4, daEnBossCastleLudwig_c, AirJump);

    /*
     * initializeState: VT+0x644 0x80B28300
     * executeState:    VT+0x648 0x80B28380
     * finalizeState:   VT+0x64C 0x80B28370
     */
    sState_ExternVirtual(0x80B8A444, daEnBossCastleLudwig_c, AirStomp);

    /*
     * initializeState: VT+0x408 0x80B28390
     * executeState:    VT+0x40C 0x80B283F0
     * finalizeState:   VT+0x410 0x80B283E0
     */
    sState_ExternVirtual(0x80B8A504, daEnBossCastleLudwig_c, FumiHit);

    /*
     * initializeState: VT+0x45C 0x80B28430
     * executeState:    VT+0x460 0x80B28530
     * finalizeState:   VT+0x464 0x80B28520
     */
    sState_ExternVirtual(0x80B8A544, daEnBossCastleLudwig_c, ShellAtk);

    /*
     * initializeState: VT+0x698 0x80B287C0
     * executeState:    VT+0x69C 0x80B28830
     * finalizeState:   VT+0x6A0 0x80B28820
     */
    sState_ExternVirtual(0x80B8A588, daEnBossCastleLudwig_c, ShellAtk_Ed);

    /*
     * initializeState: VT+0x16C 0x80B28DD0
     * executeState:    VT+0x170 0x80B28E20
     * finalizeState:   VT+0x174 0x80B28E10
     */
    sState_ExternVirtual(0x80B8A5C4, daEnBossCastleLudwig_c, DieFumi);

    /*
     * initializeState: VT+0x280 0x80B29310
     * executeState:    VT+0x284 0x80B29390
     * finalizeState:   VT+0x288 0x80B29350
     */
    sState_ExternVirtual(0x80B8A604, daEnBossCastleLudwig_c, DemoWait);

    /*
     * initializeState: VT+0x5A0 0x80B294E0
     * executeState:    VT+0x5A4 0x80B295C0
     * finalizeState:   VT+0x5A8 0x80B295B0
     */
    sState_ExternVirtual(0x80B8A644, daEnBossCastleLudwig_c, DemoAwake);

    /*
     * initializeState: VT+0x3E4 0x80B28980
     * executeState:    VT+0x3E8 0x80B289A0
     * finalizeState:   VT+0x3EC 0x80B28990
     */
    sState_ExternVirtual(0x80B8A6C4, daEnBossCastleLudwig_c, AttackSearch);

    /*
     * initializeState: VT+0x3F0 0x80B28BD0
     * executeState:    VT+0x3F4 0x80B28C50
     * finalizeState:   VT+0x3F8 0x80B28C40
     */
    sState_ExternVirtual(0x80B8A704, daEnBossCastleLudwig_c, Attack);
};
