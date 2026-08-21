#pragma once

#include "machine/m_vec.h"

class dEnemyMng_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x800A7D30 @unofficial */
    void execute();

    /* 0x800A7560 */
    void spawnYoshiEgg(mVec3_c* pos, int param_2, u32 param_3, s8 param_4, int param_5);

    /* 0x800A7860 */
    void setNoGetItemTimer(int playerNo);

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A1F0 */ static dEnemyMng_c* m_instance;

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x000, 0x138);

    /* 0x138 */ u32 m0x138;

    FILL(0x13C, 0x15C);

    /* 0x15C */ s32 m0x15C;

    FILL(0x160, 0x174);

    /* 0x174 */ s32 mPokeyTimer;
};
