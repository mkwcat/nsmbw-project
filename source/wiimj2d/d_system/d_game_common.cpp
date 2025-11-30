// d_game_common.cpp
// NSMBW .text: 0x800B2E70 - 0x800B5930

#include "d_game_common.h"

#include "d_bases/d_MiniGameCannon.h"
#include "d_bases/d_s_stage.h"
#include "d_player/d_SmallScoreManager.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_game_key.h"
#include "d_system/d_game_key_core.h"
#include "d_system/d_info.h"
#include "d_system/d_lyttextbox.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_save_manager.h"
#include "d_system/d_scene.h"
#include "framework/f_feature.h"
#include "machine/m_vec.h"
#include "state/s_Lib.h"
#include <algorithm>
#include <nw4r/lyt/Window.h>
#include <nw4r/ut/Color.h>

namespace dGameCom
{

[[address(0x800B2E70)]]
void initRandomSeed();

[[address(0x800B2EE0)]]
u32 rndInt(u32 max);

[[address(0x800B2F00)]]
f32 rnd();

[[address(0x800B2F10)]]
f32 rndF(f32 max);

[[address(0x800B30C0)]]
f32 getDispCenterX();

[[address(0x800B2FB0)]]
void initGame();

[[address(0x800B32E0)]]
mVec3_c ScalePosForAspectRatio(const mVec3_c&);

[[address(0x800B34D0)]]
void CreateBlueNumber(const mVec3_c& pos, int type, int playerNo)
{
    if (playerNo >= PLAYER_COUNT) {
        return;
    }

    dSmallScoreManager_c::m_instance->CreateBlueNumber(
      pos, type, static_cast<int>(daPyMng_c::mPlayerType[playerNo])
    );
}

[[address(0x800B3510)]]
void CreateRedNumber(const mVec3_c& pos, int playerNo)
{
    if (playerNo >= PLAYER_COUNT) {
        return;
    }

    dSmallScoreManager_c::m_instance->CreateRedNumber(
      pos, static_cast<int>(daPyMng_c::mPlayerType[playerNo])
    );
}

[[address(0x800B3540)]]
void CreateSmallScore(const mVec3_c& pos, int type, int playerNo, bool goal)
{
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

[[address(0x800B35B0)]]
void CreateSmallAll1up(const mVec3_c&);

[[address(0x800B35D0)]]
void GoalScoreExecute(const mVec3_c& pos, int playerNo)
{
    if (playerNo >= PLAYER_COUNT) {
        playerNo = 0;
    }

    dSmallScoreManager_c::m_instance->GoalScoreExecute(
      pos, static_cast<int>(daPyMng_c::mPlayerType[playerNo])
    );
}

[[address(0x800B37E0)]]
void ScalePosForLayoutEffect(const mVec3_c&, bool);

[[address(0x800B3980)]]
short CalculateTilt(int, float, float);

bool CalculateTiltShoulder(
  short* target_var, short target_value, short increment, s8 playerNo, short max
)
{
    if (playerNo < 0) {
        return sLib::chaseAngle(target_var, target_value, increment);
    }

    dGameKeyCore_c* currentCore = dGameKey_c::m_instance->mpCores[playerNo];
    if (currentCore->isClassic() || currentCore->isDolphin()) {
        short LR = currentCore->getTiltLR();
        short newTarget = *target_var + LR;
        if (max) {
            newTarget = std::clamp<short>(newTarget, -max, max);
        }
        return sLib::chaseAngle(target_var, newTarget, increment);
    } else {
        return sLib::chaseAngle(target_var, target_value, increment);
    }
}

[[address(0x800B3600)]]
void FUN_800B3600(int, int) ASM_METHOD(
  // clang-format off
/* 800B3600 800DAB64 */  lwz      r0, UNDEF_8042a4e4@sda21;
/* 800B3604 7C691B78 */  mr       r9, r3;
/* 800B3608 7C852378 */  mr       r5, r4;
/* 800B360C 2C000000 */  cmpwi    r0, 0;
/* 800B3610 4C820020 */  bnelr-;
/* 800B3614 3CC0802F */  lis      r6, UNDEF_802f0df8@ha;
/* 800B3618 80EDAC80 */  lwz      r7, UNDEF_8042a600@sda21;
/* 800B361C 38C60DF8 */  addi     r6, r6, UNDEF_802f0df8@l;
/* 800B3620 7C0620AE */  lbzx     r0, r6, r4;
/* 800B3624 2C000000 */  cmpwi    r0, 0;
/* 800B3628 41820068 */  beq-     UNDEF_800b3690;

                         addi     r11, r7, 0x368;
                         li       r0, PLAYER_COUNT;
                         mtctr    r0;

L_FUN_800B3600_InfoLoopStart:;
                         lbz      r0, 0x19(r11);
                         cmpwi    r0, 0;
                         beq-     L_FUN_800B3600_InfoLoopCond;

                         lwz      r0, 0x0(r11);
                         cmpw     r4, r0;
                         beqlr-;

L_FUN_800B3600_InfoLoopCond:;
                         addi     r11, r11, 0x23C;
                         bdnz+    L_FUN_800B3600_InfoLoopStart;

UNDEF_800b3690:;
                         lis      r8, m_instance__7dInfo_c@ha;
                         lwz      r8, m_instance__7dInfo_c@l(r8);
/* 800B3690 2C040001 */  cmpwi    r4, 1;
/* 800B3698 40820014 */  bne-     UNDEF_800b36ac;

/* 800B369C 7CC81A14 */  add      r6, r8, r3;
                         cmpwi    r3, 4;
                         blt-     L_FUN_800B3600_0xB56_NoAdjust;
                         addi     r6, r6, ADJUST_dInfo_c_mEx0xB56;
L_FUN_800B3600_0xB56_NoAdjust:;
/* 800B36A0 88060B56 */  lbz      r0, 0xB56(r6);
/* 800B36A4 2C000000 */  cmpwi    r0, 0;
/* 800B36A8 4C820020 */  bnelr-;

UNDEF_800b36ac:;
/* 800B36AC 2C070000 */  cmpwi    r7, 0;
/* 800B36B0 4D820020 */  beqlr-;
/* 800B36B4 1C030016 */  mulli    r0, r3, 22;
/* 800B36B8 7C080214 */  add      r0, r8, r0;
/* 800B36BC 7CC02214 */  add      r6, r0, r4;
                         cmpwi    r3, 4;
                         blt-     L_FUN_800B3600_0xAFE_NoAdjust;
                         addi     r6, r6, ADJUST_dInfo_c_mEx0xAFE;
L_FUN_800B3600_0xAFE_NoAdjust:;
/* 800B36C0 88060AFE */  lbz      r0, 0xAFE(r6);
/* 800B36C4 2C000000 */  cmpwi    r0, 0;
/* 800B36C8 4C820020 */  bnelr-;
/* 800B36CC 1C03023C */  mulli    r0, r3, 572;
/* 800B36D0 7CC70214 */  add      r6, r7, r0;
/* 800B36D4 88060381 */  lbz      r0, 897(r6);
/* 800B36D8 2C000000 */  cmpwi    r0, 0;
/* 800B36DC 41820028 */  beq-     UNDEF_800b3704;
/* 800B36E0 80060368 */  lwz      r0, 872(r6);
/* 800B36E4 7C040000 */  cmpw     r4, r0;
/* 800B36E8 4C820020 */  bnelr-;
/* 800B36EC 80660370 */  lwz      r3, 880(r6);
/* 800B36F0 38000000 */  li       r0, 0;
/* 800B36F4 9066036C */  stw      r3, 876(r6);
/* 800B36F8 9006037C */  stw      r0, 892(r6);
/* 800B36FC 4E800020 */  blr;
UNDEF_800b3704:;
/* 800B3704 7CE33B78 */  mr       r3, r7;
/* 800B3708 7D244B78 */  mr       r4, r9;
/* 800B370C 480A3BD4 */  b        UNDEF_801572e0;
/* 800B3710 4E800020 */  blr;
  // clang-format on
);

[[address(0x800B3B50)]]
bool isGameStop(u32 flag);

[[address(0x800B3B60)]]
void LayoutDispNumber(const int& value, const int& maxChars, LytTextBox_c* textBox, bool itoaType);

[[address(0x800B3BE0)]]
void LayoutDispNumberDigit(int const& value, LytTextBox_c* textBox, bool itoaType);

[[address(0x800B3C50)]]
void WindowPaneColorSet(nw4r::lyt::Window* window, int playerNum)
{
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

[[address(0x800B44D0)]]
void SelectCursorSetup(nw4r::lyt::Picture* pane, int param2, bool param3);

[[address(0x800B4760)]]
bool PlayerEnterCheck(int player)
{
    return dInfo_c::m_instance->getPlyConnectStage(player) == dInfo_c::PlyConnectStage_e::ENTER;
}

[[address(0x800B4780)]]
void Player1upColor(LytTextBox_c* textBox, int player)
{
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

[[address(0x800B4940)]]
void MiniGameCannonTitle()
{
    if (dMiniGameCannon_c* mg = dScStage_c::getMiniGameCannon()) {
        mg->mActive = true;
        mg->m0x2E0 = true;
    }
}

[[address(0x800B4970)]]
void MiniGameCannonStart()
{
    if (dMiniGameCannon_c* mg = dScStage_c::getMiniGameCannon()) {
        mg->mActive = true;
        mg->m0x2DA = true;
        mg->m0x2C0 = false;
    }
}

[[address(0x800B49A0)]]
void MiniGameCannonResult()
{
    if (dMiniGameCannon_c* mg = dScStage_c::getMiniGameCannon()) {
        mg->mActive = true;
        mg->m0x2DA = true;
        mg->m0x2C0 = true;
    }
}

[[address(0x800B49D0)]]
bool MiniGameCannonEndCheck()
{
    if (dMiniGameCannon_c* mg = dScStage_c::getMiniGameCannon()) {
        return mg->mActive;
    }
    return false;
}

[[address(0x800B4A00)]]
void MiniGameCannonTitleCloseRequest()
{
    if (dMiniGameCannon_c* mg = dScStage_c::getMiniGameCannon()) {
        mg->m0x2E2 = true;
    }
}

[[address(0x800B4A30)]]
void MiniGameCannonOperateCloseRequest()
{
    if (dMiniGameCannon_c* mg = dScStage_c::getMiniGameCannon()) {
        mg->m0x2E3 = true;
    }
}

[[address(0x800B4A60)]]
void MiniGameCannonResultCloseRequest()
{
    if (dMiniGameCannon_c* mg = dScStage_c::getMiniGameCannon()) {
        mg->m0x2E4 = true;
    }
}

[[address(0x800B4A90)]]
void MiniGameWireTitle();

[[address(0x800B4AC0)]]
void MiniGameWireStart();

//[[address(0x800B4AF0)]]
// void hash_71636FC0_C70BA13D;

[[address(0x800B4B20)]]
void MiniGameWireResult(const int* param);

[[address(0x800B4B90)]]
bool MiniGameWireEndCheck();

[[address(0x800B4BC0)]]
void MiniGameWireTitleCloseRequest();

[[address(0x800B4BF0)]]
void MiniGameWireOperateCloseRequest();

[[address(0x800B4C20)]]
void MiniGameWireResultCloseRequest();

[[address(0x800B4C50)]]
void MiniGameWireTurnOverCloseRequest();

//[[address(0x800B4C80)]]
// void hash_28043523_E21C82B0;

//[[address(0x800B4CC0)]]
// void hash_F8207C44_B2544017;

//[[address(0x800B4CF0)]]
// void hash_8F40075D_69D61FE1;

[[address(0x800B4DC0)]]
void MiniGameMessageDisp(int param);

[[address(0x800B4E00)]]
void MiniGameMessageClose();

[[address(0x800B4E30)]]
bool isNowCourseClear()
{
    if (fFeature::ALWAYS_CAN_EXIT_COURSE) {
        return true;
    }

    if (dScStage_c::m_miniGame != 0 || dInfo_c::m_startGameInfo.stage1 == STAGE_e::PEACH_CASTLE ||
        dScene_c::m_nowScene != dProf::STAGE || dInfo_c::mGameFlag & 0x10) {
        return true;
    }

    dMj2dGame_c* save = dSaveMng_c::m_instance->getSaveGame();
    return save->isCourseDataFlag(
      dInfo_c::m_startGameInfo.world1, dInfo_c::m_startGameInfo.stage1,
      dMj2dGame_c::COURSE_COMPLETION_e::GOAL_MASK
    );
}

[[address(0x800B5340)]]
bool chkContinue()
{
    // Original function is flawed as it indexes in mPlayerType twice (so like
    // mRest[int(mPlayerType[int(mPlayerType[i])])]). It doesn't matter but i think it's kinda
    // interesting.

    for (int i = 0; i < CHARACTER_COUNT; i++) {
        if (daPyMng_c::mRest[i] == 0) {
            return true;
        }
    }

    return false;
}

[[address(0x800B53F0)]]
bool chkCancelButton(int player)
{
    return dGameKey_c::m_instance->mpCores[player]->checkMenuCancel();
}

[[address(0x800B5450)]]
void setWorldClearFlag();

[[address(0x800B5500)]]
SCAspectRatio GetAspectRatio();

} // namespace dGameCom
