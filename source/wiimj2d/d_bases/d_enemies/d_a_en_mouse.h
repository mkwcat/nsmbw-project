#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnMouse_c : public dEn_c {
    SIZE_ASSERT(0x5D8);
    VTABLE(0x060, fBase_c, 0x80AFCFC0);
    // 0x80AFCF88 g_profile_EN_MOUSE
    // 0x80A6D7C0 daEnMouse_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnMouse_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5D8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A6F150
     * executeState:    0x80A6F1C0
     * finalizeState:   0x80A6F1B0
     */
    sState_Extern(0x80B18F98, daEnMouse_c, Walk);

    /*
     * initializeState: 0x80A6F3B0
     * executeState:    0x80A6F3E0
     * finalizeState:   0x80A6F3D0
     */
    sState_Extern(0x80B18FD8, daEnMouse_c, Turn);

    /*
     * initializeState: 0x80A6F570
     * executeState:    0x80A6F590
     * finalizeState:   0x80A6F580
     */
    sState_Extern(0x80B19018, daEnMouse_c, Slave);

    /*
     * initializeState: 0x80A6F820
     * executeState:    0x80A6F8A0
     * finalizeState:   0x80A6F890
     */
    sState_Extern(0x80B19058, daEnMouse_c, PanicRun);

    /*
     * initializeState: 0x80A6FA50
     * executeState:    0x80A6FAC0
     * finalizeState:   0x80A6FAB0
     */
    sState_Extern(0x80B19098, daEnMouse_c, PanicTurn);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x16C 0x80A6EFF0
     * executeState:    VT+0x170 0x80A6F050
     * finalizeState:   VT+0x174 0x80A6F040
     */
    sState_ExternVirtual(0x80B18F18, daEnMouse_c, DieFumi);

    /*
     * initializeState: VT+0x178 0x80A6F0A0
     * executeState:    VT+0x17C 0x80A6F100
     * finalizeState:   VT+0x180 0x80A6F0F0
     */
    sState_ExternVirtual(0x80B18F58, daEnMouse_c, DieFall);
};
