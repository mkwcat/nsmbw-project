#pragma once

#include <nw4r/math/vec.h>

namespace EGG {

class Frustum {
#ifndef CLANGD
    SIZE_ASSERT(0x3C);
#endif

    /* 0x38 VTABLE */

public:
    // Constants and Types
    // ^^^^^^

    enum class ProjectionType {
        PROJ_ORTHO,
        PROJ_PERSP,
    };

public:
    // Instance Methods
    // ^^^^^^

    [[nsmbw(0x802C6DD0)]]
    void ResetOrthographic(f32 top, f32 bottom, f32 left, f32 right, f32, f32);

    ProjectionType GetProjectionType() const { return mProjType; }

    void SetProjectionType(
        ProjectionType type
    ) {
        mProjType = type;
    }

    void SetScale(
        const nw4r::math::VEC3& scale
    ) {
        mScale = scale;
    }

private:
    // Instance Variables
    // ^^^^^^

    /* 0x00 */ ProjectionType mProjType;

    FILL(0x04, 0x28);

    /* 0x28 */ nw4r::math::VEC3 mScale;
    /* 0x34 */ mutable u16      mFlags;

public:
    // Structors
    // ^^^^^^

    /* VT+0x08 */
    virtual ~Frustum() {}

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x0C */
    virtual void SetProjectionGX() const;
};

} // namespace EGG
