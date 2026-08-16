#pragma once

class dAcPyKey_c {
    SIZE_ASSERT(0x164);

public:
    // Constants
    // ^^^^^^

    enum BUTTONS_e {
        DOWN  = 0_bit,
        UP    = 1_bit,
        RIGHT = 2_bit,
        LEFT  = 3_bit,
        CROSS = LEFT | RIGHT | UP | DOWN,
        TWO   = 8_bit,
        ONE   = 9_bit,
        B     = 10_bit,
        A     = 11_bit,
    };

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8005E040 */
    void update();

    /* 0x8005E590 */
    u16 triggerOne() const;

    /* 0x8005E5D0 */
    u16 buttonOne() const;

    /* 0x8005E6F0 */
    bool triggerJump() const;

    /* 0x8005E780 */
    bool triggerShakeJump() const;

    /* 0x8005E7A0 */
    bool buttonWalk(int* dir) const;

    /* 0x8005E8B0 */
    bool triggerJumpBuf(int param2);

    /* 0x8005E910 */
    void onDemoButton(int button);

    /* 0x8005E930 */
    void offDemoButton(int button);

    /* 0x8005E960 */
    void onDemoTrigger(int button);

public:
    // Instance Variables
    // ^^^^^^

    int  mRemoconID;
    u16  mDownButtons;
    u16  mTriggeredButtons;
    u16  mPrevDownButtons;
    u16  mPrevTriggeredButtons;
    u16  mDownButtonsDemo;
    u16  mTriggeredButtonsDemo;
    u16  mDemoDoShake;
    u16  mStatus;
    u8   mHipAtkHoldCount;
    bool mHipAtkRead;
    bool mHipAtkHoldStart;
    u8   mTriggerShakeJump;
    u8   mActiveShakeJump;
    bool mActionTriggered;
    int  mShakeCooldown;
    int  m0x20;

    int  mJumpTriggeredHistory[4][10];
    int  mJumpButtonHistory[4][10];
};
