// d_kinopio_model.cpp
// NSMBW .text: 0x800BCBD0 - 0x800BD7F0

#include "d_kinopio_model.h"

#include "d_static/d_player_model/d_player_model_manager.h"
#include <nw4r/g3d/g3d_resanmchr.h>

[[nsmbw(0x800BCBD0)]]
dKinopioMdl_c::dKinopioMdl_c(u8 index);

/* VT+0x08 */
[[nsmbw(0x800BCC90)]]
dKinopioMdl_c::~dKinopioMdl_c();

/* VT+0xB8 */
[[nsmbw(0x800BCD20)]]
void dKinopioMdl_c::createPlayerModel();

/* VT+0x34 */
[[nsmbw(0x800BCF30)]]
void dKinopioMdl_c::setColorType(
    u8 colorType
) {
    if (mCurColorType == colorType) {
        return;
    }

    mCurColorType  = colorType;
    int   modelIdx = static_cast<int>(mModelIdx);

    float frame    = 0;
    if (modelIdx == MODEL_PROPELLER || modelIdx == MODEL_PENGUIN) {
        switch (static_cast<dPyMdlMng_c::ModelType_e>(mCharaID)) {
        case dPyMdlMng_c::ModelType_e::MODEL_TOAD_YELLOW:
            frame = 1;
            break;
        case dPyMdlMng_c::ModelType_e::MODEL_TOAD_BLACK:
            frame = 2;
            break;
        case dPyMdlMng_c::ModelType_e::MODEL_TOAD_ORANGE:
            frame = 3;
            break;
        default:
            break;
        }
    } else {
        if (colorType == 1) {
            frame = 1;
        } else if (colorType == 2) {
            frame = 2;
        }
        switch (static_cast<dPyMdlMng_c::ModelType_e>(mCharaID)) {
        case dPyMdlMng_c::ModelType_e::MODEL_TOAD_YELLOW:
            frame += 3;
            break;
        case dPyMdlMng_c::ModelType_e::MODEL_TOAD_RED:
            frame = 6;
            break;
        case dPyMdlMng_c::ModelType_e::MODEL_TOAD_BLACK:
            frame += 7;
            break;
        case dPyMdlMng_c::ModelType_e::MODEL_TOAD_ORANGE:
            frame += 10;
            break;
        default:
            break;
        }
    }

    using StringArray = const char* const[];

    // Head animation
    {
        m3d::anmTexPat_c*       headTexAnm = getHeadTexAnm();

        nw4r::g3d::ResAnmTexPat anmTexPat  = mModelResFile.GetResAnmTexPat(
            StringArray{"KH_switch", "KH_switch", "PLKH_switch", "PKH_switch"}[modelIdx]
        );
        headTexAnm->setAnm(mModels[modelIdx].mHead, anmTexPat, 0, m3d::PLAY_MODE_4);

        headTexAnm->setRate(0.0, 0);
        headTexAnm->setFrame(frame, 0);
        mModels[modelIdx].mHead.setAnm(*headTexAnm);
    }

    // Body animation
    {
        m3d::anmTexPat_c*       bodyTexAnm = getBodyTexAnm();

        nw4r::g3d::ResAnmTexPat anmTexPat  = mModelResFile.GetResAnmTexPat(
            StringArray{"KB_switch", "KB_switch", "PLKB_switch", "PKB_switch"}[modelIdx]
        );
        m3d::mdl_c* bodyMdl = getBodyMdl();

        bodyTexAnm->setAnm(*bodyMdl, anmTexPat, 0, m3d::PLAY_MODE_4);

        bodyTexAnm->setRate(0.0, 0);
        bodyTexAnm->setFrame(frame, 0);
        bodyMdl->setAnm(*bodyTexAnm);
    }
}

/* VT+0x80 */
[[nsmbw(0x800BD160)]]
void dKinopioMdl_c::setTexAnmType(TexAnmType_e);

/* VT+0x60 */
[[nsmbw(0x800BD260)]]
bool dKinopioMdl_c::prepareBodyAnm(ChrAnmType_e type, nw4r::g3d::ResAnmChr* anm, bool noUpdate);

/* VT+0x7C */
[[nsmbw(0x800BD5D0)]]
void dKinopioMdl_c::VT_0x7C();

/* VT+0xB4 */
[[nsmbw(0x800BD670)]]
float dKinopioMdl_c::VT_0xB4();

/* VT+0xB0 */
[[nsmbw(0x800BD6F0)]]
void dKinopioMdl_c::callbackTimingA(void* param_1, void* param_2);

[[nsmbw(0x800BD230)]]
m3d::anmTexPat_c* dKinopioMdl_c::getBodyTexAnm();
