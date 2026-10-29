#pragma once

#include "d_cyuukan.h"
#include "d_mj2d_game.h"
#include <slu/array.hpp>

class dStartInfo_c {
    /* Original size: 0x9C */

public:
    // Structors
    // ^^^^^^

    /* 0x800E3BA0 */
    dStartInfo_c();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x00 */ dCyuukan_c mCyuukan;

    /**
     * The status of the worldmap switch.
     */
    /* 0x34 */ bool mSwitchOn;

    u8              FILL(0x35, 0x44);

    // Offsets here assume PLAYER_COUNT is 4.

    /* 0x44 */ u32                                                              mScore;
    /* 0x48 */ slu::array<int, CHARACTER_COUNT, PLAYER_TYPE_e>                  mPlayerIndex;
    /* 0x58 */ slu::array<PLAYER_MODE_e, CHARACTER_COUNT, PLAYER_TYPE_e>        mPlayerMode;
    /* 0x68 */ slu::array<bool, CHARACTER_COUNT, PLAYER_TYPE_e>                 mIsEntry;
    /* 0x6C */ slu::array<int, CHARACTER_COUNT, PLAYER_TYPE_e>                  mCoin;
    /* 0x7C */ slu::array<int, CHARACTER_COUNT, PLAYER_TYPE_e>                  mRest;
    /* 0x8C */ slu::array<PLAYER_CREATE_ITEM_e, CHARACTER_COUNT, PLAYER_TYPE_e> mCreateItem;
};
