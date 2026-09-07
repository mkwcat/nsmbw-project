#pragma once

#include "d_enemy.h"

class dCc_c;

class daEnDpakkunBase_c : public dEn_c {
    SIZE_ASSERT(0x6E0);
    VTABLE(0x060, fBase_c, 0x80304248);

public:
    // Virtual Methods
    // ^^^^^^

    /* 0x8002D730 */
    bool hitCallback_YoshiHipAttk(dCc_c* main, dCc_c* other) override;

public:
    // Static Methods
    // ^^^^^^

    /* 0x8002DAB0 */
    static bool isPlayerDemo();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x6E0);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x8002E500
     * executeState:    VT+0x284 0x8002E520
     * finalizeState:   VT+0x288 0x8002E510
     */
    sState_ExternVirtual(0x8035354C, daEnDpakkunBase_c, Wait);

    /*
     * initializeState: VT+0x28C 0x8002E530
     * executeState:    VT+0x290 0x8002E550
     * finalizeState:   VT+0x294 0x8002E540
     */
    sState_ExternVirtual(0x8035358C, daEnDpakkunBase_c, Appear);

    /*
     * initializeState: VT+0x298 0x8002E560
     * executeState:    VT+0x29C 0x8002E580
     * finalizeState:   VT+0x2A0 0x8002E570
     */
    sState_ExternVirtual(0x803535CC, daEnDpakkunBase_c, Attack);

    /*
     * initializeState: VT+0x2A4 0x8002E590
     * executeState:    VT+0x2A8 0x8002E5B0
     * finalizeState:   VT+0x2AC 0x8002E5A0
     */
    sState_ExternVirtual(0x8035360C, daEnDpakkunBase_c, Disappear);

    /*
     * initializeState: VT+0x2B0 0x8002E330
     * executeState:    VT+0x2B4 0x8002E440
     * finalizeState:   VT+0x2B8 0x8002E430
     */
    sState_ExternVirtual(0x8035364C, daEnDpakkunBase_c, DieIceBreak);

    /*
     * initializeState: VT+0x2BC 0x8002E250
     * executeState:    VT+0x2C0 0x8002E2D0
     * finalizeState:   VT+0x2C4 0x8002E2C0
     */
    sState_ExternVirtual(0x8035368C, daEnDpakkunBase_c, DieVanish);
};
