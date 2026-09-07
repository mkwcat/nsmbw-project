#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daFooBall_c : public dEn_c {
    SIZE_ASSERT(0x7D0);
    VTABLE(0x060, fBase_c, 0x8095BC78);
    // 0x8095BC18 g_profile_FOO_BALL
    // 0x807F5790 daFooBall_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daFooBall_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x7D0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807F5FF0
     * executeState:    0x807F6010
     * finalizeState:   0x807F6000
     */
    sState_Extern(0x80998870, daFooBall_c, Ready);

    /*
     * initializeState: 0x807F6070
     * executeState:    0x807F60C0
     * finalizeState:   0x807F60B0
     */
    sState_Extern(0x809988B0, daFooBall_c, Rise);

    /*
     * initializeState: 0x807F61D0
     * executeState:    0x807F6220
     * finalizeState:   0x807F6210
     */
    sState_Extern(0x809988F0, daFooBall_c, Rise_Wait);

    /*
     * initializeState: 0x807F6390
     * executeState:    0x807F63D0
     * finalizeState:   0x807F63C0
     */
    sState_Extern(0x80998930, daFooBall_c, Fall);

    /*
     * initializeState: 0x807F6460
     * executeState:    0x807F6490
     * finalizeState:   0x807F6480
     */
    sState_Extern(0x80998970, daFooBall_c, Fall_Wait);

    /*
     * initializeState: 0x807F6600
     * executeState:    0x807F6680
     * finalizeState:   0x807F6670
     */
    sState_Extern(0x809989B0, daFooBall_c, Drop);

    /*
     * initializeState: 0x807F6790
     * executeState:    0x807F6810
     * finalizeState:   0x807F6800
     */
    sState_Extern(0x809989F0, daFooBall_c, Break);
};
