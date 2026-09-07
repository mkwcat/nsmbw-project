#pragma once

#include "d_enemy.h"
#include "s_State.h"

class dCc_c;

class daEnShell_c : public dEn_c {
    SIZE_ASSERT(0x7DC);
    VTABLE(0x60, fBase_c, 0x80305C50);

public:
    // Structors
    // ^^^^^^

    /* 0x80037EF0 */
    daEnShell_c();

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x7C 0x80039610 */
    virtual void setCarryFall(dActor_c* actor, int cooldown) override;

    /* VT+0x8C 0x8003A5D0 */
    virtual bool setEatSpitOut(dActor_c* actor) override;

    /* VT+0xCC 0x800389E0 */
    virtual void Normal_VsPlHitCheck(dCc_c* self, dCc_c* other) override;

    /* VT+0xF0 0x80039D70 */
    virtual bool hitCallback_YoshiHipAttk(dCc_c* self, dCc_c* other) override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800396A0 */
    void setKickSlide(dCc_c* cc, dActor_c* actor);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x798);
    /* 0x798 */ bool m0x798;
    FILL(0x799, 0x7DC);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x28C 0x8003AE40
     * executeState:    VT+0x290 0x8003AEE0
     * finalizeState:   VT+0x294 0x8003AEB0
     */
    sState_ExternVirtual(0x80353CE4, daEnShell_c, Sleep);

    /*
     * initializeState: VT+0x280 0x8003B020
     * executeState:    VT+0x284 0x8003B200
     * finalizeState:   VT+0x288 0x8003B140
     */
    sState_ExternVirtual(0x80353D24, daEnShell_c, Carry);

    /*
     * initializeState: VT+0x298 0x8003B3E0
     * executeState:    VT+0x29C 0x8003B830
     * finalizeState:   VT+0x2A0 0x8003B6F0
     */
    sState_ExternVirtual(0x80353D64, daEnShell_c, Slide);

    /*
     * initializeState: VT+0x2A4 0x8003BB40
     * executeState:    VT+0x2A8 0x8003BBB0
     * finalizeState:   VT+0x2AC 0x8003BBA0
     */
    sState_ExternVirtual(0x80353DA4, daEnShell_c, Wakeup);

    /*
     * initializeState: VT+0x2B0 0x8003BD30
     * executeState:    VT+0x2B4 0x8003BD60
     * finalizeState:   VT+0x2B8 0x8003BD50
     */
    sState_ExternVirtual(0x80353DE4, daEnShell_c, WakeupReverse);

    /*
     * initializeState: VT+0x2BC 0x8003BC30
     * executeState:    VT+0x2C0 0x8003BC80
     * finalizeState:   VT+0x2C4 0x8003BC70
     */
    sState_ExternVirtual(0x80353E24, daEnShell_c, WakeupTurn);

    /*
     * initializeState: VT+0x178 0x8003BE00
     * executeState:    VT+0x17C 0x8003BE80
     * finalizeState:   VT+0x180 0x8003BE70
     */
    sState_ExternVirtual(0x80353E64, daEnShell_c, DieFall);
};
