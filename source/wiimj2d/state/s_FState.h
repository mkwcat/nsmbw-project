#pragma once

#include "s_FStateID.h"
#include "s_StateInterfaces.h"

/**
 * A state holder for a given class.
 * @tparam T The class that this state belongs to.
 */
template <class T>
class sFState_c : public sStateIf_c {
public:
    sFState_c(
        T& owner
    )
        : mpOwner(owner)
        , mpID(nullptr) {}

    enum STATE_ACTION_e {
        INITIALIZE,
        EXECUTE,
        FINALIZE,
    };

    /**
     * Performs a state action.
     * @param action The action to perform.
     */
    void performAction(
        STATE_ACTION_e action
    ) {
        if (action == FINALIZE) {
            mpID->finalizeState(mpOwner);
        } else if (action == EXECUTE) {
            mpID->executeState(mpOwner);
        } else if (action == INITIALIZE) {
            mpID->initializeState(mpOwner);
        }
    }

    virtual void initialize() { performAction(INITIALIZE); }

    virtual void execute() { performAction(EXECUTE); }

    virtual void finalize() { performAction(FINALIZE); }

    void setID(
        const sFStateID_c<T>* id
    ) {
        mpID = id;
    }

private:
    /**
     * The owner of this state.
     */
    /* 0x04 */ T&                    mpOwner;
    /* 0x08 */ const sFStateID_c<T>* mpID;
};
