//
//  slu/base_types.hpp
//  supplemental-language-utilities
//

#pragma once

namespace slu {

namespace base_types {

using u8           = unsigned char;
using u16          = unsigned short;
using u32          = unsigned long;
using u64          = unsigned long long;

using s8           = signed char;
using s16          = signed short;
using s32          = signed long;
using s64          = signed long long;

using f32          = float;
using f64          = double;

using size_type    = decltype(sizeof 0);
using ptrdiff_type = decltype(static_cast<int*>(0) - static_cast<int*>(0));

static_assert(__is_same(u32, size_type));

} // namespace base_types

using namespace base_types;

} // namespace slu
