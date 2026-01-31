#pragma once

#include "d_profile/d_profile.h"
#include "d_system/d_a_player_key.h"
#include "d_system/d_actor.h"
#include "d_system/d_cc.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_player_model_manager.h"
#include "machine/m_mtx.h"
#include "sound/SndID.h"
#include "sound/SndObjectPlayer.h"
#include "state/s_State.h"

class daPlBase_c : public dActor_c, public dProf::Info<daPlBase_c, dProf::PLAYER, dProf::YOSHI>
{
    SIZE_ASSERT(0x14D4);

    /* 0x0060 VTABLE 0x803087C8 */

public:
    // Static Constants
    // ^^^^^^

    enum class DamageType_e {
        NORMAL = 0,
        NORMAL2 = 1,
        KNOCKBACK_AND_HURT = 2,
        KNOCKBACK_LONG = 3, // Player does not take damage
        KNOCKBACK_LONG2 = 4, // Player does not take damage
        KNOCKBACK_SHORT = 5, // Player does not take damage
        KNOCKBACK_SHORT2 = 6, // Player does not take damage
        LAVA = 7,
        FIRE = 8, // Looks the same as NORMAL?
        ELEC_SHOCK = 9,
        POISON_WATER = 10,
        CRUSH = 11,
        EAT_DIE = 12,
        EAT_DIE2 = 13, // Like EAT_DIE but does not stop the music
        UNKNOWN = 14,
        FREEZE = 15,
        FREEZE2 = 16,
        BOUNCE = 17, // Makes the player do a squishy animation
        POISON_FOG = 18,

        // Added for death messages

        FALL_DOWN = 20,
        SCROLL_OUT,
    };

    enum class DemoType_e {
        DEMO_0 = 0,
        DEMO_1 = 1,
        DEMO_2 = 2,
        DEMO_3 = 3,
        DEMO_4 = 4,
        DEMO_5 = 5,
        DEMO_6 = 6,
    };

    enum class DokanDir_e {
    };

    enum class StarSet_e {
    };

    /* @unofficial */
    enum class Status_e {
        // Dead or in a bubble
        DEAD = 4,

        // Riding Yoshi
        RIDING_YOSHI = 75,
    };

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x0D4 0x80046DF0 */
    virtual void executeMain();

    /* VT+0x0D8 0x800588F0 */
    virtual void executeLastPlayer();

    /* VT+0x0DC 0x800588E0 */
    virtual void executeLastAll();

    /* VT+0x0E0 0x80020BE0 */
    virtual bool isItemKinopio()
    {
        return false;
    }

    /* VT+0x0E4 0x80056BC0 @unofficial */
    virtual void setPowerup(PLAYER_MODE_e powerup);

    /* VT+0x0E8 0x80056D40 */
    virtual s32 getTailType(s8 param);

    /* VT+0x0EC 0x80048080 */
    virtual sBcPointData* getHeadBgPointData();

    /* VT+0x0F0 0x80054EE0 */
    virtual sBcPointData* getWallBgPointData();

    /* VT+0x0F4 0x80056BB0 */
    virtual sBcPointData* getFootBgPointData();

    /* VT+0x0F8 0x80048090 */
    virtual f32 VT_0x0F8();

    /* VT+0x0FC 0x800544E0 */
    virtual void checkBgCrossSub();

    /* VT+0x100 0x80054F80 */
    virtual void postBgCross();

    /* VT+0x104 0x800552C0 */
    virtual f32 getSandSinkRate();

    /* VT+0x108 0x80053F90 */
    virtual void setReductionScale();

    /* VT+0x10C 0x80053FE0 */
    virtual void initStampReduction();

    /* VT+0x110 0x80054070 */
    virtual void calcJumpDaiReductionScale(int param1, int param2);

    /* VT+0x114 0x800540D0 */
    virtual void setReductionBoyon();

    /* VT+0x118 0x800564F0 */
    virtual bool setPressBgDamage(int param1, int param2);

    /* VT+0x11C 0x80056360 */
    virtual bool setBalloonInDispOut(int param);

    /* VT+0x120 0x8004DCF0 */
    virtual bool isChange();

    /* VT+0x124 0x8004DF70 */
    virtual void changeNextScene(int param);

    /* VT+0x128 0x8004F260 */
    virtual bool isEnableDokanInStatus();

    /* VT+0x12C 0x80051080 */
    virtual bool setHideNotGoalPlayer();

    /* VT+0x130 0x80050E60 */
    virtual void VT_0x130();

