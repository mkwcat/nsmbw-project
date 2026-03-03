#pragma once

class dStageTimer_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x800E3A00 */
    void setTimer(short timer);

    inline short getTimer() const
    {
        return (m_timer + 0xFFF) / 0x1000;
    }

    /* 0x800E3A20 */
    void execute();

public:
    // Instance Variables
    // ^^^^^^

    /**
     * The current countdown timer value in in-game seconds * 0x1000, decremented by 92 every frame.
     */
    /* 0x04 */ int m_timer;

    /**
     * The value the timer is counting down from, in in-game seconds.
     */
    /* 0x08 */ short m_timerSet;

    /**
     * Is an Ambush stage?
     */
    /* 0x0A */ bool m_isAmbush;

    /**
     * Have we passed 100 seconds remaining?
     */
    /* 0x0B */ bool m_isHurryUp;

    /**
     * Is the timer currently paused?
     */
    /* 0x0C */ bool m_isStop;

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A350 */ static dStageTimer_c* m_instance;
};
