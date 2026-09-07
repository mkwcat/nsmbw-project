#pragma once

#include "d_enemy.h"
#include "d_mj2d_game.h"

class daEnRedcoin_c : public dEn_c {
    // Original size: 0x6A8
    VTABLE(0x060, fBase_c, 0x80B05448);
    // 0x80B053D8 g_profile_EN_REDCOIN
    // 0x80A93990 daEnRedcoin_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnRedcoin_c();

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

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A94480
     * executeState:    0x80A944A0
     * finalizeState:   0x80A94490
     */
    sState_Extern(0x80B1A7F0, daEnRedcoin_c, Wait);

    /*
     * initializeState: 0x80A94530
     * executeState:    0x80A94550
     * finalizeState:   0x80A94540
     */
    sState_Extern(0x80B1A830, daEnRedcoin_c, Move);

    /*
     * initializeState: 0x80A945E0
     * executeState:    0x80A94650
     * finalizeState:   0x80A94640
     */
    sState_Extern(0x80B1A870, daEnRedcoin_c, GetDemo);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x1E4 0x80A947F0
     * executeState:    VT+0x1E8 0x80A94810
     * finalizeState:   VT+0x1EC 0x80A94800
     */
    sState_ExternVirtual(0x80B1A8B0, daEnRedcoin_c, EatOut);
};
