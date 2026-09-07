#pragma once

#include "d_a_en_blockmain.h"

class daEnObjBlock_c : public daEnBlockMain_c {
    SIZE_ASSERT(0x860);
    VTABLE(0x060, fBase_c, 0x80AFE790);

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnObjBlock_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x698, 0x860);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A77460
     * executeState:    0x80A77480
     * finalizeState:   0x80A77470
     */
    sState_Extern(0x80B194D0, daEnObjBlock_c, SerchRailID);

    /*
     * initializeState: 0x80A774D0
     * executeState:    0x80A774F0
     * finalizeState:   0x80A774E0
     */
    sState_Extern(0x80B19510, daEnObjBlock_c, SerchObjPolID);

    /*
     * initializeState: 0x80A77540
     * executeState:    0x80A77560
     * finalizeState:   0x80A77550
     */
    sState_Extern(0x80B19550, daEnObjBlock_c, Wait);

    /*
     * initializeState: 0x80A775B0
     * executeState:    0x80A775D0
     * finalizeState:   0x80A775C0
     */
    sState_Extern(0x80B19590, daEnObjBlock_c, HitWait);
};

class daEnObjHatenaBlock_c : public daEnObjBlock_c {
    SIZE_ASSERT(0x860);
    // 0x80AFE748 g_profile_EN_OBJ_HATENA_BLOCK
    // 0x80A75B40 daEnObjHatenaBlock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnObjHatenaBlock_c();
};

class daEnObjHatenaBBlock_c : public daEnObjBlock_c {
    SIZE_ASSERT(0x860);
    // 0x80AFE754 g_profile_EN_OBJ_HATENAB_BLOCK
    // 0x80A75BD0 daEnObjHatenaBBlock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnObjHatenaBBlock_c();
};

class daEnObjRengaBlock_c : public daEnObjBlock_c {
    SIZE_ASSERT(0x860);
    // 0x80AFE760 g_profile_EN_OBJ_RENGA_BLOCK
    // 0x80A75C60 daEnObjRengaBlock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnObjRengaBlock_c();
};

class daEnObjClearBlock_c : public daEnObjBlock_c {
    SIZE_ASSERT(0x860);
    // 0x80AFE76C g_profile_EN_OBJ_CLEAR_BLOCK
    // 0x80A75CF0 daEnObjClearBlock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnObjClearBlock_c();
};

class daEnObjHatenaBlockLine_c : public daEnObjBlock_c {
    SIZE_ASSERT(0x860);
    // 0x80AFE778 g_profile_EN_HATENA_BLOCK_LINE
    // 0x80A75D80 daEnObjHatenaBlockLine_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnObjHatenaBlockLine_c();
};

class daEnObjRengaBlockLine_c : public daEnObjBlock_c {
    SIZE_ASSERT(0x860);
    // 0x80AFE784 g_profile_EN_RENGA_BLOCK_LINE
    // 0x80A75E10 daEnObjRengaBlockLine_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnObjRengaBlockLine_c();
};
