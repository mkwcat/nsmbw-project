#pragma once

#include "d_a_ice_ashiba_base.h"
#include "s_State.h"

class daIceAshibaWater_c : public daIceAshibaBase_c {
    SIZE_ASSERT(0x508);
    VTABLE(0x060, fBase_c, 0x8095D56C);
    // 0x8095D560 g_profile_ICE_ASHIBA_WATER
    // 0x807FF230 daIceAshibaWater_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daIceAshibaWater_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x4E4, 0x508);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807FF680
     * executeState:    0x807FF6B0
     * finalizeState:   0x807FF6A0
     */
    sState_Extern(0x80998E90, daIceAshibaWater_c, MoveUnderWaterAppear);

    /*
     * initializeState: 0x807FF710
     * executeState:    0x807FF730
     * finalizeState:   0x807FF720
     */
    sState_Extern(0x80998ED0, daIceAshibaWater_c, MoveUpperWater);

    /*
     * initializeState: 0x807FF7D0
     * executeState:    0x807FF7F0
     * finalizeState:   0x807FF7E0
     */
    sState_Extern(0x80998F10, daIceAshibaWater_c, MoveUnderWater);

    /*
     * initializeState: 0x807FF890
     * executeState:    0x807FF8B0
     * finalizeState:   0x807FF8A0
     */
    sState_Extern(0x80998F50, daIceAshibaWater_c, MoveUnderWaterDisappear);

    /*
     * initializeState: 0x807FF950
     * executeState:    0x807FF970
     * finalizeState:   0x807FF960
     */
    sState_Extern(0x80998F90, daIceAshibaWater_c, Quit);
};
