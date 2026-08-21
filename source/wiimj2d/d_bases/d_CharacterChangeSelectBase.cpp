// d_CharacterChangeSelectBase.cpp
// NSMBW: 0x8076F3D0 - 0x80772A50

#include "d_CharacterChangeSelectBase.h"

#include "d_bases/d_CharacterChangeIndicator.h"
#include "d_bases/d_CharacterChangeSelectArrow.h"
#include "d_bases/d_CharacterChangeSelectContents.h"
#include "d_bases/d_a_wm_2DPlayer.h"
#include "d_static/d_a_player_manager.h"
#include "d_static/d_game_key.h"
#include "d_static/d_game_key_core.h"
#include "d_static/d_mj2d_game.h"
#include "d_static/d_remocon_mng.h"
#include "d_static/d_scene.h"
#include "sound/SndAudioMgr.h"
#include "sound/SndID.h"
#include "sound/SndSceneMgr.h"
#include <revolution/os.h>

fBase_c* dCharacterChangeSelectBase_c_classInit()
{
    dCharacterChangeSelectBase_c* base = new dCharacterChangeSelectBase_c();
    base->mCcCount = 4;
    return base;
}

[[nsmbw(0x8076F400)]]
dCharacterChangeSelectBase_c::dCharacterChangeSelectBase_c();

[[nsmbw(0x8076FA40)]]
void dCharacterChangeSelectBase_c::clearPlayerNo()
{
    if (mPlayerNo < 0) {
        return;
    }

    for (std::size_t cc = 0; cc < mCcCount; cc++) {
        if (mpNumPySetupPlayers[cc] == mPlayerNo) {
            mpNumPySetupPlayers[cc] = -1;
            break;
        }
    }

    mpCcIndicator->setLampPattern(0u);
    mpCcIndicator->m0x24C = 0;
    mpCcIndicator->m0x234 = m0x2EC;

    if (dScene_c::m_nowScene != dProf::WORLD_MAP) {
        mPlayerNo = -1;
    }
}

[[nsmbw(0x8076FAE0)]]
bool dCharacterChangeSelectBase_c::updateRemocon()
{
    if (mPlayerNo >= 0) {
        bool setup = dRemoconMng_c::m_instance->mpConnect[mPlayerNo]->isSetup();
        if (!setup) {
            mpNumPyConnectStage[mPlayerNo] = dInfo_c::PlyConnectStage_e::OFF;
            clearPlayerNo();
        }
        return !setup;
    }

    dRemoconMng_c* remocons = dRemoconMng_c::m_instance;
    for (std::size_t ply = 0; ply < PLAYER_COUNT; ply++) {
        dRemoconMng_c::dConnect_c* connect = remocons->mpConnect[ply];
        if (!connect->isSetup()) {
            continue;
        }

        bool exist = false;
        for (std::size_t cc = 0; cc < mCcCount; cc++) {
            if (mpNumPySetupPlayers[cc] == ply) {
                exist = true;
                break;
            }
        }

        if (exist) {
            continue;
        }

        for (std::size_t cc = 0; cc < mCcCount; cc++) {
            if (mpNumPySetupPlayers[cc] < 0) {
                mpNumPySetupPlayers[cc] = ply;
                mPlayerNo = ply;
                return true;
            }
        }
    }

    return false;
}

PLAYER_TYPE_e dCharacterChangeSelectBase_c::getCharacterFromBase(int baseIndex)
{
    return dMj2dGame_c::scDefaultPlayerTypes[4 - baseIndex];
}

int dCharacterChangeSelectBase_c::getBaseFromCharacter(PLAYER_TYPE_e chara)
{
    for (std::size_t i = 0; i < CHARACTER_LIST_COUNT; i++) {
        if (dMj2dGame_c::scDefaultPlayerTypes[i] == chara) {
            return 4 - static_cast<int>(i);
        }
    }
    return -1;
}

PLAYER_TYPE_e dCharacterChangeSelectBase_c::getCharacterFromIcon(Icon_e icon)
{
    switch (icon) {
    default:
    case Icon_e::ICON_MARIO:
    case Icon_e::ICON_MARIO_LOCKED:
        return PLAYER_TYPE_e::MARIO;

    case Icon_e::ICON_LUIGI:
    case Icon_e::ICON_LUIGI_LOCKED:
        return PLAYER_TYPE_e::LUIGI;

    case Icon_e::ICON_YELLOW_TOAD:
    case Icon_e::ICON_YELLOW_TOAD_LOCKED:
        return PLAYER_TYPE_e::YELLOW_TOAD;

    case Icon_e::ICON_BLUE_TOAD:
    case Icon_e::ICON_BLUE_TOAD_LOCKED:
        return PLAYER_TYPE_e::BLUE_TOAD;

    case Icon_e::ICON_TOADETTE:
    case Icon_e::ICON_TOADETTE_LOCKED:
        return PLAYER_TYPE_e::TOADETTE;

    case Icon_e::ICON_PURPLE_TOADETTE:
    case Icon_e::ICON_PURPLE_TOADETTE_LOCKED:
        return PLAYER_TYPE_e::PURPLE_TOADETTE;

    case Icon_e::ICON_ORANGE_TOAD:
    case Icon_e::ICON_ORANGE_TOAD_LOCKED:
        return PLAYER_TYPE_e::ORANGE_TOAD;

    case Icon_e::ICON_BLACK_TOAD:
    case Icon_e::ICON_BLACK_TOAD_LOCKED:
        return PLAYER_TYPE_e::BLACK_TOAD;
    }
}

