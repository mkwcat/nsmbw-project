#pragma once

#include "d_enemy_toride_kokoopa.h"
#include "s_State.h"

class daEnBossCastleLemmy_c : public dEnTorideKokoopa_c {
    SIZE_ASSERT(0x1138);
    VTABLE(0x0060, fBase_c, 0x80B776B8);
    // 0x80B77600 g_profile_EN_BOSS_CASTLE_LEMMY
    // 0x80B234A0 daEnBossCastleLemmy_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBossCastleLemmy_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0600, 0x1138);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80B242B0
     * executeState:    0x80B243A0
     * finalizeState:   0x80B24390
     */
    sState_Extern(0x80B8A140, daEnBossCastleLemmy_c, FillAir);

    /*
     * initializeState: 0x80B24AA0
     * executeState:    0x80B24AD0
     * finalizeState:   0x80B24AC0
     */
    sState_Extern(0x80B8A180, daEnBossCastleLemmy_c, Chase_Lst);

    /*
     * initializeState: 0x80B25690
     * executeState:    0x80B256E0
     * finalizeState:   0x80B256A0
     */
    sState_Extern(0x80B8A340, daEnBossCastleLemmy_c, DemoAwakeEnd);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x5E4 0x80B244B0
     * executeState:    VT+0x5E8 0x80B245C0
     * finalizeState:   VT+0x5EC 0x80B245B0
     */
    sState_ExternVirtual(0x80B8A1BC, daEnBossCastleLemmy_c, Chase_St);

    /*
     * initializeState: VT+0x5F0 0x80B246F0
     * executeState:    VT+0x5F4 0x80B24890
     * finalizeState:   VT+0x5F8 0x80B24880
     */
    sState_ExternVirtual(0x80B8A1FC, daEnBossCastleLemmy_c, Chase);

    /*
     * initializeState: VT+0x5FC 0x80B24CB0
     * executeState:    VT+0x600 0x80B24D80
     * finalizeState:   VT+0x604 0x80B24D70
     */
    sState_ExternVirtual(0x80B8A23C, daEnBossCastleLemmy_c, Chase_Ed);

    /*
     * initializeState: VT+0x468 0x80B24FC0
     * executeState:    VT+0x46C 0x80B24FE0
     * finalizeState:   VT+0x470 0x80B24FD0
     */
    sState_ExternVirtual(0x80B8A27C, daEnBossCastleLemmy_c, ShellOut);

    /*
     * initializeState: VT+0x280 0x80B25370
     * executeState:    VT+0x284 0x80B253F0
     * finalizeState:   VT+0x288 0x80B253B0
     */
    sState_ExternVirtual(0x80B8A2BC, daEnBossCastleLemmy_c, DemoWait);

    /*
     * initializeState: VT+0x5A0 0x80B25540
     * executeState:    VT+0x5A4 0x80B25600
     * finalizeState:   VT+0x5A8 0x80B255F0
     */
    sState_ExternVirtual(0x80B8A2FC, daEnBossCastleLemmy_c, DemoAwake);

    /*
     * initializeState: VT+0x16C 0x80B25800
     * executeState:    VT+0x170 0x80B25940
     * finalizeState:   VT+0x174 0x80B25930
     */
    sState_ExternVirtual(0x80B8A37C, daEnBossCastleLemmy_c, DieFumi);
};
