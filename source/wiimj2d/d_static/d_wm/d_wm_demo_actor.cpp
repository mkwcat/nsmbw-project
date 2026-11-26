// d_wm_demo_actor.cpp
// NSMBW .text: 0x800F60E0 - 0x800F7050

#include "d_wm_demo_actor.h"

[[nsmbw(0x800F60E0)]]
dWmDemoActor_c::dWmDemoActor_c();

[[nsmbw(0x800F61C0)]]
void dWmDemoActor_c::VT_0x60();

[[nsmbw(0x800F61E0)]]
void dWmDemoActor_c::setCutEnd();

[[nsmbw(0x800F64A0)]]
bool dWmDemoActor_c::procJumpBase() {
    calcSpeed();
    posMove();

    // Original check waited until the actor crossed above the target and then fell back below it,
    // but that can sometimes miss. This checks if the actor is below the target and moving downward

    const mVec3_c& t = mTargetPos;
    if (mPos.y > t.y || mSpeed.y > 0.0f) {
        return false;
    }

    // Landed
    mPos = mTargetPos;
    return true;
}

[[nsmbw(0x800F6820)]]
void dWmDemoActor_c::CreateShadowModel(
    const char* param1, const char* param2, const char* param3, bool param4
);

[[nsmbw(0x800F6EE0)]]
void dWmDemoActor_c::clearCutEnd();

[[nsmbw(0x800F6EF0)]]
bool dWmDemoActor_c::checkCutEnd();

[[nsmbw(0x800F6F40)]]
dWmDemoActor_c::~dWmDemoActor_c();

[[nsmbw(0x800F6F10)]]
fBase_c::PACK_RESULT_e dWmDemoActor_c::doDelete();

[[nsmbw(0x800F6F20)]]
fBase_c::PACK_RESULT_e dWmDemoActor_c::draw();

[[nsmbw(0x800F6F30)]]
fBase_c::PACK_RESULT_e dWmDemoActor_c::create();
