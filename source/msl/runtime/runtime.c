// runtime.c
// NSMBW .text: 0x802DCF3C - 0x802DD5D0

EXTERN_C_START

void __cvt_sll_dbl() ASM_METHOD(
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

void __cvt_ull_dbl() ASM_METHOD(
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
