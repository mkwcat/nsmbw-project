#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnBuku_c : public dEn_c {
    SIZE_ASSERT(0x6E8);
    VTABLE(0x060, fBase_c, 0x80AD6360);
    // 0x80AD6308 g_profile_EN_BAKUBAKU
    // 0x809A61E0 daEnBuku_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBuku_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x6E8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809A7940
     * executeState:    0x809A79B0
     * finalizeState:   0x809A79A0
     */
    sState_Extern(0x80B116D8, daEnBuku_c, Swim);

    /*
     * initializeState: 0x809A7B20
     * executeState:    0x809A7B40
     * finalizeState:   0x809A7B30
     */
    sState_Extern(0x80B11718, daEnBuku_c, SrcSwim);

    /*
     * initializeState: 0x809A7C10
     * executeState:    0x809A7CA0
     * finalizeState:   0x809A7C90
     */
    sState_Extern(0x80B11758, daEnBuku_c, AttackSwim);

    /*
     * initializeState: 0x809A7F10
     * executeState:    0x809A7F30
     * finalizeState:   0x809A7F20
     */
    sState_Extern(0x80B11798, daEnBuku_c, AttackWait);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x809A7FB0
     * executeState:    VT+0x17C 0x809A8050
     * finalizeState:   VT+0x180 0x809A8040
     */
    sState_ExternVirtual(0x80B117D4, daEnBuku_c, DieFall);
};
