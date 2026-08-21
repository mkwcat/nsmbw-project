// runtime.c
// NSMBW .text: 0x802DCF3C - 0x802DD5D0

EXTERN_C_START

[[nsmbw(0x802DCF3C)]]
void __cvt_fp2unsigned();

[[nsmbw(0x802DCF98)]]
void __save_fpr();

EXTERN_SYMBOL(0x802DCF98, "_savefpr_14");
EXTERN_SYMBOL(0x802DCF9C, "_savefpr_15");
EXTERN_SYMBOL(0x802DCFA0, "_savefpr_16");
EXTERN_SYMBOL(0x802DCFA4, "_savefpr_17");
EXTERN_SYMBOL(0x802DCFA8, "_savefpr_18");
EXTERN_SYMBOL(0x802DCFAC, "_savefpr_19");
EXTERN_SYMBOL(0x802DCFB0, "_savefpr_20");
EXTERN_SYMBOL(0x802DCFB4, "_savefpr_21");
EXTERN_SYMBOL(0x802DCFB8, "_savefpr_22");
EXTERN_SYMBOL(0x802DCFBC, "_savefpr_23");
EXTERN_SYMBOL(0x802DCFC0, "_savefpr_24");
EXTERN_SYMBOL(0x802DCFC4, "_savefpr_25");
EXTERN_SYMBOL(0x802DCFC8, "_savefpr_26");
EXTERN_SYMBOL(0x802DCFCC, "_savefpr_27");
EXTERN_SYMBOL(0x802DCFD0, "_savefpr_28");
EXTERN_SYMBOL(0x802DCFD4, "_savefpr_29");
EXTERN_SYMBOL(0x802DCFD8, "_savefpr_30");
EXTERN_SYMBOL(0x802DCFDC, "_savefpr_31");

[[nsmbw(0x802DCFE4)]]
void __restore_fpr();

EXTERN_SYMBOL(0x802DCFE4, "_restfpr_14");
EXTERN_SYMBOL(0x802DCFE8, "_restfpr_15");
EXTERN_SYMBOL(0x802DCFEC, "_restfpr_16");
EXTERN_SYMBOL(0x802DCFF0, "_restfpr_17");
EXTERN_SYMBOL(0x802DCFF4, "_restfpr_18");
EXTERN_SYMBOL(0x802DCFF8, "_restfpr_19");
EXTERN_SYMBOL(0x802DCFFC, "_restfpr_20");
EXTERN_SYMBOL(0x802DD000, "_restfpr_21");
EXTERN_SYMBOL(0x802DD004, "_restfpr_22");
EXTERN_SYMBOL(0x802DD008, "_restfpr_23");
EXTERN_SYMBOL(0x802DD00C, "_restfpr_24");
EXTERN_SYMBOL(0x802DD010, "_restfpr_25");
EXTERN_SYMBOL(0x802DD014, "_restfpr_26");
EXTERN_SYMBOL(0x802DD018, "_restfpr_27");
EXTERN_SYMBOL(0x802DD01C, "_restfpr_28");
EXTERN_SYMBOL(0x802DD020, "_restfpr_29");
EXTERN_SYMBOL(0x802DD024, "_restfpr_30");
EXTERN_SYMBOL(0x802DD028, "_restfpr_31");

[[nsmbw(0x802DD030)]]
void __save_gpr();

EXTERN_SYMBOL(0x802DD030, "_savegpr_14");
EXTERN_SYMBOL(0x802DD034, "_savegpr_15");
EXTERN_SYMBOL(0x802DD038, "_savegpr_16");
EXTERN_SYMBOL(0x802DD03C, "_savegpr_17");
EXTERN_SYMBOL(0x802DD040, "_savegpr_18");
EXTERN_SYMBOL(0x802DD044, "_savegpr_19");
EXTERN_SYMBOL(0x802DD048, "_savegpr_20");
EXTERN_SYMBOL(0x802DD04C, "_savegpr_21");
EXTERN_SYMBOL(0x802DD050, "_savegpr_22");
EXTERN_SYMBOL(0x802DD054, "_savegpr_23");
EXTERN_SYMBOL(0x802DD058, "_savegpr_24");
EXTERN_SYMBOL(0x802DD05C, "_savegpr_25");
EXTERN_SYMBOL(0x802DD060, "_savegpr_26");
EXTERN_SYMBOL(0x802DD064, "_savegpr_27");
EXTERN_SYMBOL(0x802DD068, "_savegpr_28");
EXTERN_SYMBOL(0x802DD06C, "_savegpr_29");
EXTERN_SYMBOL(0x802DD070, "_savegpr_30");
EXTERN_SYMBOL(0x802DD074, "_savegpr_31");

[[nsmbw(0x802DD07C)]]
void __restore_gpr();

