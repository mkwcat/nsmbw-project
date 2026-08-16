#pragma once

#include "d_system/d_mj2d_game.h"

class dPyAnm_HIO_c {
public:
    u8    mID;
    float mRate;
    float mBlendDuration;
};

class dPyAnmMain_HIO_c {
public:
    dPyAnm_HIO_c mAnm[177];
};

/* @unofficial */
struct dPyModelData_s {
    float a, b, c, d;
};

class dPyModel_HIO_c {
public:
    float mData[5];

    dPyModelData_s getModelData(
        u8 index
    ) {
        return modelData[index];
    }

    dPyModelData_s modelData[3];
};

class dYoshiModel_HIO_c {
public:
    float mData[4];
};

class dPyMdlBase_HIO_c {
    SIZE_ASSERT(0x970);

public:
    u8 changeHioType(u8 hioType);

    /* @unofficial */
    float getValue(dPyModelData_s model, u8 powerup);

    float getValue(
        int playerType, int idx, int powerup
    ) {
        dPyModelData_s modelData = mPyModel[changeHioType(playerType)].getModelData(idx);
        return getValue(modelData, powerup);
    }

    enum ScaleIndex_e {};

    float get_08(
        ScaleIndex_e index
    ) {
        return m0x08[index];
    }

public:
    // Instance Variables
    // ^^^^^^

    /* 0x000 */ u8                mPad[0x8];
    /* 0x008 */ float             m0x08[8];
    /* 0x028 */ dPyAnmMain_HIO_c  mPyAnm;
    /* 0x874 */ dPyModel_HIO_c    mPyModel[3];
    /* 0x940 */ dYoshiModel_HIO_c mYoshiModel[3];
};

/* @unofficial */
struct sPowerChangeSpeedData {
    float mDefaultAccel;
    float mNoInputAccel;
    float mTurnNoInputAccel;
    float mTurnAccel;
    float mVerySlowAccel;
    float mSlowAccel;
    float mRunSlowAccel;
    float mMediumAccel;
    float mFastAccel;
};

/* @unofficial */
struct sSpeedData {
    float                 mLowSpeed, mMediumSpeed, mHighSpeed;
    sPowerChangeSpeedData mPowerChangeNormal;
    sPowerChangeSpeedData mPowerChangeIce;
    sPowerChangeSpeedData mPowerChangeLowSlip;
};

class dAcPy_HIO_Speed_c {
public:
    dAcPy_HIO_Speed_c();
    ~dAcPy_HIO_Speed_c();

    sSpeedData mDataNormal;
    sSpeedData mDataStar;
};

