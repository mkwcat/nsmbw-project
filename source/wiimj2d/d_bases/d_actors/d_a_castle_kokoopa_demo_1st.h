#pragma once

#include "d_static/d_actor/d_a_boss_demo.h"
#include "d_static/d_a_player/d_a_player_manager.h"

class dAcPy_c;

class daCastleKokoopaDemo1st_c : public daBossDemo_c
{
public:
    // Structors
    // ^^^^^^

    daCastleKokoopaDemo1st_c();

public:
    // Virtual Functions
    // ^^^^^^

    /* 0x807DACB0 */
    /* virtual */ bool checkBattleStDemo();

    /* 0x807DB2E0 */
    /* virtual */ bool demoScroll();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x807DB440 */
    bool calcBattleStDemoControl();

    /* 0x807DB740 */
    bool calcIggyDemoScroll();

    /* 0x807DB920 */
    bool isPlayerEntry(int player);

    /* 0x807DB950 */
    void setFlag115();

    /* 0x807DBA20 */
    void killPlayerFireball();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3DC, 0x3E8);

    /* 0x3E8 */ f32 mLeftBoundary;
    /* 0x3EC */ f32 mRightBoundary;
    /* 0x3F0 */ f32 REMOVED(mWalkToPos)[4];

    FILL(0x400, 0x408);

    /* 0x408 */ s32 mCheckBattleStDemoStep;
    /* 0x40C */ int REMOVED(m0x40C)[4];
    /* 0x41C */ int REMOVED(m0x41C)[4];

    /* 0x42C */ dAcPy_c* REMOVED(mpPlayersInOrder)[4];

    FILL(0x43C, 0x460);

    /* 0x460 */ u8 mLevelEffect[0x128];

    FILL(0x588, 0x590);
    OFFSET_ASSERT(0x590);

    /* 0x590 */ dAcPy_c* mpPlayersInOrder[PLAYER_COUNT];
    /* 0x5B0 */ f32 mWalkToPos[PLAYER_COUNT];
    /* 0x5D0 */ int mBattleStControlStep[PLAYER_COUNT];
    /* 0x5F0 */ int mIggyDemoScrollStep[PLAYER_COUNT];
};
