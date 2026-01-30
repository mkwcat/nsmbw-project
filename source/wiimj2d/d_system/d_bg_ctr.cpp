// d_bg_ctr.cpp
// NSMBW .text: 0x8007F7A0 - 0x80081070

#include "d_bg_ctr.h"

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
void dBg_ctr_c::set(dActor_c*, float, float, float, float, callbackF, callbackH, callbackW, u8, u8, mVec3_c*);

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