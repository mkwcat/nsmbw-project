#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnTogeTekkyu_c : public dEn_c {
    SIZE_ASSERT(0x698);
    VTABLE(0x060, fBase_c, 0x80B0BD88);
    // 0x80B0BD28 g_profile_EN_TOGETEKKYU
    // 0x80AB5C20 daEnTogeTekkyu_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnTogeTekkyu_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x698);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80AB68A0
     * executeState:    0x80AB68D0
     * finalizeState:   0x80AB68C0
     */
    sState_Extern(0x80B1BC98, daEnTogeTekkyu_c, Wait);

    /*
     * initializeState: 0x80AB6AB0
     * executeState:    0x80AB6B00
     * finalizeState:   0x80AB6AF0
     */
    sState_Extern(0x80B1BCD8, daEnTogeTekkyu_c, Move);

    /*
     * initializeState: 0x80AB6950
     * executeState:    0x80AB6980
     * finalizeState:   0x80AB6970
     */
    sState_Extern(0x80B1BD18, daEnTogeTekkyu_c, Waki);

    /*
     * initializeState: 0x80AB6A10
     * executeState:    0x80AB6A50
     * finalizeState:   0x80AB6A40
     */
    sState_Extern(0x80B1BD58, daEnTogeTekkyu_c, InIceLump);
};
