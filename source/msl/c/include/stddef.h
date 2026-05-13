#pragma once

typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;

#define offsetof(_TYPE, _MEMBER) __builtin_offsetof(_TYPE, _MEMBER)

#define NULL nullptr
