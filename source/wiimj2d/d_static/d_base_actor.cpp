// d_base_actor.cpp
// NSMBW .text: 0x8006C6D0 - 0x8006CF40

#include "d_base_actor.h"

[[nsmbw(0x8006C6D0)]]
dBaseActor_c::dBaseActor_c();

/**
 * VT+0x48
 * Destroys the base.
 */
[[nsmbw(0x8006C7F0)]]
dBaseActor_c::~dBaseActor_c();

/**
 * VT+0x0C
 * pre method for the create operation.
 */
[[nsmbw(0x8006C870)]]
fBase_c::PACK_RESULT_e dBaseActor_c::preCreate();

/**
 * VT+0x10
 * post method for the create operation.
 */
[[nsmbw(0x8006C8A0)]]
void dBaseActor_c::postCreate(fBase_c::MAIN_STATE_e status);

/**
 * VT+0x18
 * pre method for the delete operation.
 */
[[nsmbw(0x8006C8B0)]]
fBase_c::PACK_RESULT_e dBaseActor_c::preDelete();

/**
 * VT+0x1C
 * post method for the delete operation.
 */
[[nsmbw(0x8006C8E0)]]
void dBaseActor_c::postDelete(fBase_c::MAIN_STATE_e status);

/**
 * VT+0x24
 * pre method for the execute operation.
 */
[[nsmbw(0x8006C8F0)]]
fBase_c::PACK_RESULT_e dBaseActor_c::preExecute();

/**
 * VT+0x28
 * post method for the execute operation.
 */
[[nsmbw(0x8006C980)]]
void dBaseActor_c::postExecute(fBase_c::MAIN_STATE_e status);

/**
 * VT+0x30
 * pre method for the draw operation.
 */
[[nsmbw(0x8006C9F0)]]
fBase_c::PACK_RESULT_e dBaseActor_c::preDraw();

/**
 * VT+0x34
 * post method for the draw operation.
 */
[[nsmbw(0x8006CA40)]]
void dBaseActor_c::postDraw(fBase_c::MAIN_STATE_e status);

/**
 * VT+0x50
 * Alternate drawing function used to draw 3D models in front of 2D graphics (first draw
 * pass).This feature is not used in stages. See [here](#drawing-models-over-2d-layouts) for
 * details.
 */
[[nsmbw(0x8006CA50)]]
void dBaseActor_c::draw2D();

/**
 * VT+0x54
 * Alternate drawing function used to draw 3D models in front of 2D graphics (second
 * draw pass). This feature is not used in stages. See [here](#drawing-models-over-2d-layouts)
 * for details.
 */
[[nsmbw(0x8006CA60)]]
void dBaseActor_c::draw2D_lyt2();

/**
 * Updates the actor's speed (3D actors).
 */
[[nsmbw(0x8006CC00)]]
void dBaseActor_c::calcSpeed();

/**
 * Updates the actor's speed (2D actors).
 */
[[nsmbw(0x8006CD50)]]
void dBaseActor_c::calcSpeedXY();

/**
 * Updates the actor's X speed.
 */
[[nsmbw(0x8006CD90)]]
void dBaseActor_c::calcSpeedX();

/**
 * Updates the actor's falling speed.
 */
[[nsmbw(0x8006CE70)]]
void dBaseActor_c::calcFallSpeed();

/**
 * Updates the actor's Y speed.
 */
[[nsmbw(0x8006CDE0)]]
void dBaseActor_c::calcSpeedY();

/**
 * Updates the actor's forward speed.
 */
[[nsmbw(0x8006CE10)]]
void dBaseActor_c::calcSpeedF();

/**
 * Generates a partial transformation matrix for the actor and stores it in mMatrix. The
 * transformation matrix only contains the translation and the rotation on the Y axis.
 */
[[nsmbw(0x8006CCB0)]]
void dBaseActor_c::makeMtx();

/**
 * Gets the actor's centered position.
 */
[[nsmbw(0x8006CED0)]]
mVec3_c dBaseActor_c::getCenterPos() const;

/**
 * Moves the actor by the given delta.
 */
[[nsmbw(0x8006CD00)]]
void dBaseActor_c::posMove(mVec3_c& delta);

/**
 * Moves the actor by its mSpeed "speed".
 */
[[nsmbw(0x8006CD40)]]
void dBaseActor_c::posMove();

/**
 * Counts the instances of the given actor profile. [why is this not static?]
 */
[[nsmbw(0x8006CF10)]]
int dBaseActor_c::GetProfNameActorNum(u16 profile);

/**
 * Calls draw2D on every actor.
 */
[[nsmbw(0x8006CAE0)]]
void dBaseActor_c::draw2DActorOnLyt1();

/**
 * Calls draw2D_lyt2 on every actor.
 */
[[nsmbw(0x8006CB40)]]
void dBaseActor_c::draw2DActorOnLyt2();

/**
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
[[nsmbw(0x8006CA80)]]
dBaseActor_c* dBaseActor_c::construct(
  u16 profName, unsigned long param, const mVec3_c* position, const mAng3_c* rotation
);

/**
 * Creates a child actor with the given parent.
 *
 * @param profName The actor's profile name.
 * @param parent The actor's parent. Must not be nullptr.
 * @param param The actor's parameters.
 * @param position The actor's position.
 * @param rotation The actor's rotation.
 * @return A pointer to the instantiated actor, or nullptr.
 */
[[nsmbw(0x8006CBA0)]]
dBaseActor_c* dBaseActor_c::construct(
  u16 profName, dBase_c* parent, unsigned long param, const mVec3_c* position,
  const mAng3_c* rotation
);

/**
 * Sets temporary data to be used for the next actor's construction.
 *
 * @param position The actor's position.
 * @param rotation The actor's rotation.
 */
[[nsmbw(0x8006CA70)]]
void dBaseActor_c::setTmpCtData(const mVec3_c* position, const mAng3_c* rotation);