    /* VT+0x134 0x80050E70 */
    virtual s32 setDemoCannonWarp(int param1, short param2, short param3);

public:
    // Virtual State IDs
    // ^^^^^^

    /**
     * initializeState: VT+0x138 0x8004E450
     * executeState:    VT+0x13C 0x8004E4D0
     * finalizeState:   VT+0x140 0x8004E4C0
     */
    sState_ExternVirtual(0x80354A6C, daPlBase_c, StateID_DemoNone);

    /**
     * initializeState: VT+0x144 0x8004E700
     * executeState:    VT+0x148 0x8004E710
     * finalizeState:   VT+0x14C 0x8004E7A0
     */
    sState_ExternVirtual(0x80354AAC, daPlBase_c, StateID_DemoStartWait);

    /**
     * initializeState: VT+0x150 0x8004E7B0
     * executeState:    VT+0x154 0x8004E820
     * finalizeState:   VT+0x158 0x8004E810
     */
    sState_ExternVirtual(0x80354AEC, daPlBase_c, StateID_DemoWait);

    /**
     * initializeState: VT+0x15C 0x8004F100
     * executeState:    VT+0x160 0x8004F120
     * finalizeState:   VT+0x164 0x8004F110
     */
    sState_ExternVirtual(0x80354B2C, daPlBase_c, StateID_DemoInDokanU);

    /**
     * initializeState: VT+0x168 0x8004F130
     * executeState:    VT+0x16C 0x8004F150
     * finalizeState:   VT+0x170 0x8004F140
     */
    sState_ExternVirtual(0x80354B6C, daPlBase_c, StateID_DemoInDokanD);

    /**
     * initializeState: VT+0x174 0x8004F190
     * executeState:    VT+0x178 0x8004F1B0
     * finalizeState:   VT+0x17C 0x8004F1A0
     */
    sState_ExternVirtual(0x80354BAC, daPlBase_c, StateID_DemoInDokanR);

    /**
     * initializeState: VT+0x180 0x8004F160
     * executeState:    VT+0x184 0x8004F180
     * finalizeState:   VT+0x188 0x8004F170
     */
    sState_ExternVirtual(0x80354BEC, daPlBase_c, StateID_DemoInDokanL);

    /**
     * initializeState: VT+0x18C 0x8004FE70
     * executeState:    VT+0x190 0x8004FE90
     * finalizeState:   VT+0x194 0x8004FE80
     */
    sState_ExternVirtual(0x80354C2C, daPlBase_c, StateID_DemoOutDokanU);

    /**
     * initializeState: VT+0x198 0x8004FEA0
     * executeState:    VT+0x19C 0x8004FEC0
     * finalizeState:   VT+0x1A0 0x8004FEB0
     */
    sState_ExternVirtual(0x80354C6C, daPlBase_c, StateID_DemoOutDokanD);

    /**
     * initializeState: VT+0x1A4 0x8004FF00
     * executeState:    VT+0x1A8 0x8004FF20
     * finalizeState:   VT+0x1AC 0x8004FF10
     */
    sState_ExternVirtual(0x80354CAC, daPlBase_c, StateID_DemoOutDokanR);

    /**
     * initializeState: VT+0x1B0 0x8004FED0
     * executeState:    VT+0x1B4 0x8004FEF0
     * finalizeState:   VT+0x1B8 0x8004FEE0
     */
    sState_ExternVirtual(0x80354CEC, daPlBase_c, StateID_DemoOutDokanL);

    /**
     * initializeState: VT+0x1BC 0x8004FF30
     * executeState:    VT+0x1C0 0x8004FFA0
     * finalizeState:   VT+0x1C4 0x8004FF90
     */
    sState_ExternVirtual(0x80354D2C, daPlBase_c, StateID_DemoOutDokanRoll);

    /**
     * initializeState: VT+0x1C8 0x800502A0
     * executeState:    VT+0x1CC 0x80050380
     * finalizeState:   VT+0x1D0 0x80050370
     */
    sState_ExternVirtual(0x80354D6C, daPlBase_c, StateID_DemoInWaterTank);

    /**
     * initializeState: VT+0x1D4 0x800504B0
     * executeState:    VT+0x1D8 0x80050540
     * finalizeState:   VT+0x1DC 0x80050530
     */
    sState_ExternVirtual(0x80354DAC, daPlBase_c, StateID_DemoOutWaterTank);

