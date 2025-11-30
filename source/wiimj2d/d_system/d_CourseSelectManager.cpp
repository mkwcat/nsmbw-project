// d_CourseSelectManager.cpp
// NSMBW d_bases.text: 0x8092F020 - 0x80932F60

#include "d_CourseSelectManager.h"

#include "d_bases/d_CharacterChangeSelectBase.h"
#include "d_bases/d_CharacterChangeSelectContents.h"
#include "d_bases/d_CourseSelectMenu.h"
#include "d_bases/d_EasyPairing.h"
#include "d_bases/d_NumberOfPeopleChange.h"
#include "d_bases/d_StockItem.h"
#include "d_bases/d_a_wm_2DPlayer.h"
#include "d_bases/d_a_wm_player.h"
#include "d_system/d_game_common.h"
#include "d_system/d_mj2d_game.h"
#include <iterator>

[[address_data(0x809A2370)]]
dCourseSelectManager_c* dCourseSelectManager_c::m_instance;

[[address(0x8092F020)]]
dCourseSelectManager_c* dCourseSelectManager_c_classInit()
{
    return new dCourseSelectManager_c();
}

[[address(0x8092F050)]]
dCourseSelectManager_c::dCourseSelectManager_c();

/**
 * VT+0x24
 * pre method for the execute operation.
 */
[[address(0x8092F3D0)]]
fBase_c::PACK_RESULT_e dCourseSelectManager_c::preExecute()
{
    if (dBase_c::preExecute() == PACK_RESULT_e::NOT_READY) {
        return PACK_RESULT_e::NOT_READY;
    }

    if (daWmPlayer_c::ms_instance == nullptr) {
        return PACK_RESULT_e::NOT_READY;
    }

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (not mpa2DPlayer[i] or not mpa2DPlayer[i]->mReady) {
            return PACK_RESULT_e::NOT_READY;
        }
    }

    if (dGameCom::isGameStop(0xFFFFFFFF)) {
        return PACK_RESULT_e::NOT_READY;
    }

    return PACK_RESULT_e::SUCCEEDED;
}

[[address(0x8092F770)]]
void dCourseSelectManager_c::executeState_ContinueCheck()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        // Original function is flawed like in dGameCom::chkContinue()
        if (daPyMng_c::mRest[i] == 0) {
            mStateMgr.changeState(StateID_ContinueEndWait);
            return;
        }
    }

    mContinueActive = false;
    mStateMgr.changeState(StateID_KeyWait);
}

[[address(0x8092F830)]]
void dCourseSelectManager_c::executeState_ContinueEndWait()
{
    if (mpContinue->mDoExit) {
        mpContinue->mVisible = false;
        mpContinue->mIsOpen = false;
        mpContinue->mIsGameOver = false;

        mpContinue->mLayout.ReverseAnimeStartSetup(0, false);
        for (int i = 0; i < PLAYER_COUNT; i++) {
            int player = daPyMng_c::findPlayerWithType((PLAYER_TYPE_e)i);
            int newRest = mpContinue->mRestNum[i];
            daPyMng_c::mRest[daPyMng_c::mPlayerType[player]] = newRest;
        }

        mStateMgr.changeState(StateID_KeyWait);
        mCrsSelectGuide.mRestDispNeeded = true;
    }
}

