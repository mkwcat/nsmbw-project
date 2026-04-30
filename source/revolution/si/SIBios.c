// SIBios.c
// NSMBW .text: 0x801BA940 - 0x801BB980

#include <revolution/os/OSInterrupt.h>
#include <revolution/si.h>

EXTERN_C_START

[[nsmbw_data(0x803402D0)]] struct Si_ {
    /* 0x00 */ s32 status;
    /* 0x04 */ u32 xy;
    FILL(0x08, 0x20);
} Si{};

[[nsmbw_data(0x803402E8)]]
u32 Type_SI[4];

[[nsmbw_data(0x8038FAD0)]] struct Packet_ {
    /* 0x00 */ s32 x0;
    FILL(0x04, 0x20);
} Packet[4]{};

bool SIIsChanBusy(s32 status)
{
    return !(Packet[status].x0 == -1 && Si.status != status);
}

u32 SIGetStatus(s32 chan)
{
    int level = OSDisableInterrupts();

    u32 sr = *reinterpret_cast<u32*>(0xCD006438) >> (8 * (3 - chan));
    if (sr & 0x0008 && !(Type_SI[chan] & 0x0080)) {
        Type_SI[chan] = 0x0008;
    }

    OSRestoreInterrupts(level);
    return sr;
}

[[nsmbw(0x801BB7C0)]]
u32 SIGetType(s32 chan);

void SISetCommand(s32 param_1, u32 param_2)
{
    *reinterpret_cast<u32*>(0xCD006400 + param_1 * 0xC) = param_2;
}

void SITransferCommands()
{
    *reinterpret_cast<u32*>(0xCD006438) = 0x80000000;
}

[[nsmbw(0x801BB390)]]
bool SITransfer(
  s32 chan, void* out, u32 outSize, void* in, u32 inSize, SICallback callback, s64 param_7
);

u32 SIEnablePolling(u32 param_1) ASM_METHOD(
  // clang-format off
    mr.      r12, r3;
    lis      r6, UNDEF_803402d4@ha; // Si.xy@ha
    lwzu     r3, UNDEF_803402d4@l(r6); // Si.xy@l
    beqlr-;
    mflr     r11;
    // r6 is volatile but it's only OSDisableInterrupts
    bl       OSDisableInterrupts;
    srwi     r12, r12, 24;
    extrwi   r8, r12, 4, 24;
    lis      r4, 0xCD00;
    lis      r0, 0x8000;
    oris     r7, r8, 0x03FF;
    lwz      r5, 0(r6);
    ori      r7, r7, 0xFFF0;
    and      r12, r12, r7;
    andc     r5, r5, r8;
    or       r12, r5, r12;
    stw      r12, 0(r6);
    stw      r0, 0x6438(r4);
    stw      r12, 0x6430(r4);
    bl       OSRestoreInterrupts;
    mr       r3, r12;
    mtlr     r11;
    blr;
  // clang-format on
);

u32 SIDisablePolling(u32 param_1) ASM_METHOD(
  // clang-format off
    mr.      r12, r3;
    lis      r6, UNDEF_803402d4@ha; // Si.xy@ha
    lwzu     r3, UNDEF_803402d4@l(r6); // Si.xy@l
    beqlr-;
    mflr     r11;
    // r6 is volatile but it's only OSDisableInterrupts
    bl       OSDisableInterrupts;
    rlwinm   r0, r12, 8, 24, 27;
    lis      r4, 0xCD00;
    lwz      r5, 0(r6);
    andc     r12, r5, r0;
    stw      r12, 0x6430(r4);
    stw      r12, 0(r6);
    bl       OSRestoreInterrupts;
    mr       r3, r12;
    mtlr     r11;
    blr;
  // clang-format on
);

