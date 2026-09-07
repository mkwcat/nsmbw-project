#pragma once

#include "d_enemy_toride_kokoopa.h"
#include "s_State.h"

class daEnBossLarry_c : public dEnTorideKokoopa_c {
    SIZE_ASSERT(0xE98);
    VTABLE(0x060, fBase_c, 0x80B81E54);
    // 0x80B81980 g_profile_EN_BOSS_LARRY
    // 0x80B515F0 daEnBossLarry_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBossLarry_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x600, 0xE98);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x5E4 0x80B52490
     * executeState:    VT+0x5E8 0x80B52520
     * finalizeState:   VT+0x5EC 0x80B52510
     */
    sState_ExternVirtual(0x80B8C94C, daEnBossLarry_c, Dance);

    /*
     * initializeState: VT+0x16C 0x80B525B0
     * executeState:    VT+0x170 0x80B52720
     * finalizeState:   VT+0x174 0x80B52710
     */
    sState_ExternVirtual(0x80B8C98C, daEnBossLarry_c, DieFumi);

    /*
     * initializeState: VT+0x5F0 0x80B527C0
     * executeState:    VT+0x5F4 0x80B528E0
     * finalizeState:   VT+0x5F8 0x80B528D0
     */
    sState_ExternVirtual(0x80B8C9CC, daEnBossLarry_c, DemoFall);

    /*
     * initializeState: VT+0x5FC 0x80B52980
     * executeState:    VT+0x600 0x80B52AD0
     * finalizeState:   VT+0x604 0x80B52AC0
     */
    sState_ExternVirtual(0x80B8CA0C, daEnBossLarry_c, DemoFallEd);

    /*
     * initializeState: VT+0x5D0 0x80B52C60
     * executeState:    VT+0x5D4 0x80B52D90
     * finalizeState:   VT+0x5D8 0x80B52D80
     */
    sState_ExternVirtual(0x80B8CA4C, daEnBossLarry_c, DemoEscape_St);

    /*
     * initializeState: VT+0x608 0x80B52EC0
     * executeState:    VT+0x60C 0x80B52F70
     * finalizeState:   VT+0x610 0x80B52F60
     */
    sState_ExternVirtual(0x80B8CA8C, daEnBossLarry_c, DemoEscape_Ready);

    /*
     * initializeState: VT+0x614 0x80B53040
     * executeState:    VT+0x618 0x80B53230
     * finalizeState:   VT+0x61C 0x80B53220
     */
    sState_ExternVirtual(0x80B8CACC, daEnBossLarry_c, DemoEscape_Jump);

    /*
     * initializeState: VT+0x45C 0x80B532F0
     * executeState:    VT+0x460 0x80B53530
     * finalizeState:   VT+0x464 0x80B53520
     */
    sState_ExternVirtual(0x80B8CB0C, daEnBossLarry_c, ShellAtk);

    /*
     * initializeState: VT+0x620 0x80B53730
     * executeState:    VT+0x624 0x80B53760
     * finalizeState:   VT+0x628 0x80B53750
     */
    sState_ExternVirtual(0x80B8CB4C, daEnBossLarry_c, ShellAtk_Ed);
};
