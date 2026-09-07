#pragma once

#include "d_a_en_blockmain.h"
#include "s_State.h"

class daEnPataBlock_c : public daEnBlockMain_c {
    SIZE_ASSERT(0x898);
    VTABLE(0x060, fBase_c, 0x80B01EC0);
    // 0x80B01E68 g_profile_EN_PATABLOCK
    // 0x80A7FF00 daEnPataBlock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnPataBlock_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x698, 0x898);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A80F60
     * executeState:    0x80A80FA0
     * finalizeState:   0x80A80F90
     */
    sState_Extern(0x80B19C08, daEnPataBlock_c, Fly_Normal);

    /*
     * initializeState: 0x80A81020
     * executeState:    0x80A81040
     * finalizeState:   0x80A81030
     */
    sState_Extern(0x80B19C48, daEnPataBlock_c, Fly_8Loop);

    /*
     * initializeState: 0x80A810D0
     * executeState:    0x80A810F0
     * finalizeState:   0x80A810E0
     */
    sState_Extern(0x80B19C88, daEnPataBlock_c, Fly_UpDown);

    /*
     * initializeState: 0x80A81140
     * executeState:    0x80A811D0
     * finalizeState:   0x80A811C0
     */
    sState_Extern(0x80B19CC8, daEnPataBlock_c, Still);
};
