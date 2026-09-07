//
//  mkwcat/Attribute.hpp
//  nsmbw-project
//

#include "Macro.hpp"

namespace mkwcat::Attribute {

struct Entry {
    unsigned int* addr;

    union {
        unsigned int* instruction;
        void (*function)();
    } dest;
};

#define nsmbw(_ADDRESS) _Clang::__external__(#_ADDRESS)

#define nsmbw_data(_ADDRESS) __gnu__::__section__(".external." #_ADDRESS)] ][[__gnu__::__weak__]] [[_Clang::__require_constant_initialization__

#define nsmbw_data_noconstinit(_ADDRESS) __gnu__::__section__(".external." #_ADDRESS)]] [[__gnu__::__weak__

#define EXTERN_TEXT_INLINE(_ADDR, _PROTOTYPE) SECTION(".external." #_ADDR) _PROTOTYPE

#define EXTERN_REPL(_ADDR, _PROTOTYPE) \
    SECTION("extern") void __ExternDest_##_ADDR() { \
        __builtin_unreachable(); \
    } \
    PRAGMA(clang diagnostic push) \
    PRAGMA(clang diagnostic ignored "-Wreturn-type") \
    SECTION("extern") [[__gnu__::__weak__]] [[__gnu__::__naked__]] _PROTOTYPE { \
        ASM(nop; b ext_##_ADDR + 4;); \
    } \
    PRAGMA(clang diagnostic pop) \
    extern unsigned int __Extern_##_ADDR __asm__("ext_" #_ADDR); \
    SECTION("extern_array") \
    [[__gnu__::__used__]] \
    constinit ::mkwcat::Attribute::Entry __ExternEntry_##_ADDR = { \
        &__Extern_##_ADDR, {.function = &__ExternDest_##_ADDR} \
    };

/**
 * Define an external function by its symbol name only
 */
#define EXTERN_SYMBOL(_ADDR, _NAME) \
    void __ExternSymbol_##_ADDR() asm(_NAME); \
    SECTION(".external." #_ADDR) void __ExternSymbol_##_ADDR() { \
        __builtin_unreachable(); \
    }

} // namespace mkwcat::Attribute
