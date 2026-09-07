#pragma once

#include "d_a_en_blockmain.h"
#include "s_State.h"

class daAutoScroolSwich_c : public daEnBlockMain_c {
    SIZE_ASSERT(0x780);
    VTABLE(0x060, fBase_c, 0x8095102C);
    // 0x80950FF0 g_profile_AC_AUTOSCROOL_SWICH
    // 0x807B77D0 daAutoScroolSwich_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daAutoScroolSwich_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x698, 0x780);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807B8290
     * executeState:    0x807B82B0
     * finalizeState:   0x807B82A0
     */
    sState_Extern(0x80995E90, daAutoScroolSwich_c, Wait);

    /*
     * initializeState: 0x807B82C0
     * executeState:    0x807B8310
     * finalizeState:   0x807B82D0
     */
    sState_Extern(0x80995ED0, daAutoScroolSwich_c, HitWait);
};
