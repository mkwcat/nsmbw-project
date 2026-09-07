#pragma once

#include "d_a_lift_remocon_main.h"
#include "s_State.h"

class daLiftRemoconXline_c : public daLiftRemoconMain_c {
    SIZE_ASSERT(0x778);
    VTABLE(0x060, fBase_c, 0x809682B8);
    // 0x80968240 g_profile_AC_LIFT_REMOCON_XLINE
    // 0x8083FEC0 daLiftRemoconXline_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8083FEF0 */
    daLiftRemoconXline_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x454, 0x778);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808411C0
     * executeState:    0x808411E0
     * finalizeState:   0x808411D0
     */
    sState_Extern(0x8099B4D0, daLiftRemoconXline_c, Wait);

    /*
     * initializeState: 0x80841280
     * executeState:    0x808412A0
     * finalizeState:   0x80841290
     */
    sState_Extern(0x8099B510, daLiftRemoconXline_c, Move);

    /*
     * initializeState: 0x808415B0
     * executeState:    0x808415D0
     * finalizeState:   0x808415C0
     */
    sState_Extern(0x8099B550, daLiftRemoconXline_c, End);
};
