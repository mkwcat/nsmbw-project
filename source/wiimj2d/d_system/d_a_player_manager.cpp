// d_a_player_manager.cpp
// NSMBW .text: 0x8005E9A0 - 0x800613B0

#include "d_a_player_manager.h"

#include "d_bases/d_s_stage.h"
#include "d_player/d_a_player.h"
#include "d_player/d_a_yoshi.h"
#include "d_player/d_gamedisplay.h"
#include "d_profile/d_profile.h"
#include "d_system/d_a_player_demo_manager.h"
#include "d_system/d_audio.h"
#include "d_system/d_balloon_mng.h"
#include "d_system/d_bg_parameter.h"
#include "d_system/d_course_data.h"
#include "d_system/d_game_common.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_multi_manager.h"
#include "d_system/d_next.h"
#include "d_system/d_pause_manager.h"
#include "d_system/d_player_effect_mng.h"
#include "d_system/d_player_model_manager.h"
#include "d_system/d_quake.h"
#include "d_system/d_score_mng.h"
#include "d_system/d_stage_timer.h"
#include "d_system/d_yoshi_model.h"
#include "framework/f_feature.h"
#include "framework/f_manager.h"
#include "machine/m_ef.h"
#include "machine/m_vec.h"
#include "sound/SndID.h"
#include "sound/SndSceneMgr.h"
#include <algorithm>
#include <mkwcat/Relocate.hpp>
#include <numeric>
#include <revolution/os.h>
#include <revolution/os/OSLink.h>

[[nsmbw_data(0x80429F80)]]
int daPyMng_c::mNum;

[[nsmbw_data(0x80429F84)]]
s32 daPyMng_c::mCtrlPlrNo;

[[nsmbw_data(0x80429F88)]]
u8 daPyMng_c::mOldActPlayerInfo;

u64 daPyMng_c::mActPlayerInfo;

/* 0x80355110 */
fBaseID_e daPyMng_c::m_playerID[PLAYER_COUNT];

/* 0x80355120 */
fBaseID_e daPyMng_c::m_yoshiID[PLAYER_COUNT];

/* 0x80355130 */
s32 daPyMng_c::mCourseInList[PLAYER_COUNT];

/* 0x80429F8C */
u8 daPyMng_c::m_yoshiColor[PLAYER_COUNT];

/* 0x80355140 */
s32 daPyMng_c::m_yoshiFruit[PLAYER_COUNT];

/* 0x80355150 */
s32 daPyMng_c::mPlayerEntry[PLAYER_COUNT];

/* 0x80355160 */
// Index is player ID
PLAYER_TYPE_e daPyMng_c::mPlayerType[PLAYER_COUNT] = {
  dMj2dGame_c::scDefaultPlayerTypes[0], dMj2dGame_c::scDefaultPlayerTypes[1],
  dMj2dGame_c::scDefaultPlayerTypes[2], dMj2dGame_c::scDefaultPlayerTypes[3],
  dMj2dGame_c::scDefaultPlayerTypes[4], dMj2dGame_c::scDefaultPlayerTypes[5],
  dMj2dGame_c::scDefaultPlayerTypes[6], dMj2dGame_c::scDefaultPlayerTypes[7]
};

/* 0x80355170 */
// Index is player type
PLAYER_MODE_e daPyMng_c::mPlayerMode[CHARACTER_COUNT];

/* 0x80355180 */
// Index is player type
PLAYER_CREATE_ITEM_e daPyMng_c::mCreateItem[CHARACTER_COUNT];

/* 0x80355190 */
// Index is player type
int daPyMng_c::mRest[CHARACTER_COUNT] = {5, 5, 5, 5, 5, 5, 5, 5};

/* 0x803551A0 */
// Index is player type
s32 daPyMng_c::mCoin[CHARACTER_COUNT];

/* 0x803551B0 */
s32 daPyMng_c::m_quakeTimer[CHARACTER_COUNT];

/* 0x803551C0 */
s32 daPyMng_c::m_quakeEffectFlag[CHARACTER_COUNT];

/* 0x803551E0 */
static daPyDemoMng_c mDemoManager;

/* 0x80429F90 */
u16 daPyMng_c::m_star_time[CHARACTER_COUNT];

/* 0x80429F98 */
u16 daPyMng_c::m_star_count[CHARACTER_COUNT];

[[nsmbw_data(0x80429FA0)]]
int daPyMng_c::mScore;

[[nsmbw_data(0x80429FA4)]]
int daPyMng_c::mKinopioMode;

[[nsmbw_data(0x80429FA8)]]
s32 daPyMng_c::mTimeUpPlayerNum;

[[nsmbw_data(0x80429FAC)]]
s32 daPyMng_c::mAllBalloon;

[[nsmbw_data(0x80429FB0)]]
s32 daPyMng_c::mPauseEnableInfo;

[[nsmbw_data(0x80429FB4)]]
s32 daPyMng_c::mPauseDisable;

[[nsmbw_data(0x80429FB8)]]
s32 daPyMng_c::mStopTimerInfo;

[[nsmbw_data(0x80429FBC)]]
s32 daPyMng_c::mStopTimerInfoOld;

[[nsmbw_data(0x80429FC0)]]
s32 daPyMng_c::mQuakeTrigger;

[[nsmbw_data(0x80429FC4)]]
s32 daPyMng_c::mBgmState;

[[nsmbw_data(0x80429FC8)]]
int daPyMng_c::mBonusNoCap;

[[nsmbw_data(0x80429FCC)]]
int daPyMng_c::mKinopioCarryCount;

// Functions
// ^^^^^^

[[nsmbw(0x8005E9A0)]]
void daPyMng_c::createYoshi(mVec3_c&, int, dAcPy_c*);

[[nsmbw(0x8005EA60)]]
void daPyMng_c::initGame()
{
    mActPlayerInfo |= 1;
    mOldActPlayerInfo |= 1;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        mPlayerType[i] = dMj2dGame_c::scDefaultPlayerTypes[i];
        mPlayerEntry[i] = 0;

        int playerIndex = int(dMj2dGame_c::scDefaultPlayerTypes[i]);
        mPlayerMode[playerIndex] = PLAYER_MODE_e::NONE;
        mCreateItem[playerIndex] = PLAYER_CREATE_ITEM_e::NONE;
    }

    setDefaultParam();

    mBonusNoCap = 0;
    mKinopioCarryCount = 0;
}

[[nsmbw(0x8005EB10)]]
void daPyMng_c::initStage()
{
    checkCorrectCreateInfo();

    mNum = 0;
    mActPlayerInfo = 0;
    mOldActPlayerInfo = 0;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        setPlayer(i, nullptr);
        m_star_time[i] = 0;
        m_star_count[i] = 0;
    }

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mPlayerEntry[i] != 0) {
            addNum(i);
        }
    }

    if (dScStage_c::getCourseIn() && dInfo_c::m_instance->mCyuukanState >= 0 && isOnePlayer() &&
        dInfo_c::m_instance->mCyuukan.mIsKinopioInChukan) {
        for (int i = 0; i < PLAYER_COUNT; i++) {
            if (mPlayerEntry[i] == 0) {
                initKinopioPlayer(0, i);
                break;
            }
        }
    }

    mTimeUpPlayerNum = 0;
    mAllBalloon = 0;
    mPauseEnableInfo = 0;
    mPauseDisable = 0;
    mStopTimerInfo = 0;
    mStopTimerInfoOld = 0;
    mQuakeTrigger = 0;

    for (int i = 0; i < CHARACTER_COUNT; i++) {
        m_quakeTimer[i] = 0;
        m_quakeEffectFlag[i] = 0;
    }

    mBgmState = 0;

    checkBonusNoCap();

    mKinopioCarryCount = 0;

    daPyDemoMng_c::mspInstance->initStage();
    dMultiMng_c::mspInstance->initStage();
}

