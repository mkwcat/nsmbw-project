#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnSnakeBlock_c : public dEn_c {
    SIZE_ASSERT(0x2B40);
    VTABLE(0x0060, fBase_c, 0x80B09138);
    // 0x80B090E0 g_profile_EN_SNAKEBLOCK
    // 0x80AA67E0 daEnSnakeBlock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnSnakeBlock_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0524, 0x2B40);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80AA83B0
     * executeState:    0x80AA83D0
     * finalizeState:   0x80AA83C0
     */
    sState_Extern(0x80B1B3B8, daEnSnakeBlock_c, Wait);

    /*
     * initializeState: 0x80AA83E0
     * executeState:    0x80AA8540
     * finalizeState:   0x80AA8530
     */
    sState_Extern(0x80B1B3F8, daEnSnakeBlock_c, Move);

    /*
     * initializeState: 0x80AA8720
     * executeState:    0x80AA87F0
     * finalizeState:   0x80AA87E0
     */
    sState_Extern(0x80B1B438, daEnSnakeBlock_c, Shake);

    /*
     * initializeState: 0x80AA88F0
     * executeState:    0x80AA8A90
     * finalizeState:   0x80AA8A80
     */
    sState_Extern(0x80B1B478, daEnSnakeBlock_c, Collapse1);

    /*
     * initializeState: 0x80AA8B30
     * executeState:    0x80AA8BA0
     * finalizeState:   0x80AA8B90
     */
    sState_Extern(0x80B1B4B8, daEnSnakeBlock_c, Collapse2);

    /*
     * initializeState: 0x80AA8D50
     * executeState:    0x80AA8DC0
     * finalizeState:   0x80AA8DB0
     */
    sState_Extern(0x80B1B4F8, daEnSnakeBlock_c, Collapse3);

    /*
     * initializeState: 0x80AA8820
     * executeState:    0x80AA88E0
     * finalizeState:   0x80AA88D0
     */
    sState_Extern(0x80B1B538, daEnSnakeBlock_c, Stop);
};
