#pragma once

#include "machine/m_angle.h"
#include <egg/math/eggMath.h>
#include <nw4r/math/vec.h>

/**
 * A two-dimensional floating point vector.
 */
class mVec2_c : public nw4r::math::VEC2
{
    SIZE_ASSERT(0x8);

public:
    /**
     * Constructs an empty vector.
     */
    constexpr mVec2_c()
    {
    }

    /**
     * Constructs a vector from a float array.
     */
    constexpr mVec2_c(const f32* p)
    {
        x = p[0];
        y = p[1];
    }

    /**
     * Constructs a vector from two floating point values.
     */
    constexpr mVec2_c(f32 fx, f32 fy)
    {
        x = fx;
        y = fy;
    }

    constexpr ~mVec2_c()
    {
    }

    void init(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    /**
     * Augmented addition operator.
     */
    mVec2_c& operator+=(const mVec2_c& v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }

    /**
     * Augmented subtraction operator.
     */
    mVec2_c& operator-=(const mVec2_c& v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    /**
     * Augmented scalar product operator.
     */
    mVec2_c& operator*=(f32 f)
    {
        x *= f;
        y *= f;
        return *this;
    }

    /**
     * Augmented scalar division operator.
     */
    mVec2_c& operator/=(f32 f)
    {
        return operator*=(1.0f / f);
    }

    /**
     * Positive operator.
     */
    mVec2_c operator+() const
    {
        return *this;
    }

    /**
     * Negative operator.
     */
    mVec2_c operator-() const
    {
        return mVec2_c(-x, -y);
    }

    /**
     * Addition operator.
     */
    mVec2_c operator+(const mVec2_c& v) const
    {
        return mVec2_c(x + v.x, y + v.y);
    }

    /**
     * Subtraction operator.
     */
    mVec2_c operator-(const mVec2_c& v) const
    {
        return mVec2_c(x - v.x, y - v.y);
    }

    /**
     * Scalar product operator.
     */
    mVec2_c operator*(f32 f) const
    {
        return mVec2_c(f * x, f * y);
    }

    /**
     * Scalar division operator.
     */
    mVec2_c operator/(f32 f) const
    {
        f32 r = 1.0f / f;
        return operator*(r);
    }

    /**
     * Equality operator.
     */
    bool operator==(const mVec2_c& v) const
    {
        return x == v.x && y == v.y;
    }

    /**
     * Inequality operator.
     */
    bool operator!=(const mVec2_c& v) const
    {
        return x != v.x || y != v.y;
    }

    static float distance(mVec2_c& v1, mVec2_c& v2)
    {
        v1 -= v2;
        return v1.getLength();
    }

    float getLength() const
    {
        return EGG::Math<float>::sqrt(x * x + y * y);
    }

    // float normalise() const
    // {
    //     return ((EGG::Vector2f*) this)->normalise();
    // }

    void set(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
};

/**
 * A three-dimensional floating point vector.
 */
class mVec3_c : public nw4r::math::VEC3
{
    SIZE_ASSERT(0xC);

public:
    /**
     * Constructs an empty vector.
     */
    constexpr mVec3_c()
    {
        if consteval {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }
    }

    /**
     * Constructs a vector from a float array.
     */
    constexpr mVec3_c(const f32* p)
    {
        x = p[0];
        y = p[1];
        z = p[2];
    }

    /**
     * Constructs a vector from three floating point values.
     */
    constexpr mVec3_c(f32 fx, f32 fy, f32 fz)
    {
        x = fx;
        y = fy;
        z = fz;
    }

    /**
     * Augmented addition operator.
     */
    constexpr mVec3_c& operator+=(const mVec3_c& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    /**
     * Augmented subtraction operator.
     */
    constexpr mVec3_c& operator-=(const mVec3_c& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    /**
     * Augmented scalar product operator.
     */
    constexpr mVec3_c& operator*=(f32 f)
    {
        x *= f;
        y *= f;
        z *= f;
        return *this;
    }

    /**
     * Augmented scalar division operator.
     */
    constexpr mVec3_c& operator/=(f32 f)
    {
        return operator*=(1.0f / f);
    }

    /**
     * Positive operator.
     */
    constexpr mVec3_c operator+() const
    {
        return *this;
    }

    /**
     * Negative operator.
     */
    constexpr mVec3_c operator-() const
    {
        return mVec3_c(-x, -y, -z);
    }

    /**
     * Addition operator.
     */
    constexpr mVec3_c operator+(const mVec3_c& v) const
    {
        return mVec3_c(x + v.x, y + v.y, z + v.z);
    }

    /**
     * Subtraction operator.
     */
    constexpr mVec3_c operator-(const mVec3_c& v) const
    {
        return mVec3_c(x - v.x, y - v.y, z - v.z);
    }

    /**
     * Scalar product operator.
     */
    constexpr mVec3_c operator*(f32 f) const
    {
        return mVec3_c(f * x, f * y, f * z);
    }

    /**
     * Scalar division operator.
     */
    constexpr mVec3_c operator/(f32 f) const
    {
        f32 r = 1.0f / f;
        return operator*(r);
    }

    /**
     * Equality operator.
     */
    constexpr bool operator==(const mVec3_c& v) const
    {
        return x == v.x && y == v.y && z == v.z;
    }

    /**
     * Inequality operator.
     */
    constexpr bool operator!=(const mVec3_c& v) const
    {
        return x != v.x || y != v.y || z != v.z;
    }

    static float distance(const mVec3_c& v1, const mVec3_c& v2)
    {
        return EGG::Math<float>::sqrt(VECSquareDistance(&v1, &v2));
    }

    void set(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    /**
     * 0x80170AC0
     * Normalizes the vector.
     * @return The vector's magnitude.
     */
    float normalize();

    /**
     * 0x80170B40
     * Normalizes the vector.
     * @return If the operation was successful.
     */
    bool normalizeRS();

    /**
     * 0x80170BD0
     * Rotates the vector on the X axis by the given angle.
     */
    void rotX(mAng angle);

    /**
     * 0x80170C80
     * Rotates the vector on the Y axis by the given angle.
     */
    void rotY(mAng angle);

    /**
     * 0x803780C8
     * The null vector.
     */
    static mVec3_c Zero;

    /**
     * 0x803780D4
     * The unit vector for the X axis.
     */
    static mVec3_c Ex;

    /**
     * 0x803780E0
     * The unit vector for the Y axis.
     */
    static mVec3_c Ey;

    /**
     * 0x803780EC
     * The unit vector for the Z axis.
     */
    static mVec3_c Ez;
};
