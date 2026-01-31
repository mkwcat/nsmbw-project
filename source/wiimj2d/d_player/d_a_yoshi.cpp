// d_a_yoshi.cpp
// NSMBW .text: 0x8014B400 - 0x80154800

#include "d_a_yoshi.h"

#include "d_bases/d_s_stage.h"
#include "d_system/d_a_player_manager.h"

/* VT+0x0DC */
[[nsmbw(0x80150E10)]]
void daYoshi_c::executeLastAll()
{
    if (!isStatus(1)) {
        return;
    }

    setHitTongueReserve();
    calcHeadAttentionAngle();
    mModelMng.calc2();

    if (dScStage_c::isGameStopAllowed()) {
        if (isStatus(198)) {
            offStatus(198);
            stopOther();
            daPyMng_c::mStopTimerInfo |= 1 << mPlrNo;
        }

        if (isStatus(199)) {
            offStatus(199);
            playOther();
            daPyMng_c::mStopTimerInfo &= ~(1 << mPlrNo);
        }
    }
}

[[nsmbw(0x80150420)]]
void daYoshi_c::setHitTongueReserve();