[[address(0x8092F940)]]
void dCourseSelectManager_c::executeState_KeyWait() ASM_METHOD(
  // clang-format off
/* 8092F940 9421FFE0 */  stwu     r1, -32(r1);
/* 8092F944 7C0802A6 */  mflr     r0;
/* 8092F948 90010024 */  stw      r0, 36(r1);
/* 8092F94C 39610020 */  addi     r11, r1, 32;
/* 8092F950 4B9AD711 */  bl       UNDEF_802dd060;
/* 8092F954 88030541 */  lbz      r0, 1345(r3);
/* 8092F958 3FE0809A */  lis      r31, UNDEF_809a2360@ha;
/* 8092F95C 7C7E1B78 */  mr       r30, r3;
/* 8092F960 2C000000 */  cmpwi    r0, 0;
/* 8092F964 3BFF2360 */  addi     r31, r31, UNDEF_809a2360@l;
/* 8092F968 4182001C */  beq-     UNDEF_8092f984;
/* 8092F96C 85830070 */  lwzu     r12, 112(r3);
/* 8092F970 389F0060 */  addi     r4, r31, 96;
/* 8092F974 818C0018 */  lwz      r12, 24(r12);
/* 8092F978 7D8903A6 */  mtctr    r12;
/* 8092F97C 4E800421 */  bctrl;
/* 8092F980 480001E8 */  b        UNDEF_8092fb68;
UNDEF_8092f984:;
/* 8092F984 88030542 */  lbz      r0, 1346(r3);
/* 8092F988 2C000000 */  cmpwi    r0, 0;
/* 8092F98C 41820038 */  beq-     UNDEF_8092f9c4;
/* 8092F990 38000000 */  li       r0, 0;
/* 8092F994 9803053D */  stb      r0, 1341(r3);
/* 8092F998 3C608043 */  lis      r3, UNDEF_8042a788@ha;
/* 8092F99C 38800001 */  li       r4, 1;
/* 8092F9A0 8063A788 */  lwz      r3, UNDEF_8042a788@l(r3);
/* 8092F9A4 4B86D19D */  bl       UNDEF_8019cb40;
/* 8092F9A8 819E0070 */  lwz      r12, 112(r30);
/* 8092F9AC 387E0070 */  addi     r3, r30, 112;
/* 8092F9B0 389F0260 */  addi     r4, r31, 608;
/* 8092F9B4 818C0018 */  lwz      r12, 24(r12);
/* 8092F9B8 7D8903A6 */  mtctr    r12;
/* 8092F9BC 4E800421 */  bctrl;
/* 8092F9C0 480001A8 */  b        UNDEF_8092fb68;
UNDEF_8092f9c4:;
/* 8092F9C4 88030544 */  lbz      r0, 1348(r3);
/* 8092F9C8 2C000000 */  cmpwi    r0, 0;
/* 8092F9CC 4182001C */  beq-     UNDEF_8092f9e8;
/* 8092F9D0 85830070 */  lwzu     r12, 112(r3);
/* 8092F9D4 389F0720 */  addi     r4, r31, 1824;
/* 8092F9D8 818C0018 */  lwz      r12, 24(r12);
/* 8092F9DC 7D8903A6 */  mtctr    r12;
/* 8092F9E0 4E800421 */  bctrl;
/* 8092F9E4 48000184 */  b        UNDEF_8092fb68;
UNDEF_8092f9e8:;
/* 8092F9E8 8803053E */  lbz      r0, 1342(r3);
/* 8092F9EC 2C000000 */  cmpwi    r0, 0;
/* 8092F9F0 41820078 */  beq-     UNDEF_8092fa68;
/* 8092F9F4 808300AC */  lwz      r4, 172(r3);
/* 8092F9F8 38A00001 */  li       r5, 1;
/* 8092F9FC 38000000 */  li       r0, 0;
/* 8092FA00 3CC08043 */  lis      r6, UNDEF_8042a768@ha;
/* 8092FA04 98A40271 */  stb      r5, 625(r4);
/* 8092FA08 3880007C */  li       r4, 124;
/* 8092FA0C 38A00001 */  li       r5, 1;
/* 8092FA10 80E300AC */  lwz      r7, 172(r3);
/* 8092FA14 81030550 */  lwz      r8, 1360(r3);
/* 8092FA18 91070268 */  stw      r8, 616(r7);
/* 8092FA1C 806300AC */  lwz      r3, 172(r3);
/* 8092FA20 98030273 */  stb      r0, 627(r3);
/* 8092FA24 8066A768 */  lwz      r3, UNDEF_8042a768@l(r6);
/* 8092FA28 4B865A99 */  bl       UNDEF_801954c0; // startSystemSe__11SndAudioMgrFUiUl
/* 8092FA2C 3C608043 */  lis      r3, UNDEF_8042a788@ha;
/* 8092FA30 38800002 */  li       r4, 2;
/* 8092FA34 8063A788 */  lwz      r3, UNDEF_8042a788@l(r3);
/* 8092FA38 4B86D109 */  bl       UNDEF_8019cb40;
/* 8092FA3C 7FC3F378 */  mr       r3, r30;
/* 8092FA40 48001731 */  bl       UNDEF_80931170;
/* 8092FA44 7FC3F378 */  mr       r3, r30;
/* 8092FA48 480016A9 */  bl       UNDEF_809310f0;
/* 8092FA4C 819E0070 */  lwz      r12, 112(r30);
/* 8092FA50 387E0070 */  addi     r3, r30, 112;
/* 8092FA54 389F0120 */  addi     r4, r31, 288;
/* 8092FA58 818C0018 */  lwz      r12, 24(r12);
/* 8092FA5C 7D8903A6 */  mtctr    r12;
/* 8092FA60 4E800421 */  bctrl;
/* 8092FA64 48000104 */  b        UNDEF_8092fb68;
UNDEF_8092fa68:;
/* 8092FA68 8803053F */  lbz      r0, 1343(r3);
/* 8092FA6C 2C000000 */  cmpwi    r0, 0;
/* 8092FA70 4182001C */  beq-     UNDEF_8092fa8c;
/* 8092FA74 85830070 */  lwzu     r12, 112(r3);
/* 8092FA78 389F0560 */  addi     r4, r31, 1376;
/* 8092FA7C 818C0018 */  lwz      r12, 24(r12);
/* 8092FA80 7D8903A6 */  mtctr    r12;
/* 8092FA84 4E800421 */  bctrl;
/* 8092FA88 480000E0 */  b        UNDEF_8092fb68;
UNDEF_8092fa8c:;
/* 8092FA8C 88030547 */  lbz      r0, 1351(r3);
/* 8092FA90 2C000000 */  cmpwi    r0, 0;
/* 8092FA94 4182001C */  beq-     UNDEF_8092fab0;
/* 8092FA98 85830070 */  lwzu     r12, 112(r3);
/* 8092FA9C 389F07E0 */  addi     r4, r31, 2016;
/* 8092FAA0 818C0018 */  lwz      r12, 24(r12);
/* 8092FAA4 7D8903A6 */  mtctr    r12;
/* 8092FAA8 4E800421 */  bctrl;
/* 8092FAAC 480000BC */  b        UNDEF_8092fb68;
UNDEF_8092fab0:;
/* 8092FAB0 88030548 */  lbz      r0, 1352(r3);
/* 8092FAB4 2C000000 */  cmpwi    r0, 0;
/* 8092FAB8 4182001C */  beq-     UNDEF_8092fad4;
/* 8092FABC 85830070 */  lwzu     r12, 112(r3);
/* 8092FAC0 389F01A0 */  addi     r4, r31, 416;
/* 8092FAC4 818C0018 */  lwz      r12, 24(r12);
/* 8092FAC8 7D8903A6 */  mtctr    r12;
/* 8092FACC 4E800421 */  bctrl;
/* 8092FAD0 48000098 */  b        UNDEF_8092fb68;
UNDEF_8092fad4:;
/* 8092FAD4 8803054D */  lbz      r0, 1357(r3);
/* 8092FAD8 2C000000 */  cmpwi    r0, 0;
/* 8092FADC 4182001C */  beq-     UNDEF_8092faf8;
/* 8092FAE0 85830070 */  lwzu     r12, 112(r3);
/* 8092FAE4 389F08A0 */  addi     r4, r31, 2208;
/* 8092FAE8 818C0018 */  lwz      r12, 24(r12);
/* 8092FAEC 7D8903A6 */  mtctr    r12;
/* 8092FAF0 4E800421 */  bctrl;
/* 8092FAF4 48000074 */  b        UNDEF_8092fb68;
UNDEF_8092faf8:;
/* 8092FAF8 3F808035 */  lis      r28, mPlayerType__9daPyMng_c@ha;
/* 8092FAFC 3FE08035 */  lis      r31, mPlayerMode__9daPyMng_c@ha;
/* 8092FB00 7FDBF378 */  mr       r27, r30;
/* 8092FB04 3B400000 */  li       r26, 0;
/* 8092FB08 3B9C5160 */  addi     r28, r28, mPlayerType__9daPyMng_c@l;
/* 8092FB0C 3BFF5170 */  addi     r31, r31, mPlayerMode__9daPyMng_c@l;
/* 8092FB10 3BA00000 */  li       r29, 0;
UNDEF_8092fb14:;
/* 8092FB14 7C7ED214 */  add      r3, r30, r26;
/* 8092FB18 88030549 */  lbz      r0, 1353(r3);
/* 8092FB1C 2C000000 */  cmpwi    r0, 0;
/* 8092FB20 41820034 */  beq-     UNDEF_8092fb54;
/* 8092FB24 9BA30549 */  stb      r29, 1353(r3);
/* 8092FB28 7F43D378 */  mr       r3, r26;
/* 8092FB2C 4B784C35 */  bl       PlayerEnterCheck__8dGameComFi;
/* 8092FB30 2C030000 */  cmpwi    r3, 0;
/* 8092FB34 41820020 */  beq-     UNDEF_8092fb54;
/* 8092FB38 801C0000 */  lwz      r0, 0(r28);
/* 8092FB3C          */  lwz      r4, OFFSET_dCourseSelectManager_c_maPlayerPowerup(r27);
/* 8092FB40 5400103A */  slwi     r0, r0, 2;
/* 8092FB44 7C9F012E */  stwx     r4, r31, r0;
/* 8092FB48 7C7E0214 */  add      r3, r30, r0;
/* 8092FB4C          */  lwz      r3, OFFSET_dCourseSelectManager_c_mpa2DPlayer(r3);
/* 8092FB50 4BF972A1 */  bl       UNDEF_808c6df0;
UNDEF_8092fb54:;
/* 8092FB54 3B5A0001 */  addi     r26, r26, 1;
/* 8092FB58 3B7B0004 */  addi     r27, r27, 4;
/* 8092FB5C          */  cmpwi    r26, PLAYER_COUNT;
/* 8092FB60 3B9C0004 */  addi     r28, r28, 4;
/* 8092FB64 4180FFB0 */  blt+     UNDEF_8092fb14;
UNDEF_8092fb68:;
/* 8092FB68 39610020 */  addi     r11, r1, 32;
/* 8092FB6C 4B9AD541 */  bl       UNDEF_802dd0ac;
/* 8092FB70 80010024 */  lwz      r0, 36(r1);
/* 8092FB74 7C0803A6 */  mtlr     r0;
/* 8092FB78 38210020 */  addi     r1, r1, 32;
/* 8092FB7C 4E800020 */  blr;
  // clang-format on
);

