#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daBgmInterlockingDummyBlock_c : public dEn_c {
    SIZE_ASSERT(0x610);
    VTABLE(0x060, fBase_c, 0x80952000);
    // 0x80951F90 g_profile_BGM_INTERLOCKING_DUMMY_BLOCK
    // 0x807BBDA0 daBgmInterlockingDummyBlock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBgmInterlockingDummyBlock_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x610);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807BC3F0
     * executeState:    0x807BC530
     * finalizeState:   0x807BC520
     */
    sState_Extern(0x809960F8, daBgmInterlockingDummyBlock_c, WaitForLeader);

    /*
     * initializeState: 0x807BC700
     * executeState:    0x807BC720
     * finalizeState:   0x807BC710
     */
    sState_Extern(0x80996138, daBgmInterlockingDummyBlock_c, WaitForNormal);

    /*
     * initializeState: 0x807BC9F0
     * executeState:    0x807BCA10
     * finalizeState:   0x807BCA00
     */
    sState_Extern(0x80996178, daBgmInterlockingDummyBlock_c, MoveRightLeader);

    /*
     * initializeState: 0x807BCD00
     * executeState:    0x807BCD20
     * finalizeState:   0x807BCD10
     */
    sState_Extern(0x809961B8, daBgmInterlockingDummyBlock_c, MoveLeftLeader);

    /*
     * initializeState: 0x807BCB70
     * executeState:    0x807BCB90
     * finalizeState:   0x807BCB80
     */
    sState_Extern(0x809961F8, daBgmInterlockingDummyBlock_c, MoveRightNormal);

    /*
     * initializeState: 0x807BCE80
     * executeState:    0x807BCEA0
     * finalizeState:   0x807BCE90
     */
    sState_Extern(0x80996238, daBgmInterlockingDummyBlock_c, MoveLeftNormal);

    /*
     * initializeState: 0x807BC680
     * executeState:    0x807BC6A0
     * finalizeState:   0x807BC690
     */
    sState_Extern(0x80996278, daBgmInterlockingDummyBlock_c, WaitReady);
};
