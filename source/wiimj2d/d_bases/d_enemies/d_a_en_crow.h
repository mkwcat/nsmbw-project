#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnCrow_c : public dEn_c {
    SIZE_ASSERT(0x718);
    VTABLE(0x060, fBase_c, 0x80AE5B10);
    // 0x80AE5A70 g_profile_EN_CROW
    // 0x809ED3D0 daEnCrow_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnCrow_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x718);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809EDED0
     * executeState:    0x809EDF50
     * finalizeState:   0x809EDF40
     */
    sState_Extern(0x80B13F50, daEnCrow_c, Appear);

    /*
     * initializeState: 0x809EE050
     * executeState:    0x809EE0C0
     * finalizeState:   0x809EE0B0
     */
    sState_Extern(0x80B13F90, daEnCrow_c, Loop);

    /*
     * initializeState: 0x809EE2F0
     * executeState:    0x809EE3E0
     * finalizeState:   0x809EE3D0
     */
    sState_Extern(0x80B13FD0, daEnCrow_c, Swoop);

    /*
     * initializeState: 0x809EE640
     * executeState:    0x809EE6C0
     * finalizeState:   0x809EE6B0
     */
    sState_Extern(0x80B14010, daEnCrow_c, Escape);

    /*
     * initializeState: 0x809EE800
     * executeState:    0x809EE870
     * finalizeState:   0x809EE860
     */
    sState_Extern(0x80B14050, daEnCrow_c, Escape2);

    /*
     * initializeState: 0x809EE9A0
     * executeState:    0x809EEA10
     * finalizeState:   0x809EEA00
     */
    sState_Extern(0x80B14090, daEnCrow_c, Escape3);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x16C 0x809EEAC0
     * executeState:    VT+0x170 0x809EEB20
     * finalizeState:   VT+0x174 0x809EEB10
     */
    sState_ExternVirtual(0x80B140CC, daEnCrow_c, DieFumi);

    /*
     * initializeState: VT+0x178 0x809EEBD0
     * executeState:    VT+0x17C 0x809EEC60
     * finalizeState:   VT+0x180 0x809EEC50
     */
    sState_ExternVirtual(0x80B1410C, daEnCrow_c, DieFall);
};
