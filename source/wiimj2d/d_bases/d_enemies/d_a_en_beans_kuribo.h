#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnBeansKuribo_c : public dEn_c {
    SIZE_ASSERT(0x618);
    VTABLE(0x060, fBase_c, 0x80AD7AA8);
    // 0x80AD7A50 g_profile_EN_BEANS_KURIBO
    // 0x809AFFF0 daEnBeansKuribo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBeansKuribo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x618);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809B0E30
     * executeState:    0x809B0EC0
     * finalizeState:   0x809B0EB0
     */
    sState_Extern(0x80B11D38, daEnBeansKuribo_c, Walk);

    /*
     * initializeState: 0x809B1010
     * executeState:    0x809B1050
     * finalizeState:   0x809B1040
     */
    sState_Extern(0x80B11D78, daEnBeansKuribo_c, Turn);

    /*
     * initializeState: 0x809B10F0
     * executeState:    0x809B1220
     * finalizeState:   0x809B1210
     */
    sState_Extern(0x80B11DB8, daEnBeansKuribo_c, Around);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x809B15F0
     * executeState:    VT+0x17C 0x809B1610
     * finalizeState:   VT+0x180 0x809B1600
     */
    sState_ExternVirtual(0x80B11DF4, daEnBeansKuribo_c, DieFall);
};
