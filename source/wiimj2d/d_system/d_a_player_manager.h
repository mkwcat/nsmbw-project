#pragma once

#include "component/c_array.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_player_model_manager.h"
#include "d_yoshi_model.h"
#include "framework/f_base_id.h"

class dAcPy_c;
class daYoshi_c;
class daPlBase_c;
class daPyDemoMng_c;

class daPyMng_c
{
public:
    // Constants
    // ^^^^^^

#define MAX_COINS 99

    static constexpr int START_REST = 5;

    // Static Methods
    // ^^^^^^

    [[nodiscard]]
    static bool isOnePlayer()
    {
        return getEntryNum() == 1;
    }

    [[nodiscard]]
    static bool isOnePlayerInGame()
    {
        return getNumInGame() == 1;
    }

    [[nodiscard]]
    static bool isPlayerActive(int player)
    {
        return mActPlayerInfo & (1ull << player);
    }

    /* 0x8005E9A0 */
    static void createYoshi(mVec3_c&, int, dAcPy_c*);

    /* 0x8005EA60 */
    static void initGame();

    /* 0x8005EB10 */
    static void initStage();

    /* 0x8005ECE0 */
    static void setDefaultParam();

    /* 0x8005ED90 */
    [[nodiscard]]
    static mVec3_c getPlayerSetPos(u8 course, u8 gotoID);

    /* 0x8005EE90 */
    [[nodiscard]]
    static u8 getPlayerCreateAction();

    /* 0x8005EEE0 */
    static bool create(int plrNo, mVec3_c position, int gotoKind, u8 faceLeft);

    /* 0x8005EF50 */
    static void createCourseInit();

    /* 0x8005F570 @unofficial */
    static void initKinopioPlayer(PLAYER_MODE_e playerMode, int player);

    /* 0x8005F5C0 */
    static void update();

    /* 0x8005F8C0 */
    static void setPlayer(int plrNo, dAcPy_c* player);

    /* 0x8005F900 */
    [[nodiscard]]
    static dAcPy_c* getPlayer(int plrNo);

    /* 0x8005F920 */
    static void decideCtrlPlrNo();

    /* 0x8005F990 */
    static bool setYoshi(daPlBase_c* yoshi);

    /* 0x8005FA00 */
    static void releaseYoshi(daPlBase_c* yoshi);

    /* 0x8005FA60 */
    [[nodiscard]]
    static daYoshi_c* getYoshi(int index);

    /* 0x8005FB00 */
    static int getYoshiNum();

    /* 0x8005FB90 */
    static daPlBase_c* getCtrlPlayer(int plrNo);

    static PLAYER_TYPE_e getModelPlayerType(dPyMdlMng_c::ModelType_e modelType);

    static dPyMdlMng_c::ModelType_e getPlayerTypeModelType(PLAYER_TYPE_e playerType);

    /* 0x8005FBE0 */
    static dPyMdlMng_c::ModelType_e getCourseInPlayerModelType(u8 index);

    static int getPlayerColorType(PLAYER_TYPE_e playerType);

    /* 0x8005FC20 @renamed */
    static void setCarryOverYoshiInfo(u8 index, dYoshiMdl_c::COLOR_e color, int fruit);

    /* 0x8005FC40 */
    static dYoshiMdl_c::COLOR_e getYoshiColor(int index);

    /* 0x8005FC50 */
    static int getYoshiFruit(int index);

    /* 0x8005FC70 */
    [[nodiscard]]
    static u32 getActScrollInfo();

    /* 0x8005FD20 */
    [[nodiscard]]
    static u8 getScrollNum();

    /* 0x8005FDB0 */
    static bool addNum(int num);

    /* 0x8005FE30 */
    static bool decNum(int num);

    /* 0x8005FEB0 */
    static int addNum();

    /* 0x8005FED0 */
    static int decNum();

    /* 0x8005FEF0 */
    static int getNumInGame();

    /* 0x8005FFB0 */
    static int getEntryNum();

    /* 0x80060110 @unofficial */
    static int findPlayerWithType(PLAYER_TYPE_e type);

    /* 0x80060170 */
    static bool changeItemKinopioPlrNo(int* ownedPlayer);

    /* 0x80060200 */
    [[nodiscard]]
    static int getCoinAll();

    /* 0x80060250 */
    static void incCoin(int player);

