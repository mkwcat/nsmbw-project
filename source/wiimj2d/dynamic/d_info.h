#pragma once

#include "System.h"
#include <dynamic/actor/d_a_player_manager.h>
#include <dynamic/d_cyuukan.h>

class dInfo_c
{
    /* 0x000 VTABLE 0x80315EA0 */

public:
    //
    // Constants and Types
    //

    /* @unofficial */
    enum class ScreenType_e {
        NORMAL = 0,
        SUPER_GUIDE = 1,
        TITLE = 2,
        TITLE_REPLAY = 3,
        HINT_MOVIE = 4,
    };

    struct StartGameInfo_s {
        SIZE_ASSERT(0x10);

        /* 0x00 */ u32 demoTime;

        /**
         * Hint movie type (0 = Super Skills, 1 = 1UP, 2 = Star Coin, 3 = Secret Exit)
         */
        /* 0x04 */ u8 demoType;

        /**
         * Goto ID (a.k.a. entrance)
         */
        /* 0x05 */ u8 gotoID;

        /**
         * Course ID (a.k.a. area)
         */
        /* 0x06 */ u8 courseID;

        /* 0x07 */ bool isDemo;

        /* 0x08 */ ScreenType_e screenType;

        /* 0x0C */ u8 world1;
        /* 0x0D */ u8 stage1;
        /* 0x0E */ u8 world2;
        /* 0x0F */ u8 stage2;
    };

public:
    //
    // Constructors
    //

    /* 0x800BB0E0 */
    dInfo_c();

    /* VT+0x8 0x800BB130 */
    virtual ~dInfo_c();

public:
    //
    // Functions
    //

    /* 0x800BB180 */
    void PlayerStateInit();

public:
    //
    // Member Data
    //

    /* 0x004 */ s32 m0x004;

    /* 0x008 */ dCyuukan_c mCyuukan;

    /* 0x03C */ s32 mWorld;
    /* 0x040 */ s32 mLevel;
    /* 0x044 */ s32 mWmNode;

    FILL(0x048, 0x384);

    /* 0x384 */ s32 mPlayerActiveMode[4];

    FILL(0x394, 0xAF4);

    /* 0xAF4 */ s32 m0xAF4;

    FILL(0xAF8, 0xAFC);

    /* 0xAFC */ s32 m0xAFC;

    FILL(0xB00, 0xB5C);
    OFFSET_ASSERT(0xB5C);

    /* 0xB5C */ s32 mExPlayerActiveMode[PLAYER_COUNT - 4];

public:
    //
    // Static Data
    //

    /* 0x80315E98 */ static StartGameInfo_s m_startGameInfo;

    /* 0x8042A25C */ static dInfo_c* m_instance;
};