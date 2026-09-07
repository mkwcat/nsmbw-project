#pragma once

#include "d_a_player_manager.h"
#include "d_enemy.h"
#include "m_vec.h"

class daEnRedRing_c : public dEn_c {
    // Original size: 0x800
    VTABLE(0x060, fBase_c, 0x80B05048);
    // 0x80B04FE0 g_profile_EN_REDRING
    // 0x80A926A0 daEnRedRing_c_classInit

public:
    // Virtual Methods
    // ^^^^^^

    /**
     * VT+0x08 0x80A92820
     * do method for the create operation.
     */
    PACK_RESULT_e create() override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80A92E80 */
    void UNDEF_80A92E80();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x688);

#if PLAYER_COUNT == 8
#  define OFFSET_daEnRedRing_c_mPlayerDelta 0x688
    /* 0x688 */ mVec2_c mPlayerDelta[8];
#else
    FILL(0x688, 0x6C8);
#endif

    FILL(0x6C8, 0x800);
    OFFSET_ASSERT(0x800);

#if PLAYER_COUNT == 8
#  define OFFSET_daEnRedRing_c_mPrevPlayerDelta 0x800
    /* 0x800 */ mVec2_c mPrevPlayerDelta[8];
#else
#  define OFFSET_daEnRedRing_c_mPlayerDelta 0x800
    /* 0x800 */ mVec2_c mPlayerDelta[PLAYER_COUNT];
#  define OFFSET_daEnRedRing_c_mPrevPlayerDelta \
      (OFFSET_daEnRedRing_c_mPlayerDelta + 0x8 * PLAYER_COUNT)
    /* 0x800 */ mVec2_c mPrevPlayerDelta[PLAYER_COUNT];
#endif

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A93040
     * executeState:    0x80A93140
     * finalizeState:   0x80A930E0
     */
    sState_Extern(0x80B1A730, daEnRedRing_c, Wait);

    /*
     * initializeState: 0x80A932B0
     * executeState:    0x80A93300
     * finalizeState:   0x80A932F0
     */
    sState_Extern(0x80B1A770, daEnRedRing_c, Vanish);

    /*
     * initializeState: 0x80A93400
     * executeState:    0x80A93430
     * finalizeState:   0x80A93420
     */
    sState_Extern(0x80B1A7B0, daEnRedRing_c, Kill);
};
