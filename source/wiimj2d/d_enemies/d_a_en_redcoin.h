#pragma once

#include "d_static/d_a_player/d_a_player_manager.h"
#include "d_static/d_enemy/d_enemy.h"

class daEnRedcoin_c : public dEn_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x80A94250 */
    void selectItems();

    /* 0x80A94340 */
    void awardItems();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x66C);

    /* 0x66C */ int mItemType;

    FILL(0x670, 0x67C);

    /* 0x67C */ int REMOVED(mPlyItemSpawnMode)[4];
    /* 0x68C */ int REMOVED(mPlyItem)[4];

    FILL(0x69C, 0x6A8);
    OFFSET_ASSERT(0x6A8);

#define OFFSET_mPlyItemSpawnMode 0x6A8
    /* 0x6A8 */ int mPlyItemSpawnMode[PLAYER_COUNT];

#define OFFSET_mPlyItem (0x6A8 + PLAYER_COUNT * 4)
    int mPlyItem[PLAYER_COUNT];
};
