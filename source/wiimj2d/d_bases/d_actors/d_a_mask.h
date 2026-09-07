#pragma once

#include "d_actor.h"
#include "d_mj2d_game.h"

class daMask_c : public dActor_c {
    SIZE_ASSERT(0x510);
    VTABLE(0x060, fBase_c, 0x80324D84);
    // 0x80324D78 g_profile_MASK
    // 0x80124EB0 daMask_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daMask_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80126050 */ daPlBase_c* GetPlayerP();
    /* 0x801260B0 */ bool isYoshi();

public:
    // Instance Inline Methods
    // ^^^^^^

    int getPlrAcNo() { return mMaskPlrNo >= 0 && mMaskPlrNo < PLAYER_COUNT ? mMaskPlrNo : -1; }

    int getYoshiNo() {
        return mMaskPlrNo >= PLAYER_COUNT && mMaskPlrNo < PLAYER_COUNT * 2
                   ? mMaskPlrNo - PLAYER_COUNT
                   : -1;
    }

public:
    // Instance Variables
    // ^^^^^^

    /* 0x392 */ u8 mMaskPlrNo;

    FILL(0x393, 0x510);
};
