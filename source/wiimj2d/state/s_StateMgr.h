#pragma once

#include "s_StateInterfaces.h"

template <class T, class Method>
class sFStateMgr_c;

/**
 * An implementation of sStateMgrIf_c.
 * @tparam T The parent class for this state manager.
 * @tparam Method The state method handler to use.
 * @tparam Factory The state factory to use.
 * @tparam Check The state ID checker to use.
 */
template <class T, class Method, template <class> class Factory, class Check>
class sStateMgr_c : public sStateMgrIf_c
{
    friend class sFStateMgr_c<T, Method>;

public:
    sStateMgr_c(T& owner, const sStateIDIf_c& initialState)
      : mFactory(owner)
      , mMethod(mCheck, mFactory, initialState)
    {
    }

    /**
     * VT+0x0C
     * Initializes the current state.
     */
    virtual void initializeState() override
    {
        mMethod.initializeStateMethod();
    }

    /**
     * VT+0x10
     * Executes the current state.
     */
    virtual void executeState() override
    {
        mMethod.executeStateMethod();
    }

    /**
     * VT+0x14
     * Prepares the current state for termination.
     */
    virtual void finalizeState() override
    {
        mMethod.finalizeStateMethod();
    }

    /**
     * VT+0x18
     * Transitions to a new state ID.
     */
    virtual void changeState(const sStateIDIf_c& newState) override
    {
        mMethod.changeStateMethod(newState);
    }

    /**
     * VT+0x1C
     * Marks the current state to be executed again.
     */
    virtual void refreshState() override
    {
        mMethod.refreshStateMethod();
    }

    /**
     * VT+0x20
     * Returns the state holder.
     */
    virtual sStateIf_c* getState() const override
    {
        return mMethod.getState();
    }

    /**
     * VT+0x24
     * Returns the next state ID.
     */
    virtual const sStateIDIf_c* getNewStateID() const override
    {
        return mMethod.getNewStateID();
    }

    /**
     * VT+0x28
     * Returns the current state ID.
     */
    virtual const sStateIDIf_c* getStateID() const override
    {
        return mMethod.getStateID();
    }

    /**
     * VT+0x2C
     * Returns the previous state ID.
     */
    virtual const sStateIDIf_c* getOldStateID() const override
    {
        return mMethod.getOldStateID();
    }

private:
    /* 0x04 */ Check mCheck;
    /* 0x08 */ Factory<T> mFactory;
    /* 0x0C */ Method mMethod;
};
