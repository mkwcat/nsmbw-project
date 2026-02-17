#pragma once

#include "d_profile/d_profile.h"
#include "d_system/d_actor.h"
#include "d_system/d_allocator.h"
#include "d_system/d_enemy.h"
#include "machine/m_3d_anmchr.h"
#include "machine/m_3d_anmtexpat.h"
#include "machine/m_3d_anmtexsrt.h"
#include "machine/m_3d_mdl.h"

class daEnHatenaBalloon_c : public dEn_c,
                            public dProf::Info<daEnHatenaBalloon_c, dProf::EN_HATENA_BALLOON>
{
    SIZE_ASSERT(0x8A0);

public:
    // Nested Types
    // ^^^^^^

    struct Param_s {
        u32 : 15;
        u32 green_demon : 1 = 0; // +++
        u32 has_item : 4 = 0;
        u32 unk : 4 = 0;
        u32 player : 4 = 0;
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

    /* 0x524 */ dHeapAllocator_c mAllocator;
    /* 0x540 */ nw4r::g3d::ResFile mResFile;
    /* 0x544 */ m3d::mdl_c mModel;
    /* 0x584 */ m3d::mdl_c mModelBack;
    /* 0x5C4 */ m3d::anmChr_c mAnmChr;
    /* 0x5FC */ m3d::anmChr_c mAnmChrBack;
    /* 0x634 */ m3d::anmTexPat_c mAnmTexPat;
    /* 0x660 */ m3d::anmTexPat_c mAnmTexPatBack;
    /* 0x68C */ m3d::anmTexSrt_c mAnmTexSrt;
    /* 0x6B8 */ m3d::mdl_c mItemModel;
    /* 0x6F8 */ m3d::anmChr_c mItemAnmChr;
    /* 0x730 */ m3d::anmTexPat_c mItemAnmTexPat;

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

    /* 0x86C */ bool mPopReady;

    /* 0x870 */ mVec3_c mBalloonPopPos;

    FILL(0x87C, 0x8A0);
};