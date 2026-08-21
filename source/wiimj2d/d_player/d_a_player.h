#pragma once

#include "d_player/d_a_yoshi.h"
#include "d_profile/d_profile.h"
#include "d_static/d_a_player_base.h"
#include "d_static/d_a_player_manager.h"
#include "d_static/d_bc.h"
#include "d_static/d_cc.h"
#include "d_static/d_mj2d_game.h"
#include "d_static/d_player_model_manager.h"
#include "d_static/d_quake.h"
#include "framework/f_base_id.h"
#include "state/s_State.h"

/**
 * The player class for Mario, Luigi and the Toads.
 */
class dAcPy_c : public daPlBase_c, public dProf::Info<dAcPy_c, dProf::PLAYER>
{
public:
    // Constants
    // ^^^^^^

    /// @unofficial
    enum SpinHipAttackSubstate_e {
        SPIN_HIP_ATTACK_ACTION_0,
        SPIN_HIP_ATTACK_ACTION_1
    };

    /// @unofficial
    enum FallSubstate_e {
        FALL_ACTION_0,
        FALL_ACTION_1
    };

    /// @unofficial
    enum JumpSubstate_e {
        JUMP_TAKE_OFF,
        JUMP_AIR
    };

    /// @unofficial
    enum LandSubstate_e {
        LAND_ACTION_0,
        LAND_ACTION_1
    };

    /// @unofficial
    enum SpinJumpSubstate_e {
        SPIN_JUMP_ACTION_0,
        SPIN_JUMP_ACTION_1
    };

    /// @unofficial
    enum SitJumpSubstate_e {
        SIT_JUMP_ACTION_0,
        SIT_JUMP_ACTION_1
    };

    /// @unofficial
    enum CannonJumpSubstate_e {
        CANNON_JUMP_ACTION_0,
        CANNON_JUMP_ACTION_1,
        CANNON_JUMP_ACTION_2
    };

    /// @unofficial
    enum BlockJumpSubstate_e {
        BLOCK_JUMP_ACTION_0,
        BLOCK_JUMP_ACTION_1
    };

    /// @unofficial
    enum RollSlipSubstate_e {
        ROLL_SLIP_ACTION_0,
        ROLL_SLIP_ACTION_1,
        ROLL_SLIP_ACTION_2
    };

    /// @unofficial
    enum PenguinSlideSubstate_e {
        PENGUIN_SLIDE_ACTION_0,
        PENGUIN_SLIDE_ACTION_1,
        PENGUIN_SLIDE_ACTION_2
    };

    /// @unofficial
    enum CrouchSubstate_e {
        CROUCH_GROUND,
        CROUCH_WATER
    };

    /// @unofficial
    enum ThrowSubstate_e {
        THROW_ACTION_0,
        THROW_ACTION_1,
        THROW_ACTION_2
    };

    /// @unofficial
    enum SwimSubstate_e {
        SWIM_ACTION_0,
        SWIM_ACTION_1,
        SWIM_ACTION_2,
        SWIM_ACTION_3
    };

    /// @unofficial
    enum VineSubstate_e {
        VINE_ACTION_IVY,
        VINE_ACTION_NET,
        VINE_ACTION_ATTACK,
        VINE_ACTION_ROLL
    };

    /// @unofficial
    enum HangSubstate_e {
        HANG_ACTION_START,
        HANG_ACTION_WAIT,
        HANG_ACTION_MOVE
    };

    /// @unofficial
    enum KaniSubstate_e {
        KANI_ACTION_WALK,
        KANI_ACTION_HANG_INIT,
        KANI_ACTION_JUMP_HANG_INIT,
        KANI_ACTION_HANG,
        KANI_ACTION_HANG_FALL,
        KANI_ACTION_HANG_UP,
        KANI_ACTION_HANG_UP_VINE
    };

    /// @unofficial
    enum RopeSwingState_e {
        ROPE_SWING_0,
        ROPE_SWING_1,
        ROPE_SWING_2,
        ROPE_SWING_3,
        ROPE_SWING_4,
        ROPE_SWING_5,
        ROPE_SWING_6,
        ROPE_SWING_7,
        ROPE_SWING_8,
        ROPE_SWING_9,
        ROPE_SWING_10
    };

    /// @unofficial
    enum DemoOutDoorState_e {
        DEMO_OUT_DOOR_OPEN_DOOR,
        DEMO_OUT_DOOR_MOVE_CENTER,
        DEMO_OUT_DOOR_MOVE_INTER,
        DEMO_OUT_DOOR_WAIT_CLOSE,
        DEMO_OUT_DOOR_WAIT_ENTER,
        DEMO_OUT_DOOR_FINISHED
    };

