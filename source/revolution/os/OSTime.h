#pragma once

EXTERN_C_START

struct OSCalendarTime {
    /* 0x00 */ s32 sec;
    /* 0x04 */ s32 min;
    /* 0x08 */ s32 hour;
    /* 0x0C */ s32 mday;
    /* 0x10 */ s32 month;
    /* 0x14 */ s32 year;
    /* 0x18 */ s32 wday;
    /* 0x1C */ s32 yday;
    /* 0x20 */ s32 msec;
    /* 0x24 */ s32 usec;
};

using OSTime = s64;
using OSTick = s32;

/* 0x801B60C0 */
OSTime OSGetTime();

/* 0x801B60E0 */
OSTick OSGetTick();

/* 0x801B61C0 */
void OSTicksToCalendarTime(OSTime time, OSCalendarTime* cal);

EXTERN_C_END
