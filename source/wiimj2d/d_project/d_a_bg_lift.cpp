// d_a_bg_lift.cpp
// nsmbw-project

#include "d_a_bg_lift.h"
#include "d_player/d_a_player.h"
#include "d_system/d_bg.h"
#include "revolution/os/OSError.h"

dBaseActorProfile_s g_profile_AC_BG_LIFT{
  {{
    .mClassInit = []() -> fBase_c* { return new daBgLift_c(); },
    .mExecuteOrder = 412,
    .mDrawOrder = 523,
  }},
  .mActorProps = 0x4,
};

daBgLift_c::daBgLift_c()
{
}

daBgLift_c::~daBgLift_c()
{
    mPanelObj.~dPanelObjList_c();
}

/**
 * VT+0x08
 * do method for the create operation.
 */
fBase_c::PACK_RESULT_e daBgLift_c::create()
{
    // Assign members based on actor parameters
    mTileNum = mParam & 0xFFFF;

    // Used block, placeholder
    mTileNum = 0x32;

    // Initialize the tile renderer
    dPanelObjMgr_c* panelObjMgr = dBg_c::m_bg_p->getPanelObjMgr(0);
    panelObjMgr->addPanelObjList(&mPanelObj);

    mPanelObj.mPos.x = mPos.x - 8;
    mPanelObj.mPos.y = -(8 + mPos.y);
    mPanelObj.mTileNumber = mTileNum;

    return fBase_c::PACK_RESULT_e::SUCCEEDED;
}

/**
 * VT+0x14
 * do method for the delete operation. This method was renamed due to conflict with the delete
 * C++ keyword.
 */
fBase_c::PACK_RESULT_e daBgLift_c::doDelete()
{
    //  Remove tile renderer
    dPanelObjMgr_c* panelObjMgr = dBg_c::m_bg_p->getPanelObjMgr(0);
    panelObjMgr->removePanelObjList(&mPanelObj);

    return fBase_c::PACK_RESULT_e::SUCCEEDED;
}

/**
 * VT+0x20
 * do method for the execute operation.
 */
fBase_c::PACK_RESULT_e daBgLift_c::execute()
{
    mStateMgr.executeState();

    // Update the tile renderer
    mPanelObj.setPos(mPos.x - 8, -(8 + mPos.y), mPos.z);
    mPanelObj.setScaleFoot(mScale.x);

    return fBase_c::PACK_RESULT_e::SUCCEEDED;
}

/**
 * VT+0x5C
 * Code to be executed after all actors' execute operation has run.
 */
void daBgLift_c::finalUpdate()
{
    if (isState(StateID_Carry)) {
        mPos = calcCarryPos(mCarryOffset);
    }
}

void daBgLift_c::setSpinLiftUpActor(dActor_c* actor)
{
    mCarryNo = *actor->getPlrNo();
    mCarryOffset.y = 4.0f;
    OS_REPORT("fucker test!!!!\n");
    changeState(StateID_Carry);
}

mVec3_c daBgLift_c::calcCarryPos(const mVec3_c& offset)
{
    dAcPy_c* player = daPyMng_c::getPlayer(mPlayerNo);
    if (player->isStatus(4)) {
        return mPos;
    }
    mMtx_c mtx = player->getCarryMtx();
    mMtx_c transposeMtx = mMtx_c::createTrans(offset);
    mVec3_c res;
    mtx.concat(transposeMtx).multVecZero(res);
    return res;
}

void daBgLift_c::initializeState_Carry()
{
    mPlayerNo = mCarryNo;
    dAcPy_c* player = daPyMng_c::getPlayer(mCarryNo);
    mAmiLayer = player->mAmiLayer;

    // mCcOffsetX = mCc.mCcData.mOffset.x;
    // mCcOffsetY = mCc.mCcData.mOffset.y;
    // mCcWidth = mCc.mCcData.mSize.x;
    // mCcHeight = mCc.mCcData.mSize.y;
    // mCc.mAmiLine = l_Ami_Line[mAmiLayer];
    // mBc.mAmiLine = l_Ami_Line[mAmiLayer];
    // mCc.mCcData.mVsKind |= BIT_FLAG(CC_KIND_KILLER) | BIT_FLAG(CC_KIND_BALLOON);
    // mCc.mCcData.mAttack = CC_ATTACK_SHELL;
    // mRc.setRide(nullptr);
    mActorProperties &= ~0x2;
}

void daBgLift_c::finalizeState_Carry()
{
    dAcPy_c* player = daPyMng_c::getPlayer(mCarryNo);
    player->cancelCarry(this);
    // mCc.mCcData.mVsKind &= ~BIT_FLAG(CC_KIND_KILLER);
    // mCc.mCcData.mAttack = CC_ATTACK_NONE;
    // mCc.mCcData.mOffset.set(mCcOffsetX, mCcOffsetY);
    // mCc.mCcData.mSize.set(mCcWidth, mCcHeight);
    // mRc.setRide(nullptr);
    // mBc.mFlags = 0;
    mCarryingFlags &= ~(CARRY_RELEASE | CARRY_THROW);
    mActorProperties |= 0x2;
}

void daBgLift_c::executeState_Carry()
{
    if (mCarryingFlags & CARRY_RELEASE) {
        mDirection = mThrowDirection;
        changeState(StateID_Throw);
    }
    // updateCarryCc();
}

void daBgLift_c::initializeState_Throw()
{
}

void daBgLift_c::finalizeState_Throw()
{
}

void daBgLift_c::executeState_Throw()
{
}