    /**
     * initializeState: VT+0x1E0 0x80050870
     * executeState:    VT+0x1E4 0x80050AF0
     * finalizeState:   VT+0x1E8 0x800509F0
     */
    sState_ExternVirtual(0x80354DEC, daPlBase_c, StateID_DemoRailDokan);

    /**
     * initializeState: VT+0x1EC 0x80050E30
     * executeState:    VT+0x1F0 0x80050E50
     * finalizeState:   VT+0x1F4 0x80050E40
     */
    sState_ExternVirtual(0x80354E2C, daPlBase_c, StateID_DemoDown);

    /**
     * initializeState: VT+0x1F8 0x80052FE0
     * executeState:    VT+0x1FC 0x80053090
     * finalizeState:   VT+0x200 0x80053040
     */
    sState_ExternVirtual(0x80354E6C, daPlBase_c, StateID_DemoNextGotoBlock);

    /**
     * initializeState: VT+0x204 0x80051400
     * executeState:    VT+0x208 0x80051AB0
     * finalizeState:   VT+0x20C 0x80051410
     */
    sState_ExternVirtual(0x80354EAC, daPlBase_c, StateID_DemoGoal);

    /**
     * initializeState: VT+0x210 0x80052730
     * executeState:    VT+0x214 0x80052900
     * finalizeState:   VT+0x218 0x80052880
     */
    sState_ExternVirtual(0x80354EEC, daPlBase_c, StateID_DemoControl);

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x21C 0x8004D820 */
    virtual void initialDokanUnder();

    /* VT+0x220 0x8004D830 */
    virtual void initialDokanUper();

    /* VT+0x224 0x8004D840 */
    virtual void initialDokanRight();

    /* VT+0x228 0x8004D850 */
    virtual void initialDokanLeft();

    /* VT+0x22C 0x8004D860 */
    virtual void initialDokanUnderM();

    /* VT+0x230 0x8004D870 */
    virtual void initialDokanUperM();

    /* VT+0x234 0x8004D880 */
    virtual void initialDokanRightM();

    /* VT+0x238 0x8004D890 */
    virtual void initialDokanLeftM();

    /* VT+0x23C 0x8004D8A0 */
    virtual void initialDokanDepth();

    /* VT+0x240 0x8004D8B0 */
    virtual void initialDoor();

    /* VT+0x244 0x8004D8F0 */
    virtual void initialFall();

    /* VT+0x248 0x8004D8E0 */
    virtual void initialVine();

    /* VT+0x24C 0x8004D8C0 */
    virtual void initialJumpRight();

    /* VT+0x250 0x8004D8D0 */
    virtual void initialJumpLeft();

    /* VT+0x254 0x8004D960 */
    virtual void initialHipAttack();

    /* VT+0x258 0x8004D9C0 */
    virtual void initialSlip();

    /* VT+0x25C 0x8004DA20 */
    virtual void initialSwim();

    /* VT+0x260 0x8004DA70 */
    virtual void initialBlockJump();

    /* VT+0x264 0x8004DA80 */
    virtual void initialBlockJumpBelow();

    /* VT+0x268 0x8004DA30 */
    virtual void initialTorideBoss();

    /* VT+0x26C 0x8004DA90 */
    virtual void initialNormal();

    /* VT+0x270 0x8004DB00 */
    virtual void setCreateAction(int param);

    /* VT+0x274 0x8004E280 */
    virtual bool setTimeOverDemo();

    /* VT+0x278 0x80055E00 */
    virtual void setFallDownDemo();

    /* VT+0x27C 0x8004F300 */
    virtual bool setDokanIn(DokanDir_e dir);

    /* VT+0x280 0x8004F670 */
    virtual void initDemoOutDokan();

    /* VT+0x284 0x80051CF0 */
    virtual void VT_0x284();

    /* VT+0x288 0x80051240 */
    virtual void initDemoGoalBase();

    /* VT+0x28C 0x80051A90 */
    virtual void executeDemoGoal_Run();

    /* VT+0x290 0x80052870 */
    virtual void initializeDemoControl();

    /* VT+0x294 0x80047390 */
    virtual void changeState(const sStateIDIf_c& state, void* param);

public:
    // Virtual State IDs
    // ^^^^^^

    /**
     * initializeState: VT+0x298 0x800475B0
     * executeState:    VT+0x29C 0x800475D0
     * finalizeState:   VT+0x2A0 0x800475C0
     */
    sState_ExternVirtual(0x8035451C, daPlBase_c, StateID_None);

