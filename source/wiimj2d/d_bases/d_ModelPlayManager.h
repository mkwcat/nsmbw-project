#pragma once

#include "d_system/d_base.h"

class dModelPlayManager_c : public dBase_c {
public:
    // Nested Types
    // ^^^^^^

    struct OtehonInfo_s {
        SIZE_ASSERT(0x24);

        /* 0x00 */ int WorldNo;
        /* 0x04 */ int StageNo;
        /* 0x08 */ int OtehonType;
        /* 0x0C */ int NextGotoNo;
        /* 0x10 */ int OtehonTime;
        /* 0x14 */ int CourseNo;
        /* 0x18 */ int BuyCoinCount;
        /* 0x1C */ int Condition;
        /* 0x20 */ int ConditionCoinCount;
    };

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0xA7C);

    /* 0xA7C */ bool mReady;

public:
    // Static Variables
    // ^^^^^^

    /* 0x80934670 */
    static const OtehonInfo_s m_otehonInfo[];
};
