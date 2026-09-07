#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnKingKiller_c : public dEn_c {
    SIZE_ASSERT(0x1818);
    VTABLE(0x0060, fBase_c, 0x80AF71B8);
    // 0x80AF7148 g_profile_EN_KING_KILLER
    // 0x80A51060 daEnKingKiller_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnKingKiller_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0524, 0x1818);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A52170
     * executeState:    0x80A521A0
     * finalizeState:   0x80A52190
     */
    sState_Extern(0x80B17E70, daEnKingKiller_c, Wait);

    /*
     * initializeState: 0x80A52240
     * executeState:    0x80A52390
     * finalizeState:   0x80A52380
     */
    sState_Extern(0x80B17EB0, daEnKingKiller_c, Move);
};
