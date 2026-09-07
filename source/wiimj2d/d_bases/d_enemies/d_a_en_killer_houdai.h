#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnKild_c : public dEn_c {
    SIZE_ASSERT(0xE48);
    VTABLE(0x060, fBase_c, 0x80AF6DB8);
    // 0x80AF6CDC g_profile_EN_KILLER_HOUDAI
    // 0x80A4E060 daEnKild_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnKild_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0xE48);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A503D0
     * executeState:    0x80A50410
     * finalizeState:   0x80A50400
     */
    sState_Extern(0x80B17DB0, daEnKild_c, Wait);

    /*
     * initializeState: 0x80A50460
     * executeState:    0x80A504E0
     * finalizeState:   0x80A504D0
     */
    sState_Extern(0x80B17DF0, daEnKild_c, Slide);

    /*
     * initializeState: 0x80A50650
     * executeState:    0x80A508F0
     * finalizeState:   0x80A508E0
     */
    sState_Extern(0x80B17E30, daEnKild_c, Fall);
};

class daEnMagnumKild_c : public daEnKild_c {
    SIZE_ASSERT(0xE48);
    VTABLE(0x060, fBase_c, 0x80AF6DB8);
    // 0x80AF6CD0 g_profile_EN_MAGNUM_KILLER_HOUDAI
    // 0x80A4DEB0 daEnMagnumKild_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnMagnumKild_c();
};

class daEnKildSlide_c : public daEnKild_c {
    SIZE_ASSERT(0xE48);
    // 0x80AF6CE8 g_profile_EN_KILLER_HOUDAI_SLIDE
    // 0x80A4E210 daEnKildSlide_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnKildSlide_c();
};
