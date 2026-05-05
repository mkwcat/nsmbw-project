// d_info.cpp
// NSMBW .text: 0x800BB0E0 - 0x800BBD80
// NSMBW .data: 0x80315E90 - 0x80315EB0
// NSMBW .bss: 0x80359054 - 0x803590F0
// NSMBW .sbss: 0x8042A25C - 0x8042A268

#include "d_info.h"

#include "d_bases/d_s_stage.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_cyuukan.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_save_manager.h"
#include <cstring>

[[nsmbw_data(0x80315E90)]]
dInfo_c::StartGameInfo_s dInfo_c::m_startGameInfo{};

/* 0x80359054 */
dStartInfo_c dInfo_c::m_startInfo;

[[nsmbw_data(0x8042A25C)]]
dInfo_c* dInfo_c::m_instance;

[[nsmbw_data(0x8042A260)]]
dInfo_c::GameFlag_e dInfo_c::mGameFlag;

[[nsmbw(0x800BB0E0)]]
dInfo_c::dInfo_c();

[[nsmbw(0x800BB130)]]
dInfo_c::~dInfo_c();

dInfo_c::dInfo_c(dInfo_c* old)
{
    u8 dInfoOld[dInfo_c::ORIGINAL_SIZE];
    std::memcpy(dInfoOld, static_cast<void*>(old), dInfo_c::ORIGINAL_SIZE);
    operator delete(old);
    std::memcpy(static_cast<void*>(this), dInfoOld, dInfo_c::ORIGINAL_SIZE);
}

EXTERN_SYMBOL(0x80315EA0, "__vt__7dInfo_c");

[[nsmbw(0x800BB180)]]
void dInfo_c::PlayerStateInit()
{
    for (s32 i = 0; i < PLAYER_COUNT; i++) {
        daPyMng_c::mPlayerType[i] = dMj2dGame_c::scDefaultPlayerTypes[i];

        setPlyConnectStage(i, dInfo_c::PlyConnectStage_e::OFF);
    }
}

[[nsmbw(0x800BB1C0)]]
void dInfo_c::CourseSelectInit();

[[nsmbw(0x800BB330)]]
void dInfo_c::addStockItem(int item)
{
    auto* save = dSaveMng_c::m_instance->getSaveGame(-1);
    save->setStockItem(item, save->getStockItem(item) + 1);
}

[[nsmbw(0x800BB380)]]
void dInfo_c::subStockItem(int item)
{
    auto* save = dSaveMng_c::m_instance->getSaveGame(-1);
    save->setStockItem(item, save->getStockItem(item) - 1);
}

[[nsmbw(0x800BB3D0)]]
u8 dInfo_c::getStockItem(int item) const
{
    return dSaveMng_c::m_instance->getSaveGame(-1)->getStockItem(item);
}

[[nsmbw(0x800BB410)]]
void dInfo_c::clsStockItem(int item);

EXTERN_SYMBOL(0x800BB450, "initGame__7dInfo_cFv");

[[nsmbw(0x800BB5B0)]]
void dInfo_c::initMultiMode()
{
    // Reset win counts
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (i < 4)
            mCoinBattleWin[i] = 0;
        else
            mExCoinBattleWin[i - 4] = 0;
    }

    // Reset clear states
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            mCoinCourse[i][j].mClearState = MultiClearState_e::NONE;
            mFreeCourse[i][j].mClearState = MultiClearState_e::NONE;
        }
    }

    // Reset favorited slots
    for (int i = 0; i < 10; i++) {
        mCoinFavorite[i].mWorld = 10;
        mCoinFavorite[i].mLevel = 42;
        mCoinFavorite[i].mClearState = MultiClearState_e::NONE;

        mFreeFavorite[i].mWorld = 10;
        mFreeFavorite[i].mLevel = 42;
        mFreeFavorite[i].mClearState = MultiClearState_e::NONE;
    }
}

EXTERN_SYMBOL(0x800BB7D0, "startGame__7dInfo_cFRCQ27dInfo_c15StartGameInfo_s");

[[nsmbw(0x800BB7D0)]]
void dInfo_c::startGame(const StartGameInfo_s& startGameInfo);

EXTERN_SYMBOL(0x800BB8D0, "startStaffCredit__7dInfo_cFv");

