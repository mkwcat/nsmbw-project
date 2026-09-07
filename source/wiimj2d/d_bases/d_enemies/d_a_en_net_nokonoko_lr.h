#pragma once

#include "d_a_en_net_nokonoko_base.h"
#include "s_State.h"

class daEnNetNokoLR_c : public daEnNetNoko_c {
    SIZE_ASSERT(0x608);
    VTABLE(0x060, fBase_c, 0x80AFD4A8);
    // 0x80AFD490 g_profile_EN_NET_NOKONOKO_LR
    // 0x80A70640 daEnNetNokoLR_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnNetNokoLR_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x600, 0x608);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A70960
     * executeState:    0x80A70AA0
     * finalizeState:   0x80A70A90
     */
    sState_Extern(0x80B19100, daEnNetNokoLR_c, Move);

    /*
     * initializeState: 0x80A70B90
     * executeState:    0x80A70CA0
     * finalizeState:   0x80A70C90
     */
    sState_Extern(0x80B19140, daEnNetNokoLR_c, Turn);
};
