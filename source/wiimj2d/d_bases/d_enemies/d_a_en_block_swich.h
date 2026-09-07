#pragma once

#include "d_a_en_blockmain.h"

class daEnBlockSwich_c : public daEnBlockMain_c {
    SIZE_ASSERT(0x700);
    VTABLE(0x060, fBase_c, 0x80ADCA3C);
    // 0x80ADCA08 g_profile_EN_BLSWICH
    // 0x809C5FA0 daEnBlockSwich_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBlockSwich_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x698, 0x700);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809C6890
     * executeState:    0x809C68B0
     * finalizeState:   0x809C68A0
     */
    sState_Extern(0x80B128C8, daEnBlockSwich_c, Wait);

    /*
     * initializeState: 0x809C68C0
     * executeState:    0x809C68E0
     * finalizeState:   0x809C68D0
     */
    sState_Extern(0x80B12908, daEnBlockSwich_c, EndWait);
};

class daEnBlockPswich_c : public daEnBlockSwich_c {
    SIZE_ASSERT(0x700);
    // 0x80ADCA14 g_profile_EN_BLPSWICH
    // 0x809C6020 daEnBlockPswich_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBlockPswich_c();
};

class daEnBlockQswich_c : public daEnBlockSwich_c {
    SIZE_ASSERT(0x700);
    // 0x80ADCA20 g_profile_EN_BLQSWICH
    // 0x809C60A0 daEnBlockQswich_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBlockQswich_c();
};
