// d_a_bg_lift.cpp
// nsmbw-project

#include "d_a_bg_carry.h"
#include "d_player/d_a_player.h"
#include "d_system/d_a_player_base.h"
#include "d_system/d_bg.h"
#include "d_system/d_mj2d_game.h"

void daBgCarry_c::callBackF(dActor_c* self, dActor_c* other)
{
    if (other->mKind == ACTOR_TYPE_e::PLAYER) {
        daPlBase_c* player = (daPlBase_c*) other;
        player->setStatus5D(self->mPosDelta.x);
        if (self->mPosDelta.y <= 0.0f) {
            player->UNDEF_80056370(self, 9);
        } else {
            player->UNDEF_80056370(self, 1);
        }
    }
}

void daBgCarry_c::callBackH(dActor_c* self, dActor_c* other)
{
    if (other->mKind == ACTOR_TYPE_e::PLAYER) {
        daPlBase_c* player = (daPlBase_c*) other;
        if (self->mPosDelta.y < 0.0f) {
            player->UNDEF_80056370(self, 2);
        } else {
            player->UNDEF_80056370(self, 10);
        }
    }
}

void daBgCarry_c::callBackW(dActor_c* self, dActor_c* other, u8 direction)
{
    if (other->mKind == ACTOR_TYPE_e::PLAYER) {
        daPlBase_c* player = (daPlBase_c*) other;
        if (direction == 1) {
            if (self->mPosDelta.x > 0.f) {
                player->UNDEF_80056370(self, 6);
            } else {
                player->UNDEF_80056370(self, 12);
            }
        } else {
            if (self->mPosDelta.x < 0.0f) {
                player->UNDEF_80056370(self, 5);
            } else {
                player->UNDEF_80056370(self, 11);
            }
        }
    }
}

bool daBgCarry_c::checkRevFoot(dActor_c* self, dActor_c* other)
{
    return self->mPosDelta.y > 0.0f;
}

bool daBgCarry_c::checkRevHead(dActor_c* self, dActor_c* other)
{
    return self->mPosDelta.y < 0.0f;
}

bool daBgCarry_c::checkRevWall(dActor_c* self, dActor_c* other, u8 direction)
{
    if (direction == 0) {
        return self->mPosDelta.x < 0.0f;
    } else {
        return self->mPosDelta.x > 0.0f;
    }
}

dBaseActorProfile_s g_profile_AC_BG_CARRY{
  {{
    .mClassInit = []() -> fBase_c* { return new daBgCarry_c(); },
    .mExecuteOrder = 412,
    .mDrawOrder = 523,
  }},
  .mActorProps = 0x4,
};

const sBcSensorPoint l_bgcarry_foot = {{0}, 0, -0x8000};
const sBcSensorPoint l_bgcarry_head = {{0}, 0, 0x8000};
const sBcSensorLine l_bgcarry_wall = {{1}, -0x5000, 0x5000, 0x8000};

sBgSetInfo l_bgcarry_bgc_info = {
  mVec2_c(-8, 8), mVec2_c(8, -8), &daBgCarry_c::callBackF, &daBgCarry_c::callBackH,
  &daBgCarry_c::callBackW
};

daBgCarry_c::daBgCarry_c()
{
}

daBgCarry_c::~daBgCarry_c()
{
    mPanelObj.~dPanelObjList_c();
    mBg.~dBg_ctr_c();
}

/**
 * VT+0x08
 * do method for the create operation.
 */
