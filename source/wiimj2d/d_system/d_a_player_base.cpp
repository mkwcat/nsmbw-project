// d_a_player_base.cpp
// NSMBW .text: 0x800460D0 - 0x8005B3A0

#include "d_a_player_base.h"

#include "d_bases/d_s_stage.h"
#include "d_player/d_a_player.h"
#include "d_player/d_a_yoshi.h"
#include "d_player/d_gamedisplay.h"
#include "d_profile/d_profile.h"
#include "d_project/d_gamerule.h"
#include "d_system/d_a_player_hio_ADJ.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_course_data.h"
#include "d_system/d_game_common.h"
#include "d_system/d_mj2d_game.h"
#include "framework/f_manager.h"
#include "state/s_Lib.h"
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iterator>

[[nsmbw_data(0x8042BB20)]]
const float daPlBase_c::sc_DirSpeed[] = {1.0f, -1.0f};

[[nsmbw(0x8004DB40)]]
bool daPlBase_c::isDemoType(DemoType_e type);

[[nsmbw(0x8004DD00)]]
bool daPlBase_c::isDemo();

[[nsmbw(0x8004DDE0)]]
bool daPlBase_c::isDemoAll();

[[nsmbw(0x8004E040)]]
bool daPlBase_c::isPlayerGameStop();

[[nsmbw(0x8004E050)]]
void daPlBase_c::stopOther();

[[nsmbw(0x8004E100)]]
void daPlBase_c::playOther();

[[nsmbw(0x8004E290)]]
void daPlBase_c::changeDemoState(const sStateIDIf_c& state, int param);

[[nsmbw(0x8004E920)]]
void daPlBase_c::getWaterDokanCenterOffset(float);

[[nsmbw(0x8004E980)]]
void daPlBase_c::initDemoInDokan();

[[nsmbw(0x8004EA20)]]
void daPlBase_c::endDemoInDokan();

[[nsmbw(0x8004EA80)]]
void daPlBase_c::executeDemoInDokan(u8 param);

[[nsmbw(0x8004EDE0)]]
void daPlBase_c::initDemoInDokanUD(
    u8 param
) {
    auto& hio = dPyMdlMng_c::m_hio.mPyAnm.mAnm[0];
    mpModelMng->mModel->setAnm(0, hio.mRate, hio.mBlendDuration, 0.0f);

    const bool isYoshi = mKind == ACTOR_TYPE_e::YOSHI;
    mGotoPos           = mPos;

    if (param == 1) {
        mGotoPos.y += m_DemoStateArg == 2 ? 16.0f : 32.0f;
        mPos.y -= isYoshi ? 16.0f : 8.0f;
        if (isYoshi) {
            mAngle.y = 0;
        }
        return initDemoInDokan();
    }

    float f;
    onStatus(Status_e::PROPEL_NO_ROLL);
    if (isYoshi) {
        if (dAcPy_c* py = static_cast<daYoshi_c*>(this)->getPlayerRideOn()) {
            float dPyStatic_HIO_c::* value = &dPyStatic_HIO_c::mDokanUDOffsetYoshiBig;
            if (py->mPlayerMode == PLAYER_MODE_e::NONE) {
                value = &dPyStatic_HIO_c::mDokanUDOffsetYoshiSmall;
            } else if (py->mPlayerMode == PLAYER_MODE_e::MINI_MUSHROOM) {
                value = &dPyStatic_HIO_c::mDokanUDOffsetYoshiMini;
            }
            f = dPyStatic_HIO_c::get(py->mPlayerType).*value;
        } else {
            f = 30.0f;
        }
    } else {
        float dPyStatic_HIO_c::* value = &dPyStatic_HIO_c::mDokanUDAdjustBig;
        if (mPlayerMode == PLAYER_MODE_e::NONE) {
            value = &dPyStatic_HIO_c::mDokanUDOffsetSmall;
            f     = 0.0f;
        } else if (mPlayerMode == PLAYER_MODE_e::MINI_MUSHROOM) {
            value = &dPyStatic_HIO_c::mDokanUDOffsetMini;
            f     = 0.0f;
        } else if (mPlayerMode == PLAYER_MODE_e::PROPELLER_SHROOM) {
            value = &dPyStatic_HIO_c::mDokanUDAdjustPropeller;
            f     = mModelHeight;
        } else {
            value = &dPyStatic_HIO_c::mDokanUDAdjustBig;
            f     = mModelHeight;
        }
        f += dPyStatic_HIO_c::get(static_cast<dAcPy_c*>(this)->mPlayerType).*value;
    }

    mGotoPos.y = -f + mPos.y;
    mPos.y += 2.0f;

    if (isYoshi) {
        mAngle.y = 0;
    }
    return initDemoInDokan();
}

