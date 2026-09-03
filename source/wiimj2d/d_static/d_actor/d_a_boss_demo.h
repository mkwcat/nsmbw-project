#pragma once

#include "d_actor_state.h"
#include "f_base_id.h"
#include "s_State.h"
#include <revolution/types.h>

class dEnBoss_c;

class daBossDemo_c : public dActorState_c {
    SIZE_ASSERT(0x3DC);
    VTABLE(0x060, fBase_c, 0x80301804);

public:
    // Structors
    // ^^^^^^

    daBossDemo_c() {}

public:
    // Instance Variables
    // ^^^^^^

    /* 0x3D0 */ int       m0x3D0;
    /* 0x3D4 */ BOOL      mBattleEnd;
    /* 0x3D8 */ fBaseID_e mBossID;

public:
    // Virtual State IDs
    // ^^^^^^

    /**
     * initializeState: VT+0x0E0 0x8001CF50
     * executeState:    VT+0x0E4 0x8001CF70
     * finalizeState:   VT+0x0E8 0x8001CF60
     */
    sState_ExternVirtual(0x80352970, daBossDemo_c, Ready);

    /**
     * initializeState: VT+0x0EC 0x8001D060
     * executeState:    VT+0x0F0 0x8001D080
     * finalizeState:   VT+0x0F4 0x8001D070
     */
    sState_ExternVirtual(0x803529B0, daBossDemo_c, BattleStDemo);

    /**
     * initializeState: VT+0x0F8 0x8001D090
     * executeState:    VT+0x0FC 0x8001D110
     * finalizeState:   VT+0x100 0x8001D100
     */
    sState_ExternVirtual(0x803529F0, daBossDemo_c, BattleIn);

    /**
     * initializeState: VT+0x104 0x8001D180
     * executeState:    VT+0x108 0x8001D1A0
     * finalizeState:   VT+0x10C 0x8001D190
     */
    sState_ExternVirtual(0x80352A30, daBossDemo_c, BattleEdDemo);

public:
    // Virtual Methods
    // ^^^^^^

    /**
     * VT+0x110
     * Returns to the world map and clears the course after finishing it with Super Guide.
     */
    virtual bool abandonRetryAfterOtehonClear();

    /**
     * VT+0x114
     * Returns to the world map without clearing the course after finishing it with Super Guide.
     */
    virtual void retryAfterOtehonClear();

    /**
     * VT+0x118
     * Starts the boss battle background music.
     */
    virtual void startBGM() {}

    /**
     * VT+0x11C
     * Stops the boss battle background music.
     */
    virtual void stopBGM() {}

    /* VT+0x120 */ virtual fBaseID_e getBossID() { return mBossID; }

    /* VT+0x124 */ virtual void setBossID(
        fBaseID_e bossID
    ) {
        mBossID = bossID;
    }

    /**
     * VT+0x128
     * Returns whether the boss battle start cutscene is ready to play.
     */
    virtual BOOL checkBattleStDemo() { return false; }

    /**
     * VT+0x12C
     * Returns whether the boss battle end cutscene is ready to play.
     */
    virtual BOOL checkBattleEdDemo() { return mBattleEnd; }

    /**
     * VT+0x130
     * Returns whether the camera has finished scrolling to the boss.
     */
    virtual bool demoScroll() { return true; }

    /**
     * VT+0x134
     * Returns the corresponding boss actor.
     */
    virtual dEnBoss_c* bossSearch() { return nullptr; }

    /**
     * VT+0x138
     * Subclass-specific initialization code.
     */
    virtual void initialize() {}
};
