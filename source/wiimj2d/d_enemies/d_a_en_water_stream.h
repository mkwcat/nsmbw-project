#pragma once

#include "d_static/d_a_player/d_a_player_manager.h"
#include "d_static/d_enemy/d_enemy.h"
#include "machine/m_ef.h"

class daEnWaterStream_c : public dEn_c
{
    // ORIGINAL SIZE: 0x678

public:
    // Structors
    // ^^^^^^

    daEnWaterStream_c() = delete;

public:
    // Instance Variables
    // ^^^^^^

    /* 0x524 */ u32 m0x524;
    /* 0x528 */ u32 m0x528;
    /* 0x52C */ u32 m0x52C;
    /* 0x530 */ void* mp0x530;
    /* 0x534 */ u32 m0x534;
    /* 0x538 */ u32 m0x538;
    /* 0x53C */ mEf::levelEffect_c mEffect;
    /* 0x664 */ // int mPlayerTimers[4];
    /* 0x674 */ // u32 mUnused0x674;

    OFFSET_ASSERT(0x664);
    /* 0x664 */ int mPlayerTimers[PLAYER_COUNT];
};