    enum QuakeMode_e {
        QUAKE_MODE_0
    };

public:
    // Instance Methods
    // ^^^^^^

    void setSeaLandSmokeEffect();
    /* 0x801267F0 */ bool setHipAttackAction();
    void setWaterInEffect();
    void setSpinHipAttackEffect();
    void setScrollMode(s8);
    dActor_c* getCarryPropelActor();
    void setPropelSpinSmokeEffect();
    void setWaterWalkFlag();
    bool setKaniActionInitHangHand();
    bool jump_common();
    void _jumpSet(jmpInf_c*);
    void calcJumpCount();
    /* 0x801275B0 */ float getJumpSpeed();
    void setJumpSpeed();
    void fn_80127740(
      int jumpType, AnmBlend_e blendMode
    ); ///< Jump animation set, some enum as first param @unofficial
    void fn_80145fd0(int jumpType); ///< Jump voice, some enum as param @unofficial
    bool checkCarryThrow();
    void jumpExeTakeOff();
    void jumpExecAir();
    void fn_801282d0(AnmBlend_e blendMode); ///< @unofficial
    bool spinLiftUp(dActor_c*, bool); ///< @unofficial
    void setJumpCommonBase();
    /* 0x8012DD20 */ dAcPy_c* getCarryPlayer();
    bool isIceSlipAnmPlay();
    /* 0x80128600 */ int checkWallSlideEnable(int);
    bool checkWallJump();
    /* 0x80128970 */ void setWallSlideEffect();
    void setSpinHoldReq(float targetX);
    bool setSpinSpeed(float, float);
    void setSpinJumpEffect(int);
    void endSpinJumpEffect();
    void setSpinJumpEffectSub(int);
    void setMissSpinJumpEffect(int);
    void initRideSpinMove();
    void setSpinFireBall();
    void endRideSpinMove();
    bool isMissSpinEnableAnm();
    s16 getMissSpinAngle();
    void setMissSpin();
    void resetMissSpin();
    void updateMissSpin();
    void setKaniMoveSpeed(bool);
    void setCrouchSmokeEffect();
    void setSlipSE();
    void setSlipEffect();
    /* 0x8012E6E0 */ void releaseCarryActor();
    void setInvalidKeyTimer(int, int);
    void setInvalidKeyTimer_LR(int, int);
    bool checkPenguinSlideJump();
    void setPenguinSlideEffect();
    void setPenguinSlideLandEffect();
    void setNormalWalkAnm(AnmBlend_e, float);
    void setRunOnWaterEffect();
    void turnPowerSet();
    void setTurnSmokeEffect();
    void CrouchActionGround();
    void CrouchActionWater();
    void setWaterGroundJump();
    dActor_c* getCarryPropelBlock();
    dActor_c* getCarryHardBlock();
    float getLiftUpOffset();
    mVec3_c getLiftUpPos();
    /* 0x8012E260 */
    void clearSpinLiftUpReserve();
    void checkSpinLiftUpReserve(dCc_c* cc);
    /* 0x8012E330 */
    void setSpinLiftUpReserve();
    void checkSpinLiftUpRoofHeight();
    void setCarryOffFall(const dAcPy_c* player);
    bool checkEnableThrow();
    void initializeThrowCommonBase();
    void initializeThrowCommon();
    void finalizeThrowCommonBase();
    void finalizeThrowCommon();
    void setThrowActor();
    const sBcPlayerPointData* getBgPointData();
    void setBcData(int);
    void executeThrowCommon();
    void setWaterMoveSpeed();
    void calcUzuSwimSpeed(float, float, float*); ///< @unofficial
    void setUzuSpeedY(float f);
    void setUzuSpeedF(float f);
    bool setUzuSwimAction();
    bool setSwimAction();
    void setWaterOutEffect();
    void setPaddleSwimEffect();
    void resetPaddleSwimEffect();
    void setWaterSurfaceSwimEffect();
    void setFlutterKickEffect();
    void setInitSwimAction_FireBall();
    const sBcPlayerPointData* getBgPointData_Powerup(PLAYER_MODE_e, int); ///< @unofficial
    bool setWaterSurfaceJump();
    void createFireBall(int);
    void SwimAction_Swim();
    void setSwimAction_Swim(AnmBlend_e blendMode);
    void setSwimAction_Walk(AnmBlend_e blendMode);
    void setSwimAction_Penguin(AnmBlend_e blendMode);
    void setSwimActionWalkAnm();
    void SwimAction_Walk();
    s16 getPenguinSwinAngleX();
    void setPenWaterMoveSpeed(int i);
    bool setPenguinPaddleSwim();
    void SwimAction_Penguin();
    void setSwimAction_FireBall();
    void SwimAction_FireBall();
    bool checkSetFireBall();
    void calcPenguinSwimGroundRev();
    void setIvyHangEffect();
    bool setVineAction();
    float getHangBcOffsetY();
    bool setKaniHangToVineAction();
    bool setVineToKaniHangAction();
    void calcVineSpeed();
    bool checkVineEnd();
    void setVineWalkSE();
    void VineActionIvy();
    /* 0x80139800 */ bool setRideOffPlayerJump(float, float);
    void VineActionNet();
    void VineActionAttack();
    void VineActionRoll();
    bool checkNetPunch();

