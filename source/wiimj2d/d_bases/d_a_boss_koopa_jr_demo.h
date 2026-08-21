#pragma once

#include "d_static/d_a_boss_demo.h"
#include "d_static/d_util.h"

class dAcPy_c;

// TODO
class daKameckForAirshipDemo_c : public dActor_c {
public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x858);

    /* 0x858 */ float mBossDemoX;
};

// TODO
class daPeachForAirshipDemo_c : public dActor_c {};

class daBossKoopaJrDemo_c : public daBossDemo_c {
public:
    // Structors
    // ^^^^^^

    daBossKoopaJrDemo_c();

public:
    // Virtual Methods
    // ^^^^^^

    /* 0x807D00D0 */
    /* virtual */ void initialize();

    /* 0x807D1570 */
    /* virtual */ void initializeState_BattleStDemo();

    /* 0x807D1690 */
    /* virtual */ void finalizeState_BattleStDemo();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x807D03B0 */
    void sortPlayers();

    /* 0x807D0490 */
    void calcPlayerWalkPos();

    /* 0x807D0800 */
    bool isPlayerEntry(int player);

    /* 0x807D0910 */
    bool checkRestart();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3DC, 0x3E0);

    /* 0x3E0 */ int                       mDemoNum;
    /* 0x3E4 */ float                     mXBased;
    /* 0x3E8 */ float                     mPlayerStandCenter;
    /* 0x3EC */ float                     REMOVED(mPlayerWalkPos)[4];
    /* 0x3FC */ float                     mAirshipDemoX;
    /* 0x400 */ float                     mAirshipDemoY;
    /* 0x404 */ float                     m0x404;
    /* 0x408 */ dAcPy_c*                  REMOVED(mpPlayersInOrder)[4];
    /* 0x418 */ float                     m0x418;
    /* 0x41C */ float                     m0x41C;
    /* 0x420 */ daKameckForAirshipDemo_c* mpKamek;
    /* 0x424 */ daPeachForAirshipDemo_c*  mpPeach;
    /* 0x428 */ float                     REMOVED(mPlrYPos)[4];
    /* 0x438 */ bool                      REMOVED(m0x438)[4];
    /* 0x43C */ Util::dDisp_c             mDisp;
    /* 0x448 */ float                     mSizeY;
    /* 0x44C */ float                     m0x44C;
    /* 0x450 */ float                     mBaseXCopy;
    /* 0x454 */ float                     m0x454;

    FILL(0x458, 0x460);

    /* 0x460 */ float mBaseYCopy;
    /* 0x464 */ float mScreenTopCopy;

    FILL(0x468, 0x470);

    /* 0x470 */ dAcPy_c* mpFirstPlr;
    /* 0x474 */ float    mBaseX2;
    /* 0x478 */ float    mBaseX;
    /* 0x47C */ float    mScreenTop;
    /* 0x480 */ float    mBaseY;
    /* 0x484 */ float    m0x484;

    FILL(0x488, 0x490);
    OFFSET_ASSERT(0x490);

    float    mPlayerWalkPos[PLAYER_COUNT];
    dAcPy_c* mpPlayersInOrder[PLAYER_COUNT];
    float    mPlrYPos[PLAYER_COUNT];
    bool     m0x438[PLAYER_COUNT];

public:
    // State IDs
    // ^^^^^^
};
