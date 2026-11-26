#pragma once

// Enum value must be greater or equals than MAGIC_ENUM_RANGE_MIN. By default MAGIC_ENUM_RANGE_MIN =
// -128. If need another min range for all enum types by default, redefine the macro
// MAGIC_ENUM_RANGE_MIN.
#if !defined(MAGIC_ENUM_RANGE_MIN)
#  define MAGIC_ENUM_RANGE_MIN -128
#endif

// Enum value must be less or equals than MAGIC_ENUM_RANGE_MAX. By default MAGIC_ENUM_RANGE_MAX =
// 127. If need another max range for all enum types by default, redefine the macro
// MAGIC_ENUM_RANGE_MAX.
#if !defined(MAGIC_ENUM_RANGE_MAX)
#  define MAGIC_ENUM_RANGE_MAX 127
#endif

namespace magic_enum::customize {

// Enum value must be in range [MAGIC_ENUM_RANGE_MIN, MAGIC_ENUM_RANGE_MAX]. By default
// MAGIC_ENUM_RANGE_MIN = -128, MAGIC_ENUM_RANGE_MAX = 127. If need another range for all enum types
// by default, redefine the macro MAGIC_ENUM_RANGE_MIN and MAGIC_ENUM_RANGE_MAX. If need another
// range for specific enum type, add specialization enum_range for necessary enum type.
template <typename E>
struct enum_range {
    static constexpr int min = MAGIC_ENUM_RANGE_MIN;
    static constexpr int max = MAGIC_ENUM_RANGE_MAX;
};

static_assert(
    MAGIC_ENUM_RANGE_MAX > MAGIC_ENUM_RANGE_MIN,
    "MAGIC_ENUM_RANGE_MAX must be greater than MAGIC_ENUM_RANGE_MIN."
);

} // namespace magic_enum::customize