    /* 0x80060460 */
    static void addRest(int player, int num, bool playEffect);

    /* 0x80060590 */
    static void incRestAll(bool playEffect);

    /* 0x80060690 */
    static void addScore(int score, int player);

    /* 0x80060750 */
    static void stopStarBGM();

    /* 0x80060860 */
    static void stopYoshiBGM();

    /* 0x800608E0 */
    static void checkLastAlivePlayer();

    /* 0x80060970 */
    static void executeLastPlayer();

    /* 0x80060A10 */
    static void executeLastAll();

    /* 0x80060AB0 */
    static void deleteCullingYoshi();

    /* 0x80060C10 */
    static void setHipAttackQuake(int param1, u8 param2);

    /* 0x80060DB0 @unofficial */
    static void setHipAttackSpecialEffect();

    /* 0x80060EF0 */
    static void checkBonusNoCap();

    /* 0x80060F20 */
    static void initYoshiPriority();

    /* 0x80060FE0 */
    static void setYoshiPriority();

    /* 0x80061110 */
    [[nodiscard]]
    static bool isCreateBalloon(int index);

    /* 0x80061160 */
    static void checkCorrectCreateInfo();

    // Static Variables
    // ^^^^^^

    /* 0x80355110 */
    static cArray_c<fBaseID_e, PLAYER_COUNT, int> m_playerID;

    /* 0x80355120 */
    static cArray_c<fBaseID_e, PLAYER_COUNT, int> m_yoshiID;

    /* 0x80355130 */
    static cArray_c<s32, PLAYER_COUNT, int> mCourseInList;

    /* 0x80355140 */
    static cArray_c<s32, PLAYER_COUNT, int> m_yoshiFruit;

    /* 0x80355150 */
    static cArray_c<s32, PLAYER_COUNT, int> mPlayerEntry;

    /* 0x80355160 */
    static cArray_c<PLAYER_TYPE_e, PLAYER_COUNT, int> mPlayerType;

    /* 0x80355170 */
    static cEnumArray_c<PLAYER_MODE_e, PLAYER_TYPE_e> mPlayerMode;

    /* 0x80355180 */
    static cEnumArray_c<PLAYER_CREATE_ITEM_e, PLAYER_TYPE_e> mCreateItem;

    /* 0x80355190 */
    static cEnumArray_c<int, PLAYER_TYPE_e> mRest;

    /* 0x803551A0 */
    static cEnumArray_c<int, PLAYER_TYPE_e> mCoin;

    /* 0x803551B0 */
    static cArray_c<s32, PLAYER_COUNT, int> m_quakeTimer;

    /* 0x803551C0 */
    static cArray_c<s32, PLAYER_COUNT, int> m_quakeEffectFlag;

    /* 0x803551E0 */
    static daPyDemoMng_c mDemoManager;

    /* 0x80429F80 */
    static int mNum;

    /* 0x80429F84 */
    static s32 mCtrlPlrNo;

    /* 0x80429F88 */
    static u8 mOldActPlayerInfo;
    static u64 mActPlayerInfo;

    /* 0x80429F8C */
    static cArray_c<u8, PLAYER_COUNT, int> m_yoshiColor;

    /* 0x80429F90 */
    static cArray_c<u16, PLAYER_COUNT, int> m_star_time;

    /* 0x80429F98 */
    static cArray_c<u16, PLAYER_COUNT, int> m_star_count;

    /* 0x80429FA0 */
    static int mScore;

    /* 0x80429FA4 */
    static PLAYER_MODE_e mKinopioMode;

    /* 0x80429FA8 */
    static s32 mTimeUpPlayerNum;

    /* 0x80429FAC */
    static s32 mAllBalloon;

    /* 0x80429FB0 */
    static s32 mPauseEnableInfo;

    /* 0x80429FB4 */
    static s32 mPauseDisable;

    /* 0x80429FB8 */
    static s32 mStopTimerInfo;

    /* 0x80429FBC */
    static s32 mStopTimerInfoOld;

    /* 0x80429FC0 */
    static s32 mQuakeTrigger;

    /* 0x80429FC4 */
    static s32 mBgmState;

    /* 0x80429FC8 */
    static int mBonusNoCap;

    /* 0x80429FCC */
    static int mKinopioCarryCount;
};
