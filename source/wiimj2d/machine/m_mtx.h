#pragma once

#include "machine/m_angle.h"
#include "machine/m_vec.h"
#include "nw4r/math/vec.h"

/**
 * A 3x4 matrix.
 */
class mMtx_c
{
    SIZE_ASSERT(0x30);

public:
    /**
     * Constructs an empty matrix.
     */
    mMtx_c()
    {
    }

    /**
     * Constructs a matrix with the given components.
     */
    mMtx_c(
      float _00, float _01, float _02, float _03, float _10, float _11, float _12, float _13,
      float _20, float _21, float _22, float _23
    );

    /**
     * Generates a rotation matrix for the X axis with the given angle.
     */
    void XrotS(mAng angle);

    /**
     * Rotates the matrix on the X axis by the given angle.
     */
    void XrotM(mAng angle);

    /**
     * Generates a rotation matrix for the Y axis with the given angle.
     */
    void YrotS(mAng angle);

    /**
     * Rotates the matrix on the Y axis by the given angle.
     */
    void YrotM(mAng angle);

    /**
     * Generates a rotation matrix for the Z axis with the given angle.
     */
    void ZrotS(mAng angle);

    /**
     * Rotates the matrix on the Z axis by the given angle.
     */
    void ZrotM(mAng angle);

    /**
     * Rotates the matrix on the Y, X and Z axes by the given angles.
     */
    void ZXYrotM(mAng xRot, mAng yRot, mAng zRot);

    /**
     * Rotates the matrix on the Z, Y and X axes by the given angles.
     */
    void XYZrotM(mAng xRot, mAng yRot, mAng zRot);

    /**
     * Extracts the rotation vector from the matrix.
     */
    void toRot(mAng3_c& out) const;

    /**
     * Extracts the translation vector from the matrix.
     */
    [[nsmbw(0x8016F270)]]
    void multVecZero(nw4r::math::VEC3& out) const;

    /**
     * Zeroes out the matrix.
     */
    void zero();

    static mMtx_c createTrans(const mVec3_c& v)
    {
        return createTrans(v.x, v.y, v.z);
    }

    static mMtx_c createTrans(float x, float y, float z)
    {
        mMtx_c mtx;
        PSMTXTrans(&mtx.mData, x, y, z);
        return mtx;
    }

    mMtx_c& concat(const mMtx_c& other)
    {
        PSMTXConcat(&mData, &other.mData, &mData);
        return *this;
    }

    mMtx_c& trans(const mVec3_c& v)
    {
        PSMTXTrans(&mData, v.x, v.y, v.z);
        return *this;
    }

    mMtx_c& trans(float x, float y, float z)
    {
        PSMTXTrans(&mData, x, y, z);
        return *this;
    }

    mMtx_c& ZXYrotM(const mAng3_c& ang)
    {
        ZXYrotM(ang.x, ang.y, ang.z);
        return *this;
    }

    /**
     * The matrix components.
     */
    float mData[3][4];

    /**
     * The identity matrix.
     */
    static mMtx_c Identity;
};