    bool setAmiRollAction(mVec3_c*);
    bool isAmiRollAction();
    void setAmiRollPos(short, float);
    void setAmiRollPos(short, float, mVec3_c&);
    void endAmiRollAction(short ang);

    void setCarryPlayerHang(float height);
    bool setHangAction();
    void HangActionStart();
    void setHangActionWait();
    void HangActionWait();
    void setHangActionMove();
    void HangActionMove();

    void setPoleTurnAngle();
    bool setPoleAction();
    void PoleActionStart();
    void setPoleActionWait();
    void PoleActionWait();
    void setPoleActionUp();
    void PoleActionUp();
    void setPoleActionDown();
    void PoleActionDown();
    void setPoleJump();
    bool setPoleShakeJump();

    bool setKaniHangAction();
    void setKaniWalkEffect();
    void setKaniHangEffect();
    void setKaniCliffCatchEffect();
    void setKaniAction_Walk();
    void setKaniAction_Hang();
    void setKaniAction_HangUp();
    void setKaniAction_HangFall();
    void setKaniAction_JumpHang();
    void setKaniAction_HangUpVine();
    void setKaniAction_HangHand();
    void setKaniHangStartEffect();
    void KaniAction_Walk();
    void KaniAction_HangInit();
    void KaniAction_JumpHangInit();
    bool checkCliffHangFootGround();
    bool checkCliffHangWater();
    void KaniAction_Hang();
    void KaniAction_HangFall();
    void KaniAction_HangUp();
    void KaniAction_HangUpVine();

    void setCatchRopeSE();
    void setClimbRopeSE();
    void setSlideRopeSE();
    void setRopeHasigoSE();
    void releasePoleCheck();

    bool setTarzanRopeAction();
    bool setTarzanRopeJump();

    /* 0x80139A90 */ daYoshi_c* getRideYoshi();
    /* 0x80138890 */ bool isNotBalloonCourse();
    bool fn_801477c0(); ///< @unofficial
    /* 0x80144C60 */ void setSceneChangeInfo();
    bool updateRopeAngle();
    void setRopeSwingAnm(float, float);
    bool checkStartSwingUp();
    bool checkStartSwingDown();
    void updateRopeSwingAnm();
    void TarzanRopeActionStart();
    void setTarzanRopeActionWait();
    void TarzanRopeActionWait();
    void setTarzanRopeActionUp();
    void TarzanRopeActionUp();
    void setTarzanRopeActionDown();
    void TarzanRopeActionDown();
    void setTarzanRopeActionHasigoMove();
    void TarzanRopeActionHasigoMove();
    void TarzanRopeActionHasigoHangDown();
    void setTarzanRopeActionHasigoHangUp();
    void TarzanRopeActionHasigoHangUp();

    void startQuakeAction(QuakeMode_e);
    void setQuakeAction(int, QuakeMode_e);
    void setQuakeActionLocal(int, QuakeMode_e);
    void endQuakeAction();
    void setQuakeNumbEffect();

    void initElecShock();
    bool executeElecShock();
    void setElecEffect();

    bool setFlyDamageAction(int, dActor_c*);

    void initCcData();
    void initBcData();
    void calcModel();

    void setBreakBalloonJump(u8, short);
    void setDrawBalloonInPlayer(mVec3_c& pos);
    bool checkAllBalloonFade();

    /* 0x80138E80 */ void setBalloonHelpVoice();
    bool setBalloonInNextgoto();
    /* 0x80138FA0 */ bool setBalloonInDamage();
    bool setBalloonButtonA();
    /* 0x80139330 */ bool setBalloonInDispOutByYoshi(int);
    /* 0x80139350 */ bool setBalloonInDispOutBase(int type, int yoshi, bool noDeathMsg);

    void setShakeIce(float);
    mVec3_c getIceDrawPos();

    void fn_801395a0(); ///< @unofficial
    void fn_801416c0(PLAYER_MODE_e); ///< @unofficial

    /* 0x80139910 */ bool setRideOffYoshiJump(daPlBase_c* yoshi);
    /* 0x80139AE0 */ void setRideOnYoshi(daYoshi_c* yoshi);

