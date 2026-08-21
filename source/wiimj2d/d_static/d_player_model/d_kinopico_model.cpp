// d_kinopico_model.cpp
// NSMBW: ---

#include "d_kinopico_model.h"

#include "d_static/d_player_model/d_player_model.h"
#include "d_static/d_player_model/d_player_model_manager.h"
#include "machine/m_3d_anmtexpat.h"
#include "machine/m_3d_mdl.h"
#include <nw4r/g3d/g3d_resmdl.h>

dKinopicoMdl_c::dKinopicoMdl_c(
    u8 index
)
    : dPlayerMdl_c(index) {
    static ModelData l_modelData = {
        "Kinopico",
        "C_rcha",
        {"CB_model", "SCB_model", "PLCB_model", "PCB_model"},
        {"CH_model", "SCH_model", "PLCH_model", "PCH_model"},
        18.0,
        13.0,
        18.0,
        18.0,
    };

    mpModelData   = &l_modelData;

    mFaceJointIdx = 15;
}

dKinopicoMdl_c::~dKinopicoMdl_c() {}

void dKinopicoMdl_c::createAnim(
    m3d::anmTexPat_c& anm, const char* name, u8 modelIdx
) {
    nw4r::g3d::ResAnmTexPat anmTexPat = mModelResFile.GetResAnmTexPat(name);
    nw4r::g3d::ResMdl       mdl       = mModelResFile.GetResMdl(
        modelIdx < MODEL_COUNT ? mpModelData->mBodyModels[modelIdx]
                               : mpModelData->mHeadModels[modelIdx - MODEL_COUNT]
    );
    anm.create(mdl, anmTexPat, &mAllocator, nullptr, 2);
}

void dKinopicoMdl_c::createPlayerModel() {
    dPlayerMdl_c::createPlayerModel();

    createAnim(mHeadSwitchAnim, "PH_wait", MODEL_COUNT + MODEL_NORMAL);
    createAnim(mBodySwitchAnim, "KB_switch", MODEL_NORMAL);

    createAnim(mPropelHeadSwitchAnim, "PH_wait", MODEL_COUNT + MODEL_PROPELLER);
    createAnim(mPropelBodySwitchAnim, "PLKB_switch", MODEL_PROPELLER);

    createAnim(mPenguinHeadSwitchAnim, "PH_wait", MODEL_COUNT + MODEL_PENGUIN);
    createAnim(mPenguinBodySwitchAnim, "PKB_switch", MODEL_PENGUIN);
}

m3d::anmTexPat_c* dKinopicoMdl_c::getBodyTexAnm() {
    switch (mModelIdx) {
    default:
        return &mBodySwitchAnim;
    case MODEL_PROPELLER:
        return &mPropelBodySwitchAnim;
    case MODEL_PENGUIN:
        return &mPenguinBodySwitchAnim;
    }
}

// TODO
// void dKinopicoMdl_c::setTexAnmType(TexAnmType_e type);

void dKinopicoMdl_c::setColorType(
    u8 colorType
) {
    if (mCurColorType == colorType) {
        return;
    }

    mCurColorType  = colorType;
    int   modelIdx = static_cast<int>(mModelIdx);

    float frame    = 0;
    if (modelIdx == MODEL_PROPELLER || modelIdx == MODEL_PENGUIN) {
        if (mCharaID == static_cast<u8>(dPyMdlMng_c::ModelType_e::MODEL_TOADETTE_PURPLE)) {
            frame = 1;
        }
    } else {
        if (colorType == 1) {
            frame = 1;
        } else if (colorType == 2) {
            frame = 2;
        }
        if (mCharaID == static_cast<u8>(dPyMdlMng_c::ModelType_e::MODEL_TOADETTE_PURPLE)) {
            frame += 3;
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

bool dKinopicoMdl_c::prepareBodyAnm(
    ChrAnmType_e type, nw4r::g3d::ResAnmChr* anm, bool noUpdate
) {
    const char* s = nullptr;

#define CASE(_key, _str) \
    case ChrAnmType_e::_key: \
        s = _str; \
        break

    if (mModelIdx == MODEL_e::MODEL_PENGUIN) {
        switch (type) {
        default:
            break;

            CASE(WAIT, "PCB_wait");
            CASE(STAR_ROLL, "PCB_star_roll");
            CASE(GOAL_PUTON_CAP2, "PCB_goal_puton_cap");
        }
    }
    if (s == nullptr) {
        if (dPlayerMdl_c::prepareBodyAnm(type, anm, noUpdate)) {
            return true;
        }
        switch (type) {
        default:
            break;

            CASE(WAIT, "CB_wait");
            CASE(STOOP, "CB_stoop");
            CASE(STOOP_START, "CB_stoop_start");
            CASE(ROLL_JUMP, "CB_roll_jump");
            CASE(MONKEY_START, "KB_monkey_start");
            CASE(MONKEY_WAIT_R, "KB_monkey_wait_r");
            CASE(MONKEY_WAIT_L, "KB_monkey_wait_l");
            CASE(MONKEY_R_TO_L, "KB_monkey_r_to_l");
            CASE(MONKEY_L_TO_R, "KB_monkey_l_to_r");
            CASE(SJUMPED, "CB_Sjumped");
            CASE(STAR_ROLL, "CB_star_roll");
            CASE(GOAL_PUTON_CAP, "CB_goal_puton_cap");
            CASE(BUSY_WAIT, "KB_busy_wait");
            CASE(DEMO_TALK, "KB_demo_takl");
            CASE(ENDING_WAIT, "KB_ending_wait");
        }
    }
    if (s) {
        *anm = mAnimResFile.GetResAnmChr(s);
        if (!noUpdate) {
            mFlags |= 0x400000;
        }
        mFlags2 |= 0x400000;
    }
    return !!s;
}

float dKinopicoMdl_c::VT_0xB4() {
    MODEL_e model = mModelIdx;
    if (mFlags & 0x800000 || mFlags & 0x1000000) {
        model = MODEL_NORMAL;
    }

    using FloatArray = float[];

    float length;
    if (mFlags & 0x400000) {
        // Big
        length = FloatArray{1.0, 0.628, 1.0, 1.0}[model];
    } else {
        // Small
        length = FloatArray{0.6, 0.377, 0.6, 0.45}[model];
    }

    if (mFlags & 0x8) {
        length += FloatArray{0.15, 0.2, 0.15, 0.37}[model];

        if (mPowerupID == 3) {
            length -= 0.05;
        }
    }

    return length;
}
