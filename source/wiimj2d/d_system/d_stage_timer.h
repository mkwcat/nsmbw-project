#pragma once

class dStageTimer_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x800E3A20 */
    void execute();

    inline int getDispTimeRoundUp() const
    {
        return (mTime + 0xFFF) / 0x1000;
    }

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x00, 0x0C);

    /**
     * The current countdown timer in in-game milliseconds, decremented by 92 every frame.
     */
    /* 0x04 */ int mTime;

    /**
     * The current countdown timer in in-game seconds, rounded up.
     */
    /* 0x08 */ short mDispTime;

    /**
     * Is an Ambush stage?
     */
    /* 0x0A */ bool mIsAmbush;

    /**
     * Have we passed 100 seconds remaining?
     */
    /* 0x0B */ bool mHurryUp;

    /**
     * Is the timer currently paused?
     */
    /* 0x0C */ bool mPause;

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A350 */ static dStageTimer_c* m_instance;
};