    void setCloudStateMove();
    bool checkCloudStateCrouch();
    void setCloudStateFireCreate();

    bool checkCarryActor(dAcPy_c* player);
    bool setDropCarryPlayer();
    void setCarryPlayerMode_Move(float);
    void setCarryPlayerMode_Fire();
    void setCarryPlayerMode_Crouch();

    dAcPy_c* getRidePlayer();

    void setYoshiBackPos();
    void setPlayerHandPos();
    void setPlayerEatPos(dActor_c* eatingActor);
    void setPlayerEatReact();

    void endPowerUpEffect();

    void setJrCrownPos();
    void setJrCrownElecDamage();

    bool setFireBallAction();
    bool checkFireJump();

    bool fn_80146e40(float, float, bool); ///< @unofficial
    int getSpinActionMode();

    bool setPropelAction();
    void resetPropelFlyTime();
    void clearPropelFlyUpTime();
    void calcPropelMoveSpeedF();
    void setPropelActionFlyInit();
    void setPropelActionBigFly();
    void setPropelActionFly();
    void PropelActionFly();
    void setPropelActionFall();
    void PropelActionFall();
    void setStartPropelJumpEffect();
    bool calcPropelFallSpinEffect();
    void setPropelFallSpinEffect();
    void endPropelFlyPartsMove();
    void stopPropelFallSpinEffect();
    void updatePropelParts();
    void updatePropelFlyPartsMove();
    bool isEnablePropelJump();
    bool setSpinActionReq();
    bool setSpinAction();

    void initPlayerDownCommon();
    void initDemo_DownPose();
    void initDemo_DownFall();
    void exeDemo_DownFall();
    /* 0x8013D7B0 */ void checkRest();
    /* 0x8013DA30 */ void stopOtherDownDemo();
    /* 0x8013DB30 */ void playOtherDownDemo();
    void setPlayerEatDie();
    void releaseEatDie();
    bool setEatDieHide();
    bool setEatDieFadeOut();
    bool setEatDieSpitOut();
    void setEatDieScreamVoice();

    bool searchDoorActor();
    void setDemoInDoor_Walk();
    bool isDoorDemoEnable();
    bool setDoorDemo(dActor_c*);
    void exeDemoOutDoor_OpenDoor();
    void initDemoOutDoor_MoveInter();
    void exeDemoOutDoor_MoveInter();
    void initDemoOutDoor_MoveCenter();
    void exeDemoOutDoor_MoveCenter();
    void exeDemoOutDoor_WaitClose();
    void exeDemoOutDoor_WaitEnter();

    bool initDemoDokanCannon(mVec3_c& pos, int cannonMode); // @unofficial
    /* 0x8013FBE0 */ void endDemoDokanCannon(mVec3_c& pos);
    bool isDokanCannonIn();
    /* 0x80146F60 */ bool setCannonJump(float speedY, float speedF, int jumpType);

    void setOffYoshiInGoal(daPlBase_c* yoshi);

    bool isDrawingCarryFukidashi();
    void getCcBounds(sRangeDataF* bounds); // @unofficial
    /* 0x8012E650 */ bool cancelCarry(dActor_c* carriedActor);

    void setFireBallDamage(u8 type);

    /* 0x80145C00 */ bool switchMode(PLAYER_MODE_e); // @unofficial

    mVec3_c getModelScaleBase();
    mVec3_c getModelScale();

    void calcInvalidKeyTimer();
    void calcTimerProc();
    void calcStarTimer();

    /* 0x80141020 */ void initChangeInit();
    /* 0x80141080 */ bool executeChangeInit();
    int change_reverse_scale_set();
    void initChangeNormal();
    bool executeChangeNormal();
    /* 0x80141080 */ void setChange(int);
    bool updateChange();

    void setFollowEffect(int);
    void setItemGetEffect();
    void setChukanPowerUpEffect();
    void updateItemGetEffect();
    void updateFollowEffect();

    void setCenterOffset();
    void selectAction();

    bool isDrawingFukidashi();
    void managePropelFukidashi();

    void setCcAtSpin();
    void setCcAtSpinFall();
    void setCcAtSpinLiftUp();
    void setCcAtNetPunch();
    void setCcData();
    void setCcDataDirect();

    void fn_80143060(sBcPointData& data1, sBcPointData& data2, bool); ///< @unofficial
    bool fn_80143220(sBcPointData& data1, sBcPointData& data2); ///< @unofficial
    void reviseBcDataCarryPlayer(sBcPointData& data1, sBcPointData& data2); ///< @unofficial
    void reviseBcDataCarryHardBlock(sBcPointData& data1, sBcPointData& data2); ///< @unofficial

