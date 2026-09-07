#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnWakiJugem_c : public dEn_c {
    SIZE_ASSERT(0x530);
    VTABLE(0x060, fBase_c, 0x80B0D758);
    // 0x80B0D748 g_profile_EN_WAKI_JUGEM
    // 0x80ABC840 daEnWakiJugem_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnWakiJugem_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x530);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80ABCC10
     * executeState:    0x80ABCC40
     * finalizeState:   0x80ABCC30
     */
    sState_Extern(0x80B1C018, daEnWakiJugem_c, WakiMove);
};
