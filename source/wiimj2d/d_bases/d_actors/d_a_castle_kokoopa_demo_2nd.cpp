// d_a_castle_kokoopa_demo_2nd.cpp
// NSMBW d_bases.text: 0x807DCD80 - 0x807DDCC0

#include "d_a_castle_kokoopa_demo_2nd.h"

#include "d_a_koopa_jr_for_castle_demo.h"
#include "d_a_koopa_ship_for_castle_demo.h"
#include "d_a_peach_for_castle_demo.h"
#include "d_a_player_demo_manager.h"
#include "d_a_player_manager.h"
#include "d_actorcreate_mng.h"
#include "d_balloon_mng.h"
#include "d_gamedisplay.h"
#include "d_profile.h"
#include "f_base_id.h"
#include "m_vec.h"
#include <algorithm>
#include <iterator>
#include <mkwcat/Relocate.hpp>
#include <mkwcat/VTable.hpp>

[[nsmbw(0x807DCD80)]]
fBase_c* daCastleKokoopaDemo2nd_c_classInit() {
    return new daCastleKokoopaDemo2nd_c;
}

daCastleKokoopaDemo2nd_c::daCastleKokoopaDemo2nd_c() {
    mkwcat::VTable::Fix<fBase_c>(this);
    mBossID = fBaseID_e::NONE;
}

[[nsmbw(0x807DCE80)]]
void daCastleKokoopaDemo2nd_c::initialize() {
    mBasePos     = mPos;
    mDoomshipPos = {mPos.x + 264.0f, mPos.y + 128.0f, 0.0f};
    m0x3FC       = mPos.x + 96.0f;
    std::fill(std::begin(m0x400), std::end(m0x400), 0.0f);
    std::fill(std::begin(m0x410), std::end(m0x410), 0.0f);
    std::fill(std::begin(mpPlayersInOrder), std::end(mpPlayersInOrder), nullptr);

    mVec3_c posKoopaShip = {mDoomshipPos.x + 160.0f, mDoomshipPos.y - 96.0f, 0.0f};
    mVec3_c posKoopaJr   = {mBasePos.x + 200.0f, mBasePos.y + 16.0f, 1500.0f};
    mVec3_c posPeach     = {mDoomshipPos.x + 40.0f, mDoomshipPos.y - 16.0f, 1500.0f};

    mpKoopaShip          = static_cast<daKoopaShipForCastleDemo_c*>(
        dActor_c::construct(dProf::KOOPA_SHIP_FOR_CASTLE_DEMO, this, 0, &posKoopaShip, nullptr, 0)
    );
    mpKoopaJr = static_cast<daKoopaJrForCastleDemo_c*>(
        dActor_c::construct(dProf::KOOPA_JR_FOR_CASTLE_DEMO, this, 0, &posKoopaJr, nullptr, 0)
    );
    mpPeach = static_cast<daPeachForCastleDemo_c*>(
        dActor_c::construct(dProf::PEACH_FOR_CASTLE_DEMO, this, 0, &posPeach, nullptr, 0)
    );

    dActorCreateMng_c::m_instance->mIsEndingDemo = true;
    daPyDemoMng_c::mspInstance->startControlDemoAll();
    dGameDisplay_c::m_instance->m0x452   = false;
    dBalloonMng_c::m_instance->mBossDead = true;
}

[[nsmbw(0x807DD290)]]
bool daCastleKokoopaDemo2nd_c::isPlayerActive(
    int plrNo
) {
    return daPyMng_c::isPlayerActive(plrNo);
}

PATCH_REFERENCES(
    offsetof(daCastleKokoopaDemo2nd_c, m0x400), //
    {
        {0x807DD1A0 + 2, R_PPC_ADDR16_LO},
        {0x807DD220 + 2, R_PPC_ADDR16_LO},
    }
);

PATCH_REFERENCES(
    offsetof(daCastleKokoopaDemo2nd_c, m0x410), //
    {
        {0x807DD238 + 2, R_PPC_ADDR16_LO},

        {0x807DD650 + 2, R_PPC_ADDR16_LO},

    }
);

PATCH_REFERENCES(
    offsetof(daCastleKokoopaDemo2nd_c, mpPlayersInOrder), //
    {
        {0x807DD10C + 2, R_PPC_ADDR16_LO},
        {0x807DD118 + 2, R_PPC_ADDR16_LO},
        {0x807DD148 + 2, R_PPC_ADDR16_LO},
        {0x807DD154 + 2, R_PPC_ADDR16_LO, -0x4},
        {0x807DD170 + 2, R_PPC_ADDR16_LO, -0x4},
        {0x807DD174 + 2, R_PPC_ADDR16_LO},
        {0x807DD1E4 + 2, R_PPC_ADDR16_LO},

        {0x807DD664 + 2, R_PPC_ADDR16_LO},
    }
);
