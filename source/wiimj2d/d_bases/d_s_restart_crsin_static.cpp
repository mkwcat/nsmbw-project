// d_s_restart_crsin_static.cpp
// NSMBW .text: 0x801018E0 - 0x80101A50

#include "d_bases/d_s_crsin.h"

#include "d_bases/d_s_stage.h"
#include "d_profile/d_profile.h"
#include "d_project/d_demo_info.h"
#include "d_s_restart_crsin.h"
#include "d_system/d_fader.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"
#include "framework/f_feature.h"
#include "machine/m_dvd.h"

[[nsmbw(0x80374060)]]
dInfo_c::StartGameInfo_s dScRestartCrsin_c::m_startGameInfo;

[[nsmbw(0x801018E0)]]
void dScRestartCrsin_c::startTitle(u8 isDemo, bool param2)
{
    m_startGameInfo.courseNo = 0;
    m_startGameInfo.nextGotoNo = -1;

    if (fFeat::autoboot_title_demo) {
        dScStage_c::m_titleCount = (dScStage_c::m_titleCount + 1) % dDemoInfo::c_titleDemoStageCnt;
        const dInfo_c::StageNo_s& stage = dDemoInfo::c_titleDemoStage[dScStage_c::m_titleCount];
        m_startGameInfo.isDemo = true;
        m_startGameInfo.stage1 = stage;
        m_startGameInfo.stage2 = stage;
        m_startGameInfo.demoType = dInfo_c::DemoType_e::TITLE_REPLAY;
    } else if (isDemo) {
        const dInfo_c::StageNo_s& stage =
          dDemoInfo::c_titleDemoStage[dScStage_c::m_titleRandomTable[dScStage_c::m_titleCount]];
        m_startGameInfo.isDemo = true;
        m_startGameInfo.stage1 = stage;
        m_startGameInfo.stage2 = stage;
        m_startGameInfo.demoType = dInfo_c::DemoType_e::TITLE_REPLAY;
    } else {
        m_startGameInfo.isDemo = false;
        m_startGameInfo.stage1 = {WORLD_e::WORLD_1, STAGE_e::TITLE};
        m_startGameInfo.stage2 = {WORLD_e::WORLD_1, STAGE_e::TITLE};
        m_startGameInfo.demoType = dInfo_c::DemoType_e::TITLE;
    }

    dFader_c::setFader(dFader_c::fader_type_e::FADE);
    dScCrsin_c::m_isDispOff = true;
    mDvd::setOverlayRes(false);
    dScene_c::setNextScene(dProf::RESTART_CRSIN, param2, param2);
}

[[nsmbw(0x801019D0)]]
void dScRestartCrsin_c::reStartPeachCastle()
{
    if (fFeat::autoboot_hint_movie_demo) {
        dScStage_c::m_titleCount = (dScStage_c::m_titleCount + 1) % dDemoInfo::c_otehonInfoCnt;
        const dDemoInfo::OtehonInfo_s& info = dDemoInfo::c_otehonInfo[dScStage_c::m_titleCount];
        m_startGameInfo.isDemo = true;
        m_startGameInfo.stage1 = {
          static_cast<WORLD_e>(info.worldNo), static_cast<STAGE_e>(info.stageNo)
        };
        m_startGameInfo.stage2 = m_startGameInfo.stage1;
        m_startGameInfo.demoType = dInfo_c::DemoType_e::HINT_MOVIE;
        m_startGameInfo.demoTime = static_cast<u32>(info.otehonTime);
        m_startGameInfo.otehonType = static_cast<dInfo_c::OtehonType_e>(info.otehonType);
        m_startGameInfo.courseNo = static_cast<u8>(info.courseNo);
        m_startGameInfo.nextGotoNo = static_cast<u8>(info.nextGotoNo);

        dFader_c::setFader(dFader_c::fader_type_e::CIRCLE);
        dScCrsin_c::m_isDispOff = true;
        dScene_c::setNextScene(dProf::RESTART_CRSIN, false, false);
        return;
    }

    m_startGameInfo.demoType = dInfo_c::DemoType_e::NONE;
    m_startGameInfo.isDemo = false;
    m_startGameInfo.stage1 = {WORLD_e::WORLD_1, STAGE_e::PEACH_CASTLE};
    m_startGameInfo.stage2 = m_startGameInfo.stage1;
    m_startGameInfo.courseNo = 0;
    m_startGameInfo.nextGotoNo = -1;

    dFader_c::setFader(dFader_c::fader_type_e::CIRCLE);
    dScCrsin_c::m_isDispOff = true;
    dScStage_c::m_exitMode = dScStage_c::ExitMode_e(2);
    mDvd::setOverlayRes(dInfo_c::isPipeRandomizer());
    dScene_c::setNextScene(dProf::RESTART_CRSIN, false, false);
}
