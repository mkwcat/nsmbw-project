#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnGesso_c : public dEn_c {
    SIZE_ASSERT(0x738);
    VTABLE(0x060, fBase_c, 0x80AEAFE8);
    // 0x80AEAF80 g_profile_EN_GESSO
    // 0x80A04110 daEnGesso_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnGesso_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x738);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A053F0
     * executeState:    0x80A05490
     * finalizeState:   0x80A05480
     */
    sState_Extern(0x80B14DF0, daEnGesso_c, SwimReady);

    /*
     * initializeState: 0x80A05590
     * executeState:    0x80A056D0
     * finalizeState:   0x80A056C0
     */
    sState_Extern(0x80B14E30, daEnGesso_c, SwimUp);

    /*
     * initializeState: 0x80A05810
     * executeState:    0x80A058B0
     * finalizeState:   0x80A058A0
     */
    sState_Extern(0x80B14E70, daEnGesso_c, SwimWait);

    /*
     * initializeState: 0x80A05A10
     * executeState:    0x80A05AC0
     * finalizeState:   0x80A05AB0
     */
    sState_Extern(0x80B14EB0, daEnGesso_c, SwimDown);

    /*
     * initializeState: 0x80A05BF0
     * executeState:    0x80A05C20
     * finalizeState:   0x80A05C10
     */
    sState_Extern(0x80B14EF0, daEnGesso_c, SwimDown_Fin);

    /*
     * initializeState: 0x80A05D30
     * executeState:    0x80A05D70
     * finalizeState:   0x80A05D60
     */
    sState_Extern(0x80B14F30, daEnGesso_c, RestReady);

    /*
     * initializeState: 0x80A05E80
     * executeState:    0x80A05F10
     * finalizeState:   0x80A05F00
     */
    sState_Extern(0x80B14F70, daEnGesso_c, Rest);

    /*
     * initializeState: 0x80A06040
     * executeState:    0x80A06120
     * finalizeState:   0x80A060B0
     */
    sState_Extern(0x80B14FB0, daEnGesso_c, Hide);

    /*
     * initializeState: 0x80A06200
     * executeState:    0x80A06270
     * finalizeState:   0x80A06260
     */
    sState_Extern(0x80B14FF0, daEnGesso_c, InDokan);

    /*
     * initializeState: 0x80A06460
     * executeState:    0x80A06480
     * finalizeState:   0x80A06470
     */
    sState_Extern(0x80B15030, daEnGesso_c, SetUp_Normal);

    /*
     * initializeState: 0x80A06570
     * executeState:    0x80A06590
     * finalizeState:   0x80A06580
     */
    sState_Extern(0x80B15070, daEnGesso_c, SetUp_Right);

    /*
     * initializeState: 0x80A066B0
     * executeState:    0x80A066D0
     * finalizeState:   0x80A066C0
     */
    sState_Extern(0x80B150B0, daEnGesso_c, SetUp_Left);

    /*
     * initializeState: 0x80A067F0
     * executeState:    0x80A06810
     * finalizeState:   0x80A06800
     */
    sState_Extern(0x80B150F0, daEnGesso_c, CancelSetUp_Normal);

    /*
     * initializeState: 0x80A06890
     * executeState:    0x80A068B0
     * finalizeState:   0x80A068A0
     */
    sState_Extern(0x80B15130, daEnGesso_c, CancelSetUp_Right);

    /*
     * initializeState: 0x80A06960
     * executeState:    0x80A06980
     * finalizeState:   0x80A06970
     */
    sState_Extern(0x80B15170, daEnGesso_c, CancelSetUp_Left);

    /*
     * initializeState: 0x80A06A30
     * executeState:    0x80A06A70
     * finalizeState:   0x80A06A60
     */
    sState_Extern(0x80B151B0, daEnGesso_c, InDokan_Ready);

    /*
     * initializeState: 0x80A06AE0
     * executeState:    0x80A06B00
     * finalizeState:   0x80A06AF0
     */
    sState_Extern(0x80B151F0, daEnGesso_c, ShootReady);

    /*
     * initializeState: 0x80A06B80
     * executeState:    0x80A06C90
     * finalizeState:   0x80A06C80
     */
    sState_Extern(0x80B15230, daEnGesso_c, Shoot);

    /*
     * initializeState: 0x80A06E20
     * executeState:    0x80A06E90
     * finalizeState:   0x80A06E80
     */
    sState_Extern(0x80B15270, daEnGesso_c, ShootEd);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x80A06010
     * executeState:    VT+0x284 0x80A06030
     * finalizeState:   VT+0x288 0x80A06020
     */
    sState_ExternVirtual(0x80B152AC, daEnGesso_c, Attack);

    /*
     * initializeState: VT+0x178 0x80A05240
     * executeState:    VT+0x17C 0x80A05340
     * finalizeState:   VT+0x180 0x80A05330
     */
    sState_ExternVirtual(0x80B152EC, daEnGesso_c, DieFall);
};