[[nsmbw(0x8004EFD0)]]
void daPlBase_c::initDemoInDokanLR(u8 param);

[[nsmbw(0x80050870)]]
void daPlBase_c::initializeState_DemoRailDokan() ASM_METHOD(
  // clang-format off
/* 80050870 9421FFD0 */  stwu     r1, -48(r1);
/* 80050874 7C0802A6 */  mflr     r0;
/* 80050878 388000BB */  li       r4, 187;
/* 8005087C 90010034 */  stw      r0, 52(r1);
/* 80050880 93E1002C */  stw      r31, 44(r1);
/* 80050884 7C7F1B78 */  mr       r31, r3;
/* 80050888 93C10028 */  stw      r30, 40(r1);
/* 8005088C 480063E5 */  bl       UNDEF_80056c70;
/* 80050890 806DAB28 */  lwz      r3, -21720(r13);
/* 80050894 808DA7F8 */  lwz      r4, -22536(r13);
/* 80050898 8803120E */  lbz      r0, 4622(r3);
/* 8005089C 1C0003B0 */  mulli    r0, r0, 944;
/* 800508A0 7C640214 */  add      r3, r4, r0;
/* 800508A4 8003002C */  lwz      r0, 44(r3);
/* 800508A8 2C000000 */  cmpwi    r0, 0;
/* 800508AC 41820008 */  beq-     UNDEF_800508b4;
/* 800508B0 48000008 */  b        UNDEF_800508b8;
UNDEF_800508b4:;
/* 800508B4 38600000 */  li       r3, 0;
UNDEF_800508b8:;
/* 800508B8 801F03F8 */  lwz      r0, 1016(r31);
/* 800508BC 5404063E */  clrlwi   r4, r0, 24                ;
/* 800508C0 4803DB11 */  bl       UNDEF_8008e3d0;
/* 800508C4 7C7E1B78 */  mr       r30, r3;
/* 800508C8 8863000F */  lbz      r3, 15(r3);
/* 800508CC 480888E5 */  bl       UNDEF_800d91b0;
/* 800508D0 808DAB28 */  lwz      r4, -21720(r13);
/* 800508D4 80ADA7F8 */  lwz      r5, -22536(r13);
/* 800508D8 8804120E */  lbz      r0, 4622(r4);
/* 800508DC 1C0003B0 */  mulli    r0, r0, 944;
/* 800508E0 7CC50214 */  add      r6, r5, r0;
/* 800508E4 8006002C */  lwz      r0, 44(r6);
/* 800508E8 2C000000 */  cmpwi    r0, 0;
/* 800508EC 41820008 */  beq-     UNDEF_800508f4;
/* 800508F0 48000008 */  b        UNDEF_800508f8;
UNDEF_800508f4:;
/* 800508F4 38C00000 */  li       r6, 0;
UNDEF_800508f8:;
/* 800508F8 A01E0010 */  lhz      r0, 16(r30);
                         clrlwi.  r0, r0, 31;
                         beq      NOT_DIRECT_PIPE_END;
                         lhz      r7, 4(r3);
                         subi     r0, r7, 2;
                         sth      r0, 1068(r31);
                         b        AFTER_DIRECT_PIPE_END_CHECK;
NOT_DIRECT_PIPE_END:;
                         li       r0, 1;
                         sth      r0, 1068(r31);
AFTER_DIRECT_PIPE_END_CHECK:;
                         lhz      r5, 2(r3);
                         lha      r4, 1068(r31);
                         lwz      r6, 60(r6);
                         add      r0, r5, r4;
                         slwi     r0, r0, 4;
                         add      r5, r6, r0;
/* 80050934 A8850002 */  lha      r4, 2(r5);
/* 80050938 3C604330 */  lis      r3, 17200;
/* 8005093C A8050000 */  lha      r0, 0(r5);
/* 80050940 7C8400D0 */  neg      r4, r4;
/* 80050944 90610010 */  stw      r3, 16(r1);
/* 80050948 6C848000 */  xoris    r4, r4, 32768;
/* 8005094C 6C008000 */  xoris    r0, r0, 32768;
/* 80050950 90810014 */  stw      r4, 20(r1);
/* 80050954 C8628838 */  lfd      f3, -30664(r2);
/* 80050958 C8010010 */  lfd      f0, 16(r1);
/* 8005095C 9001001C */  stw      r0, 28(r1);
/* 80050960 EC401828 */  fsubs    f2, f0, f3;
/* 80050964 C01F00B0 */  lfs      f0, 176(r31);
/* 80050968 90610018 */  stw      r3, 24(r1);
/* 8005096C C03F00AC */  lfs      f1, 172(r31);
/* 80050970 EC820028 */  fsubs    f4, f2, f0;
/* 80050974 C8010018 */  lfd      f0, 24(r1);
/* 80050978 EC401828 */  fsubs    f2, f0, f3;
/* 8005097C D081000C */  stfs     f4, 12(r1);
/* 80050980 EC040132 */  fmuls    f0, f4, f4;
/* 80050984 EC220828 */  fsubs    f1, f2, f1;
/* 80050988 D0210008 */  stfs     f1, 8(r1);
/* 8005098C EC210072 */  fmuls    f1, f1, f1;
/* 80050990 EC21002A */  fadds    f1, f1, f0;
/* 80050994 4826DDCD */  bl       UNDEF_802be760;
/* 80050998 C041000C */  lfs      f2, 12(r1);
/* 8005099C C0010008 */  lfs      f0, 8(r1);
/* 800509A0 EC620824 */  fdivs    f3, f2, f1;
/* 800509A4 C04288E8 */  lfs      f2, -30488(r2);
/* 800509A8 C0828844 */  lfs      f4, -30652(r2);
/* 800509AC EC000824 */  fdivs    f0, f0, f1;
/* 800509B0 EC6200F2 */  fmuls    f3, f2, f3;
/* 800509B4 EC420032 */  fmuls    f2, f2, f0;
/* 800509B8 EC210132 */  fmuls    f1, f1, f4;
/* 800509BC D07F040C */  stfs     f3, 1036(r31);
/* 800509C0 D05F0408 */  stfs     f2, 1032(r31);
/* 800509C4 FC00081E */  fctiwz   f0, f1;
/* 800509C8 D8010020 */  stfd     f0, 32(r1);
/* 800509CC 80010024 */  lwz      r0, 36(r1);
/* 800509D0 B01F042E */  sth      r0, 1070(r31);
/* 800509D4 83E1002C */  lwz      r31, 44(r1);
/* 800509D8 83C10028 */  lwz      r30, 40(r1);
/* 800509DC 80010034 */  lwz      r0, 52(r1);
/* 800509E0 7C0803A6 */  mtlr     r0;
/* 800509E4 38210030 */  addi     r1, r1, 48;
/* 800509E8 4E800020 */  blr      ;
  // clang-format on
);