[[nsmbw(0x8005ECE0)]]
void daPyMng_c::setDefaultParam()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        int playerIndex = int(mPlayerType[i]);
        mRest[playerIndex] = 5;
        mCoin[playerIndex] = 0;
        m_playerID[i] = fBaseID_e::NONE;
        m_yoshiID[i] = fBaseID_e::NONE;
    }

    mScore = 0;
}

[[nsmbw(0x8005ED90)]]
mVec3_c daPyMng_c::getPlayerSetPos(u8 course, u8 gotoID);

[[nsmbw(0x8005EE90)]]
u8 daPyMng_c::getPlayerCreateAction();

[[nsmbw(0x8005EEE0)]]
bool daPyMng_c::create(int player, mVec3_c position, int gotoKind, u8 faceLeft)
{
    if (!(mPlayerEntry[player])) {
        return false;
    }

    dActor_c::construct(
      dProf::PLAYER, u32(faceLeft) << 24 | u32(gotoKind & 0xFF) << 16 | u32(player & 63), &position,
      nullptr, 0
    );
    return true;
}

[[nsmbw(0x8005EF50)]]
void daPyMng_c::createCourseInit()
{
    dScStage_c* stage = dScStage_c::m_instance;
    mVec3_c playerSetPos = getPlayerSetPos(stage->mCourse, stage->mGoto);

    u8 entType = getPlayerCreateAction();

    OS_REPORT(
      "daPyMng_c::createCourseInit: Course(%d) Goto(%d) EntranceType(%d) Position(%f, %f, %f)\n",
      stage->mCourse, stage->mGoto, entType, playerSetPos.x, playerSetPos.y, playerSetPos.z
    );

    if (entType != 0 /* NORMAL */ && entType != 1 /* NORMAL1 */ && entType != 27 /* BOSS_STAND */) {
        // Handle any other entType values
        daPyDemoMng_c::mspInstance->genCourseInList();
        f32 dispCenter = dGameCom::getDispCenterX();
        for (int i = 0; i < PLAYER_COUNT; i++) {
            create(i, playerSetPos, entType, dispCenter < 0);
        }

        return;
    }

    // Handle NORMAL, NORMAL1, BOSS_STAND
    daPyDemoMng_c::mspInstance->init();
    decideCtrlPlrNo();

    if (!dScStage_c::m_isStaffCredit) {
        bool isAmbush;

        if (stage->m_isCourseIn && dInfo_c::m_instance->mCyuukanState >= 0) {
            playerSetPos = dInfo_c::m_instance->mCyuukan.mPlayerSetPos;
            isAmbush = dInfo_c::m_instance->mCyuukan.m0x14 & 1;
        } else {
            isAmbush = dCd_c::getFileP(stage->mCourse)->mpCourseInfo->mIsAmbush;
        }

        int createOrder[PLAYER_COUNT];
        std::iota(createOrder, createOrder + PLAYER_COUNT, 0);
        int entryNum = getEntryNum();

        if (dInfo_c::m_startGameInfo.screenType != dInfo_c::ScreenType_e::TITLE) {
            // Randomize the spawn order
            float createOrderRandom[PLAYER_COUNT];
            int randomCount = entryNum > 4 ? entryNum : 4;

            for (int i = 0; i < randomCount; i++) {
                createOrderRandom[i] = dGameCom::rnd();
            }

            std::sort(
              &createOrder[0], &createOrder[PLAYER_COUNT], [createOrderRandom](int l, int r) {
                return createOrderRandom[l] < createOrderRandom[r];
            }
            );
        }

        int livePlayerCount = 0;
        for (int i = 0; i < PLAYER_COUNT; i++) {
            if (mPlayerEntry[i] && !isCreateBalloon(i)) {
                livePlayerCount++;
            }
        }

        f32 playerSetDist = 24.0f;

        if (entryNum > 4 && dInfo_c::m_startGameInfo.screenType != dInfo_c::ScreenType_e::TITLE) {
            playerSetDist -= 2.0f * (entryNum - 4);
        }

        f32 playerSetOffset = playerSetDist / 2 * (livePlayerCount - 1);

        if (isAmbush) {
            playerSetPos.x -= playerSetOffset;
        } else {
            playerSetPos.x += playerSetOffset;
        }

        for (int i = 0; i < PLAYER_COUNT; i++) {
            if (createOrder[i] == -1) {
                continue;
            }

            bool result = create(createOrder[i], playerSetPos, entType, isAmbush);

            if (result && !isCreateBalloon(createOrder[i])) {
                if (isAmbush) {
                    playerSetPos.x += playerSetDist;
                } else {
                    playerSetPos.x -= playerSetDist;
                }
            }
        }
    } else {
        // Setup spawn for staff credits
        playerSetPos.x += 512 - 320;

        static const f32 l_STAFF_CREDIT_POS[8][2] = {
          {-192, -48},
          {192, -48},
          {-216, 0},
          {216, 0},

          // New positions
          {-168, -80},
          {168, -80},
          {-144, -80},
          {144, -80},
        };

        for (int i = 0; i < PLAYER_COUNT; i++) {
            if (mPlayerEntry[i] != 0) {
                mVec3_c pos = {
                  playerSetPos.x + l_STAFF_CREDIT_POS[i % 8][0],
                  playerSetPos.y + l_STAFF_CREDIT_POS[i % 8][1],
                  playerSetPos.z,
                };
                create(i, pos, 0, l_STAFF_CREDIT_POS[i % 8][0] > 0);
            }
        }
    }
}

[[nsmbw(0x8005F570)]]
void daPyMng_c::initKinopioPlayer(int kinopioMode, int index)
{
    mActPlayerInfo |= 1 << index;
    mOldActPlayerInfo |= 1 << index;
    mPlayerEntry[index] = 1;
    mCreateItem[int(mPlayerType[index])] = PLAYER_CREATE_ITEM_e::RESCUE_TOAD;
    mKinopioMode = kinopioMode;
}

static int mDeathCount[PLAYER_COUNT] = {};

[[nsmbw(0x8005F5C0)]]
void daPyMng_c::update()
{
    // Hack for incrementing death count
    if (fFeat::infinite_lives) {
        for (int i = 0; i < PLAYER_COUNT; i++) {
            if (mRest[i] == 4) {
                mDeathCount[i]++;
            }
            mRest[i] = 5;
        }
    }

    checkLastAlivePlayer();
    if (dGameDisplay_c* display = dScStage_c::getGameDisplay()) {
        if (fFeat::infinite_lives) {
            display->updatePlayNum(mDeathCount);
        } else {
            display->updatePlayNum(mRest);
        }
        display->setCoinNum(getCoinAll());
        display->setScore(mScore);
        display->setCollect();
    }

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (m_quakeTimer[i] != 0) {
            m_quakeTimer[i]--;
            if (m_quakeTimer[i] == 0) {
                m_quakeEffectFlag[i] = 0;
            }
        }
    }

    if (dNext_c::m_instance->mExitReq) {
        bool wait = false;

        for (int i = 0; i < PLAYER_COUNT; i++) {
            if (!isPlayerActive(i)) {
                continue;
            }

            if (daPlBase_c* player = getCtrlPlayer(i);
                player && !player->isStatus(100) && !player->isWaitFrameCountMax()) {
                wait = true;
            }
        }

        if (!wait) {
            dNext_c::m_instance->mTimer = 0;
        }
    }

    if (dQuake_c::m_instance->mFlags.off(0x38)) {
        mQuakeTrigger = 0;
    } else if (mQuakeTrigger == 0) {
        for (int i = 0; i < PLAYER_COUNT; i++) {
            daPlBase_c* player = getCtrlPlayer(i);
            if (player == nullptr) {
                continue;
            }

            if (dQuake_c::m_instance->mFlags.on(0x20)) {
                player->onStatus(139);
            } else if (dQuake_c::m_instance->mFlags.on(0x8) || m_quakeEffectFlag[i] == 0) {
                player->onStatus(140);
            }
        }

        mQuakeTrigger = 1;
    } else {
        mQuakeTrigger = 1;
    }

    PauseManager_c::m_instance->setPauseEnable(mPauseDisable == 0);

    if (mStopTimerInfo != mStopTimerInfoOld) {
        dStageTimer_c::m_instance->mPause = mStopTimerInfo != 0;
        mStopTimerInfoOld = mStopTimerInfo;
    }

    daPyDemoMng_c::mspInstance->update();
    dPyEffectMng_c::mspInstance->update();
}

