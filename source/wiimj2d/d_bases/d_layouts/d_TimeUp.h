#pragma once

#include "d_base.h"
#include "s_State.h"

class dTimeUp_c : public dBase_c {
    SIZE_ASSERT(0x260);
    VTABLE(0x060, fBase_c, 0x80950858);
    // 0x80950768 g_profile_TIME_UP
    // 0x807B32D0 dTimeUp_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x807B3300 */
    dTimeUp_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x260);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807B37F0
     * executeState:    0x807B3800
     * finalizeState:   0x807B38B0
     */
    sState_Extern(0x80995B10, dTimeUp_c, DispWait);

    /*
     * initializeState: 0x807B38C0
     * executeState:    0x807B3920
     * finalizeState:   0x807B3980
     */
    sState_Extern(0x80995B50, dTimeUp_c, OpenAnimeEndWait);

    /*
     * initializeState: 0x807B3990
     * executeState:    0x807B39E0
     * finalizeState:   0x807B3A10
     */
    sState_Extern(0x80995B90, dTimeUp_c, DispEndWait);

    /*
     * initializeState: 0x807B3A20
     * executeState:    0x807B3A30
     * finalizeState:   0x807B3A90
     */
    sState_Extern(0x80995BD0, dTimeUp_c, ExitAnimeEndWait);
};
