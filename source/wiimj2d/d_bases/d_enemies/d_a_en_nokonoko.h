#pragma once

#include "d_a_en_shell.h"
#include "s_State.h"

class daEnNoko_c : public daEnShell_c {
    SIZE_ASSERT(0xA18);
    VTABLE(0x060, fBase_c, 0x80AFDDAC);
    // 0x80AFDCB0 g_profile_EN_NOKONOKO
    // 0x80A724A0 daEnNoko_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnNoko_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x7DC, 0xA18);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A74500
     * executeState:    0x80A74560
     * finalizeState:   0x80A74550
     */
    sState_Extern(0x80B19290, daEnNoko_c, BlockAppear);

    /*
     * initializeState: 0x80A73D40
     * executeState:    0x80A73EE0
     * finalizeState:   0x80A73ED0
     */
    sState_Extern(0x80B192D0, daEnNoko_c, Walk);

    /*
     * initializeState: 0x80A74300
     * executeState:    0x80A74340
     * finalizeState:   0x80A74330
     */
    sState_Extern(0x80B19310, daEnNoko_c, Turn);

    /*
     * initializeState: 0x80A74400
     * executeState:    0x80A74440
     * finalizeState:   0x80A74430
     */
    sState_Extern(0x80B19350, daEnNoko_c, WindTurn);

    /*
     * initializeState: 0x80A74590
     * executeState:    0x80A745C0
     * finalizeState:   0x80A745B0
     */
    sState_Extern(0x80B19390, daEnNoko_c, SpitOut_Ready);

    /*
     * initializeState: 0x80A74660
     * executeState:    0x80A746F0
     * finalizeState:   0x80A746E0
     */
    sState_Extern(0x80B193D0, daEnNoko_c, BgmDance);

    /*
     * initializeState: 0x80A747C0
     * executeState:    0x80A74850
     * finalizeState:   0x80A74840
     */
    sState_Extern(0x80B19410, daEnNoko_c, BgmDanceEd);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x2A4 0x80A740C0
     * executeState:    VT+0x2A8 0x80A74190
     * finalizeState:   VT+0x2AC 0x80A74130
     */
    sState_ExternVirtual(0x80B1944C, daEnNoko_c, Wakeup);

    /*
     * initializeState: VT+0x2BC 0x80A74250
     * executeState:    VT+0x2C0 0x80A742B0
     * finalizeState:   VT+0x2C4 0x80A742A0
     */
    sState_ExternVirtual(0x80B1948C, daEnNoko_c, WakeupTurn);
};
