// d_a_lift_ridemove.cpp
// NSMBW d_bases.text: 0x80845940 - 0x808468E0

#include "d_a_lift_ridemove.h"
#include "d_player/d_a_player.h"
#include "d_player/d_a_yoshi.h"

[[nsmbw(0x80845D60)]]
bool daLiftRideMove_c::isAllPlayerOnLift()
{
    int numPlayer = 0;

    for (dRc_c* rc = mRideRoll.mpChain; rc != nullptr; rc = rc->mpNext) {
        if (rc->mpOwner == nullptr) {
            continue;
        }

        if (dAcPy_c* player = rc->mpOwner->DynamicCast<dAcPy_c>()) {
            numPlayer++;

            if (player->getCarryPlayer()) {
                numPlayer++;
            }
        }

        if (daYoshi_c* yoshi = rc->mpOwner->DynamicCast<daYoshi_c>()) {
            if (yoshi->mEatStage != 0 && yoshi->getPlrNo() != -1) {
                numPlayer++;
            }
        }
    }

    if (numPlayer < daPyMng_c::mNum) {
        return numPlayer != 0 && (mParam & (1u << 28));
    }

    return daPyMng_c::mNum != 0;
}