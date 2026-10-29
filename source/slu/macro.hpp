//
//  slu/macro.hpp
//  supplemental-language-utilities
//

namespace slu::macro {

/**
 * The restrict keyword from C.
 */
#define restrict __restrict

/**
 * Macro version of #pragma.
 */
#define PRAGMA(...) _Pragma(#__VA_ARGS__)

/**
 * Create padding bytes in a struct.
 */
#define FILL(X_START, X_END) __Fill_##X_START[X_END - X_START]

/**
 * Mark variable as removed.
 */
#define REMOVED(X_NAME) __Removed_##X_NAME

/**
 * Begin C Linkage.
 */
#define EXTERN_C_START \
    extern "C" { \
    PRAGMA( \
        clang diagnostic push \
    ) \
    PRAGMA(clang diagnostic ignored "-Wold-style-cast")

/**
 * End C Linkage.
 */
#define EXTERN_C_END \
    PRAGMA(clang diagnostic pop) \
    }

/**
 * Util macro for stringifying macro parameters.
 */
#define STRINGIFY_EXPANDED(...) #__VA_ARGS__
#define STRINGIFY(...)          STRINGIFY_EXPANDED(__VA_ARGS__)

/**
 * Util macro for concattening macro parameters.
 */
#define CONCAT_EXPANDED(X_ONE, X_TWO) X_ONE##X_TWO
#define CONCAT(X_ONE, X_TWO)          CONCAT_EXPANDED(X_ONE, X_TWO)

/**
 * Prevent a symbol from being garbage collected. Also can forcibly emit weak symbols.
 */
#define KEEP(X_SYMBOL) \
    [[__gnu__::__section__("rel_ignore")]] [[__gnu__::__used__]] static auto CONCAT( \
        __RelIgnore, __COUNTER__ \
    ) = &X_SYMBOL;

/**
 * Attribute that does nothing on Clang.
 */
#define NOTHING_ATTRIBUTE __gnu__::____const__

/**
 * The macro arguments are only expanded in nsmbw-project.
 */
#if is_nsmbw
#  define NSMBW_ONLY(...) __VA_ARGS__
#else
#  define NSMBW_ONLY(...)
#endif

/**
 * The macro arguments are only expanded outside of nsmbw-project.
 */
#if is_nsmbw
#  define IF_NOT_NSMBW(...)
#else
#  define IF_NOT_NSMBW(...) __VA_ARGS__
#endif

/**
 * The macro arguments are only expanded in mkw-project.
 */
#if is_mkw
#  define MKW_ONLY(...) __VA_ARGS__
#else
#  define MKW_ONLY(...)
#endif

/**
 * The macro arguments are only expanded outside of mkw-project.
 */
#if is_mkw
#  define IF_NOT_MKW(...)
#else
#  define IF_NOT_MKW(...) __VA_ARGS__
#endif

/**
 * Enforce this function is only called in nsmbw-project.
 */
#define error_if_not_nsmbw \
    NSMBW_ONLY(maybe_unused) \
    IF_NOT_NSMBW(gnu::error("This function is only available in nsmbw-project"))

/**
 * Enforce this function is only called in mkw-project.
 */
#define error_if_not_mkw \
    MKW_ONLY(maybe_unused) \
    IF_NOT_MKW(gnu::error("This function is only available in mkw-project"))

#define SLU_FIRST(FIRST, ...)                         FIRST
#define SLU_SECOND(FIRST, SECOND, ...)                SECOND
#define SLU_THIRD(FIRST, SECOND, THIRD, FOURTH, ...)  THIRD
#define SLU_FOURTH(FIRST, SECOND, THIRD, FOURTH, ...) FOURTH

} // namespace slu::macro
