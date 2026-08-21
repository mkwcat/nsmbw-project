#pragma once

#include "d_static/d_enemy.h"
#include "state/s_State.h"

class dCc_c;

class daEnShell_c : public dEn_c
{
public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x7C 0x80039610 */
    virtual void setCarryFall(dActor_c* actor, int cooldown) override;

    /* VT+0x8C 0x8003A5D0 */
    virtual bool setEatSpitOut(dActor_c* actor) override;

    /* VT+0xCC 0x800389E0 */
    virtual void Normal_VsPlHitCheck(dCc_c* self, dCc_c* other) override;

    /* VT+0xF0 0x80039D70 */
    virtual bool hitCallback_YoshiHipAttk(dCc_c* self, dCc_c* other) override;

    // Virtual States
    // ^^^^^^

    /**
     * VT+?
     * initializeState_Slide: VT+? 0x8003B3E0
     * executeState_Slide:    VT+? 0x8003B830
     */
    sState_Extern(0x80353D64, daEnShell_c, Slide);

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800396A0 */
    void setKickSlide(dCc_c* cc, dActor_c* actor);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x798);
    OFFSET_ASSERT(0x798);

    /* 0x798 */ bool m0x798;
};
