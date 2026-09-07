// stack_chk.c
// nsmbw-project

#include <cstdint>
#include <revolution/os/OSError.h>

EXTERN_C_START

std::uintptr_t __stack_chk_guard;

[[gnu::no_stack_protector]]
void __stack_chk_init(
    std::uintptr_t value
) {
    __stack_chk_guard = value;
}

[[noreturn]] [[gnu::no_stack_protector]]
void __stack_chk_fail() {
    OS_PANIC("Stack smashing detected!");
}

EXTERN_C_END
