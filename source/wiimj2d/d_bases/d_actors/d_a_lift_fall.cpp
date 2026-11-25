// d_a_lift_fall.cpp
// NSMBW d_bases.text: 0x80837370 - 0x80838020

#include "d_a_lift_fall.h"

#include "d_a_ice.h"
#include "d_a_player.h"
#include "d_a_yoshi.h"
#include <algorithm>

[[nsmbw(0x808377B0)]]
bool daLiftFall_c::checkRideStart() const {
    int count = 0;
    for (dRc_c* rc = mRc.mChain; rc != nullptr; rc = rc->mNext) {
        dActor_c* actor = rc->mOwner;
        if (!actor) {
            continue;
        }

        if (auto* player = actor->DynamicCast<dAcPy_c>()) {
            count++;
            if (player->getCarryPlayer()) {
                count++;
            }
        } else if (auto* yoshi = actor->DynamicCast<daYoshi_c>()) {
            if (yoshi->mEatStage != 0) {
                count++;
            }
        } else if (auto* ice = actor->DynamicCast<daIce_c>()) {
            if (ice->checkPlAttach_Head(nullptr)) {
                count++;
            }
        }
    }

    int minPlr = (mParam >> 12) & 0xF;
    if (minPlr == 0) {
        // Just enforce one player minimum instead of 25%
        minPlr = 1;
    } else {
        // Multiply by 16-bit reciprocal
        // 1 = 50%
        // 2 = 75%
        // 3 = 100%
        u32 r  = (minPlr + 1) * 0x4000;
        minPlr = s16((r * daPyMng_c::getEntryNum()) >> 16);
        minPlr = std::max(minPlr, 1);
    }

    return count >= minPlr;
}
