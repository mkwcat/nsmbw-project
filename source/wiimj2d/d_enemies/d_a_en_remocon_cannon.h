#pragma once

#include "System.h"
#include "d_system/d_enemy.h"
#include "d_system/d_ef.h"
#include "machine/m_3d_anmchr.h"
#include "machine/m_3d_anmtexpat.h"
#include "machine/m_vec.h"
#include <nw4r/g3d/g3d_resfile.h>

/* @unofficial */
class dRemoconCannonGuide_c
{
    SIZE_ASSERT(0xAC);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x00 */ nw4r::g3d::ResFile mRes;
    /* 0x04 */ m3d::mdl_c mModel;
    /* 0x44 */ m3d::anmChr_c mAnmChr;
    /* 0x7C */ u32 m0x7C;
    /* 0x80 */ m3d::anmTexPat_c mAnmTexPat;
};

class daEnRemoconCannon_c : public dEn_c
{
    SIZE_ASSERT(0xB60 + 0x8);

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80A950A0 */
    static void setupGuide(dRemoconCannonGuide_c** guide, int mPlayerNo);

    /* 0x80A954B0 */
    void createModel();

    /* 0x80A95890 */
    void setBodyColor();

    /* 0x80A95990 */
    void EffectDischargeTail();

    /* 0x80A95C00 */
    void UNDEF_80a95c00();

    /* 0x80A960A0 */
    void firePlayer(int playerType);

    /* 0x80A96210 */
    mVec3_c calcTiltPos();

    /* 0x80A964E0 */
    bool UNDEF_80a964e0(short target);

    /* unofficial */
    void EffectDischarge();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x778);

    /* 0x778 */ int mPlayerNo;

    FILL(0x77C, 0x78C);

    mVec3_c mStagePos;

    FILL(0x798, 0x7A4);

    /* 0x7A4 */ short mTargetAngle;
    /* 0x7A6 */ short _7A6;

    FILL(0x7A8, 0x7BC);

    /* 0x7BC */ dRemoconCannonGuide_c *mpGuide;
    
    FILL(0x7C0, 0x888);

    /* 0x888 */ bool mHasPlayer;

    FILL(0x889, 0x898);

    /* 0x898 */ m3d::anmTexPat_c mAnmTexPat;

    FILL(0x8C4, 0x8FC);

    /* 0x8FC */ dEf::dLevelEffect_c mEffectTrail[2];
    /* 0xB4C */ bool REMOVED(mCannonFired)[4];

    FILL(0xB50, 0xB54);

    /* 0xB54 */ int mPlayerNo2;

    FILL(0xB58, 0xB60);

    /* 0xB60 */ bool mCannonFired[8];

public:
    // State IDs
    // ^^^^^^

    sState_Extern(0x80B1A9D0, daEnRemoconCannon_c, Fire);
};