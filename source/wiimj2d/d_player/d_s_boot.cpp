// d_s_boot.cpp
// NSMBW .text: 0x8015BA70 - 0x8015F270

#include "d_s_boot.h"

#include "d_bases/d_s_restart_crsin.h"
#include "d_bases/d_s_stage.h"
#include "d_project/d_demo_info.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_remocon_mng.h"
#include "framework/f_feature.h"
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
    if (fFeat::autoboot_title_demo > 0 &&
        fFeat::autoboot_title_demo <= dDemoInfo::c_titleDemoStageCnt) {
        dScStage_c::m_titleCount = fFeat::autoboot_title_demo - 2;
        return dScRestartCrsin_c::startTitle(1, false);
    }

    if (fFeat::autoboot_hint_movie_demo > 0 &&
        fFeat::autoboot_hint_movie_demo <= dDemoInfo::c_otehonInfoCnt) {
        dScStage_c::m_titleCount = fFeat::autoboot_hint_movie_demo - 2;
        return dScRestartCrsin_c::reStartPeachCastle();
    }

    if (fFeat::autoboot_player_index) {
        dRemoconMng_c::m_instance->setFirstConnect(fFeat::autoboot_player_index);
    }

    bool mUsedIndex[CHARACTER_COUNT] = {};
    for (int ply = 0;
         ply < std::min(fFeat::autoboot_player_index + fFeat::autoboot_player_count, PLAYER_COUNT);
         ply++) {
        if (ply < fFeat::autoboot_player_index) {
            dInfo_c::m_instance->setPlyConnectStage(ply, dInfo_c::PlyConnectStage_e::OFF);
            continue;
        }
        u8            abType = fFeat::autoboot_player_type_order[ply];
        PLAYER_TYPE_e type;
        if (abType >= std::size(mUsedIndex) || mUsedIndex[abType]) {
            type = *std::find_if(
                std::begin(dMj2dGame_c::scDefaultPlayerTypes),
                std::end(dMj2dGame_c::scDefaultPlayerTypes), [&mUsedIndex](PLAYER_TYPE_e type) {
                    return !mUsedIndex[+type];
                }
            );
        } else {
            type = static_cast<PLAYER_TYPE_e>(abType);
        }
        mUsedIndex[+type]            = true;

        daPyMng_c::mPlayerType[ply]  = type;
        daPyMng_c::mPlayerEntry[ply] = 1;
        daPyMng_c::mPlayerMode[type] = static_cast<PLAYER_MODE_e>(fFeat::autoboot_powerup);
        dInfo_c::m_instance->setPlyConnectStage(ply, dInfo_c::PlyConnectStage_e::ENTER);
        if (fFeat::autoboot_in_star) {
            daPyMng_c::mCreateItem[type] |= PLAYER_CREATE_ITEM_e::STAR_POWER;
        }
        if (fFeat::autoboot_on_yoshi) {
            daPyMng_c::mCreateItem[type] |= PLAYER_CREATE_ITEM_e::YOSHI;
        }
    }

    if (fFeat::autoboot_staffroll) {
        dInfo_c::m_instance->startStaffCredit();
        return;
    }

    if (fFeat::autoboot_movie) {
        dScene_c::setNextScene(dProf::MOVIE, fFeat::autoboot_movie, false);
        return;
    }

    if (!!fFeat::autoboot_world && fFeat::autoboot_course) {
        __extension__ dInfo_c::m_instance->startGame(
            dInfo_c::StartGameInfo_s{
                .demoTime   = 0,
                .otehonType = {},
                .nextGotoNo = static_cast<u8>(fFeat::autoboot_next_goto - 1),
                .courseNo   = static_cast<u8>((fFeat::autoboot_course ?: 1) - 1),
                .isDemo     = false,
                .demoType   = dInfo_c::DemoType_e::NONE,
                .stage1 =
                    {static_cast<WORLD_e>(fFeat::autoboot_world - 1),
                     static_cast<STAGE_e>(fFeat::autoboot_stage - 1)},
                .stage2 = {
                    static_cast<WORLD_e>(fFeat::autoboot_world - 1),
                    static_cast<STAGE_e>(fFeat::autoboot_stage - 1)
                },
            }
        );
        return;
    }

    return dScRestartCrsin_c::startTitle(0, false);
}
