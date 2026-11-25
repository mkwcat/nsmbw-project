#pragma once

#include "d_a_fireball_base.h"
#include "s_State.h"

class daFireBall_Player_c : public daFireBall_Base_c {
    SIZE_ASSERT(0x560);
    VTABLE(0x060, fBase_c, 0x80324080);
    // 0x80324060 g_profile_PL_FIREBALL
    // 0x8011A5B0 daFireBall_Player_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daFireBall_Player_c();

public:
    // Constants
    // ^^^^^^

    enum class CreateKind_e {
        Slow = 0,
        Fast = 1,
    };

public:
    // Nested Types
    // ^^^^^^

    struct Param_s {
        /*  0 */ u32 unk0       : 26 = 0;
        /* 26 */ u32 createKind : 2  = 0;
        /* 28 -- */ // u32 unk28 : 2 = 0;
        /* 30 -- */ // u32 plrNo : 2 = 0;
        /* 28 ++ */ u32 plrNo   : 4  = 0;
    };

public:
    // Virtual Methods
    // ^^^^^^

    /* 0x8011AC90 */ PACK_RESULT_e doDelete() override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8011A6B0 */ bool createCheck();

public:
    // Static Methods
    // ^^^^^^

    /* 0x8011B060 */ [[nodiscard]] static bool isFireBallEnable(int plrNo, CreateKind_e createKind);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x554 */ int m_PlayerNo;
    /* 0x558 */ int m_Counter;

    /* 0x55C */ u8  FILL(0x55C, 0x560);

public:
    // Static Variables
    // ^^^^^^

    /* 0x80375840 */ static int sm_FireBallCnt[PLAYER_COUNT];
    /* 0x80375850 */ static int sm_AliveFireBallCnt[PLAYER_COUNT];

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0xE0 0x8011ACF0
     * executeState:    VT+0xE4 0x8011AD10
     * finalizeState:   VT+0xE8 0x8011AD00
     */
    sState_ExternVirtual(0x8037586C, daFireBall_Player_c, Move);
};
