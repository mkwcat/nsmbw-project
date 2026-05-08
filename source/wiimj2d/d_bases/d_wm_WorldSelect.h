#pragma once

#include "component/c_array.h"
#include "d_system/d_base.h"
#include "d_system/d_mj2d_game.h"
#include "machine/m_angle.h"
#include "state/s_State.h"
#include "state/s_StateMgrDefault.h"
#include <nw4r/lyt/Pane.h>

class daWmIsland_c;
class dWorldSelectGuide_c;

class dWorldSelect_c : public dBase_c {
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

public:
    // State IDs
    // ^^^^^^

    sState_Extern(0x809A1FF8, dWorldSelect_c, OnStageWait);
    sState_Extern(0x809A2030, dWorldSelect_c, OpenAnimeEndWait);
    sState_Extern(0x809A2078, dWorldSelect_c, SelectExpand);
    sState_Extern(0x809A20B8, dWorldSelect_c, Select);
    sState_Extern(0x809A20F8, dWorldSelect_c, IsLandSizeDown);
    sState_Extern(0x809A2138, dWorldSelect_c, IslandMove);
    sState_Extern(0x809A2178, dWorldSelect_c, IslandAgainMoveWait);
    sState_Extern(0x809A21B8, dWorldSelect_c, ExitAnimeEndWait);
    sState_Extern(0x809A21F8, dWorldSelect_c, DecisionAnimeEndWait);
    sState_Extern(0x809A2238, dWorldSelect_c, SceneChangeWait);
    sState_Extern(0x809A2278, dWorldSelect_c, World9OnStageStartWait);
    sState_Extern(0x809A22B8, dWorldSelect_c, World9OnStageAnimeEndWait);
    sState_Extern(0x809A22F8, dWorldSelect_c, World9DeMoEndWait);
};
