// d_a_wm_SubPlayer.cpp
// NSMBW d_bases.text: 0x808E8AA0 - 0x808EF8D0

#include "d_a_wm_SubPlayer.h"

#include "d_bases/d_a_wm_Map.h"
#include "d_bases/d_a_wm_player.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_wm_player_base.h"
#include "machine/m_angle.h"
#include "machine/m_heap.h"
#include <mkwcat/Port.hpp>
#include <revolution/os.h>

/**
 * Copy of create.
 */
EXTERN_REPL(
  0x808EB220, //
  fBase_c::PACK_RESULT_e daWmSubPlayer_c::createSubPlayer()
);

/**
 * VT+0x08
 * do method for the create operation.
 */
[[nsmbw(0x808EB220)]]
fBase_c::PACK_RESULT_e daWmSubPlayer_c::create()
{
    createSubPlayer();

    mNodeTrail.alloc(16, mHeap::g_gameHeaps[0]);

    // Temporary(?) hack that makes the node reached check more generous
    *static_cast<float*>(mkwcat::Port<0x8093CE28>()) = 0.05f;

    return PACK_RESULT_e::SUCCEEDED;
}

[[nsmbw(0x808EB7D0)]]
void daWmSubPlayer_c::loadModel() ASM_METHOD(
  // clang-format off
/* 808EB7D0 9421FFE0 */  stwu     r1, -32(r1);
/* 808EB7D4 7C0802A6 */  mflr     r0;
/* 808EB7E0 90010024 */  stw      r0, 36(r1);
/* 808EB7EC 93E1001C */  stw      r31, 28(r1);
/* 808EB7F0 93C10018 */  stw      r30, 24(r1);
/* 808EB7F4 93A10014 */  stw      r29, 20(r1);
/* 808EB7F8 93810010 */  stw      r28, 16(r1);

/* 808EB7D8 3CA08035 */  lis      r5, scDefaultPlayerTypes__11dMj2dGame_c@ha;
/* 808EB7DC 3C808035 */  lis      r4, mPlayerMode__9daPyMng_c@ha;
/* 808EB7E4 38A55160 */  addi     r5, r5, scDefaultPlayerTypes__11dMj2dGame_c@l;
/* 808EB7FC 7C7C1B78 */  mr       r28, r3;

/* 808EB800 80030004 */  lwz      r0, 0x4(r3);
/* 808EB80C 541F073E */  clrlwi   r31, r0, 28;
/* 808EB808          */  clrlslwi r0, r0, 28, 2;
/* 808EB810          */  lwzx     r30, r5, r0;

/* 808EB804 3860000C */  li       r3, 0xC;
/* 808EB81C 4B9CDB35 */  bl       __nw__FUl;
/* 808EB820          */  mr.      r29, r3;
/* 808EB824 41820014 */  beq-     UNDEF_808eb838;

                         mr       r3, r30;
                         bl       getPlayerTypeModelType__9daPyMng_cF13PLAYER_TYPE_e;
                         mr       r4, r3;
                         mr       r3, r29;
/* 808EB834 4B7EB57D */  bl       __ct__11dPyMdlMng_cFQ211dPyMdlMng_c11ModelType_e;
UNDEF_808eb838:;
/* 808EB838 907C01CC */  stw      r3, 460(r28);
/* 808EB83C 7FE4FB78 */  mr       r4, r31;
                         slwi     r5, r30, 2;
                         addis    r5, r5, mPlayerMode__9daPyMng_c@ha;
                         lwz      r5, mPlayerMode__9daPyMng_c@l(r5);
/* 808EB840 57C5063E */  clrlwi   r5, r5, 24;
/* 808EB844 38C00001 */  li       r6, 1;
/* 808EB848 4B7EB699 */  bl       UNDEF_800d6ee0;
/* 808EB84C 38000015 */  li       r0, 21;
/* 808EB850 901C0290 */  stw      r0, 656(r28);
/* 808EB854 38600054 */  li       r3, 84;
/* 808EB858 4B9CDB39 */  bl       UNDEF_802b9390;
/* 808EB85C 907C028C */  stw      r3, 652(r28);
/* 808EB860 3BA00000 */  li       r29, 0;
/* 808EB864 3BC00000 */  li       r30, 0;
/* 808EB868 4800001C */  b        UNDEF_808eb884;
UNDEF_808eb86c:;
/* 808EB86C 3860000C */  li       r3, 12;
/* 808EB870 4B9CDAE1 */  bl       UNDEF_802b9350;
/* 808EB874 809C028C */  lwz      r4, 652(r28);
/* 808EB878 3BBD0001 */  addi     r29, r29, 1;
/* 808EB87C 7C64F12E */  stwx     r3, r4, r30;
/* 808EB880 3BDE0004 */  addi     r30, r30, 4;
UNDEF_808eb884:;
/* 808EB884 801C0290 */  lwz      r0, 656(r28);
/* 808EB888 7C1D0000 */  cmpw     r29, r0;
/* 808EB88C 4180FFE0 */  blt+     UNDEF_808eb86c;
/* 808EB890 3C808098 */  lis      r4, UNDEF_80985b28@ha;
/* 808EB894 3CA08098 */  lis      r5, UNDEF_80985b38@ha;
/* 808EB898 38845B28 */  addi     r4, r4, UNDEF_80985b28@l;
/* 808EB89C 7F83E378 */  mr       r3, r28;
/* 808EB8A0 7C862378 */  mr       r6, r4;
/* 808EB8A4 38A55B38 */  addi     r5, r5, UNDEF_80985b38@l;
/* 808EB8A8 38E00001 */  li       r7, 1;
/* 808EB8AC 4B80AF75 */  bl       CreateShadowModel__14dWmDemoActor_cFPCcPCcPCcb;
/* 808EB8B0 80010024 */  lwz      r0, 36(r1);
/* 808EB8B4 83E1001C */  lwz      r31, 28(r1);
/* 808EB8B8 83C10018 */  lwz      r30, 24(r1);
/* 808EB8BC 83A10014 */  lwz      r29, 20(r1);
/* 808EB8C0 83810010 */  lwz      r28, 16(r1);
/* 808EB8C4 7C0803A6 */  mtlr     r0;
/* 808EB8C8 38210020 */  addi     r1, r1, 32;
/* 808EB8CC 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x808EDC40)]]
void daWmSubPlayer_c::setWalkSpeed(f32 speed);

[[nsmbw(0x808EE0C0)]]
s32 daWmSubPlayer_c::getPlayerOrder()
{
    s32 order = 1;
    s32 playerNo = getPlayerNo();
    dWmPlayerBase_c* player = daWmPlayer_c::ms_instance->mNextPlayer;

    for (s32 i = 0; i < playerNo; i++) {
        if (player->mVisible) {
            order++;
        }

        player = player->mNextPlayer;
    }

    return order;
}

[[nsmbw(0x808EE110)]]
f32 daWmSubPlayer_c::getDistanceToAheadPlayer();

bool daWmSubPlayer_c::isPastAheadPlayer(float& distToNextNode)
{
    if (getPlayerOrder() == 1 || mToNode < 0) {
        return false;
    }

    dWmPlayerBase_c* base = getAheadPlayer();
    if (base == nullptr) {
        return false;
    }

    daWmSubPlayer_c* ahead = static_cast<daWmSubPlayer_c*>(base);

    if (ahead->mNodeTrail.mUsedCount > mNodeTrail.mUsedCount) {
        return true;
    }
    if (mToNode != ahead->mToNode) {
        return false;
    }

    mVec3_c toPos = daWmMap_c::m_instance->GetPos(mToNode);
    distToNextNode = mVec3_c::distance(mPos, toPos);
    return distToNextNode < mVec3_c::distance(ahead->mPos, toPos);
}

[[nsmbw(0x808EE200)]]
dWmPlayerBase_c* daWmSubPlayer_c::getAheadPlayer();

[[nsmbw(0x808EE620)]]
void daWmSubPlayer_c::calcWalkSpeed()
{
    f32 prevSpeedF = mSpeedF;

    bool ahead = false;
    f32 distToNextNode;
    if (isSubPlayerStopPoint()) {
        const float l_SPEED_FACTOR_ARR[] = {
          1.00, 0.75, 0.50, 0.25, 0.18, 0.145, 0.11, 0.09,
        };

        setWalkSpeed(l_SPEED_FACTOR_ARR[getPlayerOrder()]);
    } else if (mMoveDir != dWmLib::MovementDir_e::UP && mMoveDir != dWmLib::MovementDir_e::DOWN) {
        ahead = isPastAheadPlayer(distToNextNode);
        f32 distance;
        if (ahead || (distance = getDistanceToAheadPlayer()) < 40.0) {
            setWalkSpeed(0.1);
            mPrevSpeedMultiply = 2;
        } else if (distance < 70.0) {
            setWalkSpeed(0.75);
            mPrevSpeedMultiply = 2;
        } else if (distance > 84.0) {
            setWalkSpeed(1.2);
            mPrevSpeedMultiply = 1;
        } else {
            setWalkSpeed(1.0);
        }
    }

    // Ease into the new speed a bit
    if (!ahead || distToNextNode > 40.0) {
        mSpeedF = prevSpeedF * 0.9 + mSpeedF * 0.1;
    } else {
        mSpeedF = 0;
    }
}

[[nsmbw(0x808EE950)]]
int daWmSubPlayer_c::getSubPlayerNum();

[[nsmbw(0x808EE960)]]
f32 daWmSubPlayer_c::getPlayerOrderDistance()
{
    using FloatArray = f32[];

    return FloatArray{
      // 2 players
      0.0, 45.0,

      // 3 players
      0.0, 40.0, 40.0,

      // 4 players
      0.0, 40.0, 40.0, 50.0,

      // 5 players
      0.0, 40.0, 40.0, 40.0, 40.0,

      // 6 players
      0.0, 40.0, 45.0, 50.0, 45.0, 40.0,

      // 7 players
      0.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0,

      // 8 players
      0.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0
    }[getPlayerOrderTableIndex(getPlayerOrder())];
}

[[nsmbw(0x808EE9B0)]]
s16 daWmSubPlayer_c::getPlayerOrderAngle()
{
    using AngleArray = s16[];

    return AngleArray{
      // 2 players
      mAng::fromDegree(0.0),
      mAng::fromDegree(180.0),

      // 3 players
      mAng::fromDegree(0.0),
      mAng::fromDegree(137.33),
      mAng::fromDegree(-137.33),

      // 4 players
      mAng::fromDegree(0.0),
      mAng::fromDegree(126.343),
      mAng::fromDegree(-126.343),
      mAng::fromDegree(180.0),

      // 5 players
      mAng::fromDegree(0.0),
      mAng::fromDegree(-140.0),
      mAng::fromDegree(140.0),
      mAng::fromDegree(74.0),
      mAng::fromDegree(-74.0),

      // 6 players
      mAng::fromDegree(0.0),
      mAng::fromDegree(60.0),
      mAng::fromDegree(-120.0),
      mAng::fromDegree(120.0),
      mAng::fromDegree(-60.0),
      mAng::fromDegree(180.0),

      // 7 players
      mAng::fromDegree(0.0),
      mAng::fromDegree(-67.5),
      mAng::fromDegree(67.5),
      mAng::fromDegree(-112.5),
      mAng::fromDegree(112.5),
      mAng::fromDegree(-157.5),
      mAng::fromDegree(157.5),

      // 8 players
      mAng::fromDegree(0.0),
      mAng::fromDegree(45.0),
      mAng::fromDegree(-45.0),
      mAng::fromDegree(90.0),
      mAng::fromDegree(-90.0),
      mAng::fromDegree(135.0),
      mAng::fromDegree(-135.0),
      mAng::fromDegree(180.0),

    }[getPlayerOrderTableIndex(getPlayerOrder())];
}

[[nsmbw(0x808EEA00)]]
s32 daWmSubPlayer_c::getPlayerOrderTableIndex(int playerOrder)
{
    int subPlayerNum = getSubPlayerNum();
    if (subPlayerNum == 0) {
        return 0;
    }

    static constexpr s32 l_INDEX_TABLE[] = {0, 2, 5, 9, 14, 20, 27};

    return l_INDEX_TABLE[subPlayerNum - 1] + playerOrder;
}

[[nsmbw(0x808EEF00)]]
bool daWmSubPlayer_c::isWrongDirection(dWmLib::MovementDir_e dir1, dWmLib::MovementDir_e dir2);

[[nsmbw(0x808EEF70)]]
bool daWmSubPlayer_c::isSubPlayerStopPoint();

[[nsmbw(0x808EF2B0)]]
bool daWmSubPlayer_c::isPlayerType(PLAYER_TYPE_e playerType)
{
    return dMj2dGame_c::scDefaultPlayerTypes[getPlayerNo()] == playerType;
}

[[nsmbw(0x808EF2D0)]]
bool daWmSubPlayer_c::isPlayerStar()
{
    return static_cast<bool>(
      daPyMng_c::mCreateItem[daPyMng_c::mPlayerType[mModelManager->mModel->mPlayerNo]] &
      PLAYER_CREATE_ITEM_e::STAR_POWER
    );
}

[[nsmbw(0x808EF680)]]
daWmSubPlayer_c::NodeTrail_c::Node_s* daWmSubPlayer_c::NodeTrail_c::pushNext()
{
    if (mUsedCount >= mAllocCount) {
        if (mUsedCount > mAllocCount) {
            return nullptr;
        }

        // Automatically pop the oldest node
        popFirst();
    }

    return &mpNodes[(mFirstNode + mUsedCount++) % mAllocCount];
}

[[nsmbw(0x808EF6D0)]]
daWmSubPlayer_c::NodeTrail_c::Node_s* daWmSubPlayer_c::NodeTrail_c::popFirst();

/* VT+0x0C */
[[nsmbw(0x808EF730)]]
void daWmSubPlayer_c::NodeTrailBase_c::alloc(int count);

/* VT+0x10 */
[[nsmbw(0x808EF780)]]
void daWmSubPlayer_c::NodeTrailBase_c::alloc(int count, EGG::Heap* heap);
