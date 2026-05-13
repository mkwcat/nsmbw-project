#pragma once

EXTERN_C_START

#define NAN (0.0 / 0.0)

/**
 * Returns the absolute value of x.
 */
inline double fabs(double x)
{
    return __builtin_fabs(x);
}

/**
 * Returns the absolute value of x.
 */
inline float fabsf(float x)
{
    return __builtin_fabs(x);
}

/* 0x802E8B58 */
double sqrt(double x);

inline float sqrtf(float x)
{
    return sqrt(x);
}

EXTERN_C_END
