// d_a_mask.cpp
// NSMBW .text: 0x80124EB0 - 0x80126650

#include "d_a_mask.h"

#include "d_a_player.h"
#include "d_a_player_manager.h"
#include "d_a_yoshi.h"
#include "d_mj2d_game.h"

[[nsmbw(0x80126050)]]
daPlBase_c* daMask_c::GetPlayerP() {
    if (int no = getPlrAcNo(); no != -1) {
        return daPyMng_c::getPlayer(no);
    } else if (int no = getYoshiNo(); no != -1) {
        return daPyMng_c::getYoshiDirectP(no);
    }
    return nullptr;
}

[[nsmbw(0x801260B0)]]
bool daMask_c::isYoshi() {
    return mMaskPlrNo >= PLAYER_COUNT && mMaskPlrNo < PLAYER_COUNT * 2;
}