[[address(0x8092FDF0)]]
void dCourseSelectManager_c::executeState_StockItemSelectWait()
{
    if (mpStockItem->m0x8DD != 0) {
        return;
    }

    for (int i = 0; i < PLAYER_COUNT; i++) {
        mpa2DPlayer[i]->m0x269 = 1;
    }

    mpCrsSelectMenu->m0x273 = 0;

    mStateMgr.changeState(StateID_KeyWait);
}

[[address(0x80930960)]]
void dCourseSelectManager_c::initializeState_EasyPairingWait()
{
    mpNumPyChg->setEasyPairingWait(true);
    mpEasyPairing->m0x279 = true;
}

[[address(0x80930A10)]]
void dCourseSelectManager_c::finalizeState_EasyPairingWait()
{
    mpNumPyChg->setEasyPairingWait(false);
}

[[address(0x809311E0)]]
PLAYER_MODE_e dCourseSelectManager_c::getPlayerPowerup(int playerIndex)
{
    int plrType = static_cast<int>(daPyMng_c::mPlayerType[playerIndex]);

    if (plrType >= std::size(mpa2DPlayer) || mpa2DPlayer[plrType] == nullptr) {
        return PLAYER_MODE_e::NONE;
    }

    return mpa2DPlayer[plrType]->mPowerup;
}
