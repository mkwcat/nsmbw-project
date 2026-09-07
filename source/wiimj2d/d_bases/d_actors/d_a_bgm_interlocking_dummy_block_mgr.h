#pragma once

#include "d_actor.h"
#include "s_State.h"

class daBgmInterlockingDummyBlockMgr_c : public dActor_c {
    SIZE_ASSERT(0x400);
    VTABLE(0x060, fBase_c, 0x8095255C);
    // 0x80952550 g_profile_BGM_INTERLOCKING_DUMMY_BLOCK_MGR
    // 0x807BD820 daBgmInterlockingDummyBlockMgr_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x807BD850 */
    daBgmInterlockingDummyBlockMgr_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x400);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807BDC00
     * executeState:    0x807BDC10
     * finalizeState:   0x807BDC20
     */
    sState_Extern(0x809962B8, daBgmInterlockingDummyBlockMgr_c, Wait);
};
