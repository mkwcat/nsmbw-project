// d_game_common.cpp
// NSMBW .text: 0x800B2E70 - 0x800B5930

#include "d_game_common.h"

#include "d_MiniGameCannon.h"
#include "d_SmallScoreManager.h"
#include "d_StaffCreditScore.h"
#include "d_a_player_manager.h"
#include "d_fukidashiManager.h"
#include "d_game_key.h"
#include "d_game_key_core.h"
#include "d_gamerule.h"
#include "d_info.h"
#include "d_lyttextbox.h"
#include "d_mj2d_game.h"
#include "d_s_stage.h"
#include "d_save_manager.h"
#include "d_scene.h"
#include "m_vec.h"
#include "s_Lib.h"
#include <algorithm>
#include <nw4r/lyt/Window.h>
#include <nw4r/ut/Color.h>

namespace dGameCom {

[[nsmbw(0x800B2E70)]]
void initRandomSeed();

[[nsmbw(0x800B2EE0)]]
u32 rndInt(u32 max);

[[nsmbw(0x800B2F00)]]
f32 rnd();

[[nsmbw(0x800B2F10)]]
f32 rndF(f32 max);

[[nsmbw(0x800B30C0)]]
f32 getDispCenterX();

[[nsmbw(0x800B3100)]]
bool checkRectangleOverlap(const mVec3_c&, const mVec3_c&, const mVec3_c&, const mVec3_c&, float);

[[nsmbw(0x800B2FB0)]]
void initGame();

[[nsmbw(0x800B32E0)]]
mVec3_c ScalePosForAspectRatio(const mVec3_c&);

[[nsmbw(0x800B33D0)]]
void getGlbPosToLyt(mVec3_c&);

[[nsmbw(0x800B34D0)]]
void CreateBlueNumber(
    const mVec3_c& pos, int type, int playerNo
) {
    if (playerNo >= PLAYER_COUNT) {
        return;
    }

    dSmallScoreManager_c::m_instance->CreateBlueNumber(
        pos, type, static_cast<int>(daPyMng_c::mPlayerType[playerNo])
    );
}

[[nsmbw(0x800B3510)]]
void CreateRedNumber(
    const mVec3_c& pos, int playerNo
) {
    if (playerNo >= PLAYER_COUNT) {
        return;
    }

    dSmallScoreManager_c::m_instance->CreateRedNumber(
        pos, static_cast<int>(daPyMng_c::mPlayerType[playerNo])
    );
}

[[nsmbw(0x800B3540)]]
void CreateSmallScore(
    const mVec3_c& pos, int type, int playerNo, bool goal
) {
    int color = PLAYER_COUNT;
    if (playerNo != -1) {
        if (playerNo >= PLAYER_COUNT) {
            return;
        }
        color = static_cast<int>(daPyMng_c::mPlayerType[playerNo]);
    }

    if (!goal) {
        dSmallScoreManager_c::m_instance->CreateSmallScore(pos, type, color);
    } else {
        dSmallScoreManager_c::m_instance->CreateGoalScore(pos, type, color);
    }
}

[[nsmbw(0x800B35B0)]]
void CreateSmallAll1up(const mVec3_c&);

[[nsmbw(0x800B35D0)]]
void GoalScoreExecute(
    const mVec3_c& pos, int playerNo
) {
    if (playerNo >= PLAYER_COUNT) {
        playerNo = 0;
    }

    dSmallScoreManager_c::m_instance->GoalScoreExecute(pos, +daPyMng_c::mPlayerType[playerNo]);
}

[[nsmbw(0x800B37E0)]]
void ScalePosForLayoutEffect(const mVec3_c&, bool);

[[nsmbw(0x800B3980)]]
short CalculateTilt(int, float, float);

bool CalculateTiltShoulder(
    short* target_var, short target_value, short increment, int playerNo, short max
) {
    if (playerNo < 0) {
        return sLib::chaseAngle(target_var, target_value, increment);
    }

    dGameKeyCore_c* currentCore = dGameKey_c::m_instance->mpCores[playerNo];
    if (currentCore->isClassic() || currentCore->isDolphin()) {
        short LR        = currentCore->getTiltLR();
        short newTarget = *target_var + LR;
        if (max) {
            newTarget = std::clamp<short>(newTarget, -max, max);
        }
        return sLib::chaseAngle(target_var, newTarget, increment);
    } else {
        return sLib::chaseAngle(target_var, target_value, increment);
    }
}

[[nsmbw(0x800B3600)]]
void showFukidashi(
    int plrNo, int fukidashiAction
) {
    if (dScStage_c::m_gameMode != dScStage_c::GAME_MODE_e::UNKNOWN_0) {
        return;
    }

    dfukidashiManager_c* mng = dfukidashiManager_c::m_instance;
    if (mng == nullptr) {
        return;
    }
    if ((0b01100000000111111000 >> fukidashiAction) & 1) {
        for (int i = 0; i < PLAYER_COUNT; i++) {
            if (mng->getInfo(plrNo)->isDispOn()) {
                return;
            }
        }
    }
    if (fukidashiAction == 1 && dInfo_c::m_instance->isFukidashiHidePropeller(plrNo)) {
        return;
    }
    if (dInfo_c::m_instance->getFukidashiActionPerformed(plrNo, fukidashiAction)) {
        return;
    }

    dfukidashiInfo_c* info = mng->getInfo(plrNo);
    if (!info->isDispOn()) {
        mng->showAction(plrNo, fukidashiAction);
    } else if (info->isAction(fukidashiAction)) {
        info->reSetTimer();
    }
}

[[nsmbw(0x800B3720)]]
void hideFukidashiForLevel(int plrNo, int fukidashiAction, int param3);

[[nsmbw(0x800B3750)]]
void hideFukidashiTemporarily(int plrNo, int fukidashiAction, int param3);

[[nsmbw(0x800B3780)]]
void hideFukidashiForSession(int plrNo, int fukidashiAction);

[[nsmbw(0x800B3B50)]]
bool isGameStop(u32 flag);

[[nsmbw(0x800B3B60)]]
void LayoutDispNumber(const int& value, const int& maxChars, LytTextBox_c* textBox, bool itoaType);

[[nsmbw(0x800B3BE0)]]
void LayoutDispNumberDigit(const int& value, LytTextBox_c* textBox, bool itoaType);

[[nsmbw(0x800B3C50)]]
void WindowPaneColorSet(
    nw4r::lyt::Window* window, int playerNum
) {
    static constinit const nw4r::ut::Color l_PLY_COLOR_0[] = {
        "#32000000", // Mario
        "#00461400", // Luigi
        "#00005A00", // Blue Toad
        "#28280000", // Yellow Toad
        "#32102A00", // Toadette
        "#2F004100", // Purple Toadette
        "#32320000", // Orange Toad
        "#10101000", // Black Toad
    };

    static constinit const nw4r::ut::Color l_PLY_COLOR_2[] = {
        "#E65050FF", // Mario
        "#3CBE32FF", // Luigi
        "#4178FAFF", // Blue Toad
        "#FFFF3CFF", // Yellow Toad
        "#E97EDBFF", // Toadette
        "#C179FFFF", // Purple Toadette
        "#FF8200FF", // Orange Toad
        "#303030FF", // Black Toad
    };

    int index = daPyMng_c::getPlayerColorType(static_cast<PLAYER_TYPE_e>(playerNum));

    nw4r::lyt::Material* windowMaterial = window->GetMaterial(1);

    windowMaterial->SetTevColor(0, l_PLY_COLOR_0[index]);
    windowMaterial->SetTevColor(1, l_PLY_COLOR_2[index]);
}

[[nsmbw(0x800B44D0)]]
void SelectCursorSetup(nw4r::lyt::Picture* pane, int param2, bool param3);

[[nsmbw(0x800B4760)]]
bool PlayerEnterCheck(
    int player
) {
    return dInfo_c::m_instance->getPlyConnectStage(player) == dInfo_c::PlyConnectStage_e::ENTER;
}

[[nsmbw(0x800B4780)]]
void Player1upColor(
    LytTextBox_c* textBox, int player
) {
    static constinit const nw4r::ut::Color l_PLY_COLOR_0[] = {
        "#FFFF32", // Mario
        "#D2FF00", // Luigi
        "#D2F0FF", // Blue Toad
        "#FFFF64", // Yellow Toad
        "#FFBEFF", // Toadette
        "#E7C9FF", // Purple Toadette
        "#FFD85A", // Orange Toad
        "#6B6B6B", // Black Toad
    };

    static constinit const nw4r::ut::Color l_PLY_COLOR_2[] = {
        "#E60000", // Mario
        "#197D0A", // Luigi
        "#1E2DF0", // Blue Toad
        "#FFBE00", // Yellow Toad
        "#D676D6", // Toadette
        "#A472F8", // Purple Toadette
        "#FF8200", // Orange Toad
        "#464646", // Black Toad
    };

    int index = daPyMng_c::getPlayerColorType(static_cast<PLAYER_TYPE_e>(player));

    textBox->SetVtxColor(0, l_PLY_COLOR_0[index]);
    textBox->SetVtxColor(2, l_PLY_COLOR_2[index]);
}

[[nsmbw(0x800B4940)]]
void MiniGameCannonTitle() {
    if (dMiniGameCannon_c* mg = dScStage_c::getMiniGameCannon()) {
        mg->mActive      = true;
        mg->mIsTitleOpen = true;
    }
}

[[nsmbw(0x800B4970)]]
void MiniGameCannonStart() {
    if (dMiniGameCannon_c* mg = dScStage_c::getMiniGameCannon()) {
        mg->mActive       = true;
        mg->mIsWindowOpen = true;
        mg->mCurrentState = false;
    }
}

[[nsmbw(0x800B49A0)]]
void MiniGameCannonResult() {
    if (dMiniGameCannon_c* mg = dScStage_c::getMiniGameCannon()) {
        mg->mActive       = true;
        mg->mIsWindowOpen = true;
        mg->mCurrentState = true;
    }
}

[[nsmbw(0x800B49D0)]]
bool MiniGameCannonEndCheck() {
    if (dMiniGameCannon_c* mg = dScStage_c::getMiniGameCannon()) {
        return mg->mActive;
    }
    return false;
}

[[nsmbw(0x800B4A00)]]
void MiniGameCannonTitleCloseRequest() {
    if (dMiniGameCannon_c* mg = dScStage_c::getMiniGameCannon()) {
        mg->mCloseTitle = true;
    }
}

[[nsmbw(0x800B4A30)]]
void MiniGameCannonOperateCloseRequest() {
    if (dMiniGameCannon_c* mg = dScStage_c::getMiniGameCannon()) {
        mg->mCloseOperate = true;
    }
}

[[nsmbw(0x800B4A60)]]
void MiniGameCannonResultCloseRequest() {
    if (dMiniGameCannon_c* mg = dScStage_c::getMiniGameCannon()) {
        mg->mCloseResult = true;
    }
}

[[nsmbw(0x800B4A90)]]
void MiniGameWireTitle();

[[nsmbw(0x800B4AC0)]]
void MiniGameWireStart();

//[[nsmbw(0x800B4AF0)]]
// void hash_71636FC0_C70BA13D;

[[nsmbw(0x800B4B20)]]
void MiniGameWireResult(const int* param);

[[nsmbw(0x800B4B90)]]
bool MiniGameWireEndCheck();

[[nsmbw(0x800B4BC0)]]
void MiniGameWireTitleCloseRequest();

[[nsmbw(0x800B4BF0)]]
void MiniGameWireOperateCloseRequest();

[[nsmbw(0x800B4C20)]]
void MiniGameWireResultCloseRequest();

[[nsmbw(0x800B4C50)]]
void MiniGameWireTurnOverCloseRequest();

//[[nsmbw(0x800B4C80)]]
// void hash_28043523_E21C82B0;

//[[nsmbw(0x800B4CC0)]]
// void hash_F8207C44_B2544017;

[[nsmbw(0x800B4CF0)]]
void MiniGameWireFacePosEffect(const mVec3_c&);

[[nsmbw(0x800B4DC0)]]
void MiniGameMessageDisp(int param);

[[nsmbw(0x800B4E00)]]
void MiniGameMessageClose();

[[nsmbw(0x800B4E30)]]
bool isNowCourseClear() {
    if (dGameRule_s::current.always_can_exit_course) {
        return true;
    }

    if (dScStage_c::m_miniGame != 0 || dInfo_c::m_startGameInfo.stage1 == STAGE_e::PEACH_CASTLE ||
        dScene_c::m_nowScene != dProf::STAGE ||
        !!(dInfo_c::mGameFlag & dInfo_c::GameFlag_e::MULTI_MODE)) {
        return true;
    }

    dMj2dGame_c* save = dSaveMng_c::m_instance->getSaveGame();
    return save->isCourseDataFlag(
        dInfo_c::m_startGameInfo.stage1.world, dInfo_c::m_startGameInfo.stage1.stage,
        dMj2dGame_c::COURSE_COMPLETION_e::GOAL_MASK
    );
}

[[nsmbw(0x800B5340)]]
bool chkContinue() {
    // Original function is flawed as it indexes in mPlayerType twice (so like
    // mRest[int(mPlayerType[int(mPlayerType[i])])]). It doesn't matter but i think it's kinda
    // interesting.

    for (int rest : daPyMng_c::mRest) {
        if (rest == 0) {
            return true;
        }
    }

    return false;
}

[[nsmbw(0x800B53F0)]]
bool chkCancelButton(
    int player
) {
    return dGameKey_c::m_instance->mpCores[player]->checkMenuCancel();
}

[[nsmbw(0x800B5140)]]
void DispSizeScale(nw4r::math::VEC2&);

[[nsmbw(0x800B51D0)]]
void StaffCreditAddCoin(
    int player
) {
    if (dStaffCreditScore_c* staffCredit = dScStage_c::m_instance->mpStaffCreditScore) {
        int num = staffCredit->mCoinNum[player] + 1;
        if (num > 999) {
            num = 999;
        }
        staffCredit->mCoinNum[player] = num;
    }
}

[[nsmbw(0x800B5450)]]
void setWorldClearFlag();

[[nsmbw(0x800B5500)]]
SCAspectRatio GetAspectRatio();

} // namespace dGameCom
