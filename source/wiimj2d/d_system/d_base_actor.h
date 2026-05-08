#pragma once

#include "d_system/d_base.h"
#include "framework/f_list.h"
#include "machine/m_angle.h"
#include "machine/m_mtx.h"
#include "machine/m_vec.h"

struct dBaseActorProfile_s : dBaseProfile_s {
    /**
     * Various actor-related properties.
     */
    u32 mActorProps;
};

/**
 * The minimum required implementation for an actor base.
 */
class dBaseActor_c : public dBase_c {
    SIZE_ASSERT(0x125);

public:
    /**
     * An identifier that represents the actor's kind. This is only used in world maps.
     */
    enum ACTOR_KIND_e {
        ACTOR_MAP_GENERIC = 0, // A generic map actor (dWmActor_c).
        ACTOR_MAP_DEMO    = 1, // A map actor affected by cutscenes (dWmDemoActor_c).
        ACTOR_MAP_OBJECT  = 2, // A map object (dWmObjActor_c).
        ACTOR_MAP_ENEMY   = 3, // A map enemy (dWmEnemy_c).
        ACTOR_MAP_PLAYER  = 4, // The worldmap player actor (dWmPlayer_c).
        ACTOR_MAP_STOP    = 5, // @unused The unused map stop actor (daWmStop_c).
        ACTOR_UNK_6       = 6, // @unused Not used anywhere.
        ACTOR_MENU_PLAYER = 7, // The menu player actor (da2DPlayer_c).
        ACTOR_GENERIC     = 8, // A generic non-map actor.
    };

    /* 0x8006C6D0 */
    dBaseActor_c();

protected:
    /**
     * VT+0x0C 0x8006C870
     * pre method for the create operation.
     */
    virtual PACK_RESULT_e preCreate() override;

    /**
     * VT+0x10 0x8006C8A0
     * post method for the create operation.
     */
    virtual void postCreate(fBase_c::MAIN_STATE_e status) override;

    /**
     * VT+0x18 0x8006C8B0
     * pre method for the delete operation.
     */
    virtual PACK_RESULT_e preDelete() override;

    /**
     * VT+0x1C 0x8006C8E0
     * post method for the delete operation.
     */
    virtual void postDelete(fBase_c::MAIN_STATE_e status) override;

    /**
     * VT+0x24 0x8006C8F0
     * pre method for the execute operation.
     */
    virtual PACK_RESULT_e preExecute() override;

    /**
     * VT+0x28 0x8006C980
     * post method for the execute operation.
     */
    virtual void postExecute(fBase_c::MAIN_STATE_e status) override;

    /**
     * VT+0x30 0x8006C9F0
     * pre method for the draw operation.
     */
    virtual PACK_RESULT_e preDraw() override;

    /**
     * VT+0x34 0x8006CA40
     * post method for the draw operation.
     */
    virtual void postDraw(fBase_c::MAIN_STATE_e status) override;

    /**
     * VT+0x48 0x8006C7F0
     * Destroys the base.
     */
    virtual ~dBaseActor_c() override;

    /**
     * VT+0x50 0x8006CA50
     * Alternate drawing function used to draw 3D models in front of 2D graphics (first draw
     * pass).This feature is not used in stages. See [here](#drawing-models-over-2d-layouts) for
     * details.
     */
    virtual void draw2D();

    /**
     * VT+0x54 0x8006CA60
     * Alternate drawing function used to draw 3D models in front of 2D graphics (second
     * draw pass). This feature is not used in stages. See [here](#drawing-models-over-2d-layouts)
     * for details.
     */
    virtual void draw2D_lyt2();

    /**
     * VT+0x58 0x8001D1C0, 0x807B6C80 - d_a_boss_demo.o, ?
     * Gets the actor kind. See ACTOR_KIND_e.
     */
    virtual ACTOR_KIND_e GetActorType() { return ACTOR_GENERIC; }

    /**
     * VT+0x5C 0x8001D1B0, 0x807B6C70 - d_a_boss_demo.o, ?
     * Code to be executed after all actors' execute operation has run.
     */
    virtual void finalUpdate() {}

public:
    /**
     * 0x8006CC00
     * Updates the actor's speed (3D actors).
     */
    void calcSpeed();

    /**
     * 0x8006CD50
     * Updates the actor's speed (2D actors).
     */
    void calcSpeedXY();

    /**
     * 0x8006CD90
     * Updates the actor's X speed.
     */
    void calcSpeedX();

    /**
     * 0x8006CE70
     * Updates the actor's falling speed.
     */
    void calcFallSpeed();

    /**
     * 0x8006CDE0
     * Updates the actor's Y speed.
     */
    void calcSpeedY();

    /**
     * 0x8006CE10
     * Updates the actor's forward speed.
     */
    void calcSpeedF();

