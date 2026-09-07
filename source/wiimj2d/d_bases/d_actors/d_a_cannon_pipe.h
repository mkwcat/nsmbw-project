#pragma once

#include "d_a_move_pipe.h"
#include "s_State.h"

class daCannonPipe_c : public daMovePipe_c {
    SIZE_ASSERT(0x770);
    VTABLE(0x060, fBase_c, 0x80955F30);
    // 0x80955EE8 g_profile_CANNON_PIPE
    // 0x807D63E0 daCannonPipe_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daCannonPipe_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x450, 0x770);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807D7550
     * executeState:    0x807D7580
     * finalizeState:   0x807D7570
     */
    sState_Extern(0x80997308, daCannonPipe_c, Wait);

    /*
     * initializeState: 0x807D75B0
     * executeState:    0x807D75F0
     * finalizeState:   0x807D75E0
     */
    sState_Extern(0x80997348, daCannonPipe_c, PilderOn);

    /*
     * initializeState: 0x807D7670
     * executeState:    0x807D7690
     * finalizeState:   0x807D7680
     */
    sState_Extern(0x80997388, daCannonPipe_c, CanstWait);

    /*
     * initializeState: 0x807D76C0
     * executeState:    0x807D7730
     * finalizeState:   0x807D7720
     */
    sState_Extern(0x809973C8, daCannonPipe_c, CannonSet);

    /*
     * initializeState: 0x807D77F0
     * executeState:    0x807D7810
     * finalizeState:   0x807D7800
     */
    sState_Extern(0x80997408, daCannonPipe_c, WaitShoot3);

    /*
     * initializeState: 0x807D7840
     * executeState:    0x807D7860
     * finalizeState:   0x807D7850
     */
    sState_Extern(0x80997448, daCannonPipe_c, WaitShoot2);

    /*
     * initializeState: 0x807D78B0
     * executeState:    0x807D78D0
     * finalizeState:   0x807D78C0
     */
    sState_Extern(0x80997488, daCannonPipe_c, WaitShoot);

    /*
     * initializeState: 0x807D7920
     * executeState:    0x807D7940
     * finalizeState:   0x807D7930
     */
    sState_Extern(0x809974C8, daCannonPipe_c, Return);
};