bool dCharacterChangeSelectBase_c::isLockedIcon(Icon_e icon)
{
    switch (icon) {
    default:
        return false;

    case Icon_e::ICON_MARIO_LOCKED:
    case Icon_e::ICON_LUIGI_LOCKED:
    case Icon_e::ICON_YELLOW_TOAD_LOCKED:
    case Icon_e::ICON_BLUE_TOAD_LOCKED:
    case Icon_e::ICON_TOADETTE_LOCKED:
    case Icon_e::ICON_PURPLE_TOADETTE_LOCKED:
    case Icon_e::ICON_ORANGE_TOAD_LOCKED:
    case Icon_e::ICON_BLACK_TOAD_LOCKED:
        return true;
    }
}

[[nsmbw(0x8076FC80)]]
bool dCharacterChangeSelectBase_c::isCharacterLocked(PLAYER_TYPE_e character)
{
    for (std::size_t ply = 0; ply < PLAYER_COUNT; ply++) {
        if (mPlayerNo == ply) {
            continue;
        }

        if (mpNumPyConnectStage[ply] == dInfo_c::PlyConnectStage_e::ENTER &&
            mpNumPyPlyDecidedPlayerType[ply] == character) {
            return true;
        }
    }
    return false;
}

[[nsmbw(0x8076FD70)]]
void dCharacterChangeSelectBase_c::calcContentsIcon(int swapIndex, int baseIndex)
{
    Icon_e iconIndex = ICON_FROM_BASE[4 - baseIndex];

    if (isCharacterLocked(getCharacterFromBase(baseIndex))) {
        iconIndex = ICON_LOCKED_FROM_BASE[4 - baseIndex];
    }

    if (swapIndex == 0) {
        mpCcSelContents->m0x290 = iconIndex;
    } else {
        mpCcSelContents->m0x298 = iconIndex;
    }
}

[[nsmbw(0x8076FE40)]]
void dCharacterChangeSelectBase_c::initDecidedCharacter()
{
    mDecidedCharacter = getCharacterFromBase(mOption);
}

[[nsmbw(0x8076FE60)]]
void dCharacterChangeSelectBase_c::initOption()
{
    mOption = getBaseFromCharacter(daPyMng_c::mPlayerType[mPlayerNo]);
}

[[nsmbw(0x8076FE90)]]
void dCharacterChangeSelectBase_c::resetIndicator()
{
    mpCcIndicator->setLampPattern(0u);
}

[[nsmbw(0x8076FEE0)]]
void dCharacterChangeSelectBase_c::readyContents()
{
    mOption = 4 - mPlayerNo;
    mp0x278->SetVisible(true);
    mp0x27C->SetVisible(false);
    calcContentsIcon(0, mOption);
    mpCcSelContents->m0x29D = true;
    mpCcSelContents->mPlayerNo = mPlayerNo;
    mpCcIndicator->m0x24C = 2;
    mpCcIndicator->m0x234 = m0x2EC;
}

[[nsmbw(0x80770090)]]
void dCharacterChangeSelectBase_c::finalizeState_OnStageWait()
{
    resetIndicator();
    mp0x278->SetVisible(false);
    mp0x27C->SetVisible(true);

    bool isWorldMap = dScene_c::m_nowScene == dProf::WORLD_MAP;
    if (isWorldMap) {
        if (mpNumPyConnectStage[mPlayerNo] != dInfo_c::PlyConnectStage_e::ENTER) {
            return;
        }

        mpCcIndicator->mPlayerNo = mPlayerNo;
        mpCcIndicator->m0x248 = 3;
        mpCcIndicator->setLampPattern(getLampPattern(mPlayerNo));
        mpCcIndicator->m0x24C = 1;
        mpCcIndicator->m0x234 = m0x2EC;
    } else {
        mPlayerNo = -1;
        if (!updateRemocon()) {
            return;
        }

        mpCcIndicator->mPlayerNo = mPlayerNo;
        mpCcIndicator->m0x248 = 3;
        mpCcIndicator->setLampPattern(getLampPattern(mPlayerNo));
        mpCcIndicator->m0x24C = 0;
        mpCcIndicator->m0x234 = m0x2EC;
        mpNumPyConnectStage[mPlayerNo] = dInfo_c::PlyConnectStage_e::SETUP;
        readyContents();
        mpCcSelArrow->mOption = mOption;
        mpCcSelArrow->m0x269 = true;
        mpNumPyConnectStage[mPlayerNo] = dInfo_c::PlyConnectStage_e::SELECT;
    }
}

