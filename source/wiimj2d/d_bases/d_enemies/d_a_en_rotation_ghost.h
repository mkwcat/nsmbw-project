#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnRotarionGhost_c : public dEn_c {
    SIZE_ASSERT(0x7F8);
    VTABLE(0x060, fBase_c, 0x80B06D10);
    // 0x80B06BF8 g_profile_EN_ROTATION_GHOST
    // 0x80A99160 daEnRotarionGhost_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnRotarionGhost_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x7F8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A99FB0
     * executeState:    0x80A99FD0
     * finalizeState:   0x80A99FC0
     */
    sState_Extern(0x80B1AB10, daEnRotarionGhost_c, RotetionMove);
};
