#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnBrosBase_c : public dEn_c {
    SIZE_ASSERT(0x84C);
    VTABLE(0x060, fBase_c, 0x80302714);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x84C);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x80024F60
     * executeState:    VT+0x284 0x80025030
     * finalizeState:   VT+0x288 0x80025020
     */
    sState_ExternVirtual(0x80352EB4, daEnBrosBase_c, Move);

    /*
     * initializeState: VT+0x28C 0x800252A0
     * executeState:    VT+0x290 0x800252F0
     * finalizeState:   VT+0x294 0x800252E0
     */
    sState_ExternVirtual(0x80352EF4, daEnBrosBase_c, Attack);

    /*
     * initializeState: VT+0x298 0x80025550
     * executeState:    VT+0x29C 0x800255B0
     * finalizeState:   VT+0x2A0 0x800255A0
     */
    sState_ExternVirtual(0x80352F34, daEnBrosBase_c, JumpSt);

    /*
     * initializeState: VT+0x2A4 0x800256C0
     * executeState:    VT+0x2A8 0x800256E0
     * finalizeState:   VT+0x2AC 0x800256D0
     */
    sState_ExternVirtual(0x80352F74, daEnBrosBase_c, Jump);

    /*
     * initializeState: VT+0x2B0 0x80025A00
     * executeState:    VT+0x2B4 0x80025AD0
     * finalizeState:   VT+0x2B8 0x80025AC0
     */
    sState_ExternVirtual(0x80352FB4, daEnBrosBase_c, JumpEd);

    /*
     * initializeState: VT+0x2BC 0x800257A0
     * executeState:    VT+0x2C0 0x80025800
     * finalizeState:   VT+0x2C4 0x800257F0
     */
    sState_ExternVirtual(0x80352FF4, daEnBrosBase_c, AirAttack);

    /*
     * initializeState: VT+0x16C 0x80025B80
     * executeState:    VT+0x170 0x80025BD0
     * finalizeState:   VT+0x174 0x80025BC0
     */
    sState_ExternVirtual(0x80353034, daEnBrosBase_c, DieFumi);

    /*
     * initializeState: VT+0x178 0x80025C40
     * executeState:    VT+0x17C 0x80025C90
     * finalizeState:   VT+0x180 0x80025C80
     */
    sState_ExternVirtual(0x80353074, daEnBrosBase_c, DieFall);
};
