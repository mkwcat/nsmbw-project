// d_s_multi.cpp
// NSMBW   d_bases.text:  0x8091A2F0 - 0x8091BA50

#include "d_bases/d_s_multi.h"
#include "d_bases/d_MultiCourseSelect.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_game_common.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"

[[nsmbw(0x8091AC10)]]
void dScMulti_c::executeState_SelectCourse()
{
    if (mpCourseSelect->mExitWindowActive == false) {
        if (mpCourseSelect->mBeginCourse) {
            u8 worldNum = 0;
            u8 levelNum = 0;
            mpCourseSelect->getContentCourseNo(
              &worldNum, &levelNum, mpCourseSelect->mCurrButton
            );

            // Prepare the course
            dInfo_c::StartGameInfo_s startInfo;
            startInfo.demoType = dInfo_c::DemoType_e::NONE;
            startInfo.isDemo = false;
            startInfo.courseNo = 0;
            startInfo.nextGotoNo = 0xFF;
            startInfo.stage1 = {static_cast<WORLD_e>(worldNum), static_cast<STAGE_e>(levelNum)};
            startInfo.stage2 = startInfo.stage1;

            // Setup active players
            for (int i = 0; i < PLAYER_COUNT; i++) {
                bool isActive = dGameCom::PlayerEnterCheck(i);
                if (isActive) {
                    PLAYER_TYPE_e type = daPyMng_c::mPlayerType[i];
                    daPyMng_c::mPlayerEntry[i] = true;
                    daPyMng_c::mPlayerMode[type] = PLAYER_MODE_e::NONE;
                    daPyMng_c::mCreateItem[type] = PLAYER_CREATE_ITEM_e::NONE;
                } else {
                    daPyMng_c::mPlayerEntry[i] = false;
                }
            }

            dInfo_c::m_instance->startGame(startInfo);
        }
    } else {
        m_D4 = 0;
        mStateMgr.changeState(StateID_ReturnTitleFinalConfirm);
    }
}