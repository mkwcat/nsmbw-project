// d_a_en_hatena_balloon.cpp
// NSMBW .text: 0x801102B0 - 0x80114C00

#include "d_a_en_hatena_balloon.h"

#include "d_enemies/d_a_en_item.h"
#include "d_player/d_a_player.h"
#include "d_system/d_actor_mng.h"
#include "d_system/d_audio.h"
#include "d_system/d_balloon_mng.h"
#include "d_system/d_quake.h"
#include "d_system/d_resource_mng.h"
#include "framework/f_feature.h"
#include "framework/f_param.h"
#include "machine/m_3d_fanm.h"
#include "machine/m_heap.h"
#include "machine/m_vec.h"
#include "sound/SndID.h"

[[nsmbw(0x80110DE0)]]
void daEnHatenaBalloon_c::PlYsHitCheck(dActor_c* actor, daEnHatenaBalloon_c* balloon);

[[nsmbw(0x80111990)]]
void daEnHatenaBalloon_c::model_set()
{
    mAllocator.createFrmHeap(-1, mHeap::g_gameHeaps[0], nullptr, 32);
    mResFile = dResMng_c::m_instance->mRes.getRes("balloon", "g3d/balloon.brres");

    nw4r::g3d::ResMdl resMdl = mResFile.GetResMdl("balloon");
    mModel.create(resMdl, &mAllocator, 32, 1, nullptr);
    mModel.setPriorityDraw(-1, 0x98);

    nw4r::g3d::ResAnmChr floatResAnmChr = mResFile.GetResAnmChr("float");
    mAnmChr.create(resMdl, floatResAnmChr, &mAllocator, 0);
    mAnmChr.setAnm(mModel, floatResAnmChr, m3d::PLAY_MODE_0);
    mModel.setAnm(mAnmChr, 1.0f);

    nw4r::g3d::ResAnmTexSrt floatResAnmTexSrt = mResFile.GetResAnmTexSrt("float");
    mAnmTexSrt.create(resMdl, floatResAnmTexSrt, &mAllocator, nullptr, 1);
    mAnmTexSrt.setAnm(mModel, floatResAnmTexSrt, 0, m3d::PLAY_MODE_0);
    mModel.setAnm(mAnmTexSrt, 1.0f);

    nw4r::g3d::ResAnmTexPat balloonResAnmTexPat = mResFile.GetResAnmTexPat("balloon");
    mAnmTexPat.create(resMdl, balloonResAnmTexPat, &mAllocator, nullptr, 1);
    mAnmTexPat.setAnm(mModel, balloonResAnmTexPat, 0, m3d::PLAY_MODE_1);
    mModel.setAnm(mAnmTexPat, 1.0f);

    float frame = 0.0f;
    if (dActorMng_c::m_instance->envAllWaterCheck()) {
        frame = 1.0f;
    }
    mAnmTexPat.setFrame(frame, 0);
    mAnmTexPat.setRate(0.0f, 0);

    resMdl = mResFile.GetResMdl("balloon_back");
    mModelBack.create(resMdl, &mAllocator, 32, 1, nullptr);

    nw4r::g3d::ResAnmChr floatBackResAnmChr = mResFile.GetResAnmChr("float_back");
    mAnmChrBack.create(resMdl, floatBackResAnmChr, &mAllocator, 0);
    mAnmChrBack.setAnm(mModelBack, floatBackResAnmChr, m3d::PLAY_MODE_0);
    mModelBack.setAnm(mAnmChrBack, 1.0f);

    nw4r::g3d::ResAnmTexPat balloonBackResAnmTexPat = mResFile.GetResAnmTexPat("balloon_back");
    mAnmTexPatBack.create(resMdl, balloonBackResAnmTexPat, &mAllocator, nullptr, 1);
    mAnmTexPatBack.setAnm(mModelBack, balloonBackResAnmTexPat, 0, m3d::PLAY_MODE_1);
    mModelBack.setAnm(mAnmTexPatBack, 1.0f);

    frame = 0.0f;
    if (dActorMng_c::m_instance->envAllWaterCheck()) {
        frame = 1.0f;
    }
    mAnmTexPatBack.setFrame(frame, 0);
    mAnmTexPatBack.setRate(0.0f, 0);

    if (mHasItem) {
        const char* itemModelName = "I_kinoko";
        const char* itemModelResName = "g3d/I_kinoko.brres";

        nw4r::g3d::ResFile itemResFile =
          dResMng_c::m_instance->mRes.getRes(itemModelName, itemModelResName);
        nw4r::g3d::ResMdl itemResMdl = itemResFile.GetResMdl(itemModelName);
        mItemModel.create(itemResMdl, &mAllocator, 32, 1, nullptr);
        dActor_c::setSoftLight_Item(mItemModel);

        nw4r::g3d::ResAnmChr itemResAnmChr = itemResFile.GetResAnmChr("wait");
        mItemAnmChr.create(itemResMdl, itemResAnmChr, &mAllocator, 0);
        mItemAnmChr.setAnm(mItemModel, itemResAnmChr, m3d::PLAY_MODE_0);
        mItemModel.setAnm(mItemAnmChr);
        mItemAnmChr.setRate(0.5f);

        ITEM_e itemType = static_cast<ITEM_e>(fParam_c<daEnHatenaBalloon_c>(mParam).item_type);
        if (itemType == ITEM_e::ONE_UP) {
            nw4r::g3d::ResAnmTexPat itemResAnmTexPat =
              itemResFile.GetResAnmTexPat("I_kinoko_switch");
            mItemAnmTexPat.create(itemResMdl, itemResAnmTexPat, &mAllocator, nullptr, 1);
            mItemAnmTexPat.setAnm(mItemModel, itemResAnmTexPat, 0, m3d::PLAY_MODE_1);
            mItemModel.setAnm(mItemAnmTexPat);
            mItemAnmTexPat.setFrame(1.0f, 0);
            mItemAnmTexPat.setRate(0.0f, 0);
        }
    }

    mAllocator.adjustFrmHeap();
}