    /**
     * initializeState: VT+0x2A4 0x80047790
     * executeState:    VT+0x2A8 0x800477B0
     * finalizeState:   VT+0x2AC 0x800477A0
     */
    sState_ExternVirtual(0x8035455C, daPlBase_c, StateID_Walk);

    /**
     * initializeState: VT+0x2B0 0x800479A0
     * executeState:    VT+0x2B4 0x80047AC0
     * finalizeState:   VT+0x2B8 0x80047A00
     */
    sState_ExternVirtual(0x8035459C, daPlBase_c, StateID_Jump);

    /**
     * initializeState: VT+0x2BC 0x80047BE0
     * executeState:    VT+0x2C0 0x80047C00
     * finalizeState:   VT+0x2C4 0x80047BF0
     */
    sState_ExternVirtual(0x803545DC, daPlBase_c, StateID_SitJump);

    /**
     * initializeState: VT+0x2C8 0x80047C40
     * executeState:    VT+0x2CC 0x80047D60
     * finalizeState:   VT+0x2D0 0x80047D10
     */
    sState_ExternVirtual(0x8035461C, daPlBase_c, StateID_Fall);

    /**
     * initializeState: VT+0x2D4 0x80047D80
     * executeState:    VT+0x2D8 0x80047DA0
     * finalizeState:   VT+0x2DC 0x80047D90
     */
    sState_ExternVirtual(0x8035465C, daPlBase_c, StateID_Land);

    /**
     * initializeState: VT+0x2E0 0x800480A0
     * executeState:    VT+0x2E4 0x800480C0
     * finalizeState:   VT+0x2E8 0x800480B0
     */
    sState_ExternVirtual(0x8035469C, daPlBase_c, StateID_Crouch);

    /**
     * initializeState: VT+0x2EC 0x800480D0
     * executeState:    VT+0x2F0 0x800481C0
     * finalizeState:   VT+0x2F4 0x80048170
     */
    sState_ExternVirtual(0x803546DC, daPlBase_c, StateID_Slip);

    /**
     * initializeState: VT+0x2F8 0x80048C00
     * executeState:    VT+0x2FC 0x80048C20
     * finalizeState:   VT+0x300 0x80048C10
     */
    sState_ExternVirtual(0x8035471C, daPlBase_c, StateID_Turn);

    /**
     * initializeState: VT+0x304 0x800497E0
     * executeState:    VT+0x308 0x80049940
     * finalizeState:   VT+0x30C 0x80049880
     */
    sState_ExternVirtual(0x8035475C, daPlBase_c, StateID_HipAttack);

    /**
     * initializeState: VT+0x310 0x80049A10
     * executeState:    VT+0x314 0x80049A30
     * finalizeState:   VT+0x318 0x80049A20
     */
    sState_ExternVirtual(0x8035479C, daPlBase_c, StateID_Swim);

    /**
     * initializeState: VT+0x31C 0x80049AB0
     * executeState:    VT+0x320 0x80049BB0
     * finalizeState:   VT+0x324 0x80049B60
     */
    sState_ExternVirtual(0x803547DC, daPlBase_c, StateID_JumpDai);

    /**
     * initializeState: VT+0x328 0x80049E10
     * executeState:    VT+0x32C 0x80049FA0
     * finalizeState:   VT+0x330 0x80049F50
     */
    sState_ExternVirtual(0x8035481C, daPlBase_c, StateID_PlayerJumpDai);

    /**
     * initializeState: VT+0x334 0x8004A400
     * executeState:    VT+0x338 0x8004A510
     * finalizeState:   VT+0x33C 0x8004A4D0
     */
    sState_ExternVirtual(0x8035485C, daPlBase_c, StateID_Funsui);

    /**
     * initializeState: VT+0x340 0x8004A670
     * executeState:    VT+0x344 0x8004A690
     * finalizeState:   VT+0x348 0x8004A680
     */
    sState_ExternVirtual(0x8035489C, daPlBase_c, StateID_Kani);

    /**
     * initializeState: VT+0x34C 0x8004A830
     * executeState:    VT+0x350 0x8004AA50
     * finalizeState:   VT+0x354 0x8004A8C0
     */
    sState_ExternVirtual(0x803548DC, daPlBase_c, StateID_Cloud);

    /**
     * initializeState: VT+0x358 0x8004AA60
     * executeState:    VT+0x35C 0x8004AAC0
     * finalizeState:   VT+0x360 0x8004AA80
     */
    sState_ExternVirtual(0x8035491C, daPlBase_c, StateID_AnimePlay);

