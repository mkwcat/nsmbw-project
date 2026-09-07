#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnJellyFish_c : public dEn_c {
    SIZE_ASSERT(0x8D0);
    VTABLE(0x060, fBase_c, 0x80AF2330);
    // 0x80AF2210 g_profile_EN_JELLY_FISH
    // 0x80A2E810 daEnJellyFish_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnJellyFish_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x8D0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A30010
     * executeState:    0x80A300D0
     * finalizeState:   0x80A300C0
     */
    sState_Extern(0x80B16BD8, daEnJellyFish_c, Wait);

    /*
     * initializeState: 0x80A2F8C0
     * executeState:    0x80A2F970
     * finalizeState:   0x80A2F960
     */
    sState_Extern(0x80B16C18, daEnJellyFish_c, MoveUp);

    /*
     * initializeState: 0x80A2FC00
     * executeState:    0x80A2FCC0
     * finalizeState:   0x80A30000
     */
    sState_Extern(0x80B16C58, daEnJellyFish_c, MoveDown);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x80A30220
     * executeState:    VT+0x17C 0x80A30320
     * finalizeState:   VT+0x180 0x80A30310
     */
    sState_ExternVirtual(0x80B16C94, daEnJellyFish_c, DieFall);

    /*
     * initializeState: VT+0x1FC 0x80A30500
     * executeState:    VT+0x200 0x80A30580
     * finalizeState:   VT+0x204 0x80A30600
     */
    sState_ExternVirtual(0x80B16CD4, daEnJellyFish_c, Ice);
};
