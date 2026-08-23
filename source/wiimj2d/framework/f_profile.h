#pragma once

class fBase_c;

using fProfName = u16;

/**
 * @unofficial
 * A set of basic information needed to construct a generic base.
 */
class fProfileDat_c {
public:
    // Instance Variables
    // ^^^^^^

    /**
     * The constructor function.
     */
    fBase_c* (*mClassInit)();

    /**
     * The execution priority of the base. Lower values mean higher priority.
     */
    u16 mExecuteOrder;

    /**
     * The draw priority of the base. Lower values mean higher priority.
     */
    u16 mDrawOrder;

public:
    // Static Variables
    // ^^^^^^

    /**
     * 0x8042A698
     * The profile data table.
     */
    static fProfileDat_c** sProfileList;
};