[[nsmbw(0x8005F8C0)]]
void daPyMng_c::setPlayer(int index, dAcPy_c* player);

[[nsmbw(0x8005F900)]]
dAcPy_c* daPyMng_c::getPlayer(int index);

[[nsmbw(0x8005F920)]]
void daPyMng_c::decideCtrlPlrNo()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mActPlayerInfo & (1 << i)) {
            mCtrlPlrNo = i;
            return;
        }
    }
}

[[nsmbw(0x8005F990)]]
bool daPyMng_c::setYoshi(daPlBase_c* yoshi)
{
    if (yoshi == nullptr) {
        return false;
    }

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (m_yoshiID[i] == fBaseID_e::NONE) {
            m_yoshiID[i] = yoshi->mUniqueID;
            return true;
        }
    }
    return false;
}

[[nsmbw(0x8005FA00)]]
void daPyMng_c::releaseYoshi(daPlBase_c* yoshi)
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (m_yoshiID[i] == yoshi->mUniqueID) {
            m_yoshiID[i] = fBaseID_e::NONE;
            return;
        }
    }
}

[[nsmbw(0x8005FA60)]]
daYoshi_c* daPyMng_c::getYoshi(int index)
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        daYoshi_c* yoshi = static_cast<daYoshi_c*>(fManager_c::searchBaseByID(m_yoshiID[i]));
        if (yoshi != nullptr && yoshi->getPlrNo() == index) {
            return yoshi;
        }
    }

    return nullptr;
}

[[nsmbw(0x8005FB00)]]
int daPyMng_c::getYoshiNum()
{
    int yoshiNum = 0;
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (fManager_c::searchBaseByID(m_yoshiID[i]) != nullptr) {
            yoshiNum++;
        }
    }
    return yoshiNum;
}

[[nsmbw(0x8005FB90)]]
daPlBase_c* daPyMng_c::getCtrlPlayer(int index);

PLAYER_TYPE_e daPyMng_c::getModelPlayerType(dPyMdlMng_c::ModelType_e modelType)
{
    int modelIndex = static_cast<int>(modelType);

    using PlayerTypeArray = PLAYER_TYPE_e[];
    return PlayerTypeArray{
      PLAYER_TYPE_e::MARIO,       PLAYER_TYPE_e::LUIGI,           PLAYER_TYPE_e::BLUE_TOAD,
      PLAYER_TYPE_e::YELLOW_TOAD, PLAYER_TYPE_e::BLUE_TOAD,       PLAYER_TYPE_e::LUIGI,
      PLAYER_TYPE_e::TOADETTE,    PLAYER_TYPE_e::PURPLE_TOADETTE, PLAYER_TYPE_e::BLACK_TOAD,
      PLAYER_TYPE_e::ORANGE_TOAD,
    }[modelIndex];
}

dPyMdlMng_c::ModelType_e daPyMng_c::getPlayerTypeModelType(PLAYER_TYPE_e playerType)
{
    int playerTypeInt = static_cast<int>(playerType) % 8;

    if (!!(mCreateItem[playerTypeInt] & PLAYER_CREATE_ITEM_e::RESCUE_TOAD)) {
        return dPyMdlMng_c::ModelType_e::MODEL_TOAD_RED;
    }

    using ModelTypeArray = dPyMdlMng_c::ModelType_e[];
    return ModelTypeArray{
      dPyMdlMng_c::ModelType_e::MODEL_MARIO,       dPyMdlMng_c::ModelType_e::MODEL_LUIGI,
      dPyMdlMng_c::ModelType_e::MODEL_TOAD_BLUE,   dPyMdlMng_c::ModelType_e::MODEL_TOAD_YELLOW,
      dPyMdlMng_c::ModelType_e::MODEL_TOADETTE,    dPyMdlMng_c::ModelType_e::MODEL_TOADETTE_PURPLE,
      dPyMdlMng_c::ModelType_e::MODEL_TOAD_ORANGE, dPyMdlMng_c::ModelType_e::MODEL_TOAD_BLACK,
    }[playerTypeInt];
}

[[nsmbw(0x8005FBE0)]]
dPyMdlMng_c::ModelType_e daPyMng_c::getCourseInPlayerModelType(u8 index)
{
    return getPlayerTypeModelType(mPlayerType[index]);
}

int daPyMng_c::getPlayerColorType(PLAYER_TYPE_e playerType)
{
    return static_cast<int>(getModelPlayerType(getPlayerTypeModelType(playerType)));
}

[[nsmbw(0x8005FC20)]]
void daPyMng_c::storeYoshiInfo(int index, dYoshiMdl_c::COLOR_e color, int fruit)
{
    m_yoshiColor[index] = static_cast<u8>(color);
    m_yoshiFruit[index] = fruit;
}

[[nsmbw(0x8005FC40)]]
dYoshiMdl_c::COLOR_e daPyMng_c::getYoshiColor(int index)
{
    return static_cast<dYoshiMdl_c::COLOR_e>(m_yoshiColor[index]);
}

[[nsmbw(0x8005FC50)]]
int daPyMng_c::getYoshiFruit(int index)
{
    return m_yoshiFruit[index];
}

[[nsmbw(0x8005FC70)]]
u32 daPyMng_c::getActScrollInfo()
{
    u32 info = 0;
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mPlayerEntry[i] == 0) {
            continue;
        }

        dAcPy_c* player = getPlayer(i);
        if (player == nullptr || player->mScrollType != 1) {
            info |= 1 << i;
        }
    }
    return info;
}

[[nsmbw(0x8005FD20)]]
u8 daPyMng_c::getScrollNum()
{
    int scrollNum = 0;
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mPlayerEntry[i] == 0) {
            continue;
        }

        dAcPy_c* player = getPlayer(i);
        if (player == nullptr || player->mScrollType != 1) {
            scrollNum++;
        }
    }
    return (u8) scrollNum;
}

[[nsmbw(0x8005FDB0)]]
bool daPyMng_c::addNum(int num)
{
    if (mActPlayerInfo & (1 << num)) {
        return false;
    }

    mActPlayerInfo |= 1 << num;
    mOldActPlayerInfo |= 1 << num;
    if (auto player = getPlayer(num); !player || !player->isItemKinopio()) {
        addNum();
    }
    return true;
}

[[nsmbw(0x8005FE30)]]
bool daPyMng_c::decNum(int num)
{
    if (!(mActPlayerInfo & (1 << num))) {
        return false;
    }

    mActPlayerInfo &= ~(1 << num);
    mOldActPlayerInfo &= ~(1 << num);
    if (auto player = getPlayer(num); !player || !player->isItemKinopio()) {
        decNum();
    }
    decideCtrlPlrNo();

    return true;
}

[[nsmbw(0x8005FEB0)]]
int daPyMng_c::addNum()
{
    if (mNum >= PLAYER_COUNT) {
        return mNum;
    }
    return mNum++;
}

[[nsmbw(0x8005FED0)]]
int daPyMng_c::decNum()
{
    if (mNum <= 0) {
        return mNum;
    }
    return mNum--;
}

[[nsmbw(0x8005FEF0)]]
int daPyMng_c::getNumInGame()
{
    int inGameCount = 0;
    for (int i = 0; i < CHARACTER_COUNT; i++) {
        if (mPlayerEntry[i] != 0 && mRest[int(mPlayerType[i])] > 0) {
            inGameCount++;
        }
    }
    return inGameCount;
}