[[nsmbw(0x807702A0)]]
void dCharacterChangeSelectBase_c::executeState_OnStageAnimeEndWait()
{
    if (!m0x299) {
        return;
    }

    const auto* state = &StateID_SelectWait;
    const bool isWorldMap = dScene_c::m_nowScene == dProf::WORLD_MAP;
    if (isWorldMap && mpNumPyConnectStage[mPlayerNo] == dInfo_c::PlyConnectStage_e::ENTER) {
        initOption();
        initDecidedCharacter();
        da2DPlayer_c* p2dPlayer = mp2DPlayer[mDecidedCharacter];
        p2dPlayer->mBasePos = mAllBasePos[0];
        p2dPlayer->mPos = mAllBasePos[0];
        state = &StateID_PlayerDisp;
    } else if (isWorldMap || mPlayerNo < 0) {
        state = &StateID_ConnectWait;
    }
    return mStateMgr.changeState(*state);
}

[[nsmbw(0x807703F0)]]
void dCharacterChangeSelectBase_c::finalizeState_OnStageAnimeEndWait();

[[nsmbw(0x80770400)]]
void dCharacterChangeSelectBase_c::initializeState_ConnectWait();

[[nsmbw(0x80770430)]]
void dCharacterChangeSelectBase_c::executeState_ConnectWait();

// Empty
[[nsmbw(0x80770540)]]
void dCharacterChangeSelectBase_c::finalizeState_ConnectWait();

// Empty
[[nsmbw(0x80770550)]]
void dCharacterChangeSelectBase_c::initializeState_SelectStartWait();

[[nsmbw(0x80770560)]]
void dCharacterChangeSelectBase_c::executeState_SelectStartWait();

// Empty
[[nsmbw(0x80770620)]]
void dCharacterChangeSelectBase_c::finalizeState_SelectStartWait();

[[nsmbw(0x80770630)]]
void dCharacterChangeSelectBase_c::initializeState_ButtonExitAnimeEndWait();

[[nsmbw(0x80770670)]]
void dCharacterChangeSelectBase_c::executeState_ButtonExitAnimeEndWait();

[[nsmbw(0x807706D0)]]
void dCharacterChangeSelectBase_c::finalizeState_ButtonExitAnimeEndWait();

[[nsmbw(0x807706E0)]]
void dCharacterChangeSelectBase_c::initializeState_ButtonOnStageAnimeEndWait()
{
    if (mPlayerNo < 0 || mpNumPyConnectStage[mPlayerNo] == dInfo_c::PlyConnectStage_e::OFF) {
        clearPlayerNo();
        mp0x278->SetVisible(false);
        mp0x27C->SetVisible(true);
        mpCcSelContents->m0x29F = true;
        mpCcSelArrow->m0x26B = true;
    } else {
        readyContents();
    }
    mLayout.AnimeStartSetup(0);
    m0x296 = true;
}

[[nsmbw(0x80770790)]]
void dCharacterChangeSelectBase_c::executeState_ButtonOnStageAnimeEndWait();

[[nsmbw(0x80770820)]]
void dCharacterChangeSelectBase_c::finalizeState_ButtonOnStageAnimeEndWait();

[[nsmbw(0x80770830)]]
void dCharacterChangeSelectBase_c::initializeState_ArrowDispWait();

[[nsmbw(0x80770850)]]
void dCharacterChangeSelectBase_c::executeState_ArrowDispWait();

[[nsmbw(0x807708B0)]]
void dCharacterChangeSelectBase_c::finalizeState_ArrowDispWait();

[[nsmbw(0x807708D0)]]
void dCharacterChangeSelectBase_c::initializeState_SelectWait();

