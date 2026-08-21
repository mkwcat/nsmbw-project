#pragma once

#include <egg/prim/eggBitFlag.h>

class dQuake_c
{
public:
    // Constants and Types
    // ^^^^^^

    enum class TYPE_QUAKE_e {
    };

    enum class TYPE_SHOCK_e {
        HIP_ATTACK = 3,
        PLAYER_DAMAGE = 4,
        HIP_ATTACK2 = 7,
        PLAYER_BUBBLE_SHAKE = 10,
    };

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800D8BF0 */
    void startShock(s8 player, TYPE_SHOCK_e type, int flag, int comboCount, bool grabActive);

    /* 0x800D8CA0 */
    void shockMotor(s8 player, TYPE_SHOCK_e type, int flag, bool grabActive);

    /* 0x800D8E20 */
    void UNDEF_800d8e20(s8 player, int type, int flag, bool grabActive);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x00, 0x30);

    /* 0x30 */ EGG::TBitFlag<u32> mFlags;

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A2E8 */ static dQuake_c* m_instance;
};