fBase_c::PACK_RESULT_e daBgCarry_c::create()
{
    // Assign members based on actor parameters
    mTileNum = mParam & 0xFFFF;

    // Initialize the tile renderer
    dPanelObjMgr_c* panelObjMgr = dBg_c::m_bg_p->getPanelObjMgr(0);
    panelObjMgr->addPanelObjList(&mPanelObj);

    mPanelObj.mPos.x = mPos.x - 8;
    mPanelObj.mPos.y = -(8 + mPos.y);
    mPanelObj.mTileNumber = mTileNum;

    // Tile sensors
    mBc.set(this, l_bgcarry_foot, l_bgcarry_head, l_bgcarry_wall);

    // Surface collider
    mBg.set(this, &l_bgcarry_bgc_info, 3, mLayer, nullptr);
    mBg.mFlags = 0x260;

    mBg.mBelowCheckFunc = &daBgCarry_c::checkRevFoot;
    mBg.mAboveCheckFunc = &daBgCarry_c::checkRevHead;
    mBg.mAdjCheckFunc = &daBgCarry_c::checkRevWall;

    mBg.mBelowCallback = &daBgCarry_c::callBackF;
    mBg.mAboveCallback = &daBgCarry_c::callBackH;
    mBg.mAdjCallback = &daBgCarry_c::callBackW;

    mBg.entry();

    // Set y acceleration and max speed for gravity
    mAccelY = -0.1875f;
    mSpeedMax.y = -4.0f;

    return fBase_c::PACK_RESULT_e::SUCCEEDED;
}

/**
 * VT+0x14
 * do method for the delete operation. This method was renamed due to conflict with the delete
 * C++ keyword.
 */
fBase_c::PACK_RESULT_e daBgCarry_c::doDelete()
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
fBase_c::PACK_RESULT_e daBgCarry_c::execute()
{
    mStateMgr.executeState();

    return fBase_c::PACK_RESULT_e::SUCCEEDED;
}

/**
 * VT+0x5C
 * Code to be executed after all actors' execute operation has run.
 */
void daBgCarry_c::finalUpdate()
{
    if (isState(StateID_Carry)) {
        mPos = calcCarryPos(mCarryOffset);

        dAcPy_c* player = daPyMng_c::getPlayer(mCarryNo);
        if (player->mPlayerMode == PLAYER_MODE_e::MINI_MUSHROOM) {
            mPos.z += 50.0f;
        }
    }

    // Update the tile renderer
    mPanelObj.setPos(mPos.x - 8, -(8 + mPos.y), mPos.z);
    mPanelObj.setScaleFoot(mScale.x);

    mBg.calc();
}

void daBgCarry_c::setSpinLiftUpActor(dActor_c* actor)
{
    mCarryNo = *actor->getPlrNo();
    mCarryOffset.y = 4.0f;
    mBg.mpCarryingActor = actor;
    changeState(StateID_Carry);
}

mVec3_c daBgCarry_c::calcCarryPos(const mVec3_c& offset)
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

void daBgCarry_c::placeTile()
{
    deleteActor(1);

    // Create empty block tile
    u16 worldX = ((u16) mPos.x) & 0xFFF0;
    u16 worldY = ((u16) - (mPos.y)) & 0xFFF0;

    dBg_c::m_bg_p->BgUnitChange(worldX, worldY, mLayer, mTileNum | 0x8000);
}

void daBgCarry_c::initializeState_Carry()
{
    mPlayerNo = mCarryNo;
    dAcPy_c* player = daPyMng_c::getPlayer(mCarryNo);
    mAmiLayer = player->mAmiLayer;
    mActorProperties &= ~0x2;
}

void daBgCarry_c::finalizeState_Carry()
{
    dAcPy_c* player = daPyMng_c::getPlayer(mCarryNo);
    player->cancelCarry(this);
    mCarryingFlags &= ~(CARRY_RELEASE | CARRY_THROW);
    mActorProperties |= 0x2;
}

void daBgCarry_c::executeState_Carry()
{
    if (mCarryingFlags & CARRY_RELEASE) {
        mDirection = mThrowDirection;
        changeState(StateID_Throw);
    }
}

float l_bgcarry_throw_speeds[2] = {2.5, -2.5};

void daBgCarry_c::initializeState_Throw()
{
    dAcPy_c* player = daPyMng_c::getPlayer(mCarryNo);
    float xSpeed = 0.0;
    if (player != nullptr) {
        xSpeed = l_bgcarry_throw_speeds[mDirection] + player->mSpeed.x * 0.75;
    }
    mSpeed.set(xSpeed, -1.5, 0.0);

    mBg.mpCarryingActor = nullptr;
    mBg.release();
}

void daBgCarry_c::finalizeState_Throw()
{
}

void daBgCarry_c::executeState_Throw()
{
    calcSpeedY();
    posMove();

    if (mBc.checkFoot() || mBc.checkHead(0) || mBc.checkWall(0)) {
        placeTile();
    }
}