[[nsmbw(0x807708E0)]]
void dCharacterChangeSelectBase_c::executeState_SelectWait()
{
    if (updateRemocon()) {
        mPlayerNo = -1;
        return mStateMgr.changeState(StateID_ButtonExitAnimeEndWait);
    }

    calcContentsIcon(0, mOption);

    dGameKeyCore_c* core = dGameKey_c::m_instance->mpCores[mPlayerNo];

    const sFStateID_c<dCharacterChangeSelectBase_c>* state = nullptr;
    if (core->checkMenuConfirm()) {
        if (isCharacterLocked(dMj2dGame_c::scDefaultPlayerTypes[4 - mOption])) {
            return;
        }

        (*mpNumPyEnterCount)++;

        if (*mpNumPyEnterCount >= mPlayerCount) {
            *mpNumPyEnterCount = mPlayerCount;
            if (dScene_c::m_nowScene != dProf::WORLD_MAP) {
                SndSceneMgr::sInstance->setGameSetupTrack(3);
            }
        }

        m0x2A0 = mOption;
        state = &StateID_HitAnimeEndWait;
    } else if (core->checkLeft()) {
        if (mOption >= 4) {
            return;
        }
        m0x2A0 = 5;
        mOption++;
        mpCcSelArrow->mMoveDir = 1;
        state = &StateID_MoveAnimeEndWait;
    } else if (core->checkRight()) {
        if (mOption <= 5 - CHARACTER_LIST_COUNT) {
            return;
        }
        m0x2A0 = 4;
        mOption--;
        mpCcSelArrow->mMoveDir = 2;
        state = &StateID_MoveAnimeEndWait;
    }

    if (state) {
        return mStateMgr.changeState(*state);
    }
}

[[nsmbw(0x80770B40)]]
void dCharacterChangeSelectBase_c::finalizeState_SelectWait();

[[nsmbw(0x80770B50)]]
void dCharacterChangeSelectBase_c::initializeState_MoveAnimeStartWait();

[[nsmbw(0x80770BA0)]]
void dCharacterChangeSelectBase_c::executeState_MoveAnimeStartWait();

[[nsmbw(0x80770BE0)]]
void dCharacterChangeSelectBase_c::finalizeState_MoveAnimeStartWait();

[[nsmbw(0x80770BF0)]]
void dCharacterChangeSelectBase_c::initializeState_MoveAnimeEndWait();

[[nsmbw(0x80770C90)]]
void dCharacterChangeSelectBase_c::executeState_MoveAnimeEndWait();

[[nsmbw(0x80770D00)]]
void dCharacterChangeSelectBase_c::finalizeState_MoveAnimeEndWait();

[[nsmbw(0x80770D80)]]
void dCharacterChangeSelectBase_c::initializeState_HitAnimeEndWait();

[[nsmbw(0x80770E20)]]
void dCharacterChangeSelectBase_c::executeState_HitAnimeEndWait();

[[nsmbw(0x80770E70)]]
void dCharacterChangeSelectBase_c::finalizeState_HitAnimeEndWait();

[[nsmbw(0x80770E80)]]
void dCharacterChangeSelectBase_c::initializeState_HitAfterExitWait();

[[nsmbw(0x80770E90)]]
void dCharacterChangeSelectBase_c::executeState_HitAfterExitWait();

// Empty
[[nsmbw(0x80770ED0)]]
void dCharacterChangeSelectBase_c::finalizeState_HitAfterExitWait();

