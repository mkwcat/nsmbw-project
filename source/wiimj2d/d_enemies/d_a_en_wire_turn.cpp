// d_a_en_wire_turn.cpp
// NSMBW d_enemies.text: 0x80AC9F30 - 0x80ACB7C0

#include "d_a_en_wire_turn.h"

#include "d_profile.h"
#include "d_audio.h"
#include "d_cc.h"
#include "SndID.h"
#include <algorithm>
#include <mkwcat/Relocate.hpp>
#include <mkwcat/VTable.hpp>

[[nsmbw_data(0x80AD58A0)]]
sCcDatNewF l_CC_DATA_BIG_WIRE_TURN{};

[[nsmbw(0x80AC9F30)]]
fBase_c* daEnWrturn_c_classInit() {
    return new daEnWrturn_c;
}

[[nsmbw(0x80ACA010)]]
fBase_c* daEnBigWrturn_c_classInit() {
    return new daEnBigWrturn_c;
}

daEnWrturn_c::daEnWrturn_c() {
    mkwcat::VTable::Fix<fBase_c>(this);
}

daEnBigWrturn_c::daEnBigWrturn_c() {
    mkwcat::VTable::Fix<fBase_c>(this);
}

[[nsmbw(0x80ACA0F0)]]
fBase_c::PACK_RESULT_e daEnWrturn_c::create() {
    m_0x72C = mPos;

    if (mProfName == dProf::EN_BIG_WIRE_TURN) {
        m_wireType = WireType_e::L;
        m_0x72C.x -= 96.0f;
        m_0x72C.y += 32.0f;
        initL();
    } else {
        m_wireType = WireType_e::S;
        m_0x72C.x -= 24.0f;
        m_0x72C.y += 24.0f;
        initS();
    }

    mEatBehavior = 0;
    mScale       = {1.0f, 1.0f, 1.0f};
    mPos.z       = 0.0f;
    std::fill(std::begin(m_0x8C8), std::end(m_0x8C8), -1);
    std::fill(std::begin(m_plrAmiRoll), std::end(m_plrAmiRoll), 0);
    m_0x8B6 = m_0x8BA = 0;
    mCc.entry();
    mStateMgr.changeState(StateID_Wait);
    mVisibleAreaOffset = {0.0f, 0.0f};

    return PACK_RESULT_e::SUCCEEDED;
}

[[nsmbw(0x80ACA2B0)]]
fBase_c::PACK_RESULT_e daEnWrturn_c::execute() {
    mStateMgr.executeState();

    if (m_wireType == WireType_e::L) {
        m_kaDraw.calc_vtx_pos();
        m_kaDraw.move(mPos);
    }

    ActorScrOutCheck(0);

    std::fill(std::begin(m_0x8C8), std::end(m_0x8C8), -1);
    std::fill(std::begin(m_0x6A4), std::end(m_0x6A4), fBaseID_e::NONE);
    m_0x8B6 = 0;

    return PACK_RESULT_e::SUCCEEDED;
}

[[nsmbw(0x80ACA8B0)]]
void daEnWrturn_c::initS();

void daEnWrturn_c::initL() {
    mDestroyBound.mSize = {128.0f, 128.0f};
    m_kaDraw.init(0);
    mCc.set(this, &l_CC_DATA_BIG_WIRE_TURN, 3);
}

[[nsmbw(0x80ACA980)]]
void daEnWrturn_c::BgUpdate(bool);

[[nsmbw(0x80ACB010)]]
void daEnWrturn_c::initializeState_Wait() {
    m_0x8BA = 0;
    std::fill(std::begin(m_plrAmiRoll), std::end(m_plrAmiRoll), 0);
}

[[nsmbw(0x80ACB050)]]
void daEnWrturn_c::initializeState_Move() {
    m_0x8B0 = m_0x8B4 = 0;
    BgUpdate(true);
    std::fill(std::begin(m_plrAmiChange), std::end(m_plrAmiChange), 0);

    dAudio::g_pSndObjMap->startSound(
        m_wireType == WireType_e::L ? SndID::SE_OBJ_FENCE_TURN_L : SndID::SE_OBJ_FENCE_TURN_S,
        dAudio::cvtSndObjctPos(mPos), 0b0000
    );
}

// daEnWrturn_c::executeState_Move

PATCH_REFERENCES(
    offsetof(daEnWrturn_c, m_plrMoveX), //
    {
        {0x80ACA67C + 2, R_PPC_ADDR16_LO},

        {0x80ACAEA4 + 2, R_PPC_ADDR16_LO},
        {0x80ACAF04 + 2, R_PPC_ADDR16_LO},
        {0x80ACAF5C + 2, R_PPC_ADDR16_LO},
    }
);

PATCH_REFERENCES(
    offsetof(daEnWrturn_c, m_plrMoveY), //
    {
        {0x80ACA68C + 2, R_PPC_ADDR16_LO},

        {0x80ACAEB8 + 2, R_PPC_ADDR16_LO},
    }
);

PATCH_REFERENCES(
    offsetof(daEnWrturn_c, m_plrMoveZ), //
    {
        {0x80ACA69C + 2, R_PPC_ADDR16_LO},

        {0x80ACAEC0 + 2, R_PPC_ADDR16_LO},
    }
);

PATCH_REFERENCES(
    offsetof(daEnWrturn_c, m_plrAmiChange), //
    {
        {0x80ACB24C + 2, R_PPC_ADDR16_LO},
        {0x80ACB270 + 2, R_PPC_ADDR16_LO},
        {0x80ACB284 + 2, R_PPC_ADDR16_LO},
    }
);

PATCH_REFERENCES(
    offsetof(daEnWrturn_c, m_plrAmiLayer), //
    {
        {0x80ACA6A4 + 2, R_PPC_ADDR16_LO},

        {0x80ACB260 + 2, R_PPC_ADDR16_LO},
    }
);

PATCH_REFERENCES(
    offsetof(daEnWrturn_c, m_plrAmiRoll), //
    {
        {0x80ACA6A8 + 2, R_PPC_ADDR16_LO},

        {0x80ACAE98 + 2, R_PPC_ADDR16_LO},
        {0x80ACAF48 + 2, R_PPC_ADDR16_LO},

        {0x80ACAFD0 + 2, R_PPC_ADDR16_LO},

        {0x80ACB240 + 2, R_PPC_ADDR16_LO},
    }
);

PATCH_REFERENCES(
    offsetof(daEnWrturn_c, m_0x8C8), //
    {
        {0x80ACA4F8 + 2, R_PPC_ADDR16_LO},

        {0x80ACA6FC + 2, R_PPC_ADDR16_LO},
    }
);
