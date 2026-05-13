// printf.c
// NSMBW .text: 0x802DF7A8 - 0x802E1BA0

#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

EXTERN_C_START

// 0x802DF7A8: parse_format

// 0x802DFD64: long2str

// 0x802DFFA4: longlong2str

// 0x802E0254: double2hex

// 0x802E061C: round_decimal

// 0x802E0744: float2str

[[nsmbw(0x802E0EE0)]]
int __pformatter(
    void* (*WriteProc)(void*, const char*, size_t), void* WriteProcArg, const char* format_str,
    va_list arg
);

[[nsmbw(0x802E178C)]]
void* __FileWrite(void* pFile, const char* pBuffer, size_t char_num);

// 0x802E17E4: __StringWrite

int fprintf(
    FILE* file, const char* format, ...
) {
    if (fwide(file, -1) >= 0) {
        return -1;
    }

    va_list args;
    va_start(args, format);
    return __pformatter(&__FileWrite, static_cast<void*>(file), format, args);
}

// UNUSED: printf_s

// UNUSED: fprintf

// UNUSED: fprintf_s

[[nsmbw(0x802E1850)]]
int vprintf(const char* __restrict format, va_list ap);

// UNUSED: vprintf_s

// UNUSED: vfprintf

// UNUSED: vfprintf_s

[[nsmbw(0x802E18CC)]]
int vsnprintf(char* __restrict s, size_t n, const char* __restrict format, va_list ap);

// UNUSED: vsnprintf_s

[[nsmbw(0x802E1954)]]
int vsprintf(char* __restrict s, const char* __restrict format, va_list ap);

// UNUSED: vsprintf_s

[[nsmbw(0x802E19D8)]]
int snprintf(char* __restrict s, size_t n, const char* __restrict format, ...);

// UNUSED: snprintf_s

[[nsmbw(0x802E1ACC)]]
int sprintf(char* __restrict s, const char* __restrict format, ...);

// UNUSED: sprintf_s

EXTERN_C_END
