// d_a_lift_remocon_main.cpp
// NSMBW .text: 0x800437D0 - 0x80044460

#include "d_a_lift_remocon_main.h"

#include "d_system/d_a_player_base.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_actor.h"
#include <revolution/os/OSError.h>

[[nsmbw(0x800440C0)]]
u8 daLiftRemoconMain_c::PlayerNoRideCheck(u8 playerMask);

[[nsmbw(0x800441E0)]]
u8 daLiftRemoconMain_c::UpdateControlPlayerNo(u8* rideCheck)
{
    if (mpControlPlayerTimer == nullptr) {
        mpControlPlayerTimer = new s8[PLAYER_COUNT];
        ASSERT(mpControlPlayerTimer != nullptr);
        for (int i = 0; i < PLAYER_COUNT; i++) {
            mpControlPlayerTimer[i] = 0;
        }
    }

    u32 playerMask = 0;

    for (dRc_c* chain = mRideRoll.mpChain; chain != nullptr; chain = chain->mpNext) {
        dActor_c* actor = chain->mpOwner;
        if (actor == nullptr || (actor->mKind != dActor_c::ACTOR_TYPE_e::PLAYER &&
                                 actor->mKind != dActor_c::ACTOR_TYPE_e::YOSHI)) {
            continue;
        }

        daPlBase_c* player = static_cast<daPlBase_c*>(actor);
        if (player == nullptr || player->isItemKinopio()) {
            continue;
        }

        if (player->isStatus(69)) {
            continue;
        }

        player->onStatus(92);
        playerMask |= 1 << player->getPlrNo();
        mpControlPlayerTimer[player->getPlrNo()] = 40;
    }

    for (u32 i = 0, b = 0b1; i < PLAYER_COUNT; i++, b <<= 1) {
        if (mpControlPlayerTimer[i] != 0) {
            mpControlPlayerTimer[i]--;
        }

        if (!(playerMask & b) && mpControlPlayerTimer[i] != 0) {
            playerMask |= b;
        }
    }

    *rideCheck = PlayerNoRideCheck(playerMask);
    return playerMask;
}