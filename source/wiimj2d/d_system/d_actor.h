#pragma once

#include "d_system/d_a_player_manager.h"
#include "d_system/d_base_actor.h"
#include "machine/m_vec.h"
#include "nw4r/ut/Rect.h"

class dActor_c : public dBaseActor_c
{
    SIZE_ASSERT(0x392);

public:
    // Structors
    // ^^^^^^

    /* 0x80064110 */
    dActor_c();

    /* VT+0x44 0x800642B0 */
    virtual ~dActor_c();

public:
    // Static Constants
    // ^^^^^^

    enum class ACTOR_TYPE_e : u8 {
        DEFAULT = 0,
        PLAYER = 1,
        YOSHI = 2,
        ENEMY = 3,
    };

    enum CARRY_ACTION_e {
        CARRY_RELEASE = EGG::BitFlag(0),
        CARRY_THROW = EGG::BitFlag(1),
    };

public:
    // Virtual Methods
    // ^^^^^^

    /**
     * VT+0x0C 0x80064350
     * pre method for the create operation.
     */
    virtual PACK_RESULT_e preCreate() override;

    /**
     * VT+0x10 0x80064380
     * post method for the create operation.
     */
    virtual void postCreate(fBase_c::MAIN_STATE_e status) override;

    /**
     * VT+0x18 0x80064390
     * pre method for the delete operation.
     */
    virtual PACK_RESULT_e preDelete() override;

    /**
     * VT+0x1C 0x800643E0
     * post method for the delete operation.
     */
    virtual void postDelete(fBase_c::MAIN_STATE_e status) override;

    /**
     * VT+0x24 0x800643F0
     * pre method for the execute operation.
     */
    virtual PACK_RESULT_e preExecute() override;

    /**
     * VT+0x28 0x80064490
     * post method for the execute operation.
     */
    virtual void postExecute(fBase_c::MAIN_STATE_e status) override;

    /**
     * VT+0x30 0x80064540
     * pre method for the draw operation.
     */
    virtual PACK_RESULT_e preDraw() override;

    /**
     * VT+0x34 0x800645E0
     * post method for the draw operation.
     */
    virtual void postDraw(fBase_c::MAIN_STATE_e status) override;

    /**
     * VT+0x4C 0x800645F0
     * Gets a string describing the kind of this base.
     */
    virtual const char* getKindString() const override;

    /* VT+0x60 0x80065080 */
    virtual bool ActorDrawCullCheck();

    /* VT+0x64 0x80065650 */
    virtual void block_hit_init();

    /* VT+0x68 0x8001D210 */
    virtual bool VT_0x68()
    {
        return true;
    }

    /* VT+0x6C 0x8001D200 */
    virtual u8* getPlrNo()
    {
        return &mPlayerNo;
    }

    /* VT+0x70 0x80065620 */
    virtual mVec3_c getLookatPos() const;

    /* VT+0x74 0x8001D1F0 */
    virtual bool isSpinLiftUpEnable()
    {
        return true;
    }

    /* VT+0x78 0x80065820 */
    virtual void setSpinLiftUpActor(dActor_c* actor);

    /* VT+0x7C 0x8001D1E0 */
    virtual void setCarryFall(dActor_c* actor, int param2)
    {
    }

    /* VT+0x80 0x80065830 */
    virtual void setEatTongue(dActor_c* actor);

    /* VT+0x84 0x80065850 */
    virtual void setEatTongueOff(dActor_c* actor);

    /* VT+0x88 0x80065860 */
    virtual void setEatMouth(dActor_c* actor);

    /* VT+0x8C 0x80065870 */
    virtual bool setEatSpitOut(dActor_c* actor);

    /* VT+0x90 0x80065880 */
    virtual bool setEatGlupDown(dActor_c* actor);

    /* VT+0x94 0x80065AC0 */
    virtual void eatMove(dActor_c* actor);

    /* VT+0x98 0x80066080 */
    virtual void removeCc();

    /* VT+0x9C 0x80066090 */
    virtual void reviveCc();

    /* VT+0xA0 0x80065950 */
    virtual void setAfterEatScale();

    /* VT+0xA4 0x80065970 */
    virtual void calcSpitOutPos(dActor_c* actor);

    /* VT+0xA8 0x80065A00 */
    virtual float calcEatScaleRate(dActor_c* yoshi);

    /* VT+0xAC 0x80065A40 */
    virtual void calcEatInScale(dActor_c* yoshi);

    /* VT+0xB0 0x80065660 */
    virtual bool allEnemyDeathEffSet();

    /* VT+0xB4 0x80065B40 */
    virtual void VT_0xB4();

    /* VT+0xB8 0x8001D1D0 */
    virtual void funsuiMoveX()
    {
    }

    /* VT+0xBC 0x80065B50 */
    virtual void cancelFunsuiActUpper();

    /* VT+0xC0 0x80065B60 */
    virtual void cancelFunsuiActSide();

    /* VT+0xC4 0x80065B70 */
    virtual void cancelFunsuiActVanish();

