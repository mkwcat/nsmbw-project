#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnIbaramushi_c : public dEn_c {
    SIZE_ASSERT(0xEB0);
    VTABLE(0x060, fBase_c, 0x80AEF558);
    // 0x80AEF2D0 g_profile_EN_IBARAMUSHI
    // 0x80A1C100 daEnIbaramushi_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnIbaramushi_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0xEB0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A1E7A0
     * executeState:    0x80A1E890
     * finalizeState:   0x80A1E880
     */
    sState_Extern(0x80B15F48, daEnIbaramushi_c, Wait);

    /*
     * initializeState: 0x80A1E9D0
     * executeState:    0x80A1EB60
     * finalizeState:   0x80A1EB50
     */
    sState_Extern(0x80B15F88, daEnIbaramushi_c, Walk);

    /*
     * initializeState: 0x80A1F280
     * executeState:    0x80A1F2A0
     * finalizeState:   0x80A1F290
     */
    sState_Extern(0x80B16008, daEnIbaramushi_c, DieFumiFall);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x16C 0x80A1F120
     * executeState:    VT+0x170 0x80A1F190
     * finalizeState:   VT+0x174 0x80A1F180
     */
    sState_ExternVirtual(0x80B15FC4, daEnIbaramushi_c, DieFumi);

    /*
     * initializeState: VT+0x178 0x80A1F360
     * executeState:    VT+0x17C 0x80A1F3D0
     * finalizeState:   VT+0x180 0x80A1F3C0
     */
    sState_ExternVirtual(0x80B16044, daEnIbaramushi_c, DieFall);
};
