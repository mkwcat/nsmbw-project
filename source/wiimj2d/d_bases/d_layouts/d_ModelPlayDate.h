#pragma once

#include "d_base.h"
#include "s_State.h"

class dModelPlayDate_c : public dBase_c {
    SIZE_ASSERT(0x2A0);
    VTABLE(0x060, fBase_c, 0x809488E0);
    // 0x80948640 g_profile_MODEL_PLAY_DATE
    // 0x80793E60 dModelPlayDate_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80793E90 */
    dModelPlayDate_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x2A0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80794950
     * executeState:    0x80794960
     * finalizeState:   0x807949A0
     */
    sState_Extern(0x80993908, dModelPlayDate_c, ActionWait);

    /*
     * initializeState: 0x807949D0
     * executeState:    0x80794A60
     * finalizeState:   0x80794B00
     */
    sState_Extern(0x80993948, dModelPlayDate_c, AnimeEndWait);
};
