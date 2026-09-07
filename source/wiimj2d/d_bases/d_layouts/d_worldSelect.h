#pragma once

#include "c_array.h"
#include "d_base.h"
#include "d_mj2d_game.h"
#include "m_angle.h"
#include "s_State.h"
#include "s_StateMgrDefault.h"
#include <nw4r/lyt/Pane.h>

class daWmIsland_c;
class dWorldSelectGuide_c;

class dWorldSelect_c : public dBase_c {
    SIZE_ASSERT(0x2BC);
    VTABLE(0x060, fBase_c, 0x8098E3B8);
    // 0x8098E278 g_profile_WORLD_SELECT
    // 0x80928810 dWorldSelect_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80928840 */
    dWorldSelect_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80928EC0 */
    int wrapIsland(int island);

    /* 0x80928EF0 */
    float getIslandMoveAngle();

    /* 0x80928F50 */
    bool checkIslandMove(int island, bool isMoveRight);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x20C);

    /* 0x20C */ sStateMgrDefault_c<dWorldSelect_c> m_stateMgr;

    /* 0x248 */ daWmIsland_c*                      mpaIsland[9];
    /* 0x26C */ dWorldSelectGuide_c*               mpWSelectGuide;

    /* 0x270 */ nw4r::lyt::Pane*                   mpP0x270;
    /* 0x274 */ nw4r::lyt::Pane*                   mpP0x274;

    FILL(0x278, 0x27C);

    /* 0x27C */ int m_currentIsland; // Unsure
    /* 0x280 */ int m_toIsland;
    /* 0x284 */ int m_moveNum;

    FILL(0x288, 0x294);

    /* 0x294 */ int m0x294;
    /* 0x298 */ int m_islandBeforeSpecialWorld;

    FILL(0x29C, 0x2A4);

    /* 0x2A4 */ mAng                                 m_moveAngle;
    /* 0x2A6 */ mAng                                 m_moveAngle2;

    /* 0x2A8 */ cArray_c<bool, ORIGINAL_WORLD_COUNT> m_isWorldOpen;

    FILL(0x2B2, 0x2B4);

    /* 0x2B4 */ bool m_isMoveRight;
    /* 0x2B5 */ bool m0x2B5;
    /* 0x2B6 */ bool m_isMove;
    /* 0x2B7 */ bool m0x2B7;

    FILL(0x2B8, 0x2BC);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80929400
     * executeState:    0x809294A0
     * finalizeState:   0x809296F0
     */
    sState_Extern(0x809A1FF8, dWorldSelect_c, OnStageWait);

    /*
     * initializeState: 0x80929710
     * executeState:    0x809297E0
     * finalizeState:   0x80929870
     */
    sState_Extern(0x809A2038, dWorldSelect_c, OpenAnimeEndWait);

    /*
     * initializeState: 0x80929880
     * executeState:    0x809298A0
     * finalizeState:   0x80929940
     */
    sState_Extern(0x809A2078, dWorldSelect_c, SelectExpand);

    /*
     * initializeState: 0x80929960
     * executeState:    0x80929990
     * finalizeState:   0x80929C40
     */
    sState_Extern(0x809A20B8, dWorldSelect_c, Select);

    /*
     * initializeState: 0x80929C50
     * executeState:    0x80929CE0
     * finalizeState:   0x80929DC0
     */
    sState_Extern(0x809A20F8, dWorldSelect_c, IsLandSizeDown);

    /*
     * initializeState: 0x80929E40
     * executeState:    0x80929E60
     * finalizeState:   0x8092A050
     */
    sState_Extern(0x809A2138, dWorldSelect_c, IslandMove);

    /*
     * initializeState: 0x8092A070
     * executeState:    0x8092A080
     * finalizeState:   0x8092A100
     */
    sState_Extern(0x809A2178, dWorldSelect_c, IslandAgainMoveWait);

    /*
     * initializeState: 0x8092A110
     * executeState:    0x8092A170
     * finalizeState:   0x8092A200
     */
    sState_Extern(0x809A21B8, dWorldSelect_c, ExitAnimeEndWait);

    /*
     * initializeState: 0x8092A280
     * executeState:    0x8092A360
     * finalizeState:   0x8092A3E0
     */
    sState_Extern(0x809A21F8, dWorldSelect_c, DecisionAnimeEndWait);

    /*
     * initializeState: 0x8092A3F0
     * executeState:    0x8092A400
     * finalizeState:   0x8092A410
     */
    sState_Extern(0x809A2238, dWorldSelect_c, SceneChangeWait);

    /*
     * initializeState: 0x8092A420
     * executeState:    0x8092A430
     * finalizeState:   0x8092A470
     */
    sState_Extern(0x809A2278, dWorldSelect_c, World9OnStageStartWait);

    /*
     * initializeState: 0x8092A480
     * executeState:    0x8092A4F0
     * finalizeState:   0x8092A550
     */
    sState_Extern(0x809A22B8, dWorldSelect_c, World9OnStageAnimeEndWait);

    /*
     * initializeState: 0x8092A560
     * executeState:    0x8092A570
     * finalizeState:   0x8092A5B0
     */
    sState_Extern(0x809A22F8, dWorldSelect_c, World9DeMoEndWait);
};
