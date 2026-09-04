#pragma once

#include "d_ef.h"
#include "d_enemy.h"
#include "m_3d_anmchr.h"
#include "m_3d_anmtexpat.h"
#include "m_vec.h"
#include <nw4r/g3d/g3d_resfile.h>

class dRemoconCannonGuide_c {
    SIZE_ASSERT(0xAC);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x00 */ nw4r::g3d::ResFile mRes;
    /* 0x04 */ m3d::mdl_c         mModel;
    /* 0x44 */ m3d::anmChr_c      mAnmChr;
    /* 0x7C */ u32                m0x7C;
    /* 0x80 */ m3d::anmTexPat_c   mAnmTexPat;
};

class daEnRemoconCannon_c : public dEn_c {
    // Original size: 0xB60
    VTABLE(0x060, fBase_c, 0x80B05958);
    // 0x80B05808 g_profile_EN_REMOCON_CANNON
    // 0x80A94D90 daEnRemoconCannon_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnRemoconCannon_c();

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

    // Instance Methods
    // ++++++

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

    /* 0x7BC */ dRemoconCannonGuide_c* mpGuide;

    FILL(0x7C0, 0x888);

    /* 0x888 */ bool mHasPlayer;

    FILL(0x889, 0x898);

    /* 0x898 */ m3d::anmTexPat_c mAnmTexPat;

    FILL(0x8C4, 0x8FC);

    /* 0x8FC */ dEf::dLevelEffect_c mEffectTrail[2];
    /* 0xB4C */ bool                REMOVED(mCannonFired)[4];

    FILL(0xB50, 0xB54);

    /* 0xB54 */ int mPlayerNo2;

    FILL(0xB58, 0xB60);
    OFFSET_ASSERT(0xB60);

    // Instance Variables
    // ++++++

    /* 0xB60 */ bool mCannonFired[PLAYER_COUNT];

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A966F0
     * executeState:    0x80A96730
     * finalizeState:   0x80A96720
     */
    sState_Extern(0x80B1A910, daEnRemoconCannon_c, Wait);

    /*
     * initializeState: 0x80A967E0
     * executeState:    0x80A968A0
     * finalizeState:   0x80A96890
     */
    sState_Extern(0x80B1A950, daEnRemoconCannon_c, Waken);

    /*
     * initializeState: 0x80A96920
     * executeState:    0x80A96A00
     * finalizeState:   0x80A969F0
     */
    sState_Extern(0x80B1A990, daEnRemoconCannon_c, Control);

    /*
     * initializeState: 0x80A96C10
     * executeState:    0x80A96DF0
     * finalizeState:   0x80A96DE0
     */
    sState_Extern(0x80B1A9D0, daEnRemoconCannon_c, Fire);

    /*
     * initializeState: 0x80A96EB0
     * executeState:    0x80A96F60
     * finalizeState:   0x80A96F50
     */
    sState_Extern(0x80B1AA10, daEnRemoconCannon_c, FireEnd);

    /*
     * initializeState: 0x80A96FF0
     * executeState:    0x80A97060
     * finalizeState:   0x80A97050
     */
    sState_Extern(0x80B1AA50, daEnRemoconCannon_c, Recover);
};
