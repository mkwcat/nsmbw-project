// d_score_mng.cpp
// NSMBW .text: 0x800E2070 - 0x800E2670

#include "d_score_mng.h"

#include "d_bases/d_MiniGameCannon.h"
#include "d_bases/d_s_stage.h"
#include "d_static/d_a_player_manager.h"
#include "d_static/d_game_common.h"

[[nsmbw_data(0x8042A330)]]
dScoreMng_c* dScoreMng_c::m_instance;

[[nsmbw(0x800E2500)]]
void dScoreMng_c::MiniGameScoreSet(mVec3_c& vec, u32 score, int playerNo)
{
    dGameCom::CreateSmallScore(vec, score + 16, playerNo, false);
    if (dMiniGameCannon_c* mg = dScStage_c::getMiniGameCannon()) {
        mg->mNumWon[static_cast<int>(daPyMng_c::mPlayerType[playerNo])] += score + 1;
    }
}
