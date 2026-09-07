#pragma once

#include "d_a_en_togezo_base.h"
#include "s_State.h"

class daEnSakasaTogezo_c : public daEnTogezoBase_c {
    SIZE_ASSERT(0x9D8);
    VTABLE(0x060, fBase_c, 0x80B0749C);
    // 0x80B07488 g_profile_EN_SAKASA_TOGEZO
    // 0x80A9B6A0 daEnSakasaTogezo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnSakasaTogezo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x9C4, 0x9D8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A9BF30
     * executeState:    0x80A9C060
     * finalizeState:   0x80A9C050
     */
    sState_Extern(0x80B1ABD0, daEnSakasaTogezo_c, Sakasa_Walk);

    /*
     * initializeState: 0x80A9C230
     * executeState:    0x80A9C270
     * finalizeState:   0x80A9C260
     */
    sState_Extern(0x80B1AC10, daEnSakasaTogezo_c, Sakasa_Turn);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x298 0x80A9C320
     * executeState:    VT+0x29C 0x80A9C340
     * finalizeState:   VT+0x2A0 0x80A9C330
     */
    sState_ExternVirtual(0x80B1AC4C, daEnSakasaTogezo_c, Slide);
};
