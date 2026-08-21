// d_enemy_state.cpp
// NSMBW .text: 0x800A7DA0 - 0x800A8710

#include "d_enemy.h"

[[nsmbw(0x800A7DF0)]]
void dEn_c::changeState(const sStateIDIf_c&);

[[nsmbw(0x800A7E90)]]
void dEn_c::initializeState_Ice();

[[nsmbw(0x800A7F30)]]
void dEn_c::finalizeState_Ice();

[[nsmbw(0x800A7F40)]]
void dEn_c::executeState_Ice();

[[nsmbw(0x800A8060)]]
void dEn_c::createIceActor();

[[nsmbw(0x800A8150)]]
void dEn_c::setIceAnm();

[[nsmbw(0x800A8160)]]
void dEn_c::returnAnm_Ice();

[[nsmbw(0x800A8180)]]
void dEn_c::returnState_Ice();

[[nsmbw(0x800A8190)]]
void dEn_c::initializeState_HitSpin();

[[nsmbw(0x800A81A0)]]
void dEn_c::finalizeState_HitSpin();

[[nsmbw(0x800A81B0)]]
void dEn_c::executeState_HitSpin();

[[nsmbw(0x800A81C0)]]
void dEn_c::initializeState_EatIn();

[[nsmbw(0x800A81D0)]]
void dEn_c::finalizeState_EatIn();

[[nsmbw(0x800A81E0)]]
void dEn_c::executeState_EatIn();

[[nsmbw(0x800A8260)]]
void dEn_c::initializeState_EatNow();

[[nsmbw(0x800A8270)]]
void dEn_c::finalizeState_EatNow();

[[nsmbw(0x800A8280)]]
void dEn_c::executeState_EatNow();

[[nsmbw(0x800A8290)]]
void dEn_c::initializeState_EatOut();

[[nsmbw(0x800A82A0)]]
void dEn_c::finalizeState_EatOut();

[[nsmbw(0x800A82B0)]]
void dEn_c::executeState_EatOut();
