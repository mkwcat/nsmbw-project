#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnHnswich_c : public dEn_c {
    SIZE_ASSERT(0x8B0);
    VTABLE(0x060, fBase_c, 0x80AEED30);
    // 0x80AEEB28 g_profile_EN_HNSWICH
    // 0x80A190F0 daEnHnswich_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnHnswich_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x8B0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A1AB60
     * executeState:    0x80A1ABF0
     * finalizeState:   0x80A1ABE0
     */
    sState_Extern(0x80B15D48, daEnHnswich_c, Wait);

    /*
     * initializeState: 0x80A1AE60
     * executeState:    0x80A1AE80
     * finalizeState:   0x80A1AE70
     */
    sState_Extern(0x80B15D88, daEnHnswich_c, PushReserve);

    /*
     * initializeState: 0x80A1AEC0
     * executeState:    0x80A1AFF0
     * finalizeState:   0x80A1AFE0
     */
    sState_Extern(0x80B15DC8, daEnHnswich_c, PushOn);

    /*
     * initializeState: 0x80A1B260
     * executeState:    0x80A1B280
     * finalizeState:   0x80A1B270
     */
    sState_Extern(0x80B15E08, daEnHnswich_c, DelWait);

    /*
     * initializeState: 0x80A1B430
     * executeState:    0x80A1B470
     * finalizeState:   0x80A1B460
     */
    sState_Extern(0x80B15E48, daEnHnswich_c, PushWait);

    /*
     * initializeState: 0x80A1B5E0
     * executeState:    0x80A1B710
     * finalizeState:   0x80A1B6C0
     */
    sState_Extern(0x80B15E88, daEnHnswich_c, MvOff);

    /*
     * initializeState: 0x80A1B3A0
     * executeState:    0x80A1B3F0
     * finalizeState:   0x80A1B3E0
     */
    sState_Extern(0x80B15EC8, daEnHnswich_c, TimerDel);

    /*
     * initializeState: 0x80A1B340
     * executeState:    0x80A1B390
     * finalizeState:   0x80A1B380
     */
    sState_Extern(0x80B15F08, daEnHnswich_c, Del);
};

class daEnPswich_c : public daEnHnswich_c {
    SIZE_ASSERT(0x8B0);
    // 0x80AEEB34 g_profile_EN_PSWICH
    // 0x80A19260 daEnPswich_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnPswich_c() {}
};

class daEnQswich_c : public daEnHnswich_c {
    SIZE_ASSERT(0x8B0);
    // 0x80AEEB40 g_profile_EN_QSWICH
    // 0x80A19370 daEnQswich_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnQswich_c() {}
};

class daEnBigHnswich_c : public daEnHnswich_c {
    SIZE_ASSERT(0x8B0);
    // 0x80AEEB4C g_profile_EN_BIG_HNSWICH
    // 0x80A19480 daEnBigHnswich_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBigHnswich_c() {}
};

class daEnBossKoopaSwitch_c : public daEnHnswich_c {
    SIZE_ASSERT(0x8B0);
    // 0x80AEEB58 g_profile_EN_BOSS_KOOPA_SWITCH
    // 0x80A19590 daEnBossKoopaSwitch_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBossKoopaSwitch_c() {}
};

class daEnBossKoopaBigSwitch_c : public daEnHnswich_c {
    SIZE_ASSERT(0x8B0);
    // 0x80AEEB64 g_profile_EN_BOSS_KOOPA_BIG_SWITCH
    // 0x80A196A0 daEnBossKoopaBigSwitch_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBossKoopaBigSwitch_c() {}
};
