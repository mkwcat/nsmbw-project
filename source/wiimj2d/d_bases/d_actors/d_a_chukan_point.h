#pragma once

#include "d_actor_state.h"
#include "m_3d_anmtexpat.h"
#include "m_3d_mdl.h"
#include "s_State.h"

class daChukanPoint_c : public dActorState_c {
    SIZE_ASSERT(0x4E0);
    VTABLE(0x060, fBase_c, 0x80958510);
    // 0x809584B8 g_profile_CHUKAN_POINT
    // 0x807E2040 daChukanPoint_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daChukanPoint_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x807E2710 */
    void setCyuukanData();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x3F0);

    /* 0x3F0 */ m3d::mdl_c m_model;

    FILL(0x430, 0x46C);

    /* 0x46C */ m3d::anmTexPat_c m_anmTexPat;

    FILL(0x498, 0x4E0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807E2E10
     * executeState:    0x807E2EA0
     * finalizeState:   0x807E2E90
     */
    sState_Extern(0x80997D98, daChukanPoint_c, Wait);

    /*
     * initializeState: 0x807E2F30
     * executeState:    0x807E2FE0
     * finalizeState:   0x807E2FD0
     */
    sState_Extern(0x80997DD8, daChukanPoint_c, Swing);

    /*
     * initializeState: 0x807E30E0
     * executeState:    0x807E3170
     * finalizeState:   0x807E3160
     */
    sState_Extern(0x80997E18, daChukanPoint_c, SeaWait);

    /*
     * initializeState: 0x807E31E0
     * executeState:    0x807E3290
     * finalizeState:   0x807E3280
     */
    sState_Extern(0x80997E58, daChukanPoint_c, SeaSwing);
};