    /**
     * 0x8006CCB0
     * Generates a partial transformation matrix for the actor and stores it in mMatrix. The
     * transformation matrix only contains the translation and the rotation on the Y axis.
     */
    void makeMtx();

    /**
     * 0x8006CED0
     * Gets the actor's centered position.
     */
    mVec3_c getCenterPos() const;

    /**
     * 0x8006CD00
     * Moves the actor by the given delta.
     */
    void posMove(mVec3_c& delta);

    /**
     * 0x8006CD40
     * Moves the actor by its mSpeed "speed".
     */
    void posMove();

    /**
     * 0x8006CF10
     * Counts the instances of the given actor profile. [why is this not static?]
     */
    int GetProfNameActorNum(u16 profile);

    /**
     * 0x8006CAE0
     * Calls draw2D on every actor.
     */
    static void draw2DActorOnLyt1();

    /**
     * 0x8006CB40
     * Calls draw2D_lyt2 on every actor.
     */
    static void draw2DActorOnLyt2();

    /**
     * 0x8006CA80
     * Creates an actor without a parent. The actor is created as a child of the current scene
     * actor, so that all actors can be deleted on a scene change, acting as a garbage collection
     * mechanism.
     *
     * @param profName The actor's profile name.
     * @param param The actor's parameters.
     * @param position The actor's position.
     * @param rotation The actor's rotation.
     * @return A pointer to the instantiated actor, or nullptr.
     */
    static dBaseActor_c*
    construct(u16 profName, u32 param, const mVec3_c* position, const mAng3_c* rotation);

    /**
     * 0x8006CBA0
     * Creates a child actor with the given parent.
     *
     * @param profName The actor's profile name.
     * @param parent The actor's parent. Must not be nullptr.
     * @param param The actor's parameters.
     * @param position The actor's position.
     * @param rotation The actor's rotation.
     * @return A pointer to the instantiated actor, or nullptr.
     */
    static dBaseActor_c* construct(
        u16 profName, dBase_c* parent, u32 param, const mVec3_c* position, const mAng3_c* rotation
    );

private:
    /**
     * 0x8006CA70
     * Sets temporary data to be used for the next actor's construction.
     *
     * @param position The actor's position.
     * @param rotation The actor's rotation.
     */
    static void setTmpCtData(const mVec3_c* position, const mAng3_c* rotation);

    /**
     * The node in m_actorManage.
     */
    /* 0x070 */ fLiNdBa_c mLinkActor;

public:
    /**
     * The actor's partial transformation matrix.
     */
    /* 0x07C */ mMtx_c mMatrix;

    /**
     * The actor's position.
     */
    /* 0x0AC */ mVec3_c mPos;

    /**
     * The actor's position in the previous frame.
     */
    /* 0x0B8 */ mVec3_c mLastPos;

    /**
     * The actor's position delta since the previous frame.
     */
    /* 0x0C4 */ mVec3_c mPosDelta;

    /**
     * The offset from the position to the center of the actor (defaults to 0).
     */
    /* 0x0D0 */ mVec3_c mCenterOffs;

    /**
     * The actor's scale (defaults to 1).
     */
    /* 0x0DC */ mVec3_c mScale;

    /**
     * The actor's speed.
     */
    /* 0x0E8 */ mVec3_c mSpeed;

    /**
     * The actor's maximum speed.
     */
    /* 0x0F4 */ mVec3_c mSpeedMax;

    /**
     * The actor's rotation (for 2D actors).
     */
    /* 0x100 */ mAng3_c mAngle;

    /**
     * The actor's rotation (for 3D actors).
     */
    /* 0x106 */ mAng3_c mAngle3D;

    /**
     * The actor's horizontal speed.
     */
    /* 0x10C */ float mSpeedF;

    /**
     * The actor's maximum horizontal speed.
     */
    /* 0x110 */ float mMaxSpeedF;

    /**
     * The actor's vertical acceleration.
     */
    /* 0x114 */ float mAccelY;

    /**
     * The actor's maximum fall speed.
     */
    /* 0x118 */ float mMaxFallSpeed;

    /**
     * The actor's horizontal acceleration.
     */
    /* 0x11C */ float mAccelF;

    /**
     * The actor's properties.
     */
    /* 0x120 */ u32 mActorProperties;

    /**
     * Whether the actor should be visible or not. Defaults to true.
     */
    /* 0x124 */ bool mVisible;

private:
    /**
     * Temporary storage for the next constructed actor's position.
     */
    static const mVec3_c* m_tmpCtPosP;

    /**
     * Temporary storage for the next constructed actor's rotation.
     */
    static const mAng3_c* m_tmpCtAngleP;

    /**
     * A list of all actor bases.
     */
    // static fLiMgBa_c m_actorManage;
};
