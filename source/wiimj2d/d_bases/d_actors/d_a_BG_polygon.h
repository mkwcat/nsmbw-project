#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daBGpolygon_c : public dActorState_c {
    SIZE_ASSERT(0x1A500);
    VTABLE(0x00060, fBase_c, 0x80950B48);

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBGpolygon_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x003D0, 0x1A500);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807B5F10
     * executeState:    0x807B5F30
     * finalizeState:   0x807B5F20
     */
    sState_Extern(0x80995C10, daBGpolygon_c, NonMove);

    /*
     * initializeState: 0x807B6100
     * executeState:    0x807B6120
     * finalizeState:   0x807B6110
     */
    sState_Extern(0x80995C50, daBGpolygon_c, Switch);

    /*
     * initializeState: 0x807B5F40
     * executeState:    0x807B5F60
     * finalizeState:   0x807B5F50
     */
    sState_Extern(0x80995C90, daBGpolygon_c, AutoScroll);

    /*
     * initializeState: 0x807B62F0
     * executeState:    0x807B6330
     * finalizeState:   0x807B6320
     */
    sState_Extern(0x80995CD0, daBGpolygon_c, WaitAutoScroll);

    /*
     * initializeState: 0x807B6690
     * executeState:    0x807B6710
     * finalizeState:   0x807B6700
     */
    sState_Extern(0x80995D10, daBGpolygon_c, SwitchAutoScrDownWait);

    /*
     * initializeState: 0x807B67F0
     * executeState:    0x807B6810
     * finalizeState:   0x807B6800
     */
    sState_Extern(0x80995D50, daBGpolygon_c, SwitchAutoScrReserveUp);

    /*
     * initializeState: 0x807B68D0
     * executeState:    0x807B6900
     * finalizeState:   0x807B68F0
     */
    sState_Extern(0x80995D90, daBGpolygon_c, SwitchAutoScrUpMove);

    /*
     * initializeState: 0x807B69D0
     * executeState:    0x807B6A00
     * finalizeState:   0x807B69F0
     */
    sState_Extern(0x80995DD0, daBGpolygon_c, SwitchAutoScrUpWait);

    /*
     * initializeState: 0x807B6AC0
     * executeState:    0x807B6AE0
     * finalizeState:   0x807B6AD0
     */
    sState_Extern(0x80995E10, daBGpolygon_c, SwitchAutoScrReserveDown);

    /*
     * initializeState: 0x807B6BB0
     * executeState:    0x807B6BE0
     * finalizeState:   0x807B6BD0
     */
    sState_Extern(0x80995E50, daBGpolygon_c, SwitchAutoScrDownMove);
};

class daBGWater_c : public daBGpolygon_c {
    SIZE_ASSERT(0x1A500);
    // 0x80950B00 g_profile_AC_BG_WATER
    // 0x807B40A0 daBGWater_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBGWater_c() {}
};

class daBGLava_c : public daBGpolygon_c {
    SIZE_ASSERT(0x1A500);
    // 0x80950B0C g_profile_AC_BG_LAVA
    // 0x807B44A0 daBGLava_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBGLava_c();
};

class daBGPoison_c : public daBGpolygon_c {
    SIZE_ASSERT(0x1A500);
    // 0x80950B18 g_profile_AC_BG_POISON
    // 0x807B4650 daBGPoison_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBGPoison_c() {}
};

class daBGSand_c : public daBGpolygon_c {
    SIZE_ASSERT(0x1A500);
    // 0x80950B24 g_profile_AC_BG_SAND
    // 0x807B4800 daBGSand_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBGSand_c() {}
};

class daBGCloud_c : public daBGpolygon_c {
    SIZE_ASSERT(0x1A500);
    // 0x80950B30 g_profile_AC_BG_CLOUD
    // 0x807B49B0 daBGCloud_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBGCloud_c() {}
};

class daBGMoya_c : public daBGpolygon_c {
    SIZE_ASSERT(0x1A500);
    // 0x80950B3C g_profile_AC_BG_MOYA
    // 0x807B4B60 daBGMoya_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBGMoya_c() {}
};
