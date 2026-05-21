// d_a_chukan_point.cpp
// NSMBW d_bases.text: 0x807E2040 - 0x807E38A0

#include "d_a_chukan_point.h"

#include "d_bases/d_s_stage.h"
#include "d_player/d_a_player.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_cyuukan.h"
#include "d_system/d_flag_ctrl.h"
#include "d_system/d_info.h"

[[nsmbw(0x807E2710)]]
void daChukanPoint_c::setCyuukanData() {
    mPlrNo              = -1;

    dScStage_c* scene   = dScStage_c::m_instance;
    dCyuukan_c* cyuukan = &dInfo_c::m_instance->mCyuukan;
    WORLD_e     world   = scene->mWorld;
    STAGE_e     stage   = scene->mStage;
    u8          course  = scene->mCourse;
    int         index   = mParam & 1;

    if (cyuukan->isCyuukanStart(index, world, stage)) {
        mPlrNo = cyuukan->getPlrNo(index);
    } else {
        u16 data = dFlagCtrl_c::m_instance->getFlagData(course, mPos.x, mPos.y);
        if (data > 1 && data < PLAYER_COUNT + 1) {
            mPlrNo = static_cast<s8>(data);
        }
    }

    float frame = 0.0f;
    if (mPlrNo >= 0) {
        frame = daPyMng_c::getPlayerColorType(daPyMng_c::mPlayerType[mPlrNo]) + 1;
        dFlagCtrl_c::m_instance->setFlagData(course, mPos.x, mPos.y, static_cast<u16>(mPlrNo) + 1);
    }

    m_model.setAnm(m_anmTexPat, 0.0f);
    m_anmTexPat.setFrame(frame, 0);
}
