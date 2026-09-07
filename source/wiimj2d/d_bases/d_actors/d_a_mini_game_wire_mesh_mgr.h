#pragma once

#include "d_base.h"
#include "d_ef.h"
#include "d_mj2d_game.h"
#include "m_ef.h"
#include "s_State.h"

class daMiniGameWireMeshMgr_c : public dBase_c {
    SIZE_ASSERT(0x398);
    // 0x80970950 g_profile_MINI_GAME_WIRE_MESH_MGR
    // 0x8086A040 daMiniGameWireMeshMgr_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daMiniGameWireMeshMgr_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x398);
};

class daMiniGameWireMeshMgrObj_c : public dBase_c {
    SIZE_ASSERT(0x708);
    VTABLE(0x060, fBase_c, 0x80970A88);
    // 0x80970960 g_profile_MINI_GAME_WIRE_MESH_MGR_OBJ
    // 0x8086A070 daMiniGameWireMeshMgrObj_c_classInit

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8086AB90 */
    void EffectCursor2d();

    /* 0x8086AEA0 */
    void EffectPlayerCursor();

    /* 0x8086B230 */
    void updateStockItem();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x1D5);

    /* 0x1D5 */ bool mIsGameFail;
    /* 0x1D6 */ bool mIsBadPanelFlip;

    FILL(0x1D7, 0x1E8);

    /* 0x1E8 */ int mWinItemCount;
    /* 0x1EC */ int mWinStockItem[STOCK_ITEM_COUNT];
    /* 0x208 */ int mTurnPlayer;
    /* 0x20C */ int mTurnPlayerBackup;
    /* 0x210 */ int mPlayNum;

    FILL(0x214, 0x220);

    /* 0x220 */ bool mUpdateCursor;

    FILL(0x221, 0x224);

    /* 0x224 */ dEf::dLevelEffect_c mEffectCursor;
    /* 0x34C */ mEf::effect_c       mEffectCursorSt;

    /* 0x460 */ bool                mHasPlayedCursorSt;

    FILL(0x461, 0x58C);

    /* 0x58C */ mEf::effect_c mEffectCursor2d;

    FILL(0x6A0, 0x708);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8086B3C0
     * executeState:    0x8086B3D0
     * finalizeState:   0x8086B5F0
     */
    sState_Extern(0x8099CE48, daMiniGameWireMeshMgrObj_c, ShowRule);

    /*
     * initializeState: 0x8086B600
     * executeState:    0x8086B6A0
     * finalizeState:   0x8086B7E0
     */
    sState_Extern(0x8099CE88, daMiniGameWireMeshMgrObj_c, Play);

    /*
     * initializeState: 0x8086BA70
     * executeState:    0x8086BB00
     * finalizeState:   0x8086BE80
     */
    sState_Extern(0x8099CEC8, daMiniGameWireMeshMgrObj_c, AllTurnUp);

    /*
     * initializeState: 0x8086BE90
     * executeState:    0x8086BEE0
     * finalizeState:   0x8086C0A0
     */
    sState_Extern(0x8099CF08, daMiniGameWireMeshMgrObj_c, ShowResult);

    /*
     * initializeState: 0x8086B330
     * executeState:    0x8086B370
     * finalizeState:   0x8086B3B0
     */
    sState_Extern(0x8099CF48, daMiniGameWireMeshMgrObj_c, Ready);
};