[[nsmbw(0x80050D80)]]
bool daPlBase_c::isDispOutCheckOn();

[[nsmbw(0x80050A00)]]
void daPlBase_c::setExitRailDokan() {
    dCdFile_c* file = dCd_c::m_instance->mFiles + dScStage_c::m_instance->mCourse;
    if (file->mpAreas == nullptr) {
        file = nullptr;
    }
    dCdFile_c::NextGoto_s* currGoto = file->getNextGotoP(mGotoDest);
    dCdFile_c::NextGoto_s* destGoto = file->getNextGotoP(currGoto->nextNextGotoNum);
    mLayer                          = destGoto->layer;
    assert(destGoto->type > 2 && destGoto->type < 7);
    if (destGoto->type == 3) {
        changeDemoState(StateID_DemoInDokanD, 1);
    } else if (destGoto->type == 4) {
        changeDemoState(StateID_DemoInDokanU, 1);
    } else if (destGoto->type == 5) {
        changeDemoState(StateID_DemoInDokanR, 1);
    } else if (destGoto->type == 6) {
        changeDemoState(StateID_DemoInDokanL, 1);
    }
}

[[nsmbw(0x800510F0)]]
void daPlBase_c::stopGoalOther() {
    if (!isPlayerGameStop()) {
        return;
    }

    dActor_c::mExecStopReq |= 0xF;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        daPlBase_c* ctrlPlayer = daPyMng_c::getCtrlPlayer(i);
        if (ctrlPlayer == nullptr || !ctrlPlayer->isStatus(101)) {
            continue;
        }

        dAcPy_c* player = daPyMng_c::getPlayer(i);
        if (player != nullptr) {
            player->mExecStopMask &= ~0x2;
        }

        daYoshi_c* yoshi = daPyMng_c::getYoshi(i);
        if (yoshi != nullptr) {
            yoshi->mExecStopMask &= ~0x2;
        }
    }
}

