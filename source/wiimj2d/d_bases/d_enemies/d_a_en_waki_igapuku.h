#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnWakiIgaPuku_c : public dEn_c {
    SIZE_ASSERT(0x540);
    VTABLE(0x060, fBase_c, 0x80B0D3C0);
    // 0x80B0D3B0 g_profile_EN_WAKI_IGAPUKU
    // 0x80ABBD10 daEnWakiIgaPuku_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnWakiIgaPuku_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x540);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80ABC150
     * executeState:    0x80ABC1B0
     * finalizeState:   0x80ABC1A0
     */
    sState_Extern(0x80B1BF58, daEnWakiIgaPuku_c, Wait);

    /*
     * initializeState: 0x80ABC230
     * executeState:    0x80ABC250
     * finalizeState:   0x80ABC240
     */
    sState_Extern(0x80B1BF98, daEnWakiIgaPuku_c, Waki);

    /*
     * initializeState: 0x80ABC320
     * executeState:    0x80ABC340
     * finalizeState:   0x80ABC330
     */
    sState_Extern(0x80B1BFD8, daEnWakiIgaPuku_c, Watch);
};
