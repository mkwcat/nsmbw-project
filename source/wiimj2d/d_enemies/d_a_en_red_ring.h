#pragma once

#include "d_static/d_a_player/d_a_player_manager.h"
#include "d_static/d_enemy/d_enemy.h"
#include "machine/m_vec.h"

class daEnRedRing_c : public dEn_c
{
public:
    // Virtual Functions
    // ^^^^^^

    /**
     * VT+0x08 0x80A92820
     * do method for the create operation.
     */
    PACK_RESULT_e create() override;

    /* 0x80A93140 */
    void executeState_Wait();

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
#  define OFFSET_daEnRedRing_c_mPrevPlayerDelta                                                    \
      (OFFSET_daEnRedRing_c_mPlayerDelta + 0x8 * PLAYER_COUNT)
    /* 0x800 */ mVec2_c mPrevPlayerDelta[PLAYER_COUNT];
#endif
};