[[nsmbw(0x80111EC0)]]
void daEnHatenaBalloon_c::anm_set(int);

[[nsmbw(0x80112110)]]
void daEnHatenaBalloon_c::createItem()
{
    u32 type = 8; // Mushroom
    if (fParam_c<daEnHatenaBalloon_c>(mParam).item_type == static_cast<u32>(ITEM_e::ONE_UP)) {
        type = 7; // 1-Up
    }

    if (dActor_c* item = dActor_c::construct(
          dProf::EN_ITEM, fParam_c<daEnItem_c>({.create_type = 7, .type = type}),
          (const mVec3_c[1]) {{mPos.x, mPos.y + 8.0f, 600.0f}}, nullptr, 0
        )) {
        dBalloonMng_c::m_instance->setItemId(item->mUniqueID);
    }
    dBalloonMng_c::m_instance->mCreateTimer = 0;

    dAudio::g_pSndObjMap->startSound(
      SndID::SE_OBJ_CMN_BALLOON_BREAK, dAudio::cvtSndObjctPos(mPos), 0
    );

    if (fFeat::bubble_swarm_mode && dBalloonMng_c::mNoCloneTimer == 0) {
        dBalloonMng_c::m_instance->mSwarmTimer = 1;
        dBalloonMng_c::m_instance->createSwarmBalloon();
        dBalloonMng_c::m_instance->createSwarmBalloon();
    }
}

[[nsmbw(0x80113090)]]
void daEnHatenaBalloon_c::remocon_speed_set();

[[nsmbw(0x80113400)]]
void daEnHatenaBalloon_c::remocon_times_check();

[[nsmbw(0x801134F0)]]
void daEnHatenaBalloon_c::remocon_shake_check()
{
    if (mHasItem && !fFeat::bubble_swarm_mode) {
        return;
    }

    if (m_shake_check_timer != 0) {
        m_shake_check_timer--;
        return;
    }

    if (mHasItem && fFeat::bubble_swarm_mode) {
        m_shake_check_timer = 30;
        m_countdown_anm = 31;
        anm_set(1);
        remocon_speed_set();
        return;
    }

    dAcPy_c* player = daPyMng_c::getPlayer(mPlayerNo);
    if (player == nullptr || !player->mKey.triggerShakeJump()) {
        return;
    }

    m_shake_check_timer = 30;
    m_countdown_anm = 31;
    remocon_times_check();
    dQuake_c::m_instance->shockMotor(
      mPlayerNo, dQuake_c::TYPE_SHOCK_e::PLAYER_BUBBLE_SHAKE, 0, false
    );
    player->setBalloonHelpVoice();
    anm_set(1);
    remocon_speed_set();
}