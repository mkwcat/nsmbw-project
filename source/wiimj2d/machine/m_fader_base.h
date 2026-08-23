#pragma once

/**
 * Base fader implementation.
 */
class mFaderBase_c {
public:
    enum EStatus {
        /**
         * The screen is completely blacked out.
         */
        OPAQUE   = 0,

        /**
         * The screen is completely unblocked.
         */
        HIDDEN   = 1,

        /**
         * Transition from OPAQUE to HIDDEN.
         */
        FADE_IN  = 2,

        /**
         * Transition from HIDDEN to OPAQUE.
         */
        FADE_OUT = 3,
    };

    /* VT+0x08 0x8016DDE0 */
    virtual ~mFaderBase_c();

    /* VT+0x0C */
    virtual void setStatus(EStatus status) = 0;

    /* VT+0x10 0x8016DE50 */
    virtual EStatus getStatus() const;
};
