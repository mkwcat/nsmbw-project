#pragma once

EXTERN_C_START

[[noreturn]] [[gnu::format(printf, 3, 4)]]
void OSPanic(const char* file, int line, const char* format, ...);

#ifdef NDEBUG
#  define assert(...) ((void) 0)
#else
#  define assert(...)                                                                              \
      ((__VA_ARGS__) || (OSPanic(__FILE_NAME__, __LINE__, "Failed assertion %s", #__VA_ARGS__), 0))
#endif

EXTERN_C_END