/* +++ */
class dPyStatic_HIO_c {
public:
    // Instance Variables
    // ^^^^^^
    float mDokanUDOffsetYoshiSmall, mDokanUDOffsetYoshiBig, mDokanUDOffsetYoshiMini;
    float mDokanUDOffsetSmall, mDokanUDOffsetMini;
    float mDokanUDAdjustBig, mDokanUDAdjustPropeller;

public:
    static const dPyStatic_HIO_c& get(
        PLAYER_TYPE_e pt
    ) {
        // TODO: Make this configurable via JSON
        static constexpr const dPyStatic_HIO_c l_MARIO = {
            .mDokanUDOffsetYoshiSmall = 34.0f,
            .mDokanUDOffsetYoshiBig   = 40.0f,
            .mDokanUDOffsetYoshiMini  = 30.0f,
            .mDokanUDOffsetSmall      = 20.0f,
            .mDokanUDOffsetMini       = 12.0f,
            .mDokanUDAdjustBig        = 0.0f,
            .mDokanUDAdjustPropeller  = 8.0f,
        };

        static constexpr const dPyStatic_HIO_c l_LUIGI = {
            .mDokanUDOffsetYoshiSmall = 36.0f,
            .mDokanUDOffsetYoshiBig   = 42.0f,
            .mDokanUDOffsetYoshiMini  = 30.0f,
            .mDokanUDOffsetSmall      = 20.0f,
            .mDokanUDOffsetMini       = 12.0f,
            .mDokanUDAdjustBig        = 0.0f,
            .mDokanUDAdjustPropeller  = 8.0f,
        };

        static constexpr const dPyStatic_HIO_c l_YELLOW_TOAD = {
            .mDokanUDOffsetYoshiSmall = 38.0f,
            .mDokanUDOffsetYoshiBig   = 44.0f,
            .mDokanUDOffsetYoshiMini  = 30.0f,
            .mDokanUDOffsetSmall      = 20.0f,
            .mDokanUDOffsetMini       = 12.0f,
            .mDokanUDAdjustBig        = 0.0f,
            .mDokanUDAdjustPropeller  = 8.0f,
        };

        static constexpr const dPyStatic_HIO_c l_BLUE_TOAD = {
            .mDokanUDOffsetYoshiSmall = 38.0f,
            .mDokanUDOffsetYoshiBig   = 44.0f,
            .mDokanUDOffsetYoshiMini  = 30.0f,
            .mDokanUDOffsetSmall      = 20.0f,
            .mDokanUDOffsetMini       = 12.0f,
            .mDokanUDAdjustBig        = 0.0f,
            .mDokanUDAdjustPropeller  = 8.0f,
        };

        static constexpr const dPyStatic_HIO_c l_TOADETTE = {
            .mDokanUDOffsetYoshiSmall = 38.0f,
            .mDokanUDOffsetYoshiBig   = 44.0f,
            .mDokanUDOffsetYoshiMini  = 30.0f,
            .mDokanUDOffsetSmall      = 20.0f,
            .mDokanUDOffsetMini       = 12.0f,
            .mDokanUDAdjustBig        = 0.0f,
            .mDokanUDAdjustPropeller  = 8.0f,
        };

        static constexpr const dPyStatic_HIO_c l_PURPLE_TOADETTE = {
            .mDokanUDOffsetYoshiSmall = 38.0f,
            .mDokanUDOffsetYoshiBig   = 44.0f,
            .mDokanUDOffsetYoshiMini  = 30.0f,
            .mDokanUDOffsetSmall      = 20.0f,
            .mDokanUDOffsetMini       = 12.0f,
            .mDokanUDAdjustBig        = 0.0f,
            .mDokanUDAdjustPropeller  = 8.0f,
        };

        static constexpr const dPyStatic_HIO_c l_ORANGE_TOAD = {
            .mDokanUDOffsetYoshiSmall = 38.0f,
            .mDokanUDOffsetYoshiBig   = 44.0f,
            .mDokanUDOffsetYoshiMini  = 30.0f,
            .mDokanUDOffsetSmall      = 20.0f,
            .mDokanUDOffsetMini       = 12.0f,
            .mDokanUDAdjustBig        = 0.0f,
            .mDokanUDAdjustPropeller  = 8.0f,
        };

        static constexpr const dPyStatic_HIO_c l_BLACK_TOAD = {
            .mDokanUDOffsetYoshiSmall = 38.0f,
            .mDokanUDOffsetYoshiBig   = 44.0f,
            .mDokanUDOffsetYoshiMini  = 30.0f,
            .mDokanUDOffsetSmall      = 20.0f,
            .mDokanUDOffsetMini       = 12.0f,
            .mDokanUDAdjustBig        = 0.0f,
            .mDokanUDAdjustPropeller  = 8.0f,
        };

        if (pt >= PLAYER_TYPE_e::COUNT || pt < PLAYER_TYPE_e::MARIO) {
            pt = PLAYER_TYPE_e::YELLOW_TOAD;
        }
        return *(const dPyStatic_HIO_c*[]) {
            &l_MARIO,    &l_LUIGI,           &l_BLUE_TOAD,   &l_YELLOW_TOAD, &l_BLUE_TOAD,
            &l_TOADETTE, &l_PURPLE_TOADETTE, &l_ORANGE_TOAD, &l_BLACK_TOAD,
        }[+pt];
    }
};
