//
//  slu/attribute.hpp
//  supplemental-language-utilities
//

#pragma once

#include "macro.hpp"

namespace slu::attribute {

struct entry {
    unsigned int* address;

    union {
        unsigned int* instruction;
        void (*function)();
    } dest;
};

/**
 * Define an external function by its symbol name only
 */
#define external_symbol(X_ADDRESS, _NAME) NOTHING_ATTRIBUTE]]; \
    void CONCAT(__ExternSymbol_, X_ADDRESS()) asm(_NAME); \
    [[__gnu__::__section__(".external." #X_ADDRESS)]] void CONCAT(__ExternSymbol_, X_ADDRESS)() { \
        __builtin_unreachable(); \
    } [[NOTHING_ATTRIBUTE

#if is_nsmbw
#  define nsmbw(...) _Clang::__external__(#__VA_ARGS__)
#  define nsmbw_data(...) __gnu__::__section__(".external." #__VA_ARGS__)] ][[__gnu__::__weak__]] [[_Clang::__require_constant_initialization__
#  define nsmbw_data_noconstinit(...) __gnu__::__section__(".external." #__VA_ARGS__)]] [[__gnu__::__weak__
#  define nsmbw_symbol(X_ADDRESS, _NAME) external_symbol(X_ADDRESS, _NAME)
#  define mkw(...)                       maybe_unused
#  define mkw_data(...)                  maybe_unused
#  define mkw_data_noconstinit(...)      maybe_unused
#  define mkw_symbol(X_ADDRESS, _NAME)
#elif is_mkw
#  define nsmbw(...)                  maybe_unused
#  define nsmbw_data(...)             maybe_unused
#  define nsmbw_data_noconstinit(...) maybe_unused
#  define nsmbw_symbol(X_ADDRESS, _NAME)
#  define mkw(...) _Clang::__external__(#__VA_ARGS__)
#  define mkw_data(...) __gnu__::__section__(".external." #__VA_ARGS__)] ][[__gnu__::__weak__]] [[_Clang::__require_constant_initialization__
#  define mkw_data_noconstinit(...) __gnu__::__section__(".external." #__VA_ARGS__)]] [[__gnu__::__weak__
#  define mkw_symbol(X_ADDRESS, _NAME) external_symbol(X_ADDRESS, _NAME)
#endif

#define EXTERN_TEXT_INLINE(X_ADDRESS, _PROTOTYPE) \
    [[__gnu__::__section__(".external." STRINGIFY(X_ADDRESS))]] _PROTOTYPE

#define EXTERN_REPL(X_ADDRESS, _PROTOTYPE) \
    [[__gnu__::__section__("extern")]] void CONCAT(__ExternDest_, X_ADDRESS)() { \
        __builtin_unreachable(); \
    } \
    PRAGMA(clang diagnostic push) \
    PRAGMA(clang diagnostic ignored "-Wreturn-type") \
    [[__gnu__::__section__("extern")]] [[__gnu__::__weak__]] [[__gnu__::__naked__]] _PROTOTYPE { \
        ASM(nop; b CONCAT(ext_, X_ADDRESS) + 4;); \
    } \
    PRAGMA(clang diagnostic pop) \
    extern unsigned int CONCAT(__Extern_, X_ADDRESS) __asm__("ext_" STRINGIFY(X_ADDRESS)); \
    [[__gnu__::__section__("extern_array")]] [[__gnu__::__used__]] \
    constinit ::slu::attribute::entry CONCAT(__ExternEntry_, X_ADDRESS) = { \
        &CONCAT(__Extern_, X_ADDRESS), {.function = &CONCAT(__ExternDest_, X_ADDRESS)} \
    };

} // namespace slu::attribute
