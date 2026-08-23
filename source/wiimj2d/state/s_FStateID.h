#pragma once

#include "s_StateID.h"

/**
 * An implementation of a state ID for a given class. It adds the ability to call the three state
 * methods on a state owner class.
 * @tparam T The class that this state belongs to.
 */
template <class T>
class sFStateID_c final : public sStateID_c {
public:
    typedef void (T::*stateFunc)();

    /**
     * Constructs a new sFStateID\_c instance.
     *
     * @param name The name of this state ID.
     * @param initialize The initialize method for this state ID.
     * @param execute The execute method for this state ID.
     * @param finalize The finalize method for this state ID.
     */
    constexpr sFStateID_c(
        const char* name, stateFunc initialize, stateFunc execute, stateFunc finalize
    )
        : sStateID_c()
        , mpInitialize(initialize)
        , mpExecute(execute)
        , mpFinalize(finalize) {
        mpName = name;
    }

    /**
     * VT+0x28
     * Calls the initialize method on the owner.
     * @param owner The owner of this state ID.
     */
    virtual void initializeState(
        T& owner
    ) const {
        (owner.*mpInitialize)();
    }

    /**
     * VT+0x2C
     * Calls the execute method on the owner.
     * @param owner The owner of this state ID.
     */
    virtual void executeState(
        T& owner
    ) const {
        (owner.*mpExecute)();
    }

    /**
     * VT+0x30
     * Calls the finalize method on the owner.
     * @param owner The owner of this state ID.
     */
    virtual void finalizeState(
        T& owner
    ) const {
        (owner.*mpFinalize)();
    }

private:
    /**
     * The initialize method for this state ID.
     */
    /* 0x0C */ stateFunc mpInitialize;

    /**
     * The execute method for this state ID.
     */
    /* 0x18 */ stateFunc mpExecute;

    /**
     * The finalize method for this state ID.
     */
    /* 0x24 */ stateFunc mpFinalize;
};