[[nsmbw(0x800511A0)]]
void daPlBase_c::playGoalOther() {
    dActor_c::mExecStopReq &= ~0xF;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        daPlBase_c* ctrlPlayer = daPyMng_c::getCtrlPlayer(i);
        if (ctrlPlayer == nullptr || !isStatus(101)) {
            continue;
        }

        dAcPy_c* player = daPyMng_c::getPlayer(i);
        if (player != nullptr) {
            player->mExecStopMask |= 0x2;
        }

        daYoshi_c* yoshi = daPyMng_c::getYoshi(i);
        if (yoshi != nullptr) {
            yoshi->mExecStopMask |= 0x2;
        }
    }
}

[[nsmbw(0x80051E70)]]
bool daPlBase_c::startControlDemo();

[[nsmbw(0x80051EF0)]]
void daPlBase_c::endControlDemo(int param);

[[nsmbw(0x80051F30)]]
void daPlBase_c::setControlDemoDir(u8 direction);

[[nsmbw(0x80052030)]]
bool daPlBase_c::isControlDemoWait();

[[nsmbw(0x80052080)]]
void daPlBase_c::setControlDemoWalk(
    const float& pos, const float& speed
) {
    if (!isStatus(114)) {
        return;
    }

    if (mDemoState != ControlDemoSubstate_e::WALK || mControlDemoTargetPos.x != pos) {
        // Add anti-softlock failsafe to abort demo after 10 seconds
        m_DemoSubstateTimer = 60 * 10;
    }

    mControlDemoTargetPos.x = pos;
    mDemoState              = ControlDemoSubstate_e::WALK;
    mControlDemoSpeedF      = std::fabs(speed);
    if (mControlDemoSpeedF > getSpeedData()->mHighSpeed) {
        mControlDemoSpeedF = getSpeedData()->mHighSpeed;
    }
}

[[nsmbw(0x80052170)]]
void daPlBase_c::setControlDemoAnm(int anim);

[[nsmbw(0x80052290)]]
void daPlBase_c::UNDEF_80052290(s32 param);

[[nsmbw(0x80052300)]]
void daPlBase_c::setControlDemoKinopioWalk();

[[nsmbw(0x80052470)]]
bool daPlBase_c::isBossDemoLand();

[[nsmbw(0x80052500)]]
bool daPlBase_c::isHitGroundKinopioWalk(int dir, float f, int i2);

[[nsmbw(0x80052650)]]
bool daPlBase_c::isHitWallKinopioWalk(int);

[[nsmbw(0x800526C0)]]
bool daPlBase_c::checkKinopioWaitBG(int);

