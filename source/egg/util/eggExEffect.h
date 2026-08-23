#pragma once

#include "egg/math/eggVector.h"
#include <nw4r/ut/Color.h>

namespace EGG {

class ExEffectParam {
    SIZE_ASSERT(0x98);

    /* 0x00 VTABLE 0x80350D48 */

public:
    // Structors
    // ^^^^^^

    /* 0x802DBE60 */
    ExEffectParam();

    /* VT+0x8 0x802DBF10 */
    virtual ~ExEffectParam();

public:
    // Constants and Types
    // ^^^^^^

    enum class EStatus : u32 {
        LIFE_SET                    = 0x1,
        EMIT_RATIO_SET              = 0x2,
        EMIT_INTERVAL_SET           = 0x4,
        EMIT_DIV_SET                = 0x8,
        VEL_RANDOM_SET              = 0x10,
        VEL_POWER_Y_AXIS_SET        = 0x20,
        VEL_POWER_RADIATION_DIR_SET = 0x40,
        VEL_POWER_SPEC_DIR_SET      = 0x80,
        VEL_POWER_SPEC_DIR_ADD_SET  = 0x100,
        VEL_SPEC_DIR_SET            = 0x200,
        VEL_SPEC_DIR_ADD_SET        = 0x400,
        COLOR_SET                   = 0x1000,
        COLOR_REG1_SET              = 0x2000,
        COLOR_REG2_SET              = 0x4000,
        COLOR_REG3_SET              = 0x8000,
        COLOR_REG4_SET              = 0x10000,
        DEFAULT_SIZE_SET            = 0x20000,
        SIZE_SET                    = 0x40000,
        DEFAULT_ROT_SET             = 0x80000,
        ROT_SET                     = 0x100000,
        EMITTER_SIZE_SET            = 0x10000000,
        UNKNOWN_20000000            = 0x20000000,
        LOCAL_SCALE_SET             = 0x40000000,
    };

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0xC 0x802DC7E0 */
    virtual void reset();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x04 */ EStatus         mStatus;
    /* 0x08 */ u32             m0x08; // something to do with status
    /* 0x0C */ u16             mLife;
    /* 0x10 */ f32             mEmitRatio;
    /* 0x14 */ u16             mEmitInterval;
    /* 0x16 */ u16             mEmitDiv;
    /* 0x18 */ s8              mInitVelocityRandom;
    /* 0x1C */ f32             mVelPowerYAxis;
    /* 0x20 */ f32             mVelPowerRadiationDir;
    /* 0x24 */ f32             mVelPowerSpecDir;
    /* 0x28 */ f32             mVelPowerSpecDirAdd;
    /* 0x2C */ Vector3f        mVelSpecDir;
    /* 0x38 */ Vector3f        mVelSpecDirAdd;
    /* 0x44 */ nw4r::ut::Color mColor;
    /* 0x48 */ nw4r::ut::Color mRegisterColors[4];
    /* 0x58 */ Vector2f        mDefaultScale;
    /* 0x60 */ Vector2f        mScale;
    /* 0x68 */ Vector3f        mDefaultRot;
    /* 0x74 */ Vector3f        mRot;
    /* 0x80 */ Vector3f        mEmitterSize;
    /* 0x8C */ Vector3f        mLocalScale;
};

} // namespace EGG