[[nsmbw(0x8005FFB0)]]
int daPyMng_c::getEntryNum()
{
    int entryNum = 0;
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mPlayerEntry[i] != 0) {
            entryNum++;
        }
    }
    return entryNum;
}

[[nsmbw(0x80060110)]]
int daPyMng_c::findPlayerWithType(PLAYER_TYPE_e playerType)
{
    for (int i = 0; i < CHARACTER_COUNT; i++) {
        if (mPlayerType[i] == playerType) {
            return i;
        }
    }
    return -1;
}

[[nsmbw(0x80060170)]]
bool daPyMng_c::changeItemKinopioPlrNo(int* ownedPlayer);

[[nsmbw(0x80060200)]]
int daPyMng_c::getCoinAll()
{
    int totalCoins = 0;
    for (int i = 0; i < CHARACTER_COUNT; i++) {
        totalCoins += mCoin[i];
    }
    return totalCoins;
}

[[nsmbw(0x80060250)]]
void daPyMng_c::incCoin(int player)
{
    changeItemKinopioPlrNo(&player);
    dMultiMng_c::mspInstance->incCoin(player);

    if (getCoinAll() < MAX_COINS) {
        mCoin[player]++;
        return;
    }

    int noEntry = getEntryNum() <= 0;
    if (!noEntry) {
        dBgParameter_c* bgParam = dBgParameter_c::ms_Instance_p;
        nw4r::math::VEC2 pos = dAudio::cvtSndObjctPos({
          bgParam->mScreenLeft + bgParam->mScreenWidth / 2,
          bgParam->mScreenTop - bgParam->mScreenHeight / 2,
        });

        u32 remoteMask = 0;
        for (int i = 0; i < PLAYER_COUNT; i++) {
            if (mPlayerEntry[i] != 0) {
                remoteMask |= dAudio::getRemotePlayer(i);
            }
        }

        dAudio::SndObjctCmnMap_c* objMap = dAudio::g_pSndObjMap;
        objMap->startSound(SndID::SE_SYS_100COIN_ONE_UP, pos, remoteMask);
        objMap->startSound(SndID::SE_SYS_100COIN_ONE_UP_RC, pos, remoteMask);
    }

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mPlayerEntry[i] == 0) {
            continue;
        }

        if (dAcPy_c* pPlayer = getPlayer(i); pPlayer && pPlayer->isStatus(4)) {
            addRest(i, 1, !noEntry);
        } else {
            dScoreMng_c::m_instance->UNDEF_800E25A0(8, i, noEntry);
        }
    }

    for (int i = 0; i < PLAYER_COUNT; i++) {
        mCoin[static_cast<int>(mPlayerType[i])] = 0;
    }
}

[[nsmbw(0x80060460)]]
void daPyMng_c::addRest(int player, int num, bool playEffect);

[[nsmbw(0x80060590)]]
void daPyMng_c::incRestAll(bool playEffect)
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mPlayerEntry[i] != 0) {
            addRest(i, fFeat::infinite_lives ? 0 : 1, playEffect);
        }
    }
}

// TODO (not that important)
[[nsmbw(0x80060690)]]
void daPyMng_c::addScore(int score, int player);

// TODO (not that important)
[[nsmbw(0x80060750)]]
void daPyMng_c::stopStarBGM();

// TODO (not that important)
[[nsmbw(0x80060860)]]
void daPyMng_c::stopYoshiBGM();

/* 0x800608E0 */
[[nsmbw(0x800608E0)]]
void daPyMng_c::checkLastAlivePlayer();

[[nsmbw(0x80060970)]]
void daPyMng_c::executeLastPlayer()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        daYoshi_c* yoshi = static_cast<daYoshi_c*>(fManager_c::searchBaseByID(m_yoshiID[i]));
        if (yoshi != nullptr) {
            yoshi->executeLastPlayer();
        }
    }

    for (int i = 0; i < PLAYER_COUNT; i++) {
        dAcPy_c* player = getPlayer(i);
        if (player != nullptr) {
            player->executeLastPlayer();
        }
    }
}

[[nsmbw(0x80060A10)]]
void daPyMng_c::executeLastAll()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        daYoshi_c* yoshi = static_cast<daYoshi_c*>(fManager_c::searchBaseByID(m_yoshiID[i]));
        if (yoshi != nullptr) {
            yoshi->executeLastAll();
        }
    }

    for (int i = 0; i < PLAYER_COUNT; i++) {
        dAcPy_c* player = getPlayer(i);
        if (player != nullptr) {
            player->executeLastAll();
        }
    }
}

// TODO (not important)
[[nsmbw(0x80060AB0)]]
void daPyMng_c::deleteCullingYoshi();

[[nsmbw(0x80060C10)]]
void daPyMng_c::setHipAttackQuake(int type, u8 player)
{
    if (player == 0xFF) {
        return;
    }

    if (type == 2) {
        dQuake_c::m_instance->shockMotor(player, dQuake_c::TYPE_SHOCK_e::HIP_ATTACK2, 0, false);
        return;
    }

    m_quakeTimer[player] = 5;
    m_quakeEffectFlag[player] = 0;

    int count = 0;
    for (int other = 0; other < PLAYER_COUNT; other++) {
        if (other != player && m_quakeTimer[other] != 0) {
            count++;
        }
    }

    if (dScStage_c::m_isStaffCredit ||
        (!fFeat::one_player_special_hip_attack_quake && count == 0)) {
        if (type == 1) {
            dQuake_c::m_instance->startShock(
              player, dQuake_c::TYPE_SHOCK_e::HIP_ATTACK, 3, 0, false
            );
        } else {
            dQuake_c::m_instance->shockMotor(
              player, dQuake_c::TYPE_SHOCK_e::PLAYER_DAMAGE, 0, false
            );
        }
    } else {
        SndID::Type l_QUAKE_SOUND_LIST[] = {
          SndID::SE_PLY_HPDP_SPECIAL_TWO,
          SndID::SE_PLY_HPDP_SPECIAL_THREE,
          SndID::SE_PLY_HPDP_SPECIAL_FOUR,
        };

        SndAudioMgr::sInstance->startSystemSe(l_QUAKE_SOUND_LIST[std::clamp(count - 1, 0, 2)], 1);

        if (fFeat::bubble_swarm_mode) {
            dBalloonMng_c::m_instance->popAll();
        }

        setHipAttackSpecialEffect();
    }
}

[[nsmbw(0x80060DB0)]]
void daPyMng_c::setHipAttackSpecialEffect()
{
    SndSceneMgr::sInstance->onPowerImpact();

    for (std::size_t ply = 0; ply < PLAYER_COUNT; ply++) {
        if (m_quakeTimer[ply] == 0 || m_quakeEffectFlag[ply] != 0) {
            continue;
        }

        m_quakeEffectFlag[ply] = 1;

        dAcPy_c* player = getPlayer(ply);
        if (player == nullptr) {
            continue;
        }
        daPlBase_c* base = player;

        if (player->isStatus(daPlBase_c::Status_e::RIDING_YOSHI)) {
            base = player->getRideYoshi();
            if (base == nullptr) {
                continue;
            }
        }

        mVec3_c effectPos = base->mPos;
        mEf::createEffect("Wm_mr_vshipattack", 0, &effectPos, nullptr, nullptr);
        effectPos.z = 3000.0f;
        mEf::createEffect("Wm_mr_vshipattack_ind", 0, &effectPos, nullptr, nullptr);
        dQuake_c::m_instance->startShock(ply, dQuake_c::TYPE_SHOCK_e::HIP_ATTACK, 3, 18, false);
    }
}

[[nsmbw(0x80060EF0)]]
void daPyMng_c::checkBonusNoCap()
{
    mBonusNoCap = mRest[int(PLAYER_TYPE_e::MARIO)] >= MAX_LIVES;
}

