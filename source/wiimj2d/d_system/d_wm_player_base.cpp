// d_wm_player_base.cpp
// NSMBW .text: 0x800FDC40 - 0x800FE140

#include "d_wm_player_base.h"

dWmPlayerBase_c::ACTOR_KIND_e dWmPlayerBase_c::GetActorType() {
    return ACTOR_KIND_e::ACTOR_MAP_PLAYER;
}

[[nsmbw(0x800FDE50)]]
void dWmPlayerBase_c::VT_0x78();

[[nsmbw(0x800FDE70)]]
void dWmPlayerBase_c::procDemoLose();

[[nsmbw(0x800FE020)]]
void dWmPlayerBase_c::VT_0x84();