[[nsmbw(0x800BB940)]]
void dInfo_c::initStage()
{
    m_startInfo.mCyuukan.mState = mCyuukan.mState;
    m_startInfo.mCyuukan.mPlayerSetPos = mCyuukan.mPlayerSetPos;
    m_startInfo.mCyuukan.m0x14 = mCyuukan.m0x14;
    m_startInfo.mCyuukan.mWorld = mCyuukan.mWorld;
    m_startInfo.mCyuukan.mStage = mCyuukan.mStage;
    m_startInfo.mCyuukan.mCourse = mCyuukan.mCourse;
    m_startInfo.mCyuukan.mGoto = mCyuukan.mGoto;
    m_startInfo.mCyuukan.mIsKinopioInChukan = mCyuukan.mIsKinopioInChukan;
    for (int i = 0; i < COLLECTION_COIN_COUNT; i++) {
        m_startInfo.mCyuukan.mCollectionCoin[i] = mCyuukan.mCollectionCoin[i];
    }
    m_startInfo.mCyuukan.m0x2C[0] = mCyuukan.m0x2C[0];
    m_startInfo.mCyuukan.m0x2C[1] = mCyuukan.m0x2C[1];
    m_startInfo.mSwitchOn = mSwitchOn;

    for (int ply = 0; ply < PLAYER_COUNT; ply++) {
        PLAYER_TYPE_e type = daPyMng_c::mPlayerType[ply];
        m_startInfo.mPlayerIndex[type] = ply;
        m_startInfo.mPlayerMode[type] = static_cast<PLAYER_MODE_e>(daPyMng_c::mPlayerMode[type]);
        m_startInfo.mIsEntry[type] = daPyMng_c::mPlayerEntry[ply] != 0;
        m_startInfo.mCoin[type] = daPyMng_c::mCoin[type];
        m_startInfo.mRest[type] = daPyMng_c::mRest[type];
        m_startInfo.mCreateItem[type] = daPyMng_c::mCreateItem[type];
    }

    m_startInfo.mScore = daPyMng_c::mScore;

    if (m_startGameInfo.stage1.stage != STAGE_e::STAFFROLL) {
        m0x060 = 0;
    }
    m_zoromeTime = 0;
    m0x068 = 0;
    m0x06C = 0;

    dScStage_c::m_goalType = 0;

    mCyuukan.courseIN();

    if ((m_startGameInfo.stage1.stage < STAGE_e::KINOKO_HOUSE ||
         m_startGameInfo.stage1.stage > STAGE_e::KINOKO_HOUSE_4) &&
        m_startGameInfo.stage1.stage != STAGE_e::PEACH_CASTLE) {
        mCyuukanState = mCyuukan.mState;
    } else {
        mCyuukanState = -1;
    }

    if (mCyuukanState < 0) {
        for (int i = 0; i < COLLECTION_COIN_COUNT; i++) {
            dScStage_c::setCollectionCoin(i, PLAYER_TYPE_e::COUNT);
        }
    } else {
        for (int i = 0; i < COLLECTION_COIN_COUNT; i++) {
            dScStage_c::setCollectionCoin(i, mCyuukan.mCollectionCoin[i]);
        }
    }

    extern u8 UNDEF_8042a458, UNDEF_8042a459;
    extern u8 UNDEF_8042a460, UNDEF_8042a461;

    UNDEF_8042a459 = UNDEF_8042a458;
    UNDEF_8042a461 = UNDEF_8042a460;
}

[[nsmbw(0x800BBBC0)]]
void dInfo_c::SetWorldMapEnemy(int world, int index, const enemy_s& enemy);

[[nsmbw(0x800BBC00)]]
const dInfo_c::enemy_s& dInfo_c::GetWorldMapEnemy(int world, int index);

EXTERN_SYMBOL(0x800BBC20, "SetMapEnemyInfo__7dInfo_cFiiii");

EXTERN_SYMBOL(0x800BBC40, "#0A406FBE");

EXTERN_SYMBOL(0x800BBC60, "GetMapEnemyInfo__7dInfo_cFiiRQ27dInfo_c7enemy_s");

[[nsmbw(0x800BBCA0)]]
void dInfo_c::SetIbaraNow(int i, IbaraMode_e mode);

[[nsmbw(0x800BBCB0)]]
void dInfo_c::SetIbaraOld(int i, IbaraMode_e mode);

[[nsmbw(0x800BBCC0)]]
dInfo_c::IbaraMode_e dInfo_c::GetIbaraNow(int i);

[[nsmbw(0x800BBCD0)]]
dInfo_c::IbaraMode_e dInfo_c::GetIbaraOld(int i);

EXTERN_SYMBOL(0x800BBCE0, "__sinit_\\d_info_cpp");

EXTERN_SYMBOL(0x800BBD60, "__arraydtor$68604");