[[nsmbw(0x80770EE0)]]
void dCharacterChangeSelectBase_c::initializeState_ExitAnimeEndForPlayerOnStageWait() ASM_METHOD(
  // clang-format off
/* 80770EE0 9421FFD0 */  stwu     r1, -48(r1);
/* 80770EE4 7C0802A6 */  mflr     r0;
/* 80770EE8 3C808093 */  lis      r4, UNDEF_80933d48@ha;
/* 80770EEC 3CE08093 */  lis      r7, UNDEF_80933d40@ha;
/* 80770EF0 90010034 */  stw      r0, 52(r1);
/* 80770EF4 3C004330 */  lis      r0, 17200;
/* 80770EF8 C8443D48 */  lfd      f2, UNDEF_80933d48@l(r4);
/* 80770EFC 93E1002C */  stw      r31, 44(r1);
/* 80770F00 7C7F1B78 */  mr       r31, r3;
/* 80770F04 C0273D40 */  lfs      f1, UNDEF_80933d40@l(r7);
/* 80770F08 93C10028 */  stw      r30, 40(r1);
/* 80770F0C 3BC00001 */  li       r30, 1;
/* 80770F10 80C302DC */  // lwz      r6, 732(r3);
/* 80770F14 80A302D4 */  lwz      r5, 724(r3);
/* 80770F18 1D06000C */  // mulli    r8, r6, 12;
/* 80770F1C 3CC08093 */  lis      r6, UNDEF_809352b0@ha;
/* 80770F20 54A5103A */  slwi     r5, r5, 2;
/* 80770F24 90010020 */  stw      r0, 32(r1);
/* 80770F28 7D234214 */  // add      r9, r3, r8;
                         lwz      r12, 0x80(r3);
/* 80770F30          */  lfs      f3, 0x2AC(r3);
/* 80770F34 3D008043 */  lis      r8, UNDEF_8042a760@ha;
/* 80770F38          */  lfs      f4, 0x2A8(r3);
/* 80770F40          */  lwzx     r10, r12, r5;
/* 80770F3C 38A00000 */  li       r5, 0;
/* 80770F44 38800004 */  li       r4, 4;
/* 80770F48          */  lfs      f0, 0x2A4(r3);
/* 80770F4C D00A022C */  stfs     f0, 556(r10);
/* 80770F50 C00652B0 */  lfs      f0, UNDEF_809352b0@l(r6);
/* 80770F54 D08A0230 */  stfs     f4, 560(r10);
/* 80770F58 EC010032 */  fmuls    f0, f1, f0;
/* 80770F5C D06A0234 */  stfs     f3, 564(r10);
/* 80770F60 80C8A760 */  lwz      r6, UNDEF_8042a760@l(r8);
/* 80770F64 C0A30104 */  lfs      f5, 260(r3);
/* 80770F68 80C60000 */  lwz      r6, 0(r6);
/* 80770F6C 800302D4 */  lwz      r0, 724(r3);
/* 80770F70 A0C60004 */  lhz      r6, 4(r6);
/* 80770F74 90C10024 */  stw      r6, 36(r1);
/* 80770F78 5400103A */  slwi     r0, r0, 2;
/* 80770F7C          */  lwz      r6, 0x80(r3);
/* 80770F80 C0C30108 */  lfs      f6, 264(r3);
/* 80770F84 C8210020 */  lfd      f1, 32(r1);
/* 80770F88          */  lwzx     r6, r6, r0;
/* 80770F8C EC211028 */  fsubs    f1, f1, f2;
/* 80770F90 D0810014 */  stfs     f4, 20(r1);
/* 80770F94 D0610018 */  stfs     f3, 24(r1);
/* 80770F98 EC212824 */  fdivs    f1, f1, f5;
/* 80770F9C D0A10008 */  stfs     f5, 8(r1);
/* 80770FA0 D0C1000C */  stfs     f6, 12(r1);
/* 80770FA4 EC01002A */  fadds    f0, f1, f0;
/* 80770FA8 D00600AC */  stfs     f0, 172(r6);
/* 80770FAC D08600B0 */  stfs     f4, 176(r6);
/* 80770FB0 D06600B4 */  stfs     f3, 180(r6);
/* 80770FB8 D0010010 */  stfs     f0, 16(r1);
/* 80770FC8 9BC60267 */  stb      r30, 615(r6);
/* 80770FD8 38630090 */  addi     r3, r3, 144;
/* 80770FE0 9BC60261 */  stb      r30, 609(r6);
/* 80770FE4 4B9583FD */  bl       UNDEF_800c93e0;
/* 80770FE8 9BDF0296 */  stb      r30, 662(r31);
/* 80770FEC 83E1002C */  lwz      r31, 44(r1);
/* 80770FF0 83C10028 */  lwz      r30, 40(r1);
/* 80770FF4 80010034 */  lwz      r0, 52(r1);
/* 80770FF8 7C0803A6 */  mtlr     r0;
/* 80770FFC 38210030 */  addi     r1, r1, 48;
/* 80771000 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80771090)]]
void dCharacterChangeSelectBase_c::initializeState_PlayerOnStageWait()
{
    std::size_t index = static_cast<std::size_t>(mDecidedCharacter);
    da2DPlayer_c* player = mp2DPlayer[mDecidedCharacter];

    u16 sound = (u16[][2]) {
      {SndID::SE_VOC_MA_PLAYER_JOIN, SndID::SE_VOC_MA_PLAYER_JOIN_MAME},
      {SndID::SE_VOC_LU_PLAYER_JOIN, SndID::SE_VOC_LU_PLAYER_JOIN_MAME},
      {SndID::SE_VOC_KO_PLAYER_JOIN, SndID::SE_VOC_KO_PLAYER_JOIN_MAME},
      {SndID::SE_VOC_KO2_PLAYER_JOIN, SndID::SE_VOC_KO2_PLAYER_JOIN_MAME},
      {SndID::SE_VOC_KC_PLAYER_JOIN, SndID::SE_VOC_KC_PLAYER_JOIN_MAME},
      {SndID::SE_VOC_KC_PLAYER_JOIN, SndID::SE_VOC_KC_PLAYER_JOIN_MAME},
      {SndID::SE_VOC_KO_PLAYER_JOIN, SndID::SE_VOC_KO_PLAYER_JOIN_MAME},
      {SndID::SE_VOC_KO2_PLAYER_JOIN, SndID::SE_VOC_KO2_PLAYER_JOIN_MAME},
    }[index % 8][player->mPowerup == PLAYER_MODE_e::MINI_MUSHROOM];

    SndAudioMgr::sInstance->startSystemSe(sound, 1);
    daPyMng_c::mPlayerType[mPlayerNo] = mDecidedCharacter;
    if (!player->m0x262 && !player->m0x263) {
        player->m0x263 = true;
        player->m0x23C = 2;
        player->m0x240 = true;
        player->m0x250 = 1.0f;
        player->m0x265 = true;
    }
    player->mAddY = m2dPlayerBaseY;

    m0x296 = true;
}

[[nsmbw(0x80771220)]]
void dCharacterChangeSelectBase_c::executeState_PlayerOnStageWait() ASM_METHOD(
  // clang-format off
/* 80771220 800302D4 */  lwz      r0, 724(r3);
/* 80771224 5400103A */  slwi     r0, r0, 2;
/* 80771228          */  lwz      r4, 0x80(r3);
/* 8077122C 80840080 */  lwzx     r4, r4, r0;
/* 80771230 88040263 */  lbz      r0, 611(r4);
/* 80771234 2C000000 */  cmpwi    r0, 0;
/* 80771238 4C820020 */  bnelr-;
/* 8077123C 88040262 */  lbz      r0, 610(r4);
/* 80771240 2C000000 */  cmpwi    r0, 0;
/* 80771244 41820008 */  beq-     UNDEF_8077124c;
/* 80771248 4E800020 */  blr;
UNDEF_8077124c:;
/* 8077124C 85830228 */  lwzu     r12, 552(r3);
/* 80771250 3C808099 */  lis      r4, UNDEF_80990d18@ha;
/* 80771254 38840D18 */  addi     r4, r4, UNDEF_80990d18@l;
/* 80771258 818C0018 */  lwz      r12, 24(r12);
/* 8077125C 7D8903A6 */  mtctr    r12;
/* 80771260 4E800420 */  bctr;
  // clang-format on
);