// TODO
[[nsmbw(0x80060F20)]]
void daPyMng_c::initYoshiPriority();

// TODO
[[nsmbw(0x80060FE0)]]
void daPyMng_c::setYoshiPriority();

[[nsmbw(0x80061110)]]
bool daPyMng_c::isCreateBalloon(int index)
{
    int playerType = int(mPlayerType[index]);

    return !!(mCreateItem[playerType] & PLAYER_CREATE_ITEM_e::BUBBLE) || mRest[playerType] <= 0;
}

[[nsmbw(0x80061160)]]
void daPyMng_c::checkCorrectCreateInfo()
{
    for (int i = 0; i < CHARACTER_COUNT; i++) {
        if (mPlayerType[i] >= PLAYER_TYPE_e::COUNT || mPlayerType[i] < PLAYER_TYPE_e::MARIO) {
            mPlayerType[i] = PLAYER_TYPE_e::MARIO;
        }

        int playerType = int(mPlayerType[i]);

        if (mPlayerMode[playerType] >= PLAYER_MODE_e::COUNT ||
            mPlayerMode[playerType] < PLAYER_MODE_e::NONE) {
            mPlayerMode[playerType] = PLAYER_MODE_e::NONE;
        }

        if (mRest[playerType] > MAX_LIVES || mRest[playerType] < 0) {
            mRest[playerType] = 5;
        }
    }

    if (int coinCount = getCoinAll(); coinCount < 0 || coinCount > MAX_COINS) {
        for (int i = 0; i < CHARACTER_COUNT; i++) {
            mCoin[i] = 0;
        }
    }

    if (mScore > MAX_SCORE) {
        mScore = MAX_SCORE;
    }
}

PATCH_REFERENCES(
  &daPyMng_c::m_playerID, //
  {
    {0x8005EA6A, R_PPC_ADDR16_HA}, {0x8005EA76, R_PPC_ADDR16_LO}, {0x8005EB26, R_PPC_ADDR16_HA},
    {0x8005EB2A, R_PPC_ADDR16_LO}, {0x8005ECE6, R_PPC_ADDR16_HA}, {0x8005ECEA, R_PPC_ADDR16_LO},
    {0x8005F572, R_PPC_ADDR16_HA}, {0x8005F57A, R_PPC_ADDR16_LO}, {0x8005F5D6, R_PPC_ADDR16_HA},
    {0x8005F5DA, R_PPC_ADDR16_LO}, {0x8005F8CA, R_PPC_ADDR16_HA}, {0x8005F8D2, R_PPC_ADDR16_LO},
    {0x8005F8E2, R_PPC_ADDR16_HA}, {0x8005F8EA, R_PPC_ADDR16_LO}, {0x8005F902, R_PPC_ADDR16_HA},
    {0x8005F90A, R_PPC_ADDR16_LO}, {0x8005FEF2, R_PPC_ADDR16_HA}, {0x8005FEFA, R_PPC_ADDR16_LO},
    {0x8006026A, R_PPC_ADDR16_HA}, {0x8006026E, R_PPC_ADDR16_LO}, {0x80060C1E, R_PPC_ADDR16_HA},
    {0x80060C26, R_PPC_ADDR16_LO}, {0x80061112, R_PPC_ADDR16_HA}, {0x8006111A, R_PPC_ADDR16_LO},
    {0x80061182, R_PPC_ADDR16_HA}, {0x80061186, R_PPC_ADDR16_LO}, {0x80061322, R_PPC_ADDR16_HA},
    {0x80061326, R_PPC_ADDR16_LO},
  }
);

PATCH_REFERENCES(
  &daPyMng_c::m_yoshiID, //
  {
    {0x8005F9A2, R_PPC_ADDR16_HA}, {0x8005F9AA, R_PPC_ADDR16_LO}, {0x8005F9C6, R_PPC_ADDR16_HA},
    {0x8005F9D6, R_PPC_ADDR16_LO}, {0x8005FA0A, R_PPC_ADDR16_HA}, {0x8005FA12, R_PPC_ADDR16_LO},
    {0x8005FA32, R_PPC_ADDR16_HA}, {0x8005FA3A, R_PPC_ADDR16_LO}, {0x8005FA72, R_PPC_ADDR16_HA},
    {0x8005FA76, R_PPC_ADDR16_LO}, {0x8005FB12, R_PPC_ADDR16_HA}, {0x8005FB16, R_PPC_ADDR16_LO},
    {0x8005FB72, R_PPC_ADDR16_HA}, {0x8005FB7A, R_PPC_ADDR16_LO}, {0x80060982, R_PPC_ADDR16_HA},
    {0x80060986, R_PPC_ADDR16_LO}, {0x80060A22, R_PPC_ADDR16_HA}, {0x80060A26, R_PPC_ADDR16_LO},
    {0x80060AD2, R_PPC_ADDR16_HA}, {0x80060AD6, R_PPC_ADDR16_LO}, {0x80060F3A, R_PPC_ADDR16_HA},
    {0x80060F46, R_PPC_ADDR16_LO}, {0x80060FFA, R_PPC_ADDR16_HA}, {0x80060FFE, R_PPC_ADDR16_LO},
  }
);

PATCH_REFERENCES(
  &daPyMng_c::mCourseInList, //
  {
    {0x8005D656, R_PPC_ADDR16_HA},
    {0x8005D65E, R_PPC_ADDR16_LO},
    {0x8005D662, R_PPC_ADDR16_LO},
    {0x800601E2, R_PPC_ADDR16_HA},
    {0x800601EA, R_PPC_ADDR16_LO},
  }
);

PATCH_REFERENCES(
  &daPyMng_c::m_yoshiFruit, //
  {
    {0x8005FC22, R_PPC_ADDR16_HA},
    {0x8005FC32, R_PPC_ADDR16_LO},
    {0x8005FC52, R_PPC_ADDR16_HA},
    {0x8005FC5A, R_PPC_ADDR16_LO},
  }
);

PATCH_REFERENCES(
  &daPyMng_c::mPlayerEntry, //
  {
    {0x8005D31A, R_PPC_ADDR16_HA}, {0x8005D32E, R_PPC_ADDR16_LO}, {0x8005EEEA, R_PPC_ADDR16_HA},
    {0x8005EEF6, R_PPC_ADDR16_LO}, {0x8005F38A, R_PPC_ADDR16_HA}, {0x8005F392, R_PPC_ADDR16_LO},
    {0x8005FC8A, R_PPC_ADDR16_HA}, {0x8005FC8E, R_PPC_ADDR16_LO}, {0x8005FD32, R_PPC_ADDR16_HA},
    {0x8005FD36, R_PPC_ADDR16_LO}, {0x800605A2, R_PPC_ADDR16_HA}, {0x800605A6, R_PPC_ADDR16_LO},
    {0x800BB96A, R_PPC_ADDR16_HA}, {0x800BB99E, R_PPC_ADDR16_LO}, {0x80101AEE, R_PPC_ADDR16_HA},
    {0x80101AF2, R_PPC_ADDR16_LO}, {0x8013D822, R_PPC_ADDR16_HA}, {0x8013D826, R_PPC_ADDR16_LO},
    {0x8013D826, R_PPC_ADDR16_LO}, {0x80144762, R_PPC_ADDR16_HA}, {0x8014476E, R_PPC_ADDR16_LO},
    {0x80144E0E, R_PPC_ADDR16_HA}, {0x80144E2A, R_PPC_ADDR16_LO}, {0x801586E2, R_PPC_ADDR16_HA},
    {0x8015870A, R_PPC_ADDR16_LO}, {0x8090CE32, R_PPC_ADDR16_HA}, {0x8090CE56, R_PPC_ADDR16_LO},
    {0x8091AC92, R_PPC_ADDR16_HA}, {0x8091ACA6, R_PPC_ADDR16_LO}, {0x8091F786, R_PPC_ADDR16_HA},
    {0x8091F7A2, R_PPC_ADDR16_LO}, {0x8091FE66, R_PPC_ADDR16_HA}, {0x8091FE6E, R_PPC_ADDR16_LO},
    {0x8091FE9E, R_PPC_ADDR16_LO}, {0x8091FEDA, R_PPC_ADDR16_HA}, {0x8091FEF2, R_PPC_ADDR16_LO},
    {0x80924EC6, R_PPC_ADDR16_LO}, {0x8092542A, R_PPC_ADDR16_HA}, {0x8092545A, R_PPC_ADDR16_LO},
    {0x80B6C712, R_PPC_ADDR16_HA}, {0x80B6C722, R_PPC_ADDR16_LO}, {0x80B6C932, R_PPC_ADDR16_HA},
    {0x80B6C93A, R_PPC_ADDR16_LO}, {0x80B6CE52, R_PPC_ADDR16_HA}, {0x80B6CE56, R_PPC_ADDR16_LO},
    {0x80B6CFBE, R_PPC_ADDR16_HA}, {0x80B6CFC6, R_PPC_ADDR16_LO},
  }
);

