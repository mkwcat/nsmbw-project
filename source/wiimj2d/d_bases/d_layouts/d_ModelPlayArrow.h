#pragma once

#include "d_base.h"
#include "s_State.h"

class dModelPlayArrow_c : public dBase_c {
    SIZE_ASSERT(0x260);
    VTABLE(0x060, fBase_c, 0x80947CB0);
    // 0x80947B60 g_profile_MODEL_PLAY_ARROW
    // 0x807916F0 dModelPlayArrow_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80791720 */
    dModelPlayArrow_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x260);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80791D00
     * executeState:    0x80791D10
     * finalizeState:   0x80791D40
     */
    sState_Extern(0x80993608, dModelPlayArrow_c, StartWait);

    /*
     * initializeState: 0x80791D60
     * executeState:    0x80791D70
     * finalizeState:   0x80791E00
     */
    sState_Extern(0x80993648, dModelPlayArrow_c, ActionWait);

    /*
     * initializeState: 0x80791E10
     * executeState:    0x80791E90
     * finalizeState:   0x80791F00
     */
    sState_Extern(0x80993688, dModelPlayArrow_c, OnStageAnimeEndWait);

    /*
     * initializeState: 0x80791FB0
     * executeState:    0x80792030
     * finalizeState:   0x807920A0
     */
    sState_Extern(0x809936C8, dModelPlayArrow_c, HitAnimeEndWait);

    /*
     * initializeState: 0x80792150
     * executeState:    0x807921E0
     * finalizeState:   0x80792250
     */
    sState_Extern(0x80993708, dModelPlayArrow_c, LeftOrRightExitAnimeEndWait);

    /*
     * initializeState: 0x80792260
     * executeState:    0x80792300
     * finalizeState:   0x80792370
     */
    sState_Extern(0x80993748, dModelPlayArrow_c, ExitAnimeEndWait);
};
