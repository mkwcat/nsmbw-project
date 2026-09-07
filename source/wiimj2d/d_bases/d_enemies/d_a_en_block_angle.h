#pragma once

#include "d_a_en_blockmain.h"
#include "s_State.h"

class daEnBlockAngle_c : public daEnBlockMain_c {
    SIZE_ASSERT(0x730);
    VTABLE(0x060, fBase_c, 0x80ADB458);

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBlockAngle_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x698, 0x730);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809C1A70
     * executeState:    0x809C1A90
     * finalizeState:   0x809C1A80
     */
    sState_Extern(0x80B125F8, daEnBlockAngle_c, SearchID);

    /*
     * initializeState: 0x809C1B00
     * executeState:    0x809C1B20
     * finalizeState:   0x809C1B10
     */
    sState_Extern(0x80B12638, daEnBlockAngle_c, Wait);

    /*
     * initializeState: 0x809C1BB0
     * executeState:    0x809C1BD0
     * finalizeState:   0x809C1BC0
     */
    sState_Extern(0x80B12678, daEnBlockAngle_c, NonMoveWait);

    /*
     * initializeState: 0x809C1C10
     * executeState:    0x809C1C30
     * finalizeState:   0x809C1C20
     */
    sState_Extern(0x80B126B8, daEnBlockAngle_c, HitWait);
};

class daEnBlockRengaAngle_c : public daEnBlockAngle_c {
    SIZE_ASSERT(0x730);
    // 0x80ADB44C g_profile_EN_BLOCK_RENGA_ANGLE
    // 0x809C07F0 daEnBlockRengaAngle_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBlockRengaAngle_c() {}
};

class daEnBlockHatenaAngle_c : public daEnBlockAngle_c {
    SIZE_ASSERT(0x730);
    // 0x80ADB440 g_profile_EN_BLOCK_HATENA_ANGLE
    // 0x809C0770 daEnBlockHatenaAngle_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBlockHatenaAngle_c() {}
};
