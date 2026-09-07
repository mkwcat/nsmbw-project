#pragma once

#include "d_a_en_shell.h"
#include "s_State.h"

class daEnPata_c : public daEnShell_c {
    SIZE_ASSERT(0xAB0);
    VTABLE(0x060, fBase_c, 0x80B02B74);
    // 0x80B02AF8 g_profile_EN_PATAPATA
    // 0x80A84250 daEnPata_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnPata_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x7DC, 0xAB0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A85280
     * executeState:    0x80A85360
     * finalizeState:   0x80A85350
     */
    sState_Extern(0x80B19DF0, daEnPata_c, UDfly);

    /*
     * initializeState: 0x80A854A0
     * executeState:    0x80A855B0
     * finalizeState:   0x80A855A0
     */
    sState_Extern(0x80B19E30, daEnPata_c, LRfly);

    /*
     * initializeState: 0x80A85710
     * executeState:    0x80A857F0
     * finalizeState:   0x80A857E0
     */
    sState_Extern(0x80B19E70, daEnPata_c, PataJ);

    /*
     * initializeState: 0x80A85960
     * executeState:    0x80A859A0
     * finalizeState:   0x80A85990
     */
    sState_Extern(0x80B19EB0, daEnPata_c, PataJTurn);
};
