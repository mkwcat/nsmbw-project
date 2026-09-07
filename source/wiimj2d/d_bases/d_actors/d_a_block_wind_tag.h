#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daBlockWindTag_c : public dActorState_c {
    SIZE_ASSERT(0x408);
    VTABLE(0x060, fBase_c, 0x80953510);
    // 0x80953500 g_profile_AC_BLOCK_WIND_TAG
    // 0x807C35A0 daBlockWindTag_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBlockWindTag_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x408);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807C3BD0
     * executeState:    0x807C3BF0
     * finalizeState:   0x807C3BE0
     */
    sState_Extern(0x809967A0, daBlockWindTag_c, SearchID);

    /*
     * initializeState: 0x807C3C70
     * executeState:    0x807C3C90
     * finalizeState:   0x807C3C80
     */
    sState_Extern(0x809967E0, daBlockWindTag_c, Move);

    /*
     * initializeState: 0x807C3D40
     * executeState:    0x807C3D70
     * finalizeState:   0x807C3D60
     */
    sState_Extern(0x80996820, daBlockWindTag_c, TimingMove);
};
