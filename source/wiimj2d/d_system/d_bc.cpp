// d_bc.cpp
// NSMBW .text: 0x80076BC0 - 0x80076FD0

#include "d_bc.h"

[[nsmbw(0x8006CF40)]]
dBc_c::dBc_c();

[[nsmbw(0x8006d090)]]
void dBc_c::set(
  dActor_c*, const sBcSensorBase*, const sBcSensorBase*, const sBcSensorBase*
); ///< @unofficial

[[nsmbw(0x80075090)]]
void dBc_c::checkLink();

[[nsmbw(0x80070CA0)]]
bool dBc_c::checkRide();

[[nsmbw(0x8006EF40)]]
bool dBc_c::checkHead(u32);

[[nsmbw(0x800708C0)]]
s16 dBc_c::getSakaAngle(u8);

[[nsmbw(0x80070920)]]
int dBc_c::getSakaMoveAngle(u8);

[[nsmbw(0x8006FA40)]]
dBc_c::Flag_e dBc_c::checkWall(float*);

[[nsmbw(0x80072CB0)]]
dBc_c::Flag_e dBc_c::checkWallEnm(float*);

[[nsmbw(0x8006DB30)]]
dBc_c::Flag_e dBc_c::checkFoot();

[[nsmbw(0x80072BC0)]]
dBc_c::Flag_e dBc_c::checkFootEnm();

[[nsmbw(0x80070720)]]
u16 dBc_c::getFootAttr();

[[nsmbw(0x80076530)]]
int dBc_c::checkWaterDepth(float, float, u8, u8, float*);

[[nsmbw(0x80075270)]]
dBc_c::WATER_TYPE_e dBc_c::checkWater(float, float, u8, float*);

[[nsmbw(0x800709C0)]]
u32 dBc_c::checkBg(float, float, u8, u8, unsigned long);

[[nsmbw(0x800767F0)]]
u32 dBc_c::checkWireNet(float x, float y, unsigned char layer);

[[nsmbw(0x800757B0)]]
u32 dBc_c::checkGround(const mVec3_c*, float*, u8, u8, signed char);

[[nsmbw(0x80075CA0)]]
u32 dBc_c::checkTenjou(const mVec3_c*, float*, u8, u8);

[[nsmbw(0x80075FD0)]]
u32 dBc_c::checkWall(const mVec3_c*, const mVec3_c*, float*, u8, u8, dActor_c**);