#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daObjLarry_c : public dEn_c {
    SIZE_ASSERT(0x810);
    VTABLE(0x060, fBase_c, 0x809743C8);
    // 0x809742F0 g_profile_OBJ_LARRY
    // 0x8087FE10 daObjLarry_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daObjLarry_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x810);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x808808D0
     * executeState:    VT+0x284 0x808809D0
     * finalizeState:   VT+0x288 0x80880A80
     */
    sState_ExternVirtual(0x8099D7DC, daObjLarry_c, Stop);

    /*
     * initializeState: VT+0x28C 0x80880A90
     * executeState:    VT+0x290 0x80880B30
     * finalizeState:   VT+0x294 0x80880F30
     */
    sState_ExternVirtual(0x8099D81C, daObjLarry_c, Start);

    /*
     * initializeState: VT+0x298 0x80880F40
     * executeState:    VT+0x29C 0x80880F90
     * finalizeState:   VT+0x2A0 0x808810E0
     */
    sState_ExternVirtual(0x8099D85C, daObjLarry_c, Move);

    /*
     * initializeState: VT+0x2A4 0x808810F0
     * executeState:    VT+0x2A8 0x80881180
     * finalizeState:   VT+0x2AC 0x80881300
     */
    sState_ExternVirtual(0x8099D89C, daObjLarry_c, Brake);
};
