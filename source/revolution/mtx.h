#pragma once

EXTERN_C_START

/**
 * A 3x4 matrix.
 */
typedef float Mtx[3][4];

/**
 * A 4x4 matrix.
 */
typedef float Mtx44[4][4];

struct Vec2 {
    float x;
    float y;
};

struct Vec {
    float x;
    float y;
    float z;
};

void PSMTXIdentity(Mtx* mtx);

[[nsmbw(0x801C0680)]]
void PSMTXConcat(const Mtx* a, const Mtx* b, Mtx* out);
void PSMTXCopy(const Mtx* src, Mtx* dst);

[[nsmbw(0x801C0D10)]]
void PSMTXTrans(Mtx* mtx, float x, float y, float z);
void PSMTXScale(Mtx* mtx, float x, float y, float z);

void C_MTXFrustum(Mtx44*, float, float, float, float, float, float);
void C_MTXPerspective(Mtx44*, float, float, float, float);
void C_MTXOrtho(Mtx44*, float, float, float, float, float, float);

void PSVECAdd(const Vec* a, const Vec* b, Vec* sum);
void PSVECSubtract(const Vec* a, const Vec* b, Vec* diff);
void PSVECScale(const Vec* in, Vec* out, f32 scale);
void PSVECNormalize(const Vec* in, Vec* out);
f32 PSVECMag(const Vec* v);
f32 PSVECDotProduct(const Vec* a, const Vec* b);
void PSVECCrossProduct(const Vec* a, const Vec* b, Vec* prod);
f32 PSVECSquareDistance(const Vec* a, const Vec* b);
void C_VECHalfAngle(const Vec* a, const Vec* b, Vec* half);

/**
 * Sets the given matrix to the identity matrix.
 */
#define MTXIdentity(mtx) PSMTXIdentity(mtx)

/**
 * Concatenates two matrices.
 */
#define MTXConcat(a, b, out) PSMTXConcat(a, b, out)

/**
 * Copies a matrix.
 */
#define MTXCopy(src, dst) PSMTXCopy(src, dst)

/**
 * Sets a translation matrix with the given components.
 */
#define MTXTrans(mtx, x, y, z) PSMTXTrans(mtx, x, y, z)

/**
 * Sets a scaling matrix with the given components.
 */
#define MTXScale(mtx, x, y, z) PSMTXScale(mtx, x, y, z)

#define VECSquareDistance PSVECSquareDistance

EXTERN_C_END
