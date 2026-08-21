// d_enemy_boss.cpp
// NSMBW .text: 0x800983C0 - 0x8009AD30

[[nsmbw(0x80098B60)]]
void dEnBoss_c_Normal_VsPlHitCheck(void* this_, void* cc1, void* cc2) ASM_METHOD(
  // clang-format off
/* 80098B60 9421FFE0 */  stwu     r1, -32(r1);
/* 80098B64 7C0802A6 */  mflr     r0;
/* 80098B68 90010024 */  stw      r0, 36(r1);
/* 80098B6C 93E1001C */  stw      r31, 28(r1);
/* 80098B70 93C10018 */  stw      r30, 24(r1);
/* 80098B74 7CBE2B78 */  mr       r30, r5;
/* 80098B78 93A10014 */  stw      r29, 20(r1);
/* 80098B7C 7C9D2378 */  mr       r29, r4;
/* 80098B80 93810010 */  stw      r28, 16(r1);
/* 80098B84 7C7C1B78 */  mr       r28, r3;
/* 80098B88 81830060 */  lwz      r12, 96(r3);
/* 80098B8C 818C0334 */  lwz      r12, 820(r12);
/* 80098B90 7D8903A6 */  mtctr    r12;
/* 80098B94 4E800421 */  bctrl;
/* 80098B98 2C030000 */  cmpwi    r3, 0;
/* 80098B9C 41820018 */  beq-     UNDEF_80098bb4;
/* 80098BA0 7F83E378 */  mr       r3, r28;
/* 80098BA4 7FA4EB78 */  mr       r4, r29;
/* 80098BA8 7FC5F378 */  mr       r5, r30;
/* 80098BAC 4BFFD075 */  bl       UNDEF_80095c20;
/* 80098BB0 480000BC */  b        UNDEF_80098c6c;
UNDEF_80098bb4:;
/* 80098BB4 83FE0004 */  lwz      r31, 4(r30);
/* 80098BB8 7F83E378 */  mr       r3, r28;
/* 80098BBC 7FA4EB78 */  mr       r4, r29;
/* 80098BC0 7FC5F378 */  mr       r5, r30;
/* 80098BC4 38C00002 */  li       r6, 2;
/* 80098BC8 4BFFD8D9 */  bl       UNDEF_800964a0;
/* 80098BCC 2C030001 */  cmpwi    r3, 1;
/* 80098BD0 41820018 */  beq-     UNDEF_80098be8;
/* 80098BD4 2C030003 */  cmpwi    r3, 3;
/* 80098BD8 41820010 */  beq-     UNDEF_80098be8;
/* 80098BDC 2C030000 */  cmpwi    r3, 0;
/* 80098BE0 41820034 */  beq-     UNDEF_80098c14;
/* 80098BE4 48000088 */  b        UNDEF_80098c6c;
UNDEF_80098be8:;
/* 80098BE8 819C0060 */  lwz      r12, 96(r28);
/* 80098BEC 7F83E378 */  mr       r3, r28;
/* 80098BF0 818C0338 */  lwz      r12, 824(r12);
/* 80098BF4 7D8903A6 */  mtctr    r12;
/* 80098BF8 4E800421 */  bctrl;
/* 80098BFC 2C030000 */  cmpwi    r3, 0;
/* 80098C00 4082006C */  bne-     UNDEF_80098c6c;
/* 80098C04 809E0004 */  lwz      r4, 4(r30);
/* 80098C08 7F83E378 */  mr       r3, r28;
/* 80098C0C 48000185 */  bl       UNDEF_80098d90;
/* 80098C10 4800005C */  b        UNDEF_80098c6c;
UNDEF_80098c14:;
/* 80098C14 7F83E378 */  mr       r3, r28;
/* 80098C18 7FA4EB78 */  mr       r4, r29;
/* 80098C1C 7FC5F378 */  mr       r5, r30;
/* 80098C20 4BFFD001 */  bl       UNDEF_80095c20;
/* 80098C24 7FE3FB78 */  mr       r3, r31;
/* 80098C28 3880003F */  li       r4, 63;
/* 80098C2C 4BFBE0C5 */  bl       UNDEF_80056cf0;
/* 80098C30 2C030000 */  cmpwi    r3, 0;
/* 80098C34 41820038 */  beq-     UNDEF_80098c6c;

                         // Damage cooldown
                         mr       r3, r28;
                         mr       r4, r31;
                         li       r5, 16;
                         bl       setCollTimer__5dEn_cFP8dActor_cUc;

UNDEF_80098c6c:;
/* 80098C6C 80010024 */  lwz      r0, 36(r1);
/* 80098C70 83E1001C */  lwz      r31, 28(r1);
/* 80098C74 83C10018 */  lwz      r30, 24(r1);
/* 80098C78 83A10014 */  lwz      r29, 20(r1);
/* 80098C7C 83810010 */  lwz      r28, 16(r1);
/* 80098C80 7C0803A6 */  mtlr     r0;
/* 80098C84 38210020 */  addi     r1, r1, 32;
/* 80098C88 4E800020 */  blr;
  // clang-format on
);