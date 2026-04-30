#pragma once

#include "egg/math/eggMath.h"
#include <nw4r/math/vec.h>
#include <revolution/kpad.h>

namespace EGG
{

struct Vector3f : public nw4r::math::VEC3 {
    SIZE_ASSERT(0xC);

    Vector3f()
      : nw4r::math::VEC3()
    {
    }

    Vector3f(f32 fx, f32 fy, f32 fz)
      : VEC3(fx, fy, fz)
    {
    }

    Vector3f(Vec vec)
      : VEC3(vec.x, vec.y, vec.z)
    {
    }

    f32& operator()(int i)
    {
        return (&x)[i];
    }

    Vector3f operator*(f32 f) const
    {
        return Vector3f(x * f, y * f, z * f);
    }

    friend Vector3f operator*(f32 f, const Vector3f& v)
    {
        return v.operator*(f);
    }

    Vector3f operator+(const Vector3f& v)
    {
        return Vector3f(x + v.x, y + v.y, z + v.z);
    }

    Vector3f& operator+=(const Vector3f& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vector3f operator-() const
    {
        f32 z = this->z;
        f32 y = this->y;
        f32 x = this->x;
        return Vector3f(-x, -y, -z);
    }

    Vector3f operator-(const Vector3f& v)
    {
        return Vector3f(x - v.x, y - v.y, z - v.z);
    }

    Vector3f& operator-=(const Vector3f& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    Vector3f& operator*=(f32 f)
    {
        multScalar(f);
        return *this;
    }

    Vector3f operator/(f32 f) const
    {
        return Vector3f(x / f, y / f, z / f);
    }

    Vector3f& operator/=(f32 f)
    {
        divScalar(f);
        return *this;
    }

    bool operator!=(const Vector3f& v)
    {
        return x != v.x || y != v.y || z != v.z;
    }

    void multScalar(f32 f)
    {
        x *= f;
        y *= f;
        z *= f;
    }

    void divScalar(f32 f)
    {
        multScalar(1.0f / f);
    }

    f32 dot(const Vector3f& v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }

    Vector3f cross(const Vector3f& b) const
    {
        f32 _x = (y * b.z) - (z * b.y);
        f32 _y = (z * b.x) - (x * b.z);
        f32 _z = (x * b.y) - (y * b.x);
        return Vector3f(_x, _y, _z);
    }

    f32 squaredLength() const
    {
        return (x * x + y * y + z * z);
    }

    f32 length() const
    {
        return Math<f32>::sqrt(squaredLength());
    }

    void set(f32 fx, f32 fy, f32 fz)
    {
        x = fx;
        y = fy;
        z = fz;
    }

    f32 normalise();
    f32 setLength(const Vector3f& src, f32 len);
    f32 setLength(f32 len);

    static const Vector3f zero;
    static const Vector3f ex;
    static const Vector3f ey;
    static const Vector3f ez;
};

class Vector2f
{
public:
    SIZE_ASSERT(0x8);

    constexpr Vector2f()
    {
    }

    constexpr Vector2f(f32 fx, f32 fy)
      : x(fx)
      , y(fy)
    {
    }

    constexpr Vector2f(Vec2 vec)
      : x(vec.x)
      , y(vec.y)
    {
    }

    constexpr ~Vector2f()
    {
    }

public:
    static const Vector2f zero;
    static const Vector2f ex;
    static const Vector2f ey;

    constexpr Vector2f operator-(const Vector2f& v)
    {
        return Vector2f(x - v.x, y - v.y);
    }

    constexpr f32 squaredLength() const
    {
        return (x * x + y * y);
    }

    float x, y;
};

} // namespace EGG
