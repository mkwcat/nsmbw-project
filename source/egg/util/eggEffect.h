#pragma once

#include "egg/math/eggMatrix.h"
#include "egg/math/eggVector.h"
#include "egg/prim/eggBitFlag.h"
#include "eggExEffect.h"
#include "nw4r/math/mtx.h"
#include "nw4r/math/vec.h"
#include "revolution/gx/GXStruct.h"
#include <nw4r/ef/Handle.h>

namespace EGG
{

class Effect
{
    SIZE_ASSERT(0x114);

    /* 0x000 VTABLE 0x80350AF8 */

public:
    // Structors
    // ^^^^^^

    /* 0x802D7D90 */
    Effect();

    /* VT+0x08 0x802D7E10 */
    virtual ~Effect();

public:
    // Constants and Types
    // ^^^^^^

    // TODO
    enum class ERecursive {
        RECURSIVE_3 = 3,
    };

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x0C 0x802D7E70 */
    virtual void create();

    /* VT+0x10 0x802D7F40 */
    virtual void fade();

    /* VT+0x14 0x802D7FD0 */
    virtual void followFade();

    /* VT+0x18 0x802D8040 */
    virtual void kill();

    /* VT+0x1C 0x802D80E0 */
    virtual void setDisableCalc(bool);

    /* VT+0x20 0x802D8180 */
    virtual void setDisableDraw(bool);

    /* VT+0x24 0x802D8220 */
    virtual void setDisableCalcDraw(bool);

    /* VT+0x28 0x802D82F0 */
    virtual void setLife(u16, ERecursive);

    /* VT+0x2C 0x802D8300 */
    virtual void setEmitRatio(f32, ERecursive);

    /* VT+0x30 0x802D8310 */
    virtual void setEmitInterval(u16, ERecursive);

    /* VT+0x34 0x802D8320 */
    virtual void setEmitEmitDiv(u16, ERecursive);

    /* VT+0x38 0x802D8330 */
    virtual void setInitVelocityRandom(s8, ERecursive);

    /* VT+0x3C 0x802D8340 */
    virtual void setPowerYAxis(f32, ERecursive);

    /* VT+0x40 0x802D8350 */
    virtual void setPowerRadiationDir(f32, ERecursive);

    /* VT+0x44 0x802D8360 */
    virtual void setPowerSpecDir(f32, ERecursive);

    /* VT+0x48 0x802D8370 */
    virtual void setPowerSpecDirAdd(f32, ERecursive);

    /* VT+0x4C 0x802D8380 */
    virtual void setSpecDir(const nw4r::math::VEC3&, ERecursive);

    /* VT+0x50 0x802D8390 */
    virtual void setSpecDirAdd(const nw4r::math::VEC3&, ERecursive);

    /* VT+0x54 0x802D83A0 */
    virtual void setVelocity(const nw4r::math::VEC3&);

    /* VT+0x58 0x802D8430 */
    virtual void setColor(u8 r, u8 g, u8 b, u8 a, ERecursive);

    /* VT+0x5C 0x802D8470 */
    virtual void setRegisterColor(const GXColor& regColor0, const GXColor& regColor1, u8 regIdx, ERecursive);

    /* VT+0x60 0x802D84B0 */
    virtual void setRegisterAlpha(u8 regAlpha0, u8 regAlpha1, u8 regIdx, ERecursive);

    /* VT+0x64 0x802D84C0 */
    virtual void setDefaultParticleSize(nw4r::math::VEC2&, ERecursive);

    /* VT+0x68 0x802D84D0 */
    virtual void setParticleScale(nw4r::math::VEC2&, ERecursive);

    /* VT+0x6C 0x802D84E0 */
    virtual void setDefaultParticleRotate(nw4r::math::VEC3&, ERecursive);

    /* VT+0x70 0x802D84F0 */
    virtual void setParticleRotate(nw4r::math::VEC3&, ERecursive);

    /* VT+0x74 0x802D8500 */
    virtual void setEmitterSize(const nw4r::math::VEC3&, bool, ERecursive);

    /* VT+0x78 0x802D8510 */
    virtual void setLocalScale(const nw4r::math::VEC3&, ERecursive);

    /* VT+0x7C 0x802D8520 */
    virtual void setDynamicsScale(const nw4r::math::VEC3&, const nw4r::math::VEC2*);

    /* VT+0x80 0x802D8620 */
    virtual void setScale(f32);

    /* VT+0x84 0x802D8640 */
    virtual void setScale(const nw4r::math::VEC3&);

    /* VT+0x88 0x802D8670 */
    virtual void setPos(const nw4r::math::VEC3&);

    /* VT+0x8C 0x802D86A0 */
    virtual void setMtx(const nw4r::math::MTX34&);

    /* VT+0x90 0x802D86C0 */
    virtual void setPtclAnim(int, bool setStart);

    /* VT+0x94 0x802D88B0 */
    virtual void update();

    /* VT+0x98 0x802D8B30 */
    virtual void reset();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x004 */ char name[32];
    /* 0x024 */ u32 mCreator;
    /* 0x028 */ TBitFlag<u32> mFlags;
    /* 0x02C */ Vector3f mScale;
    /* 0x038 */ Vector3f mTranslate;
    /* 0x044 */ Matrix34f mMatrix;
    /* 0x074 */ nw4r::ef::HandleBase mHandle;
    /* 0x07C */ ExEffectParam mExParam;
};

} // namespace EGG
