// d_s_world_map_static.cpp
// NSMBW .text: 0x80102770 - 0x80102DB0

#include "d_s_world_map.h"

#include "d_bases/d_s_stage.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_save_manager.h"
#include "d_system/d_wm_lib.h"

[[nsmbw_data(0x8042A52D)]]
WORLD_e dScWMap_c::m_WorldNo;

[[nsmbw_data(0x8042A52E)]]
u8 dScWMap_c::m_SceneNo;

[[nsmbw_data(0x80429355)]]
WORLD_e dScWMap_c::m_PrevWorldNo;

[[nsmbw_data(0x80429356)]]
u8 dScWMap_c::m_PrevSceneNo;

[[nsmbw_data(0x8042A538)]]
bool dScWMap_c::m_GameOver;

/* @unofficial */
[[nsmbw(0x801027A0)]]
void dScWMap_c::setNextWorldScene(u8 world, u8 node, u8);

void dScWMap_c::returnToWorldScene() {
    if (dScStage_c::m_exitMode == dScStage_c::Exit_e::CLEAR) {
        m_PrevWorldNo = dInfo_c::m_startGameInfo.stage1.world;
        m_PrevSceneNo = dInfo_c::m_startGameInfo.stage1.getWorldSceneNo();
    }

    return setNextWorldScene(static_cast<u8>(m_PrevWorldNo), m_PrevSceneNo);
}

/* @unofficial */
[[nsmbw(0x80102B70)]]
u32 dScWMap_c::AssembleBootParam(WORLD_e, u32, int);

[[nsmbw(0x80102B50)]]
u32 dScWMap_c::CreateBootParam() {
    dInfo_c* info = dInfo_c::m_instance;
    return AssembleBootParam(info->mWorld, info->mWmSceneNo, 5);
}

[[nsmbw(0x80102B90)]]
void dScWMap_c::initLoadGame() {
    dMj2dGame_c* save = dSaveMng_c::m_instance->getSaveGame(-1);
    dInfo_c*     info = dInfo_c::m_instance;

    info->mWorld      = static_cast<WORLD_e>(save->mCurrentWorld);
    info->mWmSceneNo  = save->mCurrentSubWorld;
    info->mWmNode     = save->mCurrentPathNode;
    info->m0x048      = -1;
    info->SetIbaraNow(4, static_cast<dInfo_c::IbaraMode_e>(save->getIbaraNow()));
    info->SetIbaraOld(4, static_cast<dInfo_c::IbaraMode_e>(save->getIbaraNow()));
    info->mSwitchOn = save->mSwitchOn;

    for (int w = 0; w < WORLD_COUNT; w++) {
        for (int e = 0; e < AMBUSH_ENEMY_COUNT; e++) {
            info->SetWorldMapEnemy(
                w, e,
                {save->getCSEnemySceneNo(static_cast<WORLD_e>(w), e),
                 save->getCSEnemyPosIndex(static_cast<WORLD_e>(w), e),
                 save->getCSEnemyWalkDir(static_cast<WORLD_e>(w), e),
                 save->getCSEnemyRevivalCnt(static_cast<WORLD_e>(w), e)}
            );
            info->mKinopioCourseNo[w]      = save->getKinopioCourseNo(static_cast<WORLD_e>(w));
            info->mKinopioCourseInvalid[w] = info->mKinopioCourseNo[w] == STAGE_e::COUNT;
            info->mStage0x39F[w]           = STAGE_e::COUNT;
        }
    }
    m_GameOver = false;
    dWmLib::ClearKinopioChukan();
}
