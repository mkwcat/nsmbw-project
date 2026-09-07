#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daLemmyFootholdMain_c : public dEn_c {
    SIZE_ASSERT(0x6A8);
    VTABLE(0x060, fBase_c, 0x80966340);
    // 0x8096603C g_profile_LEMMY_FOOTHOLD_MAIN
    // 0x80833430 daLemmyFootholdMain_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLemmyFootholdMain_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x6A8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808338C0
     * executeState:    0x808338E0
     * finalizeState:   0x808338D0
     */
    sState_Extern(0x8099AE48, daLemmyFootholdMain_c, DemoWait);

    /*
     * initializeState: 0x808338F0
     * executeState:    0x80833910
     * finalizeState:   0x80833900
     */
    sState_Extern(0x8099AE88, daLemmyFootholdMain_c, Wait);
};
