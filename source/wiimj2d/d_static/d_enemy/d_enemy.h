#pragma once

#include "d_static/d_actor/d_actor.h"
#include "d_static/d_actor/d_actor_state.h"
#include "state/s_State.h"

class dCc_c;

class dEn_c : public dActorMultiState_c {
    SIZE_ASSERT(0x524);

public:
    // Structors
    // ^^^^^^

    /* 0x80094E80 */
    dEn_c();

    /* 0x80095130 */
    virtual ~dEn_c() override;

public:
    // Virtual Functions
    // ^^^^^^

    /**
     * VT+0x10 0x800951D0
     * post method for the create operation.
     */
    virtual void postCreate(fBase_c::MAIN_STATE_e status) override;

    /**
     * VT+0x24 0x80095240
     * pre method for the execute operation.
     */
    virtual PACK_RESULT_e preExecute() override;

    /**
     * VT+0x28 0x80095480
     * post method for the execute operation.
     */
    virtual void postExecute(fBase_c::MAIN_STATE_e status) override;

    /**
     * VT+0x30 0x800954A0
     * pre method for the draw operation.
     */
    virtual PACK_RESULT_e preDraw() override;

    /* VT+0x64 0x80097f70 */
    virtual void block_hit_init() override;

    /* VT+0x80 0x80097C40 */
    virtual void setEatTongue(dActor_c* actor) override;

    /* VT+0x84 0x80097CB0 */
    virtual void setEatTongueOff(dActor_c* actor) override;

    /* VT+0x8C 0x80097D30 */
    virtual bool setEatSpitOut(dActor_c* actor) override;

    /* VT+0xAC 0x80097DF0 */
    virtual void calcEatInScale(dActor_c* yoshi) override;

    /* VT+0xCC 0x800973F0 */
    virtual void yoganSplashEffect(const mVec3_c& position, float scale) override;

    /* VT+0xD0 0x800974F0 */
    virtual void poisonSplashEffect(const mVec3_c& position, float scale) override;

    /* VT+0xD4 0x800A7DF0 */
    virtual void changeState(const sStateIDIf_c& state) override;

    /* VT+0xD8 0x80095CE0 */
    virtual bool EnDamageCheck(dCc_c* self, dCc_c* other);

    /* VT+0xDC 0x80095D30 */
    virtual bool PlDamageCheck(dCc_c* self, dCc_c* other);

    /* VT+0xC0 0x80095F50 */
    virtual bool YoshiDamageCheck(dCc_c* self, dCc_c* other);

    /* VT+0xC4 0x80096060 */
    virtual bool EtcDamageCheck(dCc_c* self, dCc_c* other);

    /* VT+0xC8 0x80095C10 */
    virtual void Normal_VsEnHitCheck(dCc_c* self, dCc_c* other);

    /* VT+0xCC 0x80095C20 */
    virtual void Normal_VsPlHitCheck(dCc_c* self, dCc_c* other);

    /* VT+0xD0 0x80095C80 */
    virtual void Normal_VsYoshiHitCheck(dCc_c* self, dCc_c* other);

    /* VT+0xD4 0x8009F840 */
    virtual bool hitCallback_Star(dCc_c* self, dCc_c* other);

    /* VT+0xD8 0x8009FB50 */
    virtual bool hitCallback_Slip(dCc_c* self, dCc_c* other);

    /* VT+0xDC 0x8009FE40 */
    virtual bool hitCallback_Large(dCc_c* self, dCc_c* other);

    /* VT+0xE0 0x8009FB50 */
    virtual bool hitCallback_Spin(dCc_c* self, dCc_c* other);

    /* VT+0xE4 0x8009FFC0 */
    virtual bool hitCallback_Rolling(dCc_c* self, dCc_c* other);

    /* VT+0xE8 0x8009FCE0 */
    virtual bool hitCallback_WireNet(dCc_c* self, dCc_c* other);

    /* VT+0xEC 0x800A0150 */
    virtual bool hitCallback_HipAttk(dCc_c* self, dCc_c* other);

    /* VT+0xF0 0x800A02D0 */
    virtual bool hitCallback_YoshiHipAttk(dCc_c* self, dCc_c* other);

    /* VT+0xF4 0x8009FCD0 */
    virtual bool hitCallback_Screw(dCc_c* self, dCc_c* other);

    /* VT+0xF8 0x8009FCC0 */
    virtual bool hitCallback_PenguinSlide(dCc_c* self, dCc_c* other);

    /* VT+0xFC 0x8009F9D0 */
    virtual bool hitCallback_Cannon(dCc_c* self, dCc_c* other);

    /* VT+0x100 0x800A0700 */
    virtual bool hitCallback_Shell(dCc_c* self, dCc_c* other);

