#pragma once

#include "d_static/d_allocator.h"
#include "d_static/d_wm/d_wm_actor.h"
#include "machine/m_3d_smdl.h"

class dWmSVMdl_c;

class dWmDemoActor_c : public dWmActor_c {
    SIZE_ASSERT(0x184);
    VTABLE(0x060, fBase_c, 0x8031C170);

public:
    // Structors
    // ^^^^^^

    /* 0x800F60E0 */
    dWmDemoActor_c();

    /**
     * VT+0x48 0x800F6F40 (weak)
     * Destroys the base.
     */
    virtual ~dWmDemoActor_c() override;

public:
    // Virtual Methods
    // ^^^^^^

    /**
     * VT+0x08 0x800F6F30
     * do method for the create operation.
     */
    virtual PACK_RESULT_e create() override;

    /**
     * VT+0x14 0x800F6F10
     * do method for the delete operation. This method was renamed due to conflict with the delete
     * C++ keyword.
     */
    virtual PACK_RESULT_e doDelete() override;

    /**
     * VT+0x20
     * do method for the execute operation.
     */
    virtual PACK_RESULT_e execute() override = 0;

    /**
     * VT+0x2C 0x800F6F20
     * do method for the draw operation.
     */
    virtual PACK_RESULT_e draw() override;

    /* VT+0x60 0x800F61C0 */
    virtual void VT_0x60();

    /* VT+0x64 0x800F6EF0, 0x808C82F0 */
    virtual bool checkCutEnd();

    /* VT+0x68 0x800F61E0, 0x808C82D0 */
    virtual void setCutEnd();

    /* VT+0x6C 0x800F6EE0, 0x808C82E0 */
    virtual void clearCutEnd();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800F6820 */
    void CreateShadowModel(const char* param1, const char* param2, const char* param3, bool param4);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x138 */ bool             m0x138;
    /* 0x139 */ bool             mIsCutEnd;
    /* 0x13C */ dHeapAllocator_c mAllocator;
    /* 0x158 */ m3d::smdl_c      mModel;
    /* 0x164 */ dWmSVMdl_c*      mSvMdl;
    /* 0x168 */ mVec3_c          mTargetPos;
    /* 0x174 */ float            mScaleCurr;
    /* 0x178 */ float            mScaleDelta;
    /* 0x17C */ float            mScaleTarget;
    /* 0x180 */ int              mScaleDelay;
};