[[nsmbw(0x80771270)]]
void dCharacterChangeSelectBase_c::finalizeState_PlayerOnStageWait() ASM_METHOD(
  // clang-format off
/* 80771270 808302D4 */  lwz      r4, 724(r3);
/* 80771274 38A00000 */  li       r5, 0;
/* 80771278 38000001 */  li       r0, 1;
/* 8077127C 5484103A */  slwi     r4, r4, 2;
/* 80771280          */  lwz      r6, 0x80(r3);
/* 80771284          */  lwzx     r4, r6, r4;
/* 80771288 98A40267 */  stb      r5, 615(r4);
/* 8077128C C00302EC */  lfs      f0, 748(r3);
/* 80771290 8083007C */  lwz      r4, 124(r3);
/* 80771294 9004024C */  stw      r0, 588(r4);
/* 80771298 D0040234 */  stfs     f0, 564(r4);
/* 8077129C 98A30296 */  stb      r5, 662(r3);
/* 807712A0 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x807712B0)]]
void dCharacterChangeSelectBase_c::initializeState_PlayerDisp()
{
    mp2DPlayer[mDecidedCharacter]->mPlayerNo = mPlayerNo;
    if (dScene_c::isWorldMap() && mCcIndex == 0) {
        mp2DPlayer[mDecidedCharacter]->mForbidJump = true;
    }
    mDecided = true;
}

[[nsmbw(0x807712E0)]]
void dCharacterChangeSelectBase_c::executeState_PlayerDisp() ASM_METHOD(
  // clang-format off
/* 807712E0 9421FFF0 */  stwu     r1, -16(r1);
/* 807712E4 7C0802A6 */  mflr     r0;
/* 807712E8 90010014 */  stw      r0, 20(r1);
/* 807712EC 93E1000C */  stw      r31, 12(r1);
/* 807712F0 7C7F1B78 */  mr       r31, r3;
/* 807712F4 4BFFE7ED */  bl       UNDEF_8076fae0;
/* 807712F8 2C030000 */  cmpwi    r3, 0;
/* 807712FC 41820050 */  beq-     UNDEF_8077134c;
/* 80771300 801F02D4 */  lwz      r0, 724(r31);
/* 80771304 38C00001 */  li       r6, 1;
/* 80771308 3C808099 */  lis      r4, UNDEF_80990dd8@ha;
/* 8077130C 98DF0299 */  stb      r6, 665(r31);
/* 80771310 5403103A */  slwi     r3, r0, 2;
/* 80771314 3800FFFF */  li       r0, -1;
/* 80771318          */  lwz      r5, 0x80(r31);
/* 8077131C 38840DD8 */  addi     r4, r4, UNDEF_80990dd8@l;
/* 80771320          */  lwzx     r5, r5, r3;
/* 80771324 387F0228 */  addi     r3, r31, 552;
/* 80771328 98C50269 */  stb      r6, 617(r5);
/* 8077132C 80BF0074 */  lwz      r5, 116(r31);
/* 80771330 98C5029F */  stb      r6, 671(r5);
/* 80771334 901F02D8 */  stw      r0, 728(r31);
/* 80771338 819F0228 */  lwz      r12, 552(r31);
/* 8077133C 818C0018 */  lwz      r12, 24(r12);
/* 80771340 7D8903A6 */  mtctr    r12;
/* 80771344 4E800421 */  bctrl;
/* 80771348 4800006C */  b        UNDEF_807713b4;
UNDEF_8077134c:;
/* 8077134C 807F02D8 */  lwz      r3, 728(r31);
/* 80771350 4B9440A1 */  bl       UNDEF_800b53f0;
/* 80771354 2C030000 */  cmpwi    r3, 0;
/* 80771358 4182005C */  beq-     UNDEF_807713b4;
/* 8077135C 3C608043 */  lis      r3, UNDEF_8042a768@ha;
/* 80771360 3880007A */  li       r4, 122;
/* 80771364 8063A768 */  lwz      r3, UNDEF_8042a768@l(r3);
/* 80771368 38A00001 */  li       r5, 1;
/* 8077136C 4BA24155 */  bl       UNDEF_801954c0;
/* 80771370 809F0288 */  lwz      r4, 648(r31);
/* 80771374 80640000 */  lwz      r3, 0(r4);
/* 80771378 3803FFFF */  subi     r0, r3, 1;
/* 8077137C 90040000 */  stw      r0, 0(r4);
/* 80771380 807F0288 */  lwz      r3, 648(r31);
/* 80771384 80030000 */  lwz      r0, 0(r3);
/* 80771388 2C000000 */  cmpwi    r0, 0;
/* 8077138C 4080000C */  bge-     UNDEF_80771398;
/* 80771390 38000000 */  li       r0, 0;
/* 80771394 90030000 */  stw      r0, 0(r3);
UNDEF_80771398:;
/* 80771398 819F0228 */  lwz      r12, 552(r31);
/* 8077139C 3C808099 */  lis      r4, UNDEF_80990d58@ha;
/* 807713A0 387F0228 */  addi     r3, r31, 552;
/* 807713A4 818C0018 */  lwz      r12, 24(r12);
/* 807713A8 38840D58 */  addi     r4, r4, UNDEF_80990d58@l;
/* 807713AC 7D8903A6 */  mtctr    r12;
/* 807713B0 4E800421 */  bctrl;
UNDEF_807713b4:;
/* 807713B4 80010014 */  lwz      r0, 20(r1);
/* 807713B8 83E1000C */  lwz      r31, 12(r1);
/* 807713BC 7C0803A6 */  mtlr     r0;
/* 807713C0 38210010 */  addi     r1, r1, 16;
/* 807713C4 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x807713D0)]]
void dCharacterChangeSelectBase_c::finalizeState_PlayerDisp()
{
    mDecided = false;
    mp2DPlayer[mDecidedCharacter]->mForbidJump = false;
}

[[nsmbw(0x807713E0)]]
void dCharacterChangeSelectBase_c::initializeState_PlayerExitWait() ASM_METHOD(
  // clang-format off
/* 807713E0 800302D4 */  lwz      r0, 724(r3);
/* 807713E4 3C808093 */  lis      r4, UNDEF_809352b0@ha;
/* 807713E8 C00452B0 */  lfs      f0, UNDEF_809352b0@l(r4);
/* 807713EC 5400103A */  slwi     r0, r0, 2;
/* 807713F0          */  lwz      r4, 0x80(r3);
/* 807713F4          */  lwzx     r6, r4, r0;
/* 807713F8 D004022C */  stfs     f0, 556(r6);
/* 8077140C 88060262 */  lbz      r0, 610(r6);
/* 80771410 2C000000 */  cmpwi    r0, 0;
/* 80771414 40820034 */  bne-     UNDEF_80771448;
/* 80771418 88060263 */  lbz      r0, 611(r6);
/* 8077141C 2C000000 */  cmpwi    r0, 0;
/* 80771420 40820028 */  bne-     UNDEF_80771448;
/* 80771424 38A00001 */  li       r5, 1;
/* 80771428 98A60263 */  stb      r5, 611(r6);
/* 8077142C 38000003 */  li       r0, 3;
/* 80771430 3C808093 */  lis      r4, UNDEF_80933d50@ha;
/* 80771434 9006023C */  stw      r0, 572(r6);
/* 80771438 C0043D50 */  lfs      f0, UNDEF_80933d50@l(r4);
/* 8077143C 90A60240 */  stw      r5, 576(r6);
/* 80771440 D0060250 */  stfs     f0, 592(r6);
/* 80771444 98A60265 */  stb      r5, 613(r6);
UNDEF_80771448:;
/* 80771448 800302D4 */  lwz      r0, 724(r3);
/* 8077144C 38A00001 */  li       r5, 1;
/* 80771450 5400103A */  slwi     r0, r0, 2;
/* 80771454          */  lwz      r4, 0x80(r3);
/* 80771458          */  lwzx     r4, r4, r0;
/* 8077145C 98A40267 */  stb      r5, 615(r4);
/* 80771460 80830074 */  lwz      r4, 116(r3);
/* 80771464 98A30296 */  stb      r5, 662(r3);
/* 80771468 98A4029F */  stb      r5, 671(r4);
/* 8077146C 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80771470)]]
void dCharacterChangeSelectBase_c::executeState_PlayerExitWait() ASM_METHOD(
  // clang-format off
/* 80771470 800302D4 */  lwz      r0, 724(r3);
/* 80771474 5400103A */  slwi     r0, r0, 2;
/* 80771478          */  lwz      r4, 0x80(r3);
/* 8077147C          */  lwzx     r4, r4, r0;
/* 80771480 88040263 */  lbz      r0, 611(r4);
/* 80771484 2C000000 */  cmpwi    r0, 0;
/* 80771488 4C820020 */  bnelr-;
/* 8077148C 88040262 */  lbz      r0, 610(r4);
/* 80771490 2C000000 */  cmpwi    r0, 0;
/* 80771494 41820008 */  beq-     UNDEF_8077149c;
/* 80771498 4E800020 */  blr;
UNDEF_8077149c:;
/* 8077149C 85830228 */  lwzu     r12, 552(r3);
/* 807714A0 3C808099 */  lis      r4, UNDEF_80990d98@ha;
/* 807714A4 38840D98 */  addi     r4, r4, UNDEF_80990d98@l;
/* 807714A8 818C0018 */  lwz      r12, 24(r12);
/* 807714AC 7D8903A6 */  mtctr    r12;
/* 807714B0 4E800420 */  bctr;
  // clang-format on
);

