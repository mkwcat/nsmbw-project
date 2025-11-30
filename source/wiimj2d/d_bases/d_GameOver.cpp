// d_GameOver.cpp
// NSMBW d_bases.text: 0x80788510 - 0x80789810

#include "d_GameOver.h"

#include "d_system/d_a_player_manager.h"
#include "d_system/d_game_common.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_save_manager.h"
#include "d_system/d_wm_lib.h"

[[address(0x80788F10)]]
void dGameOver_c::finalizeState_ExitAnimeEndWait()
{
    dMj2dGame_c *save = dSaveMng_c::m_instance->getSaveGame();
    dInfo_c *info = dInfo_c::m_instance;

    // Back up some stuff since dSaveMng_c::initLoadGame() overwrites it
    s8 backup_continues[PLAYER_COUNT];
    u8 backup_deathCounts[WORLD_COUNT][STAGE_COUNT];
    u8 backup_switchDeathCount; // W3-4 with the red switch on

    for (int i = 0; i < PLAYER_COUNT; i++) {
        backup_continues[i] = save->getContinue(i);
    }

    for (int world = 0; world < WORLD_COUNT; world++) {
        for (int level = 0; level < STAGE_COUNT; level++) {
            backup_deathCounts[world][level] = save->getDeathCount((WORLD_e)world, (STAGE_e)level, false);
        }
    }
    backup_switchDeathCount = save->getDeathCount(WORLD_e::WORLD_3, STAGE_e::STAGE_4, true);

    u32 backup_playerType[PLAYER_COUNT];
    u32 backup_playerRest[PLAYER_COUNT];
    u32 backup_score;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        backup_playerType[i] = daPyMng_c::mPlayerType[i];
        backup_playerRest[i] = daPyMng_c::mRest[daPyMng_c::mPlayerType[i]];
    }
    backup_score = daPyMng_c::mScore;

    dGameCom::initGame();
    dSaveMng_c::m_instance->initLoadGame(dSaveMng_c::m_instance->mData.mHeader.getSelectFileNo());

    for (int i = 0; i < STOCK_ITEM_COUNT; i++) {
        info->clsStockItem(i);
    }

    // Now restore everything
    for (int i = 0; i < PLAYER_COUNT; i++) {
        daPyMng_c::mPlayerType[i] = (PLAYER_TYPE_e)backup_playerType[i];
        daPyMng_c::mRest[daPyMng_c::mPlayerType[i]] = backup_playerRest[i];
        daPyMng_c::mCoin[daPyMng_c::mPlayerType[i]] = 0;
        daPyMng_c::mPlayerMode[daPyMng_c::mPlayerType[i]] = PLAYER_MODE_e::NONE;
        daPyMng_c::mCreateItem[daPyMng_c::mPlayerType[i]] = PLAYER_CREATE_ITEM_e::NONE;
    }
    daPyMng_c::mScore = backup_score;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        save->setContinue(i, backup_continues[i]);
    }

    for (int world = 0; world < WORLD_COUNT; world++) {
        for (int level = 0; level < STAGE_COUNT; level++) {
            save->setDeathCount((WORLD_e)world, (STAGE_e)level, false, backup_deathCounts[world][level]);
        }
    }
    save->setDeathCount(WORLD_e::WORLD_3, STAGE_e::STAGE_4, true, backup_switchDeathCount);

    dWmLib::procCourseGameOver(true);
}