#pragma once

#include "d_a_en_blockmain.h"
#include "s_State.h"

class daEnBlockHatenaPlayer_c : public daEnBlockMain_c {
    SIZE_ASSERT(0x708);
    VTABLE(0x060, fBase_c, 0x80ADBCF4);
    // 0x80ADBCDC g_profile_EN_BLOCK_HATENA_PLAYER
    // 0x809C2DD0 daEnBlockHatenaPlayer_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBlockHatenaPlayer_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x698, 0x708);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809C3AF0
     * executeState:    0x809C3B10
     * finalizeState:   0x809C3B00
     */
    sState_Extern(0x80B12788, daEnBlockHatenaPlayer_c, Wait);

    /*
     * initializeState: 0x809C3B60
     * executeState:    0x809C3B80
     * finalizeState:   0x809C3B70
     */
    sState_Extern(0x80B127C8, daEnBlockHatenaPlayer_c, HitWait);
};

class daEnBlockRengaPlayer_c : public daEnBlockHatenaPlayer_c {
    // 0x80ADBCE8 g_profile_EN_BLOCK_RENGA_PLAYER
    // 0x809C2E50 daEnBlockRengaPlayer_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBlockRengaPlayer_c() {}
};
