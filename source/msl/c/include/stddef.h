#pragma once

#include "msl/c/internal/NULL.h"
#include "msl/c/internal/ptrdiff_t.h"
#include "msl/c/internal/size_t.h"

#define offsetof(_TYPE, _MEMBER) __builtin_offsetof(_TYPE, _MEMBER)
