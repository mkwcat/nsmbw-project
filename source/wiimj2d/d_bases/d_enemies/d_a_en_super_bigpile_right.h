#pragma once

#include "d_a_en_super_bigpile.h"
#include "s_State.h"

class daEnSuperBigPileRight_c : public daEnSuperBigPile_c {
    SIZE_ASSERT(0x6A8);
    VTABLE(0x060, fBase_c, 0x80B09E4C);
    // 0x80B09E40 g_profile_EN_SUPER_BIGPILE_RIGHT
    // 0x80AAC250 daEnSuperBigPileRight_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnSuperBigPileRight_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x6A0, 0x6A8);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x28C 0x80AAC7F0
     * executeState:    VT+0x290 0x80AAC840
     * finalizeState:   VT+0x294 0x80AAC830
     */
    sState_ExternVirtual(0x80B1B724, daEnSuperBigPileRight_c, GoMove);

    /*
     * initializeState: VT+0x2A4 0x80AAC980
     * executeState:    VT+0x2A8 0x80AAC9A0
     * finalizeState:   VT+0x2AC 0x80AAC990
     */
    sState_ExternVirtual(0x80B1B764, daEnSuperBigPileRight_c, RetMove);
};
