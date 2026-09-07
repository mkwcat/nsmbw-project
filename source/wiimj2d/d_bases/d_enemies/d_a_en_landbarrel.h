#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnLandBarrel_c : public dEn_c {
    SIZE_ASSERT(0x578);
    VTABLE(0x060, fBase_c, 0x80AF8348);
    // 0x80AF8318 g_profile_EN_LANDBARREL
    // 0x80A57DE0 daEnLandBarrel_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnLandBarrel_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x578);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A58B90
     * executeState:    0x80A58BC0
     * finalizeState:   0x80A58BB0
     */
    sState_Extern(0x80B18270, daEnLandBarrel_c, Air_1st);

    /*
     * initializeState: 0x80A58CC0
     * executeState:    0x80A58D40
     * finalizeState:   0x80A58D30
     */
    sState_Extern(0x80B182B0, daEnLandBarrel_c, Air);

    /*
     * initializeState: 0x80A58EF0
     * executeState:    0x80A58F20
     * finalizeState:   0x80A58F10
     */
    sState_Extern(0x80B182F0, daEnLandBarrel_c, Move);

    /*
     * initializeState: 0x80A590D0
     * executeState:    0x80A59180
     * finalizeState:   0x80A59170
     */
    sState_Extern(0x80B18330, daEnLandBarrel_c, Break);
};