EXTERN_SYMBOL(0x802DD07C, "_restgpr_14");
EXTERN_SYMBOL(0x802DD080, "_restgpr_15");
EXTERN_SYMBOL(0x802DD084, "_restgpr_16");
EXTERN_SYMBOL(0x802DD088, "_restgpr_17");
EXTERN_SYMBOL(0x802DD08C, "_restgpr_18");
EXTERN_SYMBOL(0x802DD090, "_restgpr_19");
EXTERN_SYMBOL(0x802DD094, "_restgpr_20");
EXTERN_SYMBOL(0x802DD098, "_restgpr_21");
EXTERN_SYMBOL(0x802DD09C, "_restgpr_22");
EXTERN_SYMBOL(0x802DD0A0, "_restgpr_23");
EXTERN_SYMBOL(0x802DD0A4, "_restgpr_24");
EXTERN_SYMBOL(0x802DD0A8, "_restgpr_25");
EXTERN_SYMBOL(0x802DD0AC, "_restgpr_26");
EXTERN_SYMBOL(0x802DD0B0, "_restgpr_27");
EXTERN_SYMBOL(0x802DD0B4, "_restgpr_28");
EXTERN_SYMBOL(0x802DD0B8, "_restgpr_29");
EXTERN_SYMBOL(0x802DD0BC, "_restgpr_30");
EXTERN_SYMBOL(0x802DD0C0, "_restgpr_31");

double __cvt_sll_dbl(signed long long) ASM_METHOD(
    stwu    r1, -0x10(r1);
    rlwinm. r5, r3, 0, 0, 0;
    beq-    .L1;
    subfic  r4, r4, 0x0;
    subfze  r3, r3;
.L1:
    or.     r7, r3, r4;
    li      r6, 0x0;
    beq-    .L4;
    cntlzw  r7, r3;
    cntlzw  r8, r4;
    rlwinm  r9, r7, 26, 0, 4;
    srawi   r9, r9, 31;
    and     r9, r9, r8;
    add     r7, r7, r9;
    subfic  r8, r7, 0x20;
    addic   r9, r7, -0x20;
    slw     r3, r3, r7;
    srw     r10, r4, r8;
    or      r3, r3, r10;
    slw     r10, r4, r9;
    or      r3, r3, r10;
    slw     r4, r4, r7;
    subf    r6, r7, r6;
    clrlwi  r7, r4, 21;
    cmpwi   r7, 0x400;
    addi    r6, r6, 0x43E;
    blt-    .L3;
    bgt-    .L2;
    rlwinm. r7, r4, 0, 20, 20;
    beq-    .L3;
.L2:;
    addic   r4, r4, 0x800;
    addze   r3, r3;
    addze   r6, r6;
.L3:;
    rotlwi  r4, r4, 21;
    rlwimi  r4, r3, 21, 0, 10;
    rlwinm  r3, r3, 21, 12, 31;
    slwi    r6, r6, 20;
    or      r3, r6, r3;
    or      r3, r5, r3;
.L4:;
    stw     r3, 0x8(r1);
    stw     r4, 0xC(r1);
    lfd     f1, 0x8(r1);
    addi    r1, r1, 0x10;
    blr;
);

double __cvt_ull_dbl(unsigned long long) ASM_METHOD(
    stwu    r1, -0x10(r1);
    or.     r7, r3, r4;
    li      r6, 0x0;
    beq     .L7;
    cntlzw  r7, r3;
    cntlzw  r8, r4;
    extlwi  r9, r7, 5, 26;
    srawi   r9, r9, 31;
    and     r9, r9, r8;
    add     r7, r7, r9;
    subfic  r8, r7, 0x20;
    subic   r9, r7, 0x20;
    slw     r3, r3, r7;
    srw     r10, r4, r8;
    or      r3, r3, r10;
    slw     r10, r4, r9;
    or      r3, r3, r10;
    slw     r4, r4, r7;
    subf    r6, r7, r6;
    clrlwi  r7, r4, 21;
    cmpwi   r7, 0x400;
    addi    r6, r6, 0x43E;
    blt     .L6;
    bgt     .L5;
    rlwinm. r7, r4, 0, 20, 20;
    beq     .L6;
.L5:;
    addic   r4, r4, 0x800;
    addze   r3, r3;
    addze   r6, r6;
.L6:;
    rotrwi  r4, r4, 11;
    rlwimi  r4, r3, 21, 0, 10;
    extrwi  r3, r3, 20, 1;
    slwi    r6, r6, 20;
    or      r3, r6, r3;
.L7:;
    stw     r3, 0x8(r1);
    stw     r4, 0xC(r1);
    lfd     f1, 0x8(r1);
    addi    r1, r1, 0x10;
    blr;
);

EXTERN_C_END
