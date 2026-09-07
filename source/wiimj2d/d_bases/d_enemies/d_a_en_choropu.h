#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnChoropu_c : public dEn_c {
    SIZE_ASSERT(0x880);
    VTABLE(0x060, fBase_c, 0x80AE0ADC);
    // 0x80AE0A08 g_profile_EN_CHOROPU
    // 0x809D8B70 daEnChoropu_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnChoropu_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x880);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809D9790
     * executeState:    0x809D97B0
     * finalizeState:   0x809D97A0
     */
    sState_Extern(0x80B132B8, daEnChoropu_c, Hide);

    /*
     * initializeState: 0x809D9830
     * executeState:    0x809D98B0
     * finalizeState:   0x809D98A0
     */
    sState_Extern(0x80B132F8, daEnChoropu_c, AppearReady);

    /*
     * initializeState: 0x809D9B10
     * executeState:    0x809D9BD0
     * finalizeState:   0x809D9BC0
     */
    sState_Extern(0x80B13338, daEnChoropu_c, Appear);

    /*
     * initializeState: 0x809D9C60
     * executeState:    0x809D9D70
     * finalizeState:   0x809D9D60
     */
    sState_Extern(0x80B13378, daEnChoropu_c, LandOn);

    /*
     * initializeState: 0x809D9EA0
     * executeState:    0x809D9F40
     * finalizeState:   0x809D9F30
     */
    sState_Extern(0x80B133B8, daEnChoropu_c, Run);

    /*
     * initializeState: 0x809DA100
     * executeState:    0x809DA200
     * finalizeState:   0x809DA1F0
     */
    sState_Extern(0x80B133F8, daEnChoropu_c, Crash);

    /*
     * initializeState: 0x809DA330
     * executeState:    0x809DA3A0
     * finalizeState:   0x809DA390
     */
    sState_Extern(0x80B13438, daEnChoropu_c, CrashAfter);

    /*
     * initializeState: 0x809DA4A0
     * executeState:    0x809DA4D0
     * finalizeState:   0x809DA4B0
     */
    sState_Extern(0x80B13478, daEnChoropu_c, SlipTurn);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x809DABF0
     * executeState:    VT+0x17C 0x809DACA0
     * finalizeState:   VT+0x180 0x809DAC90
     */
    sState_ExternVirtual(0x80B134B4, daEnChoropu_c, DieFall);

    /*
     * initializeState: VT+0x16C 0x809DAAF0
     * executeState:    VT+0x170 0x809DABA0
     * finalizeState:   VT+0x174 0x809DAB90
     */
    sState_ExternVirtual(0x80B134F4, daEnChoropu_c, DieFumi);
};
