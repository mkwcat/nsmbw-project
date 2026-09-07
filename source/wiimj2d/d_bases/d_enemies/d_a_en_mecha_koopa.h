#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnMechaKoopa_c : public dEn_c {
    SIZE_ASSERT(0x600);
    VTABLE(0x060, fBase_c, 0x80AFB9C8);
    // 0x80AFB8F0 g_profile_EN_MECHA_KOOPA
    // 0x80A64110 daEnMechaKoopa_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnMechaKoopa_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x600);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A65A60
     * executeState:    0x80A65B10
     * finalizeState:   0x80A65B00
     */
    sState_Extern(0x80B188C0, daEnMechaKoopa_c, Walk);

    /*
     * initializeState: 0x80A65C90
     * executeState:    0x80A65CC0
     * finalizeState:   0x80A65CB0
     */
    sState_Extern(0x80B18900, daEnMechaKoopa_c, Turn);

    /*
     * initializeState: 0x80A65E00
     * executeState:    0x80A65E40
     * finalizeState:   0x80A65E30
     */
    sState_Extern(0x80B18940, daEnMechaKoopa_c, Sleep);

    /*
     * initializeState: 0x80A66240
     * executeState:    0x80A662F0
     * finalizeState:   0x80A662C0
     */
    sState_Extern(0x80B189C0, daEnMechaKoopa_c, Slide);

    /*
     * initializeState: 0x80A66410
     * executeState:    0x80A66510
     * finalizeState:   0x80A664F0
     */
    sState_Extern(0x80B18A00, daEnMechaKoopa_c, Kick);

    /*
     * initializeState: 0x80A66660
     * executeState:    0x80A66700
     * finalizeState:   0x80A666F0
     */
    sState_Extern(0x80B18A40, daEnMechaKoopa_c, Recover);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x80A65ED0
     * executeState:    VT+0x284 0x80A66060
     * finalizeState:   VT+0x288 0x80A65F80
     */
    sState_ExternVirtual(0x80B1897C, daEnMechaKoopa_c, Carry);

    /*
     * initializeState: VT+0x178 0x80A667D0
     * executeState:    VT+0x17C 0x80A66830
     * finalizeState:   VT+0x180 0x80A66820
     */
    sState_ExternVirtual(0x80B18A7C, daEnMechaKoopa_c, DieFall);
};