[[nsmbw(0x80052900)]]
void daPlBase_c::executeState_DemoControl() {
    offStatus(116);
    if (isStatus(115)) {
        if (isNowBgCross(BGC_FOOT)) {
            offStatus(115);
        } else {
            mSpeedF *= 0.98f;
        }
    }

    switch (mDemoState) {
    case ControlDemoSubstate_e::WALK: {
        onStatus(116);
        if (isNowBgCross(BGC_FOOT)) {
            if (!isState(StateID_Walk) && !isState(StateID_Turn)) {
                changeState(StateID_Walk, static_cast<int>(AnmBlend_e::DEFAULT));
            }
        } else {
            if (!isState(StateID_Fall)) {
                changeState(StateID_Fall, false);
            }
        }
        // Add failsafe timer check
        if (m_DemoSubstateTimer == 0 ||
            std::fabs(mPos.x - mControlDemoTargetPos.x) < mControlDemoSpeedF) {
            mDemoState = ControlDemoSubstate_e::WAIT;
            mSpeedF    = 0.0f;
            mPos.x     = mControlDemoTargetPos.x;
            break;
        }
        if (mPos.x < mControlDemoTargetPos.x) {
            mKey.onDemoTrigger(dAcPyKey_c::RIGHT);
            mSpeedF = mControlDemoSpeedF;
            break;
        }
        mKey.onDemoTrigger(dAcPyKey_c::LEFT);
        mSpeedF = -mControlDemoSpeedF;
        break;
    }
    case ControlDemoSubstate_e::CONTROL_DEMO_4: {
        if (m_DemoSubstateTimer == 0) {
            changeDemoState(StateID_DemoNone, false);
        }
        break;
    }
    case ControlDemoSubstate_e::KINOPIO_WALK: {
        if (!isNowBgCross(BGC_FOOT) || (!m_StateMgr.getStateID()->isEqual(StateID_Walk) &&
                                        !m_StateMgr.getStateID()->isEqual(StateID_Turn))) {
            mDemoState = ControlDemoSubstate_e::WAIT;
            break;
        }
        onStatus(116);
        if (isOnSinkSand() || (checkKinopioWaitBG(0) && checkKinopioWaitBG(1))) {
            mDemoState         = ControlDemoSubstate_e::KINOPIO_SINK_SAND;
            mControlDemoSpeedF = 0.0f;
            mSpeedF            = 0.0f;
            break;
        }
        int prevDirection = mItemKinopioDirection;
        sLib::calcTimer(&mItemKinopioTurnTimer);
        if (isHitWallKinopioWalk(mItemKinopioDirection) || mItemKinopioTurnTimer == 0) {
            mItemKinopioDirection ^= 1;
            mControlDemoTargetPos.x = mPos.x + sc_DirSpeed[mItemKinopioDirection] * 24.0f;
        } else if (!isHitGroundKinopioWalk(mItemKinopioDirection, 4.0f, 1) &&
                   !isHitGroundKinopioWalk(mItemKinopioDirection, 8.0f, 1)) {
            mItemKinopioDirection ^= 1;
            mControlDemoTargetPos.x = mPos.x + sc_DirSpeed[mItemKinopioDirection] * 24.0f;
        }
        float tmp = mControlDemoTargetPos.x + sc_DirSpeed[mItemKinopioDirection] * 24.0f;
        if (mPos.x < tmp) {
            mKey.onDemoTrigger(dAcPyKey_c::RIGHT);
            mSpeedF               = mControlDemoSpeedF;
            mItemKinopioDirection = 0;
        } else {
            mKey.onDemoTrigger(dAcPyKey_c::LEFT);
            mItemKinopioDirection = 1;
            mSpeedF               = -mControlDemoSpeedF;
        }
        if (prevDirection != mItemKinopioDirection) {
            mItemKinopioTurnTimer = 180;
        }
        break;
    }
    case ControlDemoSubstate_e::KINOPIO_SWIM: {
        if (!m_StateMgr.getStateID()->isEqual(StateID_Swim)) {
            mDemoState = ControlDemoSubstate_e::WAIT;
            break;
        }
        onStatus(116);
        if (isNowBgCross(BGC_FOOT) && isHitWallKinopioWalk(mItemKinopioDirection)) {
            mItemKinopioDirection ^= 1;
        }
        if (mItemKinopioDirection == 0) {
            mKey.onDemoTrigger(dAcPyKey_c::RIGHT);
            sLib::chase(&mSpeedF, 0.5625f, 0.1f);
        } else {
            mKey.onDemoTrigger(dAcPyKey_c::LEFT);
            sLib::chase(&mSpeedF, -0.5625f, 0.1f);
        }
        break;
    }
    case ControlDemoSubstate_e::KINOPIO_SINK_SAND: {
        if (!isNowBgCross(BGC_FOOT) || (!m_StateMgr.getStateID()->isEqual(StateID_Walk) &&
                                        !m_StateMgr.getStateID()->isEqual(StateID_Turn))) {
            mDemoState = ControlDemoSubstate_e::WAIT;
            break;
        }
        onStatus(116);
        onStatus(99);
        if (!checkKinopioWaitBG(0) || !checkKinopioWaitBG(1)) {
            setControlDemoKinopioWalk();
        }
        break;
    }
    default:
        break;
    }
}