    void setStarBase(StarSet_e, int);

    bool searchKinopioNearPlayer(float* dist);

    void setPlayerData();
    void setSpeedData();
    void setModeGravity();

    /* 0x8012DFC0 */ mVec3_c getCarryPos();

    /* +++ */ void setFallDownDemoNoMsg();

public:
    // Static Methods
    // ^^^^^^

    static bool ccCheckAttack(dCc_c* self, dCc_c* other);
    static bool ccCheckStamp(dCc_c* self, dCc_c* other);
    static bool ccCheckSideHit(dCc_c* self, dCc_c* other);
    static void ccCallBack(dCc_c* self, dCc_c* other);
    static void atCcCallBack(dCc_c* self, dCc_c* other);

    mMtx_c getCarryMtx()
    {
        mMtx_c mtx;
        mtx.trans(getCarryPos());
        mtx.concat(getModel()->getMtx());
        return mtx;
    }

public:
    // Virtual Methods
    // ^^^^^^

    /**
     * VT+0x08 0x80144EA0
     * do method for the create operation.
     */
    PACK_RESULT_e create() override;

    virtual PACK_RESULT_e preExecute() override;
    virtual void postExecute(MAIN_STATE_e status) override;
    virtual PACK_RESULT_e doDelete() override;
    virtual PACK_RESULT_e draw() override;

    virtual bool isSpinLiftUpEnable() override;
    virtual void setSpinLiftUpActor(dActor_c* carryingActor) override;

    virtual void setEatTongue(dActor_c* eatingActor) override;
    virtual void setEatTongueOff(dActor_c* eatingActor) override;
    virtual void setEatMouth(dActor_c* eatingActor) override;
    virtual bool setEatSpitOut(dActor_c* eatingActor) override;
    virtual void eatMove(dActor_c* eatingActor) override;

    virtual void executeMain() override;
    virtual void executeLastPlayer() override;
    virtual void executeLastAll() override;
    virtual bool isItemKinopio() override;
    virtual void setPowerup(PLAYER_MODE_e, PLAYER_MODE_e) override;
    virtual u8 getTallType(s8) override;

    virtual const sBcPointData* getHeadBgPointData() override
    {
        return &getBgPointData()->mHead;
    }

    virtual const sBcPointData* getWallBgPointData() override
    {
        return &getBgPointData()->mWall;
    }

    virtual const sBcPointData* getFootBgPointData() override
    {
        return &getBgPointData()->mFoot;
    }

    virtual float getStandHeadBgPointY() override;
    virtual void checkBgCrossSub() override;
    virtual void postBgCross() override;
    virtual float getSandSinkRate() override;
    virtual bool setPressBgDamage(int, int) override;
    /* VT+0x11C 0x80139340 */ virtual bool setBalloonInDispOut(int type) override;
    virtual bool isChange() override;
    virtual bool isEnableDokanInStatus() override;
    virtual bool setHideNotGoalPlayer() override;
    virtual int setDemoGoal(mVec3_c& landPos, float goalCastleX, u8 goalType) override;
    virtual bool setDemoCannonWarp(int, short, short) override;

public:
    // Virtual State IDs
    // ^^^^^^

    /**
     * initializeState: 0x801416E0
     * executeState:    0x801416F0
     * finalizeState:   0x80141770
     */
    sState_ExternVirtual(0x, dAcPy_c, DemoStartWait);

    /**
     * initializeState: 0x8013DC40
     * executeState:    0x8013DD70
     * finalizeState:   0x8013DD60
     */
    sState_ExternVirtual(0x8037692C, dAcPy_c, DemoDown);

public:
    // Virtual Methods
    // ^^^^^^

    virtual void initialDoor() override;
    virtual void initialVine() override;
    virtual void initialJumpRight() override;
    virtual void initialJumpLeft() override;
    virtual void initialSwim() override;
    virtual void initialBlockJump() override;
    virtual void initialBlockJumpBelow() override;

    virtual void setCreateAction(int) override;
    virtual bool setTimeOverDemo() override;
    /* VT+0x278 0x8013DF10 */ virtual void setFallDownDemo() override;
    virtual bool setDokanIn(DokanDir_e dir) override;
    virtual void initDemoOutDokan() override;
    virtual bool updateDemoKimePose(s32 clearType) override;
    virtual void initDemoGoalBase() override;
    /* VT+0x28C 0x801400B0 */ virtual void executeDemoGoal_Run() override;
    virtual void initializeDemoControl() override;

public:
    // Virtual State IDs
    // ^^^^^^

    /**
     * initializeState: 0x8012CCE0
     * executeState:    0x8012CE10
     * finalizeState:   0x8012CF80
     */
    sState_ExternVirtual(0x80375F2C, dAcPy_c, Walk);

