#pragma once

#include "d_system/d_actor_state.h"
#include "machine/m_3d_anmtexpat.h"
#include "machine/m_3d_mdl.h"

class daChukanPoint_c : public dActorState_c {
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
};