[[nsmbw(0x80056370)]]
void daPlBase_c::UNDEF_80056370(dActor_c*, int);

[[nsmbw(0x80056980)]]
void daPlBase_c::setStatus5D(float f);

[[nsmbw(0x80056BD0)]]
bool daPlBase_c::isMameAction();

[[nsmbw(0x80056C70)]]
void daPlBase_c::onStatus(int flag);

[[nsmbw(0x80056CB0)]]
void daPlBase_c::offStatus(int flag);

[[nsmbw(0x80056CF0)]]
bool daPlBase_c::isStatus(int flag);

[[nsmbw(0x80056E30)]]
dPyMdlBase_c* daPlBase_c::getModel();

[[nsmbw(0x80057650)]]
const sSpeedData* daPlBase_c::getSpeedData();

[[nsmbw(0x80057E70)]]
void daPlBase_c::playSound(SndID::Type, long);

[[nsmbw(0x800583A0)]]
void daPlBase_c::calcHeadAttentionAngle();

// Static array works here as we have a limited number of players
static fBaseID_e s_lastHitEnemy[PLAYER_COUNT] = {};

void daPlBase_c::addDeathMessage(
    dActor_c* source, DamageType_e type, bool death
) {
    // TODO: Use BMG for messages
    if (dGameRule_s::current.death_messages == dGameRule_s::DEATH_MESSAGES_MODE_e::DISABLED) {
        return;
    }
    if (dGameRule_s::current.death_messages == dGameRule_s::DEATH_MESSAGES_MODE_e::DEATH_ONLY &&
        !death) {
        return;
    }

    fBaseID_e lastHit      = s_lastHitEnemy[mPlrNo];
    s_lastHitEnemy[mPlrNo] = source ? source->mUniqueID : fBaseID_e::NONE;

    bool        repeat     = source ? source->mUniqueID == lastHit : false;

    const char* selfName   = dProf::getFormattedName(this);
    if (selfName == nullptr) {
        selfName = "Someone";
    }

    const char* enemyName     = dProf::getFormattedName(source);
    dProfName   enemy         = source ? source->mProfName : dProf::LASTACTOR;

    fBase_c*    lastEnemy     = fManager_c::searchBaseByID(lastHit);
    const char* lastEnemyName = nullptr;
    if (lastEnemy != nullptr) {
        lastEnemyName = dProf::getFormattedName(static_cast<dBase_c*>(lastEnemy));
    }

    const char* messages[128] = {};
    int         messageCount  = 0;

    auto        msg           = [&](const char* const m) {
        if (messageCount < 128) {
            messages[messageCount++] = m;
        }
    };

    switch (type) {
    default:
        if (enemy == dProf::LASTACTOR) {
            enemy = dProf::BOOT; // LASTACTOR is not a constant expression
        }

        switch (enemy) {
        default:
            if (repeat) {
                msg("%s gave %s another chance");
                msg("%s didn't learn their lesson about %s");
                if (!death) {
                    break;
                }
            }

            if (death) {
                msg("%s was finished by %s");
                msg("%s was slain by %s");
                msg("%s reached an impassable %s");
                msg("%s couldn't handle %s");
                msg("%s lost a fight with %s");
                msg("%s lost it to %s");
                msg("%s was no match for %s");
                msg("%s seriously died to %s?");
                msg("%s met the wrath of %s");
                msg("%s didn't get the memo about %s");
            } else {
                msg("%s came into contact with %s");
                msg("%s occupied the same space as %s");
                msg("%s and %s touched hitboxes");
                msg("%s was hurt badly by %s");
                msg("%s forgot %s was harmful");
                msg("%s! Stay away from %s!");
                msg("%s wasn't warned about %s...");
                msg("%s was scratched by %s");
                msg("%s tried to hug %s");
                msg("%s touched %s the wrong way");
            }
            break;

        case dProf::BOOT:
            // Enemy name = "an unknown force"
            if (death) {
                msg("%s lost the game");
                msg("%s lost a fight with the game");
                msg("%s lost it to %s");
                msg("Someone killed %s!!!");
                msg("%s died");
            } else {
                msg("%s came into contact with %s");
                msg("%s was hurt badly");
            }

            break;

        case dProf::EN_BIGPILE_UNDER:
        case dProf::EN_BIGPILE_UPPER:
        case dProf::EN_BIGPILE_RIGHT:
        case dProf::EN_BIGPILE_LEFT:
        case dProf::EN_SUPER_BIGPILE_RIGHT:
        case dProf::EN_SUPER_BIGPILE_LEFT:
        case dProf::EN_GOKUBUTO_BIGPILE_UNDER:
        case dProf::EN_GOKUBUTO_BIGPILE_UPPER:
            // "was skewered by Skewer"
            if (death) {
                msg("%s was skewered by %s");
            } else {
                msg("%s was penetrated by %s");
                msg("%s was pummeled by %s");
                msg("%s was destroyed by %s");
            }
            break;

        case dProf::EN_KILLER:
        case dProf::EN_SEARCH_KILLER:
        case dProf::EN_MAGNUM_KILLER:
        case dProf::EN_SEARCH_MAGNUM_KILLER:
            if (death) {
                msg("%s was shot by %s");
            } else {
                msg("%s was struck by %s");
            }
            break;

        case dProf::EN_KING_KILLER:
            if (death) {
                msg("%s was blasted by %s");
            } else {
                msg("%s was pummeled by %s");
            }
            break;

        case dProf::EN_ICICLE:
        case dProf::EN_BIG_ICICLE:
            if (death) {
                msg("%s was skewered by %s");
            } else {
                msg("%s was impaled by %s");
            }
            break;

        case dProf::EN_DOSUN:
        case dProf::EN_BIGDOSUN:
            if (death) {
                msg("%s was smashed by %s");
                msg("%s was thwomped by %s");
            } else {
                msg("%s was pounded by %s");
                msg("%s was thumped by %s");
            }
            break;

        case dProf::EN_KANITAMA:
            if (death) {
                msg("%s was finished by a rock");
                msg("%s was slain by a rock");

                // Three times for greater weight
                msg("%s was killed with a rock");
                msg("%s was killed with a rock");
                msg("%s was killed with a rock");
            } else {
                msg("%s came into contact with a rock");
            }
            msg("%s lost a fight with a rock");
            break;
        }
        break;

    case DamageType_e::ELEC_SHOCK:
        if (enemyName == nullptr) {
            if (death) {
                msg("%s was electrocuted");
            } else {
                msg("%s was shocked");
            }
        } else {
            if (death) {
                msg("%s was electrocuted by %s");
            } else {
                msg("%s was shocked by %s");
            }
        }
        break;

    case DamageType_e::LAVA:
        msg("%s tried to swim in lava");
        msg("%s fell into lava");
        break;

    case DamageType_e::POISON_WATER:
        msg("%s drank the weird lanky water");
        msg("%s fell into the poisonous jungle juice");
        msg("%s fell into the radioactive water");
        break;

    case DamageType_e::CRUSH:
        if (enemyName == nullptr) {
            if (death) {
                msg("%s was squished to death");
            }
            msg("%s was crushed by a heavy object");
            msg("%s was squished too much");
        } else {
            msg("%s was squashed by %s");
        }
        break;

    case DamageType_e::EAT_DIE:
    case DamageType_e::EAT_DIE2:
        if (enemyName == nullptr) {
            msg("%s was devoured");
            msg("%s was devoured by a hungry creature");
            msg("%s was devoured by a monster");
        } else {
            msg("%s was devoured by %s");
        }
        break;

    case DamageType_e::FREEZE:
    case DamageType_e::FREEZE2:
        if (enemyName == nullptr) {
            if (death) {
                msg("%s froze to death");
            } else {
                msg("%s was frozen solid");
            }
        } else {
            if (death) {
                msg("%s froze to death by %s");
            } else {
                msg("%s was frozen solid by %s");
            }
        }
        break;

    case DamageType_e::POISON_FOG:
        msg("%s couldn't escape the fog");
        msg("%s got lost in the fog");
        break;

    case DamageType_e::FALL_DOWN:
        if (enemyName == nullptr) {
            if (lastEnemyName) {
                enemyName = lastEnemyName;
                msg("%s couldn't live in the same world as %s");
                msg("%s was knocked off a cliff by %s");
                msg("%s stumbled over %s and fell off");
            } else {
                msg("%s fell off");
                msg("%s fell through the floor");
                msg("%s fell off (on purpose)");
            }

            msg("%s fell out of the world");
            msg("%s forgot how to jump");
            msg("%s thought there was ground there");
            msg("%s didn't want to play anymore");
            msg("%s lost the game");
            msg("%s you're not supposed to go down there");
            msg("%s what's it like down there");
            msg("%s left the confines of the world");
        } else {
            msg("%s fell off and dragged %s with them");
            msg("%s sacrificed themselves to take out %s");
            msg("%s thought the world better without %s");
            msg("~%s was dragged into the void by %s");
            msg("~%s was betrayed by %s");
        }
        break;

    case DamageType_e::SCROLL_OUT:
        if (enemyName == nullptr) {
            msg("%s met the wrath of the edge of the screen");
            msg("%s mysteriously vanished");
            msg("%s died because the screen scrolled too much");
            msg("The screen just went too far for %s");
            msg("%s left the confines of the screen");
            msg("%s died");
            msg("%s was left behind");
            msg("%s died because people need to slow down");
            msg("%s died because people need to slow down");
            msg("%s died because PEOPLE NEED TO SLOW DOWN!!!!");
        } else {
            msg("%s and %s couldn't handle the screen's edge");
            msg("%s and %s met the edge of the screen");
            msg("%s showed %s to the edge of the screen");
            msg("%s and %s were left behind");
            msg("%s and %s mysteriously vanished");
            msg("%s and %s died");
            msg("%s and %s died because people need to slow down");
        }
        break;
    }

    const char* message = nullptr;
    if (messageCount > 0) {
        message = messages[dGameCom::rndInt(messageCount)];
    } else {
        if (death) {
            message = "%s died";
        } else {
            message = "%s was hurt";
        }
    }

    if (enemyName == nullptr) {
        enemyName = "an unknown force";
    }

    daPlBase_c* player = this;
    if (message[0] == '~') {
        // Swap order of names
        const char* temp = selfName;
        selfName         = enemyName;
        enemyName        = temp;
        if (source) {
            if (auto player2 = source->DynamicCast<daPlBase_c>()) {
                player = player2;
            }
        }
    }

    char formattedMessage[128];
    std::snprintf(formattedMessage, sizeof(formattedMessage), message, selfName, enemyName);

    wchar_t wideMessage[128];
    std::mbstowcs(wideMessage, formattedMessage, std::size(wideMessage));

    dGameDisplay_c::m_instance->newDeathMessage(
        wideMessage, daPyMng_c::mPlayerType[player->getPlrNo()]
    );
}