    /**
     * initializeState: 0x801272B0
     * executeState:    0x80127480
     * finalizeState:   0x80127380
     */
    sState_ExternVirtual(0x80375F6C, dAcPy_c, Jump);

    /**
     * initializeState: 0x80127080
     * executeState:    0x80127230
     * finalizeState:   0x80127190
     */
    sState_ExternVirtual(0x80375FAC, dAcPy_c, Fall);

    /**
     * initializeState: 0x80128360
     * executeState:    0x801284B0
     * finalizeState:   0x80128420
     */
    sState_ExternVirtual(0x80375FEC, dAcPy_c, Land);

    /**
     * initializeState: 0x8012D760
     * executeState:    0x8012DBA0
     * finalizeState:   0x8012D900
     */
    sState_ExternVirtual(0x8037602C, dAcPy_c, Crouch);

    /**
     * initializeState: 0x80129DE0
     * executeState:    0x80129FE0
     * finalizeState:   0x80129EE0
     */
    sState_ExternVirtual(0x8037606C, dAcPy_c, SitJump);

    /**
     * initializeState: 0x8012AD30
     * executeState:    0x8012ADC0
     * finalizeState:   0x8012AD80
     */
    sState_ExternVirtual(0x803760AC, dAcPy_c, Slip);

    /**
     * initializeState: 0x8012D0C0
     * executeState:    0x8012D390
     * finalizeState:   0x8012D200
     */
    sState_ExternVirtual(0x803760EC, dAcPy_c, Turn);

    /**
     * initializeState: 0x80126950
     * executeState:    0x801269E0
     * finalizeState:   0x801269A0
     */
    sState_ExternVirtual(0x8037612C, dAcPy_c, HipAttack);

    /**
     * initializeState: 0x80130220
     * executeState:    0x80131F20
     * finalizeState:   0x80132370
     */
    sState_ExternVirtual(0x8037616C, dAcPy_c, Swim);

    /**
     * initializeState: 0x80135010
     * executeState:    0x80135E70
     * finalizeState:   0x80135120
     */
    sState_ExternVirtual(0x803761AC, dAcPy_c, Kani);

    /**
     * initializeState: 0x80139D90
     * executeState:    0x8013A070
     * finalizeState:   0x80139DD0
     */
    sState_ExternVirtual(0x803761EC, dAcPy_c, Cloud);

public:
    // Virtual Methods
    // ^^^^^^

    virtual bool isWaitFrameCountMax() override;
    virtual bool checkWalkNextAction() override;
    virtual void setWaitActionAnm(AnmBlend_e) override;
    virtual void setWalkActionAnm(AnmBlend_e) override;
    virtual void walkActionInit_Wait(AnmBlend_e) override;
    virtual void walkAction_Wait() override;
    virtual void walkActionInit_Move(AnmBlend_e) override;
    virtual void walkAction_Move() override;
    virtual bool checkCrouch() override;
    virtual bool setCancelCrouch() override;
    virtual void setSlipAction() override;
    virtual void slipActionMove(int) override;
    virtual void setHipAttack_AttackStart() override;

    virtual float getCloudOffsetY() override;
    virtual bool setRideJrCrown(const dActor_c*) override;
    virtual bool isRideJrCrownOwn(const dActor_c*) override;
    virtual void setRideJrCrownMtx(const mMtx_c*) override;
    virtual void setRideJrCrownAnm(int) override;

    virtual const mVec3_c* getHeadTopPosP() override;
    virtual const float* getGravityData() override;

    virtual bool isCarry() const override
    {
        return mCarryActorID != fBaseID_e::NONE;
    }

    virtual bool isLiftUp() override;
    virtual bool isLiftUpExceptMame() override;

    virtual void setStar(daPlBase_c::StarSet_e, int) override;
    virtual void endStar() override;
    virtual void setVirusStar(daPlBase_c*) override;

    virtual bool isNoDamage() override;
    /* VT+0x3F4 0x80146230 */ virtual bool setDamage(dActor_c* source, DamageType_e type) override;
    /* VT+0x3F8 0x80146310 */ virtual bool
    setForcedDamage(dActor_c* source, DamageType_e type) override;
    virtual bool
    setJump(float jumpSpeed, float speedF, bool allowSteer, int keyMode, int jumpMode) override;
    virtual bool
    _setJump(float jumpSpeed, float speedF, bool allowSteer, int keyMode, int jumpMode) override;

    virtual bool setHipAttackOnEnemy(mVec3_c* hitPos) override;

    virtual void clearJumpActionInfo(int) override;
    virtual bool setSwimSpeed(float speedY, float speedF) override;

