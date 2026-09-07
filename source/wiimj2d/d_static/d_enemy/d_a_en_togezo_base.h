#pragma once

#include "d_a_en_shell.h"

class daEnTogezoBase_c : public daEnShell_c {
    SIZE_ASSERT(0x9C4);
    VTABLE(0x60, fBase_c, 0x803066F8);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x7DC, 0x9C4);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8003F010
     * executeState:    0x8003F180
     * finalizeState:   0x8003F170
     */
    sState_Extern(0x80353FA8, daEnTogezoBase_c, Walk);

    /*
     * initializeState: 0x8003ED70
     * executeState:    0x8003EDD0
     * finalizeState:   0x8003EDB0
     */
    sState_Extern(0x80353FE8, daEnTogezoBase_c, Pipo);

    /*
     * initializeState: 0x8003F530
     * executeState:    0x8003F5E0
     * finalizeState:   0x8003F550
     */
    sState_Extern(0x80354028, daEnTogezoBase_c, Change_Pipo);

    /*
     * initializeState: 0x8003F6B0
     * executeState:    0x8003F7D0
     * finalizeState:   0x8003F7B0
     */
    sState_Extern(0x80354068, daEnTogezoBase_c, Change_Togezo);

    /*
     * initializeState: 0x8003F360
     * executeState:    0x8003F430
     * finalizeState:   0x8003F420
     */
    sState_Extern(0x803540A8, daEnTogezoBase_c, Turn);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x8003EC40
     * executeState:    VT+0x17C 0x8003EC90
     * finalizeState:   VT+0x180 0x8003EC80
     */
    sState_ExternVirtual(0x803540E4, daEnTogezoBase_c, DieFall);

    /*
     * initializeState: VT+0x2A4 0x8003F8B0
     * executeState:    VT+0x2A8 0x8003F8D0
     * finalizeState:   VT+0x2AC 0x8003F8C0
     */
    sState_ExternVirtual(0x80354124, daEnTogezoBase_c, Wakeup);

    /*
     * initializeState: VT+0x2BC 0x8003F920
     * executeState:    VT+0x2C0 0x8003F9A0
     * finalizeState:   VT+0x2C4 0x8003F990
     */
    sState_ExternVirtual(0x80354164, daEnTogezoBase_c, WakeupTurn);

    /*
     * initializeState: VT+0x2B0 0x8003F9F0
     * executeState:    VT+0x2B4 0x8003FB10
     * finalizeState:   VT+0x2B8 0x8003FB00
     */
    sState_ExternVirtual(0x803541A4, daEnTogezoBase_c, WakeupReverse);
};
