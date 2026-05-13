#pragma once

#ifndef _VA_LIST
#  define _VA_LIST
typedef __builtin_va_list va_list;
#endif

#ifdef va_start
#  undef va_start
#endif

#define va_start(ap, param) __builtin_va_start(ap, param)

#ifdef va_end
#  undef va_end
#endif

#define va_end(ap) __builtin_va_end(ap)

#ifdef va_arg
#  undef va_arg
#endif

#define va_arg(ap, type) __builtin_va_arg(ap, type)

#ifdef va_copy
#  undef va_copy
#endif

#define va_copy(dest, src) __builtin_va_copy(dest, src)