bool SIGetResponse(s32 chan, void* data) ASM_METHOD(
  // clang-format off
    stwu     r1, -32(r1);
    mflr     r0;
    stw      r0, 36(r1);
    stw      r31, 28(r1);
    stw      r30, 24(r1);
    mr       r30, r4;
    stw      r29, 20(r1);
    mr       r29, r3;
    stw      r28, 16(r1);
    bl       OSDisableInterrupts;
    mr       r31, r3;
    lis      r4, 0xCD00;
    subfic   r0, r29, 3;
    lwz      r28, 25656(r4);
    slwi     r0, r0, 3;
    srw      r28, r28, r0;
    rlwinm.  r0, r28, 0, 28, 28;
    beq-     UNDEF_801b32a8;
    lis      r4, UNDEF_803402e8@ha;
    slwi     r5, r29, 2;
    addi     r4, r4, UNDEF_803402e8@l;
    lwzx     r0, r4, r5;
    rlwinm.  r0, r0, 0, 24, 24;
    bne-     UNDEF_801b32a8;
    li       r0, 8;
    stwx     r0, r4, r5;
UNDEF_801b32a8:;
    rlwinm.  r0, r28, 0, 26, 26;
    beq-     UNDEF_801b32f4;
    mulli    r5, r29, 12;
    lis      r0, 0xCD00;
    lis      r4, UNDEF_8038fc50@ha;
    lis      r3, UNDEF_8038fc70@ha;
    add      r7, r0, r5;
    slwi     r8, r29, 3;
    lwz      r6, 25604(r7);
    addi     r4, r4, UNDEF_8038fc50@l;
    add      r5, r4, r8;
    slwi     r0, r29, 2;
    stwx     r6, r4, r8;
    addi     r3, r3, UNDEF_8038fc70@l;
    li       r4, 1;
    lwz      r6, 25608(r7);
    stw      r6, 4(r5);
    stwx     r4, r3, r0;
UNDEF_801b32f4:;
    lis      r3, UNDEF_8038fc70@ha;
    slwi     r4, r29, 2;
    addi     r3, r3, UNDEF_8038fc70@l;
    li       r0, 0;
    lwzx     r28, r3, r4;
    cmpwi    r28, 0;
    stwx     r0, r3, r4;
    beq-     UNDEF_801b3334;
    lis      r3, UNDEF_8038fc50@ha;
    slwi     r4, r29, 3;
    addi     r3, r3, UNDEF_8038fc50@l;
    lwzx     r0, r3, r4;
    add      r3, r3, r4;
    stw      r0, 0(r30);
    lwz      r0, 4(r3);
    stw      r0, 4(r30);
UNDEF_801b3334:;
    mr       r3, r31;
    bl       OSRestoreInterrupts;
    lwz      r31, 28(r1);
    mr       r3, r28;
    lwz      r30, 24(r1);
    lwz      r29, 20(r1);
    lwz      r28, 16(r1);
    lwz      r0, 36(r1);
    mtlr     r0;
    addi     r1, r1, 32;
    blr;
  // clang-format on
);

u32 SIGetTypeAsync(s32 param_1, SITypeAndStatusCallback param_2) ASM_METHOD(
  // clang-format off
    stwu     r1, -32(r1);
    mflr     r0;
    stw      r0, 36(r1);
    stw      r31, 28(r1);
    stw      r30, 24(r1);
    stw      r29, 20(r1);
    mr       r29, r4;
    stw      r28, 16(r1);
    mr       r28, r3;
    bl       OSDisableInterrupts;
    mr       r31, r3;
    mr       r3, r28;
    bl       SIGetType;
    lis      r4, UNDEF_803402e8@ha;
    slwi     r0, r28, 2;
    addi     r4, r4, UNDEF_803402e8@l;
    mr       r30, r3;
    lwzx     r0, r4, r0;
    rlwinm.  r0, r0, 0, 24, 24;
    beq-     UNDEF_801b3a8c;
    lis      r3, UNDEF_8038fcb0@ha;
    slwi     r0, r28, 4;
    addi     r3, r3, UNDEF_8038fcb0@l;
    lwzux    r0, r3, r0;
    cmplw    r0, r29;
    beq-     UNDEF_801b3aa0;
    cmpwi    r0, 0;
    bne-     UNDEF_801b3a34;
    stw      r29, 0(r3);
    b        UNDEF_801b3aa0;
UNDEF_801b3a34:;
    lwz      r0, 4(r3);
    cmplw    r0, r29;
    beq-     UNDEF_801b3aa0;
    cmpwi    r0, 0;
    bne-     UNDEF_801b3a50;
    stw      r29, 4(r3);
    b        UNDEF_801b3aa0;
UNDEF_801b3a50:;
    lwz      r0, 8(r3);
    cmplw    r0, r29;
    beq-     UNDEF_801b3aa0;
    cmpwi    r0, 0;
    bne-     UNDEF_801b3a6c;
    stw      r29, 8(r3);
    b        UNDEF_801b3aa0;
UNDEF_801b3a6c:;
    lwz      r0, 12(r3);
    cmplw    r0, r29;
    beq-     UNDEF_801b3aa0;
    cmpwi    r0, 0;
    bne-     UNDEF_801b3aa0;
    stw      r29, 12(r3);
    b        UNDEF_801b3aa0;
UNDEF_801b3a8c:;
    mr       r12, r29;
    mr       r3, r28;
    mr       r4, r30;
    mtctr    r12;
    bctrl;
UNDEF_801b3aa0:;
    mr       r3, r31;
    bl       OSRestoreInterrupts;
    mr       r3, r30;
    lwz      r31, 28(r1);
    lwz      r30, 24(r1);
    lwz      r29, 20(r1);
    lwz      r28, 16(r1);
    lwz      r0, 36(r1);
    mtlr     r0;
    addi     r1, r1, 32;
    blr
  // clang-format on
);

EXTERN_C_END
