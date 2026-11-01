// d_s_boot.cpp
// NSMBW .text: 0x8015BA70 - 0x8015F270

#include "d_s_boot.h"

#include "d_a_player_manager.h"
#include "d_debug_option.h"
#include "d_demo_info.h"
#include "d_info.h"
#include "d_mj2d_game.h"
#include "d_remocon_mng.h"
#include "d_s_restart_crsin.h"
#include "d_s_stage.h"
#include <algorithm>
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
void dScBoot_c::executeState_ProcEnd() {
    if (dDebugOpt::autoboot::title_demo != 0xFF &&
        dDebugOpt::autoboot::title_demo < dDemoInfo::c_titleDemoStageCnt) {
        dScStage_c::m_titleCount = +dDebugOpt::autoboot::title_demo - 1;
        return dScRestartCrsin_c::startTitle(1, false);
    }

    if (dDebugOpt::autoboot::hint_movie_demo != 0xFF &&
        dDebugOpt::autoboot::hint_movie_demo < dDemoInfo::c_otehonInfoCnt) {
        dScStage_c::m_titleCount = +dDebugOpt::autoboot::hint_movie_demo - 1;
        return dScRestartCrsin_c::reStartPeachCastle();
    }

    if (dDebugOpt::autoboot::player_index) {
        dRemoconMng_c::m_instance->setFirstConnect(dDebugOpt::autoboot::player_index);
    }

    bool mUsedIndex[CHARACTER_COUNT] = {};
    for (int ply = 0;
         ply <
         std::min(
             dDebugOpt::autoboot::player_index + dDebugOpt::autoboot::num_players, PLAYER_COUNT
         );
         ply++) {
        if (ply < dDebugOpt::autoboot::player_index) {
            dInfo_c::m_instance->setPlyConnectStage(ply, dInfo_c::PlyConnectStage_e::OFF);
            continue;
        }
        PLAYER_TYPE_e type = dDebugOpt::autoboot::player_type_order[ply];
        if (+type >= std::size(mUsedIndex) || mUsedIndex[+type]) {
            type = *std::find_if(
                std::begin(dMj2dGame_c::scDefaultPlayerTypes),
                std::end(dMj2dGame_c::scDefaultPlayerTypes), [&mUsedIndex](PLAYER_TYPE_e type) {
                    return !mUsedIndex[+type];
                }
            );
        }
        mUsedIndex[+type]            = true;

        daPyMng_c::mPlayerType[ply]  = type;
        daPyMng_c::mPlayerEntry[ply] = 1;
        daPyMng_c::mPlayerMode[type] = dDebugOpt::autoboot::player_mode;
        dInfo_c::m_instance->setPlyConnectStage(ply, dInfo_c::PlyConnectStage_e::ENTER);
        if (dDebugOpt::autoboot::in_star) {
            daPyMng_c::mCreateItem[type] |= PLAYER_CREATE_ITEM_e::STAR_POWER;
        }
        if (dDebugOpt::autoboot::on_yoshi) {
            daPyMng_c::mCreateItem[type] |= PLAYER_CREATE_ITEM_e::YOSHI;
        }
    }

    if (dDebugOpt::autoboot::staffroll) {
        dInfo_c::m_instance->startStaffCredit();
        return;
    }

    if (dDebugOpt::autoboot::movie != 0xFF) {
        dScene_c::setNextScene(dProf::MOVIE, dDebugOpt::autoboot::movie, false);
        return;
    }

    if (dDebugOpt::autoboot::world != WORLD_e::COUNT && dDebugOpt::autoboot::area) {
        __extension__ dInfo_c::m_instance->startGame(
            dInfo_c::StartGameInfo_s{
                .demoTime   = 0,
                .otehonType = {},
                .nextGotoNo = dDebugOpt::autoboot::entrance,
                .courseNo   = dDebugOpt::autoboot::area,
                .isDemo     = false,
                .demoType   = dInfo_c::DemoType_e::NONE,
                .stage1     = {dDebugOpt::autoboot::world, dDebugOpt::autoboot::stage},
                .stage2     = {dDebugOpt::autoboot::world, dDebugOpt::autoboot::stage},
            }
        );
        return;
    }

    return dScRestartCrsin_c::startTitle(0, false);
}
