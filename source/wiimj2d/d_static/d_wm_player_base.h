#pragma once

#include "d_static/d_wm_demo_actor.h"

class dWmPlayerBase_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x1C9);

public:
    // Structors
    // ^^^^^^

    dWmPlayerBase_c()
        : dWmDemoActor_c()
        , m_0x18C(false)
        , m_0x1A8(1)
        , m_0x1AC(-1)
        , m_0x1B0(-1)
        , m_0x1C8(-1) {}

public:
    // Virtual Methods
    // ^^^^^^

    /**
     * VT+0x58 0x808EF670 (weak)
     * Gets the actor kind. See ACTOR_KIND_e.
     */
    virtual ACTOR_KIND_e GetActorType() override;

    /**
     * VT+0x70
     */
    virtual void VT_0x70() = 0;

    /**
     * VT+0x74
     */
    virtual void VT_0x74() = 0;

    /**
     * VT+0x78 0x800FDE50
     */
    virtual void VT_0x78();

    /**
     * VT+0x7C 0x800FDE70
     */
    virtual void procDemoLose();

    /**
     * VT+0x80
     */
    virtual void VT_0x80() = 0;

    /**
     * VT+0x84 0x800FE020
     */
    virtual void VT_0x84();

public:
    // Inline Instance Methods
    // ++++++

    s32 getPlayerNo() const { return mParam & 0xF; }

public:
    // Instance Variables
    // ^^^^^^

    /* 0x184 */ dWmPlayerBase_c* mNextPlayer;
    /* 0x188 */ dWmPlayerBase_c* mPrevPlayer;

    /* 0x18C */ bool             m_0x18C;

    FILL(0x18D, 0x1A8);

    /* 0x1A8 */ u8  m_0x1A8;
    /* 0x1AC */ s32 m_0x1AC;
    /* 0x1B0 */ s32 m_0x1B0;

    FILL(0x1B4, 0x1C8);

    /* 0x1C8 */ u8 m_0x1C8;
};
