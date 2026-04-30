#pragma once

#include "s_FState.h"
#include "s_StateInterfaces.h"

/**
 * A state factory for a given class.
 * @tparam T The class that this state belongs to.
 */
template <class T>
class sFStateFct_c : public sStateFctIf_c
{
public:
    sFStateFct_c(T& owner)
      : mState(owner)
    {
    }

    virtual sStateIf_c* build(const sStateIDIf_c& id)
    {
        if (!id.isNull()) {
            mState.setID(static_cast<const sFStateID_c<T>*>(&id));
            return &mState;
        }
        return nullptr;
    }

    virtual void dispose(sStateIf_c*& id)
    {
        id = nullptr;
    }

private:
    /* 0x4 */ sFState_c<T> mState;
};
