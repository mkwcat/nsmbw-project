#pragma once

#include "machine/m_pad.h"
#include "machine/m_vec.h"
#include <revolution/pad.h>

class dGameKeyCore_c
{
    SIZE_ASSERT(0x93);
    /* 0x0 VTABLE 0x80315910 */

public:
    // Structors
    // ^^^^^^

    /* 0x800B5B50 */
    dGameKeyCore_c(mPad::CH_e channel);

    /* VT+0x8 0x800B5BA0 */
    virtual ~dGameKeyCore_c();

public:
    // Constants
    // ^^^^^^

    /* @unofficial */
    enum class Type_e {
        /**
         * Regular sideways Wii Remote or replay input.
         */
        CORE = 0,
        /**
         * Wii Remote with Nunchuk.
         */
        FREESTYLE = 1,
        /**
         * GameCube Controller.
         */
        DOLPHIN = 2,
        /**
         * Classic Controller (TODO).
         */
        CLASSIC = 3,
    };

    /* @unofficial */
    enum Button_e {
        UP = EGG::cCORE_SIDE_BUTTON_UP,
        DOWN = EGG::cCORE_SIDE_BUTTON_DOWN,
        LEFT = EGG::cCORE_SIDE_BUTTON_LEFT,
        RIGHT = EGG::cCORE_SIDE_BUTTON_RIGHT,

        BTN_2 = EGG::cCORE_BUTTON_2,
        BTN_1 = EGG::cCORE_BUTTON_1,
        BTN_A = EGG::cCORE_BUTTON_A,
        BTN_B = EGG::cCORE_BUTTON_B,
        BTN_Z = EGG::cCORE_BUTTON_FS_Z,

        PLUS = EGG::cCORE_BUTTON_PLUS,
        MINUS = EGG::cCORE_BUTTON_MINUS,

        HOME = EGG::cCORE_BUTTON_HOME,

        SHAKE = 24_bit,
    };

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800B5BE0 */
    void allclear();

    /* 0x800B5CB0 */
    void read();

    /* 0x800B60D0 */
    u32 setConfigKey(u32 button);

    /* 0x800B61F0 */
    void handleTilting();

    /* 0x800B62A0 */
    void setShakeY();

public:
    // Inline Methods
    // ^^^^^^

    inline EGG::Controller* getController() const
    {
        return mPad::g_core_order[mPlayerNo];
    }

    /**
     * Returns true if the controller is a sideways Wii Remote.
     */
    inline bool isCore() const
    {
        return mType == Type_e::CORE;
    }

    /**
     * Returns true if the controller is a Wii Remote + Nunchuk.
     */
    inline bool isFreestyle() const
    {
        return mType == Type_e::FREESTYLE;
    }

    /**
     * Returns true if the controller is a Wii Classic Controller.
     */
    inline bool isClassic() const
    {
        return mType == Type_e::CLASSIC;
    }

    /**
     * Returns true if the controller is a GameCube Controller.
     */
    inline bool isDolphin() const
    {
        return mType == Type_e::DOLPHIN;
    }

    /**
     * Returns true if one of the button flags is set.
     */
    inline bool isDown(u32 flags) const
    {
        return mHeld & flags;
    }

    /**
     * Returns true if one of the button flags is set on this frame.
     */
    inline bool isTrig(u32 flags) const
    {
        return mTriggered & flags;
    }

    /**
     * Checks if the confirm (2 or A) button is pressed.
     */
    inline bool checkMenuConfirm() const
    {
        return getController()->downTrigger(EGG::cCORE_BUTTON_2 | EGG::cCORE_BUTTON_A);
    }

    /**
     * Checks if the cancel (1 or B) button is pressed.
     */
    inline bool checkMenuCancel() const
    {
        return getController()->downTrigger(EGG::cCORE_BUTTON_1 | EGG::cCORE_BUTTON_B);
    }

    /**
     * Checks if the left button is pressed.
     */
    inline bool checkLeft() const
    {
        return isTrig(LEFT);
    }

    /**
     * Checks if the right button is pressed.
     */
    inline bool checkRight() const
    {
        return isTrig(RIGHT);
    }

    /**
     * Checks if the up button is pressed.
     */
    inline bool checkUp() const
    {
        return isTrig(UP);
    }

    /**
     * Checks if the down button is pressed.
     */
    inline bool checkDown() const
    {
        return isTrig(DOWN);
    }

    /**
     * Gets the mTilt value as a usable s16 for actors.
     */
    inline s16 getTiltLR() const
    {
        return static_cast<s16>(static_cast<int>((mAccelVerticalX.y / 30.0) * 16384.0));
    }

public:
    // Instance Variables
    // ^^^^^^

    /* 0x04 */ int mPlayerNo;
    /* 0x08 */ Type_e mType;
    /* 0x0C */ u32 mRawHeld; // mHeld without Nunchuck button manipulation
    /* 0x10 */ u32 mPrevRawHeld; // mHeld without Nunchuck button manipulation
    /* 0x14 */ u32 mHeld;
    /* 0x18 */ u32 mPrevHeld;
    /* 0x1C */ u32 mTriggered;
    /* 0x20 */ u32 m0x20;
    /* 0x24 */ u32 m0x24;
    /* 0x28 */ u32 m0x28;
    /* 0x2C */ u32 m0x2C;
    /* 0x30 */ u32 m0x30;
    /* 0x34 */ mVec3_c mAccel;
    /* 0x40 */ mVec3_c mAccelOld;
    /* 0x4C */ mVec2_c mAccelVerticalX;
    /* 0x54 */ mVec2_c mAccelVerticalXOld;
    /* 0x5C */ mVec2_c mAccelVerticalY;
    /* 0x64 */ mVec2_c mAccelVerticalYOld;
    /* 0x6C */ mVec2_c mAccelVerticalZ;
    /* 0x74 */ mVec2_c mAngle;
    /* 0x7C */ mVec2_c mAngleOld;
    /* 0x84 */ f32 mMoveDistance;
    /* 0x88 */ f32 mMoveDistanceOld;
    /* 0x8C */ bool mShake;
    /* 0x8D */ bool mShakeOld;
    /* 0x8E */ short mTilt;
    /* 0x90 */ u8 mShakeTimer1;
    /* 0x91 */ u8 mShakeTimer2;
    /* 0x92 */ u8 mShakeTimer3;
};
