#pragma once

#include "d_a_en_blockmain.h"
#include "s_State.h"

class daPeachCastleBlock_c : public daEnBlockMain_c {
    SIZE_ASSERT(0x7A8);
    VTABLE(0x060, fBase_c, 0x809771A8);
    // 0x80977170 g_profile_PEACH_CASTLE_BLOCK
    // 0x8088CF00 daPeachCastleBlock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daPeachCastleBlock_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x698, 0x7A8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8088D600
     * executeState:    0x8088D620
     * finalizeState:   0x8088D610
     */
    sState_Extern(0x8099E088, daPeachCastleBlock_c, HitEnd);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x2EC 0x8088D5D0
     * executeState:    VT+0x2F0 0x8088D5F0
     * finalizeState:   VT+0x2F4 0x8088D5E0
     */
    sState_ExternVirtual(0x8099E044, daPeachCastleBlock_c, Wait);
};
