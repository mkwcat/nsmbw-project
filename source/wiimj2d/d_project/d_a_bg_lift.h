#pragma once

#include "d_system/d_PanelObjList.h"
#include "d_system/d_actor_state.h"
#include "state/s_State.h"

class daBgLift_c : public dActorMultiState_c
{
public:
    // Structors
    // ^^^^^^

    daBgLift_c();

    /* VT+0x48 */
    virtual ~daBgLift_c();

public:
    // Virtual Functions
    // ^^^^^^

    /**
     * VT+0x08
     * do method for the create operation.
     */
    virtual PACK_RESULT_e create() override;

    /**
     * VT+0x14
     * do method for the delete operation. This method was renamed due to conflict with the delete
     * C++ keyword.
     */
    virtual PACK_RESULT_e doDelete() override;

    /**
     * VT+0x20
     * do method for the execute operation.
     */
    virtual PACK_RESULT_e execute() override;

    /**
     * VT+0x5C
     * Code to be executed after all actors' execute operation has run.
     */
    virtual void finalUpdate() override;

    /* VT+0x78 */
    virtual void setSpinLiftUpActor(dActor_c* actor) override;

public:
    // Instance Methods
    // ^^^^^^

    mVec3_c calcCarryPos(const mVec3_c &offset);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x414 */ u16 mTileNum;
    /* 0x418 */ dPanelObjList_c mPanelObj;
    /* 0x438 */ int mCarryNo;
    /* 0x43C */ mVec3_c mCarryOffset;

private:
    // State IDs
    // ^^^^^^

    sState(daBgLift_c, Carry);
    sState(daBgLift_c, Throw);
};