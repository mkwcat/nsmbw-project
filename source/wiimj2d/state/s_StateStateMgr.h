#pragma once

#include "s_StateID.h"
#include "s_StateInterfaces.h"

/**
 * An implementation of sStateStateMgrIf_c.
 * @tparam T The parent class for this state manager.
 * @tparam Manager The state manager to use.
 * @tparam Method The state method for the main manager to use.
 * @tparam Method The state method for the sub manager to use.
 */
template <class T, template <class, class> class Manager, class Method, class Method2>
class sStateStateMgr_c : public sStateStateMgrIf_c {
public:
    sStateStateMgr_c(
        T& owner, const sStateIDIf_c& initialState = sStateID::null
    )
        : mMgr1(owner, initialState)
        , mMgr2(owner, initialState)
        , mCurrentMgr(&mMgr1) {}

    /**
     * VT+0x0C
     * Initializes the current state.
     */
    virtual void initializeState() { mCurrentMgr->initializeState(); }

    /**
     * VT+0x10
     * Executes the current state.
     */
    virtual void executeState() { mCurrentMgr->executeState(); }

    /**
     * VT+0x14
     * Prepares the current state for termination.
     */
    virtual void finalizeState() {
        if (isSubState()) {
            returnState();
            return;
        }

        mCurrentMgr->finalizeState();
    }

    /**
     * VT+0x18
     * Transitions to a new state ID.
     */
    virtual void changeState(
        const sStateIDIf_c& newStateID
    ) {
        mCurrentMgr->changeState(newStateID);
    }

    /**
     * VT+0x1C
     * Marks the current state to be executed again.
     */
    virtual void refreshState() { mCurrentMgr->refreshState(); }

    /**
     * VT+0x20
     * Returns the state holder.
     */
    virtual sStateIf_c* getState() const { return mCurrentMgr->getState(); }

    /**
     * VT+0x24
     * Returns the next state ID.
     */
    virtual const sStateIDIf_c* getNewStateID() const { return mCurrentMgr->getNewStateID(); }

    /**
     * VT+0x28
     * Returns the current state ID.
     */
    virtual const sStateIDIf_c* getStateID() const { return mCurrentMgr->getStateID(); }

    /**
     * VT+0x2C
     * Returns the previous state ID.
     */
    virtual const sStateIDIf_c* getOldStateID() const { return mCurrentMgr->getOldStateID(); }

    /**
     * VT+0x30
     * Changes to a sub state.
     */
    virtual void changeToSubState(
        const sStateIDIf_c& newStateID
    ) {
        mCurrentMgr = &mMgr2;
        mCurrentMgr->changeState(newStateID);
    }

    /**
     * VT+0x34
     * Finalizes the sub state and changes to the main state.
     */
    virtual void returnState() {
        if (isSubState()) {
            mCurrentMgr->finalizeState();
            mCurrentMgr = &mMgr1;
        }
    }

    /**
     * VT+0x38
     * Returns true if the current state manager is the sub manager.
     */
    virtual bool isSubState() const {
        return mCurrentMgr == static_cast<const sStateMgrIf_c*>(&mMgr2);
    }

    /**
     * VT+0x3C
     * Returns the main state ID.
     */
    virtual const sStateIDIf_c* getMainStateID() const { return mMgr1.getStateID(); }

    // Offsets assume Manager = sFStateMgr_c
    /* 0x04 */ Manager<T, Method>  mMgr1;
    /* 0x40 */ Manager<T, Method2> mMgr2;
    /* 0x7C */ sStateMgrIf_c*      mCurrentMgr;
};
