#pragma once

#include "machine/m_vec.h"

class dScoreMng_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x800E2500 */
    void MiniGameScoreSet(mVec3_c& vec, u32, int);

    /* 0x800E25A0 */
    void UNDEF_800E25A0(u32 scoreType, int playerId, u32 param3);

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A330 */ static dScoreMng_c* m_instance;
};