PATCH_REFERENCES(
  &daPyMng_c::mPlayerType, //
  {
    {0x8001B7E2, R_PPC_ADDR16_HA}, {0x8001B7F2, R_PPC_ADDR16_LO}, {0x8001CD52, R_PPC_ADDR16_HA},
    {0x8001CD5A, R_PPC_ADDR16_LO}, {0x8005D31E, R_PPC_ADDR16_HA}, {0x8005D336, R_PPC_ADDR16_LO},
    {0x8005FBE2, R_PPC_ADDR16_HA}, {0x8005FBEE, R_PPC_ADDR16_LO}, {0x80060116, R_PPC_ADDR16_LO},
    {0x80060202, R_PPC_ADDR16_HA}, {0x8006020A, R_PPC_ADDR16_LO}, {0x8006020E, R_PPC_ADDR16_LO},
    {0x8006052A, R_PPC_ADDR16_HA}, {0x8006053A, R_PPC_ADDR16_LO}, {0x80060636, R_PPC_ADDR16_HA},
    {0x80060642, R_PPC_ADDR16_LO}, {0x8008EF42, R_PPC_ADDR16_HA}, {0x8008EF4E, R_PPC_ADDR16_LO},
    {0x800B1CD6, R_PPC_ADDR16_HA}, {0x800B1CDE, R_PPC_ADDR16_LO}, {0x800B34E6, R_PPC_ADDR16_HA},
    {0x800B34EE, R_PPC_ADDR16_LO}, {0x800B3522, R_PPC_ADDR16_HA}, {0x800B352A, R_PPC_ADDR16_LO},
    {0x800B3566, R_PPC_ADDR16_HA}, {0x800B356E, R_PPC_ADDR16_LO}, {0x800B35E6, R_PPC_ADDR16_HA},
    {0x800B35EE, R_PPC_ADDR16_LO}, {0x800B5346, R_PPC_ADDR16_LO}, {0x800BB182, R_PPC_ADDR16_HA},
    {0x800BB18A, R_PPC_ADDR16_LO}, {0x800BB19E, R_PPC_ADDR16_LO}, {0x800BB95A, R_PPC_ADDR16_HA},
    {0x800BB99A, R_PPC_ADDR16_LO}, {0x800D0C8A, R_PPC_ADDR16_HA}, {0x800D0C9A, R_PPC_ADDR16_LO},
    {0x800E17B6, R_PPC_ADDR16_HA}, {0x800E17CA, R_PPC_ADDR16_LO}, {0x800E196A, R_PPC_ADDR16_HA},
    {0x800E1982, R_PPC_ADDR16_LO}, {0x800E2556, R_PPC_ADDR16_HA}, {0x800E255E, R_PPC_ADDR16_LO},
    {0x801011A2, R_PPC_ADDR16_HA}, {0x801011AA, R_PPC_ADDR16_LO}, {0x801023FE, R_PPC_ADDR16_HA},
    {0x80102406, R_PPC_ADDR16_LO}, {0x8010B74E, R_PPC_ADDR16_HA}, {0x8010B756, R_PPC_ADDR16_LO},
    {0x8010DA36, R_PPC_ADDR16_HA}, {0x8010DA3E, R_PPC_ADDR16_LO}, {0x8010DAE6, R_PPC_ADDR16_HA},
    {0x8010DAEE, R_PPC_ADDR16_LO}, {0x8010DB96, R_PPC_ADDR16_HA}, {0x8010DB9E, R_PPC_ADDR16_LO},
    {0x80138896, R_PPC_ADDR16_HA}, {0x801388A6, R_PPC_ADDR16_LO}, {0x8013D82A, R_PPC_ADDR16_HA},
    {0x8013D83A, R_PPC_ADDR16_LO}, {0x80140FA2, R_PPC_ADDR16_HA}, {0x80140FAE, R_PPC_ADDR16_LO},
    {0x801446F6, R_PPC_ADDR16_HA}, {0x8014470A, R_PPC_ADDR16_LO}, {0x80144DCE, R_PPC_ADDR16_HA},
    {0x80144DDE, R_PPC_ADDR16_LO}, {0x80144E0A, R_PPC_ADDR16_HA}, {0x80144E22, R_PPC_ADDR16_LO},
    {0x8014503A, R_PPC_ADDR16_HA}, {0x80145046, R_PPC_ADDR16_LO}, {0x8076FE66, R_PPC_ADDR16_HA},
    {0x8076FE72, R_PPC_ADDR16_LO}, {0x80771192, R_PPC_ADDR16_HA}, {0x8077119A, R_PPC_ADDR16_LO},
    {0x807714CE, R_PPC_ADDR16_HA}, {0x807714E2, R_PPC_ADDR16_LO}, {0x80777EE6, R_PPC_ADDR16_HA},
    {0x80777EFE, R_PPC_ADDR16_LO}, {0x80788FDA, R_PPC_ADDR16_HA}, {0x80788FE2, R_PPC_ADDR16_LO},
    {0x80788FE6, R_PPC_ADDR16_LO}, {0x80789082, R_PPC_ADDR16_HA}, {0x807890BE, R_PPC_ADDR16_LO},
    {0x8078C2A2, R_PPC_ADDR16_HA}, {0x8078C2AE, R_PPC_ADDR16_LO}, {0x8078C40E, R_PPC_ADDR16_HA},
    {0x8078C416, R_PPC_ADDR16_LO}, {0x8078CCC6, R_PPC_ADDR16_HA}, {0x8078CCCE, R_PPC_ADDR16_LO},
    {0x8078CE3A, R_PPC_ADDR16_HA}, {0x8078CE42, R_PPC_ADDR16_LO}, {0x8079A002, R_PPC_ADDR16_HA},
    {0x8079A00A, R_PPC_ADDR16_LO}, {0x8079A00E, R_PPC_ADDR16_LO}, {0x8079A056, R_PPC_ADDR16_LO},
    {0x807A0BFA, R_PPC_ADDR16_HA}, {0x807A0C02, R_PPC_ADDR16_LO}, {0x807A0C6E, R_PPC_ADDR16_HA},
    {0x807A0C7A, R_PPC_ADDR16_LO}, {0x807A0DFE, R_PPC_ADDR16_LO}, {0x807A0EAE, R_PPC_ADDR16_HA},
    {0x807A0ECA, R_PPC_ADDR16_LO}, {0x807A1EEA, R_PPC_ADDR16_HA}, {0x807A1F02, R_PPC_ADDR16_LO},
    {0x807A53CE, R_PPC_ADDR16_HA}, {0x807A53DE, R_PPC_ADDR16_LO}, {0x807A7FFA, R_PPC_ADDR16_HA},
    {0x807A8006, R_PPC_ADDR16_LO}, {0x807AA146, R_PPC_ADDR16_HA}, {0x807AA14E, R_PPC_ADDR16_LO},
    {0x807AA3F2, R_PPC_ADDR16_HA}, {0x807AA3FA, R_PPC_ADDR16_LO}, {0x807AE142, R_PPC_ADDR16_HA},
    {0x807AE14A, R_PPC_ADDR16_LO}, {0x807AE5D2, R_PPC_ADDR16_HA}, {0x807AE5DA, R_PPC_ADDR16_LO},
    {0x807AFBF2, R_PPC_ADDR16_HA}, {0x807AFC12, R_PPC_ADDR16_LO}, {0x807B00CE, R_PPC_ADDR16_HA},
    {0x807B00DA, R_PPC_ADDR16_LO}, {0x807B01CA, R_PPC_ADDR16_HA}, {0x807B01E2, R_PPC_ADDR16_LO},
    {0x807B070A, R_PPC_ADDR16_HA}, {0x807B0712, R_PPC_ADDR16_LO}, {0x807B072E, R_PPC_ADDR16_HA},
    {0x807B073E, R_PPC_ADDR16_LO}, {0x807B07BA, R_PPC_ADDR16_HA}, {0x807B07CA, R_PPC_ADDR16_LO},
    {0x807B09F2, R_PPC_ADDR16_HA}, {0x807B0A02, R_PPC_ADDR16_LO}, {0x807B13CA, R_PPC_ADDR16_HA},
    {0x807B13D6, R_PPC_ADDR16_LO}, {0x808EB7DA, R_PPC_ADDR16_HA}, {0x808EB7E6, R_PPC_ADDR16_LO},
    {0x80902B4E, R_PPC_ADDR16_HA}, {0x80902B6A, R_PPC_ADDR16_LO}, {0x80903022, R_PPC_ADDR16_HA},
    {0x8090302A, R_PPC_ADDR16_LO}, {0x809093D6, R_PPC_ADDR16_HA}, {0x809093DE, R_PPC_ADDR16_LO},
    {0x8090947E, R_PPC_ADDR16_HA}, {0x80909492, R_PPC_ADDR16_LO}, {0x8090CE36, R_PPC_ADDR16_HA},
    {0x8090CE5A, R_PPC_ADDR16_LO}, {0x809188E2, R_PPC_ADDR16_HA}, {0x809188EA, R_PPC_ADDR16_LO},
    {0x809188FA, R_PPC_ADDR16_LO}, {0x80918C36, R_PPC_ADDR16_HA}, {0x80918C46, R_PPC_ADDR16_LO},
    {0x8091AC96, R_PPC_ADDR16_HA}, {0x8091ACAA, R_PPC_ADDR16_LO}, {0x8091D3F6, R_PPC_ADDR16_LO},
    {0x8091F78A, R_PPC_ADDR16_HA}, {0x8091F7A6, R_PPC_ADDR16_LO}, {0x8091FE72, R_PPC_ADDR16_HA},
    {0x8091FE82, R_PPC_ADDR16_LO}, {0x8091FEA2, R_PPC_ADDR16_LO}, {0x8091FEDE, R_PPC_ADDR16_HA},
    {0x8091FEF6, R_PPC_ADDR16_LO}, {0x80925422, R_PPC_ADDR16_HA}, {0x80925452, R_PPC_ADDR16_LO},
    {0x8092F772, R_PPC_ADDR16_HA}, {0x8092F77A, R_PPC_ADDR16_LO}, {0x8092F87E, R_PPC_ADDR16_HA},
    {0x8092F88E, R_PPC_ADDR16_LO}, {0x8092FAFA, R_PPC_ADDR16_HA}, {0x8092FB0A, R_PPC_ADDR16_LO},
    {0x8092FE02, R_PPC_ADDR16_HA}, {0x8092FE0A, R_PPC_ADDR16_LO}, {0x8092FE12, R_PPC_ADDR16_LO},
    {0x809311E2, R_PPC_ADDR16_HA}, {0x809311EA, R_PPC_ADDR16_LO}, {0x8093352E, R_PPC_ADDR16_HA},
    {0x80933556, R_PPC_ADDR16_LO}, {0x80A2B70A, R_PPC_ADDR16_HA}, {0x80A2B71A, R_PPC_ADDR16_LO},
    {0x80B6BCE6, R_PPC_ADDR16_HA}, {0x80B6BCFA, R_PPC_ADDR16_LO},
  }
);

