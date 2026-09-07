#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daMiniGameKinopio_c : public dEn_c {
    SIZE_ASSERT(0x648);
    VTABLE(0x060, fBase_c, 0x8096FFD8);
    // 0x8096FF4C g_profile_MINI_GAME_KINOPIO
    // 0x808672B0 daMiniGameKinopio_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daMiniGameKinopio_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x648);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808678F0
     * executeState:    0x80867990
     * finalizeState:   0x80867A40
     */
    sState_Extern(0x8099CC88, daMiniGameKinopio_c, Ready);

    /*
     * initializeState: 0x80867A50
     * executeState:    0x80867B80
     * finalizeState:   0x80867B70
     */
    sState_Extern(0x8099CCC8, daMiniGameKinopio_c, Wait);
};