    /**
     * initializeState: VT+0x364 0x8004AFE0
     * executeState:    VT+0x368 0x8004B0D0
     * finalizeState:   VT+0x36C 0x8004B090
     */
    sState_ExternVirtual(0x8035495C, daPlBase_c, StateID_WaitJump);

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x370 0x800588C0 */
    virtual bool isWaitFrameCountMax();

    /* VT+0x374 0x8004AB80 */
    virtual void checkWalkNextAction();

    /* VT+0x378 0x800475E0 */
    virtual void VT_0x378();

    /* VT+0x37C 0x800475F0 */
    virtual void VT_0x37C();

    /* VT+0x380 0x80047600 */
    virtual void VT_0x380();

    /* VT+0x384 0x80047610 */
    virtual void walkAction_Wait();

    /* VT+0x388 0x80047620 */
    virtual void VT_0x388();

    /* VT+0x38C 0x80047630 */
    virtual void walkAction_Move();

    /* VT+0x390 0x80047DB0 */
    virtual void checkCrouch();

    /* VT+0x394 0x80047DC0 */
    virtual void setCancelCrouch();

    /* VT+0x398 0x8004B220 */
    virtual void setSlipAction();

    /* VT+0x39C 0x80048630 */
    virtual void slipActionMove(int);

    /* VT+0x3A0 0x80047C10 */
    virtual void setFallAction();

    /* VT+0x3A4 0x80048F30 */
    virtual void setHipAttack_AttackStart();

    /* VT+0x3A8 0x8004A3E0 */
    virtual void releaseFunsuiAction();

    /* VT+0x3AC 0x8004A7A0 */
    virtual f32 getCloudOffsetY();

    /* VT+0x3B0 0x800588B0 */
    virtual void setRideJrCrown(const dActor_c*);

    /* VT+0x3B4 0x800588A0 */
    virtual bool isRideJrCrownOwn();

    /* VT+0x3B8 0x80058890 */
    virtual void setRideJrCrownMtx(const mMtx_c* mtx);

    /* VT+0x3BC 0x80058880 */
    virtual void setRideJrCrownAnm(int anm);

    /* VT+0x3C0 0x80049D60 */
    virtual int getHeadTopPosP();

    /* VT+0x3C4 0x80049040 */
    virtual void* getGravityData();

    /* VT+0x3C8 0x80048B90 */
    virtual bool isCarry() const;

    /* VT+0x3CC 0x80053DE0 */
    virtual bool isLiftUp();

    /* VT+0x3D0 0x80056C20 */
    virtual void VT_0x3D0();

    /* VT+0x3D4 0x80022170 */
    virtual bool isStar() const;

    /* VT+0x3D8 0x80058190 */
    virtual void setStar(StarSet_e, int);

    /* VT+0x3DC 0x80051360 */
    virtual void endStar();

    /* VT+0x3E0 0x80058870 */
    virtual void setVirusStar(daPlBase_c*);

    /* VT+0x3E4 0x800581D0 */
    virtual void clearStarCount();

    /* VT+0x3E8 0x8002D970 */
    virtual int getStarCount() const;

    /* VT+0x3EC 0x800581E0 */
    virtual s8 calcStarCount(int max);

    /* VT+0x3F0 0x80057B30 */
    virtual bool isNoDamage();

    /* VT+0x3F4 0x80057B40 */
    virtual bool setDamage(dActor_c* source, DamageType_e type);

    /* VT+0x3F8 0x80057B50 */
    virtual bool setForcedDamage(dActor_c* source, DamageType_e type);

    /* VT+0x3FC 0x80057B70 */
    virtual void VT_0x3FC();

    /* VT+0x400 0x80057B80 */
    virtual void VT_0x400();

    /* VT+0x404 0x80057B90 */
    virtual void setWaitJump(f32);

    /* VT+0x408 0x80048C30 */
    virtual void setHipAttackOnEnemy(mVec3_c*);

    /* VT+0x40C 0x80051350 */
    virtual void clearJumpActionInfo(int);

    /* VT+0x410 0x80057C30 */
    virtual bool setSwimSpeed(f32, f32);

    /* VT+0x414 0x8004C990 */
    virtual void setLandSE();

    /* VT+0x418 0x80058860 */
    virtual void set1UpKinokoEffect();

    /* VT+0x41C 0x80058850 */
    virtual void setFlagGetEffect();

