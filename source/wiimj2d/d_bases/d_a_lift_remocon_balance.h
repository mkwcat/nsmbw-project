#pragma once

#include "d_static/d_actor/d_a_lift_remocon_main.h"
#include "d_static/d_allocator.h"
#include "d_static/d_rot_shake.h"
#include "machine/m_3d_anmchr.h"
#include "machine/m_3d_anmtexpat.h"

class daRemoconBalance_c : public daLiftRemoconMain_c {
    // Original size: 0x668
    VTABLE(0x060, fBase_c, 0x80967CE8);

public:
    // Structors
    // ^^^^^^

    /* Stripped */
    daRemoconBalance_c();

public:
    // Nested Types
    // ^^^^^^

    class nodeCallbackA_c : m3d::mdl_c::callback_c {
        SIZE_ASSERT(0x8);
        VTABLE(0x0, m3d::mdl_c::callback_c, 0x80967DE8);

    public:
        explicit constexpr nodeCallbackA_c(
            daRemoconBalance_c* parent
        )
            : m_parent(parent) {}

        /* VT+0x08 0x8083C140 */
        virtual ~nodeCallbackA_c() override;

        /* VT+0x0C 0x8083CA80 */
        virtual void timingA(u32, nw4r::g3d::ChrAnmResult*, nw4r::g3d::ResMdl) override;

        /* 0x4 */ daRemoconBalance_c* m_parent;
    };

    class nodeCallbackB_c : m3d::mdl_c::callback_c {
        SIZE_ASSERT(0x8);
        VTABLE(0x0, m3d::mdl_c::callback_c, 0x80967DD0);

    public:
        explicit constexpr nodeCallbackB_c(
            daRemoconBalance_c* parent
        )
            : m_parent(parent) {}

        /* VT+0x08 0x8083C180 */
        virtual ~nodeCallbackB_c() override;

        /* VT+0x0C 0x8083CC50 */
        virtual void timingA(u32, nw4r::g3d::ChrAnmResult*, nw4r::g3d::ResMdl) override;

        /* 0x4 */ daRemoconBalance_c* m_parent;
    };

public:
    // Instance Methods
    // ^^^^^^

    void FUN_8083D380();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x454 */ nodeCallbackA_c m_nodeCallbackA{this};
    /* 0x45C */ nodeCallbackB_c m_nodeCallbackB{this};
    FILL(0x464, 0x468);
    /* 0x468 */ dHeapAllocator_c m_allocator;
    /* 0x484 */ void*            m_pResFile{};
    /* 0x488 */ m3d::mdl_c       m_modelA;
    /* 0x4C8 */ m3d::mdl_c       m_modelB;
    /* 0x508 */ m3d::mdl_c       m_modelC;
    /* 0x548 */ m3d::anmChr_c    m_anmChr;
    /* 0x580 */ m3d::anmTexPat_c m_anmTexPatA;
    /* 0x5AC */ m3d::anmTexPat_c m_anmTexPatB;
    /* 0x5D8 */ dRotShake_c      m_RotShake;
    FILL(0x5EC, 0x618);
    /* 0x618 */ int REMOVED(m_0x618)[4];

    FILL(0x628, 0x668);
    OFFSET_ASSERT(0x668);

    // Instance Variables
    // ++++++

    int m_0x618[PLAYER_COUNT];
};
