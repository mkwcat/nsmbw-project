// d_base_actor.cpp
// NSMBW .text: 0x8006C6D0 - 0x8006CF40

#include "d_base_actor.h"

#include "d_a_player.h"
#include "d_actor.h"

[[nsmbw(0x8006C6D0)]]
dBaseActor_c::dBaseActor_c();

[[nsmbw(0x8006C7F0)]]
dBaseActor_c::~dBaseActor_c();

[[nsmbw(0x8006C870)]]
fBase_c::PACK_RESULT_e dBaseActor_c::preCreate();

[[nsmbw(0x8006C8A0)]]
void dBaseActor_c::postCreate(fBase_c::MAIN_STATE_e status);

[[nsmbw(0x8006C8B0)]]
fBase_c::PACK_RESULT_e dBaseActor_c::preDelete();

[[nsmbw(0x8006C8E0)]]
void dBaseActor_c::postDelete(fBase_c::MAIN_STATE_e status);

[[nsmbw(0x8006C8F0)]]
fBase_c::PACK_RESULT_e dBaseActor_c::preExecute();

[[nsmbw(0x8006C980)]]
void dBaseActor_c::postExecute(fBase_c::MAIN_STATE_e status);

[[nsmbw(0x8006C9F0)]]
fBase_c::PACK_RESULT_e dBaseActor_c::preDraw();

[[nsmbw(0x8006CA40)]]
void dBaseActor_c::postDraw(fBase_c::MAIN_STATE_e status);

[[nsmbw(0x8006CA50)]]
void dBaseActor_c::draw2D();

[[nsmbw(0x8006CA60)]]
void dBaseActor_c::draw2D_lyt2();

[[nsmbw(0x8006CC00)]]
void dBaseActor_c::calcSpeed();

[[nsmbw(0x8006CD50)]]
void dBaseActor_c::calcSpeedXY();

[[nsmbw(0x8006CD90)]]
void dBaseActor_c::calcSpeedX();

[[nsmbw(0x8006CE70)]]
void dBaseActor_c::calcFallSpeed();

[[nsmbw(0x8006CDE0)]]
void dBaseActor_c::calcSpeedY();

[[nsmbw(0x8006CE10)]]
void dBaseActor_c::calcSpeedF();

[[nsmbw(0x8006CCB0)]]
void dBaseActor_c::makeMtx();

[[nsmbw(0x8006CED0)]]
mVec3_c dBaseActor_c::getCenterPos() const;

[[nsmbw(0x8006CD00)]]
void dBaseActor_c::posMove(mVec3_c& delta);

[[nsmbw(0x8006CD40)]]
void dBaseActor_c::posMove();

[[nsmbw(0x8006CF10)]]
int dBaseActor_c::GetProfNameActorNum(u16 profile);

[[nsmbw(0x8006CAE0)]]
void dBaseActor_c::draw2DActorOnLyt1();

[[nsmbw(0x8006CB40)]]
void dBaseActor_c::draw2DActorOnLyt2();

[[nsmbw(0x8006CA80)]]
dBaseActor_c* dBaseActor_c::construct(
    u16 profName, unsigned long param, const mVec3_c* position, const mAng3_c* rotation
);

[[nsmbw(0x8006CBA0)]]
dBaseActor_c* dBaseActor_c::construct(
    u16 profName, dBase_c* parent, unsigned long param, const mVec3_c* position,
    const mAng3_c* rotation
);

[[nsmbw(0x8006CA70)]]
void dBaseActor_c::setTmpCtData(const mVec3_c* position, const mAng3_c* rotation);