    /* VT+0x420 0x80058C70 */
    virtual void setHipAttackEffect();

    /* VT+0x424 0x800576A0 */
    virtual void setZPosition();

    /* VT+0x428 0x80057760 */
    virtual void setZPosition(f32);

    /* VT+0x42C 0x800577D0 */
    virtual void setZPositionDirect(f32);

    /* VT+0x430 0x80057810 */
    virtual void offZPosSetNone();

    /* VT+0x434 0x80058050 @unofficial */
    virtual void playVoice(SndObjctPly::PLAYER_VOICE_e voice, int param2);

    /* VT+0x438 0x800580B0 */
    virtual void VT_0x438();

    /* VT+0x43C 0x80058280 */
    virtual void VT_0x43C();

    /* VT+0x440 0x800582A0 */
    virtual void startPatternRumble(const char*);

    /* VT+0x444 0x80047480 */
    virtual s16 getMukiAngle(u8);

    /* VT+0x448 0x80047490 */
    virtual bool turnAngle();

    /* VT+0x44C 0x8004C470 */
    virtual void maxFallSpeedSet();

    /* VT+0x450 0x80057B60 */
    virtual bool setDamage2(dActor_c* source, DamageType_e type);

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8004DB40 */
    bool isDemoType(DemoType_e type);

    /* 0x8004DD00 */
    bool isDemo();

    /* 0x8004DDE0 */
    bool isDemoAll();

    /* 0x8004E040 */
    bool isPlayerGameStop();

    /* 0x8004E050 */
    void stopOther();

    /* 0x8004E100 */
    void playOther();

    /* 0x8004E290 */
    void changeDemoState(const sStateIDIf_c& state, int param);

    /* 0x80050D80 */
    bool isDispOutCheckOn();

    /* 0x800510F0 */
    void stopGoalOther();

    /* 0x800511A0 */
    void playGoalOther();

    /* 0x80051E70 */
    bool startControlDemo();

    /* 0x80051EF0 */
    void endControlDemo(int param);

    /* 0x80051F30 */
    void setControlDemoDir(u8 direction);

    /* 0x80052030 */
    [[nodiscard]]
    bool isControlDemoWait();

    /* 0x80052080 */
    void setControlDemoWalk(const f32& pos, const f32& speed);

    /* 0x80052170 */
    void setControlDemoAnm(int anim);

    void UNDEF_80052290(s32 param);

    /* 0x80052470 */
    bool isBossDemoLand();

    /* 0x80056370 */
    void UNDEF_80056370(dActor_c*, int);

    /* 0x80056980 */
    void setStatus5D(float f); ///< @unofficial

    /* 0x80056C70 */
    void onStatus(int flag);

    /* 0x80056CB0 */
    void offStatus(int flag);

    /* 0x80056CF0 */
    [[nodiscard]]
    bool isStatus(int flag);

    inline void onStatus(Status_e flag)
    {
        onStatus(static_cast<int>(flag));
    }

    inline void offStatus(Status_e flag)
    {
        offStatus(static_cast<int>(flag));
    }

    [[nodiscard]]
    inline bool isStatus(Status_e flag)
    {
        return isStatus(static_cast<int>(flag));
    }

    /* 0x80056E30 */
    dPyMdlBase_c* getModel();

    /* 0x80057E70 */
    void playSound(SndID::Type, long);

    /* 0x800583A0 */
    void calcHeadAttentionAngle();

    void addDeathMessage(dActor_c* source, DamageType_e type, bool death);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0392, 0x043C);

    /* 0x043C */ int m0x43C;

    FILL(0x0440, 0x0DE8);

    /* 0x0DE8 */ dPyMdlMng_c* mpModelMng;

    FILL(0x0DEC, 0x0EA4);

    /* 0x0EA4 */ dAcPyKey_c mKey;

    FILL(0x1008, 0x1090);

    /* 0x1090 */ PLAYER_MODE_e mPlayerMode;

    FILL(0x1094, 0x10C4);

    /* 0x10C4 */ mVec3_c m0x10C4;
    /* 0x10D0 */ f32 m0x10D0;
    /* 0x10D4 */ u32 m0x10D4;

    FILL(0x10D8, 0x1164);

    /* 0x1164 */ dCc_c mCc1;
    /* 0x1208 */ dCc_c mAttCc1;
    /* 0x12AC */ dCc_c mAttCc2;
    /* 0x1350 */ dCc_c mAttCc3;

    FILL(0x13F4, 0x14D4);
};
