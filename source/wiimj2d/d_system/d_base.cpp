// d_base.cpp
// NSMBW .text: 0x8006C420 - 0x8006C6D0

#include "d_base.h"

#include "d_profile/d_profile.h"
#include <revolution/os.h>

[[nsmbw(0x8006C420)]]
dBase_c::dBase_c()
{
    mpKindString = getKindString();
    mpNameString = dProf::getName(mProfName);

    OS_REPORT("Create: %s, %08x ->%p\n", mpNameString, mParam, this);
}

/**
 * VT+0x48
 * Destroys the base.
 */
[[nsmbw(0x8006C490)]]
dBase_c::~dBase_c()
{
    mOwnedTree.~cUnaryTreeMg_c();
}

/**
 * VT+0x0C
 * pre method for the create operation.
 */
[[nsmbw(0x8006C540)]]
fBase_c::PACK_RESULT_e dBase_c::preCreate();

/**
 * VT+0x10
 * post method for the create operation.
 */
[[nsmbw(0x8006C570)]]
void dBase_c::postCreate(MAIN_STATE_e state);

/**
 * VT+0x18
 * pre method for the delete operation.
 */
[[nsmbw(0x8006C580)]]
fBase_c::PACK_RESULT_e dBase_c::preDelete();

/**
 * VT+0x1C
 * post method for the delete operation.
 */
[[nsmbw(0x8006C5B0)]]
void dBase_c::postDelete(MAIN_STATE_e state);

/**
 * VT+0x24
 * pre method for the execute operation.
 */
[[nsmbw(0x8006C5C0)]]
fBase_c::PACK_RESULT_e dBase_c::preExecute();

/**
 * VT+0x28
 * post method for the execute operation.
 */
[[nsmbw(0x8006C600)]]
void dBase_c::postExecute(MAIN_STATE_e state);

/**
 * VT+0x30
 * pre method for the draw operation.
 */
[[nsmbw(0x8006C610)]]
fBase_c::PACK_RESULT_e dBase_c::preDraw();

/**
 * VT+0x34
 * post method for the draw operation.
 */
[[nsmbw(0x8006C650)]]
void dBase_c::postDraw(MAIN_STATE_e state);

/**
 * VT+0x4C
 * Gets a string describing the kind of this base.
 */
[[nsmbw(0x8006C660)]]
const char* dBase_c::getKindString() const;
