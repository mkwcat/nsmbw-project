#pragma once

#include "component/c_unary_tree.h"
#include "d_profile/d_profile.h"
#include "framework/f_base.h"

struct dBaseProfile_s : fProfileDat_c {
};

/**
 * An extension of fBase_c with base kind and name strings. All bases should
 * inherit from this class, not from fBase_c.
 */
class dBase_c : public fBase_c
{
    SIZE_ASSERT(0x70);

public:
    // Structors
    // ^^^^^^

    /* 0x8006C420 */
    dBase_c();

public:
    // Virtual Methods
    // ^^^^^^

    /**
     * VT+0x48 0x8006C490
     * Destroys the base.
     */
    virtual ~dBase_c() override;

    /**
     * VT+0x0C 0x8006C540
     * pre method for the create operation.
     */
    virtual PACK_RESULT_e preCreate() override;

    /**
     * VT+0x10 0x8006C570
     * post method for the create operation.
     */
    virtual void postCreate(MAIN_STATE_e state) override;

    /**
     * VT+0x18 0x8006C580
     * pre method for the delete operation.
     */
    virtual PACK_RESULT_e preDelete() override;

    /**
     * VT+0x1C 0x8006C5B0
     * post method for the delete operation.
     */
    virtual void postDelete(MAIN_STATE_e state) override;

    /**
     * VT+0x24 0x8006C5C0
     * pre method for the execute operation.
     */
    virtual PACK_RESULT_e preExecute() override;

    /**
     * VT+0x28 0x8006C600
     * post method for the execute operation.
     */
    virtual void postExecute(MAIN_STATE_e state) override;

    /**
     * VT+0x30 0x8006C610
     * pre method for the draw operation.
     */
    virtual PACK_RESULT_e preDraw() override;

    /**
     * VT+0x34 0x8006C650
     * post method for the draw operation.
     */
    virtual void postDraw(MAIN_STATE_e state) override;

    /**
     * VT+0x4C 0x8006C660
     * Gets a string describing the kind of this base.
     */
    virtual const char* getKindString() const;

public:
    // Instance Methods
    // ^^^^^^

    /**
     * Downcast the base to the specified type. Verifies the object's profile with the specified
     * type's profile, and returns nullptr if the profile doesn't match.
     */
    template <class T>
    constexpr T* DynamicCast()
    {
        return dProf::cast<T>(this);
    }

public:
    // Instance Variables
    // ^^^^^^

    /* 0x64 */ cUnaryTreeMg_c mOwnedTree;

    /**
     * A string describing the kind of this base.
     */
    /* 0x68 */ const char* mpKindString;

    /**
     * A string representing the name of the profile this base belongs to.
     */
    /* 0x6C */ const char* mpNameString;
};
