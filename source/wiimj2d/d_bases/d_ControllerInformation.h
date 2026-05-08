#pragma once

#include "d_system/d_base.h"

/**
 * Displays the controller information screen. This is the screen that reads "Hold the Wii Remote
 * sideways".
 */
class dControllerInformation_c : public dBase_c {
    SIZE_ASSERT(0x20A);

public:
    /* 0x60 VTABLE 0x80323118 */

    /**
     * The identifier for each animation.
     */
    enum ANIM_e {
        /**
         * The button's pop-out animation.
         */
        IN2BTN   = 0,

        /**
         * The button's blinking loop animation.
         */
        LOOP2BTN = 1,

        /**
         * The button's hit animation.
         */
        HIT2BTN  = 2,
    };

    /**
     * The state that controls what the layout should be doing.
     */
    enum STATE_e {
        /**
         * Initial state; waiting for layout creation.
         */
        IDLE            = 0,

        /**
         * Play the button pop-out animation.
         */
        SHOW_IN         = 1,

        /**
         * Wait for the pop-out to finish.
         */
        SHOW_LOOP       = 2,

        /**
         * Play the button animation while waiting for user input.
         */
        WAITING_FOR_END = 3,

        /**
         * The button has been pressed, play the sound effect and the shrinking button animation.
         */
        END             = 4,
    };

    FILL(0x70, 0x208);

    /* 0x208 */ bool mReady;
    /* 0x209 */ bool mVisible;
};
