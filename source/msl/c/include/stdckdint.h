#ifndef __STDC_VERSION_STDCKDINT_H__
#  define __STDC_VERSION_STDCKDINT_H__ 202311L

#  define ckd_add(R_, A_, B_) __builtin_add_overflow((A_), (B_), (R_))
#  define ckd_sub(R_, A_, B_) __builtin_sub_overflow((A_), (B_), (R_))
#  define ckd_mul(R_, A_, B_) __builtin_mul_overflow((A_), (B_), (R_))

#  ifdef __cplusplus
namespace std {
using ::__builtin_add_overflow;
using ::__builtin_mul_overflow;
using ::__builtin_sub_overflow;
} // namespace std
#  endif
#endif // __STDC_VERSION_STDCKDINT_H__
