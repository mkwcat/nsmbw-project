#pragma once

class dAcPyKey_c
{
    SIZE_ASSERT(0x164);

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

public:
    // Instance Variables
    // ^^^^^^

    int mRemoconID;
    u16 mDownButtons;
    u16 mTriggeredButtons;
    u16 mPrevDownButtons;
    u16 mPrevTriggeredButtons;
    u16 mDownButtonsDemo;
    u16 mTriggeredButtonsDemo;
    u16 mDemoDoShake;
    u16 mStatus;
    u8 mHipAtkHoldCount;
    bool mHipAtkRead;
    bool mHipAtkHoldStart;
    u8 mTriggerShakeJump;
    u8 mActiveShakeJump;
    bool mActionTriggered;
    int mShakeCooldown;
    int m_20;

    int mJumpTriggeredHistory[4][10];
    int mJumpButtonHistory[4][10];
};
