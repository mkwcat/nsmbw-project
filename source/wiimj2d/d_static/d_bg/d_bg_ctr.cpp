// d_bg_ctr.cpp
// NSMBW .text: 0x8007F7A0 - 0x80081070

#include "d_bg_ctr.h"

#include "d_actor.h"

[[nsmbw_data(0x8042A0C0)]]
dBg_ctr_c* dBg_ctr_c::mEntryN;

[[nsmbw_data(0x8042A0C4)]]
dBg_ctr_c* dBg_ctr_c::mEntryB;

[[nsmbw(0x8007F7A0)]]
dBg_ctr_c::dBg_ctr_c();

[[nsmbw(0x8007F810)]]
dBg_ctr_c::~dBg_ctr_c();

[[nsmbw(0x8007F900)]]
void dBg_ctr_c::entry();

[[nsmbw(0x8007F950)]]
void dBg_ctr_c::release();

[[nsmbw(0x8007FDA0)]]
void dBg_ctr_c::calc();

[[nsmbw(0x8007F9B0)]]
void dBg_ctr_c::set_common(dActor_c*, callbackF, callbackH, callbackW, u8, u8);

[[nsmbw(0x8007FA40)]]
void dBg_ctr_c::set(
    dActor_c*, float, float, float, float, callbackF, callbackH, callbackW, u8, u8, mVec3_c*
);

[[nsmbw(0x8007FAD0)]]
void dBg_ctr_c::set(dActor_c*, mVec2_c, mVec2_c, callbackF, callbackH, callbackW, u8, u8, mVec3_c*);

[[nsmbw(0x8007FB10)]]
void dBg_ctr_c::set(dActor_c*, const sBgSetInfo*, u8, u8, mVec3_c*);

[[nsmbw(0x8007FB80)]]
void dBg_ctr_c::set_circle(dActor_c*, float, float, float, callbackF, callbackH, callbackW, u8, u8);

[[nsmbw(0x8007FD80)]]
void dBg_ctr_c::setAngleY3(short*);

[[nsmbw(0x80080630)]]
void dBg_ctr_c::updateObjBg();

[[nsmbw(0x80080E40)]]
bool dBg_ctr_c::crossCheckEnabled(
    dBc_c* bc, u32 flags, u8 flagType
) {
    static const u32 cFlagsValue[]  = {0x80000000, 0x80000000, 0x40000000, 0x20000000};
    static const u32 cFlagsValue2[] = {0x00000000, 0x00000000, 0x10000000, 0x08000000};

    if (!mLinked || mpOwner == nullptr || m0xD4 != 0 || (bc->mAmiLine & mAmiLine) == 0 ||
        bc->mpOwner == mpOwner || bc->mpOwner == mpCarryingActor || bc->mFriendActor == mpOwner ||
        *bc->mpLayer != mLayer) {
        return false;
    }

    if (mpOwner->checkNoCollide(bc->mpOwner)) {
        return false;
    }

    if (mFlags & cFlagsValue[flagType & 0xff]) {
        return false;
    }
    auto type = static_cast<dActor_c::ACTOR_TYPE_e>(bc->getActorKind());
    if (type == dActor_c::ACTOR_TYPE_e::PLAYER || type == dActor_c::ACTOR_TYPE_e::YOSHI) {
        if (mFlags & cFlagsValue2[flagType & 0xff]) {
            return false;
        }
    } else {
        if (mFlags & 0x4000000) {
            return false;
        }
    }

    if (m0xCC == 1) {
        if (flags & 0x40) {
            return false;
        }
    } else if (m0xCC == 2) {
        if (flags & 0x80) {
            return false;
        }
    } else if (m0xCC == 3) {
        if ((flags & 0x100) || (flags & 0x10000000)) {
            return false;
        }
    } else if (m0xCC == 4) {
        if (flags & 0x200) {
            return false;
        }
    }
    if ((mFlags & 0x800) && (flags & 0x400)) {
        return false;
    }
    return !(mFlags & 0x1000) || !(flags & 0x800);
}