    /* VT+0x104 0x800A08D0 */
    virtual bool hitCallback_Fire(dCc_c* self, dCc_c* other);

    /* VT+0x108 0x800A0A30 */
    virtual bool hitCallback_Ice(dCc_c* self, dCc_c* other);

    /* VT+0x10C 0x800A03C0 */
    virtual bool hitCallback_YoshiBullet(dCc_c* self, dCc_c* other);

    /* VT+0x110 0x800A0550 */
    virtual bool hitCallback_YoshiFire(dCc_c* self, dCc_c* other);

    /* VT+0x114 0x800A10B0 */
    virtual void setDeathInfo_Other(dActor_c* killedBy);

    /* VT+0x118 0x800A0C70 */
    virtual void setDeathInfo_Quake(int);

    /* VT+0x11C 0x800A12A0 */
    virtual void setDeathInfo_IceBreak();

    /* VT+0x120 0x800A1370 */
    virtual void setDeathInfo_IceVanish();

    /* VT+0x124 defined in d_a_en_bigpile.cpp */
    [[nsmbw(0x800206D0)]]
    virtual bool isQuakeDamage();

    /* VT+0x128 0x80096230 */
    virtual void hitYoshiEat(dCc_c* self, dCc_c* other);

    /* VT+0x12C 0x800A1C00 */
    virtual void setDeathSound_HipAttk();

    /* VT+0x130 0x800A1BB0 */
    virtual void setDeathSound_Fire();

    /* VT+0x134 0x800A1C80 */
    virtual void setDeathSound_Slip(dActor_c* actor);

    /* VT+0x138 0x800A1D90 */
    virtual void setDeathSound_Spin();

    /* VT+0x13C 0x800A1E10 */
    virtual void setDeathSound_Rolling();

public:
    // Virtual State IDs
    // ^^^^^^

    /**
     * initializeState: VT+0x140 0x800A1470
     * executeState:    VT+0x144 0x800A1600
     * finalizeState:   VT+0x148 0x800A15F0
     */
    sState_ExternVirtual(0x80357EB4, dEn_c, DieFumi);

    /**
     * initializeState: VT+0x14C 0x800A16A0
     * executeState:    VT+0x150 0x800A1830
     * finalizeState:   VT+0x154 0x800A1820
     */
    sState_ExternVirtual(0x80357EF4, dEn_c, DieFall);

    /**
     * initializeState: VT+0x158 0x800A1910
     * executeState:    VT+0x15C 0x800A1930
     * finalizeState:   VT+0x160 0x800A1920
     */
    sState_ExternVirtual(0x80357F34, dEn_c, DieBigFall);

    /**
     * initializeState: VT+0x164 0x800A1980
     * executeState:    VT+0x168 0x800A1A00
     * finalizeState:   VT+0x16C 0x800A19F0
     */
    sState_ExternVirtual(0x80357F74, dEn_c, DieSmoke);

    /**
     * initializeState: VT+0x170 0x800A1AC0
     * executeState:    VT+0x174 0x800A1B40
     * finalizeState:   VT+0x178 0x800A1B30
     */
    sState_ExternVirtual(0x80357FF4, dEn_c, DieYoshiFumi);

    /**
     * initializeState: VT+0x17C 0x800A1A10
     * executeState:    VT+0x180 0x800A1AB0
     * finalizeState:   VT+0x184 0x800A1AA0
     */
    sState_ExternVirtual(0x80357FB4, dEn_c, DieIceVanish);

    /**
     * initializeState: VT+0x188 0x800A1B50
     * executeState:    VT+0x18C 0x800A1B70
     * finalizeState:   VT+0x190 0x800A1B60
     */
    sState_ExternVirtual(0x80358034, dEn_c, DieGoal);

    /**
     * initializeState: VT+0x194 0x800A1B80
     * executeState:    VT+0x198 0x800A1BA0
     * finalizeState:   VT+0x19C 0x800A1B90
     */
    sState_ExternVirtual(0x80358074, dEn_c, DieOther);

    /**
     * initializeState: VT+0x1A0 0x800A81C0
     * executeState:    VT+0x1A4 0x800A81E0
     * finalizeState:   VT+0x1A8 0x800A81D0
     */
    sState_ExternVirtual(0x80358384, dEn_c, EatIn);

    /**
     * initializeState: VT+0x1AC 0x800A8260
     * executeState:    VT+0x1B0 0x800A8280
     * finalizeState:   VT+0x1B4 0x800A8270
     */
    sState_ExternVirtual(0x803583C4, dEn_c, EatNow);

