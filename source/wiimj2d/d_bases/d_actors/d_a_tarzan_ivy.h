#pragma once

#include "d_actor.h"
#include "d_allocator.h"
#include "d_pc.h"
#include "d_rot_shake.h"
#include "m_3d_anmchr.h"
#include "m_3d_mdl.h"

class daTarzanIvy_c : public dActor_c {
    // Original size: 0x888
    VTABLE(0x060, fBase_c, 0x8097D310);

public:
    // Structors
    // ^^^^^^

    daTarzanIvy_c();

public:
    // Nested Types
    // ^^^^^^

    class nodeCallback_c : m3d::mdl_c::callback_c {
        SIZE_ASSERT(0x8);
        VTABLE(0x0, m3d::mdl_c::callback_c, 0x8097D3E8);

    public:
        explicit nodeCallback_c(
            daTarzanIvy_c* parent
        )
            : m_parent(parent) {}

        /* VT+0x08 0x808AE0A0 */
        virtual ~nodeCallback_c() override;

        /* VT+0x10 0x808AE0E0 */
        virtual void timingB(u32, nw4r::g3d::WorldMtxManip*, nw4r::g3d::ResMdl) override;

        /* 0x4 */ daTarzanIvy_c* m_parent;
    };

    struct plrInfo_s {
        SIZE_ASSERT(0x10);

        /* 0x00 */ int   m_plrNo;
        /* 0x04 */ bool  m_isRide;
        /* 0x05 */ bool  m_isRidePrev;
        /* 0x08 */ float m_0x08;
        /* 0x0C */ float m_0x0C;

        operator bool() const { return m_plrNo >= 0 && m_plrNo < PLAYER_COUNT; }
    };

    struct plrInfo2_s {
        SIZE_ASSERT(0xC);

        /* 0x0 */ float m_0x0;
        /* 0x4 */ float m_0x4;
        /* 0x8 */ short m_angle;
        /* 0xA */ s8    m_plrNo;
        /* 0xB */ s8    m_plrNo2;

        operator bool() const { return m_plrNo >= 0 && m_plrNo < PLAYER_COUNT; }
    };

    struct rotData_s {
        SIZE_ASSERT(0x20);

        /* 0x00 */ dRotShake_c m_RotShake;
        /* 0x14 */ float       m_0x14;
        /* 0x18 */ float       m_0x18;
        /* 0x1C */ bool        m_inUse;
        /* 0x1D */ s8          m_plrNo;
        FILL(0x1E, 0x20);
    };

public:
    // Instance Methods
    // ^^^^^^

    /* 0x808AE310 */ void executePlrInfo(plrInfo2_s* pi2);
    /* 0x808AE5A0 */ float getHighFlt();
    /* 0x808AE690 */ void FUN_808AE690();
    /* 0x808AEF90 */ void FUN_808AEF90();

public:
    // Static Methods
    // ^^^^^^

    /* 0x808AE2F0 */ static void initPlrInfo2(plrInfo2_s* pi2);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x394 */ plrInfo_s        REMOVED(m_plrInfo)[4];
    /* 0x3D4 */ float            m_0x3D4;
    /* 0x3D8 */ bool             m_isRideAny;
    /* 0x3D9 */ bool             m_isRideAnyPrev;
    /* 0x3DC */ int              m_0x3DC;
    /* 0x3E0 */ float            m_0x3E0;
    /* 0x3E4 */ int              m_0x3E4;
    /* 0x3E8 */ int              m_0x3E8;
    /* 0x3EC */ int              m_0x3EC;
    /* 0x3F0 */ nodeCallback_c   m_nodeCallback{this};
    /* 0x3F8 */ dHeapAllocator_c m_allocator;
    /* 0x414 */ void*            m_pResFile{};
    /* 0x418 */ m3d::anmChr_c    m_anmChr;
    /* 0x450 */ m3d::mdl_c       m_model;
    /* 0x490 */ dPoleRope_c      m_pole{m_plrAngle};
    /* 0x4D0 */ dRotShake_c      m_RotShake;
    /* 0x4E4 */ plrInfo2_s       REMOVED(m_plrInfo2)[4];
    /* 0x514 */ rotData_s        m_rotData[16];
    /* 0x714 */ rotData_s*       m_selectRotData[16];
    /* 0x754 */ mVec2_c          m_0x754[17];
    /* 0x7DC */ float            m_0x7DC;
    /* 0x7E0 */ short            m_0x7E0[16];
    /* 0x802 */ short            m_0x800[64];
    /* 0x880 */ u8               m_0x880;
    /* 0x881 */ u8               m_0x881;
    FILL(0x882, 0x888);
    OFFSET_ASSERT(0x888);

    // Instance Variables
    // ++++++

    plrInfo_s  m_plrInfo[PLAYER_COUNT];
    plrInfo2_s m_plrInfo2[PLAYER_COUNT];
    short      m_plrAngle[PLAYER_COUNT];
};
