#pragma once

#include "d_system/d_mj2d_game.h"

/**
 * @brief Multiplayer manager.
 * Keeps track of statistics for each player, used for Coin Battle and Free Mode.
 */
class dMultiMng_c
{
public:
    // Structors
    // ^^^^^^

    /**
     * 0x800CE8F0
     * Creates a multiplayer manager and sets mspInstance to it.
     */
    dMultiMng_c();

    /* VT+0x8 0x800CE910 */
    virtual ~dMultiMng_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800CE950 */
    void initStage();

    /* 0x800CEAC0 */
    void incCoin(int player);

public:
    // Instance Variables
    // ^^^^^^

    /**
     * The time left in in-game seconds when the goal is reached.
     */
    /* 0x04 */ int mGoalTime;

    /**
     * The number of remaining lives for each player.
     */
    /* 0x08 */ int mRest[ORIGINAL_PLAYER_COUNT];

    /**
     * The score of each player.
     */
    /* 0x18 */ int mScore[ORIGINAL_PLAYER_COUNT];

    /**
     * The count count for each player.
     */
    /* 0x28 */ int mCoin[ORIGINAL_PLAYER_COUNT];

    /**
     * The enemy kill count for each player.
     */
    /* 0x38 */ int mEnemyDown[ORIGINAL_PLAYER_COUNT];

    /**
     * The battle coin count for each player.
     */
    /* 0x48 */ int mBattleCoin[ORIGINAL_PLAYER_COUNT];

    /**
     * @brief The star coin collection status for each player.
     * Each byte is a bitfield representing whether each star coin has been collected
     * by the corresponding player.
     * 0x1 is the first star coin, 0x2 is the second, and 0x4 is the third.
     */
    /* 0x58 */ u8 mCollectionCoin[ORIGINAL_PLAYER_COUNT];

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A290 */ static dMultiMng_c* mspInstance;
};
