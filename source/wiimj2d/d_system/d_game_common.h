#pragma once

#include <revolution/sc.h>

namespace nw4r::lyt
{
class Picture;

class Window;
} // namespace nw4r::lyt

class LytTextBox_c;

class mVec3_c;

class mVec2_c;

namespace dGameCom
{

/* 0x800B2E70 */
void initRandomSeed();

/* 0x800B2EE0 */
u32 rndInt(u32 max);

/* 0x800B2F00 */
f32 rnd();

/* 0x800B2F10 */
f32 rndF(f32 max);

/* 0x800B30C0 */
f32 getDispCenterX();

/* 0x800B2FB0 */
void initGame();

/* 0x800B32E0 @unofficial */
mVec3_c ScalePosForAspectRatio(const mVec3_c&);

/* 0x800B34D0 */
void CreateBlueNumber(const mVec3_c&, int, int);

/* 0x800B3510 */
void CreateRedNumber(const mVec3_c&, int);

/* 0x800B3540 */
void CreateSmallScore(const mVec3_c&, int type, int playerNo, bool goal);

/* 0x800B35B0 */
void CreateSmallAll1up(const mVec3_c&);

/* 0x800B35D0 */
void GoalScoreExecute(const mVec3_c&, int);

/* 0x800B37E0 @unofficial */
void ScalePosForLayoutEffect(const mVec3_c&, bool);

/* 0x800B3980 */
short CalculateTilt(int, float, float);

bool CalculateTiltShoulder(
  short* target_var, short target_value, short increment, s8 playerNo, short max
);

/* 0x800B3600 */
void FUN_800B3600(int, int);

/* 0x800B5340 */
bool chkContinue();

/* 0x800B53F0 */
bool chkCancelButton(int player);

/* 0x800B3B50 */
bool isGameStop(u32 flag);

/* 0x800B3B60 */
void LayoutDispNumber(const int& value, const int& maxChars, LytTextBox_c* textBox, bool itoaType);

/* 0x800B3BE0 */
void LayoutDispNumberDigit(int const& value, LytTextBox_c* textBox, bool itoaType);

/* 0x800B3C50 */
void WindowPaneColorSet(nw4r::lyt::Window* window, int playerNum);

/* 0x800B44D0 */
void SelectCursorSetup(nw4r::lyt::Picture* pane, int param2, bool param3);

/* 0x800B4760 */
bool PlayerEnterCheck(int player);

/* 0x800B4780 */
void Player1upColor(LytTextBox_c* textBox, int player);

/* 0x800B4940 */
void MiniGameCannonTitle();

/* 0x800B4970 */
void MiniGameCannonStart();

/* 0x800B49A0 */
void MiniGameCannonResult();

/* 0x800B49D0 */
bool MiniGameCannonEndCheck();

/* 0x800B4A00 */
void MiniGameCannonTitleCloseRequest();

/* 0x800B4A30 */
void MiniGameCannonOperateCloseRequest();

/* 0x800B4A60 */
void MiniGameCannonResultCloseRequest();

/* 0x800B4A90 */
void MiniGameWireTitle();

/* 0x800B4AC0 */
void MiniGameWireStart();

/* 0x800B4AF0 */
// void hash_71636FC0_C70BA13D;

/* 0x800B4B20 */
void MiniGameWireResult(const int* param);

/* 0x800B4B90 */
bool MiniGameWireEndCheck();

/* 0x800B4BC0 */
void MiniGameWireTitleCloseRequest();

/* 0x800B4BF0 */
void MiniGameWireOperateCloseRequest();

/* 0x800B4C20 */
void MiniGameWireResultCloseRequest();

/* 0x800B4C50 */
void MiniGameWireTurnOverCloseRequest();

/* 0x800B4C80 */
// void hash_28043523_E21C82B0;

/* 0x800B4CC0 */
// void hash_F8207C44_B2544017;

/* 0x800B4CF0 */
// void hash_8F40075D_69D61FE1;

/* 0x800B4DC0 */
void MiniGameMessageDisp(int param);

/* 0x800B4E00 */
void MiniGameMessageClose();

/* 0x800B5450 */
void setWorldClearFlag();

/* 0x800B5500 */
SCAspectRatio GetAspectRatio();

} // namespace dGameCom
