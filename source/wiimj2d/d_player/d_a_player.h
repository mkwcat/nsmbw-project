#pragma once

#include "d_player/d_a_yoshi.h"
#include "d_profile/d_profile.h"
#include "d_system/d_a_player_base.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_cc.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_player_model_manager.h"
#include "state/s_State.h"

class dAcPy_c : public daPlBase_c, public dProf::Info<dAcPy_c, dProf::PLAYER>
{

public:
    // Instance Methods
    // ^^^^^^

    /* 0x801275B0 */
    float getJumpSpeed();

    /* 0x8012DD20 */
    dAcPy_c* getCarryPlayer();

    /* 0x8012DFC0 */
    mVec3_c getCarryPos();

    /* 0x8012E260 */
    void clearSpinLiftUpReserve();

    /* 0x8012E330 */
    void setSpinLiftUpReserve();

    /* 0x8012E650 */
    void cancelCarry(dActor_c* carriedActor);

    /* 0x8012E6E0 */
    bool releaseCarryActor();

    /* 0x80138E80 */
    void setBalloonHelpVoice();

    /* 0x80138FA0 */
    bool setBalloonInDamage();

    /* 0x80139330 */
    bool setBalloonInDispOutByYoshi(int type);

    /* 0x80139350 */
    bool setBalloonInDispOutBase(int type, bool yoshi, bool noDeathMsg);

    /* 0x8013D7B0 */
    void checkRest();

    /* 0x8013DA30 */
    void stopOtherDownDemo();

    /* 0x8013DB30 */
    void playOtherDownDemo();

    /* 0x8013FBE0 */
    void endDemoDokanCannon(mVec3_c&);

    /* 0x80141020 */
    void initChangeInit();

    /* 0x80141080 */
    bool executeChangeInit();

    /* 0x80141080 */
    void setChange(int param);

    /* 0x80144C60 */
    void setSceneChangeInfo();

    /* 0x80145C00 */
    bool switchMode(PLAYER_MODE_e mode);

    /* 0x80146F60 */
    void setCannonJump(float, float, int);

    void setFallDownDemoNoMsg();

    /* 0x80139800 */
    void setRideOffPlayerJump(f32, f32);

    /* 0x80139910 */
    void setRideOffYoshiJump(daPlBase_c*);

    /* 0x80139A90 */
    daYoshi_c* getRideYoshi();

    /* 0x80139AE0 */
    void setRideOnYoshi(daYoshi_c* yoshi);

    mMtx_c getCarryMtx()
    {
        mMtx_c mtx;
        mtx.trans(getCarryPos());
        mtx.concat(getModel()->getMtx());
        return mtx;
    }

public:
    // Virtual Functions
    // ^^^^^^

    /**
     * VT+0x08 0x80144EA0
     * do method for the create operation.
     */
    PACK_RESULT_e create() override;

    /* VT+0x11C 0x80139340 */
    bool setBalloonInDispOut(int type) override;

    /* VT+0x278 0x8013DF10 */
    void setFallDownDemo() override;

    /* VT+0x28C 0x801400B0 */
    void executeDemoGoal_Run() override;

    /* VT+0x3F4 0x80146230 */
    bool setDamage(dActor_c* source, DamageType_e type) override;

    /* VT+0x3F8 0x80146310 */
    bool setForcedDamage(dActor_c* source, DamageType_e type) override;

    /* VT+0x418 0x801436C0 */
    void set1UpKinokoEffect() override;

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

public:
    // State IDs
    // ^^^^^^

    sState_Extern(0x803763F0, dAcPy_c, LiftUp);

    sState_Extern(0x80376A70, dAcPy_c, DemoFallDown);
};
