#pragma once

/**
 * The interface for state IDs. A state ID is made up of a name string and a unique number, where 0
 * denotes a null state. Null states do not have any corresponding behaviour. They can be used, for
 * example, if a state holder needs to be initialized but the initial state ID is not known yet.
 */
class sStateIDIf_c {
public:
    constexpr sStateIDIf_c() {}

    /* VT+0x08 */
    virtual ~sStateIDIf_c() {}

    /**
     * VT+0x0C
     * Returns whether this is a null state.
     */
    virtual bool isNull() const MACINTOSH_ABSTRACT;

    /**
     * VT+0x10
     * Returns whether both states have the same number.
     */
    virtual bool isEqual(const sStateIDIf_c& other) const MACINTOSH_ABSTRACT;

    /**
     * VT+0x14
     * Overloaded equality operator, using ::isEqual.
     */
    virtual bool operator==(const sStateIDIf_c& other) const MACINTOSH_ABSTRACT;

    /**
     * VT+0x18
     * Overloaded inequality operator, using ::isEqual.
     */
    virtual bool operator!=(const sStateIDIf_c& other) const MACINTOSH_ABSTRACT;

    /**
     * VT+0x1C
     * Returns whether this state ID is called @p name.
     */
    virtual bool isSameName(const char* name) const MACINTOSH_ABSTRACT;

    /**
     * VT+0x20
     * Returns the name of this state ID.
     */
    virtual const char* name() const MACINTOSH_ABSTRACT;

    /**
     * VT+0x24
     * Returns the number of this state ID.
     */
    virtual unsigned int number() const MACINTOSH_ABSTRACT;
};

/**
 * The interface for a state holder.
 * A state holder is linked to a state ID and can execute its corresponding behaviour.
 */
class sStateIf_c {
public:
    constexpr sStateIf_c() {}

    /* VT+0x08 */
    virtual ~sStateIf_c() {}

    /**
     * VT+0x0C
     * Initializes the state.
     */
    virtual void initialize() MACINTOSH_ABSTRACT;

    /**
     * VT+0x10
     * Executes the state.
     */
    virtual void execute() MACINTOSH_ABSTRACT;

    /**
     * VT+0x14
     * Prepares the state for termination.
     */
    virtual void finalize() MACINTOSH_ABSTRACT;
};

/**
 * The interface for state factories.
 * A state factory produces a state holder from a given state ID.
 */
class sStateFctIf_c {
public:
    constexpr sStateFctIf_c() {}

    /* VT+0x08 */
    virtual ~sStateFctIf_c() {}

    /**
     * VT+0x0C
     * Returns a new state with a given state ID.
     */
    virtual sStateIf_c* build(const sStateIDIf_c& id) MACINTOSH_ABSTRACT;

    /**
     * VT+0x10
     * Clears out the pointer to a state.
     */
    virtual void dispose(sStateIf_c*& id) MACINTOSH_ABSTRACT;
};

/**
 * The interface for state ID checkers. This class is not really used, but it seems to be intended
 * for testing if a state is "normal", most likely a debug leftover.
 */
class sStateIDChkIf_c {
public:
    constexpr sStateIDChkIf_c() {}

    /* VT+0x08 */
    virtual ~sStateIDChkIf_c() {}

    /**
     * VT+0x0C
     * Returns whether a state ID is normal.
     */
    virtual bool isNormalID(const sStateIDIf_c& id) const MACINTOSH_ABSTRACT;
};

/**
 * A default implementation of a state ID checker.
 * ::isNormalID always returns true.
 */
class sStateIDChk_c : public sStateIDChkIf_c {
public:
    constexpr sStateIDChk_c() {}

    /**
     * VT+0x0C
     * Returns whether a state ID is normal. Always returns true.
     */
    virtual bool isNormalID(
        const sStateIDIf_c&
    ) const override {
        return true;
    }
};

/**
 * The interface for state managers.
 * A state manager handles execution of and transitioning between state IDs.
 */
class sStateMgrIf_c {
public:
    constexpr sStateMgrIf_c() {}

    /* VT+0x08 */
    virtual ~sStateMgrIf_c() {}

    /**
     * VT+0x0C
     * Initializes the current state.
     */
    virtual void initializeState() MACINTOSH_ABSTRACT;

    /**
     * VT+0x10
     * Executes the current state.
     */
    virtual void executeState() MACINTOSH_ABSTRACT;

    /**
     * VT+0x14
     * Prepares the current state for termination.
     */
    virtual void finalizeState() MACINTOSH_ABSTRACT;

    /**
     * VT+0x18
     * Transitions to a new state ID.
     */
    virtual void changeState(const sStateIDIf_c& newStateID) MACINTOSH_ABSTRACT;

    /**
     * VT+0x1C
     * Marks the current state to be executed again.
     */
    virtual void refreshState() MACINTOSH_ABSTRACT;

    /**
     * VT+0x20
     * Returns the state holder.
     */
    virtual sStateIf_c* getState() const MACINTOSH_ABSTRACT;

    /**
     * VT+0x24
     * Returns the next state ID.
     */
    virtual const sStateIDIf_c* getNewStateID() const MACINTOSH_ABSTRACT;

    /**
     * VT+0x28
     * Returns the current state ID.
     */
    virtual const sStateIDIf_c* getStateID() const MACINTOSH_ABSTRACT;

    /**
     * VT+0x2C
     * Returns the previous state ID.
     */
    virtual const sStateIDIf_c* getOldStateID() const MACINTOSH_ABSTRACT;
};

/**
 * An interface for two state managers.
 */
class sStateStateMgrIf_c : public sStateMgrIf_c {
public:
    constexpr sStateStateMgrIf_c() {}

    /* VT+0x08 */
    virtual ~sStateStateMgrIf_c() {}

    /**
     * VT+0x30
     * Changes to a sub state.
     */
    virtual void changeToSubState(const sStateIDIf_c& newStateID) MACINTOSH_ABSTRACT;

    /**
     * VT+0x34
     * Finalizes the sub state and changes to the main state.
     */
    virtual void returnState() MACINTOSH_ABSTRACT;

    /**
     * VT+0x38
     * Returns true if the current state manager is the sub manager.
     */
    virtual bool isSubState() const MACINTOSH_ABSTRACT;

    /**
     * VT+0x3C
     * Returns the main state ID.
     */
    virtual const sStateIDIf_c* getMainStateID() const MACINTOSH_ABSTRACT;
};