    /**
     * initializeState: VT+0x1B8 0x800A8290
     * executeState:    VT+0x1BC 0x800A82B0
     * finalizeState:   VT+0x1C0 0x800A82A0
     */
    sState_ExternVirtual(0x80358404, dEn_c, EatOut);

    /**
     * initializeState: VT+0x1C4 0x800A8190
     * executeState:    VT+0x1C8 0x800A81B0
     * finalizeState:   VT+0x1CC 0x800A81A0
     */
    sState_ExternVirtual(0x80358344, dEn_c, HitSpin);

    /**
     * initializeState: VT+0x1D0 0x800A7E90
     * executeState:    VT+0x1D4 0x800A7F40
     * finalizeState:   VT+0x1D8 0x800A7F30
     */
    sState_ExternVirtual(0x80358304, dEn_c, Ice);

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x1DC 0x80095520 */
    virtual void fumidamageEffect(const mVec3_c& pos);

    /* VT+0x1E0 0x80095530 */
    virtual void hipatkEffect(const mVec3_c& pos);

    /* VT+0x1E4 0x80095580*/
    virtual void fumidamageSE(const mVec3_c& pos, int);

    /* VT+0x1E8 0x800955D0 */
    virtual void quakeAction(); ///< @unofficial

    /* VT+0x1EC 0x80095890 */
    virtual bool checkDispIn();

    /* VT+0x1F0 0x80097770 */
    virtual void setWaterSpeed();

    /* VT+0x1F4 0x80097F20 */
    virtual void setDamage(dActor_c* actor);

    /* VT+0x1F8 0x80097F60 */
    virtual void boyonBegin();

    /* VT+0x1FC defined in d_a_en_bigpile.cpp */
    [[nsmbw(0x800206C0)]]
    virtual void calcBoyonScale();

    /* VT+0x200 0x800A8060 */
    virtual void createIceActor();

    /* VT+0x204 0x800A8150 */
    virtual void setIceAnm();

    /* VT+0x208 0x800A8160 */
    virtual void returnAnm_Ice();

    /* VT+0x20C 0x800A8180 */
    virtual void returnState_Ice();

    /* VT+0x210 defined in d_a_en_bigpile.cpp */
    [[nsmbw(0x800206B0)]]
    virtual void beginFunsui();

    /* VT+0x214 defined in d_a_en_bigpile.cpp */
    [[nsmbw(0x80020680)]]
    virtual void endFunsui();

    /* VT+0x218 defined in d_a_en_bigpile.cpp */
    [[nsmbw(0x80020690)]]
    virtual void isFunsui() const;

    /* VT+0x21C 0x800968E0 */
    virtual bool checkComboClap(int max);

    /* VT+0x220 0x80096710 */
    virtual void FumiJumpSet(dActor_c* actor);

    /* VT+0x224 0x80096700 */
    virtual void FumiScoreSet(dActor_c* actor);

    /* VT+0x228 0x80096720 */
    virtual void MameFumiJumpSet(dActor_c* actor);

    /* VT+0x22C 0x80096760 */
    virtual void YoshiFumiJumpSet(dActor_c* actor);

    /* VT+0x230 0x80096770 */
    virtual void YoshiFumiScoreSet(dActor_c* actor);

    /* VT+0x234 0x80096910 */
    virtual void fumiSE(dActor_c* actor);

    /* VT+0x238 0x80096D60 */
    virtual void fumiEffect(dActor_c* actor);

    /* VT+0x23C 0x80096A20 */
    virtual void spinfumiSE(dActor_c* actor);

    /* VT+0x240 0x80096DF0 */
    virtual void spinfumiEffect(dActor_c* actor);

    /* VT+0x244 0x80096C40 */
    virtual void mamefumiSE(dActor_c* actor);

    /* VT+0x248 0x80096E50 */
    virtual void mamefumiEffect(dActor_c* actor);

    /* VT+0x24C 0x80096B30 */
    virtual void yoshifumiSE(dActor_c* actor);

    /* VT+0x250 0x80096E40 */
    virtual void yoshifumiEffect(dActor_c* actor);

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80097B90 */
    void slipBound(dActor_c* actor);

    u8 setCollTimer(int player, u8 timer);
    u8 setCollTimer(dActor_c* player, u8 timer);

    u8 getCollTimer(int player) const;
    u8 getCollTimer(dActor_c* player) const;

    u8 incrementCollTimer(int player, int increment);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x414, 0x504);

    // Change from u16 to u8 to fit more players
    /* 0x504 */ u8 mCollTimer[8];

    FILL(0x50C, 0x524);

public:
    // Static Methods
    // ^^^^^^

    /* 0x80095950 */
    static void normal_collcheck(dCc_c* object, dCc_c* other);
};