    /* VT+0x418 0x801436C0 */ virtual void set1UpKinokoEffect() override;
    virtual void setFlagGetEffect() override;
    virtual void setHipAttackEffect() override;

    virtual void startQuakeShock(dQuake_c::TYPE_SHOCK_e) override;
    virtual void startPatternRumble(const char* pattern) override;

    virtual bool setDamage2(dActor_c*, daPlBase_c::DamageType_e) override;

    virtual void maxFallSpeedSet() override;

    virtual bool isCarryMamePlayer();

public:
    // Virtual State IDs
    // ^^^^^^

    /**
     * initializeState: 0x80129B40
     * executeState:    0x80129D60
     * finalizeState:   0x80129C70
     */
    sState_Extern(0x80376230, dAcPy_c, RideOffJump);

    /**
     * initializeState: 0x80126AB0
     * executeState:    0x80126BC0
     * finalizeState:   0x80126FD0
     */
    sState_Extern(0x80376270, dAcPy_c, SpinHipAttack);

    /**
     * initializeState: 0x8012ADD0
     * executeState:    0x8012AFA0
     * finalizeState:   0x8012AEE0
     */
    sState_Extern(0x803762B0, dAcPy_c, RollSlip);

    /**
     * initializeState: 0x80132930
     * executeState:    0x80133710
     * finalizeState:   0x80133BA0
     */
    sState_Extern(0x803762F0, dAcPy_c, Vine);

    /**
     * initializeState: 0x80133DF0
     * executeState:    0x80134190
     * finalizeState:   0x80134240
     */
    sState_Extern(0x80376330, dAcPy_c, Hang);

    /**
     * initializeState: 0x801343C0
     * executeState:    0x80134AD0
     * finalizeState:   0x80134BF0
     */
    sState_Extern(0x80376370, dAcPy_c, Pole);

    /**
     * initializeState: 0x8013BF10
     * executeState:    0x8013C050
     * finalizeState:   0x8013BFC0
     */
    sState_Extern(0x803763B0, dAcPy_c, Fire);

    /**
     * initializeState: 0x8012F480
     * executeState:    0x8012F600
     * finalizeState:   0x8012F5A0
     */
    sState_Extern(0x803763F0, dAcPy_c, LiftUp);

    /**
     * initializeState: 0x8012F180
     * executeState:    0x8012F1A0
     * finalizeState:   0x8012F190
     */
    sState_Extern(0x80376430, dAcPy_c, Throw);

    /**
     * initializeState: 0x8012F210
     * executeState:    0x8012F230
     * finalizeState:   0x8012F220
     */
    sState_Extern(0x80376470, dAcPy_c, PropelThrow);

    /**
     * initializeState: 0x80128C40
     * executeState:    0x80128EA0
     * finalizeState:   0x80128E60
     */
    sState_Extern(0x803764B0, dAcPy_c, WallJump);

    /**
     * initializeState: 0x80128810
     * executeState:    0x80128AC0
     * finalizeState:   0x801288F0
     */
    sState_Extern(0x803764F0, dAcPy_c, WallSlide);

    /**
     * initializeState: 0x8013CBC0
     * executeState:    0x8013CDD0
     * finalizeState:   0x8013CCD0
     */
    sState_Extern(0x80376530, dAcPy_c, Propel);

    /**
     * initializeState: 0x8013A570
     * executeState:    0x8013A7B0
     * finalizeState:   0x8013A680
     */
    sState_Extern(0x80376570, dAcPy_c, CarryPlayer);

    /**
     * initializeState: 0x80139B50
     * executeState:    0x80139CC0
     * finalizeState:   0x80139BD0
     */
    sState_Extern(0x803765B0, dAcPy_c, RideYoshi);

    /**
     * initializeState: 0x80129470
     * executeState:    0x80129640
     * finalizeState:   0x801298D0
     */
    sState_Extern(0x803765F0, dAcPy_c, SpinJump);

    /**
     * initializeState: 0x8012B310
     * executeState:    0x8012B6F0
     * finalizeState:   0x8012B4F0
     */
    sState_Extern(0x80376630, dAcPy_c, PenguinSlide);

    /**
     * initializeState: 0x8012A140
     * executeState:    0x8012A2B0
     * finalizeState:   0x8012A200
     */
    sState_Extern(0x80376670, dAcPy_c, KaniJump);

    /**
     * initializeState: 0x80137810
     * executeState:    0x80137940
     * finalizeState:   0x801378E0
     */
    sState_Extern(0x803766B0, dAcPy_c, Quake);

    /**
     * initializeState: 0x80137A90
     * executeState:    0x80137B30
     * finalizeState:   0x80137AF0
     */
    sState_Extern(0x803766F0, dAcPy_c, ElecShock);

