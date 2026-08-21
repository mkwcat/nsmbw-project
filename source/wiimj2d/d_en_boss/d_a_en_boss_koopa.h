#pragma once

#include "d_static/d_ef/d_ef.h"
#include "d_static/d_enemy/d_enemy_boss.h"
#include "machine/m_3d_anmchr.h"
#include "machine/m_3d_anmmatclr.h"
#include "machine/m_3d_anmtexpat.h"
#include "machine/m_3d_anmtexsrt.h"
#include "machine/m_3d_mdl.h"

class daEnBossKoopa_c : public dEnBoss_c {
    SIZE_ASSERT(0x15C8);
    VTABLE(0x60, fBase_c, 0x80B7E710);

public:
    // Structors
    // ^^^^^^

    /* Stripped */
    daEnBossKoopa_c();

    /* VT+0x48 0x80B44A80 */
    virtual ~daEnBossKoopa_c();

public:
    // Nested Types
    // ^^^^^^

    class nodeCallback_c : m3d::mdl_c::callback_c {
        SIZE_ASSERT(0x8);
        VTABLE(0x0, m3d::mdl_c::callback_c, 0x80B7EB68);

    public:
        /* VT+0x08 0x80B3E050 */
        virtual ~nodeCallback_c() override;

        /* VT+0x0C 0x80B446E0 */
        virtual void timingA(u32, nw4r::g3d::ChrAnmResult*, nw4r::g3d::ResMdl) override;

        /* 0x4 */ daEnBossKoopa_c* m_parent;
    };

public:
    // Instance Variables
    // ^^^^^^

    /* 0x0600 */ s32              m0x600;

    /* 0x0604 */ m3d::mdl_c       m_model;
    /* 0x0644 */ m3d::anmChr_c    m_anmChr;
    /* 0x067C */ m3d::anmMatClr_c m_anmMatClr;
    /* 0x06A8 */ m3d::anmTexPat_c m_anmTexPat;
    /* 0x06D4 */ m3d::anmTexSrt_c m_anmTexSrt;

    FILL(0x0700, 0x0704);

    /* 0x0704 */ nodeCallback_c m_nodeCallback;

    FILL(0x070C, 0x0790);

    /* 0x0790 */ dEf::dLevelEffect_c m_levelEffect[6];
    /* 0x0E80 */ dEf::followEffect_c m_followEffect[1];

    FILL(0x0F94, 0x15C8);
};
