// OSError.c
// NSMBW .text: 0x801AD620 - 0x801ADCE0

#include <revolution/os/OSError.h>

EXTERN_C_START

// NSMBW only:
// OVERRIDDEN: OSReport
// OVERRIDDEN: OSVReport
// OVERRIDDEN: OSPanic

[[mkw(0x801A25D0)]] void OSReport(const char* format, ...);

[[mkw(0x801A265C)]] void OSVReport(const char* format, va_list args);

[[mkw(0x801A2660)]] [[noreturn]]
void OSPanic(const char* file, int line, const char* format, ...);

[[nsmbw(0x801AD750)]] [[mkw(0x801A278C)]]
void OSSetErrorHandler(void (*handler)(const char* file, int line, const char* msg));

EXTERN_C_END
