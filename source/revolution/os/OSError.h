#pragma once

#include "OSContext.h"
#include <stdarg.h>

EXTERN_C_START

typedef u8 __OSException;
typedef u16 OSError;

/* 0x80429800 */
extern u32 __OSFpscrEnableBits;

typedef void (*OSErrorHandler)(OSError error, OSContext* context, u32, u32);

/* 0x8015F870 - s_Print.cpp */
[[gnu::format(printf, 1, 2)]]
void OSReport(const char* format, ...);

/* 0x8015F880 - s_Print.cpp */
[[gnu::format(printf, 1, 2)]]
void OSVReport(const char* format, va_list args);

/* 0x801AD620 */
[[noreturn]] [[gnu::format(printf, 3, 4)]]
void OSPanic(const char* file, int line, const char* format, ...);

/* 0x801AD750 */
void OSSetErrorHandler(void (*handler)(const char* file, int line, const char* msg));

#define OS_REPORT(fmt, ...)                                                                        \
    OSReport("%s:%d: " fmt, __FILE_NAME__, __LINE__ __VA_OPT__(, ) __VA_ARGS__)
#define OS_PANIC(msg) OSPanic(__FILE_NAME__, __LINE__, msg)
#define ASSERTMSG(exp, msg) (void) ((exp) || (OSPanic(__FILE_NAME__, __LINE__, (msg)), 0))
#define ASSERT(cond) ((cond) || (OSPanic(__FILE_NAME__, __LINE__, "Failed assertion " #cond), 0))

EXTERN_C_END
