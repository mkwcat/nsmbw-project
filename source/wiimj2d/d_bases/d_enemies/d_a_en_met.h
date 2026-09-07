#pragma once

#include "d_a_en_shell.h"
#include "s_State.h"

class daEnMet_c : public daEnShell_c {
    SIZE_ASSERT(0x880);
    VTABLE(0x060, fBase_c, 0x80AFBF48);
    // 0x80AFBF00 g_profile_EN_MET
    // 0x80A67470 daEnMet_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnMet_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x7DC, 0x880);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A682F0
     * executeState:    0x80A68480
     * finalizeState:   0x80A68470
     */
    sState_Extern(0x80B18AD0, daEnMet_c, Walk);

    /*
     * initializeState: 0x80A68600
     * executeState:    0x80A686D0
     * finalizeState:   0x80A686C0
     */
    sState_Extern(0x80B18B10, daEnMet_c, Upmet_Walk);

    /*
     * initializeState: 0x80A68830
     * executeState:    0x80A68860
     * finalizeState:   0x80A68850
     */
    sState_Extern(0x80B18B50, daEnMet_c, Turn);

    /*
     * initializeState: 0x80A68970
     * executeState:    0x80A689A0
     * finalizeState:   0x80A68990
     */
    sState_Extern(0x80B18B90, daEnMet_c, Upmet_Turn);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x298 0x80A681F0
     * executeState:    VT+0x29C 0x80A68240
     * finalizeState:   VT+0x2A0 0x80A68230
     */
    sState_ExternVirtual(0x80B18BCC, daEnMet_c, Slide);

    /*
     * initializeState: VT+0x2A4 0x80A68A70
     * executeState:    VT+0x2A8 0x80A68B40
     * finalizeState:   VT+0x2AC 0x80A68B30
     */
    sState_ExternVirtual(0x80B18C0C, daEnMet_c, Wakeup);

    /*
     * initializeState: VT+0x2BC 0x80A68C90
     * executeState:    VT+0x2C0 0x80A68D20
     * finalizeState:   VT+0x2C4 0x80A68D10
     */
    sState_ExternVirtual(0x80B18C4C, daEnMet_c, WakeupTurn);

    /*
     * initializeState: VT+0x2B0 0x80A68D70
     * executeState:    VT+0x2B4 0x80A68E40
     * finalizeState:   VT+0x2B8 0x80A68E30
     */
    sState_ExternVirtual(0x80B18C8C, daEnMet_c, WakeupReverse);
};
