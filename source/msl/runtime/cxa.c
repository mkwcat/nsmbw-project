// cxa.c
// nsmbw-project

#include <revolution/os/OSError.h>

EXTERN_C_START

[[noreturn]]
void __cxa_pure_virtual() {
    OS_PANIC("Pure virtual function called!");
}

[[noreturn]]
void __cxa_deleted_virtual() {
    OS_PANIC("Deleted virtual function called!");
}

EXTERN_C_END
