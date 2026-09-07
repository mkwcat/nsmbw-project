#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnJumpPuku_c : public dEn_c {
    SIZE_ASSERT(0x608);
    VTABLE(0x060, fBase_c, 0x80AF43C0);
    // 0x80AF4378 g_profile_EN_JUMPPUKU
    // 0x80A3AEF0 daEnJumpPuku_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnJumpPuku_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x608);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A3BDD0
     * executeState:    0x80A3BE90
     * finalizeState:   0x80A3BE80
     */
    sState_Extern(0x80B171E8, daEnJumpPuku_c, Swim);

    /*
     * initializeState: 0x80A3C000
     * executeState:    0x80A3C100
     * finalizeState:   0x80A3C0F0
     */
    sState_Extern(0x80B17228, daEnJumpPuku_c, JumpWait);

    /*
     * initializeState: 0x80A3C1F0
     * executeState:    0x80A3C220
     * finalizeState:   0x80A3C210
     */
    sState_Extern(0x80B17268, daEnJumpPuku_c, JumpReary);

    /*
     * initializeState: 0x80A3C300
     * executeState:    0x80A3C370
     * finalizeState:   0x80A3C350
     */
    sState_Extern(0x80B172A8, daEnJumpPuku_c, Jump);

    /*
     * initializeState: 0x80A3BD50
     * executeState:    0x80A3BD90
     * finalizeState:   0x80A3BD80
     */
    sState_Extern(0x80B172E8, daEnJumpPuku_c, HitSpinDown);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x1C0 0x80A3C4E0
     * executeState:    VT+0x1C4 0x80A3C580
     * finalizeState:   VT+0x1C8 0x80A3C570
     */
    sState_ExternVirtual(0x80B17324, daEnJumpPuku_c, DieOther);

    /*
     * initializeState: VT+0x1F0 0x80A3BC80
     * executeState:    VT+0x1F4 0x80A3BCE0
     * finalizeState:   VT+0x1F8 0x80A3BCD0
     */
    sState_ExternVirtual(0x80B17364, daEnJumpPuku_c, HitSpin);

    /*
     * initializeState: VT+0x1E4 0x80A3C6B0
     * executeState:    VT+0x1E8 0x80A3C810
     * finalizeState:   VT+0x1EC 0x80A3C800
     */
    sState_ExternVirtual(0x80B173A4, daEnJumpPuku_c, EatOut);
};
