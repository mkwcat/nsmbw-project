#pragma once

#include "d_a_lift_remocon_main.h"
#include "s_State.h"

class daLiftRemoconSeesaw_c : public daLiftRemoconMain_c {
    SIZE_ASSERT(0x560);
    VTABLE(0x060, fBase_c, 0x80968094);
    // 0x80968030 g_profile_AC_LIFT_REMOCON_SEESAW
    // 0x8083EBC0 daLiftRemoconSeesaw_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8083EC20 */
    daLiftRemoconSeesaw_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8083F550 */
    short CalculateInitialAngle();

    /* 0x8083F4F0 */
    short CalculateAngle();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x454, 0x54A);

    /* 0x54A */ short mCurrentAngle;

    FILL(0x54C, 0x560);
};

class daLiftBossRemoconSeesaw_c : public daLiftRemoconSeesaw_c {
    SIZE_ASSERT(0x560);
    // 0x8096803C g_profile_AC_LIFT_BOSS_REMOCON_SEESAW
    // 0x8083EBF0 daLiftBossRemoconSeesaw_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftBossRemoconSeesaw_c() {}

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8083F9B0
     * executeState:    0x8083FA10
     * finalizeState:   0x8083FA00
     */
    sState_Extern(0x8099B490, daLiftRemoconSeesaw_c, Move);
};
