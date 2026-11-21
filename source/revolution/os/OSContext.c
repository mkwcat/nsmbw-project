// OSContext.c
// NSMBW .text: 0x801ACC10 - 0x801AD620

#include <revolution/os/OSContext.h>

EXTERN_C_START

[[nsmbw(0x801ACC10)]]
void __OSLoadFPUContext(u32 dummy, OSContext* fpucontext);

[[nsmbw(0x801ACE70)]]
void OSSaveFPUContext(OSContext* fpucontext);

void OSLoadFPUContext(OSContext* fpucontext) ASM_METHOD(
    addi    r4, r3, 0;
    b       __OSLoadFPUContext;
);

[[nsmbw(0x801ACE80)]]
void OSSetCurrentContext(OSContext* context);

[[nsmbw(0x801ACEE0)]]
OSContext* OSGetCurrentContext(void);

[[nsmbw(0x801ACEF0)]]
u32 OSSaveContext(OSContext* context);

[[nsmbw(0x801ACF70)]] [[noreturn]]
void OSLoadContext(OSContext* context);

[[nsmbw(0x801AD050)]]
u32 OSGetStackPointer(void);

u32 OSSwitchStack(u32 newsp);

[[nsmbw(0x801AD060)]]
int OSSwitchFiber(u32 pc, u32 newsp);

[[nsmbw(0x801AD090)]]
int OSSwitchFiberEx(u32, u32, u32, u32, u32 pc, u32 newsp);

[[nsmbw(0x801AD0C0)]]
void OSClearContext(OSContext* context);

[[nsmbw(0x801AD0F0)]]
void OSInitContext(OSContext* context, u32 pc, u32 newsp);

[[nsmbw(0x801AD1B0)]]
void OSDumpContext(OSContext* context);

[[nsmbw(0x801AD4A0)]]
void __OSContextInit(void);

[[nsmbw(0x801AD4F0)]]
void OSFillFPUContext(OSContext* context);

EXTERN_C_END
