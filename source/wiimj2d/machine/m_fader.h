#pragma once

#include "m_fader_base.h"

class mFader_c : public mFaderBase_c {
public:
    /* 0x8042A720 */ static mFader_c* mFader;

    static bool isStatus(
        EStatus status
    ) {
        return mFader->getStatus() == status;
    }
};
