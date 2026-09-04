#pragma once

#include "d_mj2d_game.h"
#include <nw4r/ut/Color.h>

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

    float           mDokanUDOffsetYoshiSmall, mDokanUDOffsetYoshiBig, mDokanUDOffsetYoshiMini;
    float           mDokanUDOffsetSmall, mDokanUDOffsetMini;
    float           mDokanUDAdjustBig, mDokanUDAdjustPropeller;

    float           mFukidashiYOffset[PLAYER_MODE_COUNT];
    nw4r::ut::Color mFukidashiColor[3];

    nw4r::ut::Color mRemoconCannonTrailEffColor[2];

public:
    static const dPyStatic_HIO_c& get(
        PLAYER_TYPE_e pt
    ) {
        // TODO: Make this configurable via JSON
        static constexpr const dPyStatic_HIO_c lMario = {
            .mDokanUDOffsetYoshiSmall = 34.0f,
            .mDokanUDOffsetYoshiBig   = 40.0f,
            .mDokanUDOffsetYoshiMini  = 30.0f,
            .mDokanUDOffsetSmall      = 20.0f,
            .mDokanUDOffsetMini       = 12.0f,
            .mDokanUDAdjustBig        = 0.0f,
            .mDokanUDAdjustPropeller  = 8.0f,
            .mFukidashiYOffset =
                {
                    20.0, // Small
                    32.0, // Mushroom
                    32.0, // Fire Flower
                    12.0, // Mini Mushroom
                    38.0, // Propeller Shroom
                    33.0, // Penguin Suit
                    32.0, // Ice Flower
                },
            .mFukidashiColor             = {"#FAE6E6", "#F06E6E", "#FFB4B4"},
            .mRemoconCannonTrailEffColor = {"#FFCCDD", "#FF2970"},
        };

        static constexpr const dPyStatic_HIO_c lLuigi = {
            .mDokanUDOffsetYoshiSmall = 36.0f,
            .mDokanUDOffsetYoshiBig   = 42.0f,
            .mDokanUDOffsetYoshiMini  = 30.0f,
            .mDokanUDOffsetSmall      = 20.0f,
            .mDokanUDOffsetMini       = 12.0f,
            .mDokanUDAdjustBig        = 0.0f,
            .mDokanUDAdjustPropeller  = 8.0f,
            .mFukidashiYOffset =
                {
                    20.0, // Small
                    34.0, // Mushroom
                    34.0, // Fire Flower
                    12.0, // Mini Mushroom
                    39.0, // Propeller Shroom
                    35.0, // Penguin Suit
                    34.0, // Ice Flower
                },
            .mFukidashiColor             = {"#F0FFF0", "#64C864", "#64FF64"},
            .mRemoconCannonTrailEffColor = {"#CCFFCE", "#29FF33"},
        };

        static constexpr const dPyStatic_HIO_c lYellowToad = {
            .mDokanUDOffsetYoshiSmall = 38.0f,
            .mDokanUDOffsetYoshiBig   = 44.0f,
            .mDokanUDOffsetYoshiMini  = 30.0f,
            .mDokanUDOffsetSmall      = 20.0f,
            .mDokanUDOffsetMini       = 12.0f,
            .mDokanUDAdjustBig        = 0.0f,
            .mDokanUDAdjustPropeller  = 8.0f,
            .mFukidashiYOffset =
                {
                    20.0, // Small
                    29.0, // Mushroom
                    29.0, // Fire Flower
                    11.0, // Mini Mushroom
                    34.0, // Propeller Shroom
                    29.0, // Penguin Suit
                    29.0, // Ice Flower
                },
            .mFukidashiColor             = {"#FAFAE6", "#FFDC50", "#FFF06E"},
            .mRemoconCannonTrailEffColor = {"#FFFFAC", "#FFFF00"},
        };

        static constexpr const dPyStatic_HIO_c lBlueToad = {
            .mDokanUDOffsetYoshiSmall = 38.0f,
            .mDokanUDOffsetYoshiBig   = 44.0f,
            .mDokanUDOffsetYoshiMini  = 30.0f,
            .mDokanUDOffsetSmall      = 20.0f,
            .mDokanUDOffsetMini       = 12.0f,
            .mDokanUDAdjustBig        = 0.0f,
            .mDokanUDAdjustPropeller  = 8.0f,
            .mFukidashiYOffset =
                {
                    20.0, // Small
                    29.0, // Mushroom
                    29.0, // Fire Flower
                    11.0, // Mini Mushroom
                    34.0, // Propeller Shroom
                    29.0, // Penguin Suit
                    29.0, // Ice Flower
                },
            .mFukidashiColor             = {"#F0FAFA", "#648CDC", "#8CFAFF"},
            .mRemoconCannonTrailEffColor = {"#FFFFFF", "#6CFFFF"},
        };

        static constexpr const dPyStatic_HIO_c lToadette = {
            .mDokanUDOffsetYoshiSmall = 38.0f,
            .mDokanUDOffsetYoshiBig   = 44.0f,
            .mDokanUDOffsetYoshiMini  = 30.0f,
            .mDokanUDOffsetSmall      = 20.0f,
            .mDokanUDOffsetMini       = 12.0f,
            .mDokanUDAdjustBig        = 0.0f,
            .mDokanUDAdjustPropeller  = 8.0f,
            .mFukidashiYOffset =
                {
                    20.0, // Small
                    29.0, // Mushroom
                    29.0, // Fire Flower
                    11.0, // Mini Mushroom
                    34.0, // Propeller Shroom
                    29.0, // Penguin Suit
                    29.0, // Ice Flower
                },
            .mFukidashiColor             = {"#FAE1EC", "#FF8DB7", "#FFB2D6"},
            .mRemoconCannonTrailEffColor = {"#FFCEFF", "#FF6CFF"},
        };

        static constexpr const dPyStatic_HIO_c lPurpleToadette = {
            .mDokanUDOffsetYoshiSmall = 38.0f,
            .mDokanUDOffsetYoshiBig   = 44.0f,
            .mDokanUDOffsetYoshiMini  = 30.0f,
            .mDokanUDOffsetSmall      = 20.0f,
            .mDokanUDOffsetMini       = 12.0f,
            .mDokanUDAdjustBig        = 0.0f,
            .mDokanUDAdjustPropeller  = 8.0f,
            .mFukidashiYOffset =
                {
                    20.0, // Small
                    29.0, // Mushroom
                    29.0, // Fire Flower
                    11.0, // Mini Mushroom
                    34.0, // Propeller Shroom
                    29.0, // Penguin Suit
                    29.0, // Ice Flower
                },
            .mFukidashiColor             = {"#E3D5EB", "#DA89FA", "#E6C2FB"},
            .mRemoconCannonTrailEffColor = {"#CCACFF", "#AC6CFF"},
        };

        static constexpr const dPyStatic_HIO_c lOrangeToad = {
            .mDokanUDOffsetYoshiSmall = 38.0f,
            .mDokanUDOffsetYoshiBig   = 44.0f,
            .mDokanUDOffsetYoshiMini  = 30.0f,
            .mDokanUDOffsetSmall      = 20.0f,
            .mDokanUDOffsetMini       = 12.0f,
            .mDokanUDAdjustBig        = 0.0f,
            .mDokanUDAdjustPropeller  = 8.0f,
            .mFukidashiYOffset =
                {
                    20.0, // Small
                    29.0, // Mushroom
                    29.0, // Fire Flower
                    11.0, // Mini Mushroom
                    34.0, // Propeller Shroom
                    29.0, // Penguin Suit
                    29.0, // Ice Flower
                },
            .mFukidashiColor             = {"#F6E7D9", "#EA7F4F", "#F3C489"},
            .mRemoconCannonTrailEffColor = {"#FFCCAC", "#FFAC70"},
        };

        static constexpr const dPyStatic_HIO_c lBlackToad = {
            .mDokanUDOffsetYoshiSmall = 38.0f,
            .mDokanUDOffsetYoshiBig   = 44.0f,
            .mDokanUDOffsetYoshiMini  = 30.0f,
            .mDokanUDOffsetSmall      = 20.0f,
            .mDokanUDOffsetMini       = 12.0f,
            .mDokanUDAdjustBig        = 0.0f,
            .mDokanUDAdjustPropeller  = 8.0f,
            .mFukidashiYOffset =
                {
                    20.0, // Small
                    29.0, // Mushroom
                    29.0, // Fire Flower
                    11.0, // Mini Mushroom
                    34.0, // Propeller Shroom
                    29.0, // Penguin Suit
                    29.0, // Ice Flower
                },
            .mFukidashiColor             = {"#86798B", "#2D2A2E", "#5C5560"},
            .mRemoconCannonTrailEffColor = {"#ACACAC", "#6C6C6C"},
        };

        if (pt >= PLAYER_TYPE_e::COUNT || pt < PLAYER_TYPE_e::MARIO) {
            pt = PLAYER_TYPE_e::YELLOW_TOAD;
        }
        return *(const dPyStatic_HIO_c*[]) {
            &lMario,    &lLuigi,          &lBlueToad,   &lYellowToad,
            &lToadette, &lPurpleToadette, &lOrangeToad, &lBlackToad,
        }[+pt];
    }
};
