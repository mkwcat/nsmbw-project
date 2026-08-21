// d_wm_actor.cpp
// NSMBW .text: 0x800F2820 - 0x800F2C00

#include "d_wm_actor.h"

[[nsmbw(0x800F2820)]]
dWmActor_c::dWmActor_c();

[[nsmbw(0x800F2880)]]
dWmActor_c::~dWmActor_c();

[[nsmbw(0x800F28E0)]]
fBase_c::PACK_RESULT_e dWmActor_c::preCreate();

[[nsmbw(0x800F2910)]]
void dWmActor_c::postCreate(fBase_c::MAIN_STATE_e status);

[[nsmbw(0x800F2920)]]
fBase_c::PACK_RESULT_e dWmActor_c::preDelete();

[[nsmbw(0x800F2950)]]
void dWmActor_c::postDelete(fBase_c::MAIN_STATE_e status);

[[nsmbw(0x800F2960)]]
fBase_c::PACK_RESULT_e dWmActor_c::preExecute();

[[nsmbw(0x800F2A10)]]
void dWmActor_c::postExecute(fBase_c::MAIN_STATE_e status);

[[nsmbw(0x800F2A20)]]
fBase_c::PACK_RESULT_e dWmActor_c::preDraw();

[[nsmbw(0x800F2AF0)]]
void dWmActor_c::postDraw(fBase_c::MAIN_STATE_e status);

[[nsmbw(0x800F2B60)]]
dBaseActor_c::ACTOR_KIND_e dWmActor_c::GetActorType();

[[nsmbw(0x800F2B00)]]
dWmActor_c* dWmActor_c::construct(
    u16 profName, unsigned long param, const mVec3_c* position, const mAng3_c* rotation
);

[[nsmbw(0x800F2B10)]]
dWmActor_c* dWmActor_c::construct(
    u16 profName, dBase_c* base, unsigned long param, const mVec3_c* position,
    const mAng3_c* rotation
);

[[nsmbw(0x800F2B20)]]
void dWmActor_c::setSoftLight_Map(m3d::bmdl_c& mdl);

[[nsmbw(0x800F2B30)]]
void dWmActor_c::setSoftLight_MapObj(m3d::bmdl_c& mdl);

[[nsmbw(0x800F2B40)]]
void dWmActor_c::setSoftLight_Enemy(m3d::bmdl_c& mdl);

[[nsmbw(0x800F2B50)]]
void dWmActor_c::setSoftLight_Boss(m3d::bmdl_c& mdl);