[[nsmbw(0x807714C0)]]
void dCharacterChangeSelectBase_c::finalizeState_PlayerExitWait() ASM_METHOD(
  // clang-format off
/* 807714C0 800302D8 */  lwz      r0, 728(r3);
/* 807714C4 3CA08093 */  lis      r5, scDefaultPlayerTypes__11dMj2dGame_c@ha;
/* 807714C8 80C30280 */  lwz      r6, 640(r3);
/* 807714CC 3C808035 */  lis      r4, mPlayerType__9daPyMng_c@ha;
/* 807714D0 5400103A */  slwi     r0, r0, 2;
/* 807714D4 38E00001 */  li       r7, 1;
/* 807714D8 7CE6012E */  stwx     r7, r6, r0;
/* 807714DC 38A53CC0 */  addi     r5, r5, scDefaultPlayerTypes__11dMj2dGame_c@l;
/* 807714E0 38845160 */  addi     r4, r4, mPlayerType__9daPyMng_c@l;
/* 807714E4 38000000 */  li       r0, 0;
/* 807714E8 80C302D4 */  lwz      r6, 724(r3);
/* 807714EC 54C6103A */  slwi     r6, r6, 2;
/* 807714F0          */  lwz      r8, 0x80(r3);
/* 807714F4          */  lwzx     r6, r8, r6;
/* 807714F8 98E60267 */  stb      r7, 615(r6);
/* 807714FC 80E30264 */  lwz      r7, 612(r3);
/* 80771500 88C700BB */  lbz      r6, 187(r7);
/* 80771504 54C6063C */  rlwinm   r6, r6, 0, 24, 30;
/* 80771508 60C60001 */  ori      r6, r6, 1;
/* 8077150C 98C700BB */  stb      r6, 187(r7);
/* 80771510 80C302D8 */  lwz      r6, 728(r3);
/* 80771514 54C6103A */  slwi     r6, r6, 2;
/* 80771518 7CA5302E */  lwzx     r5, r5, r6;
/* 8077151C 7CA4312E */  stwx     r5, r4, r6;
/* 80771520 98030296 */  stb      r0, 662(r3);
/* 80771524 4E800020 */  blr;
  // clang-format on
);

u32 dCharacterChangeSelectBase_c::getLampPattern(int playerNo)
{
    if (unsigned(playerNo) >= PLAYER_COUNT) {
        return 0b0000000;
    }

    dRemoconMng_c::dConnect_c* connect = dRemoconMng_c::m_instance->mpConnect[playerNo];
    mPad::CH_e channel = connect->getChannel();

    if (channel >= mPad::CH_e::CHAN_0 && channel <= mPad::CH_e::CHAN_LAST) {
        return 0b1000 >> (channel - mPad::CH_e::CHAN_0);
    }
    if (channel >= mPad::CH_e::CHAN_GC_0 && channel <= mPad::CH_e::CHAN_GC_LAST) {
        return 0b10000 | (0b1000 >> (channel - mPad::CH_e::CHAN_GC_0));
    }
    if (channel >= mPad::CH_e::CHAN_CL_0 && channel <= mPad::CH_e::CHAN_CL_LAST) {
        return 0b100000 | (0b1000 >> (channel - mPad::CH_e::CHAN_CL_0));
    }

    return 0b000000;
}
