#pragma once

#include "d_a_en_bros_base.h"
#include "s_State.h"

class daEnLiftHammerBros_c : public daEnBrosBase_c {
    SIZE_ASSERT(0x858);
    VTABLE(0x060, fBase_c, 0x80AF9138);
    // 0x80AF90F8 g_profile_EN_LIFT_HAMMERBROS
    // 0x80A5B5E0 daEnLiftHammerBros_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnLiftHammerBros_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x84C, 0x858);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x298 0x80A5BCD0
     * executeState:    VT+0x29C 0x80A5BD70
     * finalizeState:   VT+0x2A0 0x80A5BD60
     */
    sState_ExternVirtual(0x80B183F0, daEnLiftHammerBros_c, JumpSt);

    /*
     * initializeState: VT+0x2A4 0x80A5BE80
     * executeState:    VT+0x2A8 0x80A5BF10
     * finalizeState:   VT+0x2AC 0x80A5BF00
     */
    sState_ExternVirtual(0x80B18430, daEnLiftHammerBros_c, Jump);

    /*
     * initializeState: VT+0x2B0 0x80A5C020
     * executeState:    VT+0x2B4 0x80A5C0C0
     * finalizeState:   VT+0x2B8 0x80A5C0B0
     */
    sState_ExternVirtual(0x80B18470, daEnLiftHammerBros_c, JumpEd);
};
