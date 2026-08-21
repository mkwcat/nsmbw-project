#pragma once

#include "d_static/d_mj2d/d_mj2d_game.h"
#include "machine/m_vec.h"

class daPyDemoMng_c {
public:
    // Structors
    // ^^^^^^

    /* 0x8005B3A0 */
    daPyDemoMng_c();

    /* VT+0x8 0x8005B3E0 */
    virtual ~daPyDemoMng_c();

public:
    // Constants and Types
    // ^^^^^^

    enum class Mode_e {
        MODE_0 = 0,
        MODE_1 = 1,
        MODE_2 = 2,
        MODE_3 = 3,
        MODE_4 = 4,
        MODE_5 = 5,
        MODE_6 = 6,
        MODE_7 = 7,
        MODE_8 = 8,
    };

    enum GoalDemoFlag_e {
        FLAG_POLE_DOWN      = 0x1,
        FLAG_POLE_DOWN_DONE = 0x2,
    };

public:
    // Functions
    // ^^^^^^

    /* 0x8005B430 */
    void initStage();

    /* 0x8005B4A0 - extern */
    void baseInit();

    /* 0x8005B4A0 */
    void init();

    /* 0x8005B550 */
    void update();

    /* 0x8005B5C0 */
    void setDemoMode(Mode_e mode, int state);

    /* 0x8005B6A0 */
    void calcNotGoalPlayer();

    /* 0x8005B780 */
    int setGoalDemoList(int param);

    /* 0x8005B840 */
    int getPoleBelowPlayer(int param);

    /* 0x8005B8A0 */
    void executeGoalDemo_Pole();

    /* 0x8005BCF0 */
    void executeGoalDemo_PoleDown();

    /* 0x8005BD60 */
    void executeGoalDemo_JumpCheck();

    /* 0x8005BE30 */
    void executeGoalDemo_Jump();

    /* 0x8005BF10 */
    void executeGoalDemo_Land();

    /* 0x8005BFD0 */
    void executeGoalDemo_KimeWait();

    /* 0x8005C130 */
    void setGoalDemoKimeAll();

    /* 0x8005C1A0 */
    void setGoalDemoRunCastle();

    /* 0x8005C210 */
    bool isAllPlayerGoalIn();

    /* 0x8005C6D0 */
    void calcGoalCenterPos();

    /* 0x8005C930 */
    bool startControlDemoAll();

    /* 0x8005C9D0 */
    bool isAllPlayerControlDemo();

    /* 0x8005CA50 */
    void endControlDemoAll(int param);

    /* 0x8005CAD0 */
    int getControlDemoPlayerNum();

    /* 0x8005CB70 */
    void onLandStopReq();

    /* 0x8005CC00 */
    bool startControlDemoLandPlayer();

    /* 0x8005CDD0 */
    bool isLandAll();

    /* 0x8005CE50 */
    void UNDEF_8005CE50(s32 param);

    /* 0x8005CED0 */
    void executeStartToride();

    /* 0x8005D050 */
    void setCourseOutList(s8 param);

    /* 0x8005D0D0 */
    void turnNextDemoNo();

    /* 0x8005D100 */
    void clearDemoNo(s8 param);

    /* 0x8005D280 */
    void genCourseInList();

public:
    // Static Variables
    // ^^^^^^

    /* 0x80429F74 */ static daPyDemoMng_c* mspInstance;

public:
    // Instance Variables
    // ^^^^^^

    /* 0x04 */ Mode_e  mDemoMode;
    /* 0x08 */ int     mDemoState;
    /* 0x0C */ s32     m0x0C;
    /* 0x10 */ u32     mFlags;
    /* 0x14 */ u32     m0x14;
    /* 0x18 */ u32     mPlayerIndex;
    /* 0x1C */ int     mPlayerCount;
    /* 0x20 */ int     mPlayerIDs[4];
    /* 0x30 */ mVec3_c mGoalCenterPos;

    FILL(0x3C, 0x54);

    /* 0x54 */ s32 m0x54;

    FILL(0x58, 0x60);

    /* 0x60 */ int mCourseInList[4];
    /* 0x70 */ int mCourseOutList[4];

    FILL(0x80, 0x84);

    /* 0x84 */ int mOwnedPlayer;

    FILL(0x88, 0x8C);

    /* 0x8C */ s32 m0x8C;

    FILL(0x90, 0x98);
    OFFSET_ASSERT(0x98);

    /* 0x98 */ int mExPlayerIDs[PLAYER_COUNT - 4];
    /* 0xA8 */ int mExCourseInList[PLAYER_COUNT - 4];
    /* 0xB8 */ int mExCourseOutList[PLAYER_COUNT - 4];
};
