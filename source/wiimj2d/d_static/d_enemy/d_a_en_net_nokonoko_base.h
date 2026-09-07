#pragma once

#include "d_enemy.h"

class daEnNetNoko_c : public dEn_c {
    SIZE_ASSERT(0x600);
    VTABLE(0x60, fBase_c, 0x8030563C);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x600);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x16C 0x80035F10
     * executeState:    VT+0x170 0x80035FA0
     * finalizeState:   VT+0x174 0x80035F90
     */
    sState_ExternVirtual(0x80353A6C, daEnNetNoko_c, DieFumi);

    /*
     * initializeState: VT+0x178 0x80036060
     * executeState:    VT+0x17C 0x80036120
     * finalizeState:   VT+0x180 0x80036110
     */
    sState_ExternVirtual(0x80353AAC, daEnNetNoko_c, DieFall);
};
