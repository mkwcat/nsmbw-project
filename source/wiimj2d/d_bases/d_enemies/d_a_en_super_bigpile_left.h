#pragma once

#include "d_a_en_super_bigpile.h"
#include "s_State.h"

class daEnSuperBigPileLeft_c : public daEnSuperBigPile_c {
    SIZE_ASSERT(0x6A8);
    VTABLE(0x060, fBase_c, 0x80B09A54);
    // 0x80B09A48 g_profile_EN_SUPER_BIGPILE_LEFT
    // 0x80AAB3D0 daEnSuperBigPileLeft_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnSuperBigPileLeft_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x6A0, 0x6A8);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x28C 0x80AAB970
     * executeState:    VT+0x290 0x80AAB9C0
     * finalizeState:   VT+0x294 0x80AAB9B0
     */
    sState_ExternVirtual(0x80B1B6A4, daEnSuperBigPileLeft_c, GoMove);

    /*
     * initializeState: VT+0x2A4 0x80AABB00
     * executeState:    VT+0x2A8 0x80AABB20
     * finalizeState:   VT+0x2AC 0x80AABB10
     */
    sState_ExternVirtual(0x80B1B6E4, daEnSuperBigPileLeft_c, RetMove);
};
