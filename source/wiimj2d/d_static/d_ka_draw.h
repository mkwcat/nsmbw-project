#pragma once

#include "d_static/d_allocator.h"
#include "machine/m_3d_mdl.h"
#include "machine/m_vec.h"

class dKADr_c {
    SIZE_ASSERT(0x11E);

public:
    // Structors
    // ^^^^^^

    dKADr_c()
        : m_nodeCallback(nodeCallback_c{this})
        , m_0x024(0.0f) {}

public:
    // Nested Types
    // ^^^^^^

    class nodeCallback_c : m3d::mdl_c::callback_c {
        SIZE_ASSERT(0x8);
        VTABLE(0x0, m3d::mdl_c::callback_c, 0x80315EF8);

    public:
        nodeCallback_c(
            dKADr_c* parent
        )
            : m_parent(parent) {}

        /* VT+0x08 0x800BC2F0 */
        virtual ~nodeCallback_c() override;

        /* VT+0x10 0x800BC190 */
        virtual void timingB(u32, nw4r::g3d::WorldMtxManip*, nw4r::g3d::ResMdl) override;

        /* 0x4 */ dKADr_c* m_parent;
    };

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800BBF60 */
    void init(u16);

    /* 0x800BBE60 */
    void calc_vtx_pos();

    /* 0x800BBFC0 */
    void move(const mVec3_c&);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x000 */ nodeCallback_c   m_nodeCallback;
    /* 0x008 */ dHeapAllocator_c m_allocator;
    /* 0x024 */ float            m_0x024;
    /* 0x028 */ m3d::mdl_c       m_model;
    /* 0x068 */ mVec3_c          m_0x068;
    /* 0x074 */ mVec3_c          m_0x074[8];
    /* 0x0D4 */ mVec3_c          m_0x0D4[6];
    /* 0x11C */ u16              m_0x11C;
};
