#pragma once

#include "d_enemy.h"
#include "d_mj2d_game.h"
#include "s_State.h"

class daFloorJrC_c : public dEn_c {
    // Original size: 0x6A8
    VTABLE(0x060, fBase_c, 0x8095B190);
    // 0x8095B148 g_profile_FLOOR_JR_C
    // 0x807F1A00 daFloorJrC_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x807F20B0 */
    daFloorJrC_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x807F28E0 */
    void clearPlayerInfo();

    /* 0x807F2940 */
    bool checkPlayerFlag(int player);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x66C);

    /* 0x66C */ float m0x66C;
    /* 0x670 */ float m0x670;
    /* 0x674 */ float m0x674;

    FILL(0x678, 0x684);

    /* 0x684 */ u8 m0x684;
    /* 0x685 */ u8 m0x685;

#if PLAYER_COUNT > 7
    /* 0x686 */ bool REMOVED(m0x686)[4];
#else
    /* 0x686 */ bool m0x686[4];
#endif
    /* 0x68A */ bool REMOVED(m0x68A)[4];

    FILL(0x68E, 0x6A8);
    OFFSET_ASSERT(0x6A8);

#if PLAYER_COUNT > 7
    bool m0x686[PLAYER_COUNT];
#endif

    bool m0x68A[PLAYER_COUNT];

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807F2980
     * executeState:    0x807F29A0
     * finalizeState:   0x807F2990
     */
    sState_Extern(0x809987A8, daFloorJrC_c, DemoWait);

    /*
     * initializeState: 0x807F29B0
     * executeState:    0x807F29E0
     * finalizeState:   0x807F29D0
     */
    sState_Extern(0x809987E8, daFloorJrC_c, Wait);
};
