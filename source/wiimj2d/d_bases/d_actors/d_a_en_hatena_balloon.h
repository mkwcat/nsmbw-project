#pragma once

#include "d_actor.h"
#include "d_allocator.h"
#include "d_enemy.h"
#include "d_profile.h"
#include "m_3d_anmchr.h"
#include "m_3d_anmtexpat.h"
#include "m_3d_anmtexsrt.h"
#include "m_3d_mdl.h"
#include "s_State.h"

class daEnHatenaBalloon_c : public dEn_c,
                            public dProf::Info<daEnHatenaBalloon_c, dProf::EN_HATENA_BALLOON> {
    SIZE_ASSERT(0x8A0);
    VTABLE(0x060, fBase_c, 0x803236B0);
    // 0x80323620 g_profile_EN_HATENA_BALLOON
    // 0x801102B0 daEnHatenaBalloon_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnHatenaBalloon_c();

public:
    // Nested Types
    // ^^^^^^

    struct Param_s {
        u32             : 15;
        u32 green_demon : 1 = 0; // +++
        u32 has_item    : 4 = 0;
        u32 unk         : 4 = 0;
        u32 player      : 4 = 0;
    };

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80110DE0 */
    void PlYsHitCheck(dActor_c* actor, daEnHatenaBalloon_c* balloon);

    /* 0x80111990 */
    void model_set();

    /* 0x80111EC0 */
    void anm_set(int);

    /* 0x80112110 */
    void createItem();

    /* 0x80113090 */
    void remocon_speed_set();

    /* 0x80113400 */
    void remocon_times_check();

    /* 0x801134F0 */
    void remocon_shake_check();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x524 */ dHeapAllocator_c   mAllocator;
    /* 0x540 */ nw4r::g3d::ResFile mResFile;
    /* 0x544 */ m3d::mdl_c         mModel;
    /* 0x584 */ m3d::mdl_c         mModelBack;
    /* 0x5C4 */ m3d::anmChr_c      mAnmChr;
    /* 0x5FC */ m3d::anmChr_c      mAnmChrBack;
    /* 0x634 */ m3d::anmTexPat_c   mAnmTexPat;
    /* 0x660 */ m3d::anmTexPat_c   mAnmTexPatBack;
    /* 0x68C */ m3d::anmTexSrt_c   mAnmTexSrt;
    /* 0x6B8 */ m3d::mdl_c         mItemModel;
    /* 0x6F8 */ m3d::anmChr_c      mItemAnmChr;
    /* 0x730 */ m3d::anmTexPat_c   mItemAnmTexPat;

    FILL(0x75C, 0x7A4);

    /* 0x7A4 */ mVec3_c mItemScale;

    FILL(0x7B0, 0x7E0);

    /* 0x7E0 */ int m_shake_check_timer;
    /* 0x7E4 */ int m_countdown_anm;

    FILL(0x7E8, 0x7EC);

    /* 0x7EC */ int mHasItem;

    FILL(0x7F0, 0x810);

    /* 0x810 */ u32 mPlayerNo;

    FILL(0x814, 0x86C);

    /* 0x86C */ bool    mPopReady;

    /* 0x870 */ mVec3_c mBalloonPopPos;

    FILL(0x87C, 0x8A0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x801138D0
     * executeState:    0x80113A90
     * finalizeState:   0x80113A80
     */
    sState_Extern(0x80375408, daEnHatenaBalloon_c, DispFlyWait);

    /*
     * initializeState: 0x80113BF0
     * executeState:    0x80113C20
     * finalizeState:   0x80113C10
     */
    sState_Extern(0x80375448, daEnHatenaBalloon_c, DispFlyMove);

    /*
     * initializeState: 0x80113DC0
     * executeState:    0x80113E00
     * finalizeState:   0x80113DF0
     */
    sState_Extern(0x80375488, daEnHatenaBalloon_c, Fly);

    /*
     * initializeState: 0x80113ED0
     * executeState:    0x80113F80
     * finalizeState:   0x80113F70
     */
    sState_Extern(0x803754C8, daEnHatenaBalloon_c, Escape);

    /*
     * initializeState: 0x801140C0
     * executeState:    0x801140E0
     * finalizeState:   0x801140D0
     */
    sState_Extern(0x80375508, daEnHatenaBalloon_c, HipAttack);

    /*
     * initializeState: 0x80114140
     * executeState:    0x80114190
     * finalizeState:   0x80114160
     */
    sState_Extern(0x80375548, daEnHatenaBalloon_c, SearchSpace);
};
