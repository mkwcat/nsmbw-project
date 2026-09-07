#pragma once

#include "d_a_en_bros_base.h"
#include "s_State.h"

class daEnHammerBros_c : public daEnBrosBase_c {
    SIZE_ASSERT(0x868);
    VTABLE(0x060, fBase_c, 0x80AED840);
    // 0x80AED820 g_profile_EN_HAMMERBROS
    // 0x80A11B30 daEnHammerBros_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnHammerBros_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x84C, 0x868);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x298 0x80A12590
     * executeState:    VT+0x29C 0x80A12600
     * finalizeState:   VT+0x2A0 0x80A125F0
     */
    sState_ExternVirtual(0x80B15884, daEnHammerBros_c, JumpSt);

    /*
     * initializeState: VT+0x2BC 0x80A12800
     * executeState:    VT+0x2C0 0x80A12860
     * finalizeState:   VT+0x2C4 0x80A12850
     */
    sState_ExternVirtual(0x80B158C4, daEnHammerBros_c, AirAttack);
};
