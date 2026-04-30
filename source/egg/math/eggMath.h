#pragma once

namespace EGG
{

template <typename T>
class Math
{
public:
    static T maxNumber()
    {
        // TODO: Generalize to other classes
        // This is low priority since it will always be a float
        return 3.402823466e+38f;
    }

    static T pi()
    {
        return 3.14159265f;
    }

    static T pi_half()
    {
        return pi() / 2.0f;
    }

    static T epsilon()
    {
        return 1.192092896e-07f;
    }

    static T inv(T t)
    {
        return 1 / t;
    }

    static T abs(T t)
    {
        return t > static_cast<T>(0) ? t : -t;
    }

    static T zero()
    {
        return static_cast<T>(0);
    }

    // Assumed to be here (emitted globally at 0x807C9890)
    static T lerp(float t, const T& low, const T& high)
    {
        if (t < 0) {
            return low;
        }

        if (t > 1) {
            return high;
        }

        return low + T(t * (high - low));
    }

    static T sqrt(T);
    static T sin(T);
    static T cos(T);
    static T tan(T);
    static T asin(T);
    static T acos(T);
    static T atan2(T, T);
    static T log10(T);

    static T gcd(T, T);
    static T lcm(T, T);
};

} // namespace EGG
