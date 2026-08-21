#pragma once

#include "component/c_array.h"
#include "d_static/d_cyuukan.h"
#include "d_static/d_mj2d/d_mj2d_game.h"

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

    FILL(0x35, 0x44);

    // Offsets here assume PLAYER_COUNT is 4.

    /* 0x44 */ u32                                                            mScore;
    /* 0x48 */ cArray_c<int, CHARACTER_COUNT, PLAYER_TYPE_e>                  mPlayerIndex;
    /* 0x58 */ cArray_c<PLAYER_MODE_e, CHARACTER_COUNT, PLAYER_TYPE_e>        mPlayerMode;
    /* 0x68 */ cArray_c<bool, CHARACTER_COUNT, PLAYER_TYPE_e>                 mIsEntry;
    /* 0x6C */ cArray_c<int, CHARACTER_COUNT, PLAYER_TYPE_e>                  mCoin;
    /* 0x7C */ cArray_c<int, CHARACTER_COUNT, PLAYER_TYPE_e>                  mRest;
    /* 0x8C */ cArray_c<PLAYER_CREATE_ITEM_e, CHARACTER_COUNT, PLAYER_TYPE_e> mCreateItem;
};
