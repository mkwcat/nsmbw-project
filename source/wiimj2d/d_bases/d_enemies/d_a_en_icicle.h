#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnIcicle_c : public dEn_c {
    SIZE_ASSERT(0x628);
    VTABLE(0x060, fBase_c, 0x80AEFEC8);
    // 0x80AEFDD8 g_profile_EN_ICICLE
    // 0x80A20990 daEnIcicle_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnIcicle_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x628);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A21560
     * executeState:    0x80A21580
     * finalizeState:   0x80A21570
     */
    sState_Extern(0x80B160D8, daEnIcicle_c, ParentWait);

    /*
     * initializeState: 0x80A21600
     * executeState:    0x80A21650
     * finalizeState:   0x80A21640
     */
    sState_Extern(0x80B16118, daEnIcicle_c, ParentChildDel);

    /*
     * initializeState: 0x80A216C0
     * executeState:    0x80A216E0
     * finalizeState:   0x80A216D0
     */
    sState_Extern(0x80B16158, daEnIcicle_c, ParentCreateWait);

    /*
     * initializeState: 0x80A21750
     * executeState:    0x80A21770
     * finalizeState:   0x80A21760
     */
    sState_Extern(0x80B16198, daEnIcicle_c, ParentDel);

    /*
     * initializeState: 0x80A21780
     * executeState:    0x80A21800
     * finalizeState:   0x80A21790
     */
    sState_Extern(0x80B161D8, daEnIcicle_c, AnmWait);

    /*
     * initializeState: 0x80A21920
     * executeState:    0x80A21940
     * finalizeState:   0x80A21930
     */
    sState_Extern(0x80B16218, daEnIcicle_c, DownWait);

    /*
     * initializeState: 0x80A219A0
     * executeState:    0x80A219C0
     * finalizeState:   0x80A219B0
     */
    sState_Extern(0x80B16258, daEnIcicle_c, Vibration);

    /*
     * initializeState: 0x80A21A70
     * executeState:    0x80A21AC0
     * finalizeState:   0x80A21AB0
     */
    sState_Extern(0x80B16298, daEnIcicle_c, DownMove);
};