PATCH_REFERENCES(
  &daPyMng_c::mPlayerMode, //
  {
    {0x8001B7E6, R_PPC_ADDR16_HA}, {0x8001B7FE, R_PPC_ADDR16_LO}, {0x800BB96E, R_PPC_ADDR16_HA},
    {0x800BB9A2, R_PPC_ADDR16_LO}, {0x800E17BA, R_PPC_ADDR16_HA}, {0x800E17CE, R_PPC_ADDR16_LO},
    {0x800E196E, R_PPC_ADDR16_HA}, {0x800E1986, R_PPC_ADDR16_LO}, {0x801446FE, R_PPC_ADDR16_HA},
    {0x8014470E, R_PPC_ADDR16_LO}, {0x80144DD2, R_PPC_ADDR16_HA}, {0x80144DE6, R_PPC_ADDR16_LO},
    {0x80144E12, R_PPC_ADDR16_HA}, {0x80144E36, R_PPC_ADDR16_LO}, {0x807786BA, R_PPC_ADDR16_HA},
    {0x807786CE, R_PPC_ADDR16_LO}, {0x80789056, R_PPC_ADDR16_HA}, {0x8078906E, R_PPC_ADDR16_LO},
    {0x807B01D2, R_PPC_ADDR16_HA}, {0x807B01EA, R_PPC_ADDR16_LO}, {0x807B070E, R_PPC_ADDR16_HA},
    {0x807B0716, R_PPC_ADDR16_LO}, {0x807B07C2, R_PPC_ADDR16_HA}, {0x807B07D2, R_PPC_ADDR16_LO},
    {0x808C59B2, R_PPC_ADDR16_HA}, {0x808C59C2, R_PPC_ADDR16_LO}, {0x808C5C5E, R_PPC_ADDR16_HA},
    {0x808C5C66, R_PPC_ADDR16_LO}, {0x808EB7DE, R_PPC_ADDR16_HA}, {0x808EB7EA, R_PPC_ADDR16_LO},
    {0x80902B4A, R_PPC_ADDR16_HA}, {0x80902B56, R_PPC_ADDR16_LO}, {0x8090CE3A, R_PPC_ADDR16_HA},
    {0x8090CE5E, R_PPC_ADDR16_LO}, {0x80918C3A, R_PPC_ADDR16_HA}, {0x80918C4A, R_PPC_ADDR16_LO},
    {0x8091AC9A, R_PPC_ADDR16_HA}, {0x8091ACAE, R_PPC_ADDR16_LO}, {0x8091F78E, R_PPC_ADDR16_HA},
    {0x8091F7AA, R_PPC_ADDR16_LO}, {0x8091FE5E, R_PPC_ADDR16_HA}, {0x8091FE6A, R_PPC_ADDR16_LO},
    {0x8091FEE2, R_PPC_ADDR16_HA}, {0x8091FEFA, R_PPC_ADDR16_LO}, {0x8092540A, R_PPC_ADDR16_HA},
    {0x8092543A, R_PPC_ADDR16_LO}, {0x8092FAFE, R_PPC_ADDR16_HA}, {0x8092FB0E, R_PPC_ADDR16_LO},
    {0x8093352A, R_PPC_ADDR16_HA}, {0x80933536, R_PPC_ADDR16_LO},
  }
);

