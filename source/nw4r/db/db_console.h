#pragma once

#include "nw4r/ut/TextWriter.h"
#include <cstdarg>

namespace nw4r::db {

namespace detail {
struct ConsoleHead {
    u8*                   textBuf;
    u16                   width;
    u16                   height;
    u16                   priority;
    u16                   attr;
    u16                   printTop;
    u16                   printXPos;
    u16                   ringTop;
    s32                   ringTopLineCnt;
    s32                   viewTopLine;
    s16                   viewPosX;
    s16                   viewPosY;
    u16                   viewLines;
    bool                  isVisible;
    nw4r::ut::TextWriter* writer;
    ConsoleHead*          next;
};
} // namespace detail

typedef detail::ConsoleHead* ConsoleHandle;

enum class ConsoleOutputType {
    CONSOLE_OUTPUT_NONE     = 0,
    CONSOLE_OUTPUT_DISPLAY  = 1,
    CONSOLE_OUTPUT_TERMINAL = 2,
    CONSOLE_OUTPUT_ALL      = CONSOLE_OUTPUT_DISPLAY | CONSOLE_OUTPUT_TERMINAL,
};

inline s16 Console_GetPositionX(
    ConsoleHandle console
) {
    return console->viewPosX;
}

inline s16 Console_GetPositionY(
    ConsoleHandle console
) {
    return console->viewPosY;
}

inline bool Console_SetVisible(
    ConsoleHandle handle, bool bVisible
) {
    const bool old    = handle->isVisible;
    handle->isVisible = bVisible;
    return old;
}

inline void Console_SetPosition(
    ConsoleHandle handle, s32 x, s32 y
) {
    handle->viewPosX = x;
    handle->viewPosY = y;
}

inline s32 Console_GetViewBaseLine(
    ConsoleHandle console
) {
    return console->viewTopLine;
}

inline s32 Console_SetViewBaseLine(
    ConsoleHandle console, s32 line
) {
    const s32 old        = console->viewTopLine;
    console->viewTopLine = line;
    return old;
}

inline s32 Console_GetBufferHeadLine(
    ConsoleHandle console
) {
    return console->ringTopLineCnt;
}

ConsoleHandle Console_Create(void* arg, u16, u16, u16, u16, u16);
ConsoleHandle Console_Destroy(ConsoleHandle console);
void Console_DrawDirect(ConsoleHandle console);
void Console_VFPrintf(
    ConsoleOutputType type, ConsoleHandle console, const char* format, va_list vlist
);
void Console_Printf(ConsoleHandle console, const char* format, ...);

[[nsmbw(0x80234700)]]
s32 Console_GetTotalLines(ConsoleHandle console);

} // namespace nw4r::db