    /**
     * initializeState: 0x80137F60
     * executeState:    0x80138280
     * finalizeState:   0x80138210
     */
    sState_Extern(0x80376730, dAcPy_c, FlyDamage);

    /**
     * initializeState: 0x801395E0
     * executeState:    0x80139780
     * finalizeState:   0x80139700
     */
    sState_Extern(0x80376770, dAcPy_c, IceDamage);

    /**
     * initializeState: 0x8012A350
     * executeState:    0x8012A570
     * finalizeState:   0x8012A4B0
     */
    sState_Extern(0x803767B0, dAcPy_c, CannonJump);

    /**
     * initializeState: 0x801362D0
     * executeState:    0x80137460
     * finalizeState:   0x80136480
     */
    sState_Extern(0x803767F0, dAcPy_c, TarzanRope);

    /**
     * initializeState: 0x8013B370
     * executeState:    0x8013B510
     * finalizeState:   0x8013B460
     */
    sState_Extern(0x80376830, dAcPy_c, PlayerEat);

    /**
     * initializeState: 0x801388D0
     * executeState:    0x80138BD0
     * finalizeState:   0x80138AD0
     */
    sState_Extern(0x80376870, dAcPy_c, Balloon);

    /**
     * initializeState: 0x8012A940
     * executeState:    0x8012AA60
     * finalizeState:   0x8012AA10
     */
    sState_Extern(0x803768B0, dAcPy_c, BlockJump);

    /**
     * initializeState: 0x8013B8E0
     * executeState:    0x8013BA00
     * finalizeState:   0x8013B980
     */
    sState_Extern(0x803768F0, dAcPy_c, JrCrown);

    /**
     * initializeState: 0x8013EA60
     * executeState:    0x8013EBD0
     * finalizeState:   0x8013EB70
     */
    sState_Extern(0x80376970, dAcPy_c, DemoInDoor);

    /**
     * initializeState: 0x8013EE50
     * executeState:    0x8013EF40
     * finalizeState:   0x8013EF30
     */
    sState_Extern(0x803769B0, dAcPy_c, DemoInJump);

    /**
     * initializeState: 0x8013F090
     * executeState:    0x8013F130
     * finalizeState:   0x8013F120
     */
    sState_Extern(0x803769F0, dAcPy_c, DemoInVine);

    /**
     * initializeState: 0x8013F490
     * executeState:    0x8013FAE0
     * finalizeState:   0x8013F600
     */
    sState_Extern(0x80376A30, dAcPy_c, DemoOutDoor);

    /**
     * initializeState: 0x8013DF80
     * executeState:    0x8013E090
     * finalizeState:   0x8013E080
     */
    sState_Extern(0x80376A70, dAcPy_c, DemoFallDown);

    /**
     * initializeState: 0x8013E140
     * executeState:    0x8013E2B0
     * finalizeState:   0x8013E2A0
     */
    sState_Extern(0x80376AB0, dAcPy_c, DemoFireDown);

    /**
     * initializeState: 0x8013E540
     * executeState:    0x8013E5F0
     * finalizeState:   0x8013E5B0
     */
    sState_Extern(0x80376AF0, dAcPy_c, DemoEatDie);

    /**
     * initializeState: 0x8013FC80
     * executeState:    0x8013FD30
     * finalizeState:   0x8013FCF0
     */
    sState_Extern(0x80376B30, dAcPy_c, DemoDokanCannon);

    /**
     * initializeState: 0x801407B0
     * executeState:    0x80140830
     * finalizeState:   0x80140820
     */
    sState_Extern(0x80376B70, dAcPy_c, DemoCannonWarp);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x14D4 */ PLAYER_TYPE_e mPlayerType;

    FILL(0x14D8, 0x14E0);

    /* 0x14E0 */ PLAYER_MODE_e mNextMode;

    FILL(0x14E4, 0x153C);

    /* 0x153C */ u8 mScrollType;

    FILL(0x153D, 0x1554);

    /* 0x1554 */ int m0x1554;

    FILL(0x1558, 0x27D4);

    /* 0x27D4 */ fBaseID_e m0x27D4;
    /* 0x27D8 */ float m0x27D8;
    /* 0x27DC */ float m0x27DC;
    /* 0x27E0 */ int m0x27E0;

    FILL(0x27E4, 0x2A60);

    /* 0x2A60 */ dPyMdlMng_c mPyMdlMng;
    /* 0x2A6C */ float m0x2A6C;
    /* 0x2A70 */ float m0x2A70;
    /* 0x2A74 */ u32 m0x2A74;
    /* 0x2A78 */ fBaseID_e mCarryActorID;
};
