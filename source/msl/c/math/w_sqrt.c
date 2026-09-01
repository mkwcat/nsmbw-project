// w_sqrt.c
// NSMBW .text: 0x802E8B58 - 0x802E8B5C

#include <cmath>

namespace std {

EXTERN_C_START

[[nsmbw(0x802E8B58)]]
double sqrt(double x);

EXTERN_C_END

} // namespace std
