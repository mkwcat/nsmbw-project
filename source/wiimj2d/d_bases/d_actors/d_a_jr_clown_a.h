#pragma once

#include "d_enemy_jr_clown_base.h"
#include "s_State.h"

class daJrClownA_c : public dEnJrClownBase_c {
    SIZE_ASSERT(0xD88);
    VTABLE(0x060, fBase_c, 0x8095E498);
    // 0x8095E450 g_profile_JR_CLOWN_A
    // 0x80804E70 daJrClownA_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80804EC0 */
    daJrClownA_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0xD48, 0xD88);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x80805810
     * executeState:    VT+0x284 0x80805860
     * finalizeState:   VT+0x288 0x80805850
     */
    sState_ExternVirtual(0x8099935C, daJrClownA_c, DemoWait);

    /*
     * initializeState: VT+0x28C 0x80805870
     * executeState:    VT+0x290 0x808059C0
     * finalizeState:   VT+0x294 0x808059B0
     */
    sState_ExternVirtual(0x8099939C, daJrClownA_c, DemoAwake);

    /*
     * initializeState: VT+0x298 0x80805C40
     * executeState:    VT+0x29C 0x80805CE0
     * finalizeState:   VT+0x2A0 0x80805CD0
     */
    sState_ExternVirtual(0x809993DC, daJrClownA_c, Move);
};
