// d_a_tarzan_ivy.cpp
// NSMBW d_bases.text: 0x808ADFC0 - 0x808AF830

#include "d_a_tarzan_ivy.h"

#include "d_a_player_base.h"
#include "d_mj2d_game.h"
#include <algorithm>
#include <cmath>
#include <mkwcat/Relocate.hpp>
#include <mkwcat/VTable.hpp>

[[nsmbw(0x808ADFC0)]]
fBase_c* daTarzanIvy_c_classInit() {
    return new daTarzanIvy_c;
}

daTarzanIvy_c::daTarzanIvy_c() {
    mkwcat::VTable::Fix<fBase_c>(this);
}

[[nsmbw(0x808AE0A0)]]
daTarzanIvy_c::nodeCallback_c::~nodeCallback_c() {}

[[nsmbw(0x808AE0E0)]]
void daTarzanIvy_c::nodeCallback_c::timingB(u32, nw4r::g3d::WorldMtxManip*, nw4r::g3d::ResMdl);

[[nsmbw(0x808AE2F0)]]
void daTarzanIvy_c::initPlrInfo2(
    plrInfo2_s* pi2
) {
    for (int i = 0; i < PLAYER_COUNT; i++) {
        pi2[i].m_plrNo2 = pi2[i].m_plrNo = -1;
    }
}

[[nsmbw(0x808AE310)]]
void daTarzanIvy_c::executePlrInfo(
    plrInfo2_s* pi2
) {
    m_isRideAnyPrev = m_isRideAny;
    m_isRideAny     = false;
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (plrInfo_s& pi = m_plrInfo[i]) {
            pi.m_isRidePrev = pi.m_isRide;
            pi.m_isRide     = false;
            pi.m_0x0C = pi.m_0x08 = 0.0;
        }
    }

    for (dPc_c* pc = m_pole.mPc; pc; pc = pc->mNext) {
        daPlBase_c* py = pc->mParent->DynamicCast<daPlBase_c>();
        if (py == nullptr) {
            continue;
        }
        s8 plr = py->getPlrNo();
        if (plr < 0 || plr >= PLAYER_COUNT) {
            continue;
        }

        pi2[plr].m_plrNo = plr;
        pi2[plr].m_0x0   = 0.0;
        pi2[plr].m_0x4   = pc->m0x24;
        pi2[plr].m_angle = pc->getAngle();
        plrInfo_s& pi    = m_plrInfo[plr];
        pi.m_isRide      = true;
        pi.m_0x08        = pc->m0x1C;
        pi.m_0x0C        = pc->m0x24;
        m_isRideAny      = true;
    }
}

[[nsmbw(0x808AE5A0)]]
float daTarzanIvy_c::getHighFlt() {
    float hi = 0.0;
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (plrInfo_s& pi = m_plrInfo[i]; pi && pi.m_isRide && pi.m_0x08 > hi) {
            hi = pi.m_0x08;
        }
    }
    if (hi == 0.0) {
        return 550.0;
    }
    hi = hi * 550.0 / 130.0 + 60.0;
    return std::min(hi, 550.0f);
}

[[nsmbw(0x808AE690)]]
void daTarzanIvy_c::FUN_808AE690() {
    for (int i = 0; i < PLAYER_COUNT; i++) {
        plrInfo2_s& pi2 = m_plrInfo2[i];
        if (!pi2 || pi2.m_plrNo == pi2.m_plrNo2) {
            continue;
        }
        for (int r = 0; r < std::size(m_rotData); r++) {
            rotData_s& rd = m_rotData[r];
            if (rd.m_inUse) {
                continue;
            }
            rd.m_inUse = true;
            rd.m_plrNo = pi2.m_plrNo;
            rd.m_0x18 = rd.m_0x14 = 0.0;
        }
    }

    for (int i = 0; i < PLAYER_COUNT; i++) {
        plrInfo_s& pi = m_plrInfo[i];
        if (!pi || !pi.m_isRide || pi.m_isRidePrev) {
            continue;
        }
        int j;
        for (j = 0; j < PLAYER_COUNT; j++) {
            if (plrInfo_s& pj = m_plrInfo[j];
                pj && pj.m_plrNo != pi.m_plrNo && pj.m_0x08 > pi.m_0x08) {
                break;
            }
        }
        if (j < PLAYER_COUNT) {
            continue;
        }

        if (m_isRideAny && !m_isRideAnyPrev) {
            if (std::fabs(m_rotData[0].m_RotShake.m_value[0]) <= 64.0) {
                m_0x3DC = 4;
            }
        }

        if (pi.m_0x0C >= 0.0 && pi.m_0x0C <= 0.1) {
            m_rotData[0].m_RotShake.m_value[0] += 16;
        } else if (pi.m_0x0C < 0.0 && pi.m_0x0C >= -0.1) {
            m_rotData[0].m_RotShake.m_value[0] -= 16;
        } else {
            float add = pi.m_0x0C * (pi.m_0x08 / 100.0) * 160.0;
            m_rotData[0].m_RotShake.m_value[0] += static_cast<short>(std::min(add, 480.0f));
        }
    }
}

[[nsmbw(0x808AEF90)]]
void daTarzanIvy_c::FUN_808AEF90() {
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (plrInfo_s& pi = m_plrInfo[i]; pi && pi.m_isRide) {
            m_pole.mPlrAngle[i] = m_rotData[0].m_RotShake.m_value[0];
        } else {
            m_pole.mPlrAngle[i] = 0;
        }
    }
}

PATCH_REFERENCES(
    offsetof(daTarzanIvy_c, m_plrInfo), //
    {
        {0x808AED10 + 2, R_PPC_ADDR16_LO},
        {0x808AED1C + 2, R_PPC_ADDR16_LO, +0x4},
        {0x808AED7C + 2, R_PPC_ADDR16_LO, +0x8},
        {0x808AEE04 + 2, R_PPC_ADDR16_LO, +0x8},

        {0x808AF478 + 2, R_PPC_ADDR16_LO},
        {0x808AF47C + 2, R_PPC_ADDR16_LO, +0x4},
        {0x808AF488 + 2, R_PPC_ADDR16_LO, +0x5},
        {0x808AF48C + 2, R_PPC_ADDR16_LO, +0x8},
        {0x808AF490 + 2, R_PPC_ADDR16_LO, +0xC},
    }
)

PATCH_REFERENCES(
    offsetof(daTarzanIvy_c, m_plrInfo2), //
    {
        {0x808AE578 + 2, R_PPC_ADDR16_LO, +0xA},

        {0x808AF3FC + 2, R_PPC_ADDR16_LO},

        {0x808AF550 + 2, R_PPC_ADDR16_LO},
    }
)
