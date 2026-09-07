#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnHanachan_c : public dEn_c {
    SIZE_ASSERT(0x988);
    VTABLE(0x060, fBase_c, 0x80AEDCA0);
    // 0x80AEDC90 g_profile_EN_HANACHAN
    // 0x80A131A0 daEnHanachan_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnHanachan_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x988);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A14720
     * executeState:    0x80A14740
     * finalizeState:   0x80A14730
     */
    sState_Extern(0x80B15908, daEnHanachan_c, Walk);

    /*
     * initializeState: 0x80A14900
     * executeState:    0x80A14A00
     * finalizeState:   0x80A149F0
     */
    sState_Extern(0x80B15948, daEnHanachan_c, Angry);

    /*
     * initializeState: 0x80A14BB0
     * executeState:    0x80A14BE0
     * finalizeState:   0x80A14BD0
     */
    sState_Extern(0x80B15988, daEnHanachan_c, Dush);

    /*
     * initializeState: 0x80A14DF0
     * executeState:    0x80A14E90
     * finalizeState:   0x80A14E80
     */
    sState_Extern(0x80B159C8, daEnHanachan_c, Down);

    /*
     * initializeState: 0x80A15060
     * executeState:    0x80A15090
     * finalizeState:   0x80A15080
     */
    sState_Extern(0x80B15A08, daEnHanachan_c, Recover);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x80A151A0
     * executeState:    VT+0x17C 0x80A152A0
     * finalizeState:   VT+0x180 0x80A15290
     */
    sState_ExternVirtual(0x80B15A44, daEnHanachan_c, DieFall);
};
