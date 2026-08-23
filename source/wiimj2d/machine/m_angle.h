#pragma once

/**
 * A one-dimensional short angle vector.
 */
struct mAng {
    SIZE_ASSERT(0x2);

    /**
     * Constructs an empty vector.
     */
    mAng() {}

    /**
     * Constructs a vector from a short pointer.
     */
    mAng(
        const s16* p
    ) {
        mAngle = *p;
    }

    /**
     * Constructs a vector from a short value.
     */
    constexpr mAng(
        s16 x
    ) {
        mAngle = x;
    }

    /**
     * Short cast operator.
     */
    operator s16*() { return &mAngle; }

    /**
     * Const short cast operator.
     */
    operator const s16*() const { return &mAngle; }

    /**
     * Augmented addition operator.
     */
    mAng& operator+=(
        const mAng& v
    ) {
        mAngle += v.mAngle;
        return *this;
    }

    /**
     * Augmented subtraction operator.
     */
    mAng& operator-=(
        const mAng& v
    ) {
        mAngle -= v.mAngle;
        return *this;
    }

    /**
     * Positive operator.
     */
    mAng operator+() const { return *this; }

    /**
     * Negative operator.
     */
    mAng operator-() const { return mAng(-mAngle); }

    /**
     * Addition operator.
     */
    mAng operator+(
        const mAng& v
    ) const {
        return mAng(mAngle + v.mAngle);
    }

    /**
     * Subtraction operator.
     */
    mAng operator-(
        const mAng& v
    ) const {
        return mAng(mAngle - v.mAngle);
    }

    /**
     * Equality operator.
     */
    bool operator==(
        const mAng& v
    ) const {
        return mAngle == v.mAngle;
    }

    /**
     * Inequality operator.
     */
    bool operator!=(
        const mAng& v
    ) const {
        return mAngle != v.mAngle;
    }

    /**
     * Convert float (degrees) to short angle.
     */
    static constexpr s16 fromDegree(
        float degree
    ) {
        if (degree > 180) {
            degree -= 360;
        } else if (degree < -180) {
            degree += 360;
        }

        return s16(degree * 182.04444);
    }

    /**
     * Computes the sine of the angle.
     */
    // float sin() const { return nw4r::math::SinS(mAngle); }

    /**
     * Computes the cosine of the angle.
     */
    // float cos() const { return nw4r::math::CosS(mAngle); }

    /**
     * The rotation.
     */
    /* 0x0 */ s16 mAngle;
};

/**
 * A three-dimensional short angle vector.
 */
class mAng3_c {
    SIZE_ASSERT(0x6);

public:
    /**
     * Constructs an empty vector.
     */
    mAng3_c() {}

    /**
     * Constructs a vector from a short array.
     */
    mAng3_c(
        const s16* p
    ) {
        x = p[0];
        y = p[1];
        z = p[2];
    }

    /**
     * Constructs a vector from three short values.
     */
    mAng3_c(
        s16 fx, s16 fy, s16 fz
    ) {
        x = fx;
        y = fy;
        z = fz;
    }

    /**
     * Short cast operator.
     */
    operator s16*() { return &x; }

    /**
     * Const short cast operator.
     */
    operator const s16*() const { return &x; }

    /**
     * Augmented addition operator.
     */
    mAng3_c& operator+=(
        const mAng3_c& v
    ) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    /**
     * Augmented subtraction operator.
     */
    mAng3_c& operator-=(
        const mAng3_c& v
    ) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    /**
     * Positive operator.
     */
    mAng3_c operator+() const { return *this; }

    /**
     * Negative operator.
     */
    mAng3_c operator-() const { return mAng3_c(-x, -y, -z); }

    /**
     * Addition operator.
     */
    mAng3_c operator+(
        const mAng3_c& v
    ) const {
        return mAng3_c(x + v.x, y + v.y, z + v.z);
    }

    /**
     * Subtraction operator.
     */
    mAng3_c operator-(
        const mAng3_c& v
    ) const {
        return mAng3_c(x - v.x, y - v.y, z - v.z);
    }

    /**
     * Equality operator.
     */
    bool operator==(
        const mAng3_c& v
    ) const {
        return x == v.x && y == v.y && z == v.z;
    }

    /**
     * Inequality operator.
     */
    bool operator!=(
        const mAng3_c& v
    ) const {
        return x != v.x || y != v.y || z != v.z;
    }

    /**
     * The rotation on the X axis.
     */
    /* 0x0 */ s16 x;

    /**
     * The rotation on the Y axis.
     */
    /* 0x2 */ s16 y;

    /**
     * The rotation on the Z axis.
     */
    /* 0x4 */ s16 z;

    /**
     * The null rotation vector.
     */
    static mAng3_c Zero;

    /**
     * The unit rotation vector for the X axis.
     */
    static mAng3_c Ex;

    /**
     * The unit rotation vector for the Y axis.
     */
    static mAng3_c Ey;

    /**
     * The unit rotation vector for the Z axis.
     */
    static mAng3_c Ez;
};
