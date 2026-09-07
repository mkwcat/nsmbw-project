#pragma once

#include "d_enemy.h"
#include "d_mj2d_game.h"
#include "m_ef.h"

class daEnWaterStream_c : public dEn_c {
    // Original size: 0x678
    VTABLE(0x060, fBase_c, 0x80B0FBE0);
    // 0x80B0FBC0 g_profile_EN_WATERSTREAM
    // 0x80AC7800 daEnWaterStream_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnWaterStream_c();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x524 */ u32                m0x524;
    /* 0x528 */ u32                m0x528;
    /* 0x52C */ u32                m0x52C;
    /* 0x530 */ void*              mp0x530;
    /* 0x534 */ u32                m0x534;
    /* 0x538 */ u32                m0x538;
    /* 0x53C */ mEf::levelEffect_c mEffect;
    /* 0x664 */ // int mPlayerTimers[4];
    /* 0x674 */ // u32 mUnused0x674;

    OFFSET_ASSERT(0x664);
    /* 0x664 */ int mPlayerTimers[PLAYER_COUNT];
};