    /* VT+0xC8 0x80065CC0 */
    virtual void waterSplashEffect(const mVec3_c& position, float scale);

    /* VT+0xCC 0x80065DC0 */
    virtual void yoganSplashEffect(const mVec3_c& position, float scale);

    /* VT+0xD0 0x80065EC0 */
    virtual void poisonSplashEffect(const mVec3_c& position, float scale);

public:
    // Instance Methods
    // ^^^^^^

    [[nodiscard]]
    daPlBase_c* castToPlayerBase()
    {
        if (mActorType == ACTOR_TYPE_e::PLAYER || mActorType == ACTOR_TYPE_e::YOSHI) {
            return reinterpret_cast<daPlBase_c*>(this);
        }

        return nullptr;
    }

    [[nodiscard]]
    dAcPy_c* castToPlayer()
    {
        if (mActorType == ACTOR_TYPE_e::PLAYER) {
            return reinterpret_cast<dAcPy_c*>(this);
        }

        return nullptr;
    }

    /* 0x800646E0 */
    void setKind(u8);

    /* 0x80064740 */
    dAcPy_c* searchNearPlayer(mVec2_c&);

    /* 0x80064AF0 */
    void changePosAngle(mVec3_c*, mAng3_c*, int);

    /* 0x80064B00 */
    void setChangePosAngleFunc(int);

    /* 0x80064B10 */
    void setLoopFunc(int);

    /* 0x80064B50 */
    bool checkAreaNo();

    /* 0x80064D10 */
    void deleteActor(u8);

    /* 0x80064DA0 @unofficial */
    bool checkOutOfArea(const mVec3_c& pos, const nw4r::ut::Rect& rect, u8 area);

    /* 0x800651C0 */
    void carryFukidashiCheck(int param1, mVec2_c param2);

    /* 0x80065480 */
    void carryFukidashiCancel(int param1, int param2);

    /* 0x80065520 */
    dAcPy_c* searchCarryFukidashiPlayer(int param1);

    /* 0x80064F50 */
    void ActorScrOutCheck(u16);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x125 */ u8 mCarryPlayerNo;
    /* 0x128 */ u32 mCarryFukidashiPlayerNo;
    /* 0x12C */ u32 mCarryingFlags;
    /* 0x130 */ u8 mThrowDirection;
    /* 0x134 */ int mComboMultiplier;
    
    FILL(0x138, 0x175);

    /* 0x175 */ u8 m0x175;
    /* 0x178 */ u32 m0x178;

    FILL(0x17C, 0x348);

    /* 0x348 */ u8 mDirection;

    FILL(0x349, 0x38C);

    /* 0x38C */ ACTOR_TYPE_e mActorType;
    /* 0x38D */ u8 mPlayerNo;
    /* 0x38E */ u8 m0x38E;
    /* 0x38F */ u8 mLayer;
    /* 0x390 */ u8 m0x390;
    /* 0x391 */ u8 mAmiLayer;

public:
    // Static Methods
    // ^^^^^^

    /* 0x80064600 */
    static void setTmpCtData(u8);

    /* 0x80064610 */
    static dActor_c* construct(
      u16 profile, u32 settings, const mVec3_c* position, const mAng3_c* rotation, u8 layer
    );

    /* 0x80064680 */
    static dActor_c* construct(
      u16 profile, dBase_c* owner, u32 settings, const mVec3_c* position, const mAng3_c* rotation,
      u8 layer
    );

    /* 0x80064720 */
    static void setSearchNearPlayerFunc(int);

    /* 0x80064790 */
    static dAcPy_c* searchNearPlayer_Main(mVec2_c&, const mVec2_c&);

    /* 0x800647A0 */
    static dAcPy_c* searchNearPlayerNormal(mVec2_c&, const mVec2_c&);

    /* 0x80064880 */
    static dAcPy_c* searchNearPlayerLoop(mVec2_c&, const mVec2_c&);

    /* 0x80064A10 */
    static void setGetTrgToSrcDirFunc(int);

    /* 0x80064A30 */
    static bool getTrgToSrcDir_Main(f32, f32);

    /* 0x80064A40 */
    static bool getTrgToSrcDirNormal(f32, f32);

    /* 0x80064A50 */
    static bool getTrgToSrcDirLoop(f32, f32);

    /* 0x80064BC0 */
    static void setSoftLight_Player(m3d::bmdl_c& model);

    /* 0x80064BD0 */
    static void setSoftLight_Enemy(m3d::bmdl_c& model);

    /* 0x80064BE0 */
    static void setSoftLight_Map(m3d::bmdl_c& model);

    /* 0x80064BF0 */
    static void setSoftLight_MapObj(m3d::bmdl_c& model);

    /* 0x80064C00 */
    static void setSoftLight_Boss(m3d::bmdl_c& model);

    /* 0x80064C10 */
    static void setSoftLight_Item(m3d::bmdl_c& model);

public:
    // Static Variables
    // ^^^^^^

    /* 0x80429FD8 */ static u8 mExecStopReq;

    /* 0x80429FDA */ static u8 mExecStop;
};
