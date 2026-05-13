//
//  mkwcat/Macro.hpp
//  nsmbw-project
//

namespace peli::Macro {

/**
 * Macro shortcut for #pragma.
 */
#define PRAGMA(...) _Pragma(#__VA_ARGS__)

/**
 * Create padding bytes in a struct.
 */
#define FILL(_START, _END) char __Fill_##_START[_END - _START]

/**
 * Mark variable as replaced.
 */
#define REMOVED(_NAME) Removed_##_NAME

/**
 * Begin C Linkage.
 */
#define EXTERN_C_START                                                                             \
    extern "C" {                                                                                   \
    PRAGMA(                                                                                        \
        clang diagnostic push                                                                      \
    )                                                                                              \
    PRAGMA(clang diagnostic ignored "-Wold-style-cast")

/**
 * End C Linkage.
 */
#define EXTERN_C_END                                                                               \
    PRAGMA(clang diagnostic pop)                                                                   \
    }

/**
 * Util macro for stringifying macro parameters.
 */
#define STRINGIFY_EXPANDED(...) #__VA_ARGS__
#define STRINGIFY(...) STRINGIFY_EXPANDED(__VA_ARGS__)

/**
 * Util macro for concattening macro parameters.
 */
#define CONCAT_EXPANDED(_ONE, _TWO) _ONE##_TWO
#define CONCAT(_ONE, _TWO) CONCAT_EXPANDED(_ONE, _TWO)

/**
 * Set the section of a definition.
 */
#define SECTION(_SECTION) [[__gnu__::__section__(CONCAT(_SECTION, ))]]

/**
 * The restrict keyword from C.
 */
#define restrict __restrict

} // namespace peli::Macro
