// d_s_multi.cpp
// NSMBW   d_bases.text:  0x8091A2F0 - 0x8091BA50

#include "d_bases/d_s_multi.h"
#include "d_bases/d_MultiCourseSelect.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_game_common.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"

[[address(0x8091AC10)]]
void dScMulti_c::executeState_SelectCourse()
{
    if (mpCourseSelect->mExitWindowActive == false) {
        if (mpCourseSelect->mBeginCourse) {
            u8 worldNum = 0;
            u8 levelNum = 0;
            mpCourseSelect->getContentCourseNo(&worldNum, &levelNum, mpCourseSelect->mCurrentSelection);

            // Prepare the course
            dInfo_c::StartGameInfo_s startInfo;
            startInfo.screenType = dInfo_c::ScreenType_e::NORMAL;
            startInfo.isDemo = false;
            startInfo.courseID = 0;
            startInfo.gotoID = 0xFF;
            startInfo.world1 = (WORLD_e)worldNum;
            startInfo.world2 = (WORLD_e)worldNum;
            startInfo.stage1 = (STAGE_e)levelNum;
            startInfo.stage2 = (STAGE_e)levelNum;

            // Setup active players
            for (int i = 0; i < PLAYER_COUNT; i++) {
                bool isActive = dGameCom::PlayerEnterCheck(i);
                if (isActive) {
                    int playerType = daPyMng_c::mPlayerType[i];
                    daPyMng_c::mPlayerEntry[i] = true;
                    daPyMng_c::mPlayerMode[playerType] = PLAYER_MODE_e::NONE;
                    daPyMng_c::mCreateItem[playerType] = PLAYER_CREATE_ITEM_e::NONE;
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