#pragma once

#include "d_base.h"
#include "s_State.h"

class dDemoMessage_c : public dBase_c {
    SIZE_ASSERT(0x264);
    VTABLE(0x060, fBase_c, 0x809424E8);
    // 0x80942400 g_profile_DEMO_MESSAGE
    // 0x8077E590 dDemoMessage_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8077E5C0 */
    dDemoMessage_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x264);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8077EAC0
     * executeState:    0x8077EAD0
     * finalizeState:   0x8077EB10
     */
    sState_Extern(0x80991A28, dDemoMessage_c, StartWait);

    /*
     * initializeState: 0x8077EB20
     * executeState:    0x8077EC70
     * finalizeState:   0x8077ECD0
     */
    sState_Extern(0x80991A68, dDemoMessage_c, StartAnimeEndWait);

    /*
     * initializeState: 0x8077ECF0
     * executeState:    0x8077ED00
     * finalizeState:   0x8077ED30
     */
    sState_Extern(0x80991AA8, dDemoMessage_c, ExitWait);

    /*
     * initializeState: 0x8077ED40
     * executeState:    0x8077ED90
     * finalizeState:   0x8077EDF0
     */
    sState_Extern(0x80991AE8, dDemoMessage_c, ExitAnimeEndWait);
};
