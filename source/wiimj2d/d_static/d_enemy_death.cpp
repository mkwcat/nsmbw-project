// d_enemy_death.cpp
// NSMBW .text: 0x8009F5F0 - 0x800A2870

#include "d_enemy.h"

[[nsmbw(0x8009F840)]]
bool dEn_c::hitCallback_Star(dCc_c*, dCc_c*);

[[nsmbw(0x8009F9D0)]]
bool dEn_c::hitCallback_Cannon(dCc_c*, dCc_c*);

[[nsmbw(0x8009FB50)]]
bool dEn_c::hitCallback_Slip(dCc_c*, dCc_c*);

[[nsmbw(0x8009FCC0)]]
bool dEn_c::hitCallback_PenguinSlide(dCc_c*, dCc_c*);

[[nsmbw(0x8009FCD0)]]
bool dEn_c::hitCallback_Screw(dCc_c*, dCc_c*);

[[nsmbw(0x8009FCE0)]]
bool dEn_c::hitCallback_WireNet(dCc_c*, dCc_c*);

[[nsmbw(0x8009FE40)]]
bool dEn_c::hitCallback_Large(dCc_c*, dCc_c*);

[[nsmbw(0x8009FFC0)]]
bool dEn_c::hitCallback_Rolling(dCc_c*, dCc_c*);

[[nsmbw(0x8009FFD0)]]
bool dEn_c::hitCallback_Spin(dCc_c*, dCc_c*);

[[nsmbw(0x800A0150)]]
bool dEn_c::hitCallback_HipAttk(dCc_c*, dCc_c*);

[[nsmbw(0x800A02D0)]]
bool dEn_c::hitCallback_YoshiHipAttk(dCc_c*, dCc_c*);

[[nsmbw(0x800A03C0)]]
bool dEn_c::hitCallback_YoshiBullet(dCc_c*, dCc_c*);

[[nsmbw(0x800A0550)]]
bool dEn_c::hitCallback_YoshiFire(dCc_c*, dCc_c*);

[[nsmbw(0x800A0700)]]
bool dEn_c::hitCallback_Shell(dCc_c*, dCc_c*);

[[nsmbw(0x800A08D0)]]
bool dEn_c::hitCallback_Fire(dCc_c*, dCc_c*);

[[nsmbw(0x800A0A30)]]
bool dEn_c::hitCallback_Ice(dCc_c*, dCc_c*);

[[nsmbw(0x800A0C70)]]
void dEn_c::setDeathInfo_Quake(int);

[[nsmbw(0x800A10B0)]]
void dEn_c::setDeathInfo_Other(dActor_c*);

[[nsmbw(0x800A12A0)]]
void dEn_c::setDeathInfo_IceBreak();

[[nsmbw(0x800A1370)]]
void dEn_c::setDeathInfo_IceVanish();

[[nsmbw(0x800A1470)]]
void dEn_c::initializeState_DieFumi();

[[nsmbw(0x800A15F0)]]
void dEn_c::finalizeState_DieFumi();

[[nsmbw(0x800A1600)]]
void dEn_c::executeState_DieFumi();

[[nsmbw(0x800A16A0)]]
void dEn_c::initializeState_DieFall();

[[nsmbw(0x800A1820)]]
void dEn_c::finalizeState_DieFall();

[[nsmbw(0x800A1830)]]
void dEn_c::executeState_DieFall();

[[nsmbw(0x800A1910)]]
void dEn_c::initializeState_DieBigFall();

[[nsmbw(0x800A1920)]]
void dEn_c::finalizeState_DieBigFall();

[[nsmbw(0x800A1930)]]
void dEn_c::executeState_DieBigFall();

[[nsmbw(0x800A1980)]]
void dEn_c::initializeState_DieSmoke();

[[nsmbw(0x800A19F0)]]
void dEn_c::finalizeState_DieSmoke();

[[nsmbw(0x800A1A00)]]
void dEn_c::executeState_DieSmoke();

[[nsmbw(0x800A1A10)]]
void dEn_c::initializeState_DieIceVanish();

[[nsmbw(0x800A1AA0)]]
void dEn_c::finalizeState_DieIceVanish();

[[nsmbw(0x800A1AB0)]]
void dEn_c::executeState_DieIceVanish();

[[nsmbw(0x800A1AC0)]]
void dEn_c::initializeState_DieYoshiFumi();

[[nsmbw(0x800A1B30)]]
void dEn_c::finalizeState_DieYoshiFumi();

[[nsmbw(0x800A1B40)]]
void dEn_c::executeState_DieYoshiFumi();

[[nsmbw(0x800A1B50)]]
void dEn_c::initializeState_DieGoal();

[[nsmbw(0x800A1B60)]]
void dEn_c::finalizeState_DieGoal();

[[nsmbw(0x800A1B70)]]
void dEn_c::executeState_DieGoal();

[[nsmbw(0x800A1B80)]]
void dEn_c::initializeState_DieOther();

[[nsmbw(0x800A1B90)]]
void dEn_c::finalizeState_DieOther();

[[nsmbw(0x800A1BA0)]]
void dEn_c::executeState_DieOther();

[[nsmbw(0x800A1BB0)]]
void dEn_c::setDeathSound_Fire();

[[nsmbw(0x800A1C00)]]
void dEn_c::setDeathSound_HipAttk();

[[nsmbw(0x800A1C80)]]
void dEn_c::setDeathSound_Slip(dActor_c*);

[[nsmbw(0x800A1D90)]]
void dEn_c::setDeathSound_Spin();

[[nsmbw(0x800A1E10)]]
void dEn_c::setDeathSound_Rolling();
