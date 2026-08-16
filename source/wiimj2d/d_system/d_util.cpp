// d_util.cpp
// NSMBW .text: 0x800E78D0 - 0x800E8BC0

#include "d_util.h"

namespace Util {

[[nsmbw(0x800E7CB0)]]
dDisp_c::dDisp_c();

[[nsmbw(0x800E7D80)]]
dDisp_c::~dDisp_c();

[[nsmbw(0x800E7EF0)]]
void dDisp_c::setSizeY(float);

[[nsmbw(0x800E7F30)]]
float dDisp_c::getSizeY();

[[nsmbw(0x800E7F40)]]
float dDisp_c::getSizeX();

[[nsmbw(0x800E7F50)]]
float dDisp_c::getPosX();

[[nsmbw(0x800E7F60)]]
bool dDisp_c::chaseBaseX(float, float);

[[nsmbw(0x800E7FE0)]]
void dDisp_c::setBaseX(float);

[[nsmbw(0x800E7FF0)]]
float dDisp_c::getBaseX();

[[nsmbw(0x800E8030)]]
void dDisp_c::resetBaseX();

[[nsmbw(0x800E8090)]]
float dDisp_c::getOrgX();

[[nsmbw(0x800E80A0)]]
bool dDisp_c::chaseOfsX(float, float);

[[nsmbw(0x800E8120)]]
void dDisp_c::setOfsX(float);

[[nsmbw(0x800E8130)]]
float dDisp_c::getOfsX();

[[nsmbw(0x800E8140)]]
bool dDisp_c::chaseBaseY(float, float);

[[nsmbw(0x800E81C0)]]
float dDisp_c::getPosY();

[[nsmbw(0x800E81D0)]]
void dDisp_c::setBaseY(float);

[[nsmbw(0x800E81E0)]]
float dDisp_c::getBaseY();

[[nsmbw(0x800E8220)]]
void dDisp_c::setOfsY(float);

[[nsmbw(0x800E8230)]]
float dDisp_c::getOfsY();

} // namespace Util
