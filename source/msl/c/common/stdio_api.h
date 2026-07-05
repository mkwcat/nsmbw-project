#pragma once

#include <stddef.h>

EXTERN_C_START

enum __ReadProcActions {
    __GetAChar,
    __UngetAChar,
    __TestForError,
};

typedef struct {
    char* NextChar;
    int   NullCharDetected;
} __InStrCtrl;

typedef struct {
    wchar_t* wCharStr;
    size_t   MaxCharCount;
    size_t   CharsWritten;
} __wOutStrCtrl;

typedef struct {
    wchar_t* wNextChar;
    int      wNullCharDetected;
} __wInStrCtrl;

/* 0x802E1BA0 */
int __StringRead(void* pPtr, int ch, int act);

EXTERN_C_END
