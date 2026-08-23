// d_a_wm_2DPlayer.cpp
// NSMBW d_bases.text: 0x808C5100 - 0x808C7D10

#include "d_a_wm_2DPlayer.h"

#include "d_static/d_a_player/d_a_player_manager.h"

[[nsmbw(0x808C5690)]]
void da2DPlayer_c::calcPlayer()
{
    mVec3_c newScale = mBaseScale * 4.1;
    mVec3_c newPos = mPos;
    mScale = newScale;
    // Yellow/Blue Toad and Toadettes/Black/Orange Toad are scaled down slightly
    if ((mModelMng->mModel->mCharaID - 2) < 2 || mModelMng->mModel->mCharaID > 5) {
        mScale = newScale * 0.95;
    }
    newPos.y += mAddY;
    newPos.z = (mPos.z - mSubZ) + mAddZ;
    mModelMng->calc(newPos, mAngle, mScale);
    FUN_808C6EE0(0);
}

[[nsmbw(0x808C5990)]]
void da2DPlayer_c::loadPlayer()
{
    u32 id = mParam & 0xF;
    mPowerup = daPyMng_c::mPlayerMode[static_cast<PLAYER_TYPE_e>(id)];

    mModelMng = new dPyMdlMng_c(daPyMng_c::getPlayerTypeModelType(static_cast<PLAYER_TYPE_e>(id)));
    mModelMng->create(id, static_cast<u8>(mPowerup), dPyMdlMng_c::SceneType_c::SCENE_TYPE_2);

    mModelMng->mModel->setAnm(0, 1.2, 10.0, 0.0);
}

[[nsmbw(0x808C6EE0)]]
void da2DPlayer_c::FUN_808C6EE0(int);
