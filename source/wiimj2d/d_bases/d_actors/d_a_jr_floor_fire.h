#pragma once

#include "d_enemy.h"

class daJrFloorFireMgr_c : public dBase_c {
    SIZE_ASSERT(0x5F0);
    // 0x80960898 g_profile_JR_FLOOR_FIRE_MGR
    // 0x80815BE0 daJrFloorFireMgr_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daJrFloorFireMgr_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x5F0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808161E0
     * executeState:    0x80816200
     * finalizeState:   0x808161F0
     */
    sState_Extern(0x80999A48, daJrFloorFireMgr_c, Idle);
};

class daJrFloorFire_c : public dEn_c {
    SIZE_ASSERT(0x790);
    VTABLE(0x060, fBase_c, 0x80960908);
    // 0x809608A4 g_profile_JR_FLOOR_FIRE
    // 0x80815C10 daJrFloorFire_cc_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daJrFloorFire_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x790);
};
