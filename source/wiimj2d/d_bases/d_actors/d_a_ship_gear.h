#pragma once

#include "d_actor_state.h"
#include "d_allocator.h"
#include "d_bg_ctr.h"
#include "m_3d_mdl.h"

class daShipGear_c : public dActorState_c {
    // Original size: 0x540
    VTABLE(0x060, fBase_c, 0x8097AF78);
    // 0x8097AF18 g_profile_AC_SHIP_GEAR
    // 0x808A1FD0 daShipGear_c_classInit

public:
    // Structors
    // ^^^^^^

    daShipGear_c();

    /* VT+0x08 */
    // virtual ~daShipGear_c() override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x808A2380 */
    void setRideOn(dActor_c* actor);

    /* 0x808A24B0 */
    void executeRide();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x3D0 */ dHeapAllocator_c m_allocator;
    /* 0x3EC */ void*            m_pResFile{};
    /* 0x3F0 */ m3d::mdl_c       m_model;
    /* 0x430 */ dBg_ctr_c        m_bg;
    /* 0x514 */ int              m_prmSize;
    /* 0x518 */ int              m_exitRide;
    /* 0x51C */ short            m_rotSpeed;
    /* 0x520 */ float            m_bgScale;
    OFFSET_ASSERT(0x524);

    union {
        struct {
            /* 0x524 */ float REMOVED(m_plrOffset)[4];
            /* 0x534 */ bool  REMOVED(m_plrRideOn)[4];
            /* 0x538 */ bool  REMOVED(m_plrRideOnPrev)[8];
            FILL(0x538, 0x53C);
        };

        /* 0x524+ */ float m_plrOffset[PLAYER_COUNT];
    };

    // Instance Variables
    // ++++++

    bool m_plrRideOn[PLAYER_COUNT];
    bool m_plrRideOnPrev[PLAYER_COUNT];
};
