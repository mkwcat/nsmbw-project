#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnKiller_c : public dEn_c {
    SIZE_ASSERT(0xA20);
    VTABLE(0x060, fBase_c, 0x80AF6720);
    // 0x80AF65D0 g_profile_EN_KILLER
    // 0x80A48F40 daEnKiller_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnKiller_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0xA20);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A4C3D0
     * executeState:    0x80A4C430
     * finalizeState:   0x80A4C420
     */
    sState_Extern(0x80B17B30, daEnKiller_c, MagMove);

    /*
     * initializeState: 0x80A4C540
     * executeState:    0x80A4C5A0
     * finalizeState:   0x80A4C590
     */
    sState_Extern(0x80B17B70, daEnKiller_c, Move);

    /*
     * initializeState: 0x80A4C740
     * executeState:    0x80A4C780
     * finalizeState:   0x80A4C770
     */
    sState_Extern(0x80B17BB0, daEnKiller_c, SearchMove);

    /*
     * initializeState: 0x80A4C8D0
     * executeState:    0x80A4C910
     * finalizeState:   0x80A4C900
     */
    sState_Extern(0x80B17BF0, daEnKiller_c, SearchMagMove);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x184 0x80A4CAE0
     * executeState:    VT+0x188 0x80A4CBA0
     * finalizeState:   VT+0x18C 0x80A4CB90
     */
    sState_ExternVirtual(0x80B17C2C, daEnKiller_c, DieBigFall);

    /*
     * initializeState: VT+0x1B4 0x80A4CCF0
     * executeState:    VT+0x1B8 0x80A4CD10
     * finalizeState:   VT+0x1BC 0x80A4CD00
     */
    sState_ExternVirtual(0x80B17C6C, daEnKiller_c, DieGoal);

    /*
     * initializeState: VT+0x1E4 0x80A4CF40
     * executeState:    VT+0x1E8 0x80A4CF60
     * finalizeState:   VT+0x1EC 0x80A4CF50
     */
    sState_ExternVirtual(0x80B17CAC, daEnKiller_c, EatOut);

    /*
     * initializeState: VT+0x1C0 0x80A4CBB0
     * executeState:    VT+0x1C4 0x80A4CC70
     * finalizeState:   VT+0x1C8 0x80A4CC60
     */
    sState_ExternVirtual(0x80B17CEC, daEnKiller_c, DieOther);

    /*
     * initializeState: VT+0x16C 0x80A4CD20
     * executeState:    VT+0x170 0x80A4CDA0
     * finalizeState:   VT+0x174 0x80A4CD90
     */
    sState_ExternVirtual(0x80B17D2C, daEnKiller_c, DieFumi);

    /*
     * initializeState: VT+0x178 0x80A4CE30
     * executeState:    VT+0x17C 0x80A4CE50
     * finalizeState:   VT+0x180 0x80A4CE40
     */
    sState_ExternVirtual(0x80B17D6C, daEnKiller_c, DieFall);
};

class daEnSearchKiller_c : public daEnKiller_c {
    SIZE_ASSERT(0xA20);
    // 0x80AF65DC g_profile_EN_SEARCH_KILLER
    // 0x80A49080 daEnSearchKiller_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnSearchKiller_c();
};

class daEnMagnumKiller_c : public daEnKiller_c {
    SIZE_ASSERT(0xA20);
    // 0x80AF65E8 g_profile_EN_MAGNUM_KILLER
    // 0x80A491C0 daEnMagnumKiller_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnMagnumKiller_c();
};

class daEnSearchMagnumKiller_c : public daEnKiller_c {
    SIZE_ASSERT(0xA20);
    // 0x80AF65F4 g_profile_EN_SEARCH_MAGNUM_KILLER
    // 0x80A49300 daEnSearchMagnumKiller_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnSearchMagnumKiller_c();
};
