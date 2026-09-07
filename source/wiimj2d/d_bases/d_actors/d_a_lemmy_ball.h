#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daLemmyBall_c : public dEn_c {
    SIZE_ASSERT(0x8A0);
    VTABLE(0x060, fBase_c, 0x80965880);
    // 0x80965738 g_profile_LEMMY_BALL
    // 0x80830C40 daLemmyBall_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLemmyBall_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x8A0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80831A50
     * executeState:    0x80831AE0
     * finalizeState:   0x80831AD0
     */
    sState_Extern(0x8099AB88, daLemmyBall_c, AttackSt);

    /*
     * initializeState: 0x80831B50
     * executeState:    0x80831BE0
     * finalizeState:   0x80831BD0
     */
    sState_Extern(0x8099ABC8, daLemmyBall_c, AttackSearch);

    /*
     * initializeState: 0x80831C50
     * executeState:    0x80831CE0
     * finalizeState:   0x80831CD0
     */
    sState_Extern(0x8099AC08, daLemmyBall_c, Attack);

    /*
     * initializeState: 0x80831D50
     * executeState:    0x80831DE0
     * finalizeState:   0x80831DD0
     */
    sState_Extern(0x8099AC48, daLemmyBall_c, AttackEnd);

    /*
     * initializeState: 0x80832060
     * executeState:    0x80832120
     * finalizeState:   0x80832110
     */
    sState_Extern(0x8099ACC8, daLemmyBall_c, Fall);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x2BC 0x808318A0
     * executeState:    VT+0x2C0 0x808318C0
     * finalizeState:   VT+0x2C4 0x808318B0
     */
    sState_ExternVirtual(0x8099AB04, daLemmyBall_c, Wait);

    /*
     * initializeState: VT+0x30C 0x80831930
     * executeState:    VT+0x310 0x808319E0
     * finalizeState:   VT+0x314 0x808319D0
     */
    sState_ExternVirtual(0x8099AB44, daLemmyBall_c, Chase);

    /*
     * initializeState: VT+0x318 0x80831E50
     * executeState:    VT+0x31C 0x80831F00
     * finalizeState:   VT+0x320 0x80831EF0
     */
    sState_ExternVirtual(0x8099AC84, daLemmyBall_c, Revival);

    /*
     * initializeState: VT+0x324 0x80832190
     * executeState:    VT+0x328 0x80832260
     * finalizeState:   VT+0x32C 0x80832250
     */
    sState_ExternVirtual(0x8099AD04, daLemmyBall_c, DemoWait);

    /*
     * initializeState: VT+0x330 0x80832270
     * executeState:    VT+0x334 0x80832320
     * finalizeState:   VT+0x338 0x80832310
     */
    sState_ExternVirtual(0x8099AD44, daLemmyBall_c, DemoAwake);

    /*
     * initializeState: VT+0x33C 0x80832330
     * executeState:    VT+0x340 0x808323E0
     * finalizeState:   VT+0x344 0x808323D0
     */
    sState_ExternVirtual(0x8099AD84, daLemmyBall_c, DemoAwake_Wait);

    /*
     * initializeState: VT+0x348 0x808323F0
     * executeState:    VT+0x34C 0x808324A0
     * finalizeState:   VT+0x350 0x80832490
     */
    sState_ExternVirtual(0x8099ADC4, daLemmyBall_c, DemoIkaku);

    /*
     * initializeState: VT+0x354 0x808324B0
     * executeState:    VT+0x358 0x80832560
     * finalizeState:   VT+0x35C 0x80832550
     */
    sState_ExternVirtual(0x8099AE04, daLemmyBall_c, DemoIkaku_Wait);
};
