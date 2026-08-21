// d_player_model_base.cpp
// NSMBW .text: 0x800D5420 - 0x800D6DB0

#include "d_player_model_base.h"
#include "machine/m_mtx.h"

/* VT+0x10 */
[[nsmbw(0x800D5720)]]
void dPyMdlBase_c::createModel();

/* VT+0x30 */
[[nsmbw(0x800D5730)]]
void dPyMdlBase_c::setPlayerMode(int);

/* VT+0x14 */
[[nsmbw(0x800D5740)]]
void dPyMdlBase_c::initialize();

/* VT+0x18 */
[[nsmbw(0x800D5750)]]
void dPyMdlBase_c::play();

/* VT+0x1C */
[[nsmbw(0x800D5760)]]
void dPyMdlBase_c::_calc();

/* VT+0x50 */
[[nsmbw(0x800D5820)]]
void dPyMdlBase_c::getJointMtx(mMtx_c*, int);

/* VT+0x28 */
[[nsmbw(0x800D5870)]]
m3d::mdl_c* dPyMdlBase_c::getBodyMdl();

/* VT+0x24 */
[[nsmbw(0x800D5C70)]]
void dPyMdlBase_c::draw();

/* VT+0x34 */
[[nsmbw(0x800D5CC0)]]
void dPyMdlBase_c::setColorType(u8);

/* VT+0x84 */
[[nsmbw(0x800D5D00)]]
void dPyMdlBase_c::setFrame(float);

/* VT+0x88 */
[[nsmbw(0x800D5D70)]]
void dPyMdlBase_c::setBodyFrame(float);

/* VT+0x8C */
[[nsmbw(0x800D5D80)]]
void dPyMdlBase_c::setRate(float);

/* VT+0x90 */
[[nsmbw(0x800D5DF0)]]
void dPyMdlBase_c::setBodyRate(float);

/* VT+0x5C */
[[nsmbw(0x800D5EC0)]]
void dPyMdlBase_c::setAnm(int, float, float, float);

/* VT+0x2C */
[[nsmbw(0x800D62D0)]]
const void* dPyMdlBase_c::getAnmResFile() const;

/* VT+0x6C */
[[nsmbw(0x800D62E0)]]
void dPyMdlBase_c::copyAnm();

/* VT+0x64 */
[[nsmbw(0x800D62F0)]]
void dPyMdlBase_c::setBodyAnm(int, float, float, float);

/* VT+0x68 */
[[nsmbw(0x800D63E0)]]
void dPyMdlBase_c::releaseBodyAnm(float);

/* VT+0x70 */
[[nsmbw(0x800D6690)]]
void dPyMdlBase_c::VT_0x70();

/* VT+0x74 */
[[nsmbw(0x800D66A0)]]
void dPyMdlBase_c::VT_0x74();

/* VT+0x78 */
[[nsmbw(0x800D66B0)]]
void dPyMdlBase_c::setAnmBind();

/* VT+0x7C */
[[nsmbw(0x800D66C0)]]
void dPyMdlBase_c::VT_0x7C();

/* VT+0x60 */
[[nsmbw(0x800D6920)]]
bool dPyMdlBase_c::prepareBodyAnm(ChrAnmType_e type, nw4r::g3d::ResAnmChr* anm, bool noUpdate);

/* VT+0x58 */
[[nsmbw(0x800D6930)]]
void dPyMdlBase_c::VT_0x58();

/* VT+0x80 */
[[nsmbw(0x800D6A20)]]
void dPyMdlBase_c::setTexAnmType(TexAnmType_e);

/* VT+0xA8 */
[[nsmbw(0x800D6CF0)]]
float* dPyMdlBase_c::getLegLengthP(u8);

/* VT+0xA4 */
[[nsmbw(0x800D6D00)]]
void dPyMdlBase_c::setPropelScale(float);

/* VT+0xA0 */
[[nsmbw(0x800D6D10)]]
s16 dPyMdlBase_c::getPropelRollAngle() const;

/* VT+0x9C */
[[nsmbw(0x800D6D20)]]
void dPyMdlBase_c::setPropelRollAngle(s16);

/* VT+0x98 */
[[nsmbw(0x800D6D30)]]
s16 dPyMdlBase_c::getPropelRollSpeed() const;

/* VT+0x94 */
[[nsmbw(0x800D6D40)]]
void dPyMdlBase_c::setPropelRollSpeed(u16);

/* VT+0x54 */
[[nsmbw(0x800D6D50)]]
bool dPyMdlBase_c::getHeadPropelJointMtx(mMtx_c*);

/* VT+0x44 */
[[nsmbw(0x800D6D60)]]
void dPyMdlBase_c::offStarAnm();

/* VT+0x40 */
[[nsmbw(0x800D6D70)]]
void dPyMdlBase_c::onStarAnm();

/* VT+0x38 */
[[nsmbw(0x800D6D80)]]
void dPyMdlBase_c::setDark(int);

/* VT+0x20 */
[[nsmbw(0x800D6D90)]]
void dPyMdlBase_c::calc2();

/* VT+0x0C */
[[nsmbw(0x800D6DA0)]]
int dPyMdlBase_c::getFaceJointIdx() const;
