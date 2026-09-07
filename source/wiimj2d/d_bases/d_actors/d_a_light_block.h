#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daLightBlock_c : public dEn_c {
    SIZE_ASSERT(0x6F0);
    VTABLE(0x060, fBase_c, 0x8096B2A8);
    // 0x8096B250 g_profile_AC_LIGHT_BLOCK
    // 0x808552E0 daLightBlock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLightBlock_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x6F0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80856270
     * executeState:    0x808562C0
     * finalizeState:   0x808562B0
     */
    sState_Extern(0x8099C308, daLightBlock_c, Wait);

    /*
     * initializeState: 0x80856460
     * executeState:    0x80856500
     * finalizeState:   0x808564B0
     */
    sState_Extern(0x8099C348, daLightBlock_c, Carry);

    /*
     * initializeState: 0x80856650
     * executeState:    0x80856760
     * finalizeState:   0x80856720
     */
    sState_Extern(0x8099C388, daLightBlock_c, Throw);

    /*
     * initializeState: 0x808568D0
     * executeState:    0x80856960
     * finalizeState:   0x80856950
     */
    sState_Extern(0x8099C3C8, daLightBlock_c, Down);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x1E4 0x80856970
     * executeState:    VT+0x1E8 0x80856BF0
     * finalizeState:   VT+0x1EC 0x80856BE0
     */
    sState_ExternVirtual(0x8099C404, daLightBlock_c, EatOut);
};
