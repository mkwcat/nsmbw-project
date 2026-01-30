// d_s_boot.cpp
// NSMBW .text: 0x8015BA70 - 0x8015F270

#include "d_s_boot.h"

#include "d_bases/d_s_restart_crsin.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_info.h"
#include "framework/f_feature.h"
#include <egg/core/eggHeap.h>

[[nsmbw_data(0x804296E8)]]
extern constinit const dBaseProfile_s g_profile_BOOT{};

[[nsmbw(0x8015BA70)]]
fBase_c* dScBoot_c_classInit();

[[nsmbw_data(0x8042A620)]]
dScBoot_c* dScBoot_c::m_instance;

[[nsmbw(0x8015D010)]]
void dScBoot_c::executeState_WiiStrapFadeOut();

[[nsmbw(0x8015D850)]]
void dScBoot_c::executeState_ProcEnd()
{
    switch (fFeat::autoboot_mode) {
    case fFeat::AUTOBOOT_MODE_e::DISABLED:
        return dScRestartCrsin_c::startTitle(0, false);

    case fFeat::AUTOBOOT_MODE_e::MOVIE:
        dScene_c::setNextScene(dProf::MOVIE, fFeat::autoboot_movie, false);
        return;

    case fFeat::AUTOBOOT_MODE_e::STAFFROLL:
    case fFeat::AUTOBOOT_MODE_e::COURSE:
        for (int ply = 0; ply < fFeat::autoboot_player_count; ply++) {
            daPyMng_c::mPlayerType[ply] = dMj2dGame_c::scDefaultPlayerTypes[ply];
            daPyMng_c::mPlayerEntry[ply] = 1;
            daPyMng_c::mPlayerMode[ply] = static_cast<PLAYER_MODE_e>(fFeat::autoboot_powerup);
            dInfo_c::m_instance->setPlyConnectStage(ply, dInfo_c::PlyConnectStage_e::ENTER);
        }
        if (fFeat::autoboot_mode == fFeat::AUTOBOOT_MODE_e::COURSE) {
            dInfo_c::m_instance->startGame(
              dInfo_c::StartGameInfo_s{
                .demoTime = 0,
                .demoType = 0,
                .gotoID = fFeat::autoboot_next_goto,
                .courseID = fFeat::autoboot_course - 1,
                .isDemo = false,
                .screenType = dInfo_c::ScreenType_e::NORMAL,
                .world1 = static_cast<WORLD_e>(fFeat::autoboot_world - 1),
                .stage1 = static_cast<STAGE_e>(fFeat::autoboot_stage - 1),
                .world2 = static_cast<WORLD_e>(fFeat::autoboot_world - 1),
                .stage2 = static_cast<STAGE_e>(fFeat::autoboot_stage - 1),
              }
            );
            return;
        } else if (fFeat::autoboot_mode == fFeat::AUTOBOOT_MODE_e::STAFFROLL) {
            dInfo_c::m_instance->startStaffCredit();
        }
        return;
    }
}
