// OSError.c
// NSMBW .text: 0x801AD620 - 0x801ADCE0

#include <revolution/os/OSError.h>

extern "C" {

// OVERRIDDEN: OSReport

// OVERRIDDEN: OSVReport

[[address(0x801AD620)]]
void OSPanic(const char* file, int line, const char* format, ...);

/* 0x801AD750 */
[[address(0x801AD750)]]
void OSSetErrorHandler(void (*handler)(const char* file, int line, const char* msg));

} // extern "C"