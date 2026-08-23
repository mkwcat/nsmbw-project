// d_a_lift_remocon_balance.cpp
// NSMBW d_bases.text: 0x8083C020 - 0x8083EAF0

#include "d_a_lift_remocon_balance.h"

#include "d_static/d_a_player/d_a_player_base.h"
#include <mkwcat/VTable.hpp>

[[nsmbw(0x8083C020)]]
fBase_c* daRemoconBalance_c_classInit() {
    return new daRemoconBalance_c;
}

daRemoconBalance_c::daRemoconBalance_c() {
    mkwcat::VTable::Fix<fBase_c>(this);
}

[[nsmbw(0x8083C140)]]
daRemoconBalance_c::nodeCallbackA_c::~nodeCallbackA_c() {}

[[nsmbw(0x8083C180)]]
daRemoconBalance_c::nodeCallbackB_c::~nodeCallbackB_c() {}

[[nsmbw(0x8083CA80)]]
void daRemoconBalance_c::nodeCallbackA_c::timingA(u32, nw4r::g3d::ChrAnmResult*, nw4r::g3d::ResMdl);

[[nsmbw(0x8083CC50)]]
void daRemoconBalance_c::nodeCallbackB_c::timingA(u32, nw4r::g3d::ChrAnmResult*, nw4r::g3d::ResMdl);

[[nsmbw(0x8083D380)]]
void daRemoconBalance_c::FUN_8083D380() {
    bool isRide[PLAYER_COUNT] = {};
    for (dRc_c* rc = mRideRoll.mpChain; rc != nullptr; rc = rc->mpNext) {
        if (rc->mpOwner == nullptr) {
            continue;
        }
        if (daPlBase_c* player = rc->mpOwner->DynamicCast<daPlBase_c>()) {
            if (const s8& plrNo = player->getPlrNo(); plrNo != -1) {
                isRide[plrNo] = true;
            }
        }
    }

    bool change = false;
    for (int plr = 0; plr < PLAYER_COUNT; plr++) {
        if (m_0x618[plr] != isRide[plr]) {
            m_0x618[plr] = isRide[plr];
            change       = true;
        }
    }

    if (change) {
        m_RotShake.m_angle0 = m_RotShake.m_angle7;
    }
}
