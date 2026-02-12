// d_next.cpp
// NSMBW .text: 0x800CFCE0 - 0x800D03C0

#include "d_next.h"

#include "d_bases/d_s_crsin.h"
#include "d_bases/d_s_stage.h"
#include "d_project/d_nextgoto_list.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_actor.h"
#include "d_system/d_fader.h"
#include "d_system/d_game_common.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_save_manager.h"
#include <bit>
#include <cassert>

[[nsmbw_data(0x8042A2A0)]]
dNext_c* dNext_c::m_instance;

[[nsmbw(0x800D01F0)]]
void dNext_c::changeScene();

void dNext_c::changeSceneRndizer(int index)
{
    dMj2dGame_c::PIPE_RANDOMIZER_MODE_e mode =
      dSaveMng_c::m_instance->getSaveGame()->getPipeRandomizerMode();

    int nextIndex = -1;
    if (mode == dMj2dGame_c::PIPE_RANDOMIZER_MODE_e::PER_EXIT) {
        nextIndex = dGameCom::rndInt(dNextGotoList_c::ms_instance.size() - 1);
        if (nextIndex >= index) {
            nextIndex++;
        }
    } else {
        nextIndex = dNextGotoList_c::ms_lookup[index];
    }
    assert(nextIndex != -1);

    dActor_c::mExecStopReq |= 0xF;

    if (dScStage_c::m_gameMode == dScStage_c::GAME_MODE_e(4)) {
        dFader_c::setFader(dFader_c::fader_type_e::FADE);
    } else {
        dFader_c::setFader(m_faderType);
    }

    dScCrsin_c::m_isDispOff = true;

    dScStage_c::m_exitMode = dScStage_c::ExitMode_e::CARRY_OVER_RNDIZER;

    const dNextGotoList_c::Entry_s& entry = dNextGotoList_c::ms_instance[nextIndex];
    return dInfo_c::m_instance->startGame({
      .demoTime = dInfo_c::m_startGameInfo.demoTime,
      .otehonType = dInfo_c::m_startGameInfo.otehonType,
      .nextGotoNo = static_cast<u8>(entry.nextgoto),
      .courseNo = static_cast<u8>(entry.course),
      .isDemo = dInfo_c::m_startGameInfo.isDemo,
      .demoType = dInfo_c::m_startGameInfo.demoType,
      .stage1 = {static_cast<WORLD_e>(entry.world), static_cast<STAGE_e>(entry.stage)},
      .stage2 = {static_cast<WORLD_e>(entry.world), static_cast<STAGE_e>(entry.stage)},
    });
}

[[nsmbw(0x800D0360)]]
void dNext_c::execute()
{
    if (dScStage_c::m_isCourseOut || !m_exitReq || !m_isSimpleChange || m_isChangeScene) {
        return;
    }
    if (daPyMng_c::mNum > 1 && m_timer != 0) {
        m_timer--;
        return;
    }
    if (dInfo_c::isPipeRandomizer()) {
        u32 check = std::bit_cast<u32>(dNextGotoList_c::Entry_s{
          .world = static_cast<u32>(dScStage_c::m_instance->mWorld),
          .stage = static_cast<u32>(dScStage_c::m_instance->mStage),
          .course = static_cast<u32>(dScStage_c::m_instance->mCourse),
          .nextgoto = static_cast<u32>(m_nextGoto.num),
          .group_start = 0,
          .group_end = 0,
        });
        for (const auto& entry : dNextGotoList_c::ms_instance) {
            dNextGotoList_c::Entry_s fixed = entry;
            fixed.group_start = fixed.group_end = 0;
            if (std::bit_cast<u32>(fixed) == check) {
                return changeSceneRndizer(&entry - dNextGotoList_c::ms_instance.begin());
            }
        }
    }
    return changeScene();
}