PATCH_REFERENCES(
  &daPyMng_c::mCreateItem, //
  {
    {0x8005D326, R_PPC_ADDR16_HA}, {0x8005D342, R_PPC_ADDR16_LO}, {0x8005FBE6, R_PPC_ADDR16_HA},
    {0x8005FBF2, R_PPC_ADDR16_LO}, {0x800BB97A, R_PPC_ADDR16_HA}, {0x800BB9B2, R_PPC_ADDR16_LO},
    {0x800E17C2, R_PPC_ADDR16_HA}, {0x800E17D6, R_PPC_ADDR16_LO}, {0x800E1976, R_PPC_ADDR16_HA},
    {0x800E198E, R_PPC_ADDR16_LO}, {0x801011A6, R_PPC_ADDR16_HA}, {0x801011AE, R_PPC_ADDR16_LO},
    {0x80140FA6, R_PPC_ADDR16_HA}, {0x80140FB6, R_PPC_ADDR16_LO}, {0x80144706, R_PPC_ADDR16_HA},
    {0x80144716, R_PPC_ADDR16_LO}, {0x80144DD6, R_PPC_ADDR16_HA}, {0x80144DEE, R_PPC_ADDR16_LO},
    {0x80144E1A, R_PPC_ADDR16_HA}, {0x80144E3E, R_PPC_ADDR16_LO}, {0x8014503E, R_PPC_ADDR16_HA},
    {0x8014504E, R_PPC_ADDR16_LO}, {0x807786B6, R_PPC_ADDR16_HA}, {0x807786CA, R_PPC_ADDR16_LO},
    {0x8078905E, R_PPC_ADDR16_HA}, {0x80789076, R_PPC_ADDR16_LO}, {0x807B00CA, R_PPC_ADDR16_HA},
    {0x807B00DE, R_PPC_ADDR16_LO}, {0x807B01CE, R_PPC_ADDR16_HA}, {0x807B01E6, R_PPC_ADDR16_LO},
    {0x807B0732, R_PPC_ADDR16_HA}, {0x807B0742, R_PPC_ADDR16_LO}, {0x807B07BE, R_PPC_ADDR16_HA},
    {0x807B07CE, R_PPC_ADDR16_LO}, {0x808C5C9A, R_PPC_ADDR16_HA}, {0x808C5C9E, R_PPC_ADDR16_LO},
    {0x808EF2D6, R_PPC_ADDR16_HA}, {0x808EF2DA, R_PPC_ADDR16_LO}, {0x80903026, R_PPC_ADDR16_HA},
    {0x80903036, R_PPC_ADDR16_LO}, {0x8090947A, R_PPC_ADDR16_HA}, {0x80909486, R_PPC_ADDR16_LO},
    {0x80918C3E, R_PPC_ADDR16_HA}, {0x80918C4E, R_PPC_ADDR16_LO}, {0x8091AC9E, R_PPC_ADDR16_HA},
    {0x8091ACB6, R_PPC_ADDR16_LO}, {0x8091F792, R_PPC_ADDR16_HA}, {0x8091F7AE, R_PPC_ADDR16_LO},
    {0x8091FE7A, R_PPC_ADDR16_HA}, {0x8091FE7E, R_PPC_ADDR16_LO}, {0x8091FEEA, R_PPC_ADDR16_HA},
    {0x8091FF02, R_PPC_ADDR16_LO}, {0x80925242, R_PPC_ADDR16_HA}, {0x8092524E, R_PPC_ADDR16_LO},
    {0x8092525E, R_PPC_ADDR16_LO}, {0x80925416, R_PPC_ADDR16_HA}, {0x80925446, R_PPC_ADDR16_LO},
  }
);

PATCH_REFERENCES(
  &daPyMng_c::mRest, //
  {
    {0x80010822, R_PPC_ADDR16_HA}, {0x80010832, R_PPC_ADDR16_LO}, {0x8001CD56, R_PPC_ADDR16_HA},
    {0x8001CD62, R_PPC_ADDR16_LO}, {0x8006052E, R_PPC_ADDR16_HA}, {0x80060542, R_PPC_ADDR16_LO},
    {0x8006055E, R_PPC_ADDR16_HA}, {0x80060566, R_PPC_ADDR16_LO}, {0x8006063A, R_PPC_ADDR16_HA},
    {0x8006064A, R_PPC_ADDR16_LO}, {0x80060EF2, R_PPC_ADDR16_HA}, {0x80060EFA, R_PPC_ADDR16_LO},
    {0x800B534A, R_PPC_ADDR16_HA}, {0x800B5356, R_PPC_ADDR16_LO}, {0x800BB972, R_PPC_ADDR16_HA},
    {0x800BB9AA, R_PPC_ADDR16_LO}, {0x800E17BE, R_PPC_ADDR16_HA}, {0x800E17D2, R_PPC_ADDR16_LO},
    {0x800E1972, R_PPC_ADDR16_HA}, {0x800E198A, R_PPC_ADDR16_LO}, {0x80102402, R_PPC_ADDR16_HA},
    {0x8010240E, R_PPC_ADDR16_LO}, {0x8010B752, R_PPC_ADDR16_HA}, {0x8010B75E, R_PPC_ADDR16_LO},
    {0x8013889A, R_PPC_ADDR16_HA}, {0x801388AE, R_PPC_ADDR16_LO}, {0x8013D82E, R_PPC_ADDR16_HA},
    {0x8013D83E, R_PPC_ADDR16_LO}, {0x80777EEA, R_PPC_ADDR16_HA}, {0x80777F02, R_PPC_ADDR16_LO},
    {0x807786C2, R_PPC_ADDR16_HA}, {0x807786D2, R_PPC_ADDR16_LO}, {0x80788FDE, R_PPC_ADDR16_HA},
    {0x80788FEE, R_PPC_ADDR16_LO}, {0x8078904A, R_PPC_ADDR16_HA}, {0x8078905A, R_PPC_ADDR16_LO},
    {0x8091885A, R_PPC_ADDR16_LO}, {0x8091D3FA, R_PPC_ADDR16_HA}, {0x8091D402, R_PPC_ADDR16_LO},
    {0x8091F796, R_PPC_ADDR16_HA}, {0x8091F7B2, R_PPC_ADDR16_LO}, {0x8091FEE6, R_PPC_ADDR16_HA},
    {0x8091FEFE, R_PPC_ADDR16_LO}, {0x80925412, R_PPC_ADDR16_HA}, {0x80925442, R_PPC_ADDR16_LO},
    {0x8092F776, R_PPC_ADDR16_HA}, {0x8092F782, R_PPC_ADDR16_LO}, {0x8092F882, R_PPC_ADDR16_HA},
    {0x8092F892, R_PPC_ADDR16_LO}, {0x80B6BCEA, R_PPC_ADDR16_HA}, {0x80B6BCFE, R_PPC_ADDR16_LO},
  }
);

PATCH_REFERENCES(
  &daPyMng_c::mCoin, //
  {
    {0x80060206, R_PPC_ADDR16_HA},
    {0x80060216, R_PPC_ADDR16_LO},
    {0x800BB982, R_PPC_ADDR16_HA},
    {0x800BB9B6, R_PPC_ADDR16_LO},
    {0x800E17C6, R_PPC_ADDR16_HA},
    {0x800E17DA, R_PPC_ADDR16_LO},
    {0x800E197A, R_PPC_ADDR16_HA},
    {0x800E1992, R_PPC_ADDR16_LO},
    {0x8078904E, R_PPC_ADDR16_HA},
    {0x8078906A, R_PPC_ADDR16_LO},
    {0x8091F79E, R_PPC_ADDR16_HA},
    {0x8091F7BA, R_PPC_ADDR16_LO},
    {0x8092541A, R_PPC_ADDR16_HA},
    {0x8092544A, R_PPC_ADDR16_LO},
    {0x80A2B70E, R_PPC_ADDR16_HA},
    {0x80A2B722, R_PPC_ADDR16_LO},
  }
);
