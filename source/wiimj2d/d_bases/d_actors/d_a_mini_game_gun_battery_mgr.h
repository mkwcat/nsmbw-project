#pragma once

#include "d_base.h"
#include "d_mj2d_game.h"
#include "s_FStateFct.h"
#include "s_State.h"
#include "s_StateMgrDefault.h"

class daMiniGameGunBatteryMgr_c : public dBase_c {
    SIZE_ASSERT(0x398);
    // 0x8096FB98 g_profile_MINI_GAME_GUN_BATTERY_MGR
    // 0x808660F0 daMiniGameGunBatteryMgr_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daMiniGameGunBatteryMgr_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x398);
};

class daMiniGameGunBatteryMgrObj_c : public dBase_c {
    // Original size: 0xF4
    VTABLE(0x60, fBase_c, 0x8096FC88);
    // 0x8096FBA8 g_profile_MINI_GAME_GUN_BATTERY_MGR_OBJ
    // 0x80866120 daMiniGameGunBatteryMgrObj_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80866210 */
    daMiniGameGunBatteryMgrObj_c();

    /**
     * VT+0x48 0x80866CF0
     * Destroys the base.
     */
    ~daMiniGameGunBatteryMgrObj_c() override;

public:
    // Virtual Functions
    // ^^^^^^

    /**
     * VT+0x08 0x80866450
     * do method for the create operation.
     */
    PACK_RESULT_e create() override;

    /**
     * VT+0x20 0x808664F0
     * do method for the execute operation.
     */
    PACK_RESULT_e execute() override;

    /**
     * VT+0x24 0x808664B0
     * pre method for the execute operation.
     */
    PACK_RESULT_e preExecute() override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80866530 */
    void hitBalloon(int player, int lives);

    /* 0x80866560 */
    void addResultRest();

    /* 0x808665F0 */
    bool checkMessageClose();

    /* 0x80866640 */
    void setMessageCloseWait(int value);

    /* 0x80866650 */
    void setPlayerDone(int player);

public:
    // Constants and Types
    // ^^^^^^

    struct Player_s {
        SIZE_ASSERT(0xC);

        /* 0x0 */ bool mDone     = false;
        /* 0x4 */ int  mNumLives = 0;
        /* 0x8 */ int  mNumHit   = -1;
    };

public:
    // Instance Variables
    // ^^^^^^

    /* 0x70 */ Player_s REMOVED(mPlayers)[4];
    /* 0xA4 */
    sStateMgrDefault_c<daMiniGameGunBatteryMgrObj_c> mStateMgr;
    /* 0xDC */ int                                   mMessageState;
    /* 0xE0 */ s8                                    m0xE0;
    /* 0xE4 */ int                                   mNumDone;
    /* 0xE8 */ int                                   mNumInGame;
    /* 0xEC */ int                                   mMessageTimer;
    /* 0xF0 */ int                                   mMessageCloseWaitTimer;

    OFFSET_ASSERT(0xF4);

#define OFFSET_daMiniGameGunBatteryMgrObj_c_mPlayers 0xF4
    /* 0xF4 */ Player_s mPlayers[PLAYER_COUNT];

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80866690
     * executeState:    0x808666E0
     * finalizeState:   0x808668C0
     */
    sState_Extern(0x8099CBB0, daMiniGameGunBatteryMgrObj_c, ShowRule);

    /*
     * initializeState: 0x808668D0
     * executeState:    0x80866970
     * finalizeState:   0x80866A20
     */
    sState_Extern(0x8099CBF0, daMiniGameGunBatteryMgrObj_c, Play);

    /*
     * initializeState: 0x80866A30
     * executeState:    0x80866A90
     * finalizeState:   0x80866C80
     */
    sState_Extern(0x8099CC30, daMiniGameGunBatteryMgrObj_c, ShowResult);
};
