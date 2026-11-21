#pragma once

#define BOOL_WIDTH 8

#define CHAR_BIT 8

#define MB_LEN_MAX 2

#define CHAR_WIDTH 8

#ifdef __CHAR_UNSIGNED__
#  define CHAR_MIN 0
#  define CHAR_MAX 255
#else
#  define CHAR_MIN (-128)
#  define CHAR_MAX 127
#endif

#define SCHAR_WIDTH 8
#define SCHAR_MIN   (-128)
#define SCHAR_MAX   127

#define UCHAR_WIDTH 8
#define UCHAR_MAX   255

#define SHRT_WIDTH 16
#define SHRT_MIN   (-SHRT_MAX - 1)
#define SHRT_MAX   32767

#define USHRT_WIDTH 16
#define USHRT_MAX   65535

#define INT_WIDTH 32
#define INT_MIN   (-INT_MAX - 1)
#define INT_MAX   2147483647

#define UINT_WIDTH 32
#define UINT_MAX   ULONG_MAX

#define LONG_WIDTH 32
#define LONG_MIN   (-LONG_MAX - 1)
#define LONG_MAX   2147483647L

#define ULONG_WIDTH 32
#define ULONG_MAX   4294967295UL

#define LLONG_WIDTH 64
#define LLONG_MIN   (-LLONG_MAX - 1)
#define LLONG_MAX   9223372036854775807LL

#define ULLONG_WIDTH 64
#define ULLONG_MAX   (LLONG_MAX * 2ULL + 1)
