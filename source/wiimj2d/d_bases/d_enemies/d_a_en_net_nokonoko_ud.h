#pragma once

#include "d_a_en_net_nokonoko_base.h"
#include "s_State.h"

class daEnNetNokoUD_c : public daEnNetNoko_c {
    SIZE_ASSERT(0x600);
    VTABLE(0x060, fBase_c, 0x80AFD860);
    // 0x80AFD830 g_profile_EN_NET_NOKONOKO_UD
    // 0x80A711E0 daEnNetNokoUD_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnNetNokoUD_c();

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A715A0
     * executeState:    0x80A716E0
     * finalizeState:   0x80A716D0
     */
    sState_Extern(0x80B19190, daEnNetNokoUD_c, Move);

    /*
     * initializeState: 0x80A71810
     * executeState:    0x80A71950
     * finalizeState:   0x80A71940
     */
    sState_Extern(0x80B191D0, daEnNetNokoUD_c, Turn_St);

    /*
     * initializeState: 0x80A719C0
     * executeState:    0x80A71AE0
     * finalizeState:   0x80A71AD0
     */
    sState_Extern(0x80B19210, daEnNetNokoUD_c, Turn_Ed);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x28C 0x80A71C60
     * executeState:    VT+0x290 0x80A71CC0
     * finalizeState:   VT+0x294 0x80A71C70
     */
    sState_ExternVirtual(0x80B1924C, daEnNetNokoUD_c, NetMove);
};
