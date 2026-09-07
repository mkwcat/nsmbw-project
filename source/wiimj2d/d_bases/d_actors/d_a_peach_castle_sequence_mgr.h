#pragma once

#include "d_base.h"
#include "s_State.h"

class daPeachCastleSequenceMgr_c : public dBase_c {
    SIZE_ASSERT(0x398);
    // 0x809775A0 g_profile_PEACH_CASTLE_SEQUENCE_MGR
    // 0x8088DC50 daPeachCastleSequenceMgr_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daPeachCastleSequenceMgr_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x398);
};

class daPeachCastleSequenceMgrObj_c : public dBase_c {
    SIZE_ASSERT(0xB8);
    VTABLE(0x60, fBase_c, 0x80977690);
    // 0x809775B0 g_profile_PEACH_CASTLE_SEQUENCE_MGR_OBJ
    // 0x8088DC80 daPeachCastleSequenceMgrObj_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8088DDA0 */
    daPeachCastleSequenceMgrObj_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x70, 0xB8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8088E0E0
     * executeState:    0x8088E110
     * finalizeState:   0x8088E1A0
     */
    sState_Extern(0x8099E0C8, daPeachCastleSequenceMgrObj_c, Wait);
};
