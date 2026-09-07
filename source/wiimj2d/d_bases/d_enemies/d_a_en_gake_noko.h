#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnGakeNoko_c : public dEn_c {
    SIZE_ASSERT(0x720);
    VTABLE(0x060, fBase_c, 0x80AEAA60);
    // 0x80AEA9F8 g_profile_EN_GAKE_NOKO
    // 0x80A024B0 daEnGakeNoko_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnGakeNoko_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x720);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A02E40
     * executeState:    0x80A02EF0
     * finalizeState:   0x80A02EE0
     */
    sState_Extern(0x80B14BC0, daEnGakeNoko_c, FoolMove);

    /*
     * initializeState: 0x80A02CA0
     * executeState:    0x80A02D50
     * finalizeState:   0x80A02D40
     */
    sState_Extern(0x80B14C00, daEnGakeNoko_c, Move);

    /*
     * initializeState: 0x80A02FD0
     * executeState:    0x80A03000
     * finalizeState:   0x80A02FF0
     */
    sState_Extern(0x80B14C40, daEnGakeNoko_c, Air);

    /*
     * initializeState: 0x80A03070
     * executeState:    0x80A030E0
     * finalizeState:   0x80A030D0
     */
    sState_Extern(0x80B14C80, daEnGakeNoko_c, Awake);

    /*
     * initializeState: 0x80A031C0
     * executeState:    0x80A03230
     * finalizeState:   0x80A03220
     */
    sState_Extern(0x80B14CC0, daEnGakeNoko_c, Fall);

    /*
     * initializeState: 0x80A03310
     * executeState:    0x80A03380
     * finalizeState:   0x80A03370
     */
    sState_Extern(0x80B14D00, daEnGakeNoko_c, Fall2);

    /*
     * initializeState: 0x80A034A0
     * executeState:    0x80A034F0
     * finalizeState:   0x80A034E0
     */
    sState_Extern(0x80B14D40, daEnGakeNoko_c, Hang);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x16C 0x80A03520
     * executeState:    VT+0x170 0x80A03600
     * finalizeState:   VT+0x174 0x80A035F0
     */
    sState_ExternVirtual(0x80B14D7C, daEnGakeNoko_c, DieFumi);
};
