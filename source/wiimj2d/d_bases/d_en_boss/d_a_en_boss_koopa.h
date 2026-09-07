#pragma once

#include "d_ef.h"
#include "d_enemy_boss.h"
#include "m_3d_anmchr.h"
#include "m_3d_anmmatclr.h"
#include "m_3d_anmtexpat.h"
#include "m_3d_anmtexsrt.h"
#include "m_3d_mdl.h"

class daEnBossKoopa_c : public dEnBoss_c {
    SIZE_ASSERT(0x15C8);
    VTABLE(0x60, fBase_c, 0x80B7E710);
    // 0x80B7DA08 g_profile_EN_BOSS_KOOPA
    // 0x80B3DEE0 daEnBossKoopa_c_classInit

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

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x80B40DB0
     * executeState:    VT+0x284 0x80B40EA0
     * finalizeState:   VT+0x288 0x80B40F10
     */
    sState_ExternVirtual(0x80B8BD2C, daEnBossKoopa_c, DemoWait);

    /*
     * initializeState: VT+0x3D0 0x80B426F0
     * executeState:    VT+0x3D4 0x80B427A0
     * finalizeState:   VT+0x3D8 0x80B42820
     */
    sState_ExternVirtual(0x80B8BD6C, daEnBossKoopa_c, Wait);

    /*
     * initializeState: VT+0x394 0x80B40F90
     * executeState:    VT+0x398 0x80B41050
     * finalizeState:   VT+0x39C 0x80B412B0
     */
    sState_ExternVirtual(0x80B8BDAC, daEnBossKoopa_c, Roar);

    /*
     * initializeState: VT+0x3DC 0x80B42830
     * executeState:    VT+0x3E0 0x80B428E0
     * finalizeState:   VT+0x3E4 0x80B42A90
     */
    sState_ExternVirtual(0x80B8BDEC, daEnBossKoopa_c, Turn);

    /*
     * initializeState: VT+0x3E8 0x80B42AA0
     * executeState:    VT+0x3EC 0x80B42BB0
     * finalizeState:   VT+0x3F0 0x80B42E10
     */
    sState_ExternVirtual(0x80B8BE2C, daEnBossKoopa_c, Walk);

    /*
     * initializeState: VT+0x418 0x80B43AC0
     * executeState:    VT+0x41C 0x80B43B50
     * finalizeState:   VT+0x420 0x80B43D70
     */
    sState_ExternVirtual(0x80B8BE6C, daEnBossKoopa_c, Fire);

    /*
     * initializeState: VT+0x424 0x80B43D80
     * executeState:    VT+0x428 0x80B43DF0
     * finalizeState:   VT+0x42C 0x80B440F0
     */
    sState_ExternVirtual(0x80B8BEAC, daEnBossKoopa_c, Through);

    /*
     * initializeState: VT+0x430 0x80B44100
     * executeState:    VT+0x434 0x80B44180
     * finalizeState:   VT+0x438 0x80B44290
     */
    sState_ExternVirtual(0x80B8BEEC, daEnBossKoopa_c, Burst);

    /*
     * initializeState: VT+0x400 0x80B432B0
     * executeState:    VT+0x404 0x80B43350
     * finalizeState:   VT+0x408 0x80B43630
     */
    sState_ExternVirtual(0x80B8BF2C, daEnBossKoopa_c, Jump);

    /*
     * initializeState: VT+0x3A0 0x80B412C0
     * executeState:    VT+0x3A4 0x80B413D0
     * finalizeState:   VT+0x3A8 0x80B414D0
     */
    sState_ExternVirtual(0x80B8BF6C, daEnBossKoopa_c, Struggle);

    /*
     * initializeState: VT+0x3AC 0x80B414E0
     * executeState:    VT+0x3B0 0x80B41520
     * finalizeState:   VT+0x3B4 0x80B417B0
     */
    sState_ExternVirtual(0x80B8BFAC, daEnBossKoopa_c, Fall);

    /*
     * initializeState: VT+0x3B8 0x80B417C0
     * executeState:    VT+0x3BC 0x80B419F0
     * finalizeState:   VT+0x3C0 0x80B41EC0
     */
    sState_ExternVirtual(0x80B8BFEC, daEnBossKoopa_c, Swell);

    /*
     * initializeState: VT+0x3F4 0x80B42E20
     * executeState:    VT+0x3F8 0x80B42F30
     * finalizeState:   VT+0x3FC 0x80B432A0
     */
    sState_ExternVirtual(0x80B8C02C, daEnBossKoopa_c, Swing);

    /*
     * initializeState: VT+0x40C 0x80B43640
     * executeState:    VT+0x410 0x80B436E0
     * finalizeState:   VT+0x414 0x80B43AB0
     */
    sState_ExternVirtual(0x80B8C06C, daEnBossKoopa_c, Approach);

    /*
     * initializeState: VT+0x3C4 0x80B41ED0
     * executeState:    VT+0x3C8 0x80B41FC0
     * finalizeState:   VT+0x3CC 0x80B426E0
     */
    sState_ExternVirtual(0x80B8C0AC, daEnBossKoopa_c, Sink);

    /*
     * initializeState: VT+0x43C 0x80B445E0
     * executeState:    VT+0x440 0x80B44640
     * finalizeState:   VT+0x444 0x80B446D0
     */
};
