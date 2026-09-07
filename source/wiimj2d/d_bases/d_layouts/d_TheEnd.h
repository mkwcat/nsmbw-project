#pragma once

#include "d_base.h"
#include "s_State.h"

class dTheEnd_c : public dBase_c {
    SIZE_ASSERT(0x24C);
    VTABLE(0x060, fBase_c, 0x809504B8);
    // 0x80950428 g_profile_THE_END
    // 0x807B2540 dTheEnd_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x807B2570 */
    dTheEnd_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x24C);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807B2A60
     * executeState:    0x807B2AB0
     * finalizeState:   0x807B2AF0
     */
    sState_Extern(0x80995A10, dTheEnd_c, OnStageWait);

    /*
     * initializeState: 0x807B2B00
     * executeState:    0x807B2B60
     * finalizeState:   0x807B2BC0
     */
    sState_Extern(0x80995A50, dTheEnd_c, OnStageAnimeEndWait);

    /*
     * initializeState: 0x807B2BD0
     * executeState:    0x807B2BE0
     * finalizeState:   0x807B2C10
     */
    sState_Extern(0x80995A90, dTheEnd_c, NowDisp);

    /*
     * initializeState: 0x807B2C20
     * executeState:    0x807B2C60
     * finalizeState:   0x807B2CC0
     */
    sState_Extern(0x80995AD0, dTheEnd_c, ExitAnimeEndWait);
};
