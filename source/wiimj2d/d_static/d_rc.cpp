// d_rc.cpp
// NSMBW .text: 0x800D9950 - 0x800DBDB0

#include "d_rc.h"

#include "d_actor.h"

[[nsmbw_data(0x8042A2F0)]]
float dRc_c::mSavePosY;

[[nsmbw_data(0x8042A2F4)]]
dRide_ctr_c* dRc_c::mRideLast;

[[nsmbw_data(0x8042A2FC)]]
dRide_ctr_c* dRide_ctr_c::mEntryN;

[[nsmbw_data(0x8042A300)]]
dRide_ctr_c* dRide_ctr_c::mEntryB;

[[nsmbw_data(0x80371B10)]]
decltype(dRc_c::_rideCheck) dRc_c::_rideCheck;

[[nsmbw(0x800D9A30)]]
bool dRc_c::check(
    u32 param1, u32 param2, u32 param3
) {
    mSavePosY = -10000.0;
    mRideLast = mRide[0];
    mRide[0] = mRide[1]          = nullptr;

    const u8        execStopFlag = dActor_c::mExecStop & 8;

    const auto      fn           = _rideCheck;
    dActor_c* const owner        = mOwner;

    for (auto* ctr = dRide_ctr_c::mEntryN; ctr != nullptr; ctr = ctr->mNext) {
        if (owner && ctr->mOwner && owner->checkNoCollide(ctr->mOwner)) {
            continue;
        }

        if ((this->*fn)(ctr, param1, param2, param3)) {
            if (execStopFlag == 0 ||
                (ctr->mOwner != nullptr && (execStopFlag & ctr->mOwner->mExecStopMask) == 0)) {
                mRide[1] = ctr;
            }
        }
    }
    return mRide[1] != nullptr;
}

[[nsmbw(0x800D9BC0)]]
void dRc_c::chkLink();

[[nsmbw(0x800DB220)]]
dRideRoll_c::dRideRoll_c();

// Moved from d_lift_remocon_main.o (weak)
[[nsmbw(0x80044400)]]
dRideRoll_c::~dRideRoll_c();
