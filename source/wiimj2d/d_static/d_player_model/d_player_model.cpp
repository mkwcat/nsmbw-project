// d_player_model.cpp
// NSMBW .text: 0x800D2EC0 - 0x800D5420

#include "d_player_model.h"

[[nsmbw(0x800D2EC0)]]
dPlayerMdl_c::dPlayerMdl_c(u8 index);

/* VT+0x08 */
[[nsmbw(0x800D31D0)]]
dPlayerMdl_c::~dPlayerMdl_c();

/* VT+0x10 */
[[nsmbw(0x800D3300)]]
void dPlayerMdl_c::createModel();

/* VT+0xB4 */
[[nsmbw(0x800D3360)]]
float dPlayerMdl_c::VT_0xB4();

/* VT+0x14 */
[[nsmbw(0x800D3370)]]
void dPlayerMdl_c::initialize();

/* VT+0xB8 */
[[nsmbw(0x800D3470)]]
void dPlayerMdl_c::createPlayerModel();

/* VT+0x1C */
[[nsmbw(0x800D37D0)]]
void dPlayerMdl_c::_calc();

/* VT+0x20 */
[[nsmbw(0x800D3920)]]
void dPlayerMdl_c::calc2();

/* VT+0x18 */
[[nsmbw(0x800D3990)]]
void dPlayerMdl_c::play();

/* VT+0x24 */
[[nsmbw(0x800D3B20)]]
void dPlayerMdl_c::draw();

/* VT+0x80 */
[[nsmbw(0x800D3CE0)]]
void dPlayerMdl_c::setTexAnmType(TexAnmType_e);

[[nsmbw(0x800D3DA0)]]
m3d::anmTexPat_c* dPlayerMdl_c::getHeadTexAnm();

/* VT+0x7C */
[[nsmbw(0x800D3DD0)]]
void dPlayerMdl_c::VT_0x7C();

/* VT+0x60 */
[[nsmbw(0x800D3FE0)]]
bool dPlayerMdl_c::prepareBodyAnm(ChrAnmType_e type, nw4r::g3d::ResAnmChr* anm, bool noUpdate);

/* VT+0x58 */
[[nsmbw(0x800D4150)]]
void dPlayerMdl_c::VT_0x58();

/* VT+0x6C */
[[nsmbw(0x800D41E0)]]
void dPlayerMdl_c::copyAnm();

/* VT+0x70 */
[[nsmbw(0x800D4330)]]
void dPlayerMdl_c::VT_0x70();

/* VT+0x74 */
[[nsmbw(0x800D44D0)]]
void dPlayerMdl_c::VT_0x74();

/* VT+0x78 */
[[nsmbw(0x800D4610)]]
void dPlayerMdl_c::setAnmBind();

/* VT+0xAC */
[[nsmbw(0x800D4750)]]
void dPlayerMdl_c::setCurrentModel(MODEL_e model);

/* VT+0x30 */
[[nsmbw(0x800D4760)]]
void dPlayerMdl_c::setPlayerMode(int);

/* VT+0x34 */
[[nsmbw(0x800D4870)]]
void dPlayerMdl_c::setColorType(u8);

/* VT+0x38 */
[[nsmbw(0x800D4880)]]
void dPlayerMdl_c::setDark(int);

/* VT+0x54 */
[[nsmbw(0x800D4A70)]]
bool dPlayerMdl_c::getHeadPropelJointMtx(mMtx_c*);

/* VT+0x40 */
[[nsmbw(0x800D4AC0)]]
void dPlayerMdl_c::onStarAnm();

/* VT+0x44 */
[[nsmbw(0x800D4B40)]]
void dPlayerMdl_c::offStarAnm();

/* VT+0xB0 */
[[nsmbw(0x800D4E70)]]
void dPlayerMdl_c::callbackTimingA(void* param_1, void* param_2);
