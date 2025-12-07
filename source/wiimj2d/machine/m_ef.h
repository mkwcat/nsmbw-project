#pragma once

#include "machine/m_angle.h"
#include "machine/m_mtx.h"
#include "machine/m_vec.h"
#include <egg/util/eggEffect.h>

namespace mEf
{

class effect_c : public EGG::Effect
{
    SIZE_ASSERT(0x114);

    /* 0x000 VTABLE 0x80329D68 */

public:
    // Structors
    // ^^^^^^

    effect_c() = default;

    /* VT+0x08 0x80025FE0 */
    virtual ~effect_c();

    /* VT+0x98 0x802D8B30 */
    void reset() override;

    /* VT+0x9C 0x8016CAA0 */
    virtual void createEffect(const char *name, int creatorID);

    /* VT+0xA0 0x8016CBF0 */
    [[address(0x8016CBF0)]]
    virtual bool createEffect(const char *name, unsigned long, const mVec3_c* pos, const mAng3_c* angle, const mVec3_c* scale);

    /* VT+0xA4 0x8016CCA0 */
    virtual bool createEffect(const char *name, unsigned long, const mMtx_c* mtx);

    /* VT+0xA8 0x8016CE80 @unofficial */
    virtual bool vfA8(const char *name, unsigned long, const mVec3_c* pos, const mAng3_c* angle, const mVec3_c* scale, u32, u32);

    /* VT+0xAC 0x8016CD30 @unofficial */
    virtual bool vfAC(const char *name, unsigned long, const mMtx_c* mtx, u32, u32);

    /* VT+0xB0 0x8016CFE0 */
    virtual bool follow(const mVec3_c* pos, const mAng3_c* angle, const mVec3_c* scale);

    /* VT+0xB4 0x8016D090 */
    virtual bool follow(const mMtx_c* mtx);
};

class levelEffect_c : public effect_c
{
    SIZE_ASSERT(0x128);

    /* 0x000 VTABLE 0x80329D68 */

public:
    // Structors
    // ^^^^^^

    // This is normally inlined but is (luckily for us) emitted externally as its own function in
    // d_en_toride_kokoopa.cpp for use with __construct_array, alleviating the requirement for us to
    // recreate the entire vtable.
    [[address(0x800A8AB0)]]
    levelEffect_c();

    // This also is normally inlined
    [[address(0x80025F60)]]
    virtual ~levelEffect_c() override;

public:
    // Instance Variables
    // ^^^^^^

    /* 0x114 */ levelEffect_c* mpPrev;
    /* 0x118 */ levelEffect_c* mpNext;
    /* 0x11C */ bool mSet;
    /* 0x11D */ bool mActive;
    /* 0x120 */ u32 m0x120;
    /* 0x124 */ u32 m0x124;
};

[[address(0x8016C9D0)]]
void createEffect(const char*, unsigned long, const mVec3_c*, const mAng3_c*, const mVec3_c*);

} // namespace mEf
