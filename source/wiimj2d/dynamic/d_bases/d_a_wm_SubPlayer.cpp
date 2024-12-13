// d_a_wm_SubPlayer.cpp
// NSMBW d_bases.text: 0x808E8AA0 - 0x808EF8D0

#include "d_a_wm_SubPlayer.h"

#include <dynamic/d_bases/d_a_wm_player.h>

[[address(0x808EE0C0)]]
s32 daWmSubPlayer_c::getPlayerOrder()
{
    s32 order = 1;
    s32 playerNo = getPlayerNo();
    dWmPlayerBase_c* player = daWmPlayer_c::ms_instance->mNextPlayer;

    for (s32 i = 0; i < playerNo; i++) {
        if (player->mVisible) {
            order++;
        }

        player = player->mNextPlayer;
    }

    return order;
}